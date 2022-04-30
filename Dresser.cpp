#include "objects.h"

Dresser::Dresser(){}

void Dresser::loadTexture(){
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	woodGrainID = createTexture("img/wood.jpg");
	drawerID = createTexture("img/drawers.jpg");
}

void DrawerFace(GLuint tex){
	glBindTexture(GL_TEXTURE_2D, tex);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.5f);
    	glTexCoord2f(0.0, 1.0); glVertex3f(-3.9, -0.0f, 2.0);
    	glTexCoord2f(1.0, 1.0);	glVertex3f(-3.9, -0.0f, -2.1);
    	glTexCoord2f(1.0, 0.0);	glVertex3f(-3.9, -2.2f, -2.1);
    	glTexCoord2f(0.0, 0.0);	glVertex3f(-3.9, -2.2f, 2.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}


void Dresser::display(){
	// Enable ambient and diffuse material, can overwrite in object implementation
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	//create four feet
	glBindTexture(GL_TEXTURE_2D, woodGrainID);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glColor3f(.8, .8, .8);
	    for(int i = 0; i < 2; i++){
    		for(int j = 0; j < 2; j++){
    			glTexCoord2f(0.0, 1.0); glVertex3f((-3.9-j*2), -2.5f, 2.0-i*4);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-3.99-j*2), -2.5f, 2.0-i*4);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-3.99-j*2), -2.2f, 2.0-i*4);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-3.9-j*2), -2.2f, 2.0-i*4);

    		    glTexCoord2f(0.0, 1.0); glVertex3f((-3.9-j*2), -2.5f, 1.9-i*4);
	    		glTexCoord2f(1.0, 1.0);	glVertex3f((-3.99-j*2), -2.5f, 1.9-i*4);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-3.99-j*2), -2.2f, 1.9-i*4);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-3.9-j*2), -2.2f, 1.9-i*4);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-3.99-j*2), -2.5f, 2.0-i*4);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-3.99-j*2), -2.5f, 1.9-i*4);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-3.99-j*2), -2.2f, 1.9-i*4);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-3.99-j*2), -2.2f, 2.0-i*4);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-3.9-j*2), -2.5f, 2.0-i*4);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-3.9-j*2), -2.5f, 1.9-i*4);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-3.9-j*2), -2.2f, 1.9-i*4);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-3.9-j*2), -2.2f, 2.0-i*4);
    		}
    	}

    //It's basically just a big box
    	glTexCoord2f(0.0, 1.0); glVertex3f(-3.9, -0.0f, 2.0);
    	glTexCoord2f(1.0, 1.0);	glVertex3f(-5.99, -0.0f, 2.0);
    	glTexCoord2f(1.0, 0.0);	glVertex3f(-5.99, -2.2f, 2.0);
    	glTexCoord2f(0.0, 0.0);	glVertex3f(-3.9, -2.2f, 2.0);

    	glTexCoord2f(0.0, 1.0); glVertex3f(-3.9, -0.0f, -2.1);
    	glTexCoord2f(1.0, 1.0);	glVertex3f(-5.99, -0.0f, -2.1);
    	glTexCoord2f(1.0, 0.0);	glVertex3f(-5.99, -2.2f, -2.1);
    	glTexCoord2f(0.0, 0.0);	glVertex3f(-3.9, -2.2f, -2.1);

   	//Top part
    	glTexCoord2f(0.0, 1.0); glVertex3f(-3.85, 0.0f, 2.0);
    	glTexCoord2f(1.0, 1.0);	glVertex3f(-3.85, 0.0f, -2.1);
    	glTexCoord2f(1.0, 0.0);	glVertex3f(-3.85, 0.05f, -2.1);
    	glTexCoord2f(0.0, 0.0);	glVertex3f(-3.85, 0.05f, 2.0);

    	glTexCoord2f(0.0, 1.0); glVertex3f(-3.85, 0.05f, 2.0);
    	glTexCoord2f(1.0, 1.0);	glVertex3f(-3.85, 0.05f, -2.1);
    	glTexCoord2f(1.0, 0.0);	glVertex3f(-5.99, 0.05f, -2.1);
    	glTexCoord2f(0.0, 0.0);	glVertex3f(-5.99, 0.05f, 2.0);


    glEnd();
    glDisable(GL_TEXTURE_2D);

    DrawerFace(drawerID);

	glDisable(GL_COLOR_MATERIAL);
}