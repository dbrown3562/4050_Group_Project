#include "objects.h"

Curtains::Curtains(){}

void Curtains::loadTexture(){
	metalID = createTexture("img/metal.jpg");
	fabricID = createTexture("img/fabricA.jpg");
}

void curtainRod(GLuint tex){
	//make a curtain rod cylinder
	//Maybe map textures to it but probably nah.
	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, tex);
	glColor3f(1.0,1.0,1.0);
	float radius = 0.05; //thin
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <= 360; i+=40){
		float angle = (float)i * M_PI/180.0f;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex3f(-2.0,2.0+y,-5.95+x);
		glVertex3f(2.0,2.0+y,-5.95+x);
		glTexCoord2f(1.0,0.0);glTexCoord2f(1.0,1.0);glTexCoord2f(0.0,1.0);glTexCoord2f(0.0,0.0);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Curtains::display(){
	//Curtains are just two rectangles
	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, fabricID);
	glBegin(GL_QUADS);
		glColor4f(1.0f,1.0f,1.0f,.7f);
		glTexCoord2f(1.0,0.0); glVertex3f(-2.0, 2.0, -5.9);
		glTexCoord2f(1.0,1.0); glVertex3f(-2.0, -1.3, -5.9);
		glTexCoord2f(0.0,1.0); glVertex3f(-1.3, -1.3, -5.9);
		glTexCoord2f(0.0,0.0); glVertex3f(-1.3, 2.0, -5.9);

		glTexCoord2f(1.0,0.0); glVertex3f(2.0, 2.0, -5.9);
		glTexCoord2f(1.0,1.0); glVertex3f(2.0, -1.3, -5.9);
		glTexCoord2f(0.0,1.0); glVertex3f(1.3, -1.3, -5.9);
		glTexCoord2f(0.0,0.0); glVertex3f(1.3, 2.0, -5.9);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	curtainRod(metalID);
}