// **********************************************************************
//	FirstTexture.cpp   --   Exemplo de mapeamento de texturas.
//		
//		Este programa foi criado a partir de um fonte obtido em 
//	http://nehe.gamedev.net, na "Lesson 06"
//
//		
//
//
//
// **********************************************************************

#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include  "glut.h"


#include "JpegLib\jpegfile.h"

// Qtd máxima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 1

#define CUBE_TEXTURE 0

// vetor com os números das texturas
GLuint texture_id[MAX_NO_TEXTURES];

float xrot;
float yrot;
float zrot;
float ratio;


void DefineLuz(void)
{
  GLfloat LuzAmbiente[]   = {0.5f, 0.5f, 0.5f, 1.0f } ;
  GLfloat LuzDifusa[]   = {0.4f, 0.4f, 0.4f, 1.0f };
  GLfloat LuzEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat PosicaoLuz[]  = {0.0f, 5.0f, 0.0f, 1.0f };
  GLfloat Especularidade[] = {1.0f, 1.0f, 1.0f, 1.0f };

   // Habilita o uso de iluminação
  glEnable(GL_LIGHTING);

  // Ativa o uso da luz ambiente
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente);
  // Define os parametros da Luz número Zero
  glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusa  );
  glLightfv(GL_LIGHT0, GL_SPECULAR, LuzEspecular  );
  glLightfv(GL_LIGHT0, GL_POSITION, PosicaoLuz );
  glEnable(GL_LIGHT0);

  // Ativa o "Color Tracking"
  glEnable(GL_COLOR_MATERIAL);

  // Define a reflectancia do material
  glMaterialfv(GL_FRONT,GL_SPECULAR, Especularidade);

  // Define a concentração do brilho.
  // Quanto maior o valor do Segundo parametro, mais
  // concentrado será o brilho. (Valores válidos: de 0 a 128)
  glMateriali(GL_FRONT,GL_SHININESS,20);

}

// **********************************************************************
//  void initTexture(void)
//		Define a textura a ser usada 
//
// **********************************************************************
void initTexture (void)
{

	// Habilita o uso de textura 
	glEnable ( GL_TEXTURE_2D );

	// Define a forma de armazenamento dos pixels na textura (1= alihamento por byte)
	glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

	// Define quantas texturas serão usadas no programa 
	glGenTextures (1, texture_id);  // 1 = uma textura;
									// texture_id = vetor que guardas os números das texturas

	// Define o número da textura do cubo.
	texture_id[CUBE_TEXTURE] = 1001;

	// Define que tipo de textura será usada
	// GL_TEXTURE_2D ==> define que será usada uma textura 2D (bitmaps)
	// texture_id[CUBE_TEXTURE]  ==> define o número da textura 
	glBindTexture ( GL_TEXTURE_2D, texture_id[CUBE_TEXTURE] );

	// carrega a uma imagem TGA 
	//image_t temp_image;

	//tgaLoad  ( "TCG1.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );
	
	unsigned int larg, alt;
	char TextureFile[] = "Texture.jpg";
	BYTE *img = JPEGLoad(TextureFile, &larg, &alt);

	if (img)
		gluBuild2DMipmaps (GL_TEXTURE_2D, 3, larg, alt, GL_BGR_EXT, GL_UNSIGNED_BYTE, img);
	else printf("Unable to open file '%s'",TextureFile); 
}
// **********************************************************************
//  void init(void)
//		Inicializa os parâmetros globais de OpenGL
//
// **********************************************************************
void init(void)
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
	
	//glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	
	glEnable(GL_DEPTH_TEST); // habilita ZBuffer

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 


	
}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape( int w, int h )
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(80,ratio,1,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 30,
		      0,0,10,
			  0.0f,1.0f,0.0f);

}
void DrawCube()
{

	glBegin ( GL_QUADS );
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();

}
// **********************************************************************
//  void display( void )
//
//
// **********************************************************************
void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	DefineLuz();
	glLoadIdentity ( );
	glPushMatrix();
	glTranslatef ( 0.0, 0.0, -5.0 );
	glRotatef ( xrot, 1.0, 0.0, 0.0 );
	glRotatef ( yrot, 0.0, 1.0, 0.0 );
	glRotatef ( zrot, 0.0, 0.0, 1.0 );

	// define qual das texturas usar
	glBindTexture ( GL_TEXTURE_2D, texture_id[CUBE_TEXTURE] );
	
      glEnable(GL_CULL_FACE);
      glCullFace(GL_FRONT);
      DrawCube();
      glCullFace(GL_BACK);
      DrawCube();
      glDisable(GL_CULL_FACE);


//    DrawCube();
	
	glPopMatrix();
	xrot+=0.3f;
	yrot+=0.2f;
	zrot+=0.4f;
	glutSwapBuffers();
}

// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )  
{
	switch ( key ) 
	{
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
    default:        // Now Wrap It Up
      break;
  }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )  
//
//
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )  
{
	switch ( a_keys ) 
	{
		case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
			glutFullScreen ( ); // Go Into Full Screen Mode
			break;
	    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
			glutInitWindowSize  ( 700, 500 ); 
			break;
		default:
			break;
	}
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
void main ( int argc, char** argv )   
{
	glutInit            ( &argc, argv ); 
	glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); 
	glutInitWindowPosition (0,0);
	glutInitWindowSize  ( 700, 500 ); 
	glutCreateWindow    ( "Tópicos em Computação Gráfica - Teste com Texturas." ); 
		
	init ();
	initTexture ();
		
	glutDisplayFunc ( display );  
	glutReshapeFunc ( reshape );
	glutKeyboardFunc ( keyboard );
	glutSpecialFunc ( arrow_keys );
	glutIdleFunc ( display );
	glutMainLoop ( );          
}




