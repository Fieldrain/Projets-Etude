#include "ElementPlan.h"

ElementPlan::ElementPlan(Vect pointC, Vect normalPlan) : PointC(pointC), NormalPlan(normalPlan)
{
}

ElementPlan::~ElementPlan()
{
}

PointIntersection ElementPlan::CalculIntersection(Rayon *rayon, map<string, double> calculs)
{

    PointIntersection p;
    p.Double = false;

    if (calculs["t"])
        p.T = calculs["t"];
    else
    {
        p.T = (PointC - rayon->GetOrigin()).dot(NormalPlan)/rayon->GetDirection().dot(NormalPlan);
    }
    
    p.CoordPoint = rayon->T(p.T);
    p.Distance = p.CoordPoint.distance(rayon->GetOrigin());

    return p;
}

Vect ElementPlan::Normal(PointIntersection point)
{
    return NormalPlan.normalize();
}

void ElementPlan::Affiche()
{
    glBegin(GL_QUADS);
    if (NormalPlan[0] != 0)
    {
        glVertex3f(PointC[0], 100 + PointC[1], -100 + PointC[2]);
        //top left
        glVertex3f(PointC[0], -100 + PointC[1], -100 + PointC[2]);
        //bottom left
        glVertex3f(PointC[0], -100 + PointC[1], 100 + PointC[2]);
        //bottom right
        glVertex3f(PointC[0], 100 + PointC[1], 100 + PointC[2]);
        //top right
    }
    else if (NormalPlan[1] != 0)
    {
        glVertex3f(-100 + PointC[0], PointC[1], 100 + PointC[2]);
        //top left
        glVertex3f(-100 + PointC[0], PointC[1], -100 + PointC[2]);
        //bottom left
        glVertex3f(100 + PointC[0], PointC[1], -100 + PointC[2]);
        //bottom right
        glVertex3f(100 + PointC[0], PointC[1], 100 + PointC[2]);
        //top right
    }
    else
    {
        glVertex3f(-100 + PointC[0], 100 + PointC[1], PointC[2]);
        //top left
        glVertex3f(-100 + PointC[0], -100 + PointC[1], PointC[2]);
        //bottom left
        glVertex3f(100 + PointC[0], -100 + PointC[1], PointC[2]);
        //bottom right
        glVertex3f(100 + PointC[0], 100 + PointC[1], PointC[2]);
        //top right
    }
    glEnd();

    
}
