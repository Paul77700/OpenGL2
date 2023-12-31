#define GLEW_STATIC 1
#include "../common/tiny_obj_loader.h"

#include <iostream>
#include<string>
#if _MSC_VER
#define DLL_EXPORT _declspec(dllexport)
#else
#define DLL_EXPORT  
#endif

extern "C" {
	DLL_EXPORT uint32_t NvOptimusEnablement = 0x00000001;
	// DLL_EXPORT int AmdPowerXpressRequestHighPerformance = 1;
}

#include "../common/Camera.h"
#include "../common/Texture.h"
#include "../common/UTILS.h"

// Vertices coordinates
// Vertices coordinates
Vertex vertices[] =
{
	// Face avant
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},

	// Face arri�re
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)},

	// Face gauche
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},

	// Face droite
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},

	// Face sup�rieure
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},

	// Face inf�rieure
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)}
};

// Indices
GLuint indices[] =
{
	// Face avant
	0, 1, 2,
	2, 3, 0,

	// Face arri�re
	4, 5, 6,
	6, 7, 4,

	// Face gauche
	8, 9, 10,
	10, 11, 8,

	// Face droite
	12, 13, 14,
	14, 15, 12,

	// Face sup�rieure
	16, 17, 18,
	18, 19, 16,

	// Face inf�rieure
	20, 21, 22,
	22, 23, 20
};

// Vertices du deuxi�me cube
Vertex vertices2[] =
{
Vertex{ glm::vec3(-1.5f, 2.5f, 7.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 2.5f, 7.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 7.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(-1.5f, 3.5f, 7.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) },

// Face arri�re
Vertex{ glm::vec3(-1.5f, 2.5f, 3.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 2.5f, 3.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 3.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(-1.5f, 3.5f, 3.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f) },

// Face gauche
Vertex{ glm::vec3(-1.5f, 2.5f, 3.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(-1.5f, 2.5f, 7.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(-1.5f, 3.5f, 7.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(-1.5f, 3.5f, 3.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },

// Face droite
Vertex{ glm::vec3(1.5f, 2.5f, 3.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 2.5f, 7.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 7.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 3.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },

// Face sup�rieure
Vertex{ glm::vec3(-1.5f, 3.5f, 3.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 3.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 3.5f, 7.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(-1.5f, 3.5f, 7.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) },

// Face inf�rieure
Vertex{ glm::vec3(-1.5f, 2.5f, 3.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 2.5f, 3.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
Vertex{ glm::vec3(1.5f, 2.5f, 7.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
Vertex{ glm::vec3(-1.5f, 2.5f, 7.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f) }
};



// Indices du deuxi�me cube
GLuint indices2[] =
{
	0, 1, 2, 2, 3, 0,   // Face avant
	4, 5, 6, 6, 7, 4,   // Face arri�re
	8, 9, 10, 10, 11, 8, // Face gauche
	12, 13, 14, 14, 15, 12, // Face droite
	16, 17, 18, 18, 19, 16, // Face sup�rieure
	20, 21, 22, 22, 23, 20 // Face inf�rieure
};






const unsigned int width = 1000;
const unsigned int height = 700;
struct Model
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;
};

Model loadModel(const std::string& filename)
{
	Model model;

	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename.c_str()))
	{
		// Erreur de chargement du mod�le
		// G�rez l'erreur de chargement du mod�le ici
		return model;
	}

	// Parcours des vertices
	for (const auto& shape : shapes)
	{
		for (const auto& index : shape.mesh.indices)
		{
			glm::vec3 vertex;
			vertex.x = attrib.vertices[3 * index.vertex_index + 0];
			vertex.y = attrib.vertices[3 * index.vertex_index + 1];
			vertex.z = attrib.vertices[3 * index.vertex_index + 2];
			model.vertices.push_back(vertex);

			glm::vec2 texCoord;
			texCoord.x = attrib.texcoords[2 * index.texcoord_index + 0];
			texCoord.y = attrib.texcoords[2 * index.texcoord_index + 1];
			model.texCoords.push_back(texCoord);

			glm::vec3 normal;
			normal.x = attrib.normals[3 * index.normal_index + 0];
			normal.y = attrib.normals[3 * index.normal_index + 1];
			normal.z = attrib.normals[3 * index.normal_index + 2];
			model.normals.push_back(normal);

			model.indices.push_back(model.indices.size());
		}
	}

	return model;
}



void drawModel(const Model& model)
{
	// Activation des tableaux de vertex
	glEnableVertexAttribArray(0); // Vertices
	glEnableVertexAttribArray(1); // Coordonn�es de texture
	glEnableVertexAttribArray(2); // Normales

	// Sp�cification des donn�es de vertex
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, model.vertices.data());
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, model.texCoords.data());
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, model.normals.data());

	// Dessin des triangles
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(model.indices.size()), GL_UNSIGNED_INT, model.indices.data());

	// D�sactivation des tableaux de vertex
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}




void drawTwoCubes()
{
	// Tableau des sommets du premier cube
	GLfloat vertices1[] = {
		// Face avant
		  -0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		// Face arri�re
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,

		// Face gauche
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f,  0.5f,

		// Face droite
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,

		 // Face sup�rieure
		 -0.5f,  0.5f,  0.5f,
		  0.5f,  0.5f,  0.5f,
		  0.5f,  0.5f, -0.5f,
		 -0.5f,  0.5f, -0.5f,

		 // Face inf�rieure
		 -0.5f, -0.5f,  0.5f,
		  0.5f, -0.5f,  0.5f,
		  0.5f, -0.5f, -0.5f,
		 -0.5f, -0.5f, -0.5f
	};


	GLfloat colors1[] = {
		// Face avant (rouge)
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		// Face arri�re (vert)
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		// ... autres faces du premier cube ...

	};

	GLfloat colors2[] = {
		// Face avant (bleu)
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		// Face arri�re (jaune)
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};
	// Tableau des sommets du deuxi�me cube (d�cal� en x)
	GLfloat vertices2[] = {
		// Face avant
		0.5f+1.0f, -0.5f+1,  0.5f + 1.0f,
		1.5f + 1.0f, -0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f,  0.5f + 1.0f,  0.5f + 1.0f,
		0.5f + 1.0f,   0.5f + 1.0f,  0.5f + 1.0f,

		// Face arri�re
		0.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f,
		 1.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f,
		 1.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,
		0.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,

		// Face gauche
		0.5f + 1.0f, -0.5f + 1.0f,  0.5f + 1.0f,
		0.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f,
		0.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,
		0.5f + 1.0f,  0.5f + 1.0f,  0.5f + 1.0f,

		// Face droite
		1.5f + 1.0f, -0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f,
		1.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,
		1.5f + 1.0f,  0.5f + 1.0f,  0.5f + 1.0f,

		// Face sup�rieure
		0.5f + 1.0f,  0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f,  0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,
		0.5f + 1.0f,  0.5f + 1.0f, -0.5f + 1.0f,

		// Face inf�rieure
		0.5f + 1.0f, -0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f, -0.5f + 1.0f,  0.5f + 1.0f,
		1.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f,
		0.5f + 1.0f, -0.5f + 1.0f, -0.5f + 1.0f
	};

	// Tableau des indices pour le premier cube
	GLuint indices1[] = {
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		6, 7, 4,
		8, 9, 10,
		10, 11, 8,
		12, 13, 14,
		14, 15, 12,
		16, 17, 18,
		18, 19, 16,
		20, 21, 22,
		22, 23, 20
	};

	// Tableau des indices pour le deuxi�me cube
	GLuint indices2[] = {
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		6, 7, 4,
		8, 9, 10,
		10, 11, 8,
		12, 13, 14,
		14, 15, 12,
		16, 17, 18,
		18, 19, 16,
		20, 21, 22,
		22, 23, 20
	};




	GLShader shader;
	/*shader.LoadVertexShader("vertex_shader.glsl");
	shader.LoadGeometryShader("geometry_shader.glsl");
	shader.LoadFragmentShader("fragment_shader.glsl");*/
	shader.Create();

	// Cr�ation et configuration du VAO pour le premier cube
	GLuint VAO1;
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);

	// Cr�ation et configuration du VBO pour les sommets du premier cube
	GLuint VBO1;
	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Cr�ation et configuration du VBO pour les couleurs du premier cube

	// Cr�ation et configuration de l'EBO pour le premier cube
	GLuint EBO1;
	glGenBuffers(1, &EBO1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);

	// Cr�ation et configuration du VAO pour le deuxi�me cube
	GLuint VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);

	// Cr�ation et configuration du VBO pour les sommets du deuxi�me cube
	GLuint VBO2;
	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);



	GLuint colorVBO1;
	glGenBuffers(1, &colorVBO1);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors1), colors1, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);

	// Cr�ation et configuration du VBO pour les couleurs du deuxi�me cube
	GLuint colorVBO2;
	glGenBuffers(1, &colorVBO2);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors2), colors2, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);



	GLuint EBO2;
	glGenBuffers(1, &EBO2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

	// Dessin du premier cube
	glBindVertexArray(VAO1);
	glUseProgram(shader.GetProgram());  // Liez le programme de shader avant le rendu
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Dessin du deuxi�me cube
	glBindVertexArray(VAO2);
	glUseProgram(shader.GetProgram());  // Liez le programme de shader avant le rendu
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Nettoyage des ressources
	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);
	glDeleteBuffers(1, &EBO1);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteBuffers(1, &EBO2);
	shader.Destroy();
}

void displayGLInfos() {
	std::cout << "Carte Graphique : " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version OpenGL : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "version GLSL : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	int numExtensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
	for (int i = 0; i < numExtensions; i++) {
		std::cout << "Extensions[" << i << "] " << glGetStringi(GL_EXTENSIONS, i) << std::endl;
	}
}



int main() {
	// Initialize GLFW
	if(!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the core profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFW window of 500x500 pixels, with the name "Hello world"
	GLFWwindow* window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

	// Error check if the window fails to create
	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// We can now use GL commands

	// Lights related stuff
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	
	// Texture data
	Texture textures[]
	{
		Texture("planks.png", "diffuse", 0),
		Texture("planksSpec.png", "specular", 1)
	};	
	

	displayGLInfos();

	// Generates Shader object using shaders default.vs.glsl and default.vs.glsl
	GLShader shaderProgram;
	shaderProgram.LoadVertexShader("default.vs.glsl");
	shaderProgram.LoadFragmentShader("default.fs.glsl");
	shaderProgram.Create();
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	std::vector <Vertex> verts2(vertices2, vertices2 + sizeof(vertices2) / sizeof(Vertex));
	std::vector <GLuint> ind2(indices2, indices2 + sizeof(indices2) / sizeof(GLuint));
	


	glm::vec3 floorPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 floorModel = glm::mat4(1.0f);
	glUseProgram(shaderProgram.GetProgram());
	glUniform4f(glGetUniformLocation(shaderProgram.GetProgram(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.GetProgram(), "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);
	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 1.0f, 2.0f));
	// Loop until the user closes the window or another function request the window to close
	while (!glfwWindowShouldClose(window))
	{
		// Handle the current size of the window
		int m_width, m_height;
		glfwGetFramebufferSize(window, &m_width, &m_height);
		glViewport(0, 0, m_width, m_height);

		
		// Specify the color of the background
		glClearColor(0.5f, 0.5f,0.5f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);



		UTILS VAO;
		VAO.bindVao();
		// Generates Vertex Buffer Object and links it to vertices
		UTILS VBO(verts);
		// Generates Element Buffer Object and links it to indices
		UTILS EBO(ind);
		// Links VBO attributes such as coordinates and colors to VAO
		VAO.linkAttribVao(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		VAO.linkAttribVao(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		VAO.linkAttribVao(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		VAO.linkAttribVao(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
		// Unbind all to prevent accidentally modifying them
		VAO.unbindVao();
		VBO.unbindVbo();
		EBO.unbindEbo();

		UTILS VAO2;
		VAO2.bindVao();
		// Generates Vertex Buffer Object and links it to vertices
		UTILS VBO2(verts2);
		// Generates Element Buffer Object and links it to indices
		UTILS EBO2(ind2);
		// Links VBO attributes such as coordinates and colors to VAO
		VAO2.linkAttribVao(VBO2, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		VAO2.linkAttribVao(VBO2, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		VAO2.linkAttribVao(VBO2, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		VAO2.linkAttribVao(VBO2, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
		// Unbind all to prevent accidentally modifying them
		VAO2.unbindVao();
		VBO2.unbindVbo();
		EBO2.unbindEbo();


		glUseProgram(shaderProgram.GetProgram());
		VAO.bindVao();
		VAO2.bindVao();

		// Keep track of how many of each type of textures we have
		unsigned int numDiffuse = 0;
		unsigned int numSpecular = 0;

		for (unsigned int i = 0; i < tex.size(); i++)
		{
			std::string num;
			std::string type = tex[i].type;
			if (type == "diffuse")
			{
				num = std::to_string(numDiffuse++);
			}
			else if (type == "specular")
			{
				num = std::to_string(numSpecular++);
			}
			tex[i].texUnit(shaderProgram, (type + num).c_str(), i);
			tex[i].Bind();
		}


		// Take care of the camera Matrix
		glUniform3f(glGetUniformLocation(shaderProgram.GetProgram(), "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		camera.Matrix(shaderProgram, "camMatrix");

		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

		// Transform the matrices to their correct form
		trans = glm::translate(trans, floorPos);
		rot = glm::mat4_cast(rotation);
		sca = glm::scale(sca, scale);

		// Push the matrices to the vertex shader
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.GetProgram(), "translation"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.GetProgram(), "rotation"), 1, GL_FALSE, glm::value_ptr(rot));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.GetProgram(), "scale"), 1, GL_FALSE, glm::value_ptr(sca));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.GetProgram(), "model"), 1, GL_FALSE, glm::value_ptr(floorModel));

		// Draw the actual mesh
		/*glDrawElements(GL_TRIANGLES, ind.size(), GL_UNSIGNED_INT, 0);
		glDrawElements(GL_TRIANGLES, ind2.size(), GL_UNSIGNED_INT, 0);*/
		Model myModel = loadModel("C:/Users/hadri/Documents/OpenGL2/OpenGL_103_uniform/models/cat.obj");

		drawTwoCubes();
		drawModel(myModel);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}












	// Clear the app before ending the program
	shaderProgram.Destroy();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}