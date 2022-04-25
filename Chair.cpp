#include "objects.h"

//Let's make a chair that's at an angle to the desk!

Chair::Chair(){}

void Chair::loadChairTextures(){
	metalID = createTexture("img/metal.jpg");
	woodGrainID = createTexture("img/wood.jpg");
}

void topPart(GLuint tex){
	glBindTexture(GL_TEXTURE_2D, tex);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
    	glTexCoord2f(0.0, 1.0); glVertex3f((0.0), -1.5f, 4.4);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((0.0), -1.5f, 3.3);
    	glTexCoord2f(1.0, 0.0);	glVertex3f((0.0), -1.45f, 3.3);
    	glTexCoord2f(0.0, 0.0);	glVertex3f((0.0), -1.45f, 4.4);

    	glTexCoord2f(0.0, 1.0); glVertex3f((1.0), -1.5f, 4.4);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.0), -1.5f, 3.3);
    	glTexCoord2f(1.0, 0.0);	glVertex3f((1.0), -1.45f, 3.3);
    	glTexCoord2f(0.0, 0.0);	glVertex3f((1.0), -1.45f, 4.4);

    	glTexCoord2f(0.0, 1.0); glVertex3f((1.0), -1.5f, 3.3);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.0), -1.45f, 3.3);
    	glTexCoord2f(1.0, 0.0);	glVertex3f((-0.1), -1.45f, 3.3);
    	glTexCoord2f(0.0, 0.0);	glVertex3f((-0.1), -1.5f, 3.3);

    	glTexCoord2f(0.0, 1.0); glVertex3f((1.0), -1.45f, 4.4);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.0), -1.45f, 3.3);
    	glTexCoord2f(1.0, 0.0);	glVertex3f((-0.1), -1.45f, 3.3);
    	glTexCoord2f(0.0, 0.0);	glVertex3f((-0.1), -1.45f, 4.4);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Chair::display(){
	glBindTexture(GL_TEXTURE_2D, metalID);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);

    	//legs
    	for(int i = 0; i < 2; i++){
    		for(int j = 0; j < 2; j++){
    			glTexCoord2f(0.0, 1.0); glVertex3f((-0.0+j), -2.5f, 4.3-i);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-0.1+j), -2.5f, 4.3-i);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-0.1+j), -1.5f, 4.3-i);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-0.0+j), -1.5f, 4.3-i);

    		    glTexCoord2f(0.0, 1.0); glVertex3f((-0.0+j), -2.5f, 4.4-i);
	    		glTexCoord2f(1.0, 1.0);	glVertex3f((-0.1+j), -2.5f, 4.4-i);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-0.1+j), -1.5f, 4.4-i);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-0.0+j), -1.5f, 4.4-i);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-0.1+j), -2.5f, 4.4-i);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-0.1+j), -2.5f, 4.3-i);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-0.1+j), -1.5f, 4.3-i);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-0.1+j), -1.5f, 4.4-i);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-0.0+j), -2.5f, 4.4-i);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-0.0+j), -2.5f, 4.3-i);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-0.0+j), -1.5f, 4.3-i);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-0.0+j), -1.5f, 4.4-i);
    		}
    	}
    	//seat

    glEnd();
    glDisable(GL_TEXTURE_2D);
    topPart(woodGrainID);
}