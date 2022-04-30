#include "objects.h"

Bed::Bed(){

}

void Bed::loadTexture(){
	woodGrainID = createTexture("img/wood.jpg");
	fabricID = createTexture("img/fabricA.jpg");
}

void drawMattressAndPillow(GLuint tex){
	//Mattress is one big rectangular prism
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT );
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

		//make it like a dark blue//comfortor... should be a bit extra "puffy"
		glColor3f(0.0f, 0.0f, 0.3f);

		//Bases
		glTexCoord2f(0.0, 1.0); glVertex3f((0.95), -1.9f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((4.99), -1.9f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((4.99), -1.9f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.95), -1.9f, -2.95);

   		glTexCoord2f(0.0, 1.0); glVertex3f((0.95), -1.27f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((4.99), -1.27f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((4.99), -1.27f, -2.92);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.95), -1.27f, -2.92);

   		//Raise the 2 sides anyone will see
		glTexCoord2f(0.0, 1.0); glVertex3f((.95), -1.27f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((.95), -1.9f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((.95), -1.9f, -2.92);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((.95), -1.27f, -2.92);

		glTexCoord2f(0.0, 1.0); glVertex3f((5.0), -1.9f, -2.92);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((5.0), -1.27f, -2.92);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((0.95), -1.27f, -2.92);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.95), -1.9f, -2.92);

   		//Make some not dark blue (like white sheets)
   		glColor3f(1.0f,1.0f,1.0f);
   		glTexCoord2f(0.0, 1.0); glVertex3f((4.99), -2.19f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((5.99), -2.19f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((5.99), -2.19f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((4.99), -2.19f, -2.95);

   		glTexCoord2f(0.0, 1.0); glVertex3f((4.99), -1.3f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((5.99), -1.3f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((5.99), -1.3f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((4.99), -1.3f, -2.95);

   		//Raise the 2 sides anyone will see
		glTexCoord2f(0.0, 1.0); glVertex3f((4.99), -1.3f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((4.99), -2.19f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((4.99), -2.19f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((4.99), -1.3f, -2.95);

		glTexCoord2f(0.0, 1.0); glVertex3f((6.0), -2.19f, -2.95);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((6.0), -1.3f, -2.95);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((4.99), -1.3f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((4.99), -2.19f, -2.95);


   		//Pillow (no texture)
   		glDisable(GL_TEXTURE_2D);
   		glVertex3f(6.0, -1.1, -5.5);
   		glVertex3f(5.0, -1.1, -5.5);
   		glVertex3f(5.0, -1.1, -3.45);
   		glVertex3f(6.0, -1.1, -3.45);

   		glVertex3f(5.0, -1.1, -5.5);
   		glVertex3f(5.0, -1.3, -5.5);
   		glVertex3f(5.0, -1.3, -3.45);
   		glVertex3f(5.0, -1.1, -3.45);

   		glVertex3f(5.0, -1.1, -3.45);
   		glVertex3f(5.0, -1.3, -3.45);
   		glVertex3f(6.0, -1.3, -3.45);
   		glVertex3f(6.0, -1.1, -3.45);


	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void drawBedFrame(GLuint tex){
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT );
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glColor3f(.8, .8, .8);
	    for(int i = 0; i < 2; i++){
    		for(int j = 0; j < 2; j++){
    			glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*5), -2.5f, -3.0-i*3);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*5), -2.5f, -3.0-i*3);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*5), -2.2f, -3.0-i*3);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*5), -2.2f, -3.0-i*3);

    		    glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*5), -2.5f, -2.9-i*3);
	    		glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*5), -2.5f, -2.9-i*3);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*5), -2.2f, -2.9-i*3);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*5), -2.2f, -2.9-i*3);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((5.99-j*5), -2.5f, -3.0-i*3);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.99-j*5), -2.5f, -2.9-i*3);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.99-j*5), -2.2f, -2.9-i*3);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.99-j*5), -2.2f, -3.0-i*3);

    	    	glTexCoord2f(0.0, 1.0); glVertex3f((5.9-j*5), -2.5f, -3.0-i*3);
    			glTexCoord2f(1.0, 1.0);	glVertex3f((5.9-j*5), -2.5f, -2.9-i*3);
    			glTexCoord2f(1.0, 0.0);	glVertex3f((5.9-j*5), -2.2f, -2.9-i*3);
    			glTexCoord2f(0.0, 0.0);	glVertex3f((5.9-j*5), -2.2f, -3.0-i*3);
    		}
    	}

    //Create the frame frame part
    	glTexCoord2f(0.0, 1.0); glVertex3f((0.9), -2.2f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((5.99), -2.2f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((5.99), -2.2f, -2.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.9), -2.2f, -2.9);

   	//Four more parts of the wood frame
   		glTexCoord2f(0.0, 1.0); glVertex3f((0.9), -2.2f, -2.9);
   		glTexCoord2f(4.0, 1.0);	glVertex3f((5.99), -2.2f, -2.9);
   		glTexCoord2f(4.0, 0.0);	glVertex3f((5.99), -1.9f, -2.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.9), -1.9f, -2.9);

   		glTexCoord2f(0.0, 1.0); glVertex3f((0.9), -2.2f, -6.0);
   		glTexCoord2f(3.0, 1.0);	glVertex3f((0.9), -1.9f, -6.0);
   		glTexCoord2f(3.0, 0.0);	glVertex3f((0.9), -1.9f, -2.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.9), -2.2f, -2.9);

      	glTexCoord2f(0.0, 1.0); glVertex3f((0.9), -1.9f, -2.95);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((5.99), -1.9f, -2.95);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((5.99), -1.9f, -2.9);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.9), -1.9f, -2.9);

	  	glTexCoord2f(0.0, 1.0); glVertex3f((0.9), -1.9f, -6.0);
   		glTexCoord2f(1.0, 1.0);	glVertex3f((0.95), -1.9f, -6.0);
   		glTexCoord2f(1.0, 0.0);	glVertex3f((0.95), -1.9f, -2.95);
   		glTexCoord2f(0.0, 0.0);	glVertex3f((0.9), -1.9f, -2.95);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Bed::display(){
	// Enable ambient and diffuse material, can overwrite in object implementation
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	
	drawBedFrame(woodGrainID);
	drawMattressAndPillow(fabricID);

	glDisable(GL_COLOR_MATERIAL);
}