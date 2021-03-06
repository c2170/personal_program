﻿// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <string>
#include "head.h"

using namespace std;

Line line[500010];
set<Point> s;
int cnt;
const double eps = 1e-8;

bool operator < (const Point& m, const Point& n)
{
	if (m.x - n.x < -eps) {
		return 1;
	}
	else if (m.x - n.x < eps && m.y - n.y < -eps) {
		return 1;
	}
	return 0;
}

int isParallel(Line m, Line n)
{
	if (m.A == 0 && n.A == 0) {
		return 1;
	}
	else if (m.B == 0 && n.B == 0) {
		return 1;
	}
	else if (n.A != 0 && n.B != 0 && (m.A / n.A == m.B / n.B)) {
		return 1;
	}
	return 0;
}

void calculate(Line m, Line n)
{
	if (isParallel(m, n)) {
		return;
	}
	double A1, A2, B1, B2, C1, C2;
	Point p;
	A1 = m.A; B1 = m.B; C1 = m.C;
	A2 = n.A; B2 = n.B; C2 = n.C;
	p.x = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1);
	p.y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
	set<Point>::iterator it;
	it = s.lower_bound(p);
	if (s.empty() || it == s.end()) {
		s.insert(p);
		cnt++;
	}
	else if (it != s.end()) {
		if (!(abs(p.x - (*it).x) < eps && abs(p.y - (*it).y) < eps)) {
			s.insert(p);
			cnt++;
		}
	}
}

int main(int argc, char** argv)
{
	FILE* in = stdin;
	FILE* out = stdout;
	int n, i, j;
	double x1, y1, x2, y2, k;
	char s[3];

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0) {
			i++;
			if (i >= argc) {
				return 0;
			}
			in = fopen(argv[i], "r");
		}
		else if (strcmp(argv[i], "-o") == 0) {
			i++;
			if (i >= argc) {
				return 0;
			}
			out = fopen(argv[i], "w");
		}
		else {
			return 0;
		}
	}
	(void)fscanf(in, "%d", &n);
	for (i = 1; i <= n; i++) {
		(void)fscanf(in, "%s%lf%lf%lf%lf", &s, &x1, &y1, &x2, &y2);
		line[i].x1 = x1;	line[i].y1 = y1;	 line[i].x2 = x2;	line[i].y2 = y2;
		if (x1 == x2) {
			line[i].A = 1;
			line[i].B = 0;
			line[i].C = -x1;
		}
		else {
			k = (y2 - y1) / (x2 - x1);
			line[i].A = k;
			line[i].B = -1;
			line[i].C = y1 - k * x1;
		}
	}
	cnt = 0;
	for (i = 2; i <= n; i++) {
		for (j = 1; j < i; j++) {
			calculate(line[i], line[j]);
		}
	}
	fprintf(out, "%d\n", cnt);
	return 0;
}



