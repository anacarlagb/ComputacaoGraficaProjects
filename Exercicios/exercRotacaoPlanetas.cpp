#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>


/*
Computacao Grafica IC/UFAL
Aluna: Ana Carla Gomes Bibiano
Exercicio: Rotacao Planetas
Clique 'y' - para  translacao sentido anti-horario
       'Y' - para  translacao sentido horario
*/


void init(void);
void keyboard(unsigned char key, int x, int y);
void reshape(GLint w, GLint h);
void desenhaPlanetas(void);
 
GLsizei winWidth = 500;
GLsizei winHeight = 500;
 
static int terra = 0;
static int marte = 0;
static int luas = 0;
 
int main(int argc, char *argv[])
{
     
    glutInit(&argc, argv);
     
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Rotacao - Planetas");
     
    init();
     
    glutDisplayFunc(desenhaPlanetas);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
     
    glutMainLoop();
     
    return 0;
}
 
 
void init(void)
{
    glClearColor(0, 0, 0, 0);
}
 
void desenhaPlanetas(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
     
//  Desenhar o sol
    glColor3f(1, 1, 0); //Define a cor amarela
     
    glPushMatrix();
    glRotatef((GLfloat) 90, 1, 0, 0); //Rotacionar o sol
    glRotatef((GLfloat) terra, 0, 0, 1); //Rotacionar o sol de acordo com o movimento dos planetas
    glutWireSphere(1, 20, 16); //Desenha o sol
    glPopMatrix();
     
//  Desenhar a Terra
    glColor3f(0, 0, 1); //Define a cor azul
     
    glPushMatrix();
    glRotatef((GLfloat) terra/2, 0, 1, 0); //Rotacionar a Terra mais devagar ao redor do sol
    glTranslatef(2, 0, 0); //Transladar a Terra para que ela possa rotacionar ao redor do sol
    glutWireSphere(0.2, 10, 8); //Desenhar a tela
    glPopMatrix();
     
//  Desenha a primeira lua
    glColor3f(1, 1, 1); //Define a cor branca
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a lua para que ela gire junto com a Terra
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com a Terra
    glRotatef((GLfloat) luas, 0, 1, 0); //Rotacionar a lua para que ela gire ao redor do eixo X da Terra
    glTranslatef(0.5, 0, 0); //Transladar a lua para ficar a 0.5 de distância da Terra
    glutWireSphere(0.05, 8, 6); //Desenha a lua
    glPopMatrix();
     
//  Desenha a segunda lua
    glColor3f(0, 1, 0); //Define a cor verde
     
    glPushMatrix();
    glRotatef((GLfloat) terra/2, 0, 1, 0); //Rotacionar a lua para que ela gire junto com a Terra
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com a Terra
    glRotatef((GLfloat) luas, 1, 1, 0); //Transladar a lua para ficar a 0.5 de distância da Terra
    glTranslatef(0, 0, 0.5); //Transladar a lua para ficar a 0.5 de distância do centro da Terra
    glutWireSphere(0.075, 8, 6); //Desenhar a luas
    glPopMatrix();
     
//  Desenhar Marte
    glColor3f(1, 0, 0);
     
    glPushMatrix();
    glRotatef((GLfloat) marte, 0, 1, 0); //Rotacionar Marte ao redor do sol
    glTranslatef(-1.5, 0, 0); //Transladar Marte para o outro lado do sol, so que mais perto do sol
    glutWireSphere(0.1, 10, 8); //Desenha Marte
    glPopMatrix();
     
    glutSwapBuffers();
}

void reshape(GLint w, GLint h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
     
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
     
    gluPerspective(60, (GLfloat) w/(GLfloat) h, 1, 20);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}
 
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'y': // move em sentido anti-horario
            terra = (terra+10) % 720;
            marte = (marte-10) % 360;
            luas = (luas+10) % 360;
            glutPostRedisplay();
            break;
             
        case 'Y': // Move em sentido horario
            terra = (terra-10) % 720;
            marte = ((marte+10) % 360);
            luas = (luas-10) % 360;
            glutPostRedisplay();
            break;
             
        case 27:
            exit(0);
            break;
             
        default:
            break;
    }
}
 
