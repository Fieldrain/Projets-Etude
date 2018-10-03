#include "Marching.h"

Marching::Marching(int L, int C) : 
    colonnes(C),
    lignes(L),
    points(new Vertices())
{
}

Marching::~Marching(){

}

void Marching::generateVBO(){
    pair<int,double*>couleurs = points->getColorList(3);
    pair<int,double*>vert = points->getDataList(2);


    if(!bID.set)
        bID.BufferID();

    glBindVertexArray(bID.bIDVao);
    
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        //vertex
        glBindBuffer(GL_ARRAY_BUFFER, bID.bIDVert);
        glBufferData(GL_ARRAY_BUFFER, vert.first, vert.second,GL_DYNAMIC_DRAW);
        glVertexPointer(P_SIZE, GL_DOUBLE, 0, (void*)0);

        //couleur
        glBindBuffer(GL_ARRAY_BUFFER, bID.bIDCoul);
        glBufferData(GL_ARRAY_BUFFER, couleurs.first, couleurs.second,GL_DYNAMIC_DRAW);
        glColorPointer(C_SIZE, GL_DOUBLE, 0, (void*)0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bID.bIDInd);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0],GL_DYNAMIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);

    delete vert.second;
    delete couleurs.second;
}

void Marching::CalculPoint(Object* objects){
    int width, height;
    glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);

    for(double i=0.0;i<height;i+=(double)(height/lignes)){
        for(double j=0.0;j<width;j+=(double)(width/colonnes)){
            Vertex* p = new Vertex(dvec({i,j}));
            if(objects->In(p).first){
                points->append(p);
                indices.push_back(points->length());
            }else{
                delete p;
            }
        }
    }

    generateVBO();
}

void Marching::ShowPoint(){
    glBindVertexArray(bID.bIDVao);
        glDrawElements(GL_POINTS, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Marching::CalculArrete(Object* objects){
    int width, height;
    glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);

    if(!grille)
        grille = new Grille(lignes,colonnes, (double)height, (double)width);

    delete points;
    points = new Vertices();
    indices.clear();
    vector<Arrete*> arretes = grille->getListArrete(objects);

    for(Arrete* a:arretes){
        
        points->append(a->getDebut());
        indices.push_back(points->length());

        points->append(a->getFin());
        indices.push_back(points->length());

    }

    generateVBO();
}

void Marching::ShowArrete(){
    glBindVertexArray(bID.bIDVao);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glDrawArrays(GL_LINES,0,(GLsizei)indices.size());

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);
}