#include "Object.h"


Object::Object()
{
    points = new Vertices();
}

Object::Object(Vertices* Sommet):points(Sommet){
}

Object::~Object()
{
	delete points;
    if(bID.set)
        bID.~BufferId();
}

Vertices *Object::GetVertices(){
	return points;
}


void Object::SetVertices(Vertices * Sommet){
    delete points;
    points = Sommet;
}

void Object::GenereVBO(){
    pair<int,double*>couleurs = points->getColorList(3);
    pair<int,double*>vert = points->getDataList(2);

    GLuint idVertex = 0;
    GLuint idColor = 1;

    for(int i=0;i<points->length();i++){
        indices.push_back(i);
    }
    indices.push_back(0);
    
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

void Object::ShowVBODefault(GLenum affichage){

    glBindVertexArray(bID.bIDVao);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glDrawElements(affichage, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    glBindVertexArray(0);
}