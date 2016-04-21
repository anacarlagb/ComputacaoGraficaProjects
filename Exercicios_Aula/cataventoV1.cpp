#include <GL/gl.h>
#include <GL/glut.h>


void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
}

void display(void){

  glClear(GL_COLOR_BUFFER_BIT);
	
 glColor3f(1.0, 1.0, .0);
  glBegin(GL_POLYGON);
	glVertex3f(249.0f,250.0f, -1.0f);
	glVertex3f(251.0f,250.0f, -1.0f);
	glVertex3f(249.0f,100.0f, -1.0f);
	glVertex3f(251.0f,100.0f, -1.0f);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_TRIANGLES);
  	glVertex2f(250.0f, 250.f);
  	glVertex2f(230.0f, 200.f);
  	glVertex2f(270.0f, 200.f);
  glEnd();

   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_TRIANGLES);
  	glVertex2f(250.0f, 250.f);
  	glVertex2f(200.0f, 230.f);
  	glVertex2f(200.0f, 270.f);
  glEnd();

   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_TRIANGLES);
  	glVertex2f(250.0f, 250.f);
  	glVertex2f(300.0f, 270.f);
  	glVertex2f(300.0f, 230.f);
  glEnd();

   glColor3f(0.0, 1.0, 0.0);
   glBegin(GL_TRIANGLES);
  	glVertex2f(250.0f, 250.f);
  	glVertex2f(230.0f, 300.f);
  	glVertex2f(270.0f, 300.f);
  glEnd();

  glFlush();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flor de Abril");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}
