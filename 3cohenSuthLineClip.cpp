#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
float x_mid, y_mid;
// Defining region codes
const int TOP = 1;    // 0001
const int BOTTOM = 2; // 0010
const int RIGHT = 4;  // 0100
const int LEFT = 8;   // 1000
// Defining x_max, y_max and x_min, y_min for clipping rectangle.
const int x_max = 300;
const int y_max = 300;
const int x_min = 80;
const int y_min = 80;
// Function to compute region code for a point(x, y).
int ComputeOutCode(double x, double y)
{
    // Point initialized as being inside the clipping window.
    int code = 0;
    if (y > y_max)
        code |= TOP;
    else if (y < y_min)
        code |= BOTTOM;
    if (x > x_max)
        code |= RIGHT;
    else if (x < x_min)
        code |= LEFT;
    return code;
}
// Implementing Cohen-Sutherland algorithm.
void CohenSutherlandLineClipAndDraw(double x1, double y1, double x2,
                                    double y2)
{
    // Initialize line as outside the clipping window.
    bool accept = false, done = false;

    // Compute region codes for P1, P2.
    int code1 = ComputeOutCode(x1, y1);
    int code2 = ComputeOutCode(x2, y2);
    do
    {
        if (!(code1 | code2))
        {
            // Trivial accept and exit.
            accept = true;
            done = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside clipping window, so trivial reject.
            break;
        }
        else
        {
            /* Failed both tests, so calculate the line segment to clip:
            from an outside point to an intersection with clip edge.
           */
            double x, y;
            int code_out;

            // At least one endpoint is outside the clip rectangle, pick it.
            code_out = (code1 != 0) ? code1 : code2;
            // Now, find intersection point.
            // Using formulas: y = y1 + slope * (x - x1), x = x1 + (1 / slope) * (y - y1).
            if (code_out & TOP)
            {
                // Point is above the clipping window.
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // Point is below the clipping window.
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // Point is to the right of clipping window.
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // Point is to the left of clipping window.
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            // Now we move outside point to intersection point to clip.
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = ComputeOutCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = ComputeOutCode(x2, y2);
            }
        }
    } while (done == false);
    if (accept)
    {
        // Drawing the clipped line.
        cout << "Line accepted from (" << x1 << ", " << y1 << ") to (" << x2
             << ", " << y2 << ")" << endl;
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
    else
        cout << "Line rejected" << endl;
}
// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    float X = getmaxx(), Y = getmaxy();
    float x_mid = X / 2;
    float y_mid = Y / 2;
    setcolor(WHITE);
    outtextxy(30, 30, "Cohen-Sutherland Line Clipping Algorithm");
    // Drawing Window using Lines
    setcolor(YELLOW);
    line(x_min, y_min, x_max, y_min);
    line(x_max, y_min, x_max, y_max);
    line(x_max, y_max, x_min, y_max);
    line(x_min, y_max, x_min, y_min);
    setcolor(GREEN);
    // First Line segment
    // P1 = (250, 320), P2 = (330, 270)
    line(250, 320, 330, 270);
    CohenSutherlandLineClipAndDraw(250, 320, 330, 270);
    // Second Line segment
    // P1 = (80, 80), P2 = (150, 150)
    CohenSutherlandLineClipAndDraw(100, 100, 150, 150);
    // Third Line segment
    // P1 = (290, 310), P2 = (320, 500)
    setcolor(GREEN);
    line(290, 310, 300, 400);
    CohenSutherlandLineClipAndDraw(290, 310, 320, 400);

    // Fourth Line segment
    // P1 = (450, 450), P2 = (500, 500)
    setcolor(GREEN);
    line(350, 150, 450, 250);
    CohenSutherlandLineClipAndDraw(350, 150, 450, 250);

    getch();
    closegraph();
    return 0;
}
