#include "glut.h"
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define	PI 3.141593

void colocaBackground();
void retangulo_bandeira();
void losango_bandeira();
void circulo_bandeira();

void Desenha() {
	glClear(GL_COLOR_BUFFER_BIT);
	retangulo_bandeira();
	losango_bandeira();
	circulo_bandeira();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Bandeira do Brasil");
	colocaBackground();
	glutDisplayFunc(Desenha);
	glutMainLoop();
	return 0;
}

void colocaBackground() { //pinta o fundo de preto 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void retangulo_bandeira() { //retangulo traseiro da bandeira
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2f(-1.0, 0.5);
	glVertex2f(-1.0, -0.5);
	glVertex2f(1.0, -0.5);
	glVertex2f(1.0, 0.5);
	glEnd();

}

void losango_bandeira() { // losango interno no medio plano
	glColor3f(1.0, 1.0, 0.0);
	
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.40);
	glVertex2f(-0.75, 0.0);
	glVertex2f(0.0, -0.40);
	glVertex2f(0.75, 0.0);
	glEnd();

}

void circulo_bandeira() { // bola azul 
	float raio, inicialX, inicialY, ang;
	float x, y;

	inicialX = 0.0;
	inicialY = 0.0;
	raio = 0.25;

	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ang = (i * PI) / 180.0;
		x = inicialX + (cos(ang) * raio);
		y = inicialY + (sin(ang) * raio);
		glVertex2f(x, y);
	}
	glEnd();
}

