#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int mat[3][3];
void dda_line(int x1, int y1, int x2, int y2, int col)
{
    int dx, dy, st;
    dx = x2 - x1;
    dy = y2 - y1;
    float y, x, xinc, yinc;
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    if (abs(dx) > abs(dy))
    {
        st = abs(dx);
    }
    else
    {
        st = abs(dy);
    }
    xinc = dx / st;
    yinc = dy / st;
    x = x1;
    y = y1;
    for (int i = 0; i < st; i++)
    {
        x += xinc;
        y += yinc;
        putpixel(ceil(x) + xmid, ymid - ceil(y), col);
    }
}
void rotate()
{
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    int c[3][2], l, m, i, j, k;
    int a[3][2] = {{200, 200}, {200, 100}, {100, 200}};
    int t[2][2] = {{0, 1}, {-1, 0}};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
        }
    }
    dda_line(a[0][0], a[0][1], a[1][0], a[1][1], YELLOW);
    dda_line(a[1][0], a[1][1], a[2][0], a[2][1], YELLOW);
    dda_line(a[2][0], a[2][1], a[0][0], a[0][1], YELLOW);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * t[k][j]);
            }
        }
    }
    dda_line(c[0][0], c[0][1], c[1][0], c[1][1], GREEN);
    dda_line(c[1][0], c[1][1], c[2][0], c[2][1], GREEN);
    dda_line(c[2][0], c[2][1], c[0][0], c[0][1], GREEN);
}
void reflection()
{
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    int c[3][2], l, m, i, j, k;
    int a[3][2] = {{200, 200}, {200, 100}, {100, 200}};
    int t[2][2] = {{0, -1}, {-1, 0}};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
        }
    }
    dda_line(a[0][0], a[0][1], a[1][0], a[1][1], YELLOW);
    dda_line(a[1][0], a[1][1], a[2][0], a[2][1], YELLOW);
    dda_line(a[2][0], a[2][1], a[0][0], a[0][1], YELLOW);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * t[k][j]);
            }
        }
    }
    dda_line(c[0][0], c[0][1], c[1][0], c[1][1], GREEN);
    dda_line(c[1][0], c[1][1], c[2][0], c[2][1], GREEN);
    dda_line(c[2][0], c[2][1], c[0][0], c[0][1], GREEN);
}
void scaling()
{
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    int c[3][2], l, m, i, j, k;
    int a[3][2] = {{20, 20}, {20, 10}, {10, 20}};
    int t[2][2] = {{5, 0}, {0, 5}};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
        }
    }
    dda_line(a[0][0], a[0][1], a[1][0], a[1][1], YELLOW);
    dda_line(a[1][0], a[1][1], a[2][0], a[2][1], YELLOW);
    dda_line(a[2][0], a[2][1], a[0][0], a[0][1], YELLOW);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * t[k][j]);
            }
        }
    }
    dda_line(c[0][0], c[0][1], c[1][0], c[1][1], GREEN);
    dda_line(c[1][0], c[1][1], c[2][0], c[2][1], GREEN);
    dda_line(c[2][0], c[2][1], c[0][0], c[0][1], GREEN);
}
void multi(int a[3][3], int b[3][3])
{
    int i, j, k;
    int c[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat[i][j] = c[i][j];
        }
    }
}
void reflection_arbitrary()
{
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    int a[3][3] = {{200, 200, 1}, {200, 100, 1}, {100, 200, 1}};
    int t[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int r[3][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    int ref[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    int rinv[3][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    int tinv[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 1, 1}};
    dda_line(a[0][0], a[0][1], a[1][0], a[1][1], YELLOW);
    dda_line(a[1][0], a[1][1], a[2][0], a[2][1], YELLOW);
    dda_line(a[2][0], a[2][1], a[0][0], a[0][1], YELLOW);
    multi(t, r);
    multi(mat, ref);
    multi(mat, rinv);
    multi(mat, tinv);
    multi(a, mat);
    dda_line(mat[0][0], mat[0][1], mat[1][0], mat[1][1], GREEN);
    dda_line(mat[1][0], mat[1][1], mat[2][0], mat[2][1], GREEN);
    dda_line(mat[2][0], mat[2][1], mat[0][0], mat[0][1], GREEN);
}
void rotation_arbitrary()
{
    int xmid, ymid;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    int c[3][3], i, j, k;
    int l[1][3] = {{200, 200, 1}};
    int a[3][3] = {{200, 200, 1}, {200, 100, 1}, {100, 200, 1}};
    int t[3][3] = {{1, 0, 0}, {0, 1, 0}, {-133, -133, 1}};
    int r[3][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    int tinv[3][3] = {{1, 0, 0}, {0, 1, 0}, {133, 133, 1}};
    dda_line(a[0][0], a[0][1], a[1][0], a[1][1], YELLOW);
    dda_line(a[1][0], a[1][1], a[2][0], a[2][1], YELLOW);
    dda_line(a[2][0], a[2][1], a[0][0], a[0][1], YELLOW);
    multi(t, r);
    multi(mat, tinv);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * mat[k][j]);
            }
        }
    }
    dda_line(c[0][0], c[0][1], c[1][0], c[1][1], GREEN);
    dda_line(c[1][0], c[1][1], c[2][0], c[2][1], GREEN);
    dda_line(c[2][0], c[2][1], c[0][0], c[0][1], GREEN);
}
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\TURBOC3\BGI");
    int n, m;
    cout << " 1.Rotation \n 2.Reflection \n 3.Scaling \n 4.Reflection about an arbitrary axis";
    cout << " 5.Rotation about an arbitrary point";
    cout << "Enter your choice :\n";
    cin >> n;
    switch (n)
    {
    case 1:
        rotate();
        break;
    case 2:
        reflection();
        break;
    case 3:
        scaling();
        break;
    case 4:
        reflection_arbitrary();
        break;
    case 5:
        rotation_arbitrary();
        break;
    default:
        cout << "Invalid Choice";
    }
    getch();
}
