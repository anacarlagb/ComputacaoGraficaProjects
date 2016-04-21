#include <GL/gl.h>
#include <GL/glut.h>

void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ola");
	
	init();

	glutMainLoop();

	return 0;

}