#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <unistd.h>     // needed to sleep.
#include "sala_entrada_estacao.h"
#include "image.h"



#define COR_DO_PLANO 0.3,0.52,0.18,1.0
#define COORD_TEXTURA_PLANO 1.0

/**
  Trabalho de Computacao Grafica - IC/UFAL
  Mapeamento da Estacao Ferroviaria de Maceio - Fase 2
  Equipe: Laysa e Ana Carla

*/
#define PI 3.1415
#define MAXTEXTURE 5

static int shoulder = 0, elbow = 0;
#define SOLID_CLOSED_CYLINDER(QUAD, BASE, TOP, HEIGHT, SLICES, STACKS) \
glPushMatrix();\
gluCylinder(QUAD, BASE, TOP, HEIGHT, SLICES, STACKS); \
glRotatef(180, 1,0,0); \
gluDisk(QUAD, 0.0f, BASE, SLICES, 1); \
glRotatef(180, 1,0,0); \
glTranslatef(0.0f, 0.0f, HEIGHT); \
gluDisk(QUAD, 0.0f, TOP, SLICES, 1); \
glTranslatef(0.0f, 0.0f, -HEIGHT); \
glPopMatrix();

GLfloat obs[3]={0.0,7.0,5.0};
GLfloat look[3]={0.0,3.0,0.0};
GLfloat sentido = 15;

static int eixoy;

GLshort texturas=1;
GLfloat tetaxz=5;
GLfloat raioxz=50;

GLint WIDTH =800;
GLint HEIGHT=600;

GLuint estacao, cadeiras, relogio, planta, extintor, ar_condicionado;
GLuint  textura_plano;

GLuint texture_id[MAXTEXTURE];

void compoe_piso_sala_entrada(void){
 //piso -- http://stackoverflow.com/questions/327043/how-to-apply-texture-to-glutsolidcube olhem :D
  glEnable(GL_TEXTURE_GEN_S); 
  glPushMatrix();

  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.85, -10.0, -6.0);
  //largura, altura, espessura
  glScalef (10.05, 0.1, 20);
  glBindTexture(GL_TEXTURE_2D, texture_id[0]);
  glutSolidCube (5.0);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S); 
  glDisable(GL_TEXTURE_GEN_T);
}

void compoe_estacao(void){

  GLUquadricObj *quadric;
  
  /* inicia a composicao da estacao */
  estacao = glGenLists(1);
  glNewList(estacao, GL_COMPILE);

  quadric = gluNewQuadric(); 
  glColor3f(0.85,0.85,0.85);
  
  compoe_piso_sala_entrada();

  compoe_parede_entrada_sala_entrada();
  compoe_parede_traseira_sala_entrada();
  compoe_parede_direita_sala_entrada();
  compoe_parede_esquerda_sala_entrada();
 // compoe_teto();
 // compoe_cadeiras();

  //compoe_relogio();
  //compoe_planta();
  //compoe_extintor();
  //compoe_ar_condicionado();
  glEndList();
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void init(void)	        // We call this right after our OpenGL window is created.
{
  LoadGLTextures();				// Load The Texture(s) 
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  compoe_estacao();
}

/* The main drawing function. */
void display(void)
{
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  glClearColor(0.1,0.1,0.2,0.2); // cor do plano de fundo
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     
  glPushMatrix();
    /* calcula a posicao do observador */
    obs[0]=raioxz*cos(2*PI*tetaxz/360);
    obs[2]=raioxz*sin(2*PI*tetaxz/360);
    gluLookAt(obs[0],obs[1],obs[2],look[0],look[1],look[2],0.0,1.0,0.0); //posicao do objeto no plano
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // choose the texture to use.
    glBegin(GL_QUADS);		                // begin drawing a cube
      // Front Face (note that the texture's corners have to match the quad's corners)
      glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
      glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);	// Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Top Left Of The Texture and Quad
   glEnd();                                    // done with the polygon.

  glCallList(estacao);
  glCallList(cadeiras);
  glCallList(relogio);
  glCallList(planta);
  glCallList(extintor);
  glCallList(ar_condicionado);
  glPopMatrix();
  //compoe_porta();
  glutSwapBuffers();
  glutSwapBuffers();
  
}



void special(int key, int x, int y){
  switch (key) {
  case GLUT_KEY_UP:
    obs[1]=obs[1]+1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_DOWN:
    obs[1] =obs[1]-1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_LEFT:
    tetaxz=tetaxz+2;
    glutPostRedisplay();
    break;
  case GLUT_KEY_RIGHT:
    tetaxz=tetaxz-2;
    glutPostRedisplay();
    break;
  }
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'r':
    raioxz=raioxz+1;
    glutPostRedisplay();
    break;
  case 'R':
    raioxz=raioxz-1;
    glutPostRedisplay();
    break;  
  case 'o':
    if (eixoy == 90){
      break;
    }
    eixoy = (eixoy + 5);
    glutPostRedisplay();
    
    break;
  case 'O':
    if (eixoy == 0){
      break;
    }
    eixoy = (eixoy - 5);
    glutPostRedisplay();
    break;
  }
}

void reshape(int width, int height){
  WIDTH=width;
  HEIGHT=height;
  glViewport(0,0,(GLint)width,(GLint)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80.0,width/(float)height,0.1,200.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) 
{  
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
  if(!glutCreateWindow("Estacao Ferroviaria de Maceio")) {
    fprintf(stderr,"Error opening a window.\n");
    exit(-1);
  }
  init();  
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return(0); 
}

