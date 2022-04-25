#include "objects.h"

Skybox::Skybox() {}

void Skybox::loadTexture() {
    // Lets set our texture
    textureID = createTexture("img/outside2.jpg");
}

//Simply create a big blue cube
//Maybe add a convincing sky texture later
//It is just a big cube.
void Skybox::display(){
	glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
	
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-3.5f, 1.5f, -10.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, -2.8f, -10.0f);
		glTexCoord2f(1.0, 0.0); glVertex3f(3.5f, -2.8f, -10.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(3.5f, 1.5f, -10.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}