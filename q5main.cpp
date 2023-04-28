#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
const int WINDOW_HEIGHT = 1000;
typedef struct tdcPt
{
    int x;
    int y;
} dcPt;
typedef struct tEdge
{
    int yUpper;
    float xIntersect, dxPerScan;
    struct tEdge *next;
} Edge;

// Vertices: Array of structures.
dcPt vertex[5] = {{200, 500}, {300, 250}, {270, 230}, {320, 200}, {360, 290}};
void insertEdge(Edge *list, Edge *edge)
{
    Edge *p, *q = list;
    p = q->next;
    while (p != NULL)
    {
        if (edge->xIntersect < p->xIntersect)
            p = NULL;
        else
        {
            q = p;
            p = p->next;
        }
    }
    edge->next = q->next;
    q->next = edge;
}
int yNext(int k, int cnt, dcPt *pts)
{
    int j;
    if ((k + 1) > (cnt - 1))
        j = 0;
    else
        j = k + 1;
    while (pts[k].y == pts[j].y)
    {
        if ((j + 1) > (cnt - 1))
            j = 0;
        else
            j++;
    }
    return (pts[j].y);
}
void makeEdgeRec(dcPt lower, dcPt upper, int yComp, Edge *edge, Edge *edges[])
{
    edge->dxPerScan = (float)(upper.x - lower.x) / (upper.y - lower.y);
    edge->xIntersect = lower.x;
    if (upper.y < yComp)
        edge->yUpper = upper.y - 1;
    else
        edge->yUpper = upper.y;
    insertEdge(edges[lower.y], edge);
}
void buildEdgeList(int cnt, dcPt *pts, Edge *edges[])
{
    Edge *edge;
    dcPt v1, v2;
    int i, yPrev = pts[cnt - 2].y;
    v1.x = pts[cnt - 1].x;
    v1.y = pts[cnt - 1].y;
    for (int i = 0; i < cnt; i++)
    {
        v2 = pts[i];
        if (v1.y != v2.y) // nonhorizontal line
        {
            edge = (Edge *)malloc(sizeof(Edge));
            if (v1.y < v2.y) // upgoing edge
                makeEdgeRec(v1, v2, yNext(i, cnt, pts), edge, edges);
            else //
                makeEdgeRec(v2, v1, yPrev, edge, edges);
        }
        yPrev = v1.y;
        v1 = v2;
    }
}
void buildActiveList(int scan, Edge *active, Edge *edges[])
{
    Edge *p, *q;
    p = edges[scan]->next;
    while (p)
    {
        q = p->next;
        insertEdge(active, p);
        p = q;
    }
}
void fillScan(int scan, Edge *active)
{
    Edge *p1, *p2;
    int i;
    p1 = active->next;
    while (p1)
    {
        p2 = p1->next;
        for (i = p1->xIntersect; i < p2->xIntersect; i++)
            putpixel((int)i, scan, GREEN);
        p1 = p2->next;
    }
}
void deleteAfter(Edge *q)
{
    Edge *p = q->next;
    q->next = p->next;
    free(p);
}
void updateActiveList(int scan, Edge *active)
{
    Edge *q = active, *p = active->next;
    while (p)
    {
        if (scan >= p->yUpper)
        {
            p = p->next;
            deleteAfter(q);
        }
        else
        {
            p->xIntersect = p->xIntersect + p->dxPerScan;
            q = p;
            p = p->next;
        }
    }
}
void resortActiveList(Edge *active)
{
    Edge *q, *p = active->next;
    active->next = NULL;
    while (p)
    {
        q = p->next;
        insertEdge(active, p);
        p = q;
    }
}
void scanFill(int cnt, dcPt *pts)
{
    Edge *edges[WINDOW_HEIGHT], *active;
    int i, scan;
    for (i = 0; i < WINDOW_HEIGHT; i++)
    {
        edges[i] = (Edge *)malloc(sizeof(Edge));
        ;
        edges[i]->next = NULL;
    }
    buildEdgeList(cnt, pts, edges);
    active = (Edge *)malloc(sizeof(Edge));
    ;
    active->next = NULL;
    for (scan = 0; scan < WINDOW_HEIGHT; scan++)
    {
        buildActiveList(scan, active, edges);
        if (active->next)
        {
            fillScan(scan, active);
            updateActiveList(scan, active);
            resortActiveList(active);
        }
    }
    free(edges[WINDOW_HEIGHT]);
    free(active);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    float X = getmaxx(), Y = getmaxy();
    float x_mid = X / 2;
    float y_mid = Y / 2;
    cleardevice();
    scanFill(5, vertex);
    getch();
    closegraph();
    return 0;
}
