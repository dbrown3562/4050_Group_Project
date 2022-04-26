#include "objects.h"

Fan::Fan(){}

void Fan::loadTexture(){
	woodGrainID = createTexture("img/wood.jpg");
	metalID = createTexture("img/metal.jpg");
}

void fanBlade(GLuint tex, float angle){
	//The fanblade is two rectangles. One big and one small connecting piece. It's gonna move ooo~.

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(1.0,0.0); glVertex3f(-.25, 2.0, .3);
		glTexCoord2f(1.0,1.0); glVertex3f(-.25, 2.0, 2.7);
		glTexCoord2f(0.0,1.0); glVertex3f(.25, 2.0, 2.7);
		glTexCoord2f(0.0,0.0); glVertex3f(.25, 2.0, .3);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glRotatef(-angle, 0.0f, 1.0f, 0.0f);


}

void bladeP2(GLuint tex, float angle){
	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, tex);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glColor3f(.5f,.5f,.5f);
		glVertex3f(-.1, 1.99, .02);
		glVertex3f(-.1, 1.99, .4);
		glVertex3f(.1, 1.99, .4);
		glVertex3f(.1, 1.99, .02);
	glEnd();
	glRotatef(-angle, 0.0f, 1.0f, 0.0f);
	glDisable(GL_TEXTURE_2D);
}

void Fan::display(float angle){
	//I want to have it so that the fan blades are moving at all times, if that's a possibility...
	//There will be three fan blades.

	fanBlade(woodGrainID, angle);
	fanBlade(woodGrainID, angle+120);
	fanBlade(woodGrainID, angle+240);
	bladeP2(metalID, angle);
	bladeP2(metalID, angle+120);
	bladeP2(metalID, angle+240);

	//add a downward facing rod
	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, metalID);
	glColor3f(1.0,1.0,1.0);
	float radius = 0.02; //thin
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <= 360; i+=40){
		float angle = (float)i * M_PI/180.0f;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex3f(0.0+y,2.5,0.0+x);
		glVertex3f(0.0+y,1.9,0.0+x);
		glTexCoord2f(1.0,0.0);glTexCoord2f(1.0,1.0);glTexCoord2f(0.0,1.0);glTexCoord2f(0.0,0.0);
	}

	//Add the "bulb"


	glEnd();
	glDisable(GL_TEXTURE_2D);
}