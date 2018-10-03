#include "BoundingBox.h"

BoundingBox::BoundingBox(Object* FormeOrigine) : formeOrigine(FormeOrigine){
    ComputeST();
    CreateControlPoint();
}

BoundingBox::~BoundingBox(){

}

void BoundingBox::ComputeST(){

    // cherche S et T avec obb
    // met point dans une matrice de covariance
    Mat<double> covariance = formeOrigine->GetVertices()->getMatCovariance();

    // calcule les vecteurs propre
    Col<double> eigval;
    Mat<double> eigvec;
    
    bool find = eig_sym(eigval, eigvec, covariance);
    if(find){
        uvec indices = sort_index(eigval,"descend");
        Col<double> v0 = eigvec.col(indices(0));
        Col<double> v1 = eigvec.col(indices(1));

        Col<double> r = normalise(v0);
        Col<double> u = normalise(v1);

        Mat<double> transfo = dmat(3,3,fill::eye);
        transfo(0,0) = r(0);
        transfo(1,0) = r(1);

        transfo(0,1) = u(0);
        transfo(1,1) = u(1);

        Col<double> Pmin = dvec({10000,10000,0});
        Col<double> Pmax = dvec({-10000,-10000,0});

        for(Vertex* v : formeOrigine->GetVertices()->getList()){
            Col<double> p2 = dvec(2,fill::zeros);

            p2(0) = dot(r,v->getData());
            p2(1) = dot(u,v->getData());

            if(p2(0) < Pmin(0))
                Pmin(0) = p2(0);

            if(p2(1) < Pmin(1))
                Pmin(1) = p2(1);

            if(p2(0) > Pmax(0))
                Pmax(0) = p2(0);

            if(p2(1) > Pmax(1))
                Pmax(1) = p2(1);
        }

        Col<double> Pcen = (Pmax+Pmin)/2.0;

        transfo(2,0) = dot(transfo.col(0),Pcen);
        transfo(2,1) = dot(transfo.col(1),Pcen);

        Col<double> P0_local = Pmax+dvec({10.0,10.0,0});
        Col<double> T_local = dvec({Pmax(0)+10,Pmin(1)-10,0});
        Col<double> S_local = dvec({Pmin(0)-10,Pmax(1)+10,0});

        Col<double> P0_global = (transfo * P0_local);
        Col<double> S_global = (transfo * S_local);
        Col<double> T_global = (transfo * T_local);

        P0 = dvec({P0_global(0),P0_global(1)});
        S = dvec({S_global(0),S_global(1)});
        T = dvec({T_global(0),T_global(1)});

    }

    // creation forme dans repere ST
    Vertices* verticesRepereST = new Vertices();

    for(Vertex* v : formeOrigine->GetVertices()->getList()){
        Col<double> P = v->getData();

        double s = dot(T,(P-P0))/dot(T,S);
        double t = dot(S,(P-P0))/dot(S,T);

        verticesRepereST->append(new Vertex(dvec({s,t})));
    }

    formeRepereST = new Forme(verticesRepereST);
}

void BoundingBox::CreateControlPoint(){

    for(int i=0;i<=lignes;i++){
        vector<Vertex*> pC;

        double distanceY = sqrt(pow(T(0)-P0(0),2)+pow(T(1)-P0(1),2));
        double Pijy = P0(1) + ((double)i*(distanceY/(double)lignes));

        for(int j=0;j<=colonnes;j++){

            double distanceY = sqrt(pow(S(0)-P0(0),2)+pow(S(1)-P0(1),2));

            double Pijx = P0(0) + ((double)j*(distanceY/(double)colonnes));
            Col<double> Pij = dvec({Pijx,Pijy});
            
            pC.push_back(new Vertex(Pij,dvec({1.0,1.0,0.0}))); 
        }
        pointsControles.push_back(pC);
    }
}

void BoundingBox::Deform(){
    Vertices* verticesDeformer = new Vertices();

    for(Vertex* v : formeRepereST->GetVertices()->getList()){
        verticesDeformer->append(BezierInterpolation(v));
    }

    formeDeformer = new Forme(verticesDeformer);
    formeDeformer->GenereVBO();
}

Vertex* BoundingBox::BezierInterpolation(Vertex* Pst){
    double s = (*Pst)[0];
    double t = (*Pst)[1];

    Col<double> newPoint = dvec(2,fill::zeros);
    for(int i=0;i<=lignes;i++){

        Col<double> pT = dvec(2,fill::zeros);
        for(int j=0;j<=colonnes;j++){
            double bernJCT = bernstein(colonnes,j,t);

            Vertex* pointControle = pointsControles[i][j];
            pT += bernJCT * pointControle->getData();
        }

        double bernILS = bernstein(lignes,i,s);
        newPoint += bernILS * pT;
    }

    return new Vertex(newPoint);
}

double BoundingBox::factorial(int n){
    if (n == 0) 
        return (1);
    else
        return (n * factorial(n - 1));
}

double BoundingBox::bernstein(double n, double i, double t){
    double binominal, bern;
    binominal = factorial(n) / (factorial(i) * factorial(n - i));

    bern = binominal * pow(t, i) * pow((1 - t), (n - i));
    return bern;
}

void BoundingBox::Show(){
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glColor3d(1, 0, 0);
        glVertex2d(P0(0), P0(1));
        glColor3d(0, 1, 0);
        glVertex2d(S(0), S(1));
        glColor3d(0, 0, 1);
        glVertex2d(T(0), T(1));
    glEnd();
    ShowControlPoint();
    if(formeDeformer)
        formeDeformer->ShowVBO();
}

void BoundingBox::ShowControlPoint(){
    glPointSize(4.0);
    glBegin(GL_POINTS);
        for(vector<Vertex*> lignes : pointsControles){
            for(Vertex* v : lignes){
                v->printGL();
            }
        }
    glEnd();
}

void BoundingBox::MovePointControl(int i,int j, double newX,double newY){
    Vertex* v = pointsControles[i][j];

    v->setData(0,newX);
    v->setData(1,newY);
}

bool BoundingBox::TestPoint(Vertex* point, double x,double y){

	if (x >= (*point)[0]-2.5 && x <= (*point)[0]+2.5 && y >= (*point)[1]-2.5 && y <= (*point)[1]+2.5){
        return true;
    }else{
        return false;
    }
}

int* BoundingBox::GetIndice(double x,double y){
    int* indices = new int[2];
    indices[0] = -1;
    indices[1] = -1;

    bool trouver = false;
    int i,j;

    for(i=0;i<=lignes && !trouver;i++){
        for(j=0;j<=colonnes && !trouver;j++){
            Vertex* v = pointsControles[i][j];
            trouver = TestPoint(v,x,y);
        }
    }

    if(trouver){
        indices[0] = i-1;
        indices[1] = j-1;
    }

    return indices;
}