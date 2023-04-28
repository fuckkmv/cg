#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void circlePlotPoints(int, int, int, int);
int xmid, ymid;
void circleMidpoint(int xCenter, int yCenter, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    // circlePlotPoints (x, y, xCenter, yCenter);
    while (x <= y)
    {
        circlePlotPoints(x, y, xCenter, yCenter);
        if (p < 0)
        {
            p += (2 * x) + 1;
        }
        else
        {
            p += (2 * (x - y)) + 1;
            y--;
        }
        x++;
    }
}
void circlePlotPoints(int x, int y, int xCenter, int yCenter)
{
    putpixel(xCenter + x, yCenter + y, YELLOW);
    putpixel(xCenter - x, yCenter + y, YELLOW);
    putpixel(xCenter + x, yCenter - y, YELLOW);
    putpixel(xCenter - x, yCenter - y, YELLOW);
    putpixel(xCenter + y, yCenter + x, YELLOW);
    putpixel(xCenter - y, yCenter + x, YELLOW);
    putpixel(xCenter + y, yCenter - x, YELLOW);
    putpixel(xCenter - y, yCenter - x, YELLOW);
}
int main()
{
    int x, y;
    float r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    cout << " Mid-point Circle Algorithm ";
    cout << " Enter the x co-ordinate of centre : ";
    cin >> x;
    cout << " Enter the y co-ordinate of centre : ";
    cin >> y;
    cout << " Enter the radius : ";
    cin >> r;
    xmid = getmaxx() / 2;
    ymid = getmaxy() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    circleMidpoint(x + xmid, ymid - y, r);
    getch();
    closegraph();
    return 0;
}
