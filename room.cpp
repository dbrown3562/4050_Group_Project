#include "objects.h"

Room::Room() {}

void Room::loadRoomTextures(){
	floorID = createTexture("img/floor.jpg");
	ceilingID = createTexture("img/ceiling.jpg");
}

void Room::loadMoreRoomTextures(){
	rugID = createTexture("img/Rug.jpg");
}

void Room::loadMoreRoomTexturesII(){
	doorID = createTexture("img/door.png");
}



//Each wall has 6 sides, to have a little bit of depth. The wall with a window will have more sides.
//Each wall will be 6f distance for the origin point and will be 12f wide and .2f thick. It will be 4f high.
//'Character' should be 2.5f higher than the walls. 

//First wall has the window and will be front and center.
//Only this wall has any reason to have depth, also.
//This wall consists of 4 different cubes
void wall1(){
	//Bottom Quad
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, -1.0f, -6.0f);
		glVertex3f(6.0f, -1.0f, -6.0f);
		glVertex3f(6.0f, -2.5f, -6.0f);
	glEnd();

	//Top
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, 1.8f, -6.0f);
		glVertex3f(-6.0f, 2.5f, -6.0f);
		glVertex3f(6.0f, 2.5f, -6.0f);
		glVertex3f(6.0f, 1.8f, -6.0f);
	glEnd();

	//Left
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, 2.5f, -6.0f);
		glVertex3f(-2.0f, 2.5f, -6.0f);
		glVertex3f(-2.0f, -2.5f, -6.0f);
	glEnd();

	//Right
	glBegin(GL_QUADS);
		glVertex3f(2.0f, -2.5f, -6.0f);
		glVertex3f(2.0f, 2.5f, -6.0f);
		glVertex3f(6.0f, 2.5f, -6.0f);
		glVertex3f(6.0f, -2.5f, -6.0f);
	glEnd();

	//Interior quads (darker color to distinguish)
	glColor3f(.8f, .8f, .6f);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, -1.0f, -6.0f);
		glVertex3f(-2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.0f);

		glVertex3f(-2.0f, 1.8f, -6.0f);
		glVertex3f(-2.0f, 1.8f, -6.2f);
		glVertex3f(2.0f, 1.8f, -6.2f);
		glVertex3f(2.0f, 1.8f, -6.0f);

		glVertex3f(-2.0f, 1.8f, -6.0f);
		glVertex3f(-2.0f, 1.8f, -6.2f);
		glVertex3f(-2.0f, -1.0f, -6.2f);
		glVertex3f(-2.0f, -1.0f, -6.0f);

		glVertex3f(2.0f, 1.8f, -6.0f);
		glVertex3f(2.0f, 1.8f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.0f);
	glEnd();

}

void window(){ //We probably want a reflective texture here
	glColor4f(1.0f, 1.0f, 1.0f, 0.2f); //Make transparent
	//Only need first and second quads
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, 1.8f, -6.0f);
		glVertex3f(-2.0f, -1.0f, -6.0f);
		glVertex3f(2.0f, -1.0f, -6.0f);
		glVertex3f(2.0f, 1.8f, -6.0f);
	glEnd();

	//Add vertical and horizontal cross to make it more realistic
	glColor3f(0.9f,0.9f,0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, 0.50f, -5.99f);
		glVertex3f(-2.0f, 0.54f, -5.99f);
		glVertex3f(2.0f, 0.54f, -5.99f);
		glVertex3f(2.0f, 0.50f, -5.99f);

		glVertex3f(-0.02f, 1.8f, -5.99f);
		glVertex3f(-0.02f, -1.0f, -5.99f);
		glVertex3f(0.02f, -1.0f, -5.99f);
		glVertex3f(0.02f, 1.8f, -5.99f);
	glEnd();	
}

//Second wall will be on the right wall
void wall2(){
	glBegin(GL_QUADS);
		glVertex3f(6.0f, -2.5f, -6.0f);
		glVertex3f(6.0f, 2.5f, -6.0f);
		glVertex3f(6.0f, 2.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, 6.0f);
	glEnd();
}

//Left wall
void wall3(){
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, 2.5f, -6.0f);
		glVertex3f(-6.0f, 2.5f, 6.0f);
		glVertex3f(-6.0f, -2.5f, 6.0f);
	glEnd();
}

//Back wall
void wall4(){
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, 6.0f);
		glVertex3f(-6.0f, 2.5f, 6.0f);
		glVertex3f(6.0f, 2.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, 6.0f);
	glEnd();
}

//Ceiling
void Room::ceiling(){
	glBindTexture(GL_TEXTURE_2D, ceilingID);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glEnable(GL_TEXTURE_2D);
	//Maybe add popcorn ceiling texture??
	glColor3f(1.0f,1.0f,0.95f);
	glBegin(GL_QUADS);
		glTexCoord2f(3.0, 0.0); glVertex3f(-6.0f, 2.5f, -6.0f);
		glTexCoord2f(3.0, 3.0); glVertex3f(-6.0f, 2.5f, 6.0f);
		glTexCoord2f(0.0, 3.0); glVertex3f(6.0f, 2.5f, 6.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(6.0f, 2.5f, -6.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//Floor
void Room::floor(){
	glBindTexture(GL_TEXTURE_2D, floorID);
    glEnable(GL_TEXTURE_2D);
	//Maybe add wood texture? Otherwise dark brown..
	glColor3f(0.5f,0.35f,0.05f);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.0); glVertex3f(-6.0f, -2.5f, -6.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-6.0f, -2.5f, 6.0f);
		glTexCoord2f(0.0, 1.0); glVertex3f(6.0f, -2.5f, 6.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(6.0f, -2.5f, -6.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//Rug
void rug(GLuint rug){
	glBindTexture(GL_TEXTURE_2D, rug);
    glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.0); glVertex3f(-2.5f, -2.49f, -3.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-2.5f, -2.49f, 3.0f);
		glTexCoord2f(0.0, 1.0); glVertex3f(2.5f, -2.49f, 3.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(2.5f, -2.49f, -3.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
}

void Room::door(){
	glBindTexture(GL_TEXTURE_2D, doorID);
    glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5.99f, 1.4f, 5.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5.99f, 1.4f, 3.0f);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5.99f, -2.5f, 3.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5.99f, -2.5f, 5.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Room::doorII(){
	glBindTexture(GL_TEXTURE_2D, doorID);
    glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5.99f, 1.4f, -5.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5.99f, 1.4f, -3.0f);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5.99f, -2.5f, -3.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5.99f, -2.5f, -5.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
}


void Room::display(){
	glColor3f(1.0f, 1.0f, 0.9f); //Try for a cream color for the walls.
	wall2();
	wall3();
	wall4();
	wall1();
	window();
	ceiling();
	floor();
	rug(rugID);
	door();
	doorII();
}