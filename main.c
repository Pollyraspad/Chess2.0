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

void Change(void)
{
	if (MY_DESK[7][0] == 1) Peshka(27, 512 - 400, 0, 0, 0);  // выравнивание положения фигуры (черные фигуры)
	if (MY_DESK[7][1] == 1) Peshka(67, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][2] == 1) Peshka(107, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][3] == 1) Peshka(147, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][4] == 1) Peshka(187, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][5] == 1) Peshka(227, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][6] == 1) Peshka(267, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][7] == 1) Peshka(307, 512 - 400, 0, 0, 0);

	if (MY_DESK[6][0] == 1) Peshka(27, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][1] == 1) Peshka(67, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][2] == 1) Peshka(107, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][3] == 1) Peshka(147, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][4] == 1) Peshka(187, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][5] == 1) Peshka(227, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][6] == 1) Peshka(267, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][7] == 1) Peshka(307, 512 - 360, 0, 0, 0);

	if (MY_DESK[5][0] == 1) Peshka(27, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][1] == 1) Peshka(67, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][2] == 1) Peshka(107, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][3] == 1) Peshka(147, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][4] == 1) Peshka(187, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][5] == 1) Peshka(227, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][6] == 1) Peshka(267, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][7] == 1) Peshka(307, 512 - 320, 0, 0, 0);

	if (MY_DESK[4][0] == 1) Peshka(27, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][1] == 1) Peshka(67, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][2] == 1) Peshka(107, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][3] == 1) Peshka(147, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][4] == 1) Peshka(187, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][5] == 1) Peshka(227, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][6] == 1) Peshka(267, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][7] == 1) Peshka(307, 512 - 280, 0, 0, 0);

	if (MY_DESK[3][0] == 1) Peshka(27, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][1] == 1) Peshka(67, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][2] == 1) Peshka(107, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][3] == 1) Peshka(147, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][4] == 1) Peshka(187, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][5] == 1) Peshka(227, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][6] == 1) Peshka(267, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][7] == 1) Peshka(307, 512 - 240, 0, 0, 0);

	if (MY_DESK[2][0] == 1) Peshka(27, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][1] == 1) Peshka(67, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][2] == 1) Peshka(107, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][3] == 1) Peshka(147, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][4] == 1) Peshka(187, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][5] == 1) Peshka(227, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][6] == 1) Peshka(267, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][7] == 1) Peshka(307, 512 - 200, 0, 0, 0);

	if (MY_DESK[1][0] == 1) Peshka(27, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][1] == 1) Peshka(67, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][2] == 1) Peshka(107, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][3] == 1) Peshka(147, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][4] == 1) Peshka(187, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][5] == 1) Peshka(227, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][6] == 1) Peshka(267, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][7] == 1) Peshka(307, 512 - 160, 0, 0, 0);

	if (MY_DESK[0][0] == 1) Peshka(27, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][1] == 1) Peshka(67, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][2] == 1) Peshka(107, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][3] == 1) Peshka(147, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][4] == 1) Peshka(187, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][5] == 1) Peshka(227, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][6] == 1) Peshka(267, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][7] == 1) Peshka(307, 512 - 120, 0, 0, 0);



	if (MY_DESK[7][0] == 2) Ferz(27, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][1] == 2) Ferz(67, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][2] == 2) Ferz(107, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][3] == 2) Ferz(147, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][4] == 2) Ferz(187, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][5] == 2) Ferz(227, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][6] == 2) Ferz(267, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][7] == 2) Ferz(307, 512 - 408, 0, 0, 0);

	if (MY_DESK[6][0] == 2) Ferz(27, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][1] == 2) Ferz(67, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][2] == 2) Ferz(107, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][3] == 2) Ferz(147, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][4] == 2) Ferz(187, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][5] == 2) Ferz(227, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][6] == 2) Ferz(267, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][7] == 2) Ferz(307, 512 - 368, 0, 0, 0);

	if (MY_DESK[5][0] == 2) Ferz(27, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][1] == 2) Ferz(67, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][2] == 2) Ferz(107, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][3] == 2) Ferz(147, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][4] == 2) Ferz(187, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][5] == 2) Ferz(227, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][6] == 2) Ferz(267, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][7] == 2) Ferz(307, 512 - 328, 0, 0, 0);

	if (MY_DESK[4][0] == 2) Ferz(27, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][1] == 2) Ferz(67, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][2] == 2) Ferz(107, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][3] == 2) Ferz(147, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][4] == 2) Ferz(187, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][5] == 2) Ferz(227, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][6] == 2) Ferz(267, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][7] == 2) Ferz(307, 512 - 288, 0, 0, 0);

	if (MY_DESK[3][0] == 2) Ferz(27, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][1] == 2) Ferz(67, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][2] == 2) Ferz(107, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][3] == 2) Ferz(147, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][4] == 2) Ferz(187, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][5] == 2) Ferz(227, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][6] == 2) Ferz(267, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][7] == 2) Ferz(307, 512 - 248, 0, 0, 0);

	if (MY_DESK[2][0] == 2) Ferz(27, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][1] == 2) Ferz(67, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][2] == 2) Ferz(107, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][3] == 2) Ferz(147, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][4] == 2) Ferz(187, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][5] == 2) Ferz(227, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][6] == 2) Ferz(267, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][7] == 2) Ferz(307, 512 - 208, 0, 0, 0);


	if (MY_DESK[1][0] == 2) Ferz(27, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][1] == 2) Ferz(67, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][2] == 2) Ferz(107, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][3] == 2) Ferz(147, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][4] == 2) Ferz(187, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][5] == 2) Ferz(227, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][6] == 2) Ferz(267, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][7] == 2) Ferz(307, 512 - 168, 0, 0, 0);

	if (MY_DESK[0][0] == 2) Ferz(27, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][1] == 2) Ferz(67, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][2] == 2) Ferz(107, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][3] == 2) Ferz(147, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][4] == 2) Ferz(187, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][5] == 2) Ferz(227, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][6] == 2) Ferz(267, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][7] == 2) Ferz(307, 512 - 128, 0, 0, 0);



	if (MY_DESK[7][0] == 3) Kon(27, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][1] == 3) Kon(67, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][2] == 3) Kon(107, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][3] == 3) Kon(147, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][4] == 3) Kon(187, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][5] == 3) Kon(227, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][6] == 3) Kon(267, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][7] == 3) Kon(307, 512 - 408, 0, 0, 0);

	if (MY_DESK[6][0] == 3) Kon(27, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][1] == 3) Kon(67, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][2] == 3) Kon(107, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][3] == 3) Kon(147, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][4] == 3) Kon(187, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][5] == 3) Kon(227, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][6] == 3) Kon(267, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][7] == 3) Kon(307, 512 - 368, 0, 0, 0);

	if (MY_DESK[5][0] == 3) Kon(27, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][1] == 3) Kon(67, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][2] == 3) Kon(107, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][3] == 3) Kon(147, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][4] == 3) Kon(187, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][5] == 3) Kon(227, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][6] == 3) Kon(267, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][7] == 3) Kon(307, 512 - 328, 0, 0, 0);

	if (MY_DESK[4][0] == 3) Kon(27, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][1] == 3) Kon(67, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][2] == 3) Kon(107, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][3] == 3) Kon(147, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][4] == 3) Kon(187, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][5] == 3) Kon(227, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][6] == 3) Kon(267, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][7] == 3) Kon(307, 512 - 288, 0, 0, 0);

	if (MY_DESK[3][0] == 3) Kon(27, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][1] == 3) Kon(67, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][2] == 3) Kon(107, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][3] == 3) Kon(147, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][4] == 3) Kon(187, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][5] == 3) Kon(227, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][6] == 3) Kon(267, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][7] == 3) Kon(307, 512 - 248, 0, 0, 0);

	if (MY_DESK[2][0] == 3) Kon(27, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][1] == 3) Kon(67, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][2] == 3) Kon(107, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][3] == 3) Kon(147, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][4] == 3) Kon(187, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][5] == 3) Kon(227, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][6] == 3) Kon(267, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][7] == 3) Kon(307, 512 - 208, 0, 0, 0);

	if (MY_DESK[1][0] == 3) Kon(27, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][1] == 3) Kon(67, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][2] == 3) Kon(107, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][3] == 3) Kon(147, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][4] == 3) Kon(187, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][5] == 3) Kon(227, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][6] == 3) Kon(267, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][7] == 3) Kon(307, 512 - 168, 0, 0, 0);

	if (MY_DESK[0][0] == 3) Kon(27, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][1] == 3) Kon(67, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][2] == 3) Kon(107, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][3] == 3) Kon(147, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][4] == 3) Kon(187, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][5] == 3) Kon(227, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][6] == 3) Kon(267, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][7] == 3) Kon(307, 512 - 128, 0, 0, 0);



	if (MY_DESK[7][0] == 4) Slon(27, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][1] == 4) Slon(67, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][2] == 4) Slon(107, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][3] == 4) Slon(147, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][4] == 4) Slon(187, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][5] == 4) Slon(227, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][6] == 4) Slon(267, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][7] == 4) Slon(307, 512 - 408, 0, 0, 0);

	if (MY_DESK[6][0] == 4) Slon(27, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][1] == 4) Slon(67, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][2] == 4) Slon(107, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][3] == 4) Slon(147, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][4] == 4) Slon(187, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][5] == 4) Slon(227, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][6] == 4) Slon(267, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][7] == 4) Slon(307, 512 - 368, 0, 0, 0);

	if (MY_DESK[5][0] == 4) Slon(27, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][1] == 4) Slon(67, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][2] == 4) Slon(107, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][3] == 4) Slon(147, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][4] == 4) Slon(187, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][5] == 4) Slon(227, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][6] == 4) Slon(267, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][7] == 4) Slon(307, 512 - 328, 0, 0, 0);

	if (MY_DESK[4][0] == 4) Slon(27, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][1] == 4) Slon(67, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][2] == 4) Slon(107, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][3] == 4) Slon(147, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][4] == 4) Slon(187, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][5] == 4) Slon(227, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][6] == 4) Slon(267, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][7] == 4) Slon(307, 512 - 288, 0, 0, 0);

	if (MY_DESK[3][0] == 4) Slon(27, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][1] == 4) Slon(67, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][2] == 4) Slon(107, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][3] == 4) Slon(147, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][4] == 4) Slon(187, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][5] == 4) Slon(227, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][6] == 4) Slon(267, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][7] == 4) Slon(307, 512 - 248, 0, 0, 0);

	if (MY_DESK[2][0] == 4) Slon(27, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][1] == 4) Slon(67, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][2] == 4) Slon(107, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][3] == 4) Slon(147, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][4] == 4) Slon(187, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][5] == 4) Slon(227, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][6] == 4) Slon(267, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][7] == 4) Slon(307, 512 - 208, 0, 0, 0);

	if (MY_DESK[1][0] == 4) Slon(27, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][1] == 4) Slon(67, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][2] == 4) Slon(107, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][3] == 4) Slon(147, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][4] == 4) Slon(187, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][5] == 4) Slon(227, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][6] == 4) Slon(267, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][7] == 4) Slon(307, 512 - 168, 0, 0, 0);

	if (MY_DESK[0][0] == 4) Slon(27, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][1] == 4) Slon(67, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][2] == 4) Slon(107, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][3] == 4) Slon(147, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][4] == 4) Slon(187, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][5] == 4) Slon(227, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][6] == 4) Slon(267, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][7] == 4) Slon(307, 512 - 128, 0, 0, 0);


	if (MY_DESK[7][0] == 5) Ladia(27, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][1] == 5) Ladia(67, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][2] == 5) Ladia(107, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][3] == 5) Ladia(147, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][4] == 5) Ladia(187, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][5] == 5) Ladia(227, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][6] == 5) Ladia(267, 512 - 400, 0, 0, 0);
	if (MY_DESK[7][7] == 5) Ladia(307, 512 - 400, 0, 0, 0);

	if (MY_DESK[6][0] == 5) Ladia(27, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][1] == 5) Ladia(67, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][2] == 5) Ladia(107, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][3] == 5) Ladia(147, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][4] == 5) Ladia(187, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][5] == 5) Ladia(227, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][6] == 5) Ladia(267, 512 - 360, 0, 0, 0);
	if (MY_DESK[6][7] == 5) Ladia(307, 512 - 360, 0, 0, 0);

	if (MY_DESK[5][0] == 5) Ladia(27, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][1] == 5) Ladia(67, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][2] == 5) Ladia(107, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][3] == 5) Ladia(147, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][4] == 5) Ladia(187, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][5] == 5) Ladia(227, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][6] == 5) Ladia(267, 512 - 320, 0, 0, 0);
	if (MY_DESK[5][7] == 5) Ladia(307, 512 - 320, 0, 0, 0);

	if (MY_DESK[4][0] == 5) Ladia(27, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][1] == 5) Ladia(67, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][2] == 5) Ladia(107, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][3] == 5) Ladia(147, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][4] == 5) Ladia(187, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][5] == 5) Ladia(227, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][6] == 5) Ladia(267, 512 - 280, 0, 0, 0);
	if (MY_DESK[4][7] == 5) Ladia(307, 512 - 280, 0, 0, 0);

	if (MY_DESK[3][0] == 5) Ladia(27, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][1] == 5) Ladia(67, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][2] == 5) Ladia(107, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][3] == 5) Ladia(147, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][4] == 5) Ladia(187, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][5] == 5) Ladia(227, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][6] == 5) Ladia(267, 512 - 240, 0, 0, 0);
	if (MY_DESK[3][7] == 5) Ladia(307, 512 - 240, 0, 0, 0);

	if (MY_DESK[2][0] == 5) Ladia(27, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][1] == 5) Ladia(67, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][2] == 5) Ladia(107, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][3] == 5) Ladia(147, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][4] == 5) Ladia(187, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][5] == 5) Ladia(227, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][6] == 5) Ladia(267, 512 - 200, 0, 0, 0);
	if (MY_DESK[2][7] == 5) Ladia(307, 512 - 200, 0, 0, 0);

	if (MY_DESK[1][0] == 5) Ladia(27, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][1] == 5) Ladia(67, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][2] == 5) Ladia(107, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][3] == 5) Ladia(147, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][4] == 5) Ladia(187, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][5] == 5) Ladia(227, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][6] == 5) Ladia(267, 512 - 160, 0, 0, 0);
	if (MY_DESK[1][7] == 5) Ladia(307, 512 - 160, 0, 0, 0);

	if (MY_DESK[0][0] == 5) Ladia(27, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][1] == 5) Ladia(67, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][2] == 5) Ladia(107, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][3] == 5) Ladia(147, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][4] == 5) Ladia(187, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][5] == 5) Ladia(227, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][6] == 5) Ladia(267, 512 - 120, 0, 0, 0);
	if (MY_DESK[0][7] == 5) Ladia(307, 512 - 120, 0, 0, 0);



	if (MY_DESK[7][0] == 6) King(27, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][1] == 6) King(67, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][2] == 6) King(107, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][3] == 6) King(147, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][4] == 6) King(187, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][5] == 6) King(227, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][6] == 6) King(267, 512 - 408, 0, 0, 0);
	if (MY_DESK[7][7] == 6) King(307, 512 - 408, 0, 0, 0);

	if (MY_DESK[6][0] == 6) King(27, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][1] == 6) King(67, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][2] == 6) King(107, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][3] == 6) King(147, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][4] == 6) King(187, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][5] == 6) King(227, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][6] == 6) King(267, 512 - 368, 0, 0, 0);
	if (MY_DESK[6][7] == 6) King(307, 512 - 368, 0, 0, 0);

	if (MY_DESK[5][0] == 6) King(27, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][1] == 6) King(67, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][2] == 6) King(107, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][3] == 6) King(147, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][4] == 6) King(187, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][5] == 6) King(227, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][6] == 6) King(267, 512 - 328, 0, 0, 0);
	if (MY_DESK[5][7] == 6) King(307, 512 - 328, 0, 0, 0);

	if (MY_DESK[4][0] == 6) King(27, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][1] == 6) King(67, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][2] == 6) King(107, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][3] == 6) King(147, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][4] == 6) King(187, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][5] == 6) King(227, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][6] == 6) King(267, 512 - 288, 0, 0, 0);
	if (MY_DESK[4][7] == 6) King(307, 512 - 288, 0, 0, 0);

	if (MY_DESK[3][0] == 6) King(27, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][1] == 6) King(67, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][2] == 6) King(107, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][3] == 6) King(147, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][4] == 6) King(187, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][5] == 6) King(227, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][6] == 6) King(267, 512 - 248, 0, 0, 0);
	if (MY_DESK[3][7] == 6) King(307, 512 - 248, 0, 0, 0);

	if (MY_DESK[2][0] == 6) King(27, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][1] == 6) King(67, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][2] == 6) King(107, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][3] == 6) King(147, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][4] == 6) King(187, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][5] == 6) King(227, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][6] == 6) King(267, 512 - 208, 0, 0, 0);
	if (MY_DESK[2][7] == 6) King(307, 512 - 208, 0, 0, 0);

	if (MY_DESK[1][0] == 6) King(27, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][1] == 6) King(67, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][2] == 6) King(107, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][3] == 6) King(147, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][4] == 6) King(187, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][5] == 6) King(227, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][6] == 6) King(267, 512 - 168, 0, 0, 0);
	if (MY_DESK[1][7] == 6) King(307, 512 - 168, 0, 0, 0);

	if (MY_DESK[0][0] == 6) King(27, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][1] == 6) King(67, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][2] == 6) King(107, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][3] == 6) King(147, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][4] == 6) King(187, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][5] == 6) King(227, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][6] == 6) King(267, 512 - 128, 0, 0, 0);
	if (MY_DESK[0][7] == 6) King(307, 512 - 128, 0, 0, 0);
	//////////////////////////////////////////////////////


	if (MY_DESK[7][0] == 11) Peshka(27, 512 - 400, 255, 255, 255);    // выравнивание положения фигуры (белые фигуры)
	if (MY_DESK[7][1] == 11) Peshka(67, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][2] == 11) Peshka(107, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][3] == 11) Peshka(147, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][4] == 11) Peshka(187, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][5] == 11) Peshka(227, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][6] == 11) Peshka(267, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][7] == 11) Peshka(307, 512 - 400, 255, 255, 255);

	if (MY_DESK[6][0] == 11) Peshka(27, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][1] == 11) Peshka(67, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][2] == 11) Peshka(107, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][3] == 11) Peshka(147, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][4] == 11) Peshka(187, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][5] == 11) Peshka(227, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][6] == 11) Peshka(267, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][7] == 11) Peshka(307, 512 - 360, 255, 255, 255);

	if (MY_DESK[5][0] == 11) Peshka(27, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][1] == 11) Peshka(67, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][2] == 11) Peshka(107, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][3] == 11) Peshka(147, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][4] == 11) Peshka(187, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][5] == 11) Peshka(227, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][6] == 11) Peshka(267, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][7] == 11) Peshka(307, 512 - 320, 255, 255, 255);

	if (MY_DESK[4][0] == 11) Peshka(27, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][1] == 11) Peshka(67, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][2] == 11) Peshka(107, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][3] == 11) Peshka(147, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][4] == 11) Peshka(187, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][5] == 11) Peshka(227, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][6] == 11) Peshka(267, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][7] == 11) Peshka(307, 512 - 280, 255, 255, 255);

	if (MY_DESK[3][0] == 11) Peshka(27, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][1] == 11) Peshka(67, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][2] == 11) Peshka(107, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][3] == 11) Peshka(147, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][4] == 11) Peshka(187, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][5] == 11) Peshka(227, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][6] == 11) Peshka(267, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][7] == 11) Peshka(307, 512 - 240, 255, 255, 255);

	if (MY_DESK[2][0] == 11) Peshka(27, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][1] == 11) Peshka(67, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][2] == 11) Peshka(107, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][3] == 11) Peshka(147, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][4] == 11) Peshka(187, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][5] == 11) Peshka(227, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][6] == 11) Peshka(267, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][7] == 11) Peshka(307, 512 - 200, 255, 255, 255);

	if (MY_DESK[1][0] == 11) Peshka(27, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][1] == 11) Peshka(67, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][2] == 11) Peshka(107, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][3] == 11) Peshka(147, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][4] == 11) Peshka(187, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][5] == 11) Peshka(227, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][6] == 11) Peshka(267, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][7] == 11) Peshka(307, 512 - 160, 255, 255, 255);

	if (MY_DESK[0][0] == 11) Peshka(27, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][1] == 11) Peshka(67, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][2] == 11) Peshka(107, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][3] == 11) Peshka(147, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][4] == 11) Peshka(187, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][5] == 11) Peshka(227, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][6] == 11) Peshka(267, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][7] == 11) Peshka(307, 512 - 120, 255, 255, 255);



	if (MY_DESK[7][0] == 21) Ferz(27, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][1] == 21) Ferz(67, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][2] == 21) Ferz(107, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][3] == 21) Ferz(147, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][4] == 21) Ferz(187, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][5] == 21) Ferz(227, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][6] == 21) Ferz(267, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][7] == 21) Ferz(307, 512 - 408, 255, 255, 255);

	if (MY_DESK[6][0] == 21) Ferz(27, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][1] == 21) Ferz(67, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][2] == 21) Ferz(107, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][3] == 21) Ferz(147, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][4] == 21) Ferz(187, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][5] == 21) Ferz(227, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][6] == 21) Ferz(267, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][7] == 21) Ferz(307, 512 - 368, 255, 255, 255);

	if (MY_DESK[5][0] == 21) Ferz(27, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][1] == 21) Ferz(67, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][2] == 21) Ferz(107, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][3] == 21) Ferz(147, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][4] == 21) Ferz(187, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][5] == 21) Ferz(227, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][6] == 21) Ferz(267, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][7] == 21) Ferz(307, 512 - 328, 255, 255, 255);

	if (MY_DESK[4][0] == 21) Ferz(27, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][1] == 21) Ferz(67, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][2] == 21) Ferz(107, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][3] == 21) Ferz(147, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][4] == 21) Ferz(187, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][5] == 21) Ferz(227, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][6] == 21) Ferz(267, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][7] == 21) Ferz(307, 512 - 288, 255, 255, 255);

	if (MY_DESK[3][0] == 21) Ferz(27, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][1] == 21) Ferz(67, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][2] == 21) Ferz(107, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][3] == 21) Ferz(147, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][4] == 21) Ferz(187, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][5] == 21) Ferz(227, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][6] == 21) Ferz(267, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][7] == 21) Ferz(307, 512 - 248, 255, 255, 255);

	if (MY_DESK[2][0] == 21) Ferz(27, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][1] == 21) Ferz(67, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][2] == 21) Ferz(107, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][3] == 21) Ferz(147, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][4] == 21) Ferz(187, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][5] == 21) Ferz(227, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][6] == 21) Ferz(267, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][7] == 21) Ferz(307, 512 - 208, 255, 255, 255);


	if (MY_DESK[1][0] == 21) Ferz(27, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][1] == 21) Ferz(67, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][2] == 21) Ferz(107, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][3] == 21) Ferz(147, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][4] == 21) Ferz(187, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][5] == 21) Ferz(227, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][6] == 21) Ferz(267, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][7] == 21) Ferz(307, 512 - 168, 255, 255, 255);

	if (MY_DESK[0][0] == 21) Ferz(27, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][1] == 21) Ferz(67, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][2] == 21) Ferz(107, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][3] == 21) Ferz(147, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][4] == 21) Ferz(187, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][5] == 21) Ferz(227, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][6] == 21) Ferz(267, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][7] == 21) Ferz(307, 512 - 128, 255, 255, 255);



	if (MY_DESK[7][0] == 31) Kon(27, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][1] == 31) Kon(67, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][2] == 31) Kon(107, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][3] == 31) Kon(147, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][4] == 31) Kon(187, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][5] == 31) Kon(227, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][6] == 31) Kon(267, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][7] == 31) Kon(307, 512 - 408, 255, 255, 255);

	if (MY_DESK[6][0] == 31) Kon(27, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][1] == 31) Kon(67, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][2] == 31) Kon(107, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][3] == 31) Kon(147, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][4] == 31) Kon(187, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][5] == 31) Kon(227, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][6] == 31) Kon(267, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][7] == 31) Kon(307, 512 - 368, 255, 255, 255);

	if (MY_DESK[5][0] == 31) Kon(27, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][1] == 31) Kon(67, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][2] == 31) Kon(107, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][3] == 31) Kon(147, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][4] == 31) Kon(187, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][5] == 31) Kon(227, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][6] == 31) Kon(267, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][7] == 31) Kon(307, 512 - 328, 0255, 255, 255);

	if (MY_DESK[4][0] == 31) Kon(27, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][1] == 31) Kon(67, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][2] == 31) Kon(107, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][3] == 31) Kon(147, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][4] == 31) Kon(187, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][5] == 31) Kon(227, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][6] == 31) Kon(267, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][7] == 31) Kon(307, 512 - 288, 255, 255, 255);

	if (MY_DESK[3][0] == 31) Kon(27, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][1] == 31) Kon(67, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][2] == 31) Kon(107, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][3] == 31) Kon(147, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][4] == 31) Kon(187, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][5] == 31) Kon(227, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][6] == 31) Kon(267, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][7] == 31) Kon(307, 512 - 248, 255, 255, 255);

	if (MY_DESK[2][0] == 31) Kon(27, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][1] == 31) Kon(67, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][2] == 31) Kon(107, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][3] == 31) Kon(147, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][4] == 31) Kon(187, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][5] == 31) Kon(227, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][6] == 31) Kon(267, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][7] == 31) Kon(307, 512 - 208, 255, 255, 255);

	if (MY_DESK[1][0] == 31) Kon(27, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][1] == 31) Kon(67, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][2] == 31) Kon(107, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][3] == 31) Kon(147, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][4] == 31) Kon(187, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][5] == 31) Kon(227, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][6] == 31) Kon(267, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][7] == 31) Kon(307, 512 - 168, 255, 255, 255);

	if (MY_DESK[0][0] == 31) Kon(27, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][1] == 31) Kon(67, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][2] == 31) Kon(107, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][3] == 31) Kon(147, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][4] == 31) Kon(187, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][5] == 31) Kon(227, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][6] == 31) Kon(267, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][7] == 31) Kon(307, 512 - 128, 255, 255, 255);



	if (MY_DESK[7][0] == 41) Slon(27, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][1] == 41) Slon(67, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][2] == 41) Slon(107, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][3] == 41) Slon(147, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][4] == 41) Slon(187, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][5] == 41) Slon(227, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][6] == 41) Slon(267, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][7] == 41) Slon(307, 512 - 408, 255, 255, 255);

	if (MY_DESK[6][0] == 41) Slon(27, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][1] == 41) Slon(67, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][2] == 41) Slon(107, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][3] == 41) Slon(147, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][4] == 41) Slon(187, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][5] == 41) Slon(227, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][6] == 41) Slon(267, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][7] == 41) Slon(307, 512 - 368, 255, 255, 255);

	if (MY_DESK[5][0] == 41) Slon(27, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][1] == 41) Slon(67, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][2] == 41) Slon(107, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][3] == 41) Slon(147, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][4] == 41) Slon(187, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][5] == 41) Slon(227, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][6] == 41) Slon(267, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][7] == 41) Slon(307, 512 - 328, 255, 255, 255);

	if (MY_DESK[4][0] == 41) Slon(27, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][1] == 41) Slon(67, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][2] == 41) Slon(107, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][3] == 41) Slon(147, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][4] == 41) Slon(187, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][5] == 41) Slon(227, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][6] == 41) Slon(267, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][7] == 41) Slon(307, 512 - 288, 255, 255, 255);

	if (MY_DESK[3][0] == 41) Slon(27, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][1] == 41) Slon(67, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][2] == 41) Slon(107, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][3] == 41) Slon(147, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][4] == 41) Slon(187, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][5] == 41) Slon(227, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][6] == 41) Slon(267, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][7] == 41) Slon(307, 512 - 248, 255, 255, 255);

	if (MY_DESK[2][0] == 41) Slon(27, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][1] == 41) Slon(67, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][2] == 41) Slon(107, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][3] == 41) Slon(147, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][4] == 41) Slon(187, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][5] == 41) Slon(227, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][6] == 41) Slon(267, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][7] == 41) Slon(307, 512 - 208, 255, 255, 255);

	if (MY_DESK[1][0] == 41) Slon(27, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][1] == 41) Slon(67, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][2] == 41) Slon(107, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][3] == 41) Slon(147, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][4] == 41) Slon(187, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][5] == 41) Slon(227, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][6] == 41) Slon(267, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][7] == 41) Slon(307, 512 - 168, 255, 255, 255);

	if (MY_DESK[0][0] == 41) Slon(27, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][1] == 41) Slon(67, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][2] == 41) Slon(107, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][3] == 41) Slon(147, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][4] == 41) Slon(187, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][5] == 41) Slon(227, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][6] == 41) Slon(267, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][7] == 41) Slon(307, 512 - 128, 255, 255, 255);


	if (MY_DESK[7][0] == 51) Ladia(27, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][1] == 51) Ladia(67, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][2] == 51) Ladia(107, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][3] == 51) Ladia(147, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][4] == 51) Ladia(187, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][5] == 51) Ladia(227, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][6] == 51) Ladia(267, 512 - 400, 255, 255, 255);
	if (MY_DESK[7][7] == 51) Ladia(307, 512 - 400, 255, 255, 255);

	if (MY_DESK[6][0] == 51) Ladia(27, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][1] == 51) Ladia(67, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][2] == 51) Ladia(107, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][3] == 51) Ladia(147, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][4] == 51) Ladia(187, 512 - 360, 255, 255, 255);;
	if (MY_DESK[6][5] == 51) Ladia(227, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][6] == 51) Ladia(267, 512 - 360, 255, 255, 255);
	if (MY_DESK[6][7] == 51) Ladia(307, 512 - 360, 255, 255, 255);

	if (MY_DESK[5][0] == 51) Ladia(27, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][1] == 51) Ladia(67, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][2] == 51) Ladia(107, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][3] == 51) Ladia(147, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][4] == 51) Ladia(187, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][5] == 51) Ladia(227, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][6] == 51) Ladia(267, 512 - 320, 255, 255, 255);
	if (MY_DESK[5][7] == 51) Ladia(307, 512 - 320, 255, 255, 255);

	if (MY_DESK[4][0] == 51) Ladia(27, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][1] == 51) Ladia(67, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][2] == 51) Ladia(107, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][3] == 51) Ladia(147, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][4] == 51) Ladia(187, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][5] == 51) Ladia(227, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][6] == 51) Ladia(267, 512 - 280, 255, 255, 255);
	if (MY_DESK[4][7] == 51) Ladia(307, 512 - 280, 255, 255, 255);

	if (MY_DESK[3][0] == 51) Ladia(27, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][1] == 51) Ladia(67, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][2] == 51) Ladia(107, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][3] == 51) Ladia(147, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][4] == 51) Ladia(187, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][5] == 51) Ladia(227, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][6] == 51) Ladia(267, 512 - 240, 255, 255, 255);
	if (MY_DESK[3][7] == 51) Ladia(307, 512 - 240, 255, 255, 255);

	if (MY_DESK[2][0] == 51) Ladia(27, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][1] == 51) Ladia(67, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][2] == 51) Ladia(107, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][3] == 51) Ladia(147, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][4] == 51) Ladia(187, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][5] == 51) Ladia(227, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][6] == 51) Ladia(267, 512 - 200, 255, 255, 255);
	if (MY_DESK[2][7] == 51) Ladia(307, 512 - 200, 255, 255, 255);

	if (MY_DESK[1][0] == 51) Ladia(27, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][1] == 51) Ladia(67, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][2] == 51) Ladia(107, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][3] == 51) Ladia(147, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][4] == 51) Ladia(187, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][5] == 51) Ladia(227, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][6] == 51) Ladia(267, 512 - 160, 255, 255, 255);
	if (MY_DESK[1][7] == 51) Ladia(307, 512 - 160, 255, 255, 255);

	if (MY_DESK[0][0] == 51) Ladia(27, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][1] == 51) Ladia(67, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][2] == 51) Ladia(107, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][3] == 51) Ladia(147, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][4] == 51) Ladia(187, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][5] == 51) Ladia(227, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][6] == 51) Ladia(267, 512 - 120, 255, 255, 255);
	if (MY_DESK[0][7] == 51) Ladia(307, 512 - 120, 255, 255, 255);



	if (MY_DESK[7][0] == 61) King(27, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][1] == 61) King(67, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][2] == 61) King(107, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][3] == 61) King(147, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][4] == 61) King(187, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][5] == 61) King(227, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][6] == 61) King(267, 512 - 408, 255, 255, 255);
	if (MY_DESK[7][7] == 61) King(307, 512 - 408, 255, 255, 255);

	if (MY_DESK[6][0] == 61) King(27, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][1] == 61) King(67, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][2] == 61) King(107, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][3] == 61) King(147, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][4] == 61) King(187, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][5] == 61) King(227, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][6] == 61) King(267, 512 - 368, 255, 255, 255);
	if (MY_DESK[6][7] == 61) King(307, 512 - 368, 255, 255, 255);

	if (MY_DESK[5][0] == 61) King(27, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][1] == 61) King(67, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][2] == 61) King(107, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][3] == 61) King(147, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][4] == 61) King(187, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][5] == 61) King(227, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][6] == 61) King(267, 512 - 328, 255, 255, 255);
	if (MY_DESK[5][7] == 61) King(307, 512 - 328, 255, 255, 255);

	if (MY_DESK[4][0] == 61) King(27, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][1] == 61) King(67, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][2] == 61) King(107, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][3] == 61) King(147, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][4] == 61) King(187, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][5] == 61) King(227, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][6] == 61) King(267, 512 - 288, 255, 255, 255);
	if (MY_DESK[4][7] == 61) King(307, 512 - 288, 255, 255, 255);

	if (MY_DESK[3][0] == 61) King(27, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][1] == 61) King(67, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][2] == 61) King(107, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][3] == 61) King(147, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][4] == 61) King(187, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][5] == 61) King(227, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][6] == 61) King(267, 512 - 248, 255, 255, 255);
	if (MY_DESK[3][7] == 61) King(307, 512 - 248, 255, 255, 255);

	if (MY_DESK[2][0] == 61) King(27, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][1] == 61) King(67, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][2] == 61) King(107, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][3] == 61) King(147, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][4] == 61) King(187, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][5] == 61) King(227, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][6] == 61) King(267, 512 - 208, 255, 255, 255);
	if (MY_DESK[2][7] == 61) King(307, 512 - 208, 255, 255, 255);

	if (MY_DESK[1][0] == 61) King(27, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][1] == 61) King(67, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][2] == 61) King(107, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][3] == 61) King(147, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][4] == 61) King(187, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][5] == 61) King(227, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][6] == 61) King(267, 512 - 168, 255, 255, 255);
	if (MY_DESK[1][7] == 61) King(307, 512 - 168, 255, 255, 255);

	if (MY_DESK[0][0] == 61) King(27, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][1] == 61) King(67, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][2] == 61) King(107, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][3] == 61) King(147, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][4] == 61) King(187, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][5] == 61) King(227, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][6] == 61) King(267, 512 - 128, 255, 255, 255);
	if (MY_DESK[0][7] == 61) King(307, 512 - 128, 255, 255, 255);
}

void Display(void)
{
	glClearColor(1, 1, 0.6, 0); //цвет фона
	glClear(GL_COLOR_BUFFER_BIT);
	Desk();
	Change();
	Peshka(370, 380, 0, 0, 0); //закрепленная фигура черной пешки
	if (how_many_peshka1 != 8)Peshka(422, 380, 255, 255, 255); //присваивание координат для белой пешки
	Ladia(367, 345, 0, 0, 0);
	if (how_many_ladia1 != 2)Ladia(419, 345, 255, 255, 255);
	Ferz(370, 310, 0, 0, 0);
	if (how_many_ferz1 != 1)Ferz(422, 310, 255, 255, 255);
	Kon(370, 275, 0, 0, 0);
	if (how_many_kon1 != 2)Kon(422, 275, 255, 255, 255);
	Slon(370, 240, 0, 0, 0);
	if (how_many_slon1 != 2)Slon(422, 240, 255, 255, 255);
	King(370, 200, 0, 0, 0);
	if (how_many_king1 != 1)King(422, 200, 255, 255, 255);

	if (how_many_peshka == 8)  Peshka(370, 380, 255, 0, 0); //закрашивание в красный цвет белых фигур
	if (how_many_ferz == 1) Ferz(370, 310, 255, 0, 0);
	if (how_many_kon == 2) Kon(370, 275, 255, 0, 0);
	if (how_many_slon == 2) Slon(370, 240, 255, 0, 0);
	if (how_many_ladia == 2) Ladia(367, 345, 255, 0, 0);
	if (how_many_king == 1) King(370, 200, 255, 0, 0);

	if (how_many_peshka1 == 8)  Peshka(422, 380, 255, 0, 0); //закрашивание в красный цвет черных фигур
	if (how_many_ferz1 == 1) Ferz(422, 310, 255, 0, 0);
	if (how_many_kon1 == 2) Kon(422, 275, 255, 0, 0);
	if (how_many_slon1 == 2) Slon(422, 240, 255, 0, 0);
	if (how_many_ladia1 == 2) Ladia(419, 345, 255, 0, 0);
	if (how_many_king1 == 1) King(422, 200, 255, 0, 0);

	glutSwapBuffers(); //Делается это для получения плавной анимации и для того, чтобы не было эффекта мерцания экрана
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv); //Для инициализации библиотеки GLUT в начале программы надо вызвать glutInit (&argc, argv)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Для задания режима дисплея вызывается glutInitDisplayMode (режим), где режим может принимать значения (GLUT_DOUBLE | GLUT_RGB) 
	glutInitWindowSize(Width, Height); //Размеры окна задаются glutInitWindowSize (ширина, высота)
	glutCreateWindow("Chess 13433/3"); //Создается окно функцией glutCreateWindow (заголовок_окна).
	glutDisplayFunc(Display); // задает функцию рисования изображения
	glutReshapeFunc(Reshape); // задает функцию обработки изменения размеров окна
	glutKeyboardFunc(Keyboard); //задает функцию обработки нажатия клавиш клавиатуры
	glutSpecialFunc(processSpecialKeys); //задает функцию обработки нажатия клавиш клавиатуры
	glutMouseFunc(mouseButton); // задает функцию, обрабатывающую команды мыши
	glShadeModel(GL_SMOOTH); // сглаживание фигуры
	glutMainLoop();
}
