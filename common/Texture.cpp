#include "Texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot)
{
     
    int width, height, numChannels;
    type = texType;
    stbi_set_flip_vertically_on_load(true);

    unsigned char* imageData = stbi_load(image, &width, &height, &numChannels, 0);
    if (!imageData) {
        throw std::runtime_error("Failed to load texture: ");
    }

    glGenTextures(1, &ID);

    glActiveTexture(GL_TEXTURE0 + slot);
    unit = slot;
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLenum format;
    if (numChannels == 4) {
        format = GL_RGBA;
    }
    else if (numChannels == 3) {
        format = GL_RGB;
    }
    else if (numChannels == 1) {
        format = GL_RED;
    }
    else {
        stbi_image_free(imageData);
        throw std::invalid_argument("Invalid number of color channels in texture: ");
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(imageData);

    glBindTexture(GL_TEXTURE_2D, 0);

}

void Texture::texUnit(GLShader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.GetProgram(), uniform);
	glUseProgram(shader.GetProgram());
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}