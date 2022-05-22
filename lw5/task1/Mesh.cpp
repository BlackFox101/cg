#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Face> faces)
	: m_vertices(vertices)
	, m_faces(faces)
{
}

void Mesh::Draw()
{
    glPushMatrix();
    glScalef(0.005, 0.005, 0.005);

    for (size_t i = 0; i < m_faces.size(); i++)
    {
        Face face = m_faces[i];
        glBegin(GL_TRIANGLES);
        {
            for (size_t i = 0; i < 3; i++)
            {
                auto vertex = m_vertices[face.vertices[i]];

                glNormal3fv(glm::value_ptr(vertex.normal));

                glTexCoord2fv(glm::value_ptr(vertex.texCoords));

                glVertex3fv(glm::value_ptr(vertex.pos));
            }
        }
        glEnd();
    }

    glPopMatrix();
}
