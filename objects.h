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
	void doorII();
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

class Curtains{
public:
	Curtains();
	void display();
	void loadTexture();
private:
	GLuint metalID;
	GLuint fabricID;
};

class Dresser{
public:
	Dresser();
	void display();
	void loadTexture();
private:
	GLuint woodGrainID;
	GLuint drawerID;
};

class Bed{
public:
	Bed();
	void display();
	void loadTexture();
private:
	GLuint woodGrainID;
	GLuint fabricID;
};

class Nightstand{
public:
	Nightstand();
	void display();
	void loadTexture();
private:
	GLuint woodGrainID;
};

class Lamp{
public:
	Lamp();
	void display();
	void loadTexture();
private:
	GLuint metalID;
	GLuint fabricID;
};


class Fan{
public:
	Fan();
	void display(float);
	void loadTexture();
private:
	GLuint metalID;
	GLuint woodGrainID;
};


#endif