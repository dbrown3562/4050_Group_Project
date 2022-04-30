#include "objects.h"

ComputerScreen::ComputerScreen() {};

void ComputerScreen::loadTexture() {
    // Lets set our texture
    textureID = createTexture("computer_screen.png");
}

void ComputerScreen::display() {
    glPushMatrix();

    // Enable ambient and diffuse material, can overwrite in object implementation
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

    glTranslatef(0.0, 0.0, 3.0);

    // Create our Computer Screen frame
    glBegin(GL_QUADS);
        // Create the front frame - Left first
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-1.05, -0.05, 0.0);
        glVertex3f(-1.05, 1.05, 0.0);
        glVertex3f(-1.0, 1.05, 0.0);
        glVertex3f(-1.0, -0.05, 0.0);

        glVertex3f(-1.05, -0.05, 0.05);
        glVertex3f(-1.05, 1.05, 0.05);
        glVertex3f(-1.0, 1.05, 0.05);
        glVertex3f(-1.0, -0.05, 0.05);

        glVertex3f(-1.05, -0.05, 0.0);
        glVertex3f(-1.05, 1.05, 0.0);
        glVertex3f(-1.05, 1.05, 0.05);
        glVertex3f(-1.05, -0.05, 0.05);

        // Create the front frame - Right
        glVertex3f(1.0, -0.05, 0.0);
        glVertex3f(1.0, 1.05, 0.0);
        glVertex3f(1.05, 1.05, 0.0);
        glVertex3f(1.05, -0.05, 0.0);

        glVertex3f(1.0, -0.05, 0.05);
        glVertex3f(1.0, 1.05, 0.05);
        glVertex3f(1.05, 1.05, 0.05);
        glVertex3f(1.05, -0.05, 0.05);

        glVertex3f(1.0, -0.05, 0.05);
        glVertex3f(1.0, 1.05, 0.05);
        glVertex3f(1.0, 1.05, 0.0);
        glVertex3f(1.0, -0.05, 0.0);

        // Create the front frame - Top
        glVertex3f(-1.0, 1.0, 0.0);
        glVertex3f(-1.0, 1.05, 0.0);
        glVertex3f(1.0, 1.05, 0.0);
        glVertex3f(1.0, 1.0, 0.0);

        // Create the front frame - Bottom
        glVertex3f(-1.0, -0.05, 0.0);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, -0.05, 0.0);
    glEnd();

    // Create a quad and map our texture for the screen
    // Must initial color to white to apply texture correctly
    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        // Create display - with texture
        glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 0.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);

    glPopMatrix();
}