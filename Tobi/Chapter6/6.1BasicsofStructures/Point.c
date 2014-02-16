#include <stdio.h>
#include <math.h>
#include "Point.h"

Point makepoint(int x, int y);
Point addpoint(Point p1, Point p2);
void printPoint(Point p);
double dist(Point p);
int ptinrect(Point p, Rect r);

main()
{
	
	Point pt1 = makepoint(1, 2);
	Point pt2;

	pt2.x = 3;
	pt2.y = 4;
	
	Rect rec;
	rec.pt1 = pt1;
	rec.pt2 = pt2;
	
	printPoint(pt1);
	double sqr = sqrt((double)pt1.x * pt1.x + (double)pt1.y * pt1.y);
	printf("%f\n", dist(pt1));
	printf("%d\n", ptinrect(addpoint(pt1, pt2), rec));
	printf("%d\n", ptinrect(pt1, rec));
}

int ptinrect(Point p, Rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

Point makepoint (int x, int y)
{
	Point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

Point addpoint(Point p1, Point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

void printPoint(Point p)
{
	printf("%d\n", p.x);
	printf("%d\n", p.y);
}

double dist(Point p)
{
	double distance;
	distance = sqrt((double)p.x * p.x + (double)p.y * p.y);
	return distance;
}
