#ifndef UTILS_CLASS_H
#define UTILS_CLASS_H


class UTILS
{
	public:
	GLuint ID;

	UTILS();
	UTILS(GLfloat* vertices, GLsizeiptr size);
	UTILS(GLuint* indices, GLsizeiptr size);

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