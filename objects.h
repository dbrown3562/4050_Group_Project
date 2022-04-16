#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include <math.h>

#include "helper.h"

class Skybox{
public:
	Skybox();
	void display();
};

class Room{
public:
	Room();
	void display();
};

//Due to the room, the base of every object connected to the ground henceforth is at -2.5f.

class ComputerScreen {
public:
	ComputerScreen();
	void display();
	void loadTexture();
private:
	GLuint textureID;
};

#endif