#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef SALA_ENTRADA_ESTACAO_H 
#define SALA_ENTRADA_ESTACAO_H

int soma(int *x, int *y) {
   return *x+*y;
}

void compoe_teto(void){
	glPushMatrix();
  //teto
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.85, 10.0, -6.0);
  glColor3f(0.92,0.85,0);
  //largura, altura, espessura
  glScalef (10.05, 1, 10);
  glutSolidCube (5.0);
  glPopMatrix();
}

void compoe_parede_entrada_sala_entrada(void){

  glPushMatrix();
 //parede entrada - parte topo
  //tras/frente - cima/baixo - direita/esquerda
  glColor3f(1.0, 1.0, 0);
  glTranslatef (10, 30.0, -6);
  //espessura, altura, largura
  glScalef (0.1, 0.1, 20.0);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede entrada  - parte 1- baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 7.9, 26.7);
  //espessura, altura, largura
  glScalef (0.1, 8.7, -7.0);
  glutSolidCube (5.0);
  glPopMatrix();

 // parede entrada - parte 2 - baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 7.9, -32.9);
  //espessura, altura, largura
  glScalef (0.1, 8.7, 9.0);
  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_traseira_sala_entrada(void){

  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  //-14.85, 10.0, -6.0
  glTranslatef (-39.8, 30.0, -6);
  //espessura, altura, largura
  glScalef (0.1, 0.1, 20.0);
  glutSolidCube (5.0);
  glPopMatrix();

  //parede exterior - parte 1 - baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-39.8, 7.9, -6);
  //espessura, altura, largura
  glScalef (0.1, 8.7, 20.0);
  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_direita_sala_entrada(void){
	
	glPushMatrix();
  // parede direita- parte 1 - baixo preenchida
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.7, 7.9, 44.0);
  //largura, altura, espessura
  glScalef (10.0, 8.7, 0.1);

  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_esquerda_sala_entrada(void){
    glPushMatrix();
  // parede direita- parte 1 - baixo preenchida
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-15, 7.9, -55.7);
  //largura, altura, espessura
  glScalef (10.0, 8.7, 0.1);

  glutSolidCube (5.0);
  glPopMatrix();
}



#endif