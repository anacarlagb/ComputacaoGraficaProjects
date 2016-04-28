#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>  // Header File For The OpenGL32 Library
#include <GL/glu.h> // Header File For The GLu32 Library
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

GLfloat porta_difusa[]    = { 1.0, 1.0, 0.0, 1.0 };
GLfloat porta_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat porta_brilho[]    = { 50.0 };
GLfloat ctp[4][2]={
  {-COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//direita - cima
  {+COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//esquerda - cima
  {+COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO},//direita -  baixo
  {-COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO} //direita - baixo
};

//Sala do meio
void compoe_estacao_sala_entrada(void);
void compoe_piso_sala_entrada(void);


// objetos da sala de entrada
void compoe_cadeiras(void);
void compoe_relogio(void);
void compoe_planta(void);
void compoe_extintor(void);
void compoe_ar_condicionado(void);





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




void compoe_porta(){
  glPushMatrix();
  glColor3f(0.5f, 0.35f, 0.05f);
  //eixo de rotação
  glTranslatef (10, -1.6, -1.0);
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glTranslatef (-10, 1.6, 1.0);

  glTranslatef (10, -1.6, -3.0);
  //espessura, altura, largura
  glScalef (0.1, 4.55, -3.8);
  glutSolidCube (4.0);
  
  glPopMatrix();
  glPopMatrix();  
}


void compoe_relogio(void){
    GLUquadricObj *quadric;
    relogio = glGenLists(1);
    glNewList(relogio, GL_COMPILE);
    glPushMatrix();  
      //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (12.0, 10.0, -6);
      glRotatef(270,1,0,1);
      glScalef(4.0,0.1,10.0);
      quadric = gluNewQuadric();
      glColor3f(1.0,1.0,1.0);    
      gluSphere(quadric,0.3,15,12);
    glPopMatrix();

}

// void compoe_cadeiras(void){
//   GLUquadricObj *quadric;
  
//   cadeiras = glGenLists(1);
//   glNewList(cadeiras, GL_COMPILE);
//   quadric = gluNewQuadric();
//   glColor3f(0,0,0);
//   GLfloat lado, atras = 0;
//   //compoe cadeiras, 4 colunas
//   for(int i = 2; i<4; i++){
//     atras = i * 9.5;
//     //6 cadeiras lado a lado - 3 da cada lado
//     for(int j=0; j<3; j++){
//       lado = j*6.0;
//       if (j>2){
//         lado = lado + 8;
//       }

//       //pe cadeira - atrás esquerda

//       quadric = gluNewQuadric();
  
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();
//       glRotatef(90,1,0,0);
//       //-tras/frente+ - +esquerda/direita- - +baixo/cima-
//       glTranslatef (8-lado, -0.8-atras, 6.8);
//       SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
//       gluDeleteQuadric(quadric);
//       glPopMatrix();


//       //pe cadeira - atrás direita
//       quadric = gluNewQuadric();
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();
//       glRotatef(90,1,0,0);
//       //-tras/frente+ - +esquerda/direita- - +baixo/cima-
//       glTranslatef (6-lado, -0.8-atras, 6.8);
//       SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
//       gluDeleteQuadric(quadric);
//       glPopMatrix();


//       //pe cadeira - frente esquerda
//       quadric = gluNewQuadric();
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();
//       glRotatef(90,1,0,0);
//       //-tras/frente+ - +esquerda/direita- - +baixo/cima-
//       glTranslatef (8-lado, 1.2-atras, 6.8);
//       SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
//       gluDeleteQuadric(quadric);
//       glPopMatrix();


//       //pe cadeira - frente direita
//       quadric = gluNewQuadric();
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();
//       glRotatef(90,1,0,0);
//       //-tras/frente+ - +esquerda/direita- - +baixo/cima-
//       glTranslatef (6-lado, 1.2-atras, 6.8);
//       SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
//       gluDeleteQuadric(quadric);
//       glPopMatrix();

//       //assento cadeira
//       glPushMatrix();  
//       //+tras/frente- - +baixo/cima- - - +esquerda/direita-
//       glTranslatef (7-lado, -6.8, 0.3-atras);
//       glScalef(4.0,0.3,3.0);
//       quadric=gluNewQuadric();
//       //glColor3f(0.3,0.5,1);
//       gluSphere(quadric,0.5,15,12);
//       glPopMatrix();

//       //apoio encosto cadeira - vertical
//       quadric = gluNewQuadric();
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();   
//       //glColor3f(0,0,0);
//       glRotatef(90,1,0,0);  
//       glTranslatef (7-lado, -1.8-atras, 5);
//       //tras/frente - direita/esquerda - cima/baixo 
//       SOLID_CLOSED_CYLINDER(quadric, 0.15, 0.15, 2.2, 30, 1)
//       //gluDeleteQuadric(quadric);
//       glPopMatrix();

//       //encosto cadeira
//       glPushMatrix();  
//       //+tras/frente- - +baixo/cima- - - +esquerda/direita-
//       glTranslatef (7-lado, -4.75, -1.5-atras);
//       glRotatef(-15,1,0,1);
//       glScalef(4,3,0.5);
//       quadric=gluNewQuadric();
//       //glColor3f(0.3,0.5,1);
//       gluSphere(quadric,0.5,15,12);
//       glPopMatrix();

//       //apoio encosto cadeira - horizontal
//       quadric = gluNewQuadric();
//       gluQuadricDrawStyle(quadric, GLU_FILL);
//       gluQuadricOrientation(quadric, GLU_INSIDE);
//       glPushMatrix();   
//       //glColor3f(0,0,0);
//       glTranslatef (7-lado, -7, -2-atras);
//       //tras/frente - cima/baixo - direita/esquerda 
//       SOLID_CLOSED_CYLINDER(quadric, 0.15, 0.15, 2.2, 30, 1)
//       gluDeleteQuadric(quadric);
//       glPopMatrix();
//     }
//   }
// }


void compoe_planta(void){
    GLUquadricObj *quadric;
    planta = glGenLists(1);
    glNewList(planta, GL_COMPILE);
   
    
    //planta da esquerda - lado de fora
    //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glPushMatrix(); 
    glTranslatef (13.0, -12.0, 8);
    //largura, altura, espessura
    glScalef(1.0,2.0,7.0);
    quadric = gluNewQuadric();
    glColor3f(.0,1.0,.0);
    glutSolidCube (2.0);
    glPopMatrix();

     //planta da direita - lado de fora
    glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (13.0, -12.0, -18);
    //largura, altura, espessura
    glScalef(1.0,2.0,7.0);
    quadric = gluNewQuadric();
    glColor3f(.0,1.0,.0);
    glutSolidCube (2.0);
    glPopMatrix();

     //calcada - lado de fora
    glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (13.0, -12.0, -6);
    //largura, altura, espessura
    glScalef(2.0,2.0,5.0);
    quadric = gluNewQuadric();
    glColor3f(1.0,1.0,1.0);
    glutSolidCube (3.0);
    glPopMatrix();
}

void compoe_extintor(void){
   GLUquadricObj *quadric;
  
     extintor = glGenLists(1);
    glNewList(extintor, GL_COMPILE);
     // EXTINTOR 
    glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (6.0, 1.0, 12);
    //largura, altura, espessura
    glScalef(1.0,2.0,1.0);
    quadric = gluNewQuadric();
    glColor3f(1,0,0);
    glutSolidCube(3.0);
    glPopMatrix();
}

void compoe_ar_condicionado(void){
   GLUquadricObj *quadric;

    ar_condicionado = glGenLists(1);
    glNewList(ar_condicionado, GL_COMPILE);

     //AR CONDICIONADO
    glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (8.0, 7.0, -18);
    //largura, altura, espessura
    glScalef(2.0,2.0,2.0);
    quadric = gluNewQuadric();
    glColor3f(0.85,0.85,0.85);
    glutSolidCube (3.0);
    glPopMatrix();
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
  //compoe_teto();
 // compoe_cadeiras();

  compoe_relogio();
  //compoe_planta();
  //compoe_extintor();
  //compoe_ar_condicionado();
  glEndList();
}

void compoe_sala_entrada(void){
   GLUquadricObj *quadric;
  
  /* inicia a composicao da estacao */
  estacao = glGenLists(1);
  glNewList(estacao, GL_COMPILE);

  quadric = gluNewQuadric(); 
  glColor3f(0.85,0.85,0.85);

}


void init(void){
    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);      // Enable Texture Mapping
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f); // Clear The Background Color To Blue 
    glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);     // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);      // Enables Depth Testing
    glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();       // Reset The Projection Matrix
    
    //gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f); // Calculate The Aspect Ratio Of The Window
    
    glMatrixMode(GL_MODELVIEW);

  // glEnable(GL_TEXTURE_2D);
  // glShadeModel(GL_FLAT);
  // glEnable(GL_DEPTH_TEST);
  // glEnable(GL_BLEND);
  // glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  // glEnable(GL_TEXTURE_2D);
  compoe_estacao();
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


void display(void){
  glEnable(GL_DEPTH_TEST);
  
  glDepthMask(GL_TRUE);
  glClearColor(0.1,0.1,0.2,0.2); // cor do plano de fundo
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();       // Reset The View

    glTranslatef(0.0f,0.0f,-5.0f);              // move 5 units into the screen.
      
  glPushMatrix();

  /* calcula a posicao do observador */
  obs[0]=raioxz*cos(2*PI*tetaxz/360);
  obs[2]=raioxz*sin(2*PI*tetaxz/360);
  gluLookAt(obs[0],obs[1],obs[2],look[0],look[1],look[2],0.0,1.0,0.0); //posicao do objeto no plano

    glBindTexture(GL_TEXTURE_2D, texture[0]);   // choose the texture to use.
    glBegin(GL_QUADS);                    // begin drawing a cube
    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
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


int main(int argc, char** argv){
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
   glutFullScreen();

    /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return(0);
}