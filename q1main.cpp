
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// Function to implement Bresenham's line drawing algorithm
void bresline(int x1, int y1, int x2, int y2)
{
    int dx, dy, P, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    P = 2 * dy - dx;
    while (x <= x2)
    {
        if (P >= 0)
        {
            putpixel(x, y, YELLOW);
            y = y + 1;
            P = P + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, YELLOW);
            P = P + 2 * dy;
        }
        x = x + 1;
    }
}
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\Dev-Cpp\\lib");
    setbkcolor(BLACK);
    cleardevice();
    int x1, x2, y1, y2;
    cout << " Bresenham's Line Drawing Algorithm \n\n";
    cout << " Enter the x co-ordinate of point 1: ";
    cin >> x1;
    cout << "\n Enter the y co-ordinate of point 1: ";
    cin >> y1;
    cout << "\n Enter the x co-ordinate of point 2: ";
    cin >> x2;
    cout << "\nEnter the y co-ordinate of point 2: ";
    cin >> y2;
    cleardevice();

    bresline(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
