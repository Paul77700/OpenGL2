#include"UTILS.h"
#include <GL/glew.h>

UTILS::UTILS(std::vector<GLuint>& indices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

UTILS::UTILS(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

UTILS::UTILS()
{
	glGenVertexArrays(1, &ID);
}

void UTILS::bindEbo()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void UTILS::unbindEbo()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void UTILS::deleteEbo()
{
	glDeleteBuffers(1, &ID);
}

void UTILS::linkAttribVao(UTILS& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.bindVbo();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.unbindVbo();
}

void UTILS::bindVbo()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void UTILS::unbindVbo()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void UTILS::deleteVbo()
{
	glDeleteBuffers(1, &ID);
}

void UTILS::bindVao()
{
	glBindVertexArray(ID);
}

void UTILS::unbindVao()
{
	glBindVertexArray(0);
}

void UTILS::deleteVao()
{
	glDeleteVertexArrays(1, &ID);
}