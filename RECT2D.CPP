#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void rect_filled_2d(int x1,int y1,int length,int breadth){
int x2 =x1+breadth;
int y2 =y1+length;
while((x1<=x2)&&(y1<=y2)){
rectangle(x1,y1,x2,y2);
x1++;
y1++;
x2--;
y2--;
}
}
void rect_3d(int x1,int x2,int length,int breadth,int depth){
for(int i=0;i<depth;i++)
rect_filled_2d(x1+i,x2+i,length,breadth);
setcolor(BROWN);
rectangle(x1+i,x2+i,x1+i+breadth,x2+i+length);
}
void lego1(int pos_x,int pos_y)
{
setcolor(RED);
rect_3d(pos_x,pos_y,30,30,10);
}
void lego2(int pos_x,int pos_y)
{
setcolor(GREEN);
rect_3d(pos_x,pos_y,30,60,10);
}
void lego3(int pos_x,int pos_y)
{
setcolor(BLUE);
rect_3d(pos_x,pos_y,30,90,10);
}
void lego4(int pos_x,int pos_y)
{
setcolor(YELLOW);
rect_3d(pos_x,pos_y,30,120,10);
}

void main()
{
int gd=DETECT,gm,m,n,x,y,k,T,j;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("enter no. of test cases T:");
scanf("%d",&T);
j=T;
srand((unsigned)time(NULL));
while(T){
setbkcolor(3);//CYAN
printf("enter size of wall for %dth case \n length m:",(j-T+1));
scanf("%d",&m);
printf("  width n:");
scanf("%d",&n);
cleardevice();
for(int i=0;i<m;i++)
{
x=510;
y=420-30*i;
k=n;
while(k>=4)
{
switch((rand()%4)+1)
{
case 1: x=x+90;
	lego1(x,y);
	x-=120;
	k-=1;
	break;
case 2: x=x+60;
	lego2(x,y);
	x-=120;
	k-=2;
	break;
case 3: x=x+30;
	lego3(x,y);
	x-=120;
	k-=3;
	break;
case 4: x=x;
	lego4(x,y);
	x-=120;
	k-=4;
	break;
}
}
while(k>2){
switch((rand()%3)+1)
{
case 1: x=x+90;
	lego1(x,y);
	x-=120;
	k-=1;
	break;
case 2: x=x+60;
	lego2(x,y);
	x-=120;
	k-=2;
	break;
case 3: x=x+30;
	lego3(x,y);
	x-=120;
	k-=3;
	break;
}
}
switch(k%3){
case 1: x=x+90;
	lego1(x,y);
	x-=120;
	k-=1;
	break;
case 2: x=x+60;
	lego2(x,y);
	x-=120;
	k-=2;
	break;
}
}
--T;
}
getch();
closegraph();
}
