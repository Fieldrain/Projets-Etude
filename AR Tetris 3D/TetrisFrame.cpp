#include "TetrisFrame.h"

TetrisFrame::TetrisFrame(int Taille) : Objet("TetrisFrame"), taille(Taille + (1 - (Taille % 2)))
{
    frame = new vector<vector<vector<int>>>();

    for (int x = 0; x < taille ; x++)
        {
            vector<vector<int>> vy;
            for (int y = 0; y < taille ; y++)
            {
                vector<int> vz;
                for (int z = 0; z < taille ; z++)
                {
                    vz.push_back(0);
                }      
                vy.push_back(vz);
            }
            frame->push_back(vy);
        }

    departPiece[0] = taille/2;
    departPiece[1] = taille-2;
    departPiece[2] = taille/2;

    fabrique = new FabriquePiece();

    CreatePiece();
}

TetrisFrame::~TetrisFrame()
{
}

void TetrisFrame::CreatePiece()
{
    srand (time(NULL));
    int i = (rand() % 100) % TypePiece::NbPiece;
    pieceCourante = fabrique->ConstruitPiece(static_cast<TypePiece>(i),departPiece);

}

bool TetrisFrame::AddPiece()
{
    bool pieceAdded = true;

    vector<vector<int>>* shape = pieceCourante->GetShape();
    for(int i=0;i<shape->size();i++)
    {
        vector<int> p = shape->at(i);
        int x = p[0];
        int y = p[1];
        int z = p[2];

        if(y<=(taille-1))
            frame->at(x)[y][z] = 1;
        else
            pieceAdded = false;
    }

    delete pieceCourante;
    pieceCourante = NULL;

    if(pieceAdded==false){
        return false;
    }

    CreatePiece();

    return true;
}

void TetrisFrame::Affiche()
{
    glPushMatrix();
        glColor3f(1,1,1);

        glPushMatrix();
            float a = (0.01*(taille-1))+0.01;
            float z = 0.0;
            glLineWidth(1.0);
            glBegin(GL_LINES);
            glVertex3f(z,z,z);
            glVertex3f(a,z,z);
            
            glVertex3f(z,z,z);
            glVertex3f(z,a,z);

            glVertex3f(z,z,z);
            glVertex3f(z,z,a);

            glVertex3f(z,z,z);
            glVertex3f(z,z,a);

            glVertex3f(a,z,z);
            glVertex3f(a,a,z);

            glVertex3f(a,z,z);
            glVertex3f(a,z,a);

            glVertex3f(z,a,z);
            glVertex3f(z,a,a);

            glVertex3f(z,z,a);
            glVertex3f(z,a,a);

            glVertex3f(z,z,a);
            glVertex3f(a,z,a);

            glVertex3f(a,a,z);
            glVertex3f(z,a,z);

            glVertex3f(a,a,a);
            glVertex3f(z,a,a);

            glVertex3f(a,z,a);
            glVertex3f(a,a,a);

            glVertex3f(a,a,z);
            glVertex3f(a,a,a);

            glEnd();
        glPopMatrix();

        for (int x = 0; x < taille ; x++)
        {
            for (int y = 0; y < taille ; y++)
            {
                for (int z = 0; z < taille ; z++)
                {
                    float x1 = 0.01*x;
                    float y1 = 0.01*y;
                    float z1 = 0.01*z;

                    glPushMatrix();
                    glTranslatef(x1,z1,y1);
                    if (frame->at(x)[y][z] == 1)
                    {
                        glutSolidCube(0.01);
                    }
                    glPopMatrix();

                }
            }
        }

        if(pieceCourante!=NULL)
            pieceCourante->Affiche();

    glPopMatrix();
}

void TetrisFrame::Translate(float x, float y, float z)
{
}

void TetrisFrame::Rotate(int type)
{
}

void TetrisFrame::Scale()
{
}

bool TetrisFrame::IsColide(Piece* p, int* d)
{
    vector<vector<int>>* shape = p->GetShape();
    for(int i=0;i<shape->size();i++)
    {
        vector<int> p = shape->at(i);
        int x = p[0];
        int y = p[1];
        int z = p[2];
        
        if (frame->at(x+d[0])[y+d[1]][z+d[2]] == 1 || (y - 1 <= 0))
        {
            return true;
            
        }
    }
    return false;
}

bool TetrisFrame::IsValide(Piece* p, int* d){
    vector<vector<int>>* shape = p->GetShape();
    bool valid = true;
    for(int i=0;i<shape->size();i++)
    {
        vector<int> p = shape->at(i);
        int x = p[0];
        int y = p[1];
        int z = p[2];

        if (!(((x+d[0])>=0 && (x+d[0])<=(taille-1)) && ((y+d[1])>=0 && (y+d[1])<=(taille-1)) && ((z+d[2])>=0 && (z+d[2])<=(taille-1)))) 
        {
            return false;
            
        }     
    }
    return valid;
}

bool TetrisFrame::DeplacePiece(Sens s){
    int deplacement[3];

    deplacement[0] = 0;
    deplacement[1] = 0;
    deplacement[2] = 0;

    switch (s){
        case Gauche :
            deplacement[0] = -1;
        break;
        
        case Droite :
            deplacement[0] = 1;
        break;

        case Bas :
            deplacement[1] = -1;
        break;

        case Avant:
            deplacement[2] = -1;
        break;

        case Arriere:
            deplacement[2] = 1;
        break;
    }

    if(IsValide(pieceCourante,deplacement)){
        if(IsColide(pieceCourante,deplacement))
            return AddPiece();
        else{
            pieceCourante->Translate(deplacement);
        }
    }

    return true;

}

void TetrisFrame::RotatePiece(SensRotation s){
    switch (s){
        case Horaire :
            pieceCourante->Rotate(0);
        break;
        
        case AntiHoraire :
            pieceCourante->Rotate(1);
        break;

    }
}