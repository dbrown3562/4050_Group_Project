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
	void loadTexture();
private:
	GLuint textureID;
};

class Room{
public:
	Room();
	void display();
	void loadRoomTextures();
	void loadMoreRoomTextures();
	void loadMoreRoomTexturesII();
	void floor();
	void ceiling();
	void door();
private:
	GLuint floorID;
	GLuint ceilingID;
	GLuint rugID;
	GLuint doorID;
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

class Desk{
public:
	Desk();
	void display();
	void loadDeskTextures();
private:
	GLuint woodGrainID;
	GLuint keyboardID;
};

class Chair{
public:
	Chair();
	void display();
	void loadChairTextures();
private:
	GLuint metalID;
	GLuint woodGrainID;
};

#endif