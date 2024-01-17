#include <stdio.h>
#include <Windows.h>
#include "GL\glut.h"
#include "Mesh.h"
#include <math.h>
#include "Bitmap.h"
#include "stb_image.h"
#include "mmsystem.h"
#include "mmsystem.h"

#pragma comment(lib,"winmm")
#define USE_MIPMAP

float _zoom = 15.0f;
float _rotate_x = 0.0f;
float _rotate_y = 0.001f;
float _translate_x = 0.0f;
float _translate_y = 0.0f;
int last_x = 0;
int last_y = 0;


unsigned char _btnStates[3] = { 0 };

float theta = 0;
float R_theta = 360;

int xa = 0;

Mesh *_mesh[15];
Mesh* _mesh2;
Mesh* _mesh3[15];
Mesh* _mesh4;
Mesh* _mesh5;
Mesh* _mesh6;

GLuint _textureIndex_b = 1;

Bitmap texture;
Bitmap texture_2;

int j = 0;
bool _smoothing = false; 
bool _Magic = false;
bool _Friend = false;


float cos_th;
float sin_th;

float cos_th2;
float sin_th2;

float cos_th3;
float sin_th3;

float cos_th4;
float sin_th4;

float cos_th5;
float sin_th5;

void init(void)
{

	PlaySound(TEXT("BGM.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	//닥터스트레인지 마법 영창
	{
		_mesh[0] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000001.obj", "obj\\Strangepic.png");
		_mesh[1] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000002.obj", "obj\\Strangepic.png");
		_mesh[2] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000003.obj", "obj\\Strangepic.png");
		_mesh[3] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000004.obj", "obj\\Strangepic.png");
		_mesh[4] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000005.obj", "obj\\Strangepic.png");
		_mesh[5] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000006.obj", "obj\\Strangepic.png");
		_mesh[6] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000007.obj", "obj\\Strangepic.png");
		_mesh[7] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000008.obj", "obj\\Strangepic.png");
		_mesh[8] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000009.obj", "obj\\Strangepic.png");
		_mesh[9] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000010.obj", "obj\\Strangepic.png");
		_mesh[10] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000011.obj", "obj\\Strangepic.png");
		_mesh[11] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000012.obj", "obj\\Strangepic.png");
		_mesh[12] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000013.obj", "obj\\Strangepic.png");
		_mesh[13] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000014.obj", "obj\\Strangepic.png");
		_mesh[14] = new Mesh("obj\\Doctor_MAGIC_Animation\\Doctor_Strange_Magic_000015.obj", "obj\\Strangepic.png");





	}


	//_mesh2 = new Mesh("obj\\Ironman.obj", "obj\\ironman_d.jpg");
	//_mesh3 = new Mesh("obj\\Beretta_M9.obj", "obj\\beretta_m9_brandon.png");
	_mesh2 = new Mesh("obj\\Magic_board_3.obj", "obj\\H_RUNE.png");
	//타노스 주먹질
	{
		_mesh3[0] = new Mesh("obj\\Thanos_animation\\Thanos_000001.obj", "obj\\Thanos_texture.bmp");
		_mesh3[1] = new Mesh("obj\\Thanos_animation\\Thanos_000002.obj", "obj\\Thanos_texture.bmp");
		_mesh3[2] = new Mesh("obj\\Thanos_animation\\Thanos_000003.obj", "obj\\Thanos_texture.bmp");
		_mesh3[3] = new Mesh("obj\\Thanos_animation\\Thanos_000004.obj", "obj\\Thanos_texture.bmp");
		_mesh3[4] = new Mesh("obj\\Thanos_animation\\Thanos_000005.obj", "obj\\Thanos_texture.bmp");
		_mesh3[5] = new Mesh("obj\\Thanos_animation\\Thanos_000006.obj", "obj\\Thanos_texture.bmp");
		_mesh3[6] = new Mesh("obj\\Thanos_animation\\Thanos_000007.obj", "obj\\Thanos_texture.bmp");
		_mesh3[7] = new Mesh("obj\\Thanos_animation\\Thanos_000008.obj", "obj\\Thanos_texture.bmp");
		_mesh3[8] = new Mesh("obj\\Thanos_animation\\Thanos_000009.obj", "obj\\Thanos_texture.bmp");
		_mesh3[9] = new Mesh("obj\\Thanos_animation\\Thanos_000010.obj", "obj\\Thanos_texture.bmp");
		_mesh3[10] = new Mesh("obj\\Thanos_animation\\Thanos_000011.obj", "obj\\Thanos_texture.bmp");
		_mesh3[11] = new Mesh("obj\\Thanos_animation\\Thanos_000012.obj", "obj\\Thanos_texture.bmp");
		_mesh3[12] = new Mesh("obj\\Thanos_animation\\Thanos_000013.obj", "obj\\Thanos_texture.bmp");
		_mesh3[13] = new Mesh("obj\\Thanos_animation\\Thanos_000014.obj", "obj\\Thanos_texture.bmp");
		_mesh3[14] = new Mesh("obj\\Thanos_animation\\Thanos_000015.obj", "obj\\Thanos_texture.bmp");
	}
	




	_mesh5 = new Mesh("obj\\Ironman_pose.obj", "obj\\ironman_d.jpg");
	
	_mesh6 = new Mesh("obj\\Spiderman.obj", "obj\\SpiderMan_Tex01_BM.360.jpg");

	_mesh4 = new Mesh("obj\\Magic_board_3.obj", "obj\\H_RUNE.png");

	
	

	glEnable(GL_DEPTH_TEST);
}

void Init2(char *filename){
	//texture[1].open(filename);
	

	//외부로 빼서 해야함
	Bitmap texture;
	texture.open(filename);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.getWidth(), texture.getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture._image);

#ifdef USE_MIPMAP
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.getWidth(), texture.getHeight(), GL_BGR_EXT, GL_UNSIGNED_BYTE, texture._image);
#endif

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

#ifdef USE_MIPMAP
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
#endif
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);	//GL_DECAL, GL_REPLACE, GL_MODULATE

#ifdef USE_MIPMAP
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	// GL_REPEAT
#endif

	glColor3f(1.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 0.1, 100);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Init3(char* filename) {
	//texture[1].open(filename);


	//외부로 빼서 해야함
	Bitmap texture;
	texture.open(filename);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.getWidth(), texture.getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture._image);

#ifdef USE_MIPMAP
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.getWidth(), texture.getHeight(), GL_BGR_EXT, GL_UNSIGNED_BYTE, texture._image);
#endif

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

#ifdef USE_MIPMAP
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
#endif
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);	//GL_DECAL, GL_REPLACE, GL_MODULATE

#ifdef USE_MIPMAP
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// GL_REPEAT
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	// GL_REPEAT
#endif

	glColor3f(1.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 0.1, 100);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void texture_draw(){

	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-40.0f, -6.0f, 40.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-40.0f, -6.0f, -40.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(40.0f, -6.0f, -40.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(40.0f, -6.0f, 40.0f);
	glEnd();

}

void texture_draw2() {


	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-40.0f, -6.0f, -40.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-40.0f, 40.0f, -40.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(40.0f, 40.0f, -40.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(40.0f, -6.0f, -40.0f);
	glEnd();

}


void texture_draw3() {


	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-40.0f, -6.0f, 40.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-40.0f, 40.0f, 40.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(40.0f, 40.0f, 40.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(40.0f, -6.0f, 40.0f);
	glEnd();

}

void texture_draw4() {


	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(40.0f, -6.0f, 40.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(40.0f, 40.0f, 40.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(40.0f, 40.0f, -40.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(40.0f, -6.0f, -40.0f);
	glEnd();

}

void texture_draw5() {


	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-40.0f, -6.0f, 40.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-40.0f, 40.0f, 40.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-40.0f, 40.0f, -40.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-40.0f, -6.0f, -40.0f);
	glEnd();

}


void timer(int value)
{

	theta = theta + 2.0;
	R_theta -= 2.0;
	//printf("%f \n", theta);

	if (theta >= 360.0) {
		theta -= 360.0;
		//printf("%f \n", &theta);
	}

	if (R_theta <= 0) {
		R_theta += 360.0;
		//printf("%f \n", &theta);
	}

	/*if (j == 0) {
		j++;
	}*/

	
	

	glutPostRedisplay();
	glutTimerFunc(10, timer, 1);

	



}

void lighting(void) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	/*GLfloat pos0[4] = { 2.0f, 2.0f, 2.0f , 1.0f };
	GLfloat ambient0[4] = { 0.1, 0.1, 0.1,1.0 };
	GLfloat diffuse[4] = { 1.0, 1.0, 0.0,1.0 };
	GLfloat specular[4] = { 1.0, 1.0, 1.0,1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	
	
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05);

	GLfloat spot_direction[3] = { -1.0, -1.0, -1.0 };
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 15.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 100.0);

	GLfloat pos1[4] = { -2.0, 2.0, -2.0 , 1.0 };
	GLfloat ambient1[4] = { 0.1, 0.1, 0.1,1.0 };
	GLfloat diffuse1[4] = { 1.0, 1.0, 1.0,1.0 };
	GLfloat specular1[4] = { 1.0, 1.0, 1.0,1.0 };

	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	glEnable(GL_LIGHT1);

	GLfloat mat_ambient[4] = { 0.3, 0.0, 0.0,1.0 };
	GLfloat mat_diffuse[4] = { 0.6, 0.0, 0.0,1.0 };
	GLfloat mat_specular[4] = { 0.8, 0.6, 0.6,1.0 };
	GLfloat mat_shininess = 32.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);*/

}


void drawMagic(void) {

	cos_th = cos((theta) * 3.14159 / 180.0);
	sin_th = sin((theta) * 3.14159 / 180.0);

	cos_th2 = cos((theta + 60.0) * 3.14159 / 180.0);
	sin_th2 = sin((theta + 60.0) * 3.14159 / 180.0);

	cos_th3 = cos((theta + 30.0) * 3.14159 / 180.0);
	sin_th3 = sin((theta + 30.0) * 3.14159 / 180.0);

	cos_th4 = cos((R_theta + 45.0) * 3.14159 / 180.0);
	sin_th4 = sin((R_theta + 45.0) * 3.14159 / 180.0);

	cos_th5 = cos((R_theta) * 3.14159 / 180.0);
	sin_th5 = sin((R_theta) * 3.14159 / 180.0);


	//Square
	{ 
		//Triangle
		{
			//Triangle_1
			{
					double rad = 0.5;
					glLineWidth(3);
					glBegin(GL_LINE_STRIP);
					glColor3d(1, 0.54902, 0);
					
					for (int i = 0; i < 361; i++)
					{
						if (i % 120 == 0) {
							double angle, x, y;
							angle = i * 3.141592 / 180;
							x = rad * cos(angle);
							y = rad * sin(angle);
							glVertex3f(x, y + 3, 2);
						}
						
					}
					glEnd();
			}

			//Triangle_2
			{
				double rad = 0.5;
				glBegin(GL_LINE_STRIP);
				for (int i = 0; i < 361; i++)
				{
					if (i % 120 == 0) {
						double angle, x, y;
						angle = i * 3.141592 / 180;
						x = rad * cos(angle);
						y = rad * sin(angle);
						glVertex3f(-x, -y + 3, 2);
					}

				}
				glEnd();
			}




		}
		//Square_1
		{
			glBegin(GL_LINES);
			glColor3d(1, 0.54902, 0);
			glVertex3f(cos_th, sin_th + 3.0, 2);
			glVertex3f(-sin_th, cos_th + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-sin_th, cos_th + 3.0, 2);
			glVertex3f(-cos_th, -sin_th + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-cos_th, -sin_th + 3.0, 2);
			glVertex3f(sin_th, -cos_th + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(sin_th, -cos_th + 3.0, 2);
			glVertex3f(cos_th, sin_th + 3.0, 2);
			glEnd();
		}
		//Square_2
		{
			glBegin(GL_LINES);
			glColor3d(1, 0.54902, 0);
			glVertex3f(cos_th2, sin_th2 + 3.0, 2);
			glVertex3f(-sin_th2, cos_th2 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-sin_th2, cos_th2 + 3.0, 2);
			glVertex3f(-cos_th2, -sin_th2 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-cos_th2, -sin_th2 + 3.0, 2);
			glVertex3f(sin_th2, -cos_th2 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(sin_th2, -cos_th2 + 3.0, 2);
			glVertex3f(cos_th2, sin_th2 + 3.0, 2);
			glEnd();
		}
		//Square_3
		{
			glBegin(GL_LINES);
			glColor3d(1, 0.54902, 0);
			glVertex3f(cos_th3, sin_th3 + 3.0, 2);
			glVertex3f(-sin_th3, cos_th3 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-sin_th3, cos_th3 + 3.0, 2);
			glVertex3f(-cos_th3, -sin_th3 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-cos_th3, -sin_th3 + 3.0, 2);
			glVertex3f(sin_th3, -cos_th3 + 3.0, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(sin_th3, -cos_th3 + 3.0, 2);
			glVertex3f(cos_th3, sin_th3 + 3.0, 2);
			glEnd();
		}

	}
	//Circle
	{
		//Circle_small
		{
			double rad = 0.5;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}
		
		//Circle_Middle
		{
			double rad = 1;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}

		//Circle_Big_Big
		{
			double rad = 1.6;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}

		//Circle_Big_Big_BIG
		{
			double rad = 2.1;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}

		{
			/*double rad = 2.0;
			glBegin(GL_POLYGON);
			for (int i = 0; i < 361; i++)
			{
				double angle = i * 3.141592 / 180;
				double x = rad * cos(angle);
				double y = rad * sin(angle);
				glVertex3f(x, y + 3, 1.8);
			}
			glEnd();*/

		}
			
		

		//Circle_Big
		{
			double rad = 1.5;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}

		//Circle__small_Big
		{
			double rad = 0.6;
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < 361; i++)
			{
				double angle, x, y;
				angle = i * 3.141592 / 180;
				x = rad * cos(angle);
				y = rad * sin(angle);
				glVertex3f(x, y + 3, 2);
			}
			glEnd();

		}

		//Square_middle
		{

			glBegin(GL_LINES);
			glColor3d(1, 0.54902, 0);
			glVertex3f(cos_th5 * 1.5, (sin_th5 + 2.0)*1.5, 2);
			glVertex3f(-sin_th5 * 1.5, (cos_th5 + 2.0) * 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-sin_th5 * 1.5, (cos_th5 + 2.0)*1.5, 2);
			glVertex3f(-cos_th5 * 1.5, (-sin_th5 + 2.0)* 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-cos_th5 * 1.5, (-sin_th5 + 2.0)* 1.5, 2);
			glVertex3f(sin_th5 * 1.5, (-cos_th5 + 2.0)* 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(sin_th5 * 1.5, (-cos_th5 + 2.0)* 1.5, 2);
			glVertex3f(cos_th5 * 1.5, (sin_th5 + 2.0)* 1.5, 2);
			glEnd();

		}
		//Square_middle_2
		{

			glBegin(GL_LINES);
			glColor3d(1, 0.54902, 0);
			glVertex3f(cos_th4 * 1.5, (sin_th4 + 2.0) * 1.5, 2);
			glVertex3f(-sin_th4 * 1.5, (cos_th4 + 2.0) * 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-sin_th4 * 1.5, (cos_th4 + 2.0) * 1.5, 2);
			glVertex3f(-cos_th4 * 1.5, (-sin_th4 + 2.0) * 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-cos_th4 * 1.5, (-sin_th4 + 2.0) * 1.5, 2);
			glVertex3f(sin_th4 * 1.5, (-cos_th4 + 2.0) * 1.5, 2);
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(sin_th4 * 1.5, (-cos_th4 + 2.0) * 1.5, 2);
			glVertex3f(cos_th4 * 1.5, (sin_th4 + 2.0) * 1.5, 2);
			glEnd();

		}
		

	}
	glFinish();
	
}

void draw(void)
{	
	
	Init2("Floor.bmp");
	texture_draw();
	
	//glutSwapBuffers();
	Init2("MAP.bmp");
	texture_draw2();
	texture_draw3();
	texture_draw4();
	texture_draw5();

	//Init2("MAP.bmp");
	



	


	
	//_mesh->loadTexture("obj\\Strangepic.png", _mesh->_textureIndex);

	if (_Magic == true) {
		{
			glPushMatrix();
			_mesh[j]->drawSolid(_smoothing);
			glPopMatrix();
		}

		_mesh2->drawSolid2(_smoothing);

	}
	

	
	//glTranslatef(0, 0, 10);

	//for (int i = 0; i < 15; i++) {
	glPushMatrix();
	_mesh3[j]->drawSolid3(_smoothing);
	glPopMatrix();
	//}
	
		
	




	if (_Friend == true) {
		_mesh5->drawSolid4(_smoothing);

		_mesh6->drawSolid5(_smoothing);
	}
	
	



	_mesh4->drawSolid6(_smoothing);


	//Init2("ironman_d.jpg");
	if (_Magic == true) {
		drawMagic();

	}
	

	lighting();
	//glPopMatrix();
	//_mesh->drawWire();
	//_mesh->drawPoint();

	
	

	
	//_mesh2->drawSolid2(_smoothing);
	
	//_mesh3->drawSolid2(_smoothing);
	
	
	
	

	
	glutTimerFunc(10, timer, 1);
	glDisable(GL_LIGHTING);
}

void Idle(void) {
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


void GL_Display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -_zoom); 
	glTranslatef(_translate_x, _translate_y, 0.0);
	//glPushMatrix();
	glRotatef(_rotate_x, 1, 0, 0);
	glRotatef(_rotate_y, 0, 1, 0);

	//_mesh3->_thanos_angle += 2;
	
	draw();
	
	glutSwapBuffers();
}

void GL_Reshape(int w, int h)
{
	//glMatrixMode(GL_MODELVIEW);
	if (w == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void GL_Motion(int x, int y)
{
	int diff_x = x - last_x;
	int diff_y = y - last_y;

	last_x = x;
	last_y = y;

	if (_btnStates[2]) {
		_zoom -= (float) 0.05f * diff_x;
	}
	else if (_btnStates[0]) {
		_rotate_x += (float)0.5f * diff_y;
		_rotate_y += (float)0.5f * diff_x;
	}
	else if (_btnStates[1]) {
		_translate_x += (float)0.05f * diff_x;
		_translate_y -= (float)0.05f * diff_y;
	}
	glutPostRedisplay();
}

void GL_Mouse(int button, int state, int x, int y)
{
	last_x = x;
	last_y = y;
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		_btnStates[0] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	case GLUT_MIDDLE_BUTTON:
		_btnStates[1] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	case GLUT_RIGHT_BUTTON:
		_btnStates[2] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void GL_Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'Q':
	case 'q':
		exit(0);
	case 'S':
	case 's':
		_smoothing = !_smoothing;
		break;
	case 'A':
	case 'a':
		_Magic = !_Magic;
		break;
	case 'Z':
	case 'z':
		_Friend = !_Friend;
		break;

	case 'C':
	case 'c':
		if (j == 14) {
			j = 0;
		}
		j++;
		break;
	case 'X':
	case 'x':
		if (j == 0) {
			j = 14;
		}
		j--;
		break;

	case 'V':
	case 'v':
		if (xa == 0) {
			
			j++;
		}
		if (xa == 1) {

			j--;
		}

		if (j >= 14) {
			xa =1;
		}

		if (j <= 0) {
			xa = 0;
		}
		break;

		
	default:
		break;

	}
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Camera Nevigation");

	glutReshapeFunc(GL_Reshape);
	glutMouseFunc(GL_Mouse);
	glutMotionFunc(GL_Motion);
	glutKeyboardFunc(GL_Keyboard);
	
	init();
	glutDisplayFunc(GL_Display);

	glutIdleFunc(Idle);

	



	
	
	//glutSwapBuffers();
	glutTimerFunc(10, timer, 1);

	
	
	
	

	glutMainLoop();
}