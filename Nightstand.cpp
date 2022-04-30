#include "objects.h"

Nightstand::Nightstand(){}

void Nightstand::loadTexture(){
	woodGrainID = createTexture("img/wood.jpg");
}

void Nightstand::display(){
	// Enable ambient and diffuse material, can overwrite in object implementation
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glBindTexture(GL_TEXTURE_2D, woodGrainID);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT );
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glColor3f(.8, .8, .8);
	    for(int i = 0; i < 2; i++){
    		for(int j = 0; j < 2; j++){
    			glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*2), -2.5f, -0.5-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*2), -2.5f, -0.5-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*2), -1.0f, -0.5-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*2), -1.0f, -0.5-i*2);

    		    glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*2), -2.5f, -0.4-i*2);
	    		glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*2), -2.5f, -0.4-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*2), -1.0f, -0.4-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*2), -1.0f, -0.4-i*2);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((5.99-j*2), -2.5f, -0.5-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*2), -2.5f, -0.4-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*2), -1.0f, -0.4-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.99-j*2), -1.0f, -0.5-i*2);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*2), -2.5f, -0.5-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.9-j*2), -2.5f, -0.4-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.9-j*2), -1.0f, -0.4-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*2), -1.0f, -0.5-i*2);
    		}
    	}

    //Add a base to the nightstand
    	glTexCoord2f(0.0, 1.0); glVertex3f((3.91), -2.0f, -0.41);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((3.91), -2.0f, -2.5);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -2.0f, -2.5);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((5.99), -2.0f, -0.41);

  		//Left and right
  	    glTexCoord2f(0.0, 1.0); glVertex3f((3.91), -2.1f, -0.4);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((3.91), -2.1f, -2.5);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((3.91), -2.0f, -2.5);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((3.91), -2.0f, -0.4);

  		glTexCoord2f(0.0, 1.0); glVertex3f((3.9), -2.1f, -0.41);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((5.99), -2.1f, -0.41);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -2.0f, -0.41);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((3.9), -2.0f, -0.41);

  	//Add the top
  		glTexCoord2f(0.0, 1.0); glVertex3f((3.9), -1.0f, -0.4);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((3.9), -1.0f, -2.5);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -1.0f, -2.5);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((5.99), -1.0f, -0.4);

  		glTexCoord2f(0.0, 1.0); glVertex3f((3.9), -1.0f, -0.4);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((3.9), -1.0f, -2.5);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((3.9), -.5f, -2.5);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((3.9), -.5f, -0.4);

  		glTexCoord2f(0.0, 1.0); glVertex3f((3.9), -1.0f, -0.4);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((5.99), -1.0f, -0.4);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -.5f, -0.4);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((3.9), -.5f, -0.4);

  		glTexCoord2f(0.0, 1.0); glVertex3f((3.9), -0.5f, -0.4);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((3.9), -0.5f, -2.5);
  		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -0.5f, -2.5);
  		glTexCoord2f(0.0, 0.0);	glVertex3f((5.99), -0.5f, -0.4);

    glEnd();

	glDisable(GL_COLOR_MATERIAL);
}