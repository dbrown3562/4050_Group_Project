#include "objects.h"

Room::Room() {}


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
		glVertex3f(-6.0f, 0.8f, -6.0f);
		glVertex3f(-6.0f, 1.5f, -6.0f);
		glVertex3f(6.0f, 1.5f, -6.0f);
		glVertex3f(6.0f, 0.8f, -6.0f);
	glEnd();

	//Left
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, 1.5f, -6.0f);
		glVertex3f(-2.0f, 1.5f, -6.0f);
		glVertex3f(-2.0f, -2.5f, -6.0f);
	glEnd();

	//Right
	glBegin(GL_QUADS);
		glVertex3f(2.0f, -2.5f, -6.0f);
		glVertex3f(2.0f, 1.5f, -6.0f);
		glVertex3f(6.0f, 1.5f, -6.0f);
		glVertex3f(6.0f, -2.5f, -6.0f);
	glEnd();

	//Interior quads (darker color to distinguish)
	glColor3f(.8f, .8f, .6f);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, -1.0f, -6.0f);
		glVertex3f(-2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.0f);

		glVertex3f(-2.0f, 0.8f, -6.0f);
		glVertex3f(-2.0f, 0.8f, -6.2f);
		glVertex3f(2.0f, 0.8f, -6.2f);
		glVertex3f(2.0f, 0.8f, -6.0f);

		glVertex3f(-2.0f, 0.8f, -6.0f);
		glVertex3f(-2.0f, 0.8f, -6.2f);
		glVertex3f(-2.0f, -1.0f, -6.2f);
		glVertex3f(-2.0f, -1.0f, -6.0f);

		glVertex3f(2.0f, 0.8f, -6.0f);
		glVertex3f(2.0f, 0.8f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.2f);
		glVertex3f(2.0f, -1.0f, -6.0f);
	glEnd();

}

void window(){ //We probably want a reflective texture here
	glColor4f(1.0f, 1.0f, 1.0f, 0.2f); //Make transparent
	//Only need first and second quads
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, 0.8f, -6.0f);
		glVertex3f(-2.0f, -1.0f, -6.0f);
		glVertex3f(2.0f, -1.0f, -6.0f);
		glVertex3f(2.0f, 0.8f, -6.0f);
	glEnd();

	//Add vertical and horizontal cross to make it more realistic
	glColor3f(0.9f,0.9f,0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, -0.08f, -6.0f);
		glVertex3f(-2.0f, -0.12f, -6.0f);
		glVertex3f(2.0f, -0.12f, -6.0f);
		glVertex3f(2.0f, -0.08f, -6.0f);

		glVertex3f(-0.02f, 0.8f, -6.0f);
		glVertex3f(-0.02f, -1.0f, -6.0f);
		glVertex3f(0.02f, -1.0f, -6.0f);
		glVertex3f(0.02f, 0.8f, -6.0f);
	glEnd();	
}

//Second wall will be on the right wall
void wall2(){
	glBegin(GL_QUADS);
		glVertex3f(6.0f, -2.5f, -6.0f);
		glVertex3f(6.0f, 1.5f, -6.0f);
		glVertex3f(6.0f, 1.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, 6.0f);
	glEnd();
}

//Left wall
void wall3(){
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, 1.5f, -6.0f);
		glVertex3f(-6.0f, 1.5f, 6.0f);
		glVertex3f(-6.0f, -2.5f, 6.0f);
	glEnd();
}

//Back wall
void wall4(){
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, 6.0f);
		glVertex3f(-6.0f, 1.5f, 6.0f);
		glVertex3f(6.0f, 1.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, 6.0f);
	glEnd();
}

//Ceiling
void ceiling(){
	//Maybe add popcorn ceiling texture??
	glColor3f(1.0f,1.0f,0.95f);
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, 1.5f, -6.0f);
		glVertex3f(-6.0f, 1.5f, 6.0f);
		glVertex3f(6.0f, 1.5f, 6.0f);
		glVertex3f(6.0f, 1.5f, -6.0f);
	glEnd();
}

//Floor
void floor(){
	//Maybe add wood texture? Otherwise dark brown..
	glColor3f(0.5f,0.35f,0.05f);
	glBegin(GL_QUADS);
		glVertex3f(-6.0f, -2.5f, -6.0f);
		glVertex3f(-6.0f, -2.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, 6.0f);
		glVertex3f(6.0f, -2.5f, -6.0f);
	glEnd();
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
}