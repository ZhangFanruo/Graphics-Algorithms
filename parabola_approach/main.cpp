#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
void print_pixel(int x1,int y1,int x,int y)
{
    putpixel(x1+x,y1+y,WHITE);
    putpixel(x1+x,y1-y,WHITE);
}
void parabola_midpoint(int x1,int y1,float a)
{
    float d=1-2*a,x=0,y=0;
    while(y<=2*a)
    {
        print_pixel(x1,y1,x,y);
        if(d<0)
        {
            d+=3+2*y;
        }
        else
        {
            d+=3+2*y-2*a;
            x++;
        }
        y++;
    }
    d=1/4-2*a;
    while(x<=2*a)
    {
        print_pixel(x1,y1,x,y);
        if(d>0)
        {
            d+=-4*a;
        }
        else
        {
            d+=2+2*y-4*a;
            y++;
        }
        x++;
    }
}
void parabola_bresenham(int x1,int y1,float a)
{
    float d=4-8*a,x=0,y=0;
    while(y<=2*a)
    {
        print_pixel(x1,y1,x,y);
        if(d<0)
        {
            d+=2*(6+4*y);
        }
        else
        {
            d+=2*(6+4*y-4*a);
            x++;
        }
        y++;
    }
    d=1-8*a;
    while(x<=2*a)
    {
        print_pixel(x1,y1,x,y);
        if(d>0)
        {
            d+=-16*a;
        }
        else
        {
            d+=4*(2+2*y-4*a);
            y++;
        }
        x++;
    }
}
int main()
{
    int i=0,gm=DETECT,gd,x1,y1,x2,y2;
    float a;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    while(i++<100)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,x1,y1);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,x2,y2);
        a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        line(x1-400,y1,x1+400,y1);
        line(x1,y1-400,x1,y1+400);
        parabola_midpoint(x1,y1,a);
       // parabola_bresenham(x1,y1,a);
    }
    getch();
    closegraph();
    return 0;
}
