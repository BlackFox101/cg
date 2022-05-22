#pragma once
#include "pch.h"
#include "Mesh.h"

typedef std::filesystem::path Path;

class AssimpModel
{
public:
	AssimpModel(Path path);

	void Draw();

private:
	std::vector<Mesh> m_meshes;
	std::optional<GLuint> m_modelTexture;
	Path m_path;

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
};

