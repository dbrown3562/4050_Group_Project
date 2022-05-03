#include "objects.h"

Lamp::Lamp(){}

void Lamp::loadTexture(){
	metalID = createTexture("img/metal.jpg");
	fabricID = createTexture("img/fabricA.jpg");
}

void coneTop(GLuint tex){
	//Display the cone top of the object
	//glEnable(GL_TEXTURE_2D);
   	//glBindTexture(GL_TEXTURE_2D, tex);

	GLfloat ambient[] = {0.8, 0.0, 0.8, 1.0};
	GLfloat diffuse[] = {0.2, 0.0, 0.2, 1.0};
	GLfloat specular[] = {0.1, 0.1, 0.1, 1.0};
	GLfloat emission[] = {0.0, 0.0, 0.0, 1.0};
	setMaterial(ambient, diffuse, specular, emission);
	glColor4f(1.0,0.0,1.0, 1.0f);

	float radius = .5;
	float radius2 = .4;
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <= 360; i+=10){
		float angle = (float)i * M_PI/180.0f;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		float x2 = radius2 * cos(angle);
		float y2 = radius2 * sin(angle);
		glVertex3f(5.4+x,.5,-1.9+y);
		glVertex3f(5.4+x2,1.5,-1.9+y2);
		//glTexCoord2f(1.0,0.0);glTexCoord2f(1.0,1.0);glTexCoord2f(0.0,1.0);glTexCoord2f(0.0,0.0);
	}
	glEnd();
}


void Lamp::display(){
	//Display the lamp on the nightstand
	//Lamp is going to be a circle base, a small rod, and a sphere "light"

	// Sample point light
	// TODO: MAKE LAMP EMISSIVE
	glPushMatrix();
	glTranslated(5.4, 0.8, -1.9);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, -1.0, 0.0);
	glEnd();
	glutSolidSphere(0.2, 20, 20);

	GLfloat lampAmbient[] = {1.0, 0.0, 1.0, 1.0};
	GLfloat lampDiffuse[] = {1.0, 0.0, 1.0, 1.0};
	GLfloat lampSpecular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lampPosition[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat lampSpotDirection[] = {0.0, -1.0, 0.0};
	glLightfv(GL_LIGHT1, GL_AMBIENT, lampAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lampDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lampSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, lampPosition);
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lampSpotDirection);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
	//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.25);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.25);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.25);
	glEnable(GL_LIGHT1);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, metalID);
	glColor3f(1.0,1.0,1.0);
	float radius = .3;
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <= 360; i+=10){
		float angle = (float)i * M_PI/180.0f;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex3f(5.4+x,-.5,-1.9+y);
		glVertex3f(5.4+x,-.4,-1.9+y);
		glTexCoord2f(1.0,0.0);glTexCoord2f(1.0,1.0);glTexCoord2f(0.0,1.0);glTexCoord2f(0.0,0.0);
	}
	glEnd();

	//Rod going up
	glColor3f(1.0,1.0,1.0);
	radius = .03;
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <= 360; i+=40){
		float angle = (float)i * M_PI/180.0f;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex3f(5.4+x,-.5,-1.9+y);
		glVertex3f(5.4+x,1.0,-1.9+y);
		glTexCoord2f(1.0,0.0);glTexCoord2f(1.0,1.0);glTexCoord2f(0.0,1.0);glTexCoord2f(0.0,0.0);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);

	coneTop(fabricID);
}
