#include "Lancer.h"

Lancer::Lancer(Scene* RenderScene):scene(RenderScene){

}

Lancer::~Lancer(){
    
}

void Lancer::Savebmp(const char *filename, int w, int h, int dpi, RGBType *data){
	FILE *f;
	int k = w*h;
	int s = 4*k;
	int filesize = 54 + s;
	
	double factor = 39.375;
	int m = static_cast<int>(factor);
	
	int ppm = dpi*m;
	
	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
	
	bmpfileheader[ 2] = (unsigned char)(filesize);
	bmpfileheader[ 3] = (unsigned char)(filesize>>8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);
	
	bmpinfoheader[ 4] = (unsigned char)(w);
	bmpinfoheader[ 5] = (unsigned char)(w>>8);
	bmpinfoheader[ 6] = (unsigned char)(w>>16);
	bmpinfoheader[ 7] = (unsigned char)(w>>24);
	
	bmpinfoheader[ 8] = (unsigned char)(h);
	bmpinfoheader[ 9] = (unsigned char)(h>>8);
	bmpinfoheader[10] = (unsigned char)(h>>16);
	bmpinfoheader[11] = (unsigned char)(h>>24);
	
	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s>>8);
	bmpinfoheader[23] = (unsigned char)(s>>16);
	bmpinfoheader[24] = (unsigned char)(s>>24);
	
	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm>>8);
	bmpinfoheader[27] = (unsigned char)(ppm>>16);
	bmpinfoheader[28] = (unsigned char)(ppm>>24);
	
	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm>>8);
	bmpinfoheader[31] = (unsigned char)(ppm>>16);
	bmpinfoheader[32] = (unsigned char)(ppm>>24);
	
	f = fopen(filename,"wb");
	
	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);
	
	for (int i = 0; i < k; i++) {
		RGBType rgb = data[i];
		
		double red = (data[i].r)*255;
		double green = (data[i].g)*255;
		double blue = (data[i].b)*255;
		
		unsigned char color[3] = {(unsigned char)floor(blue),(unsigned char)floor(green),(unsigned char)floor(red)};
		
		fwrite(color,1,3,f);
	}
	
	fclose(f);
}

void Lancer::Main(int Profondeur,Camera* camera){
    int Width = glutGet(GLUT_WINDOW_WIDTH);
	int Height = glutGet(GLUT_WINDOW_HEIGHT);
    double aspectRatio = (double)Width / (double)Height;
    RGBType *pixels = new RGBType[Width*Height];
    int dpi = 72;

    int pixelCourant;

    for(int y=0;y<Height;y++){
        for(int x=0;x<Width;x++){

            double xamnt,yamnt;
            pixelCourant = y*Width + x;

            if (Width > Height) {
                // the image is wider than it is tall
                xamnt = ((x+0.5)/Width)*aspectRatio - (((Width-Height)/(double)Height)/2);
                yamnt = ((Height - y) + 0.5)/Height;
            }
            else if (Height > Width) {
                // the imager is taller than it is wide
                xamnt = (x + 0.5)/ Width;
                yamnt = (((Height - y) + 0.5)/Height)/aspectRatio - (((Height - Width)/(double)Width)/2);
            }
            else {  
                // the image is square
                xamnt = (x + 0.5)/Width;
                yamnt = ((Height - y) + 0.5)/Height;
            }

            Vect rayDir =  (camera->GetDirection() + ((camera->GetRight()*(xamnt-0.5)) + (camera->GetDown()*(yamnt-0.5)))).normalize();

            Rayon* rayon = new Rayon(camera->GetPosition(),rayDir);
            
            Vect couleurFinal = Trace(Profondeur,rayon).clip();

            delete rayon;
            cout << couleurFinal <<endl;
            pixels[pixelCourant].r = couleurFinal[0];
			pixels[pixelCourant].g = couleurFinal[1];
			pixels[pixelCourant].b = couleurFinal[2];
            
        }
    }

    Savebmp("rendu.bmp",Width,Height,dpi,pixels);
    delete pixels;
}

Vect Lancer::Trace(int Profondeur,Rayon* NewRayon){
    
    PointIntersection point = TestIntersection(NewRayon);
    
    if(point.IndexObjet != -1){
        Vect normal = scene->GetObject(point.IndexObjet)->Normal(point);
        Vect couleur = Colorier(NewRayon,point,normal,Profondeur);
        return couleur;
    }

    return scene->GetCouleurFond();
    
}

PointIntersection Lancer::TestIntersection(Rayon* rayon){
    PointIntersection point;

    for(int i=0;i<scene->NbObject();i++){

        Retour_Calcul r_c = scene->GetObject(i)->In(rayon);

        if(r_c.dedans){
            PointIntersection pointCalculer = scene->GetObject(i)->CalculIntersection(rayon,r_c.calculs);
            
            if (pointCalculer.T>=0 && pointCalculer.T < point.T){
                point = pointCalculer;
                point.IndexObjet = i;
            }
        }
    }

    return point;
}

Vect Lancer::Colorier(Rayon* RayonCourant, PointIntersection Point, Vect Normal, int Profondeur){
    Object* object = scene->GetObject(Point.IndexObjet);
    Vect LightModelProducts = (object->GetMateriel()->GetCouleurEmission() + object->GetMateriel()->GetCouleurParameter()->GetValue(Ambient) * scene->GetCouleurAmbiante());
    Vect couleurFinal = Vect(0,0,0);

    couleurFinal = LightModelProducts.clip();

    // calcul couleur lumiere
    for(int i=0;i<scene->NbLumiere();i++){

        Lumiere* l = scene->GetLumiere(i);
        
        Vect lumiereDirection = (l->GetPosition() - Point.CoordPoint).normalize();

        double cosinus = Normal.dot(lumiereDirection);

        bool intersect = false;

        if(cosinus > 0){
            // test ombre
            double distLumiereMagn = lumiereDirection.length();

            Rayon* rayonOmbre = new Rayon(Point.CoordPoint,lumiereDirection);

            PointIntersection interOmbre = TestIntersection(rayonOmbre);

            if(interOmbre.IndexObjet!=-1 && interOmbre.T <= distLumiereMagn){
                // ombre
                intersect = true;
            }

            delete rayonOmbre;
        }

        if(!intersect){
            //calcul la couleur
            couleurFinal = couleurFinal + Phong(Normal,l,Point,RayonCourant);
        }
        
    }

    if(Profondeur > 0){
        if(object->GetMateriel()->GetType() == Reflechissant){
            Vect vReflect = RayonCourant->GetDirection().reflect(Normal);
            Rayon* rayonRefl = new Rayon(Point.CoordPoint,vReflect,true);

            couleurFinal = couleurFinal + Trace(Profondeur-1, rayonRefl);
        }

        if(object->GetMateriel()->GetType() == Transparent){
            Vect vRefract = RayonCourant->GetDirection().refract(Normal,1.0);
            Rayon* rayonTrans = new Rayon(Point.CoordPoint,vRefract,true);

            couleurFinal = couleurFinal + Trace(Profondeur-1, rayonTrans);
        }
    }

    return couleurFinal.clip();
}

Vect Lancer::Phong(Vect Normal,Lumiere* lumiere,PointIntersection Point,Rayon* rayon){
                    
    Vect position = Point.CoordPoint;
    Vect positionLumiere = lumiere->GetPosition();
    Materiel* materielObjet = scene->GetObject(Point.IndexObjet)->GetMateriel();    
    Couleur* couleurObject = materielObjet->GetCouleurParameter();
    Couleur* couleurLumiere = lumiere->GetCouleur();
    Vect attenuation = lumiere->GetAttenuation();

    Vect LightProductsAmbient = couleurObject->GetValue(Ambient) * couleurLumiere->GetValue(Ambient);
    Vect LightProductsDiffuse = couleurObject->GetValue(Diffuse) * couleurLumiere->GetValue(Diffuse);
    Vect LightProductsSpeculaire = couleurObject->GetValue(Speculaire) * couleurLumiere->GetValue(Speculaire);

    Vect L = (positionLumiere-position).normalize();
    Vect E = (rayon->GetDirection()*(-1)).normalize();
    Vect R = (L.reflect(Normal)*(-1)).normalize();

    double dotNL = Normal.dot(L);
    double dotRE = R.dot(E);
    double dist = positionLumiere.distance(position);
	double F = min(1/(attenuation[0] + attenuation[1]*dist + attenuation[2]*pow(dist,2)),1.0);

    Vect couleurAmbient = LightProductsAmbient;

    Vect couleurDiffuse = LightProductsDiffuse * max(dotNL, 0.0); 
   
    Vect couleurSpeculaire = LightProductsSpeculaire * pow(max(dotRE,0.0),materielObjet->GetShininess());

    Vect couleurF = (couleurSpeculaire + couleurDiffuse + couleurAmbient) * F;

    return couleurF / (couleurF[0]+couleurF[1]+couleurF[2]);
}
