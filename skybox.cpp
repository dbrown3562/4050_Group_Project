#include "objects.h"

Skybox::Skybox() {}

//Simply create a big blue cube
//Maybe add a convincing sky texture later
//It is just a big cube.
void Skybox::display(){
	glColor3f(0.4f, 0.4f, 1.0f);
	glutSolidCube(10.0);
}