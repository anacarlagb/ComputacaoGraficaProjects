/*
	Utiliza rotação e translação e a função glutTimeFunc() para o loop do código com a velocidade definido na função.
*/


#include <iostream>
#include <GL/glut.h>

GLsizei winWidth = 500, winHeight = 400;

using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);

	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

}

//contém apenas as petalas para gerar o catavento
void catavento()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);

		glVertex2f(250.0f, 250.0f);
		glVertex2f(230.0f, 200.0f);
		glVertex2f(270.0f, 200.0f);
	glEnd();

	

	//vermelha
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f, 250.0f);
		glVertex2f(300.0f, 230.0f);
		glVertex2f(300.0f, 270.0f);
	glEnd();
	
	//verde
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f, 250.0f);
		glVertex2f(230.0f, 300.0f);
		glVertex2f(270.0f, 300.0f);
	glEnd();
	
	//azul
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f, 250.0f);
		glVertex2f(200.0f, 230.0f);
		glVertex2f(200.0f, 270.0f);
	glEnd();
	
}

/*
a cada x milisegundos executa de novo, e gera o caravento
*/
void atualiza(int tempo)
{
	glTranslatef(250, 250, 0);
	glRotatef(15, 0.0, 0.0, 1.0);
	glTranslatef(-250, -250, 0);

	glPopMatrix();
	

	glutPostRedisplay();
	glutTimerFunc(100, atualiza, 0);
}

//deixa o caule fixo
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();//salva a transformação corrente na pilha
	glLoadIdentity();//troca a matriz corrente com a matriz identidade/ reseta a matriz
	glMatrixMode(GL_PROJECTION);//todas as futuras alterações irão afetar a câmera
	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
	glColor3f(1.0, 1.0, .0);
	glBegin(GL_POLYGON);
		glVertex3f(249.0f, 250.0f, -1.0f);
		glVertex3f(251.0f, 250.0f, -1.0f);
		glVertex3f(249.0f, 100.0f, -1.0f);
		glVertex3f(251.0f, 100.0f, -1.0f);
	glEnd();
	glPopMatrix();//pega a transformação da pilha

	catavento();

	glutSwapBuffers();
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("flor de Abril");

	init();

	glutDisplayFunc(display);
	
	glutTimerFunc(100, atualiza, 0);
	

	glutMainLoop();

	return 0;
}