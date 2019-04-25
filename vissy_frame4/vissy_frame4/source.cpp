
#include<stdlib.h>
#include<Windows.h>

#include<gl/GL.h>

#include<GL/glut.h>
#include<math.h>

#define PI 3.1416





void bitmap_output(double x, double y, const char  *string, void *font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (double)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}

}

int window;

float rtri = 0.0f;

float rquad = 0.0f;



void myinit()

{

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//glPointSize(1.0);

	//glMatrixMode(GL_PROJECTION);

	//glLoadIdentity();

	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);


}



void drawSun(GLfloat x, GLfloat y, GLfloat radius) {

	int i;

	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * 3.1415;

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0, 1.0, 0.0);

	glVertex2f(x, y); // center of circle

	for (i = 0; i <= triangleAmount + 1; i++) {

		glVertex2f(

			x + (radius * cos(i *  twicePi / triangleAmount)),

			y + (radius * sin(i * twicePi / triangleAmount))

		);

	}

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.68f, 0.75f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.92f, 0.75f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.8f, 0.88f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.8f, 0.62f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.88f, 0.65f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.88f, 0.85f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.72f, 0.65f);

	glEnd();



	glBegin(GL_LINES);

	glVertex2f(0.8f, 0.75f);

	glVertex2f(0.72f, 0.85f);

	glEnd();

}



void frame()

{

	glBegin(GL_POLYGON);			//Bottom road

	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(-1.0, -0.45f);

	glVertex2f(1.0, -0.45f);

	glVertex2f(1.0, -0.235f);

	glVertex2f(-1.0, -0.235f);

	glEnd();



	glBegin(GL_POLYGON);			//Top road

	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(-1.0, -0.225f);

	glVertex2f(1.0, -0.225f);

	glVertex2f(1.0, 0.0);

	glVertex2f(-1.0, 0.0);

	glEnd();



	glBegin(GL_POLYGON);            //Background light blue

	glColor3f(0.30196078431f, 0.72156862745f, 1.0f);

	glVertex2f(-1.0, 0.01f);

	glVertex2f(1.0, 0.01f);

	glVertex2f(1.0, 1.0);

	glVertex2f(-1.0, 1.0);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);		//Garden

	glVertex2f(-1.0, -0.46f);

	glVertex2f(1.0, -0.46f);

	glVertex2f(1.0, -1.0);

	glVertex2f(-1.0, -1.0);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.64705882352, 0.0);		//Showroom entry

	glVertex2f(-0.75f, 0.01f);

	glVertex2f(-0.5f, 0.01f);

	glVertex2f(-0.5f, 0.7f);

	glVertex2f(-0.75f, 0.7f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);		//showroom 1

	glVertex2f(-0.25f, 0.01f);

	glVertex2f(-0.5f, 0.01f);

	glVertex2f(-0.5f, 0.7f);

	glVertex2f(-0.25f, 0.7f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.5, 0.5);		//showroom 2

	glVertex2f(0.0f, 0.01f);

	glVertex2f(-0.25f, 0.01f);

	glVertex2f(-0.25f, 0.7f);

	glVertex2f(0.0f, 0.7f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 1.0);		//showroom 3

	glVertex2f(0.25f, 0.01f);

	glVertex2f(0.0f, 0.01f);

	glVertex2f(0.0f, 0.7f);

	glVertex2f(0.25f, 0.7f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//building name of all showrooms

	glVertex2f(-0.75f, 0.7f);

	glVertex2f(0.25f, 0.7f);

	glVertex2f(0.25f, 0.85f);

	glVertex2f(-0.75f, 0.85f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.5, 0.2, 1.0);		//building door

	glVertex2f(-0.7f, 0.01f);

	glVertex2f(-0.55f, 0.01f);

	glVertex2f(-0.55f, 0.4f);

	glVertex2f(-0.7f, 0.4f);

	glEnd();



	drawSun(0.8f, 0.75f, 0.1);




	glBegin(GL_POLYGON);

	glColor3f(0.5, 0.5, 1.0);		//dad shirt

	glVertex2f(-0.25f, -0.05f);

	glVertex2f(-0.37f, -0.05f);

	glVertex2f(-0.37f, 0.25f);

	glVertex2f(-0.25f, 0.25f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.3);		//dad left hand

	glVertex2f(-0.45f, -0.07f);

	glVertex2f(-0.37f, 0.18f);

	glVertex2f(-0.37f, 0.25f);

	glVertex2f(-0.45f, 0.0f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.3);		//dad right hand

	glVertex2f(-0.25f, 0.18f);

	glVertex2f(-0.15f, -0.07f);

	glVertex2f(-0.15f, 0.0f);

	glVertex2f(-0.25f, 0.25f);

	glEnd();




	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.6);		//dad face

	glVertex2f(-0.25f, 0.45f);

	glVertex2f(-0.37f, 0.45f);

	glVertex2f(-0.37f, 0.27f);

	glVertex2f(-0.25f, 0.27f);

	glEnd();



	glLineWidth(10);
	glBegin(GL_LINE);

	glColor3f(0.0, 0.0, 0.0);		//dad left eye

	glVertex2f(-0.28f, 0.40f);

	glVertex2f(-0.29f, 0.40f);

	glEnd();


	glLineWidth(10);
	glBegin(GL_LINE);

	glColor3f(0.0, 0.0, 0.0);		//dad left eye

	glVertex2f(-0.34f, 0.40f);

	glVertex2f(-0.f, 0.40f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);		//dad right leg

	glVertex2f(-0.25f, -0.05f);

	glVertex2f(-0.3f, -0.05f);

	glVertex2f(-0.3f, -0.25f);

	glVertex2f(-0.25f, -0.25f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//dad right leg shoe

	glVertex2f(-0.25f, -0.28f);

	glVertex2f(-0.31f, -0.28f);

	glVertex2f(-0.3f, -0.25f);

	glVertex2f(-0.25f, -0.25f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);		//dad left leg

	glVertex2f(-0.37f, -0.05f);

	glVertex2f(-0.32f, -0.05f);

	glVertex2f(-0.32f, -0.25f);

	glVertex2f(-0.37f, -0.25f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//dad left leg

	glVertex2f(-0.38f, -0.28f);

	glVertex2f(-0.32f, -0.28f);

	glVertex2f(-0.32f, -0.25f);

	glVertex2f(-0.37f, -0.25f);

	glEnd();




	glBegin(GL_POLYGON);

	glColor3f(0.5, 1.0, 0.8);		//boy shirt

	glVertex2f(-0.22f, -0.05f);

	glVertex2f(-0.13f, -0.05f);

	glVertex2f(-0.13f, 0.15f);

	glVertex2f(-0.22f, 0.15f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.6);		//boy face

	glVertex2f(-0.22f, 0.3f);

	glVertex2f(-0.13f, 0.3f);

	glVertex2f(-0.13f, 0.17f);

	glVertex2f(-0.22f, 0.17f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.3);		//boy hand

	glVertex2f(-0.06f, -0.05f);

	glVertex2f(-0.13f, 0.1f);

	glVertex2f(-0.13f, 0.15f);

	glVertex2f(-0.06f, 0.0f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.8);		//boy left leg

	glVertex2f(-0.22f, -0.05f);

	glVertex2f(-0.18f, -0.05f);

	glVertex2f(-0.18f, -0.20f);

	glVertex2f(-0.22f, -0.20f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//boy left leg shoe

	glVertex2f(-0.23f, -0.23f);

	glVertex2f(-0.18f, -0.23f);

	glVertex2f(-0.18f, -0.20f);

	glVertex2f(-0.22f, -0.20f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.8);		//boy right leg

	glVertex2f(-0.13f, -0.05f);

	glVertex2f(-0.17f, -0.05f);

	glVertex2f(-0.17f, -0.20f);

	glVertex2f(-0.13f, -0.20f);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//boy right leg shoe

	glVertex2f(-0.13f, -0.23f);

	glVertex2f(-0.18f, -0.23f);

	glVertex2f(-0.17f, -0.20f);

	glVertex2f(-0.13f, -0.20f);

	glEnd();


	drawSun(0.8f, 0.75f, 0.1);


}



void display()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(50.0, 50.0, 0.0);
	frame();
	glPopMatrix();

	//people();

	bitmap_output(-22, 38, "WATCH SHOWROOM", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(-22, 28, "CASIO", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(-10, 28, "CITIZEN", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(3, 28, "TIMEX", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(-25, 20, "Buy", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-27, 15, "Any watch", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-26, 10, "My Son", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-6, 10, "OK DAD", GLUT_BITMAP_HELVETICA_18);


	glFlush();

}



int main(int argc, char **argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1366, 768);

	glutCreateWindow("CG PROJECT FASTRACK");

	glutDisplayFunc(display);

	myinit();

	glutMainLoop();

	return 0;

}

