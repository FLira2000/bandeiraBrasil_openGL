#include "glut.h"
#include <math.h>

#define	PI 3.141593

using namespace std;

void init(void) { //pinta o fundo de preto 
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
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_LINE_LOOP);
	for (double i = 0; i < 2 * PI; i += PI / 6)
		glVertex3f(cos(i) * 64, sin(i) * 64, 0.0);
	glEnd();
}

void Desenha() {
	glClear(GL_COLOR_BUFFER_BIT);
	retangulo_bandeira();
	losango_bandeira();
	circulo_bandeira();
	glFlush();
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Bandeira do Brasil");
	glutDisplayFunc(Desenha);
	init();
	glutMainLoop();
	return 0;
}