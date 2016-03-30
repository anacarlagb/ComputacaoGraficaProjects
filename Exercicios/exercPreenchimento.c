#include <GL/glut.h>
#include <stdlib.h>

/*
Exercicio Avaliativo - Computacao Grafica IC-UFAL
Aluna: Ana Carla Gomes Bibiano.
Fonte do código: http://www.ft.unicamp.br/~magic/opengl/preenchimento.html
*/

/*
  O vetor tux[] abaixo do tipo GLubyte representa o padrao de preenchimento de poligonos.
  Esse vetor tem um conjunto de números representados na forma hexadecimal. 
  Para construir este vetor, toma-se cada linha do mapa de bits de baixo para cima. 
  Cada 8 pixels de uma linha da figura equivalem aos bits componentes de um elemento do vetor. 
  Logo a sequencia de bits 00000000110001000010001100000000, equivalerá à sequencia "0x0, 0xc4, 0x23, 0x0" do array tux[].
*/
GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x7f,  0xfe,  0x0, 
 0x0,  0xc4,  0x23,  0x0, 
 0x1,  0x83,  0x21,  0x80, 
 0x1,  0x7,  0xe0,  0x80, 
 0x1,  0x7,  0xf0,  0x80, 
 0x1,  0x8f,  0xf9,  0x80, 
 0x0,  0xff,  0xff,  0x0, 
 0x0,  0x4f,  0xf1,  0x0, 
 0x0,  0x6f,  0xf1,  0x0, 
 0x0,  0x2f,  0xf3,  0x0, 
 0x0,  0x27,  0xe2,  0x0, 
 0x0,  0x30,  0x66,  0x0, 
 0x0,  0x1b,  0x1c,  0x0, 
 0x0,  0xb,  0x88,  0x0, 
 0x0,  0xb,  0x98,  0x0, 
 0x0,  0x8,  0x18,  0x0, 
 0x0,  0xa,  0x90,  0x0, 
 0x0,  0x8,  0x10,  0x0, 
 0x0,  0xc,  0x30,  0x0, 
 0x0,  0x6,  0x60,  0x0, 
 0x0,  0x3,  0xc0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0
};

GLfloat r,g,b;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  /*
  A funcao glutInitDisplayMode() avisa GLUT para utilizar dois buffers no desenho de cenas:
  um principal e outro auxiliar. Todos os objetos deverao ser desenhados no buffer auxiliar.
  Quando a funcao glutSwapBuffers() for chamada, o buffer auxiliar passa a ser o principal,
  e o principal toma o lugar do auxiliar. Assim, a imagem gerada
  é apresentada de uma so vez na tela, evitando cintilacoes e a visualização do processo de desenho, 
  efeitos indesejáveis principalmente em animacoes.
  */
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  /*
  Define que funcao GLUT devera chamar quando ocorrerem eventos de mouse. 
  Quando o usuario pressiona ou solta uma dos botoes do mouse, clique
  gera uma chamada de mouse. A funcao de chamada passada como argumento 
  para glutMouseFunc() deve possuir o seguinte protótipo:
  void funcao()(int button, int state, int x, int y);
  */
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  r=0; g=1; b=0;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);

  /*
   As funcoes glDisable() e glEnable() permitem habilitar diversas habilidades do OpenGL.
   O parâmetro GL_POLYGON_STIPPLE passado para essa funcao desabilita
    o desenho de poligonos utilizando padrões de desenho. 
   Quando GL_POLYGON_STIPPLE é habilitado, OpenGL usa o padrão corrente para desenhar.
  */
  glDisable(GL_POLYGON_STIPPLE);

  /*
    A funcao glPolygonMode() indica que a parte de tras dos poligonos (GL_BACK) 
    sera desenhada apenas com a linha de contorno externo (GL_LINE), de cor vermelha, 
    conforme especificado pela função glColor3f().
*/     
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(1.0, 0.0, 0.0);
/*
  As funcoes glBegin()/glEnd() sao usadas agora para iniciar
  o traçado de um polígono (GL_POLYGON) de coordenadas especificadas pela função glVertex2i(). 
  O contorno retangular vermelho é o resultado. 
  */
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();

 
    /*
      A funcao glPolygonMode() abaixo indica agora que a parte de tras dos polígonos será desenhada
      apenas com preenchimento sólido (GL_FILL). A cor de desenho agora é (R, G, B) = (0, 1, 0), 
      desenhando assim um retângulo verde
    */
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();


  /*
    Essa sequencia de glColor3f()  desenha cada vértice de uma cor diferente, 
    OpenGL interpola estas cores para compor as tonalidades do interior do polígono, 
    gerando um preenchimento bastante colorido.
  */
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);  glVertex2i(30,113);  
  glColor3f(0.0, 1.0, 0.0);  glVertex2i(113,113);
  glColor3f(0.0, 0.0, 1.0);  glVertex2i(113,30);  
  glColor3f(1.0, 1.0, 0.0);  glVertex2i(30,30); 
  glEnd();


  /*
   A funcao glEnable() é responsavel pelo pelo preenchimento de padroes. 
   
  */
  glEnable(GL_POLYGON_STIPPLE);
  /*A função glColor3f() define magenta, combinacao das tonalidades puras vermelho (R=1) e azul (B=1), 
  como a nova cor de desenho.*/
  glColor3f(1.0, 0.0, 1.0);
 /* A funcao glPolygonStipple() define o novo padrao de preenchimento de polígonos, 
  representado pelo vetor tux[]. 
  Em seguida, o par glBegin()/glEnd() desenha o último polígono, preenchindo com o padrão "tux". */
  glPolygonStipple(tux);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
 /*
    A função glFlush() faz com que qualquer comando OpenGL ainda não executado 
    seja executado o mais rapido possível pelo mecanismo de exibicao.
 */
  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

/*
A funcao de tratamento de eventos de mouse verifica se teve algum clique.  
Se o botao esquerdo (GLUT_LEFT_BUTTON) for pressionado (GLUT_DOWN), 
serao gerados tres valores aleatorios para as variaveis r, g e b, na faixa [0,1]. 
Quando a funcao glutPostRedisplay() é executada, a funcao display é chamada novamente, 
fazendo com que a janela corrente seja redesenhada e o polígono no canto superior esquerdo dessa janela mude de cor.
*/

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
	if (state == GLUT_DOWN) {
	  r=(GLfloat)rand()/(RAND_MAX+1.0);
	  g=(GLfloat)rand()/(RAND_MAX+1.0);
	  b=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	}
	break;
  }
}