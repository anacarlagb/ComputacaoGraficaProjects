#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>


#define COORD_TEXTURA_PISCINA 1.0

#include "SOIL.h"

#include "JpegLib\jpegfile.h"

#define PI 3.1415

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

// Textures path images
#define TEXTURE_FLOOR 0
#define TEXTURE_BOARD 1


//texture variables
GLuint texture_id[2];


static int shoulder = 0, elbow = 0;

GLint WIDTH =800;
GLint HEIGHT=600;

// camera
GLfloat obs[3]={0.0,7.0,5.0};
GLfloat look[3]={0.0,3.0,0.0};

//Define profundidade da sala
GLfloat finalX = 10.0;

//Define altura da sala
GLfloat finalY = 10.0;

//Define largura da sala
GLfloat finalZ = 10.0;
GLfloat sentido = 15;

GLfloat ctpi[4][2]={
  {0.0,0.0},
  {0.0,COORD_TEXTURA_PISCINA},
  {COORD_TEXTURA_PISCINA,COORD_TEXTURA_PISCINA},
  {COORD_TEXTURA_PISCINA,0.0}
};



static int eixoy;

GLfloat origemX = -finalX;
GLfloat origemY = -finalY;
GLfloat origemZ = -finalZ;

//camera
GLfloat tetaxz=5;
GLfloat raioxz=50;

GLuint  sala, biros_esq, biros_dir, comp_esq, comp_dir, janelas_sol, janelas_entrada, grade, cadeiras;


void draw_wall(float x1,float y1, float z1,
			float x2, float y2, float z2,
			float x3, float y3, float z3,
			float x4, float y4, float z4, int tex_index){

	glBindTexture(GL_TEXTURE_2D, texture_id[tex_index]);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( x1, y1, z1 );
    glTexCoord2f(1.0f, 0.0f); glVertex3f( x2, y2, z2 );
    glTexCoord2f(1.0f, 1.0f); glVertex3f( x3, y3, z3 );
    glTexCoord2f(0.0f, 1.0f); glVertex3f( x4, y4, z4 );
  glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
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


void compoe_biros_esquerdo(void) {
 
 GLUquadricObj *quadric;
  
// inicia a composicao do biro
  biros_esq = glGenLists(1);
  glNewList(biros_esq, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);
  GLfloat lado, atras;
  //compoe biros do lado da porta, 4 colunas
  for(int i = 0; i<4; i++){
    atras = i * 10.0;
    //3 biros lado a lado
    for(int j=0; j<3; j++){
      lado = j * 6.0;
      //biro do computador - frente
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (7.0 - lado, -7.0, 7.6 - atras);
      //largura, altura, espessura
      glScalef (1.2, 1.2, 0.1);
      glutSolidCube (5.0);
      glPopMatrix();

      //biro do computador - divisoria
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (4.3 - lado, -5.5, 5.4 - atras);
      //espessura, altura, largura
      glScalef (0.1, 1.8, 1.0);
      glutSolidCube (5.0);
      glPopMatrix();

      //biro do computador - base
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (7.0 - lado, -4.3, 5.4 - atras);
      //altura, espessura, largura
      glScalef (1.2, 0.1, 1.0);
      glutSolidCube (5.0);
      glPopMatrix();
    }
  }
}

void compoe_biros_direito(void){
  GLUquadricObj *quadric;
  // inicia a composicao do biro
  biros_dir = glGenLists(1);
  glNewList(biros_dir, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado, atras;
  //compoe biros do lado da porta, 4 colunas
  for(int i = 0; i<4; i++){
    atras = i * 10.0;
    //3 biros lado a lado
    for(int j=0; j<3; j++){
      lado = j * 6.0;
      //biro do computador - frente
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-19 - lado, -7.0, 7.6 - atras);
      //largura, altura, espessura
      glScalef (1.2, 1.2, 0.1);
      glutSolidCube (5.0);
      glPopMatrix();

      //biro do computador - divisoria
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-16.3 - lado, -5.5, 5.4 - atras);
      //espessura, altura, largura
      glScalef (0.1, 1.8, 1.0);
      glutSolidCube (5.0);
      glPopMatrix();

      //biro do computador - base
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-19 - lado, -4.3, 5.4 - atras);
      //altura, espessura, largura
      glScalef (1.2, 0.1, 1.0);
      glutSolidCube (5.0);
      glPopMatrix();
    }
  }
}

void compoe_computador_esq(void){

  GLUquadricObj *quadric;
  // inicia a composicao do computador
  comp_esq = glGenLists(1);
  glNewList(comp_esq, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado, atras;
  //compoe computadores do lado da porta, 4 colunas
  for(int i = 0; i<4; i++){
    atras = i * 10.0;
    //3 computadores lado a lado
    for(int j=0; j<3; j++){
      lado = j * 6.0;

      //base tela
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE); 
      glPushMatrix();  
      //tras/frente - direita/esquerda - cima/baixo 
      glRotatef(90,1,0,0);
      glTranslatef (7.0-lado, 6.0-atras, 3.9);    
      SOLID_CLOSED_CYLINDER(quadric, 1., 1., 0.15, 30, 1)
      gluDeleteQuadric(quadric);
      glPopMatrix();

      //apoio tela
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();   
      glRotatef(90,1,0,0);  
      glTranslatef (7.0-lado, 6.8-atras, 2.0);
      //tras/frente - direita/esquerda - cima/baixo 
      SOLID_CLOSED_CYLINDER(quadric, 0.25, 0.25, 2., 30, 1)
      gluDeleteQuadric(quadric);
      glPopMatrix();

      //tela
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (7.0-lado, -1.7, 6.5-atras);
      glScalef (3., 3., 0.2);
      glutSolidCube (1.0);
      glPopMatrix();

      //cpu
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (9.3-lado, -2.8, 6.0-atras);
      glScalef (1., 3., 3.);
      glutSolidCube (1.0);
      glPopMatrix();

      //teclado
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (7.3-lado, -4.0, 4.0-atras);
      glScalef (2.6, 0.2, 1.2);
      glutSolidCube (1.0);
      glPopMatrix();




      //mouse
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (5.0-lado, -4.1, 4.0-atras);
      gluSphere(quadric, 0.25, 30,15);
      gluDeleteQuadric(quadric);
      glPopMatrix();
    }
  }
}

void compoe_computador_dir(void){

  GLUquadricObj *quadric;
  // inicia a composicao do computador
  comp_dir = glGenLists(1);
  glNewList(comp_dir, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado, atras;
  //compoe computador do lado da porta, 4 colunas
  for(int i = 0; i<4; i++){
    atras = i * 10.0;
    //3 computadores lado a lado
    for(int j=0; j<3; j++){
      lado = j * 6.0;

      //base tela
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE); 
      glPushMatrix();  
      //tras/frente - direita/esquerda - cima/baixo 
      glRotatef(90,1,0,0);
      glTranslatef (-19-lado, 6.0-atras, 3.9);    
      SOLID_CLOSED_CYLINDER(quadric, 1., 1., 0.15, 30, 1)
      gluDeleteQuadric(quadric);
      glPopMatrix();

      //apoio tela
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();   
      glRotatef(90,1,0,0);  
      glTranslatef (-19-lado, 6.8-atras, 2.0);
      //tras/frente - direita/esquerda - cima/baixo 
      SOLID_CLOSED_CYLINDER(quadric, 0.25, 0.25, 2., 30, 1)
      gluDeleteQuadric(quadric);
      glPopMatrix();

      //tela
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (-19-lado, -1.7, 6.5-atras);
      glScalef (3., 3., 0.2);
      glutSolidCube (1.0);
      glPopMatrix();

      //cpu
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (-21.3-lado, -2.8, 6.0-atras);
      glScalef (1., 3., 3.);
      glutSolidCube (1.0);
      glPopMatrix();

      //teclado
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (-18.7-lado, -4.0, 4.0-atras);
      glScalef (2.6, 0.2, 1.2);
      glutSolidCube (1.0);
      glPopMatrix();
       


      //mouse
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda 
      glTranslatef (-21-lado, -4.1, 4.0-atras);
      gluSphere(quadric, 0.25, 30,15);
      gluDeleteQuadric(quadric);
      glPopMatrix();
      
    }
  }
} 

void compoe_janelas_sol(void){
  GLUquadricObj *quadric;
  // inicia a composicao do computador
  janelas_sol = glGenLists(1);
  glNewList(janelas_sol, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado = 0.0;
  //compoe 5 janelas lado a lado 3 vezes
  for(int i = 0; i<3; i++){
    //5 janelas
    for(int j=0; j<5; j++){
      lado = lado + 3.0;

      //janelas menores sol
      glPushMatrix();
      //-tras/frente+ - -baixo/cima+ - -esquerda/direira+
      glTranslatef (-33.8, 8.2, -32.2+lado);
      //largura, altura, espessura
      glScalef (0.2, 1.5, 1.3);
      glutWireCube(2.0);
      glPopMatrix();

      //parede exterior sol - meio verical
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-33.8, 0.0, -33.7+lado);
      //espessura, altura, largura
      glScalef (0.1, 4.0, 0.1);
      glutSolidCube (5.0);
      glPopMatrix();

      //janelas sol
      glPushMatrix();
      //-tras/frente+ - -baixo/cima+ - -esquerda/direira+
      glTranslatef (-33.8, 2.7, -32.2+lado);
      //largura, altura, espessura
      glScalef (0.2, 3.5, 1.3);
      glutWireCube(2.0);
      glPopMatrix();

    }
    lado = lado + 1.7;
  }
}

void compoe_janelas_entrada(void){

  GLUquadricObj *quadric;
  // inicia a composicao do computador
  janelas_entrada = glGenLists(1);
  glNewList(janelas_entrada, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado = 0.0;
  //compoe 5 janelas lado a lado 3 vezes
  for(int i = 0; i<3; i++){
    //5 janelas
    for(int j=0; j<5; j++){
      lado = lado + 3.0;

      glPushMatrix();
      //-tras/frente+ - -baixo/cima+ - +esquerda/direita-
      glTranslatef (10.0, 8.2, -32.2+lado);
      //espessura, altura, largura
      glScalef (0.2, 1.5, 1.3);
      glutWireCube (2.0);
      glPopMatrix();

      //parede exterior sol - meio verical
      glPushMatrix();
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (10, 0.0, -33.7+lado);
      //espessura, altura, largura
      glScalef (0.1, 4.0, 0.1);
      glutSolidCube (5.0);
      glPopMatrix();
      if (i==2 && j==1) {
          //parede exterior sol - meio vertical
          glPushMatrix();
          //tras/frente - cima/baixo - direita/esquerda
          glTranslatef (10, 0.0, -30.7+lado);
          //espessura, altura, largura
          glScalef (0.1, 4.0, 0.2);
          glutSolidCube (5.0);
          glPopMatrix();
          break;
      }
    }    
    lado = lado + 1.7;
  }
}

void compoe_grade(void){
  GLUquadricObj *quadric;
  // inicia a composicao da grade
  grade = glGenLists(1);
  glNewList(grade, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat baixo = 0.0;
  //compoe 15 grades uma abaixo da outra
  for(int i = 0; i<20; i++){
    baixo = baixo + 1.0;
    //grade
    glPushMatrix();
    //tras/frente - cima/baixo - direita/esquerda
    glTranslatef (-37.0, 10-baixo, -6.2);
    //largura, altura, espessura
    //espessura 98 deixa a grade no mesmo tamanho da parede da sala
    glScalef (0.2, 0.2, 120);
    glutSolidCube (0.5);
    glPopMatrix();
  }
}

void compoe_cadeiras(void){
  GLUquadricObj *quadric;
  // inicia a composicao do computador
  cadeiras = glGenLists(1);
  glNewList(cadeiras, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado, atras = 0;
  //compoe cadeiras, 4 colunas
  for(int i = 0; i<4; i++){
    atras = i * 9.5;
    //6 cadeiras lado a lado - 3 da cada lado
    for(int j=0; j<6; j++){
      lado = j*6.0;
      if (j>2){
        lado = lado + 8;
      }

      //pe cadeira - atrás esquerda
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      gluQuadricTexture(quadric, GL_TRUE);
      glPushMatrix();
      glRotatef(90,1,0,0);
      //-tras/frente+ - +esquerda/direita- - +baixo/cima-
      glTranslatef (8-lado, -0.8-atras, 6.8);
      SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
      gluDeleteQuadric(quadric);
      glPopMatrix();


      //pe cadeira - atrás direita
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      gluQuadricTexture(quadric, GL_TRUE);
      glPushMatrix();
      glRotatef(90,1,0,0);
      //-tras/frente+ - +esquerda/direita- - +baixo/cima-
      glTranslatef (6-lado, -0.8-atras, 6.8);
      SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
      gluDeleteQuadric(quadric);
      glPopMatrix();


      //pe cadeira - frente esquerda
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      gluQuadricTexture(quadric, GL_TRUE);
      glPushMatrix();
      glRotatef(90,1,0,0);
      //-tras/frente+ - +esquerda/direita- - +baixo/cima-
      glTranslatef (8-lado, 1.2-atras, 6.8);
      SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
      gluDeleteQuadric(quadric);
      glPopMatrix();


      //pe cadeira - frente direita
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      gluQuadricTexture(quadric, GL_TRUE);
      glPushMatrix();
      glRotatef(90,1,0,0);
      //-tras/frente+ - +esquerda/direita- - +baixo/cima-
      glTranslatef (6-lado, 1.2-atras, 6.8);
      SOLID_CLOSED_CYLINDER(quadric, 0.1, 0.1, 3.3, 30, 5)
      gluDeleteQuadric(quadric);
      glPopMatrix();

      //assento cadeira
      glPushMatrix();  
      //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (7-lado, -6.8, 0.3-atras);
      glScalef(4.0,0.3,3.0);
      quadric=gluNewQuadric();
      glColor3f(0.3,0.5,1);
     
      gluSphere(quadric,0.5,15,12);
      glPopMatrix();

      //apoio encosto cadeira - vertical
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();   
      glColor3f(0,0,0);
      glRotatef(90,1,0,0);  
      glTranslatef (7-lado, -1.8-atras, 5);
      //tras/frente - direita/esquerda - cima/baixo 
      SOLID_CLOSED_CYLINDER(quadric, 0.15, 0.15, 2.2, 30, 1)
      //gluDeleteQuadric(quadric);
      glPopMatrix();

      //encosto cadeira
      glPushMatrix();  
      //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (7-lado, -4.75, -1.5-atras);
      glRotatef(-15,1,0,1);
      glScalef(4,3,0.5);
      quadric=gluNewQuadric();
      glColor3f(0.3,0.5,1);
      
      gluSphere(quadric,0.5,15,12);
      glPopMatrix();

      //apoio encosto cadeira - horizontal
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL);
      gluQuadricOrientation(quadric, GLU_INSIDE);
      glPushMatrix();   
      glColor3f(0,0,0);
      glTranslatef (7-lado, -7, -2-atras);
      //tras/frente - cima/baixo - direita/esquerda 
      SOLID_CLOSED_CYLINDER(quadric, 0.15, 0.15, 2.2, 30, 1)
      gluDeleteQuadric(quadric);
      glPopMatrix();
    }
  }
}

void compoe_parede_entrada_porta(void){
  //entrada da sala - frente
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 0.0, 14.0);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 2.0);
  glutWireCube (5.0);
  glPopMatrix();

  //entrada da sala - direita preenchida
  glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 0.0, 10.0);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.2);
  glutSolidCube (5.0);
  glPopMatrix();

  //entrada da sala - esquerda preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 0.0, 18.8);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();


  //entrada da sala - meio preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 0.0, 12.3);
  //espessura, altura, largura
  glScalef (0.05, 4.0, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();

  //entrada da sala - horizontal lado direito
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, -5.7, 11.3);
  //espessura, altura, largura
  glScalef (0.05, 0.06, 0.4);
  glutSolidCube (5.0);
  glPopMatrix();

  //entrada da sala - horizontal meio
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 5.4, 14.1);
  //espessura, altura, largura
  glScalef (0.05, 0.06, 1.8);
  glutSolidCube (5.0);
  glPopMatrix();

  //entrada da sala - horizontal topo
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 9.5, 14.1);
  //espessura, altura, largura
  glScalef (0.05, 0.2, 1.8);
  glutSolidCube (5.0);
  glPopMatrix();

  //entrada da sala - lateral
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (7.0, 0.0, 9.4);
  //largura, altura, espessura
  glScalef (1.2, 4.0, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();
}

void compoe_parede_entrada(void){

  //parede entrada - baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, -1.6, -10.8);
  //espessura, altura, largura
  glScalef (0.1, 3.37, 8.1);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede entrada - meio verical 1
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 0.0, -15.1);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.4);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede entrada - meio verical 2
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 0.0, 1.8);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.4);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede entrada - parte topo
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 10.0, -6);
  //espessura, altura, largura
  glScalef (0.1, 0.1, 10.0);
  glutSolidCube (5.0);
  glPopMatrix();

  compoe_parede_entrada_porta();
}

void compoe_parede_exterior(void){

  //parede exterior sol - parte baixo
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, -5.5, -6);
  //espessura, altura, largura
  glScalef (0.1, 1.9, 10.0);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior sol - parte cima
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, 6.5, -6);
  //espessura, altura, largura
  glScalef (0.1, 0.1, 10.0);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior sol - meio verical 1
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, 0.0, -15.1);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.4);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior sol - meio vertical 2
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, 0.0, 1.8);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.4);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior sol - meio vertical 3
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, 0.0, 18.3);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 0.29);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior sol - parte topo
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-33.8, 10.0, -6);
  //espessura, altura, largura
  glScalef (0.1, 0.1, 10.0);
  glutSolidCube (5.0);
  glPopMatrix();
}

void compoe_sala(void){
  GLUquadricObj *quadric;
  

  /* inicia a composicao da sala */
  sala = glGenLists(1);
  glNewList(sala, GL_COMPILE);

  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);

 

  //ar condicionado esquerdo
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glPushMatrix();
  glColor3f(1,1,1);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (2.0, 7.5, -30.5);
  //espessura, altura, largura
  glScalef (0.8, 0.4, 0.15);
  glBindTexture(GL_TEXTURE_2D, texture_id[1]);
  glutSolidCube (10.0);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);


//ar condicionado direito
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glPushMatrix();
  glColor3f(1,1,1);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-25.0, 7.5, -30.5);
  //espessura, altura, largura
  glScalef (0.8, 0.4, 0.15);
  glBindTexture(GL_TEXTURE_2D, texture_id[1]);
  glutSolidCube (10.0);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);

  //janela sobre a porta
  glPushMatrix();
  glColor3f(1,1,1);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 7.5, 15.5);
  //espessura, altura, largura
  glScalef (0.1, 1.0, 1.5);
  glutWireCube (4.0);
  glPopMatrix();

 

  //janela do lado da janela sobre a porta
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, 7.5, 11.2);
  //espessura, altura, largura
  glScalef (0.1, 1.0, 0.5);
  glutWireCube (4.0);
  glPopMatrix();

  //janela lateral do lado da porta
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, -0.2, 11.2);
  //espessura, altura, largura
  glScalef (0.1, 2.68, 0.5);
  glutWireCube (4.0);
  glPopMatrix();

  //janela lateral em baixo da janela lateral do lado da porta
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (4.3, -7.8, 11.2);
  //espessura, altura, largura
  glScalef (0.1, 1.0, 0.5);
  glutWireCube (4.0);
  glPopMatrix();

  //tela do projetor
  //glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  //glTranslatef (-16, -1.5, 18.5);
  //largura, altura, espessura
  //glScalef (3, 2.8, 0.05);
  //glutWireCube (5.0);
  //glPopMatrix();

  //quadro
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glPushMatrix();
  glColor3f(0.75,0.75,0.75);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-15.7, 1., 18.5);
  //largura, altura, espessura
  glScalef (4, 1.5, 0.05);
  glBindTexture(GL_TEXTURE_2D, texture_id[2]);
  glutSolidCube (5.0);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);




  //parede quadro
  glPushMatrix();
  glColor3f(0.7,0.7,0.7);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-12, 0, 19.2);
  //largura, altura, espessura
  glScalef (8.9, 4, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();


  //teto
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.85, 10.0, -6.0);
  //largura, altura, espessura
  glScalef (10.05, 0.1, 10);
  glutWireCube (5.0);
  glPopMatrix();


/*
  //piso 

  //glEnable(GL_TEXTURE_GEN_S);
  //glEnable(GL_TEXTURE_GEN_T);

glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glBindTexture(GL_TEXTURE_2D, textura_plano);
  glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
		glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
		glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
        glEnd();
	glDisable(GL_TEXTURE_2D);
 
  glColor3f(0.85,0.85,0.85);
  //tras/frente - cima/baixo - direita/esquerda
 glPushMatrix();
  glTranslatef (-14.85, -10.0, -6.0);
  //largura, altura, espessura
  glScalef (10.05, 0.1, 10);
  //glBindTexture(GL_TEXTURE_2D, texture_id[texture_floor]);
  glutSolidCube (5.0);
  glPopMatrix();
  //glDisable(GL_TEXTURE_GEN_S);
  //glDisable(GL_TEXTURE_GEN_T);*/

/*//textura do chao 1 (com quadrado)
draw_wall(-55.0f, -25, -25.0f,
      -55.0f, -25,  25.0f,
      55.0f, -25,  25.0f,
      55.0f, -25, -25.0f,0);*/

 // piso
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
 
  glColor3f(0.85,0.85,0.85);
  //tras/frente - cima/baixo - direita/esquerda
 glPushMatrix();
  glTranslatef (-14.85, -10.0, -6.0);
  //largura, altura, espessura
  glScalef (10.05, 0.1, 10);
  glBindTexture(GL_TEXTURE_2D, texture_id[0]);
  glutSolidCube (5.0);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);

  glBegin(GL_QUADS);
  glTexCoord2fv(ctpi[0]);  glVertex3f(-4.0,0.0,9.7);
  glTexCoord2fv(ctpi[1]);  glVertex3f(9.0,0.0,5.0);
  glTexCoord2fv(ctpi[2]);  glVertex3f(9.0,0.0,-4.0);
  glTexCoord2fv(ctpi[3]);  glVertex3f(-4.0,0.0,-4.0);
  glEnd(); 

  //parede ar
  glPushMatrix();
  glColor3f(1,1,1);
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-12, 0, -31);
  //largura, altura, espessura
  glScalef (8.9, 4, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();

  glColor3f(0,0,1.0);
  compoe_grade();

  glColor3f(1.0,1.0,1.0);

  compoe_parede_exterior();
  compoe_parede_entrada();

  compoe_janelas_sol();
  compoe_janelas_entrada();

  compoe_biros_esquerdo();
  compoe_biros_direito();
  glColor3f(0,0,0);
  compoe_computador_esq();
  compoe_computador_dir();

  compoe_cadeiras();

  glEndList();
}

void display(void){
  glEnable(GL_DEPTH_TEST);
  
  glDepthMask(GL_TRUE);
  glClearColor(0.5,0.5,0.5,0.5);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
  glPushMatrix();

  /* calcula a posicao do observador */
  obs[0]=raioxz*cos(2*PI*tetaxz/360);
  obs[2]=raioxz*sin(2*PI*tetaxz/360);

  gluLookAt(obs[0],obs[1],obs[2],look[0],look[1],look[2],0.0,1.0,0.0);

  glCallList(sala);
  glCallList(biros_esq);
  glCallList(biros_dir);
  glCallList(comp_esq);
  glCallList(comp_dir);
  glCallList(janelas_sol);
  glCallList(janelas_entrada);
  glCallList(grade);
  glCallList(cadeiras);


  //porta
  glColor3f(1.0,1.0,0.0);
  glPushMatrix();
  //eixo de rotação
  glTranslatef (4.3, -2.4, 18.25);
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glTranslatef (-4.3, 2.4, -18.25);

  glTranslatef (4.3, -2.4, 15.5);
  //espessura, altura, largura
  glScalef (0.1, 3.8, 1.5);
  glutSolidCube (4.0);
  
  glPopMatrix();
  glPopMatrix();  


  glutSwapBuffers();
}




void special(int key, int x, int y){
  float fraction = 1;
  switch (key) {
  case GLUT_KEY_UP:
		obs[1] = obs[1] + fraction;
    glutPostRedisplay();
    break;
  case GLUT_KEY_DOWN:
		obs[1] = obs[1] - fraction;
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
    //if(raioxz==0){
     // raioxz=1;
    //}
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


void loadTextureFromFile(char *filename,int index)
{

	 int width, height;
   unsigned char* image =
       SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

			 printf("%d %d\n", width, height);

   glGenTextures(1, &texture_id[index]);
   glBindTexture(GL_TEXTURE_2D, texture_id[index]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_BLEND);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_BLEND);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	 glBindTexture(GL_TEXTURE_2D, 0);
}

void init_textures(){

		loadTextureFromFile("floor.jpg",0);
		loadTextureFromFile("ar.jpg",1);
    loadTextureFromFile("board.jpg",2);
    loadTextureFromFile("wall.jpg",3);

}

void init(){

  
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
 
  // habilitando as texturas
  //init_textures();
  compoe_sala();
}

int main(int argc,char **argv){
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);

  if(!glutCreateWindow("Laboratório 1 - Instituto de Computação - UFAL")) {
    fprintf(stderr,"Error opening a window.\n");
    exit(-1);
  }

  init();
  init_textures();
  
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
 
  glutMainLoop();



  return(0);
}
