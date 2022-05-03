#include "objects.h"

//Height and width, as well as rotation items.
#define WIDTH 800
#define HEIGHT 600

GLfloat xRotation, yRotation;

float fanRotation = 0.0;

//All classes defined outside of the loop to prevent continuous instantiation
Skybox skybox = Skybox();
Room room = Room();

ComputerScreen compScreen = ComputerScreen();
Desk desk = Desk();
Chair chair = Chair();
Dresser dresser = Dresser();
Nightstand nightstand = Nightstand();
Bed bed = Bed();
Lamp lamp = Lamp();
Fan fan = Fan();
Curtains curtains = Curtains();



int firstIteration = 1;


//------------------------------------------------------------------------------------------------------------------------------------------

//===============================================================================//
//								 HELPER FUNCTIONS								 //
//===============================================================================//

//Make sure that the room doesn't go crazy
int addY(int y){
	if(y >= 90){
		return y;
	}
	return (y + 3);
}

int subY(int y){
	if(y <= -90){
		return y;
	}
	return (y - 3);
}



//===============================================================================//
//							FUNCTIONS TO BE IMPLEMENTED							 //
//===============================================================================//


//This is where all of our classes will be displayed
void display(void){
	//Get started
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen
	glLoadIdentity();

	//Handle Rotations (Rotate from the view point instead of the object perspective)
	//Viewing position will be (0.0,0.0,0.0)
	glRotatef(yRotation, 1.0, 0.0, 0.0);
    glRotatef(xRotation, 0.0, 1.0, 0.0);

	//Call all of the class display functions


    //Skybox and Room must be displayed first
    skybox.display();
    room.display();

    desk.display();
    chair.display();
    curtains.display();
    dresser.display();
    bed.display();
    nightstand.display();
    lamp.display();
    fan.display(fanRotation);
	compScreen.display();

	fanRotation += 1;

	// Our fan light
	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.0);
	glutSolidSphere(0.25, 10, 10);
	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lampAmbient[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lampDiffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lampSpecular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lampSpotDirection[] = {0.0, 0.0, -1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, lampAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lampDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lampSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.7);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05);
	glEnable(GL_LIGHT0);
	glPopMatrix();

	//End the display loop
	glFlush();
	glutSwapBuffers(); 
}


void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			yRotation = subY(yRotation);
			break;
		case 's':
			yRotation = addY(yRotation);
			break;
		case 'a':
			xRotation -= 3;
			break;
		case 'd':
			xRotation += 3;
			break;
		default:
			break;
	}
}


//===============================================================================//
//							SHOULD ALL BE GOOD BELOW							 //
//===============================================================================//



//Reshape the perspective to be within bounds of the window
void reshape(int x, int y){
    if(x == 0 || y == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

//Initialize the window
void initWindow()
/* Clear the image area, and set up the coordinate system */
{
    glViewport(0.0f, 0.0f, WIDTH, HEIGHT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
    glOrtho(0,WIDTH,0,HEIGHT,0, 1);
    glMatrixMode( GL_MODELVIEW );

	// Setup lighting
	GLfloat globalAmbient[] = {0.2, 0.2, 0.2, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
}


//Main running loop
int main(int argc, char *argv[]){
		glutInit(&argc, argv);
        glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
        glutInitWindowSize(WIDTH,HEIGHT);
        glutCreateWindow("CG4050/6050 TEAM #7: Check out our Room!");

        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutIdleFunc(display);
        glutKeyboardFunc(keyboard);

        if(firstIteration){
			// Textures must load after OpenGL context creation...for now, just calling it here
			compScreen.loadTexture();
			room.loadRoomTextures();
			room.loadMoreRoomTextures();
			room.loadMoreRoomTexturesII();
			skybox.loadTexture();
			desk.loadDeskTextures();
			chair.loadChairTextures();
			curtains.loadTexture();
			dresser.loadTexture();
			bed.loadTexture();
			nightstand.loadTexture();
			lamp.loadTexture();
			fan.loadTexture();
			firstIteration = 0;
		}

        initWindow();
        glutMainLoop();
	return 0;
}