#ifndef HELPER_H
#define HELPER_H

#include <GL/glut.h>
#include <iostream>

#include "stb_image.h"

// Creates texture and returns the new texture ID
// RGB textures only (can change later)
inline GLuint createTexture(std::string filename) {
	GLuint textureID;
	int width, height, nrChannels;

    // Make sure to flip images for OpenGL
    stbi_set_flip_vertically_on_load(true);

	// Use stb_image to load image files/textures
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 3);

	if(data) {
		glGenTextures(1, &textureID);

		// Bind the new texture and set parameters on binded texture
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		// Load in texture data
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
	else
        std::cout << "Failed to load texture\n";

	stbi_image_free(data);
	return textureID;
}

// Sets the current material based on given material settings
// Each setting requires 4 values
inline void setMaterial(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat emission[4]) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
}

#endif