#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
using namespace std;
double x1, x2, z1, z2;
void draw_cube(double edge[20][3])
{
    int i;
    cleardevice();
    for (i = 0; i < 19; i++)
    {
        x1 = edge[i][0] + edge[i][2] * (cos(2.3562));
        z1 = edge[i][1] - edge[i][2] * (sin(2.3562));
        x2 = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
        z2 = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
        line(x1 + 320, 240 - z1, x2 + 320, 240 - z2);
    }
    line(320, 240, 320, 25);
    line(320, 240, 550, 240);
    line(320, 240, 150, 410);
}
void translate(double edge[20][3])
{
    int a, b, c;
    int i;
    cout << "Enter the Translation Factors : ";
    cin >> a >> b >> c;
    cleardevice();
    for (i = 0; i < 20; i++)
    {
        edge[i][0] += a;
        edge[i][0] += b;
        edge[i][0] += c;
    }
    draw_cube(edge);
}
void rotate(double edge[20][3])
{
    int n;
    int i;
    double temp, theta, temp1;
    cleardevice();
    cout << " 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis \n";
    cout << "Enter your choice : ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << " Enter The Angle ";
        cin >> theta;
        theta = (theta * 3.14) / 180;
        for (i = 0; i < 20; i++)
        {
            edge[i][0] = edge[i][0];
            temp = edge[i][1];
            temp1 = edge[i][2];
            edge[i][1] = temp * cos(theta) - temp1 * sin(theta);
            edge[i][2] = temp * sin(theta) + temp1 * cos(theta);
        }
        draw_cube(edge);
        break;
    case 2:
        cout << " Enter The Angle ";
        cin >> theta;
        theta = (theta * 3.14) / 180;
        for (i = 0; i < 20; i++)
        {
            edge[i][1] = edge[i][1];
            temp = edge[i][0];
            temp1 = edge[i][2];
            edge[i][0] = temp * cos(theta) + temp1 * sin(theta);
            edge[i][2] = -temp * sin(theta) + temp1 * cos(theta);
        }
        draw_cube(edge);
        break;
    case 3:
        cout << " Enter The Angle ";
        cin >> theta;
        theta = (theta * 3.14) / 180;
        for (i = 0; i < 20; i++)
        {
            edge[i][2] = edge[i][2];
            temp = edge[i][0];
            temp1 = edge[i][1];
            edge[i][0] = temp * cos(theta) - temp1 * sin(theta);
            edge[i][1] = temp * sin(theta) + temp1 * cos(theta);
        }
        draw_cube(edge);
        break;
    }
}
void reflect(double edge[20][3])
{
    int n;
    int i;
    cleardevice();
    cout << " 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis \n";
    cout << " Enter Your Choice : ";
    cin >> n;
    switch (n)
    {
    case 1:
        for (i = 0; i < 20; i++)
        {
            edge[i][0] = edge[i][0];
            edge[i][1] = -edge[i][1];
            edge[i][2] = -edge[i][2];
        }
        draw_cube(edge);
        break;
    case 2:
        for (i = 0; i < 20; i++)
        {
            edge[i][1] = edge[i][1];
            edge[i][0] = -edge[i][0];
            edge[i][2] = -edge[i][2];
        }
        draw_cube(edge);
        break;
    case 3:
        for (i = 0; i < 20; i++)
        {
            edge[i][2] = edge[i][2];
            edge[i][0] = -edge[i][0];
            edge[i][1] = -edge[i][1];
        }
        draw_cube(edge);
        break;
    }
}
void perspect(double edge[20][3])
{
    int n;
    int i;
    double p, q, r;
    cleardevice();
    cout << " 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis \n";
    cout << " Enter Your Choice : ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << " Enter P : ";
        cin >> p;
        for (i = 0; i < 20; i++)
        {
            edge[i][0] = edge[i][0] / (p * edge[i][0] + 1);
            edge[i][1] = edge[i][1] / (p * edge[i][0] + 1);
            edge[i][2] = edge[i][2] / (p * edge[i][0] + 1);
        }
        draw_cube(edge);
        break;
    case 2:
        cout << " Enter Q : ";
        cin >> q;
        for (i = 0; i < 20; i++)
        {
            edge[i][1] = edge[i][1] / (edge[i][1] * q + 1);
            edge[i][0] = edge[i][0] / (edge[i][1] * q + 1);
            edge[i][2] = edge[i][2] / (edge[i][1] * q + 1);
        }
        draw_cube(edge);
        break;
    case 3:
        cout << " Enter R : ";
        cin >> r;
        for (i = 0; i < 20; i++)
        {
            edge[i][2] = edge[i][2] / (edge[i][2] * r + 1);
            edge[i][0] = edge[i][0] / (edge[i][2] * r + 1);
            edge[i][1] = edge[i][1] / (edge[i][2] * r + 1);
        }
        draw_cube(edge);
        break;
    }
}
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\TURBOC3\BGI");
    int n;
    double
        edge[20][3] = {100, 0, 0, 100, 100, 0, 0, 100, 0, 0, 100, 100, 0, 0, 100, 0, 0, 0, 100,
                       0, 0,
                       100, 0, 100, 100, 75, 100, 75, 100, 100, 100, 100, 75, 100, 100, 0, 100, 100, 75,
                       100, 75, 100, 75, 100, 100, 0, 100, 100, 0, 100, 0, 0, 0, 0, 0, 0, 100, 100, 0, 100};
    cout << " 1.Draw Cube \n 2.Rotation \n 3.Reflection \n 4.Translation \n 5.Perspective Projection \n";
    cout << " Enter Your Choice : ";
    cin >> n;
    switch (n)
    {
    case 1:
        draw_cube(edge);
        break;
    case 2:
        rotate(edge);
        break;
    case 3:
        reflect(edge);
        break;
    case 4:
        translate(edge);
        break;
    case 5:
        perspect(edge);
        break;
    default:
        cout << " Invalid Choice ";
    }
    getch();
}
