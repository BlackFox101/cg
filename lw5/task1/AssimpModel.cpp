#include "AssimpModel.h"
#include "Texture.h"

using namespace std;

AssimpModel::AssimpModel(Path path)
    : m_path(path)
{
    if (!filesystem::exists(path))
    {
        throw invalid_argument("File not found: " + path.string());
    }

    // Чтение файла с помощью Assimp
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path.string(), aiProcess_Triangulate | aiProcess_FlipUVs);

    // Проверка на ошибки
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        throw invalid_argument(importer.GetErrorString());
    }

    std::queue<aiNode*> nodes;
    nodes.push(scene->mRootNode);
    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();

        // Обрабатываем каждый меш текущего узла
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            // Узел содержит только индексы объектов в сцене.
            // Сцена же содержит все данные; узел - это лишь способ организации данных
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            m_meshes.push_back(processMesh(mesh, scene));
        }

        // После того, как мы обработали все меши (если таковые имелись), мы начинаем рекурсивно обрабатывать каждый из дочерних узлов
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            nodes.push(node->mChildren[i]);
        }
    }
}

Mesh AssimpModel::processMesh(aiMesh* mesh, const aiScene* scene)
{
    vector<Vertex> vertices;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        auto meshVertex = mesh->mVertices[i];
        vertex.pos = { meshVertex.x, meshVertex.y, meshVertex.z };

        auto meshNormal = mesh->mNormals[i];
        vertex.normal = { meshNormal.x, meshNormal.y, meshNormal.z };
    
        if (mesh->mTextureCoords[0])
        {
            auto meshTexture = mesh->mTextureCoords[0][i];
            vertex.texCoords = { meshTexture.x, meshTexture.y };
        }
        else
        {
            vertex.texCoords = glm::vec2(0.0f, 0.0f);
        }

        vertices.push_back(vertex);
    }

    vector<Face> faces;
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace meshFace = mesh->mFaces[i];

        Face face;
        // Получаем все индексы граней и сохраняем их в векторе indices
        for (unsigned int j = 0; j < meshFace.mNumIndices; j++)
        {
            face.vertices[j] = meshFace.mIndices[j];
        }
        faces.push_back(face);
    }

    return Mesh(vertices, faces);
}

void AssimpModel::Draw()
{
    if (!m_modelTexture)
    {
        auto path = m_path;
        for (const Path& extension : { ".png", ".jpg" } )
        {
            if (!filesystem::exists(path.replace_extension(extension)))
            {
                continue;
            }

            m_modelTexture = Texture::LoadTexture(path.string());
            break;
        }
    }

    glBindTexture(GL_TEXTURE_2D, *m_modelTexture);
    for (auto mesh : m_meshes)
    {
        mesh.Draw();
    }
}