#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <conio.h>
#include <math.h>
#include <GL/glut.h>
#include <fstream>
#include <stack>

#define DEG2RAD 57.2957795 
#define M_PI 22/7
float heading;
const float piover180 = 0.0174532925f;
GLfloat sceneroty;
//angle of rotation
float xpos = 80, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;
int view = 0;
float accel = 0;
float cRadius = 10.0f; // our radius distance from our character
bool dPressed = false, aPressed = false, wPressed = false, sPressed = false;
bool out = false;
float lastx, lasty;
int xc = 0, yc = 0;
// Function to Draw our 3d Track
void DrawTrack()
{
	glColor3f(0, 0, 0);
	int trax = 80;
	glBegin(GL_POLYGON);
	glVertex3f(trax - 10, -0.1, -400);
	glVertex3f(trax + 10, -0.1, -400);
	glVertex3f(trax + 10, -0.1, 400);
	glVertex3f(trax - 10, -0.1, 400);
	glEnd();

	glColor3f(1, 1, 1);
	for (int i = -410; i <= 400; i += 10)
	{
		glBegin(GL_POLYGON);
		glVertex3f(trax - 0.1, -0.09, i);
		glVertex3f(trax + 0.1, -0.09, i);
		glVertex3f(trax + 0.1, -0.09, i + 5);
		glVertex3f(trax - 0.1, -0.09, i + 5);
		glEnd();
	}
	glColor3f(0, 0, 0);
	trax = -80;
	glBegin(GL_POLYGON);
	glVertex3f(trax - 10, -0.1, -400);
	glVertex3f(trax + 10, -0.1, -400);
	glVertex3f(trax + 10, -0.1, 400);
	glVertex3f(trax - 10, -0.1, 400);
	glEnd();

	glColor3f(1, 1, 1);
	for (int i = -410; i <= 400; i += 10)
	{
		glBegin(GL_POLYGON);
		glVertex3f(trax - 0.1, -0.09, i);
		glVertex3f(trax + 0.1, -0.09, i);
		glVertex3f(trax + 0.1, -0.09, i + 5);
		glVertex3f(trax - 0.1, -0.09, i + 5);
		glEnd();
	}

	glColor3f(0, 0, 0);
	trax = 410;
	glBegin(GL_POLYGON);
	glVertex3f(90, -0.1, trax - 10);
	glVertex3f(90, -0.1, trax + 10);
	glVertex3f(-90, -0.1, trax + 10);
	glVertex3f(-90, -0.1, trax - 10);
	glEnd();
	glColor3f(1, 1, 1);
	for (int i = -80; i <= 70; i += 10)
	{
		glBegin(GL_POLYGON);
		glVertex3f(i, -0.09, trax - 0.1);
		glVertex3f(i, -0.09, trax + 0.1);
		glVertex3f(i + 5, -0.09, trax - 0.1);
		glVertex3f(i + 5, -0.09, trax + 0.1);
		glEnd();
	}
	glColor3f(0, 0, 0);
	trax = -410;
	glBegin(GL_POLYGON);
	glVertex3f(90, -0.1, trax - 10);
	glVertex3f(90, -0.1, trax + 10);
	glVertex3f(-90, -0.1, trax + 10);
	glVertex3f(-90, -0.1, trax - 10);
	glEnd();

	glColor3f(1, 1, 1);
	for (int i = -80; i <= 70; i += 10)
	{
		glBegin(GL_POLYGON);
		glVertex3f(i, -0.09, trax - 0.1);
		glVertex3f(i, -0.09, trax + 0.1);
		glVertex3f(i + 5, -0.09, trax - 0.1);
		glVertex3f(i + 5, -0.09, trax + 0.1);
		glEnd();
	}

	glColor3f(0, 1.0f, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-6000, -0.14, -6000);
	glVertex3f(6000, -0.14, -6000);
	glVertex3f(6000, -0.14, 6000);
	glVertex3f(-6000, -0.14, 6000);
	glEnd();
	glFlush();
}
// Function to Draw our 3D car
void DrawCar()
{
	glTranslated(xpos, 0.2f, zpos);
	glColor3f(1.0f, 0.0f, 0.0f);
	sceneroty = 360.0f - yrot;
	glRotatef(-sceneroty, 0, 1.0f, 0);
	glutSolidCube(2);
	// Back
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(1, 0.3, 0);
	glVertex3f(1, 0.1, 2.5);
	glVertex3f(-1, 0.1, 2.5);
	glVertex3f(-1, 0.3, 0);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(1, -1, 2.5);
	glVertex3f(1, 0.1, 2.5);
	glVertex3f(-1, 0.1, 2.5);
	glVertex3f(-1, -1, 2.5);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, 2.5);
	glVertex3f(-1, 0.3, 2.5);
	glVertex3f(-1, 0.1, 1);
	glVertex3f(-1, -1, 1);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 0.9, 1);
	glVertex3f(-0.9, 0.4, 1.1);
	glVertex3f(0.9, 0.4, 1.1);
	glVertex3f(0.9, 0.9, 1);
	glEnd();
	// Front
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(1, 0.3, 0);
	glVertex3f(1, 0.1, -2.5);
	glVertex3f(-1, 0.1, -2.5);
	glVertex3f(-1, 0.3, 0);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(1, -1, -2.5);
	glVertex3f(1, 0.1, -2.5);
	glVertex3f(-1, 0.1, -2.5);
	glVertex3f(-1, -1, -2.5);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, -2.5);
	glVertex3f(-1, 0.3, -2.5);
	glVertex3f(-1, 0.1, -1);
	glVertex3f(-1, -1, -1);
	glEnd();
	glFlush();
}

void enable(void) {
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	glEnable(GL_LIGHTING); //enable the lighting
	glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH); //set the shader to smooth shader

}


void display(void) {
	glClearColor(0.0, 1.0, 1.0, 1.0); //clear the screen to Cyan
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	enable();
	glLoadIdentity();

	if (view)
	{
		glRotatef(90, 0, 0, 1);
		gluLookAt(0.8, 70.0, zpos, 0, 0, zpos, 0, 1, 0);
	}
	else
	{
		gluLookAt(xpos - sin(sceneroty*piover180) * 10 + 0.01, 13, zpos + cos(sceneroty*piover180) * 10, xpos, ypos, zpos, 0, 1, 0);
	}

	xpos -= (float)sin(heading*piover180) * accel;
	zpos -= (float)cos(heading*piover180) * accel;
	if (accel > 0)
		accel -= 0.00003;
	if (accel < 0)
		accel += 0.00003;
	if (((xpos < 70 && xpos > -70) && (zpos > -400 && zpos < 400)) || xpos > 90 || xpos < -90 || zpos > 420 || zpos < -420)
	{
		out = true;
		if (accel > 0)
			accel -= 0.000008;
		else
			accel += 0.000008;
	}
	else
	{
		if (out)
		{
			if (wPressed)
			{
				accel += 0.002;
			}
			if (sPressed)
			{
				accel -= 0.002;
			}
			out = false;
		}
	}
	glColor3f(1.0f, 1.0f, 1.0f);
	DrawTrack();
	DrawCar();

	glutSwapBuffers(); //swap the buffers
	angle++; //increase the angle
}
void idle()
{
	if (wPressed)
		accel += 0.000065;
	if (sPressed)
		accel -= 0.000065;
	if (abs(accel) < 0.01)
		return;
	if (dPressed)
	{
		heading -= 0.04f;
		yrot = heading;
		if (accel > 0)
			accel -= 0.000003;
		else
			accel += 0.000003;
	}
	if (aPressed)
	{
		heading += 0.04f;
		yrot = heading;
		if (accel > 0)
			accel -= 0.000024;
		else
			accel += 0.000024;
	}
	display();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection
	glLoadIdentity();
	gluPerspective(120, (GLfloat)w / (GLfloat)h, 0.1, 100.0); //set the perspective (angle of sight, width, height, , depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model

}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'c')
	{
		view = !view;
	}

	if (key == ' ')
	{
		if (accel > 0.03)
			accel -= 0.03;
		else if (accel < -0.03)
			accel += 0.03;
		else
			accel = 0;
	}

	if (key == 'd')
	{
		dPressed = true;
	}

	if (key == 'a')
	{
		aPressed = true;
	}

	if (key == 'w')
	{
		wPressed = true;
	}

	if (key == 's')
	{
		sPressed = true;
	}
	if (key == 27)
	{
		exit(0);
	}
}

void keyboard1(unsigned char key, int x, int y) {
	if (key == 'w')
		wPressed = false;
	if (key == 's')
		sPressed = false;
	if (key == 'a')
		aPressed = false;
	if (key == 'd')
		dPressed = false;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Speed for Need!");
	//	init();
	glutSetKeyRepeat(1);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboard1);
	glutMainLoop();
	return 0;
}