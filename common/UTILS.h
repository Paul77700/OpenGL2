#ifndef UTILS_CLASS_H
#define UTILS_CLASS_H
#include <GLM/glm.hpp>
#include <GL/glew.h>
#include <vector>
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};
class UTILS
{
	public:
	GLuint ID;

	UTILS();
	UTILS(std::vector<Vertex>& vertices);
	UTILS(std::vector<GLuint>& indices);

	void linkAttribVao(UTILS& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void bindVao();
	void unbindVao();
	void deleteVao();
	void bindVbo();
	void unbindVbo();
	void deleteVbo();
	void bindEbo();
	void unbindEbo();
	void deleteEbo();
};
#endif