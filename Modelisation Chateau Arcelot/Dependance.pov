#include "TexturePerso.pov"

#declare Placement_Toit = <-1.25,0,0>;

#declare Pierre_Fenetre = pigment { image_map { png "image/beige_2.png"  map_type 1}}
#declare Pierre_Ligne = pigment { image_map { png "image/beige_3.png"  map_type 1}}
#declare Pierre_Porte = pigment {image_map {png "image/beige_1.png" map_type 1}}
#declare Pierre_Porte_Cercle = pigment {image_map {png "image/beige_1.png" map_type 1}}


//----------Toit----------
#macro decoupe_face_premiere_inclinaison()
       difference
       {
            box {<0,0,0> <1430,300,800> pigment{Red} texture {T_Roof}}
            box {<-10,0,-100> <1500,300,100> pigment{Red} texture {T_Roof} translate <0,0,-100> rotate <20,0,0> }
       }
#end

#macro decoupe_back_premiere_inclinaison()
      difference
      {
            decoupe_face_premiere_inclinaison()
            box {<-10,0,300> <1500,300,100> pigment{Red} texture {T_Roof} rotate <-20,0,0> translate <0,-37,700>}
      }
#end

#macro decoupe_droite_premiere_inclinaison()
      difference
      {
            decoupe_back_premiere_inclinaison()
            box {<1430,0,0> <1600,400,800> pigment{Red} texture {T_Roof} rotate <0,0,15> translate <40,-450,0> }
      }
#end

#macro decoupe_gauche_premiere_inclinaison()
    difference
    {
        decoupe_droite_premiere_inclinaison()
        box { <-200,0,0> <0,400,800> pigment{Red} texture {T_Roof} rotate <0,0,-15> translate <0,0,0> }
    }
#end

#macro decoupe_face_deuxieme_inclinaison()
    difference
    {
        decoupe_gauche_premiere_inclinaison()
        box{ <-10,0,0> <1500,500,300> pigment{Red} texture {T_Roof} rotate <75,0,0> translate <0,400,-100>}
    }
#end

#macro decoupe_back_deuxieme_inclinaison()
    difference
    {
        decoupe_face_deuxieme_inclinaison()
        box{ <-10,0,800> <1500,500,1200> pigment{Red} texture {T_Roof} rotate <-75,0,0> translate <0,-670,600>}
    }
#end

#macro decoupe_gauche_deuxieme_inclinaison()
    difference
    {
        decoupe_back_deuxieme_inclinaison()
        box{<-200,0,0> <0,400,800> pigment{Red} texture {T_Roof} rotate <0,0,-60> translate <0,100,0>}
    }
#end

#macro decoupe_droite_deuxieme_inclinaison(placement)
    difference
    {
        decoupe_gauche_deuxieme_inclinaison()
        box{<1450,0,0> <1800,500,800> pigment{Red} texture {T_Roof} rotate <0,0,70> translate <900,-1250,0>}
        translate placement
    }
#end

#macro toit(placement)
    decoupe_droite_deuxieme_inclinaison(placement)
#end
//----------Fin Toit----------

//----------Fenetre Toit----------
#macro fenetre_toit_forme_de_base()
    union
    {
        cylinder {<0,0,0>, <0,0,50> 50 pigment{color rgb<1,0.87,0.6>} translate <230,730,0>}
        box{<0,0,0> <100,70,50> pigment{color rgb<1,0.87,0.6>} translate <180,660,0> }
    }
#end

#macro fenetre_toit_bordure_blanche()
    difference
    {
        sphere{<0,0,0> 35 pigment{Gray95} translate <35,35,0>}
        box{<0,0,-40> <70,70,0> pigment{Gray95} translate <0,0,0>}
        translate <195,690,-0.1>
    }
#end

#macro fenetre_toit_bordure_blanche_droite()
    box{<0,0,0> <7,60,0> pigment{Gray95} translate <227,695,-0.3>}
#end

#macro fenetre_toit_vitre()
    difference
    {
        sphere{<0,0,0> 30 material{M_Window} translate <30,30,0>}
        box{<0,0,-40> <70,70,0> material{M_Window} translate <0,0,0>}
        translate <200,695,-0.2>
    }
#end

#macro fenetre_toit(placement, rotation)
    union
    {
        fenetre_toit_forme_de_base()
        fenetre_toit_bordure_blanche()
        fenetre_toit_vitre()
        fenetre_toit_bordure_blanche_droite()
        translate placement
        rotate rotation
    }
#end
//----------Fin Fenetre Toit----------

//----------Fenetre Face----------
#macro bordure_verticale_fenetre(placement)
    #local largeur=5;
    #local hauteur=200;
    box{<0,0,0> <largeur, hauteur,0.2> pigment{Gray95} translate placement}
#end

#macro bordure_horizontale_fenetre(placement)
    #local largeur=100;
    #local hauteur=5;
    box{<0,0,0> <largeur,hauteur,0.2> pigment{Gray95} translate placement}
#end

#macro fenetre (posX, posY, posZ, rotation, echelle)
    union
    {
        #local largeur=100;
        #local hauteur=200;
        box{<0,0,0> <largeur,hauteur,0.1> material{M_Window} translate <posX, posY, posZ>}
        //appel des macros pour les bordures de la fen�tre
        bordure_verticale_fenetre(<posX,posY+0,posZ-0.1>)
        bordure_verticale_fenetre(<posX+50,posY+0,posZ-0.1>)
        bordure_verticale_fenetre(<posX+98,posY+0,posZ-0.1>)
        bordure_horizontale_fenetre(<posX+0,posY+0,posZ-0.1>)
        bordure_horizontale_fenetre(<posX+0,posY+65,posZ-0.1>)
        bordure_horizontale_fenetre(<posX+0,posY+135,posZ-0.1>)
        bordure_horizontale_fenetre(<posX+0,posY+195,posZ-0.1>)
        rotate rotation
        scale echelle
    }
#end

#macro decoration_fenetre_bande_interieure_verticale(placement)
    box{<0,0,0> <133,2,0.1> pigment{Brown} translate placement}
#end

#macro decoration_fenetre_bande_interieure_horizontale(placement)
    box{<0,0,0> <2,232,0.1> pigment{Brown} translate placement}
#end

#macro decoration_fenetre_petit_carre(posX,posY,posZ)
    difference
    {
        box{<0,0,0> <10,10,0.1> pigment{Brown} translate <posX,posY,posZ>}
        box{<0,0,-0.1> <5,5,0.2> pigment{Brown} translate <posX+2.5,posY+2.5,posZ>}
    }
#end

#macro decoration_fenetre_bande_exterieure_horizontale(placement)
    box{<0,0,0> <170,2,0.1> pigment{Brown} translate placement}
#end

#macro decoration_fenetre_bande_exterieure_verticale(placement)
    box{<0,0,0> <2,265,0.1> pigment{Brown} translate placement}
#end

#macro decoration_fenetre(placement, rotation, echelle)
    union
    {
        decoration_fenetre_bande_interieure_verticale(<514,295,0>)
        decoration_fenetre_bande_interieure_verticale(<514,65,0>)
        decoration_fenetre_bande_interieure_horizontale(<512,65,0>)
        decoration_fenetre_bande_interieure_horizontale(<646,65,0>)
        decoration_fenetre_petit_carre(648,55,0)
        decoration_fenetre_petit_carre(648,297,0)
        decoration_fenetre_petit_carre(502,297,0)
        decoration_fenetre_petit_carre(502,55,0)
        decoration_fenetre_bande_exterieure_horizontale(<495,47,0>)
        decoration_fenetre_bande_exterieure_horizontale(<495,311,0>)
        decoration_fenetre_bande_exterieure_verticale(<495,47,0>)
        decoration_fenetre_bande_exterieure_verticale(<663,47,0>)
        decoration_fenetre_bande_pierre_verticale()
        decoration_fenetre_bande_pierre_horizontale()
        translate placement
        rotate rotation
        scale echelle
    }

#end

#macro decoration_fenetre_bande_pierre_verticale()
    #local posX= 514;
    #local posY=+67;
    #local posZ=-0.2;
    #local nbBloc=0;
    #while (nbBloc<14)
        box{ <0,0,0> <15,15,0.2> pigment {Pierre_Fenetre} translate <posX, posY,posZ> }
        box{ <0,0,0> <15,15,0.2> pigment {Pierre_Fenetre} translate <posX+117, posY,posZ> }
        #local nbBloc=nbBloc+1;
        #local posY = posY +16.25;
    #end
#end

#macro decoration_fenetre_bande_pierre_horizontale()
    #local posX= 530;
    #local posY=+67;
    #local posZ=-0.2;
    #local nbBloc=0;
    #while (nbBloc<6)
        box{ <0,0,0> <15,15,0.2> pigment {Pierre_Fenetre} translate <posX, posY,posZ> }
        box{ <0,0,0> <15,15,0.2> pigment {Pierre_Fenetre} translate <posX, posY+212,posZ> }
        #local nbBloc=nbBloc+1;
        #local posX = posX +16.75;
    #end
#end
//----------Fin Fenetre Face----------

//---------- Porte Face----------
#macro vitre_porte(placement)
    #local largeur=50;
    #local hauteur=100;
    box{<0,0,0> <largeur, hauteur, 0.2>  material{M_Window} translate placement}
#end

#macro moitie_cercle_bordure()
                difference {
                            sphere{<0,0,0> 72 pigment{Gray95} }
                            box{<-72,-72,-72> <72,72,0> pigment{Gray95}}
                            }
#end

#macro moitie_cercle_bordure_interieure()
                difference {
                            sphere{<0,0,0> 15 pigment{Gray95} }
                            box{<-15,-15,-15> <15,15,0> pigment{Gray95}}
                            }
#end

#macro bordure_droite_vitre_cercle(placement, rotation)
      box{ <0,0,0> <50,5,0> pigment{Gray95} rotate rotation translate placement}
#end

#macro moitie_cercle_vitre()
                difference {
                            sphere{<0,0,0> 55 material{M_Window}}
                            box{<-55,-55,-55> <55,55,0> material{M_Window}}
                            }
#end

#macro dessus_porte(placement_bordure, placement_bordure_interieure, placement_vitre, placement_barre)
    difference{
                moitie_cercle_bordure()
                box{<-72,-72,0> <72,0,72> pigment{Gray95}}
                translate placement_bordure
               }
    difference {
                moitie_cercle_vitre()
                box{<-55,-55,0> <55,0,55> material{M_Window}}
                translate placement_vitre
               }
    difference{
                moitie_cercle_bordure_interieure()
                box{<-15,-15,0> <15,0,15> pigment{Gray95}}
                translate placement_bordure_interieure
               }
    bordure_droite_vitre_cercle(placement_barre, <0,0,45> )
    bordure_droite_vitre_cercle(<placement_barre.x-5,placement_barre.y+3,placement_barre.z> , <0,0,130> )
#end

#macro bordure_verticale_pierre_porte(posX, posY, posZ)
    #local nbPierre=0;
    #local Y=posY;
    #while(nbPierre<3)
        box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX-30, Y, posZ>}
        box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX+140, Y, posZ>}
        #local Y= Y+30;
        box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX-15, Y, posZ>}
        box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX+125, Y, posZ>}
        #local Y= Y+30;
        #local nbPierre=nbPierre+1;
    #end
    box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX-30, Y, posZ>}
    box{<0,0,0> <30,30,0> pigment{Pierre_Porte} translate <posX+140, Y, posZ>}
#end

#macro demi_cercle_plat()
    difference
    {
        sphere {<0,0,0> 100 texture {Pierre_Porte_Cercle} translate <100,100,0>}
        box{<0,0,0> <200,200,-100> texture {Pierre_Porte_Cercle}}
    }
#end

#macro bordure_cercle_pierre_porte(posX, posY, posZ)
    difference
    {
       demi_cercle_plat()
       box{<0,0,0> <200,100,0> texture {Pierre_Porte_Cercle}}
       translate <posX-30,posY+100,posZ>
    }
#end

#macro porte(posX, posY, posZ, rotation)
    union
    {
        #local largeur=140;
        #local hauteur=200;
        box{<0,0,0> <largeur, hauteur, 0> pigment{Gray95} translate <posX,posY,posZ-0.1>}
        box{<0,0,0> <5,200,0> pigment{Gray80} translate<posX+67,posY,posZ-0.11>}
        box{<0,0,0> <50,80,0> pigment{Gray80} translate<posX+10, posY+7,posZ-0.11>}
        box{<0,0,0> <50,80,0> pigment{Gray80} translate<posX+80, posY+7,posZ-0.11>}
        bordure_verticale_pierre_porte(posX, posY, posZ-0.05)
        bordure_cercle_pierre_porte(posX, posY, posZ)
        vitre_porte(<posX+10,posY+95,posZ-0.2>)
        vitre_porte(<posX+80,posY+95,posZ-0.2>)
        dessus_porte(<posX+70,posY+200,posZ-0.01>,<posX+70,posY+207,posZ-0.03>, <posX+70, posY+207, posZ-0.02>, <posX+75, posY+215, posZ-0.04>)
        rotate rotation
    }
#end

//----------Fin Porte Face----------

//----------Porte C�t�----------

#macro bordure_pierre_porte_cote(placement)
    box{<0,0,0> <160,280,0> texture {Pierre_Porte} rotate <0,90,0> translate<placement.x, placement.y, placement.z+30>}
#end

#macro vitre_porte_cote(placement)
    box{<0,0,0> <30,100,0> material{M_Window} rotate <0,90,0> translate placement}
#end

#macro vitre_dessus_porte_cote(placement)
    box{<0,0,0> <30,30,0> material{M_Window} rotate <0,90,0> translate placement}
#end

#macro decoration_porte_cote(placement)
    box{<0,0,0> <30,70,0> pigment{Gray80} rotate <0,90,0> translate placement}
#end

#macro decoration_entre_porte_et_dessus_cote(placement)
    box{<0,0,0> <100,5,0> pigment{Gray80} rotate<0,90,0> translate placement}
#end

#macro porte_cote(placement, echelle)
    union
    {
        box{<0,0,0> <100,200,0> pigment{Gray95} translate <0,0,-0.01>}
        box{<0,0,0> <100,50,0> pigment{Gray95} translate <0,200,-0.01>}
        rotate <0,90,0>
        translate placement
        scale echelle
    }
    union
    {
        bordure_pierre_porte_cote(placement)
        vitre_porte_cote(<placement.x-0.02, placement.y+90, placement.z-15>)
        vitre_porte_cote(<placement.x-0.02, placement.y+90, placement.z-55>)
        vitre_dessus_porte_cote(<placement.x-0.02, placement.y+210, placement.z-15>)
        vitre_dessus_porte_cote(<placement.x-0.02, placement.y+210, placement.z-55>)
        decoration_porte_cote(<placement.x-0.02, placement.y+10, placement.z-15>)
        decoration_porte_cote(<placement.x-0.02, placement.y+10, placement.z-55>)
        decoration_entre_porte_et_dessus_cote(<placement.x-0.02, placement.y+198, placement.z>)
        scale echelle
    }
#end
//----------Fin Porte C�t�----------

//----------Decoration----------
#macro s_decoratif_barre_droite(rotation, placement)
    box{ <0,0,0> <10,2,2> pigment{Brown} rotate rotation translate placement}
#end

#macro s_decoratif(posX, posY, posZ)
    union
    {
        s_decoratif_barre_droite(<0,0,0>, <0,0,0>)
        s_decoratif_barre_droite(<0,0,40>, <10,0,0>)
        s_decoratif_barre_droite(<0,0,0>, <17,7,0>)
        translate <posX, posY, posZ-0.1>
    }
#end

#macro bande_s_decorative(nbMax,longueur,posX, posY, posZ, rotation)
    union
    {
        #local nombre_decoration = 0;
        #local X = posX;
        #while(nombre_decoration < nbMax)
              s_decoratif(X, posY, posZ)
              #local X= X+22;
              #local nombre_decoration=nombre_decoration+1;
        #end
        box{<0,0,0> <longueur,2,0>  pigment{Brown}translate <posX,posY-10,posZ-0.1>}
        rotate rotation
    }
#end

#macro gamma_decoratif_barre_longue_horizontale(placement)
    box{<0,0,0> <15,2,0> pigment{Brown} translate placement}
#end

#macro gamma_decoratif_barre_longue_verticale(placement)
    box{<0,0,0> <2,10,0> pigment{Brown} translate placement}
#end

#macro gamma_decoratif_barre_courte_horizontale(placement)
    box{<0,0,0> <7,2,0> pigment{Brown} translate placement}
#end

#macro gamma_decoratif_barre_courte_verticale(placement)
    box{<0,0,0> <2,4,0> pigment{Brown} translate placement}
#end

#macro gamma_decoratif(posX, posY, posZ)
    union
    {
        gamma_decoratif_barre_longue_horizontale(<0,0,-0.1>)
        gamma_decoratif_barre_longue_verticale(<15,0,-0.1>)
        gamma_decoratif_barre_longue_horizontale(<15,10,-0.1>)
        gamma_decoratif_barre_courte_verticale(<28,6,-0.1>)
        gamma_decoratif_barre_courte_horizontale(<23,5,-0.1>)
        gamma_decoratif_barre_courte_verticale(<23,1,-0.1>)
        translate <posX, posY, posZ>
    }
#end

#macro bande_gamma_decorative(nbMax, longueur, posX, posY, posZ, rotation)
    union
    {
        #local nombre_decoration = 0;
        #local X = posX;
        #while(nombre_decoration < nbMax)
            gamma_decoratif(X,posY,posZ)
            #local X = X + 23;
            #local nombre_decoration = nombre_decoration+1;
        #end
        box{<0,0,0> <longueur,2,0.1>  pigment{Brown}translate <posX,posY-7,posZ-0.1>}
        rotate rotation
    }
#end

#macro bande_pierre(nbMax,basse, haute, rotation, placement)
    union
    {
        #local posX=3;
        #local nbPierre = 0;
        #while(nbPierre<nbMax)
            box{<0,0,0> <15,15,0.1> pigment {Pierre_Ligne} translate <posX,basse,-0.1>}
            box{<0,0,0> <15,15,0.1> pigment {Pierre_Ligne} translate <posX,haute,-0.1>}
            #local posX=posX+15;
            #local nbPierre = nbPierre+1;
        #end
        rotate rotation
        translate placement
    }
#end

#macro marche_porte_cote(placement, rotation)
    union
    {
        box{<0,0,0> <100,30,30> pigment{Pierre_Ligne} rotate rotation translate placement}
        box{<0,0,0> <100,15,30> pigment{Pierre_Ligne} rotate rotation translate <placement.x-30, placement.y, placement.z>}
    }
#end

#macro bande_cote_droit_grillage_bois(placement)
    box{<0,0,0> <3,300,0> pigment{Brown} rotate <0,0,45> translate placement}
#end

#macro bande_cote_gauche_grillage_bois(placement)
    box{<0,0,0> <3,300,0> pigment{Brown} rotate <0,0,-45> translate placement}
#end

#macro grillage_bois(placement, nbMax)
    union
    {
        #local X = placement.x;
        #local nbTour=0;
        #while(nbTour<nbMax)
            bande_cote_droit_grillage_bois(<X, placement.y-10, placement.z>)
            bande_cote_gauche_grillage_bois(<X+69, placement.y-10, placement.z>)
            #local X = X +20;
            #local nbTour=nbTour+1;
        #end
    }
#end

#macro bordure_bois_grillage_bois(largeur, hauteur, placement)
    box{<0,0,0> <largeur, hauteur,0.4> pigment{Red} translate placement}
#end                                        //color rgb<1,0.87,0.6>

#macro bordure_bois_grillage_bois_2(largeur, hauteur, placement)
    box{<0,0,0> <largeur, hauteur,0.2> pigment{Brown} translate placement}
#end

#macro decoupe_bordure_bois_grillage_bois(largeur, hauteur, placement)
    box{<0,0,0> <largeur, hauteur,0.2> pigment{color rgb<1,0.87,0.6>} translate placement}
#end

#macro decoupe_taille_grillage(placement)
    difference
    {
        decoupe_bordure_bois_grillage_bois(1500,300,<0,-11,-1>)
        bordure_bois_grillage_bois(267,197 ,<600,0,-1.1> )
        translate placement
    }
#end

#macro decoupe_grillage(rotation, placement)
    difference
    {
        grillage_bois(<300,0,-1>, 40)
        decoupe_taille_grillage(<0,0,-0.1>)
        rotate rotation
        translate placement
    }
#end

#macro decoupe_bordure(rotation, placement)
    difference
    {
        bordure_bois_grillage_bois_2(277,207 ,<600,0,-3> )
        bordure_bois_grillage_bois(267,197 ,<605,5,-3.1> )
        rotate rotation
        translate placement
    }
#end

#macro grillage_final(rotation)
    union
    {
        decoupe_grillage(rotation, <0.35,400,905>)
        decoupe_grillage(rotation, <0.35,400,1360>)
        decoupe_bordure(rotation, <2.9,395,910>)
        decoupe_bordure(rotation, <2.9,395,1365>)
    }
#end

//----------Fin Decoration----------


//appel des macros
#macro face_dependance_gauche()
    union
    {
        fenetre(180, 420, -0.1,<0,0,0>,<1,1,1>)
        fenetre(528, 420, -0.1, <0,0,0>,<1,1,1>)
        fenetre(780, 420, -0.1, <0,0,0>,<1,1,1>)
        fenetre(1030, 420, -0.1, <0,0,0>,<1,1,1>)
        fenetre(1280, 420, -0.1, <0,0,0>,<1,1,1>)
        fenetre(528, 80, -0.1, <0,0,0>,<1,1,1>)
        fenetre(780, 80, -0.1, <0,0,0>,<1,1,1>)
        fenetre(1030, 80, -0.1,<0,0,0>,<1,1,1>)
        porte(165,0,0, <0,0,0>)     //to check after windows border changes
        porte(1265,0,0, <0,0,0>)      //same
        toit(<15,660,0>)
        bande_s_decorative(65, 1420,0,330,0, <0,0,0>)
        bande_gamma_decorative(62,1430,0,630,0<0,0,0>)
        fenetre_toit(<348,0,0>, <0,0,0>)
        fenetre_toit(<600,0,0>, <0,0,0>)
        decoration_fenetre(<0,0,-0.1>,<0,0,0>,<1,1,1>)
        decoration_fenetre(<250,0,-0.1>,<0,0,0>,<1,1,1>)
        decoration_fenetre(<500,0,-0.1>, <0,0,0>,<1,1,1>)
        decoration_fenetre(<-350,335,-0.1>,<0,0,0>,<1,1,1>)
        decoration_fenetre(<0,335,-0.1>, <0,0,0>,<1,1,1>)
        decoration_fenetre(<250,335,-0.1>, <0,0,0>,<1,1,1>)
        decoration_fenetre(<500,335,-0.1>, <0,0,0>,<1,1,1>)
        decoration_fenetre(<750,335,-0.1>, <0,0,0>,<1,1,1>)
        bande_pierre(95,340,645,<0,0,0>, <0,0,0>)
        box {<0,0,0> <1430,660,800> pigment {color rgb<1,0.87,0.6>}}
    }
#end

#macro gauche_dependance_gauche()
    union
    {
        fenetre(-551, 150, 0, <0,90,0>,<1,0.8,0.8>)
        decoration_fenetre(<-1080,70,0>, <0,90,0>,<1,0.8,0.8>)
        fenetre(-551, 520, 0, <0,90,0>,<1,0.8,0.8>)
        decoration_fenetre(<-1080,440,0>, <0,90,0>,<1,0.8,0.8>)
        fenetre_toit(<-630,0,0>, <0,90,0>)
        porte_cote(<-0.02,0,170>, <1,1.2,1.15>)
        porte_cote(<-0.02,0,625>, <1,1.2,1.15>)
        bande_s_decorative(36, 800,-800,350,0,<0,90,0>)
        bande_gamma_decorative(34, 800, -800, 630, 0, <0,90,0>)
        bande_pierre(53,360,645,<0,90,0>, <0,0,800>)
        grillage_final(<0,90,0>)
        //marche_porte_cote(<-30,0,190>,<0,90,0>)
        //marche_porte_cote(<-30,0,710>,<0,90,0>)
    }
#end

#macro back_dependance_gauche()
    union
    {
        porte(-1400, 0, -800.5, <0,180,0>)
        porte(-300, 0, -800.5, <0,180,0>)
        fenetre(-280, 410, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-809,330,-801>, <0,180,0>,<1,1,1>)
        fenetre(-690, 410, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1220,330,-801>, <0,180,0>,<1,1,1>)
        fenetre(-920, 410, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1450,330,-801>, <0,180,0>,<1,1,1>)
        fenetre(-1150, 410, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1680,330,-801>, <0,180,0>,<1,1,1>)
        fenetre(-1380, 410, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1910,330,-801>, <0,180,0>,<1,1,1>)
        fenetre(-690, 80, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1220,0,-801>, <0,180,0>,<1,1,1>)
        fenetre(-920, 80, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1450,0,-801>, <0,180,0>,<1,1,1>)
        fenetre(-1150, 80, -801, <0,180,0>,<1,1,1>)
        decoration_fenetre(<-1680,0,-801>, <0,180,0>,<1,1,1>)
        fenetre_toit(<-870,0,-800>, <0,180,0>)
        fenetre_toit(<-1100,0,-800>, <0,180,0>)
        bande_s_decorative(65, 1430,-1430,350,-800,<0,180,0>)
        bande_gamma_decorative(62, 1430, -1430, 630, -800, <0,180,0>)
        bande_pierre(95,360,645,<0,180,0>, <1430,0,800>)
    }
#end

#macro dependance_gauche(placement, rotation)
    union
    {
        face_dependance_gauche()
        gauche_dependance_gauche()
        back_dependance_gauche()
        rotate rotation
        translate placement
    }
#end
