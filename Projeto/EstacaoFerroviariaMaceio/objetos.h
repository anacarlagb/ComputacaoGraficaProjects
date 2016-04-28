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

GLfloat ctp[4][2]={
  {-COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//direita - cima
  {+COORD_TEXTURA_PLANO,-COORD_TEXTURA_PLANO},//esquerda - cima
  {+COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO},//direita -  baixo
  {-COORD_TEXTURA_PLANO,+COORD_TEXTURA_PLANO} //direita - baixo
};


void compoe_obj_porta(void);
void carrega_textura_porta(void);


void compoe_obj_porta(void){
  glBegin(GL_QUADS);
    glTexCoord2fv(ctp[0]);  glVertex3f(-10,10,10); //cima - direita
    glTexCoord2fv(ctp[1]);  glVertex3f(10,10,10);  //embaixo - direita
    glTexCoord2fv(ctp[2]);  glVertex3f(10,0,-10);  //cima - esquerda
    glTexCoord2fv(ctp[3]);  glVertex3f(-10,0,-10); //baixo - esquerda
  glEnd();
  glTranslatef(28.0,3.0,25.0);
}


void carrega_textura_porta(void){
    LoadGLTextures("fachada.bmp");
}


#endif