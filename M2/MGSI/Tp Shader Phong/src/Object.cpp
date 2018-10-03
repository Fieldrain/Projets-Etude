#include "Object.h"


Object::Object()
{
    points = new Vertices();
    normales = new Vertices();
    uv = new Vertices();
}

Object::~Object()
{
	delete points;
    delete normales;
    delete uv;
    delete indices;
    if(bID.set)
        bID.~BufferId();
}

void Object::GenereVBO(Shader* shader){
    pair<int,double*> couleurs = points->getColorList();
    pair<int,double*> vert = points->getDataList();
    pair<int,double*> norm = normales->getDataList();
    pair<int,double*> coordText = uv->getDataList();

    GLuint idVertex = shader->getLocation("vVertex");
    GLuint idColor = shader->getLocation("vColor");
    GLuint idNormal = shader->getLocation("vNormal");
    GLuint idUv = shader->getLocation("vUV");
    
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
        glBufferData(GL_ARRAY_BUFFER, norm.first, norm.second,GL_DYNAMIC_DRAW);
        glVertexAttribPointer(idNormal, P_SIZE, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

        glBindBuffer(GL_ARRAY_BUFFER, bID.bIDUv);
        glBufferData(GL_ARRAY_BUFFER, coordText.first, coordText.second,GL_DYNAMIC_DRAW);
        glVertexAttribPointer(idUv, 2, GL_DOUBLE, GL_FALSE, 0, (void*)0 );

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bID.bIDInd);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, nbIndice*sizeof(int), &indices[0],GL_DYNAMIC_DRAW);

        InitTexture("textures/Metalcolor.ppm");

        glEnableVertexAttribArray(idVertex);
        glEnableVertexAttribArray(idColor);
        glEnableVertexAttribArray(idNormal);
        glEnableVertexAttribArray(idUv);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    delete vert.second;
    delete couleurs.second;
    delete norm.second;
    delete coordText.second;

}

/*
*   Pour appliquer les transformations on créer une nouvelle liste de point (vertices)
*   On parcours les points (vertex) d'origine pour recuperer le vecteur colonne 
*   On ajoute a la nouvelle liste de points un nouveau point mais transformer
*   Tous cela permet de n'avoir qu'une seule instance objet de notre forme et d'etre sur qu'elle ne soit pas modifier au cours du temps
*/

void Object::ShowDefault(GLenum affichage,int pas){
    /*glPushMatrix();
    
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
        
    glPopMatrix();*/
}

void Object::ShowVBODefault(GLenum affichage){

    glBindVertexArray(bID.bIDVao);
        glDrawElements(affichage, (GLsizei)nbIndice, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Object::InitTexture(string fileName){
    int iwidth, iheight;
    GLubyte *image = image = glmReadPPM(fileName.c_str(), &iwidth, &iheight);

    glBindTexture(GL_TEXTURE_2D, bID.bIDTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, iwidth, iheight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
}

GLubyte *Object::glmReadPPM(const char *filename, int *width, int *height)
{
    FILE *fp;
    int i, w, h, d;
    unsigned char *image;
    char head[70]; /* max line <= 70 in PPM (per spec). */

    fp = fopen(filename, "rb");
    if (!fp)
    {
        perror(filename);
        return NULL;
    }

    /* grab first two chars of the file and make sure that it has the
       correct magic cookie for a raw PPM file. */
    fgets(head, 70, fp);
    if (strncmp(head, "P6", 2))
    {
        fprintf(stderr, "%s: Not a raw PPM file\n", filename);
        return NULL;
    }

    /* grab the three elements in the header (width, height, maxval). */
    i = 0;
    while (i < 3)
    {
        fgets(head, 70, fp);
        if (head[0] == '#') /* skip comments. */
            continue;
        if (i == 0)
            i += sscanf(head, "%d %d %d", &w, &h, &d);
        else if (i == 1)
            i += sscanf(head, "%d %d", &h, &d);
        else if (i == 2)
            i += sscanf(head, "%d", &d);
    }

    /* grab all the image data in one fell swoop. */
    image = new unsigned char[w * h * 3];
    fread(image, sizeof(unsigned char), w * h * 3, fp);
    fclose(fp);

    *width = w;
    *height = h;
    return image;
}