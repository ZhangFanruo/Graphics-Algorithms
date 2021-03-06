#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
#define M_PI 3.14159
using namespace std;
struct point
{
    float x,y,z;
};
point translation(point p,int dx,int dy,int dz)
{
    float a[4][1]= {p.x,p.y,p.z,1},tran[4][4]= {{1,0,0,dx},{0,1,0,dy},{0,0,1,dz},{0,0,0,1}},result[4][1]= {0,0,0,0};
    int i,j,k;
    for(i=0; i<4; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<4; k++)
                result[i][j]+=tran[i][k]*a[k][j];
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    p.z=result[2][0];
    return p;
}
point rotation(point p,int ang,int about)
{
    float angle=ang*M_PI/180;
    float a[4][1]= {p.x,p.y,p.z,1},result[4][1]= {0,0,0,0};
    float rot_z[4][4]= {{cos(angle),-sin(angle),0,0},{sin(angle),cos(angle),0,0},{0,0,1,0},{0,0,0,1}};
    float rot_x[4][4]= {{1,0,0,0},{0,cos(angle),-sin(angle),0},{0,sin(angle),cos(angle),0},{0,0,0,1}};
    float rot_y[4][4]= {{cos(angle),0,sin(angle),0},{0,1,0,0},{-sin(angle),0,cos(angle),0},{0,0,0,1}};
    int i,j,k;
    for(i=0; i<4; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<4; k++)
            {
                if(about==1)
                result[i][j]+=rot_x[i][k]*a[k][j];
                else if(about==2)
                    result[i][j]+=rot_y[i][k]*a[k][j];
                else if(about==3)
                    result[i][j]+=rot_z[i][k]*a[k][j];
            }
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    p.z=result[2][0];
    cout<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
    return p;
}
point scaling(point p,int sx,int sy,int sz)
{
    float a[4][1]= {p.x,p.y,p.z,1},sca[4][4]= {{sx,0,0,0},{0,sy,0,0},{0,0,sz,0},{0,0,0,1}},result[4][1]= {0,0,0,0};
    int i,j,k;
    for(i=0; i<4; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<4; k++)
                result[i][j]+=sca[i][k]*a[k][j];
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    p.z=result[2][0];
    return p;
}
int main()
{
    int gm=DETECT,gd,i=0;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    point p[10];
    p[0].x=100;p[1].x=200;p[2].x=200;p[3].x=100;
    p[0].y=100;p[1].y=100;p[2].y=200;p[3].y=200;
    p[0].z=100;p[1].z=100;p[2].z=100;p[3].z=100;
    p[4].x=p[0].x;p[4].y=p[0].y;p[4].z=p[0].z;
    for(i=0; i<=3; i++)
    {
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
    float a=p[0].x,b=p[0].y,c=p[0].z;
    for(i=0; i<=3; i++)
    {
        p[i]=translation(p[i],-a,-b,-c);
    }
    p[i].x=p[0].x;   p[i].y=p[0].y;    p[i].z=p[0].z;
    for(i=0; i<=4; i++)
    {
        p[i]=rotation(p[i],10,3);
    }
    for(i=0; i<=3; i++)
    {
        p[i]=translation(p[i],a,b,c);
    }
    p[i].x=p[0].x;   p[i].y=p[0].y;    p[i].z=p[0].z;
    getch();
    for(i=0; i<=3; i++)
    {
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
    getch();
    closegraph();
    return 0;
}
