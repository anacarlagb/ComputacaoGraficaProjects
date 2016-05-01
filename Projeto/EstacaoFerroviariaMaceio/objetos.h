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
  {-COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//direita - cima
  {+COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//esquerda - cima
  {+COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO},//direita -  baixo
  {-COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO} //direita - baixo
};


typedef struct
{
  float x;
  float y;
}CIRCLE;

CIRCLE circle;

//Fonte: http://www.swiftless.com/tutorials/opengl/circle.html
void createcircle (int k, int r, int h) {
  glBegin(GL_LINES);
      int i;
      for (i = 0;i < 180; i++){      
          glVertex3f(circle.x + k,circle.y - h,0);
          circle.x = r * cos(i + 0.1) - h;
          circle.y = r * sin(i + 0.1) + k;
          glVertex3f(circle.x + k,circle.y - h,0);
      }
  glEnd();
};

void compoe_obj(void);
void compoe_obj_porta(void); 
void compoe_janelas_parede_esquerda_inferior(void); 
void compoe_janelas_parede_direita_inferior(void);
void compoe_janelas_parede_superior(void); 

void carrega_textura(int indexImage);
void carrega_textura_porta(int indexImage);
void carrega_textura_paredes_laterais(int indexImage);
void carrega_textura_paredes_superior(int indexImage);
void carrega_textura_grama(int indexImage);


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
     glTexCoord2fv(ctp[0]);  glVertex3f(11.0f,  -10.0f,  25.0f);  // Top Right Of The Texture and Quad
     glTexCoord2fv(ctp[1]);  glVertex3f(11.0f,  -10.0f,    0.0f);  // Top Left Of The Texture and Quad  
     glTexCoord2fv(ctp[2]);  glVertex3f(11.0f,   28.0f,    0.0f);  // Bottom Left Of The Texture and Quad
     glTexCoord2fv(ctp[3]);  glVertex3f(11.0f,   28.0f,   25.0f);  // Bottom Right Of The Texture and Quad
  glEnd();
   glTranslatef(0,0,-88.8); //x- frente/traz y -cima/baixo z - esquerda/direita
}

void compoe_janelas_parede_direita_inferior(void){
  glBindTexture(GL_TEXTURE_2D, texture[2]);   // choose the texture to use. 
  //janela 1 - lado esquerdo
  glTranslatef(0,0,30.8); //x- frente/traz y -cima/baixo z - esquerda/direita
  glBegin(GL_QUADS); // x- frente/traz y -altura z - largura
    glColor3f(1.0, 1.0, 0);
     glTexCoord2fv(ctp[0]);  glVertex3f(11.0f,  -10.0f,  25.0f);  // Top Right Of The Texture and Quad
     glTexCoord2fv(ctp[1]);  glVertex3f(11.0f,  -10.0f,    0.0f);  // Top Left Of The Texture and Quad  
     glTexCoord2fv(ctp[2]);  glVertex3f(11.0f,   28.0f,    0.0f);  // Bottom Left Of The Texture and Quad
     glTexCoord2fv(ctp[3]);  glVertex3f(11.0f,   28.0f,   25.0f);  // Bottom Right Of The Texture and Quad
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
      glTexCoord2fv(ctp[0]);  glVertex3f(-100, -10,100);
      glTexCoord2fv(ctp[1]);  glVertex3f( 80, -10,100);
      glTexCoord2fv(ctp[2]);  glVertex3f( 80, -10,-100);
      glTexCoord2fv(ctp[3]);  glVertex3f(-100, -10,-100);
  glEnd();
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