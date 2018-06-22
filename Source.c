#include <stdlib.h>
#include <glut.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>



GLint Width = 512, Height = 512;


int figure_cod;
int MY_DESK[8][8] = { { 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 } };

int how_many_peshka = 0;   // черные фигуры
int how_many_ferz = 0;
int how_many_kon = 0;
int how_many_slon = 0;
int how_many_ladia = 0;
int how_many_king = 0;

int how_many_peshka1 = 0;  // белые
int how_many_ferz1 = 0;
int how_many_kon1 = 0;
int how_many_slon1 = 0;
int how_many_ladia1 = 0;
int how_many_king1 = 0;

int i, j, k, l;
int flag = 0;
int *A;
int *B;
int K = 0;

void Desk(void);
void Peshka(int x, int y, int R, int G, int B);
void Ladia(int x, int y, int R, int G, int B);
void Ferz(int x, int y, int R, int G, int B);
void Kon(int x, int y, int R, int G, int B);
void Slon(int x, int y, int R, int G, int B);
void King(int x, int y, int R, int G, int B);
void Change(void);
int Proverka(int *A, int *B, int figure_cod);




void Desk(void)
{
	int i, j;
	int CubeSize = 40;                                             //размер квадратов
	int left = ((Width - 8 * CubeSize) / 2) - 80;          // располжение поля
	int right = left + CubeSize;  // располжение поля			
	int bottom = (Height - 8 * CubeSize) / 2;				// располжение поля	
	int top = bottom + CubeSize;					// располжение поля

	glColor3ub(255, 222, 173);                                     // цвет светлых тонов квадрата
	glBegin(GL_QUADS);				//примитив для создания доски (т.е. разрисовка доски)
	glVertex2f(left, bottom);                  // объявление вершин доски
	glVertex2f(left, bottom + 320);
	glVertex2f(left + 320, bottom + 320);
	glVertex2f(left + 320, bottom);
	glEnd();

	//Обводим контур доски
	glColor3ub(160, 82, 45);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(left, bottom);
	glVertex2f(left, bottom + 320);
	glVertex2f(left, bottom + 320);
	glVertex2f(left + 320, bottom + 320);
	glVertex2f(left + 320, bottom + 320);
	glVertex2f(left + 320, bottom);
	glVertex2f(left + 320, bottom);
	glVertex2f(left, bottom);
	glEnd();

	//Рисуем клетки
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			glColor3ub(160, 82, 45); // цвет темных тонов квадрата
			glBegin(GL_QUADS); // построение самой доски
			glVertex2f(left + 80 * i, bottom + 80 * j);
			glVertex2f(left + 80 * i, top + 80 * j);
			glVertex2f(right + 80 * i, top + 80 * j);
			glVertex2f(right + 80 * i, bottom + 80 * j);
			glEnd();

			glBegin(GL_QUADS);
			glVertex2f(left + 40 + 80 * i, bottom + 40 + 80 * j);
			glVertex2f(left + 40 + 80 * i, top + 40 + 80 * j);
			glVertex2f(right + 40 + 80 * i, top + 40 + 80 * j);
			glVertex2f(right + +40 + 80 * i, bottom + 40 + 80 * j);
			glEnd();
		}
	}

}
void Peshka(int x, int y, int R, int G, int B)
{
	glColor3ub(R, G, B); // задаем цвета фигуре	
	glBegin(GL_POLYGON); //рисуем фигуру
	glVertex2f(x, y);
	glVertex2f(5 + x, 5 + y);
	glVertex2f(10 + x, 5 + y);
	glVertex2f(15 + x, 0 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 5 + y);
	glVertex2f(5 + x, 8 + y);
	glVertex2f(9 + x, 8 + y);
	glVertex2f(9 + x, 5 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(4 + x, 8 + y);
	glVertex2f(2 + x, 12 + y);
	glVertex2f(4 + x, 15 + y);
	glVertex2f(7 + x, 16 + y);
	glVertex2f(10 + x, 15 + y);
	glVertex2f(12 + x, 12 + y);
	glVertex2f(10 + x, 8 + y);
	glEnd();

	if (G == 255) // обводим контур фигуры
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(5 + x, 8 + y);
		glVertex2f(10 + x, 8 + y);
		glVertex2f(10 + x, 5 + y);
		glVertex2f(9 + x, 5 + y);
		glVertex2f(14 + x, 0 + y);
		glVertex2f(x, y);
		glVertex2f(14 + x, 0 + y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(10 + x, 5 + y);
		glVertex2f(4 + x, 8 + y);
		glVertex2f(2 + x, 12 + y);
		glVertex2f(2 + x, 12 + y);
		glVertex2f(4 + x, 15 + y);
		glVertex2f(4 + x, 15 + y);
		glVertex2f(7 + x, 16 + y);
		glVertex2f(7 + x, 16 + y);
		glVertex2f(10 + x, 15 + y);
		glVertex2f(10 + x, 15 + y);
		glVertex2f(12 + x, 12 + y);
		glVertex2f(12 + x, 12 + y);
		glVertex2f(10 + x, 8 + y);
		glEnd();
	}

}
void Ladia(int x, int y, int R, int G, int B)
{

	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	glVertex2f(2 + x, y);
	glVertex2f(5 + x, 5 + y);
	glVertex2f(15 + x, 5 + y);
	glVertex2f(18 + x, 0 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 5 + y);
	glVertex2f(5 + x, 11 + y);
	glVertex2f(14 + x, 11 + y);
	glVertex2f(14 + x, 5 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(3 + x, 11 + y);
	glVertex2f(3 + x, 15 + y);
	glVertex2f(16 + x, 15 + y);
	glVertex2f(16 + x, 11 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(3 + x, 15 + y);
	glVertex2f(3 + x, 18 + y);
	glVertex2f(6 + x, 18 + y);
	glVertex2f(6 + x, 15 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + 3 + x, 15 + y);
	glVertex2f(5 + 3 + x, 18 + y);
	glVertex2f(5 + 6 + x, 18 + y);
	glVertex2f(5 + 6 + x, 15 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(10 + 3 + x, 15 + y);
	glVertex2f(10 + 3 + x, 18 + y);
	glVertex2f(10 + 6 + x, 18 + y);
	glVertex2f(10 + 6 + x, 15 + y);
	glEnd();


	if (G == 255)
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(2 + x, y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(14 + x, 5 + y);
		glVertex2f(14 + x, 5 + y);
		glVertex2f(18 + x, 0 + y);
		glVertex2f(2 + x, y);
		glVertex2f(18 + x, 0 + y);
		glVertex2f(5 + x, 5 + y);
		glVertex2f(5 + x, 11 + y);
		glVertex2f(15 + x, 11 + y);
		glVertex2f(15 + x, 5 + y);
		glVertex2f(3 + x, 11 + y);
		glVertex2f(3 + x, 18 + y);
		glVertex2f(17 + x, 11 + y);
		glVertex2f(3 + x, 11 + y);
		glVertex2f(17 + x, 18 + y);
		glVertex2f(17 + x, 11 + y);
		glVertex2f(3 + x, 18 + y);
		glVertex2f(6 + x, 18 + y);
		glVertex2f(6 + x, 18 + y);
		glVertex2f(6 + x, 15 + y);
		glVertex2f(6 + x, 15 + y);
		glVertex2f(8 + x, 15 + y);
		glVertex2f(5 + 3 + x, 15 + y);
		glVertex2f(5 + 3 + x, 18 + y);
		glVertex2f(5 + 3 + x, 18 + y);
		glVertex2f(5 + 6 + x, 18 + y);
		glVertex2f(5 + 6 + x, 18 + y);
		glVertex2f(5 + 6 + x, 15 + y);
		glVertex2f(5 + 6 + x, 15 + y);
		glVertex2f(5 + 8 + x, 15 + y);
		glVertex2f(10 + 3 + x, 15 + y);
		glVertex2f(10 + 3 + x, 18 + y);
		glVertex2f(10 + 3 + x, 18 + y);
		glVertex2f(10 + 6 + x, 18 + y);
		glEnd();
	}


}
void Slon(int x, int y, int R, int G, int B)
{
	glColor3ub(R, G, B);
	glBegin(GL_TRIANGLES);
	glVertex2f(x + 2, y);
	glVertex2f(7 + x, 20 + y);
	glVertex2f(12 + x, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(3 + x, 15 + y);
	glVertex2f(3 + x, 17 + y);
	glVertex2f(11 + x, 17 + y);
	glVertex2f(11 + x, 15 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 17 + y);
	glVertex2f(3 + x, 20 + y);
	glVertex2f(3 + x, 23 + y);
	glVertex2f(5 + x, 26 + y);
	glVertex2f(7 + x, 27 + y);
	glVertex2f(9 + x, 26 + y);
	glVertex2f(11 + x, 23 + y);
	glVertex2f(11 + x, 20 + y);
	glVertex2f(9 + x, 17 + y);
	glEnd();

	if (G == 255)
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(x + 2, y);
		glVertex2f(6 + x, 15 + y);
		glVertex2f(8 + x, 15 + y);
		glVertex2f(12 + x, y);
		glVertex2f(12 + x, y);
		glVertex2f(x + 2, y);

		glVertex2f(3 + x, 15 + y);
		glVertex2f(3 + x, 17 + y);
		glVertex2f(3 + x, 17 + y);
		glVertex2f(11 + x, 17 + y);
		glVertex2f(11 + x, 17 + y);
		glVertex2f(11 + x, 15 + y);
		glVertex2f(11 + x, 15 + y);
		glVertex2f(3 + x, 15 + y);

		glVertex2f(5 + x, 17 + y);
		glVertex2f(3 + x, 20 + y);
		glVertex2f(3 + x, 20 + y);
		glVertex2f(3 + x, 23 + y);
		glVertex2f(3 + x, 23 + y);
		glVertex2f(5 + x, 25 + y);
		glVertex2f(5 + x, 25 + y);
		glVertex2f(7 + x, 27 + y);
		glVertex2f(7 + x, 27 + y);
		glVertex2f(9 + x, 25 + y);
		glVertex2f(9 + x, 25 + y);
		glVertex2f(11 + x, 23 + y);
		glVertex2f(11 + x, 23 + y);
		glVertex2f(11 + x, 20 + y);
		glVertex2f(11 + x, 20 + y);
		glVertex2f(9 + x, 17 + y);

		glEnd();
	}




}
void Ferz(int x, int y, int R, int G, int B)
{
	glColor3ub(R, G, B);
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(7 + x, 18 + y);
	glVertex2f(14 + x, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1 + x, 15 + y);
	glVertex2f(1 + x, 18 + y);
	glVertex2f(13 + x, 18 + y);
	glVertex2f(13 + x, 15 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 18 + y);
	glVertex2f(1 + x, 25 + y);
	glVertex2f(13 + x, 25 + y);
	glVertex2f(9 + x, 18 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 26 + y);
	glVertex2f(4 + x, 28 + y);
	glVertex2f(5 + x, 30 + y);
	glVertex2f(7 + x, 31 + y);
	glVertex2f(9 + x, 30 + y);
	glVertex2f(10 + x, 28 + y);
	glVertex2f(9 + x, 26 + y);
	glEnd();


	if (G == 255)
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(6 + x, 16 + y);
		glVertex2f(8 + x, 16 + y);
		glVertex2f(14 + x, y);
		glVertex2f(x, y);
		glVertex2f(14 + x, y);

		glVertex2f(1 + x, 15 + y);
		glVertex2f(1 + x, 18 + y);
		glVertex2f(1 + x, 18 + y);
		glVertex2f(13 + x, 18 + y);
		glVertex2f(13 + x, 18 + y);
		glVertex2f(13 + x, 15 + y);
		glVertex2f(13 + x, 15 + y);
		glVertex2f(1 + x, 15 + y);

		glVertex2f(5 + x, 18 + y);
		glVertex2f(1 + x, 25 + y);
		glVertex2f(1 + x, 25 + y);
		glVertex2f(13 + x, 25 + y);
		glVertex2f(13 + x, 25 + y);
		glVertex2f(9 + x, 18 + y);
		glVertex2f(9 + x, 18 + y);
		glVertex2f(5 + x, 18 + y);

		glVertex2f(5 + x, 26 + y);
		glVertex2f(4 + x, 28 + y);
		glVertex2f(4 + x, 28 + y);
		glVertex2f(5 + x, 30 + y);
		glVertex2f(5 + x, 30 + y);
		glVertex2f(7 + x, 31 + y);
		glVertex2f(7 + x, 31 + y);
		glVertex2f(9 + x, 30 + y);
		glVertex2f(9 + x, 30 + y);
		glVertex2f(10 + x, 28 + y);
		glVertex2f(10 + x, 28 + y);
		glVertex2f(9 + x, 26 + y);
		glVertex2f(9 + x, 26 + y);
		glVertex2f(5 + x, 26 + y);

		glEnd();
	}
}
void Kon(int x, int y, int R, int G, int B)
{
	glColor3ub(R, G, B);
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(7 + x, 18 + y);
	glVertex2f(14 + x, y);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 6 + y);
	glVertex2f(1 + x, 7 + y);
	glVertex2f(1 + x, 21 + y);
	glVertex2f(5 + x, 27 + y);
	glVertex2f(12 + x, 27 + y);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(11 + x, 27 + y);
	glVertex2f(19 + x, 13 + y);
	glVertex2f(6 + x, 14 + y);
	glEnd();

	if (G == 255)
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(3 + x, 6 + y);
		glVertex2f(8 + x, 15 + y);
		glVertex2f(14 + x, y);
		glVertex2f(14 + x, y);
		glVertex2f(x, y);


		glVertex2f(11 + x, 6 + y);
		glVertex2f(1 + x, 7 + y);
		glVertex2f(1 + x, 7 + y);
		glVertex2f(1 + x, 21 + y);
		glVertex2f(1 + x, 21 + y);
		glVertex2f(5 + x, 27 + y);
		glVertex2f(5 + x, 27 + y);
		glVertex2f(12 + x, 27 + y);

		glVertex2f(11 + x, 27 + y);
		glVertex2f(19 + x, 13 + y);
		glVertex2f(19 + x, 13 + y);
		glVertex2f(8 + x, 15 + y);
		glEnd();
	}
}
void King(int x, int y, int R, int G, int B)
{
	glColor3ub(R, G, B);
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(7 + x, 18 + y);
	glVertex2f(14 + x, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1 + x, 15 + y);
	glVertex2f(1 + x, 18 + y);
	glVertex2f(13 + x, 18 + y);
	glVertex2f(13 + x, 15 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + x, 18 + y);
	glVertex2f(1 + x, 25 + y);
	glVertex2f(14 + x, 25 + y);
	glVertex2f(9 + x, 18 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1 + x, 25 + y);
	glVertex2f(1 + x, 28 + y);
	glVertex2f(4 + x, 28 + y);
	glVertex2f(4 + x, 25 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(5 + 1 + x, 25 + y);
	glVertex2f(5 + 1 + x, 28 + y);
	glVertex2f(5 + 4 + x, 28 + y);
	glVertex2f(5 + 4 + x, 25 + y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(10 + 1 + x, 25 + y);
	glVertex2f(10 + 1 + x, 28 + y);
	glVertex2f(10 + 4 + x, 28 + y);
	glVertex2f(10 + 4 + x, 25 + y);
	glEnd();

	if (G == 255)
	{
		glColor3ub(0, 0, 0);
		glLineWidth(1.3);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(6 + x, 16 + y);
		glVertex2f(8 + x, 16 + y);
		glVertex2f(14 + x, y);
		glVertex2f(x, y);
		glVertex2f(14 + x, y);

		glVertex2f(1 + x, 15 + y);
		glVertex2f(1 + x, 18 + y);
		glVertex2f(1 + x, 18 + y);
		glVertex2f(13 + x, 18 + y);
		glVertex2f(13 + x, 18 + y);
		glVertex2f(13 + x, 15 + y);
		glVertex2f(13 + x, 15 + y);
		glVertex2f(1 + x, 15 + y);

		glVertex2f(5 + x, 18 + y);
		glVertex2f(1 + x, 25 + y);

		glVertex2f(14 + x, 26 + y);
		glVertex2f(9 + x, 18 + y);
		glVertex2f(9 + x, 18 + y);
		glVertex2f(5 + x, 19 + y);

		glVertex2f(1 + x, 25 + y);
		glVertex2f(1 + x, 28 + y);
		glVertex2f(1 + x, 28 + y);
		glVertex2f(4 + x, 28 + y);
		glVertex2f(4 + x, 28 + y);
		glVertex2f(4 + x, 25 + y);
		glVertex2f(4 + x, 25 + y);
		glVertex2f(5 + 1 + x, 25 + y);
		glVertex2f(5 + 1 + x, 25 + y);
		glVertex2f(5 + 1 + x, 28 + y);
		glVertex2f(5 + 1 + x, 28 + y);
		glVertex2f(5 + 4 + x, 28 + y);
		glVertex2f(5 + 4 + x, 28 + y);
		glVertex2f(5 + 4 + x, 25 + y);
		glVertex2f(5 + 4 + x, 25 + y);
		glVertex2f(10 + 1 + x, 25 + y);
		glVertex2f(10 + 1 + x, 25 + y);
		glVertex2f(10 + 1 + x, 28 + y);
		glVertex2f(10 + 1 + x, 28 + y);
		glVertex2f(10 + 4 + x, 28 + y);
		glVertex2f(10 + 4 + x, 28 + y);
		glVertex2f(10 + 4 + x, 25 + y);
		glEnd();
	}
}
