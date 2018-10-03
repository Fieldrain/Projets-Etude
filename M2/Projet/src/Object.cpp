#include "Object.h"


Object::Object()
{
    points = new Vertices();
}

Object::Object(Vertices* Sommet):points(Sommet){
}

Object::Object(Vertices* Sommet, vector<int> Indices):points(Sommet),indices(Indices){
}

Object::~Object()
{
	delete points;
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

Tangentes* Object::getTangentes(){
    return tangentes;
}

void Object::SetVertices(Vertices * Sommet){
    delete points;
    points = Sommet;
}

void Object::SetIndices(vector<int> Indices){
    indices.clear();
    indices = Indices;
}

void Object::SetTangentes(Tangentes* newTangentes){
    tangentes = newTangentes;
}

void Object::SetUv(Uv* newUv){
    uv = newUv;
}

void Object::GenereVBO(Shader* shader){
    pair<int,double *>couleurs = points->getColorList(3);
    pair<int,double *>vert = points->getDataList(3);
    pair<int,pair<double*,double*>> tang = tangentes->getList(3);
    pair<int,double*> coordUv = uv->getListIndice(3);
    pair<int,double*> valUv = uv->getListUv(2);

    GLuint idVertex = shader->getLocation("vVertex");
    GLuint idColor = shader->getLocation("vColor");
    GLuint idUv = shader->getLocation("vUv");
    
    ofstream myfile;
    myfile.open ("test.txt");
    myfile << points->length() <<endl;
    myfile << tangentes->length() <<endl;
    myfile << uv << endl;
    myfile.close();

    if(!bID.set)
        bID.BufferID();

    glBindVertexArray(bID.bIDVao);
    
    //vbo
    //vertex
    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDVert);
    glBufferData(GL_ARRAY_BUFFER, vert.first, vert.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idVertex, P_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );
    
    //couleur
    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDCoul);
    glBufferData(GL_ARRAY_BUFFER, couleurs.first, couleurs.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idColor, C_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

    //uv
    glBindBuffer(GL_ARRAY_BUFFER, bID.bIDUv);
    glBufferData(GL_ARRAY_BUFFER, valUv.first, valUv.second,GL_DYNAMIC_DRAW);
    glVertexAttribPointer(idUv, 2, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bID.bIDInd);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0],GL_DYNAMIC_DRAW);

    //textures
    // pour les indice uv
    int tailleIndice = (int)sqrt(uv->lengthIndice());
    glBindTexture(GL_TEXTURE_2D, bID.bIDUvIndice);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,tailleIndice,tailleIndice, 0, GL_RGB,GL_DOUBLE,coordUv.second);
   
    // pour les tangentes
    int tailleTangente = tangentes->length();
    glBindTexture(GL_TEXTURE_1D, bID.bIDTang1);
    glTexImage1D(GL_TEXTURE_1D, 0, 3, tailleTangente, 0, GL_RGB,GL_DOUBLE,tang.second.first);

    glBindTexture(GL_TEXTURE_1D, bID.bIDTang2);
    glTexImage1D(GL_TEXTURE_1D, 0, 3, tailleTangente, 0, GL_RGB,GL_DOUBLE,tang.second.second);

    glEnableVertexAttribArray(idVertex);
    glEnableVertexAttribArray(idColor);
    glEnableVertexAttribArray(idUv);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    delete vert.second;
    delete couleurs.second;
    delete tang.second.first;
    delete tang.second.second;
    delete coordUv.second;
    delete valUv.second;

}

/*
*   Pour appliquer les transformations on créer une nouvelle liste de point (vertices)
*   On parcours les points (vertex) d'origine pour recuperer le vecteur colonne 
*   On ajoute a la nouvelle liste de points un nouveau point mais transformer
*   Tous cela permet de n'avoir qu'une seule instance objet de notre forme et d'etre sur qu'elle ne soit pas modifier au cours du temps
*/
Vertices * Object::ApplyMat(Mat<double> transformation){
    return (*points) * transformation;
}

vector<pair<Col<double>,Col<double>>> Object::CalculTangentes(vector<pair<Col<double>,Col<double>>> tangentesInit,Mat<double> transformation){
    vector<pair<Col<double>,Col<double>>> tangentes;

    for(pair<Col<double>,Col<double>> tang : tangentesInit){
        pair<Col<double>,Col<double>> newTang;

        newTang.first = normalise(transformation*tang.first);
        newTang.second = normalise(transformation*tang.second);

        tangentes.push_back(newTang);
    }
    return tangentes;
}

void Object::ShowDefault(GLenum affichage,int pas){
    glPushMatrix();
    
        if(!indices.empty()){//parcours avec indice
            for(int n=0;n<indices.size()-pas;n=n+pas){
                glBegin(affichage);
                    for(int i=0; i<pas;i++){
                            Vertex* vertex_1 = (*points)[indices[n+i]];
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

void Object::ShowTangentes(int repere){
    for(int i=0;i<indices.size();i++){
        Vertex* vertex_1 = (*points)[indices[i]];

        pair<Col<double>,Col<double>> tangente = (*tangentes)[indices[i]];
        
        if(repere == 0){
            vertex_1->setData(2,0);
            tangente.first(2) = 0;
            tangente.second(2) = 0;
        }

        glBegin(GL_LINES);
            glColor3d(1.0, 0.0, 0.0);
            glVertex3d((*vertex_1)[0], (*vertex_1)[1], (*vertex_1)[2]);
            glVertex3d((*vertex_1)[0] + tangente.first(0)*0.25, 
                       (*vertex_1)[1] + tangente.first(1)*0.25,
                       (*vertex_1)[2] + tangente.first(2)*0.25);
        glEnd();

        glBegin(GL_LINES);
            glColor3d(0.0, 1.0, 0.0);
            glVertex3d((*vertex_1)[0], (*vertex_1)[1], (*vertex_1)[2]);
            glVertex3d((*vertex_1)[0] + tangente.second(0) *0.25, 
                       (*vertex_1)[1] + tangente.second(1) *0.25,
                       (*vertex_1)[2] + tangente.second(2) *0.25);
        glEnd();

        tangente.first.resize(3);
        tangente.second.resize(3);

        Col<double> n = normalise(cross(tangente.first,tangente.second));

        glBegin(GL_LINES);
            glColor3d(0.0, 0.0, 1.0);
            glVertex3d((*vertex_1)[0], (*vertex_1)[1], (*vertex_1)[2]);
            glVertex3d((*vertex_1)[0] + n(0) *0.25, 
                       (*vertex_1)[1] + n(1) *0.25,
                       (*vertex_1)[2] + n(2) *0.25);
        glEnd();
    }
}
