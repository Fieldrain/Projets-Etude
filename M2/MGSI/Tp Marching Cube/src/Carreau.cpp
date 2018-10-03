#include "Carreau.h"

Carreau::Carreau(vector<Vertex*> Points):
    points(Points)
{}

Carreau::~Carreau(){
    points.clear();
}

vector<Arrete*> Carreau::getArrete(Object* objects){
    vector<Arrete*> arretes;

    int configuration = 0;
    double* poids = new double[points.size()];


    for(int i=0;i<points.size();i++){
        Vertex* p = points[i];

        pair<bool,double> res = objects->In(p);
        poids[i] = res.second;


        if(res.first){
            configuration += (int)pow(2,i); 
        }
    }

    Vertex* A = points[0];
    double pA = poids[0];

    Vertex* B = points[1];
    double pB = poids[1];

    Vertex* C = points[2];
    double pC = poids[2];

    Vertex* D = points[3];
    double pD = poids[3];
    /*
        D---C
        |   |
        A---B
    */
    double Px=0.0;
    double Py=0.0;
    double Qx=0.0;
    double Qy=0.0;

    switch(configuration){
        case 0:
            // pas d'arrete
        break;
        case 1: // p est le point le plus en bas
            /*
                D----C
                |    |
                A*---B
            */

            Px= (*D)[0];
            Py= interpolation((*D)[1],(*A)[1],pD,pA);

            Qx= interpolation((*B)[0],(*A)[0],pB,pA);
            Qy= (*B)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 2:
            /*
                D----C
                |    |
                A----B*
            */

            Px= interpolation((*A)[0],(*B)[0],pA,pB);
            Py= (*A)[1];

            Qx= (*C)[0];
            Qy= interpolation((*C)[1],(*B)[1],pC,pB);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 3:
            /*
                D----C
                |    |
                A*---B*
            */

            Px= (*D)[0];
            Py= interpolation((*D)[1],(*A)[1],pD,pA);

            Qx= (*C)[0];
            Qy= interpolation((*C)[1],(*B)[1],pC,pB);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 4:
            /*
                D----C*
                |    |
                A----B
            */

            Px= interpolation((*D)[0],(*C)[0],pD,pC);
            Py= (*D)[1];

            Qx= (*B)[0];
            Qy= interpolation((*B)[1],(*C)[1],pB,pC);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 5:
            /*
                D----C*
                |    |
                A*---B
            */
            //1er arrete HG
            Px= (*D)[0];
            Py= interpolation((*D)[1],(*A)[1],pD,pA);

            Qx= interpolation((*D)[0],(*C)[0],pD,pC);
            Qy= (*D)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));

            //2eme arrete BD
            Px = interpolation((*B)[0],(*A)[0],pB,pA);
            Py = (*B)[1];

            Qx = (*B)[0];
            Qy = interpolation((*B)[1],(*C)[1],pB,pC);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 6:
            /*
                D----C*
                |    |
                A----B*
            */
            Px= interpolation((*A)[0],(*B)[0],pA,pB);
            Py= (*A)[1];

            Qx= interpolation((*D)[0],(*C)[0],pD,pC);
            Qy= (*D)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 7:
            /*
                D----C*
                |    |
                A*---B*
            */
            Px= (*D)[0];
            Py= interpolation((*D)[1],(*A)[1],pD,pA);

            Qx= interpolation((*D)[0],(*C)[0],pD,pC);
            Qy= (*D)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 8: 
            /*
                D*---C
                |    |
                A----B
            */
            Qx= interpolation((*C)[0],(*D)[0],pC,pD);
            Qy= (*C)[1];

            Px= (*A)[0];
            Py= interpolation((*A)[1],(*D)[1],pA,pD);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 9:
            /*
                D*---C
                |    |
                A*---B
            */
            Qx= interpolation((*C)[0],(*D)[0],pC,pD);
            Qy= (*C)[1];

            Px= interpolation((*B)[0],(*A)[0],pB,pA);
            Py= (*B)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 10:
            /*
                D*---C
                |    |
                A----B*
            */
            //1er arrete HD
            Qx= interpolation((*C)[0],(*D)[0],pC,pD);
            Qy= (*C)[1];

            Px= (*C)[0];
            Py= interpolation((*C)[1],(*B)[1],pC,pB);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
            //2eme arrete
            Qx = (*A)[0];
            Qy = interpolation((*A)[1],(*D)[1],pA,pD);

            Px = interpolation((*A)[0],(*B)[0],pA,pB);
            Py = (*A)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 11:
            /*
                D*---C
                |    |
                A*---B*
            */
            Qx= interpolation((*C)[0],(*D)[0],pC,pD);
            Qy= (*C)[1];

            Px= (*C)[0];
            Py= interpolation((*C)[1],(*B)[1],pC,pB);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 12:
            /*
                D*---C*
                |    |
                A----B
            */
            Qx= (*B)[0];
            Qy= interpolation((*B)[1],(*C)[1],pB,pC);

            Px= (*A)[0];
            Py= interpolation((*A)[1],(*D)[1],pA,pD);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 13:
            /*
                D*---C*
                |    |
                A*---B
            */
            Qx= (*B)[0];
            Qy= interpolation((*B)[1],(*C)[1],pB,pC);

            Px= interpolation((*B)[0],(*A)[0],pB,pA);
            Py= (*B)[1];

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 14:
            /*
                D*---C*
                |    |
                A----B*
            */
            Qx= interpolation((*A)[0],(*B)[0],pA,pB);
            Qy= (*A)[1];

            Px= (*A)[0];
            Py= interpolation((*A)[1],(*D)[1],pA,pD);

            arretes.push_back(new Arrete(new Vertex(dvec({Qx,Qy})),new Vertex(dvec({Px,Py}))));
        break;
        case 15:
            // pas d'arrete
        break;
    }

    return arretes;
}

double Carreau::interpolation(double v0,double v1,double p0,double p1){
    return v0 + (v1-v0)*((1.0-p0)/(p1-p0));
}
