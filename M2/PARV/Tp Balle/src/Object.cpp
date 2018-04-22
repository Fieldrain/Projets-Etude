#include "Object.h"


Object::Object()
{
    points = new Vertices();
    normales = new Vertices();
}

Object::Object(Vertices* Sommet):points(Sommet){
}

Object::Object(Vertices* Sommet, vector<int> Indices):points(Sommet),indices(Indices){
}

Object::~Object()
{
	delete points;
    delete normales;
	indices.clear();
    if(bID.set)
        bID.~BufferId();
}

Vertices *Object::GetVertices(){
	return points;
}

vector<int> Object::GetIndices(){
	return indices;
}

void Object::SetVertices(Vertices * Sommet){
    delete points;
    points = Sommet;
}

void Object::SetIndices(vector<int> Indices){
    indices.clear();
    indices = Indices;
}

void Object::GenereVBO(Shader* shader){
    pair<int,double *>couleurs = points->getColorList(3);
    pair<int,double *>vert = points->getDataList(3);
    pair<int,double *>normal = normales->getDataList(3);

    GLuint idVertex = shader->getLocation("vVertex");
    GLuint idColor = shader->getLocation("vColor");
    GLuint idNormal = shader->getLocation("vNormal");

    
    if(!bID.set)
        bID.BufferID();

    glBindVertexArray(bID.bIDVao);
    
    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDVert);
    glBufferData(GL_ARRAY_BUFFER, vert.first, vert.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idVertex, P_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDCoul);
    glBufferData(GL_ARRAY_BUFFER, couleurs.first, couleurs.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idColor, C_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDNorm);
    glBufferData(GL_ARRAY_BUFFER, normal.first, normal.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idNormal, P_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bID.bIDInd);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0],GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(idVertex);
    glEnableVertexAttribArray(idColor);
    glEnableVertexAttribArray(idNormal);
    

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    delete vert.second;
    delete couleurs.second;
    delete normal.second;

}

/*
*   Pour appliquer les transformations on créer une nouvelle liste de point (vertices)
*   On parcours les points (vertex) d'origine pour recuperer le vecteur colonne 
*   On ajoute a la nouvelle liste de points un nouveau point mais transformer
*   Tous cela permet de n'avoir qu'une seule instance objet de notre forme et d'etre sur qu'elle ne soit pas modifier au cours du temps
*/

void Object::ShowDefault(GLenum affichage,int pas){
    glPushMatrix();
    
        if(!indices.empty()){//parcours avec indice
            for(int n=0;n<indices.size()-pas;n=n+pas){
                glBegin(affichage);
                    for(int i=0; i<pas;i++){
                        Vertex* vertex_1  = (*points)[indices[n+i]];
                        vertex_1->printGL();
                    }
                glEnd();	
            }
        }else{//parcours sans indice
            for(int n=0;n<points->length()-pas;n=n+pas){
                glBegin(affichage);
                    for(int i=0; i<pas;i++){
                        Vertex* vertex_1 = (*points)[i];
                        vertex_1->printGL();
                    }
                glEnd();	
            }
        }
        
    glPopMatrix();
}

void Object::ShowVBODefault(GLenum affichage){

    glBindVertexArray(bID.bIDVao);
        glDrawElements(affichage, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}