#include "objects.h"

Desk::Desk() {}

void Desk::loadDeskTextures(){
	woodGrainID = createTexture("img/wood.jpg");
	keyboardID = createTexture("img/keyboard.jpg");
}

void keyboard(GLuint tex){
   		//Add a keyboard on the desk
   		//It'll be an ugly triangle (doesn't need a back)
   	glBegin(GL_QUADS);
   		glVertex3f(1.2f, -0.65f, 3.7f);
   		glVertex3f(1.2f, -0.65f, 5.5f);
   		glVertex3f(1.2f, -0.55f, 5.5f);
   		glVertex3f(1.2f, -0.65f, 3.7f);

   		glVertex3f(-0.05f, -0.65f, 3.7f);
   		glVertex3f(-0.05f, -0.65f, 5.5f);
   		glVertex3f(-0.05f, -0.55f, 5.5f);
   		glVertex3f(-0.05f, -0.65f, 3.7f);
   	glEnd();

   		//Keyboard texture
   	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, tex);

   	glBegin(GL_QUADS);
   		glTexCoord2f(1.0,0.0); glVertex3f(1.2f, -0.65f, 3.7f);
   		glTexCoord2f(1.0,1.0); glVertex3f(1.2f, -0.55f, 5.5f);
   		glTexCoord2f(0.0,1.0); glVertex3f(-0.05f, -0.55f, 5.5f);
   		glTexCoord2f(0.0,0.0); glVertex3f(-0.05f, -0.65f, 3.7f);
   	glEnd();
   	glDisable(GL_TEXTURE_2D);
}

void Desk::display(){
	// Enable ambient and diffuse material, can overwrite in object implementation
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	//Desk consists of 4 feet
	//2 are shorter to have some drawer type elements
	//So many rectangles :(

	glBindTexture(GL_TEXTURE_2D, woodGrainID);
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    	//Each leg only needs four quads left set of legs
    	for(int i = 0; i < 2; i++){
    		glTexCoord2f(0.0, 1.0); glVertex3f((1.5), -2.5f, 5.7-i*2);
    		glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -2.5f, 5.7-i*2);
    		glTexCoord2f(1.0, 0.0);	glVertex3f((1.6), -1.1f, 5.7-i*2);
    		glTexCoord2f(0.0, 0.0);	glVertex3f((1.5), -1.1f, 5.7-i*2);

    	    glTexCoord2f(0.0, 1.0); glVertex3f((1.5), -2.5f, 5.9-i*2);
    		glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -2.5f, 5.9-i*2);
    		glTexCoord2f(1.0, 0.0);	glVertex3f((1.6), -1.1f, 5.9-i*2);
    		glTexCoord2f(0.0, 0.0);	glVertex3f((1.5), -1.1f, 5.9-i*2);

    	    glTexCoord2f(0.0, 1.0); glVertex3f((1.6), -2.5f, 5.9-i*2);
    		glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -2.5f, 5.7-i*2);
    		glTexCoord2f(1.0, 0.0);	glVertex3f((1.6), -1.1f, 5.7-i*2);
    		glTexCoord2f(0.0, 0.0);	glVertex3f((1.6), -1.1f, 5.9-i*2);

    	    glTexCoord2f(0.0, 1.0); glVertex3f((1.5), -2.5f, 5.9-i*2);
    		glTexCoord2f(1.0, 1.0);	glVertex3f((1.5), -2.5f, 5.7-i*2);
    		glTexCoord2f(1.0, 0.0);	glVertex3f((1.5), -1.1f, 5.7-i*2);
    		glTexCoord2f(0.0, 0.0);	glVertex3f((1.5), -1.1f, 5.9-i*2);
    	}

    	//wood support beam
    	glTexCoord2f(0.0, 1.0); glVertex3f((1.5), -1.8f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.5), -1.8f, 5.7);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((1.5), -1.6f, 5.7);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.5), -1.6f, 3.7);

   		//Backboard
   		glTexCoord2f(0.0, 1.0); glVertex3f((1.5), -1.9f, 5.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-0.5), -1.9f, 5.7);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -1.1f, 5.7);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.5), -1.1f, 5.7);


    	//Right set of legs
    	for(int i = 0; i < 2; i++){
    		for(int j = 0; j < 2; j++){
    			glTexCoord2f(0.0, 1.0); glVertex3f((-1.5+j), -2.5f, 5.7-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6+j), -2.5f, 5.7-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-1.6+j), -2.0f, 5.7-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-1.5+j), -2.0f, 5.7-i*2);

    		    glTexCoord2f(0.0, 1.0); glVertex3f((-1.5+j), -2.5f, 5.9-i*2);
	    		glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6+j), -2.5f, 5.9-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-1.6+j), -2.0f, 5.9-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-1.5+j), -2.0f, 5.9-i*2);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-1.6+j), -2.5f, 5.9-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6+j), -2.5f, 5.7-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-1.6+j), -2.0f, 5.7-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-1.6+j), -2.0f, 5.9-i*2);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((-1.5+j), -2.5f, 5.9-i*2);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((-1.5+j), -2.5f, 5.7-i*2);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((-1.5+j), -2.0f, 5.7-i*2);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((-1.5+j), -2.0f, 5.9-i*2);
    		}
    	}
    	//Drawer-like item
    	glTexCoord2f(0.0, 1.0); glVertex3f((1.6), -1.1f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -1.1f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((1.6), -0.7f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.6), -0.7f, 3.7);

   		glTexCoord2f(0.0, 1.0); glVertex3f((-0.5), -1.1f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-0.5), -1.1f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -0.7f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 3.7);

       	glTexCoord2f(0.0, 1.0); glVertex3f((1.6), -0.7f, 5.9);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -1.1f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -1.1f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 5.9);
	
		glTexCoord2f(0.0, 1.0); glVertex3f((1.6), -0.7f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.6), -1.1f, 3.7);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -1.1f, 3.7);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 3.7);

    	//Insert knob here later, maybe.


    	//Secondary container kind of like a door area.
    	glTexCoord2f(0.0, 1.0); glVertex3f((-0.5), -2.0f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-0.5), -2.0f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -0.7f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 3.7);

   		glTexCoord2f(0.0, 1.0); glVertex3f((-1.6), -2.0f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6), -2.0f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-1.6), -0.7f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-1.6), -0.7f, 3.7);

       	glTexCoord2f(0.0, 1.0); glVertex3f((-1.6), -0.7f, 5.9);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6), -2.0f, 5.9);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -2.0f, 5.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 5.9);
	
		glTexCoord2f(0.0, 1.0); glVertex3f((-1.6), -0.7f, 3.7);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.6), -2.0f, 3.7);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-0.5), -2.0f, 3.7);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-0.5), -0.7f, 3.7);

   		//Knob here, too, maybe...

   		//Top
   		glTexCoord2f(0.0, 1.0); glVertex3f((1.65), -0.7f, 3.65);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((1.65), -0.7f, 5.95);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((1.65), -0.65f, 5.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.65), -0.65f, 3.65);

   		glTexCoord2f(0.0, 1.0); glVertex3f((-1.65), -0.7f, 3.65);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.65), -0.7f, 5.95);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((-1.65), -0.65f, 5.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((-1.65), -0.65f, 3.65);

       	glTexCoord2f(0.0, 1.0); glVertex3f((-1.65), -0.7f, 3.65);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.65), -0.65f, 3.65);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((1.65), -0.65f, 3.65);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.65), -0.7f, 3.65);
	
		glTexCoord2f(0.0, 1.0); glVertex3f((-1.65), -0.65f, 5.95);
    	glTexCoord2f(1.0, 1.0);	glVertex3f((-1.65), -0.65f, 3.65);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((1.65), -0.65f, 3.65);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((1.65), -0.65f, 5.95);

   		glEnd();
   	glDisable(GL_TEXTURE_2D);
   	keyboard(keyboardID);

	glDisable(GL_COLOR_MATERIAL);
}