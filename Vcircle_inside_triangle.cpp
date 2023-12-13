#include<iostream>
 #include<conio.h>
#include<math.h>
#include<graphics.h>
int main()
{
 int gd=DETECT, gm, a=250, x ,y ,radius=71;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 x = getmaxx()/2;
 y = getmaxy()/2;
 outtextxy(230,70, "Circle inside a Triangle");
 circle(x, y, radius);
 moveto(194, 311);
 linerel(a,0);
 linerel(-a/2, -sqrt(3.0)/2*a);
 lineto(194, 311);
 outtextxy(210, 400, "Press any key to continue...");
 getch();
closegraph();
}
