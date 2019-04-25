/*
#include<stdlib.h>
#include<Windows.h>
#include<gl/GL.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1416

GLint i, x1 = 0;
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





void circle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;

	glBegin(GL_POLYGON);
	{
		for (i = 0; i <= 50; i++, theta += delTheta)
		{
			glVertex2f(rad * cos(theta), rad * sin(theta));
		}
	}
	glEnd();
}







void road1()
{

	glBegin(GL_POLYGON);			//table blue
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-10, -50, 0);
	glVertex3f(5, -30, 0);
	glVertex3f(-10, -10, 0);
	glVertex3f(40, -10, 0);
	glVertex3f(40, -50, 0);
	glEnd();

	glBegin(GL_POLYGON);			//table green
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-50, -50, 0);
	glVertex3f(-10, -50, 0);
	glVertex3f(5, -30, 0);
	glVertex3f(-10, -10, 0);
	glVertex3f(-50, -10, 0);
	glEnd();

	glBegin(GL_POLYGON);			//boy face
	glColor3f(0.0, 1.5, 0.5);
	glVertex3f(-18, 22, 0);
	glVertex3f(-12, 22, 0);
	glVertex3f(-12, 14, 0);
	glVertex3f(-15, 11, 0);
	glVertex3f(-18, 14, 0);
	glEnd();

	glLineWidth(5);		//boy eye
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(-14, 20, 0);
	glVertex3f(-13.5, 20, 0);
	glEnd();

	glBegin(GL_POLYGON);			//boy shirt
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-20, -10, 0);
	glVertex3f(-10, -10, 0);
	glVertex3f(-10, 10, 0);
	glVertex3f(-15, 13, 0);
	glVertex3f(-20, 10, 0);
	glEnd();

	glBegin(GL_POLYGON);			//boy hair
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-18, 22, 0);
	glVertex3f(-12, 22, 0);
	glVertex3f(-10, 25, 0);
	glVertex3f(-18, 25, 0);
	glEnd();

	glBegin(GL_POLYGON);			//dad hand
	glColor3f(1.35, 1.0, 0.5);
	glVertex3f(-10, 7, 0);
	glVertex3f(-10, 10, 0);
	glVertex3f(-2, 4, 0);
	glVertex3f(-2, 1, 0);
	glEnd();


	glBegin(GL_POLYGON);			//dad hand
	glColor3f(1.35, 1.0, 0.5);
	glVertex3f(6, 10, 0);
	glVertex3f(6, 13, 0);
	glVertex3f(-2, 4, 0);
	glVertex3f(-2, 1, 0);
	glEnd();

	glBegin(GL_POLYGON);			//dad face
	glColor3f(1.35, 1.0, 0.3);
	glVertex3f(10, 15, 0);
	glVertex3f(7, 17, 0);
	glVertex3f(7, 25, 0);
	glVertex3f(13, 25, 0);
	glVertex3f(13, 17, 0);
	glEnd();


	glLineWidth(5);		//dad eye
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(8.5, 23, 0);
	glVertex3f(9, 23, 0);
	glEnd();
	

	glBegin(GL_POLYGON);			//dad hair
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(7, 25, 0);
	glVertex3f(13, 25, 0);
	glVertex3f(13, 27, 0);
	glVertex3f(5, 27, 0);
	glEnd();


	glBegin(GL_POLYGON);			//dad shirt
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(5, 13, 0);
	glVertex3f(5, -10, 0);
	glVertex3f(17, -10, 0);
	glVertex3f(17, 13, 0);
	glVertex3f(10, 16, 0);
	glEnd();



}



void init(void)
{
	//glClearColor(0, 0.749, 1, 0);
	glClearColor(1.5, 0.5, 0.7, 0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	road1();
	glPushMatrix();
	glTranslatef(x1, 0, 0);
	glPopMatrix();
	bitmap_output(-4, 35, "HAPPY", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-5, 30, "BIRTHDAY", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(30, 30, "MY BOY", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(30, 25, "123", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(30, 20, "456", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(30, 15, "789", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-40, 25, "THANK YOU DADDY", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-40, 20, "XYZ", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-40, 15, "abc", GLUT_BITMAP_HELVETICA_18);


	glFlush();
}




void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Frame1");
	init();
	glutDisplayFunc(display);
	glColor3f(1, 0, 0);
	glLineWidth(5.0);
	glutDisplayFunc(display);
	glutMainLoop();
}*/



#include<stdlib.h>
#include<Windows.h>
#include<gl/GL.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1416

GLint i, x1 = 0;

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

	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glPointSize(1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

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

	glColor3f(1.0, 0.64705882352, 0.0);		//Showroom base

	glVertex2f(-0.75f, 0.01f);

	glVertex2f(0.25f, 0.01f);

	glVertex2f(0.25f, 0.4f);

	glVertex2f(-0.75f, 0.4f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.75294117647, 0.79607843137);		//Showroom middle

	glVertex2f(-0.75f, 0.4f);

	glVertex2f(0.25f, 0.4f);

	glVertex2f(0.25f, 0.75f);

	glVertex2f(-0.75f, 0.75f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);		//Showroom top with name

	glVertex2f(-0.75f, 0.75f);

	glVertex2f(0.25f, 0.75f);

	glVertex2f(0.25f, 0.9f);

	glVertex2f(-0.75f, 0.9f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.0);		//Showroom door

	glVertex2f(-0.65f, 0.01f);

	glVertex2f(-0.45f, 0.01f);

	glVertex2f(-0.45f, 0.35f);

	glVertex2f(-0.65f, 0.35f);

	glEnd();


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



	drawSun(0.8f, 0.75f, 0.1);





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
}



void display()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(50, 50, 0);
	frame();
	glPopMatrix();
	bitmap_output(-0.6,0., "FASTRACK", GLUT_BITMAP_HELVETICA_18);

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

