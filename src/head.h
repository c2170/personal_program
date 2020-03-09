#pragma once
typedef struct
{
	double x1, y1, x2, y2;
	double A, B, C;
}Line;

typedef struct
{
	double x, y;
}Point;

int isParallel(Line m, Line n);

void calculate(Line m, Line n); 
