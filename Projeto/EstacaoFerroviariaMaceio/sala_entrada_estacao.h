#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef SALA_ENTRADA_ESTACAO_H 
#define SALA_ENTRADA_ESTACAO_H

void compoe_banheiros(void);


void compoe_teto(void){
	 // teto - parte esquerda 
  glPushMatrix();
    glColor3f(0.5f, 0.35f, 0.05f);
    //tras/frente - cima/baixo - direita/esquerda
    glTranslatef (-14.85, 17.0, 26.7);
    //espessura, altura, largura
    glScalef (10.05, 0.1, 7.0);
    glutSolidCube (5.0);
  glPopMatrix();

     // teto - parte direita
  glPushMatrix();
      glColor3f(0.5f, 0.35f, 0.05f);
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-14.85, 17.0, -38.0);
      //espessura, altura, largura
      glScalef (10.05, 0.1, 7.0);
      glutSolidCube (5.0);
  glPopMatrix();

     // teto - parte meio
    glPushMatrix();
      glColor3f(0.5f, 0.35f, 0.05f);
      //tras/frente - cima/baixo - direita/esquerda
      glTranslatef (-14.85, 30.0, -4.0);
      //espessura, altura, largura
      glScalef (10.05, 0.1, 7.0);
      glutSolidCube (5.0);
  glPopMatrix();


}

void compoe_parede_entrada_sala_entrada(void){

  glColor3f(1.0, 1.0, 0);
  //parede entrada  - parte 1- baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, -4.9, 26.7);
  //espessura, altura, largura
  glScalef (0.1, 8.7, -9.0);
  glutSolidCube (5.0);
  glPopMatrix();


 // parede entrada - parte 2 - baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, -4.9, -32.9);
  //espessura, altura, largura
  glScalef (0.1, 8.7, 9.0);
  glutSolidCube (5.0);
  glPopMatrix();


  // parede entrada - parte cima preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (10, 20.3, -4.0);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 7.0);
  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_traseira_sala_entrada(void){

  //parede traseira  - parte 1- baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-39.8, -4.9, 26.7);
  //espessura, altura, largura
  glScalef (0.1, 8.7, -7.0);
  glutSolidCube (5.0);
  glPopMatrix();


 // parede traseira - parte 2 - baixo preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-39.8, -4.9, -37.9);
  //espessura, altura, largura
  glScalef (0.1, 8.7, 7.0);
  glutSolidCube (5.0);
  glPopMatrix();

   // parede traseira - parte 2 - cima preenchida
  glPushMatrix();
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-39.8, 20.3, -4.0);
  //espessura, altura, largura
  glScalef (0.1, 4.0, 7.0);
  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_direita_sala_entrada(void){
	glPushMatrix();
  // parede direita- parte 1 - baixo preenchida
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.7, -4.9, 44.0);
  //largura, altura, espessura
  glScalef (10.0, 8.7, 0.1);

  glutSolidCube (5.0);
  glPopMatrix();


  glPushMatrix();
  // parede direita- parte superior
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.7, 20.5, 13.0);
  //largura, altura, espessura
  glScalef (10.0, 3.9, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();

   glPushMatrix();
  // parede direita- parte superior
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-10.5, -10.0, 13.0);
  //largura, altura, espessura
  glScalef (7.7, 8.7, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();

}

void compoe_parede_esquerda_sala_entrada(void){
  glPushMatrix();
  // parede esquerda- parte 1 - baixo preenchida
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-15, -4.9, -55.7);
  //largura, altura, espessura
  glScalef (10.0, 8.7, 0.1);

  glutSolidCube (5.0);
  glPopMatrix();

  glPushMatrix();
  // parede esquerda - parte superior
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.7, 20.5, -21.7);
  //largura, altura, espessura
  glScalef (10.0, 3.9, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();

  glPushMatrix();
  // parede esquerda - parte superior
  //tras/frente - cima/baixo - direita/esquerda
  glTranslatef (-14.7, -10, -21.7);
  //largura, altura, espessura
  glScalef (5.0, 3.9, 0.1);
  glutSolidCube (5.0);
  glPopMatrix();
}


void compoe_biros_direito(void){
  GLUquadricObj *quadric;
  // inicia a composicao do biro
  GLuint biros_dir;
  biros_dir = glGenLists(1);
  glNewList(biros_dir, GL_COMPILE);
  quadric = gluNewQuadric();
  glColor3f(1.0, 1.0, 1.0);
  //gluQuadricTexture(quadric, GL_TRUE);

  GLfloat lado, atras;
  int i, j;
  //compoe biros do lado da porta, 4 colunas
  for(i = 3; i<4; i++){
    atras = i * 17.0;
    //3 biros lado a lado
    for(j=0; j<3; j++){
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
void compoe_biros_esquerdo(void) {
 
 GLUquadricObj *quadric;
  glColor3f(1.0, 1.0, 1.0);
// inicia a composicao do biro
  GLuint biros_esq = glGenLists(1);
  glNewList(biros_esq, GL_COMPILE);
  quadric = gluNewQuadric();
  //gluQuadricTexture(quadric, GL_TRUE);
  GLfloat lado, atras;
  //compoe biros do lado da porta, 4 colunas
  int i,j;
  for(i = 3; i<4; i++){
    atras = i * 17.0;
    //3 biros lado a lado
    for(j=0; j<3; j++){
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



// void compoe_banheiros(void){
//   glColor3f(1.0, 1.0, 1.0);
//   glPushMatrix();
//      //parede vertical
//     //tras/frente - cima/baixo - direita/esquerda
//     glTranslatef (-6.7, 4.9, 15.0);
//     //largura, altura, espessura
//     glScalef (7.0, 5.7, 0.3);
//     glutSolidCube (5.0);
//   glPopMatrix();
//    //parede horizontal
//   glPushMatrix();
//     //tras/frente - cima/baixo - direita/esquerda
//     glTranslatef (-33.8, 4.9, 26.7);
//     //espessura, altura, largura
//     glScalef (0.1, 5.7, -6.0);
//     glutSolidCube (5.0);
//   glPopMatrix();
 
 
//   glPushMatrix();
//     //tras/frente - cima/baixo - direita/esquerda
//     glTranslatef (-5.8, 4.9, 26.7);
//     //espessura, altura, largura
//     glScalef (0.1, 5.7, -3.0);
//     glutSolidCube (5.0);
//   glPopMatrix();
// }




#endif