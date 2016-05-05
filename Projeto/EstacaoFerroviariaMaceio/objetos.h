#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>  // Header File For The OpenGL32 Library
#include <GL/glu.h> // Header File For The GLu32 Library
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <unistd.h>     // needed to sleep.
#include "sala_entrada_estacao.h"
#include "image.h"

#ifndef OBJETOS_H 
#define OBJETOS_H

#define COORD_TEXTURA_PLANO 1.0
#define COR_DO_PLANO 0.3,0.52,0.18,1.0

GLfloat ctp[4][2]={
  {-COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},
  {+COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},
  {+COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO},
  {-COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO}
};


typedef struct
{
  float x;
  float y;
}CIRCLE;

CIRCLE circle;

//Fonte: http://www.swiftless.com/tutorials/opengl/circle.html
void createcircle (int k, int r, int h) {
  glColor3f(0.5f, 0.35f, 0.05f);
  glBegin(GL_LINES);
      int i;
      for (i = 0;i < 180; i++){      
          glVertex3f(circle.x + k,circle.y - h, 13.6);
          circle.x = r * cos(i + 0.1) - h;
          circle.y = r * sin(i + 0.1) + k;
          glVertex3f(circle.x + k,circle.y - h, 13.6);
      }
  glEnd();
};

void compoe_obj(void);
void compoe_obj_porta(void); 
void compoe_janelas_parede_esquerda_inferior(void); 
void compoe_janelas_parede_direita_inferior(void);
void compoe_janelas_parede_superior(void); 
void compoe_textura_relogio(void); 

void carrega_textura(int indexImage);
void carrega_textura_porta(int indexImage);
void carrega_textura_paredes_laterais(int indexImage);
void carrega_textura_paredes_superior(int indexImage);
void carrega_textura_grama(int indexImage);
void carrega_textura_relogio(int indexImage);
void compoe_catracas(void);


void compoe_obj(void){
 glBindTexture(GL_TEXTURE_2D, texture[0]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glTexCoord2fv(ctp[0]);  glVertex3f(-10,10,10); //cima - direita
    glTexCoord2fv(ctp[1]);  glVertex3f(10,10,10);  //embaixo - direita
    glTexCoord2fv(ctp[2]);  glVertex3f(10,0,-10);  //cima - esquerda
    glTexCoord2fv(ctp[3]);  glVertex3f(-10,0,-10); //baixo - esquerda
  glEnd();
  glTranslatef(28.0,3.0,25.0);
}

void compoe_janelas_parede_esquerda_inferior(void){
  glBindTexture(GL_TEXTURE_2D, texture[1]);   // choose the texture to use. 
  //janela 1 - lado esquerdo
  glBegin(GL_QUADS); // x- frente/traz y -altura z - largura
    glColor3f(1.0, 1.0, 0);
     glTexCoord2fv(ctp[0]);  glVertex3f(11.0f,  -27.0f,  25.0f);  // Top Right Of The Texture and Quad
     glTexCoord2fv(ctp[1]);  glVertex3f(11.0f,  -27.0f,    0.0f);  // Top Left Of The Texture and Quad  
     glTexCoord2fv(ctp[2]);  glVertex3f(11.0f,   11.0f,    0.0f);  // Bottom Left Of The Texture and Quad
     glTexCoord2fv(ctp[3]);  glVertex3f(11.0f,   11.0f,   25.0f);  // Bottom Right Of The Texture and Quad
  glEnd();
   glTranslatef(0,0,-88.8); //x- frente/traz y -cima/baixo z - esquerda/direita
}

void compoe_janelas_parede_direita_inferior(void){
  glBindTexture(GL_TEXTURE_2D, texture[2]);   // choose the texture to use. 
  //janela 1 - lado esquerdo
  glTranslatef(0,0,30.8); //x- frente/traz y -cima/baixo z - esquerda/direita
  glBegin(GL_QUADS); // x- frente/traz y -altura z - largura
    glColor3f(1.0, 1.0, 0);
     glTexCoord2fv(ctp[0]);  glVertex3f(11.0f,  -27.0f,  25.0f);  // Top Right Of The Texture and Quad
     glTexCoord2fv(ctp[1]);  glVertex3f(11.0f,  -27.0f,    0.0f);  // Top Left Of The Texture and Quad  
     glTexCoord2fv(ctp[2]);  glVertex3f(11.0f,    11.0f,    0.0f);  // Bottom Left Of The Texture and Quad
     glTexCoord2fv(ctp[3]);  glVertex3f(11.0f,    11.0f,   25.0f);  // Bottom Right Of The Texture and Quad
  glEnd();
  glTranslatef(0,0,45.8); //x- frente/traz y -cima/baixo z - esquerda/direita
} 



void compoe_janelas_parede_superior(void){
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, texture[3]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0);
    glTexCoord2fv(ctp[0]);  glVertex3f(11.0f,  12.0f,  -12.0f);  // Top Right Of The Texture and Quad
    glTexCoord2fv(ctp[1]);  glVertex3f(11.0f,  12.0f,    5.0f);  // Top Left Of The Texture and Quad  
    glTexCoord2fv(ctp[2]);  glVertex3f(11.0f,  30.0f,   5.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2fv(ctp[3]);  glVertex3f(11.0f,  30.0f, -12.0f);  // Bottom Right Of The Texture and Quad
  glEnd();
 glPopMatrix();
 
}



void compoe_grama(void){
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, texture[4]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0);
      glTexCoord2fv(ctp[0]);  glVertex3f(-100,-10,  150);
      glTexCoord2fv(ctp[1]);  glVertex3f( 80, -10,  150);
      glTexCoord2fv(ctp[2]);  glVertex3f( 80, -10, -150);
      glTexCoord2fv(ctp[3]);  glVertex3f(-100,-10, -150);
  glEnd();
 glPopMatrix();

}

void compoe_textura_relogio(void){
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, texture[5]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
   glTexCoord2f(0.0f, 0.0f); glVertex3f(12.0f,  28.0f,   -5.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(12.0f,  28.0f,   0.5f);  // Top Left Of The Texture and Quad  
    glTexCoord2f(1.0f, 1.0f); glVertex3f(12.0f,  33.5f,   0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(12.0f,  33.5f,   -5.0f);  // Bottom Right Of The Texture and Quad
  glEnd();
 glPopMatrix();
}


void compoe_mesa(void){
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, texture[6]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glColor3f(1.0, .0, .0);
        glTexCoord2f(0.0f, 1.0f);  glVertex3f(-20, -6,  24);
        glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0,  -6,  24);
        glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0,  -6,  16);
        glTexCoord2f(1.0f, 1.0f);  glVertex3f(-20, -6,  16);
  glEnd();
 glPopMatrix();

    GLUquadricObj *quadric;
    glPushMatrix();
       //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (-10.0, -9.0, 20);
      //largura, altura, espessura
      glScalef(3.0,2.0,1.0);
      quadric = gluNewQuadric();
      glColor3f(0.5f, 0.35f, 0.05f);  
      glutSolidCube (3.0);
    glPopMatrix();


  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, texture[6]);   // choose the texture to use. 
  glBegin(GL_QUADS);
    glColor3f(1.0, .0, .0);
        glTexCoord2f(0.0f, 1.0f);  glVertex3f(-20, -6, 40);
        glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0, -6,  40);
        glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0, -6,  30);
        glTexCoord2f(1.0f, 1.0f);  glVertex3f(-20,-6, 30);
  glEnd();
 glPopMatrix();

    GLUquadricObj *quadric2;
    glPushMatrix();
       //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (-10.0, -9.0, 35);
      //largura, altura, espessura
      glScalef(3.0,2.0,1.0);
      quadric2 = gluNewQuadric();
      glColor3f(0.5f, 0.35f, 0.05f);  
      glutSolidCube (3.0);
    glPopMatrix();

}

void compoe_fachada_lanchonete(void){
   glPushMatrix();
    glColor3f(1.0, 1.0, 0);
    glBindTexture(GL_TEXTURE_2D, texture[7]);   // choose the texture to use. 
    glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-39.0f,  4.0f,  10.0f);  // Top Left Of The Texture and Quad 
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-39.0f,  10.0f,  10.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-39.0f,  10.0f,  40.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-39.0f,  4.0f,  40.0f);  // Top Right Of The Texture and Quad 
      
    glEnd();
  glPopMatrix();
}

void compoe_fachada_venda_trem(void){
   glPushMatrix();
    glColor3f(1.0, 1.0, 0);
    glBindTexture(GL_TEXTURE_2D, texture[8]);   // choose the texture to use. 
    glBegin(GL_QUADS);
     glColor3f(1.0, 1.0, 1.0);
     glTexCoord2f(1.0f, 0.0f);  glVertex3f(-38.0f,    2.0f,  -50.0f);  // Top Left Of The Texture and Quad 
     glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0f,    10.0f,  -50.0f);  // Bottom Left Of The Texture and Quad
     glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0f,    10.0f,  -30.0f);  // Bottom Right Of The Texture and Quad
     glTexCoord2f(0.0f, 0.0f); glVertex3f(-38.0f,     2.0f,  -30.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
}

void compoe_fachada_frontal(void){
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.1f,    -10.0f,  -55.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,     17.0f,  -55.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,     17.0f,  -51.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.1f,    -10.0f,  -51.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.0f,    -10.0f,  49.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.f,     17.0f,  49.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.f,     17.0f,  44.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.f,    -10.0f,  44.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();


   glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.0f,    -10.0f,  13.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.f,     30.0f,  13.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.f,     30.0f,  9.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.f,    -10.0f,  9.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.0f,    -10.0f,  -18.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.f,     30.0f,  -18.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.f,     30.0f,  -22.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.f,    -10.0f,  -22.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.1f,    26.0f,   9.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,     30.0f,  9.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,     30.0f,  -22.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.1f,    26.0f,   -22.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.1f,    18.0f,  -55.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,    14.0f,  -55.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,    14.0f,  -20.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.1f,    18.0f,  -20.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[9]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(11.1f,    18.0f,  12.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,    14.0f,  12.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,    14.0f,  49.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(11.1f,    18.0f,  49.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
}

void compoe_telhado(void){
    // telhado  - meio  - frente
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.1f,     48.0f,    13.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,     30.0f,    13.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,     30.0f,  -22.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.1f,     48.0f,  -22.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
    // telhado  - meio  - atras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.1f,     30.0f,    13.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.1f,     48.0f,    13.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.1f,     48.0f,   -22.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.1f,     30.0f,  -22.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();


  // telhado esquerdo - frente 
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.1f,     35.0f,    49.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,     17.0f,    49.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,     17.0f,  13.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.1f,     35.0f,  13.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
       // telhado esquerdo - atras 
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.1f, 17.0f, 49.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.1f , 35.0f, 49.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.1f , 35.0f, 13.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.1f, 17.0f, 13.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

      // telhado direito  - frente
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.1f,     35.0f,    -22.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(11.1f,     17.0f,    -22.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(11.1f,     17.0f,    -55.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.1f,     35.0f,   -55.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
     // telhado direito  - atras
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[10]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(0.5f, 0.35f, 0.05f);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.1f,  17.0f,    -22.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.1f,   35.0f,    -22.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.1f,   35.0f,    -55.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.1f,  17.0f,   -55.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
}

void compoe_textura_catraca(void){
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[11]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-49,   -2.0f,    8.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-49,   -4.0f,    8.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-49,   -4.0f,    10.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-49,   -2.0f,    10.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[11]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-49,   -2.0f,    0.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-49,   -4.0f,    0.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-49,   -4.0f,    2.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-49,   -2.0f,    2.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[11]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-49,   -2.0f,    -8.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-49,   -4.0f,    -8.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-49,   -4.0f,    -10.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-49,   -2.0f,    -10.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[11]);   // choose the texture to use. 
     glBegin(GL_QUADS);
       glColor3f(1.0, 1.0, 1.0);
       glTexCoord2f(1.0f, 0.0f); glVertex3f(-49,   -2.0f,    -16.0f);  // Top Left Of The Texture and Quad 
       glTexCoord2f(1.0f, 1.0f); glVertex3f(-49,   -4.0f,    -16.0f);  // Bottom Left Of The Texture and Quad
       glTexCoord2f(0.0f, 1.0f); glVertex3f(-49,   -4.0f,    -18.0f);  // Bottom Right Of The Texture and Quad
       glTexCoord2f(0.0f, 0.0f); glVertex3f(-49,   -2.0f,    -18.0f);  // Top Right Of The Texture and Quad  
    glEnd();
  glPopMatrix();
}
void compoe_catracas(void){
   GLUquadricObj *quadric;
    GLuint catracas = glGenLists(1);
    glNewList(catracas, GL_COMPILE);
    glPushMatrix();  
       //+tras/frente- - +baixo/cima- - - +esquerda/direita-
      glTranslatef (-52.0, -12.0, 8);
      //largura, altura, espessura
      glScalef(2.0,7.0,1.0);
      quadric = gluNewQuadric();
      glColor3f(0,0,0);
      glutSolidCube (3.0);
    glPopMatrix();


  glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (-52.0, -12.0, 0);
    //largura, altura, espessura
    glScalef(2.0,7.0,1.0);
    quadric = gluNewQuadric();
    glColor3f(0,0,0);
    glutSolidCube (3.0);
  glPopMatrix();

  glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (-52.0, -12.0, -8);
    //largura, altura, espessura
    glScalef(2.0,7.0,1.0);
    quadric = gluNewQuadric();
    glColor3f(0,0,0);
    glutSolidCube (3.0);
  glPopMatrix();


  glPushMatrix();  
     //+tras/frente- - +baixo/cima- - - +esquerda/direita-
    glTranslatef (-52.0, -12.0, -16);
    //largura, altura, espessura
    glScalef(2.0,7.0,1.0);
    quadric = gluNewQuadric();
    glColor3f(0,0,0);
    glutSolidCube (3.0);
  glPopMatrix();
}

void compoe_textura_trilho_trem(void){
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[12]);   // choose the texture to use. 
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_QUADS);
       glTexCoord2f(0.0f, 1.0f);  glVertex3f(-98, -9,  6);
       glTexCoord2f(0.0f, 0.0f);  glVertex3f(-62, -9,  6);
       glTexCoord2f(1.0f, 0.0f);  glVertex3f(-62, -9, -10);
       glTexCoord2f(1.0f, 1.0f);  glVertex3f(-98, -9, -10);
    glEnd();
   glPopMatrix();


}

void compoe_trem(void){
    glBindTexture(GL_TEXTURE_2D, texture[13]);   // choose the texture to use. 

  glPushMatrix();
      glColor3f(1, 0, 0);
     // /* nariz */
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      glTranslatef(-65,0,-2);
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      gluCylinder(quadratic,5,0.3f,5.0f,32,32);  
  glPopMatrix(); 

  glPushMatrix(); 
        /* corpo */
      glColor3f(1, 1, 1);
      GLUquadricObj *quadric;
      glTranslatef(-73,0,-2);
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      quadric = gluNewQuadric();
      gluQuadricTexture(quadric, GL_TRUE);
      gluCylinder(quadric, 5, 5, 8, 32, 32);     
  glPopMatrix();

  glPushMatrix(); 
        /* corpo */
      glColor3f(1, 1, 1);
      GLUquadricObj *quadric3;
      glTranslatef(-97,0,-2);
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      quadric3 = gluNewQuadric();
      gluQuadricTexture(quadric, GL_TRUE);
      gluCylinder(quadric, 10, 5, 28, 32, 32);     
  glPopMatrix();
  
}



void carrega_textura(int indexImage){
  LoadGLTextures("fachada.bmp", indexImage);
}

void carrega_textura_porta(int indexImage){
  LoadGLTextures("objetos/porta5.bmp", indexImage);
}

void carrega_textura_paredes_laterais(int indexImage){
  LoadGLTextures("objetos/janela1.bmp", indexImage);
}
void carrega_textura_paredes_superior(int indexImage){
  LoadGLTextures("objetos/fachada_frente_cima.bmp", indexImage);
}

void carrega_textura_grama(int indexImage){
  LoadGLTextures("objetos/grama.bmp", indexImage);
}

void carrega_textura_relogio(int indexImage){
  LoadGLTextures("objetos/relogio3.bmp", indexImage);
}

void carrega_textura_mesa(int indexImage){
  LoadGLTextures("objetos/toalhaMesa.bmp", indexImage);
}
void carrega_fachada_lanchonete(int indexImage){
  LoadGLTextures("objetos/fachada_lanchonete.bmp", indexImage);
}

void carrega_fachada_passagem(int indexImage){
  LoadGLTextures("objetos/fachada_venda_trem.bmp", indexImage);
}

void carrega_fachada_frontal(int indexImage){
  LoadGLTextures("objetos/cor-creme.bmp", indexImage);
}
void carrega_textura_telhado(int indexImage){
  LoadGLTextures("objetos/telhado.bmp", indexImage);
}

void carrega_textura_controle_catraca(int indexImage){
  LoadGLTextures("objetos/controle.bmp", indexImage);
}

void carrega_textura_trilho_trem(int indexImage){
   LoadGLTextures("objetos/trilho_trem2.bmp", indexImage);
}

void carrega_textura_trem(int indexImage){
   LoadGLTextures("objetos/textura_trem2.bmp", indexImage);
}


void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides )
{
    int numberOfVertices = numberOfSides + 2;
    
    GLfloat twicePi = 2.0f * M_PI;
    
    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];
    
    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = z;
    int i;
    
    for (i = 1; i < numberOfVertices; i++ )
    {
        circleVerticesX[i] = x + ( radius * cos( i *  twicePi / numberOfSides ) );
        circleVerticesY[i] = y + ( radius * sin( i * twicePi / numberOfSides ) );
        circleVerticesZ[i] = z;
    }
    
    GLfloat allCircleVertices[( numberOfVertices ) * 3];
    
    for (i = 0; i < numberOfVertices; i++ )
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
        allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
    }
    
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices );
    glDrawArrays( GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState( GL_VERTEX_ARRAY );
}
#endif