////Write C++ program to draw man walking in the rain with an umbrella. Apply the concept of polymorphism
//#include <iostream>
//#include <graphics.h>
//#include <cstdlib>
//#include <ctime>
//#include <dos.h>
//int main() {
//int gd = DETECT, gm;
//initgraph(&gd, &gm, NULL);
//int xmov, x, y;
//for (xmov = 1; xmov < 200; xmov = xmov + 5) {
//line(0, 400, 639, 400);
//circle(30 + xmov, 280, 20); // head
//line(30 + xmov, 300, 30 + xmov, 350); // body
//line(30 + xmov, 330, 70 + xmov, 330); // hand
//if (xmov % 2 == 0) {
//line(30 + xmov, 350, 25 + xmov, 400); // left leg
//line(30 + xmov, 350, 10 + xmov, 400); // right leg
//} else {
//line(30 + xmov, 350, 25 + xmov, 400);
//delay(25);
//}
//line(70 + xmov, 250, 70 + xmov, 330); // umbrella
//pieslice(80 + xmov, 250, 180, 0, 80);
//srand(time(NULL)); // Seed for rand() based on current time
//for (int i = 0; i <= 300; i++) {
//x = rand() % 800;
//y = rand() % 800;
//outtextxy(x, y, "/");
//}
//delay(600);
//cleardevice();
//}
//getch();
//closegraph();
//return 0;
//}	
#include<stdio.h>
#include<graphics.h>

#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75

int ldisp=0;

void DrawManAndUmbrella(int x,int ldisp)
{
//head
circle(x,GroundY-90,10);
line(x,GroundY-80,x,GroundY-30);
//hand
line(x,GroundY-70,x+10,GroundY-60);
line(x,GroundY-65,x+10,GroundY-55);
line(x+10,GroundY-60,x+20,GroundY-70);
line(x+10,GroundY-55,x+20,GroundY-70);
//legs
line(x,GroundY-30,x+ldisp,GroundY);
line(x,GroundY-30,x-ldisp,GroundY);
//umbrella
pieslice(x+20,GroundY-120,0,180,40);
line(x+20,GroundY-120,x+20,GroundY-70);
}

void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
 rx=rand() % ScreenWidth;
 ry=rand() % ScreenHeight;
 if(ry<GroundY-4)
 {
  if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
  line(rx,ry,rx+0.5,ry+4);
 }
}
}
int main()
{
  int gd=DETECT,gm,x=0;
  //Change BGI directory according to yours
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  while(!kbhit())
  {
   //Draw Ground
   line(0,GroundY,ScreenWidth,GroundY);
   Rain(x);
   ldisp=(ldisp+2)%20;
   DrawManAndUmbrella(x,ldisp);
   delay(75);
   cleardevice();
   x=(x+2)%ScreenWidth;
}
  getch();
}


