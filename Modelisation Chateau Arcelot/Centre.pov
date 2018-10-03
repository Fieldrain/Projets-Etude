#include "TexturePerso.pov"
#include "Mur.pov"

#macro Base(X,Y,Z)
#local longueurMilieu = 1100;
#local longueur = 2800;

#local largeurMilieu = 1800;
#local largeur = 1600;

#local hauteurMilieu = 1175;
#local hauteur = 1100;

#local y1 = -270;
#local y2 = 270-30;

object{
  union{
    difference{
      union{
        difference{
              union{
                box{
                  <-longueur/2,-hauteur/2,-largeur/2>
                  <longueur/2,hauteur/2,largeur/2>
                  texture{T_Wall scale<300,100,1>}
                }

                box{
                  <-longueurMilieu/2,-hauteurMilieu/2,-largeurMilieu/2>
                  <longueurMilieu/2,hauteurMilieu/2,largeurMilieu/2>
                  texture{T_Wall scale<300,100,1>}
                  translate<0,37,0>
                }

                box{
                  <-(longueur+0.1)/2,-hauteur/2,-(largeur-0.1)/2>
                  <(longueur+0.1)/2,hauteur/2,(largeur-0.1)/2>
                  texture{T_Wall rotate<0,90,0> scale<300,100,1>}
                }

                union{
                  //Bordure centre
                  Bordure(longueur,largeur,-20)
                  Bordure(longueurMilieu,largeurMilieu,-20)

                  //Bordure haute
                  Bordure(longueur,largeur,hauteur/2)
                  Bordure(longueurMilieu,largeurMilieu,hauteurMilieu/2+37)

                  texture{T_Wall scale<100,100,100>}
                }
              }

            union{
              #local diff = 50;
              box{
                <-(longueur-diff)/2,-(hauteur-20)/2,-(largeur-diff)/2>
                <(longueur-diff)/2,(hauteur-20)/2,(largeur-diff)/2>

              }
              box{
                <-(longueurMilieu-diff)/2,-(hauteurMilieu-20)/2,-(largeurMilieu-diff)/2>
                <(longueurMilieu-diff)/2,(hauteurMilieu-20)/2,(largeurMilieu-diff)/2>

                translate<0,37,0>
              }
              texture{T_Wall scale<300,100,1>}
            }
          }

          object{union{murs()} scale 100 translate<0,-1100/2,0> }
        }

      //placement Trou pour fenetre avant bas
      TrouFenetre(-longueur/2+210,y1,-largeur/2,1)
      TrouFenetre(-longueur/2+450,y1,-largeur/2,1)
      TrouFenetre(-longueur/2+690,y1,-largeur/2,1)

      TrouFenetre(-longueurMilieu/2+230,y1,-largeurMilieu/2,2)
      TrouFenetre(longueurMilieu/2-230,y1,-largeurMilieu/2,2)

      TrouFenetre(longueur/2-690,y1,-largeur/2,1)
      TrouFenetre(longueur/2-450,y1,-largeur/2,1)
      TrouFenetre(longueur/2-210,y1,-largeur/2,1)

      //placement Trou pour fenetre derriere bas
      TrouFenetre(-longueur/2+210,y1,largeur/2,1)
      TrouFenetre(-longueur/2+450,y1,largeur/2,1)
      TrouFenetre(-longueur/2+690,y1,largeur/2,1)

      TrouFenetre(-longueurMilieu/2+230,y1,largeurMilieu/2,2)
      TrouFenetre(longueurMilieu/2-230,y1,largeurMilieu/2,2)

      TrouFenetre(longueur/2-690,y1,largeur/2,1)
      TrouFenetre(longueur/2-450,y1,largeur/2,1)
      TrouFenetre(longueur/2-210,y1,largeur/2,1)


      //placement Trou pour fenetre avant haut
      TrouFenetre(-longueur/2+210,y2,-largeur/2,3)
      TrouFenetre(-longueur/2+450,y2,-largeur/2,3)
      TrouFenetre(-longueur/2+690,y2,-largeur/2,3)

      TrouFenetre(-longueurMilieu/2+230,y2,-largeurMilieu/2,3)
      TrouFenetre(0,y2,-largeurMilieu/2,3)
      TrouFenetre(longueurMilieu/2-230,y2,-largeurMilieu/2,3)

      TrouFenetre(longueur/2-690,y2,-largeur/2,3)
      TrouFenetre(longueur/2-450,y2,-largeur/2,3)
      TrouFenetre(longueur/2-210,y2,-largeur/2,3)

      //placement Trou pour fenetre derriere haut
      TrouFenetre(-longueur/2+210,y2,largeur/2,3)
      TrouFenetre(-longueur/2+450,y2,largeur/2,3)
      TrouFenetre(-longueur/2+690,y2,largeur/2,3)

      TrouFenetre(-longueurMilieu/2+230,y2,largeurMilieu/2,3)
      TrouFenetre(0,y2,largeurMilieu/2,3)
      TrouFenetre(longueurMilieu/2-230,y2,largeurMilieu/2,3)

      TrouFenetre(longueur/2-690,y2,largeur/2,3)
      TrouFenetre(longueur/2-450,y2,largeur/2,3)
      TrouFenetre(longueur/2-210,y2,largeur/2,3)

      //porte fond
      box{<-90,20,largeurMilieu/2-50>
          <90,420,largeurMilieu/2+2>
          translate<0,-1100/2,0>
      }

      //porte face
      box{<-90,20,-largeurMilieu/2+50>
          <90,420,-largeurMilieu/2-2>
          translate<0,-1100/2,0>
      }

    }
    union{
      //Toit Centrale
      ToitMilieu(longueurMilieu,largeurMilieu,hauteurMilieu/2+37)
      ToitCentre(longueur,largeur,hauteur/2)

      texture{T_Roof}
    }

    union{
      box{<-longueurMilieu/2,0,-largeurMilieu/2-50>
          <longueurMilieu/2,10,-largeurMilieu/2>

      }

      box{<-longueurMilieu/4,10,-largeurMilieu/2-25>
          <longueurMilieu/4,20,-largeurMilieu/2>

      }

      box{<-longueurMilieu/2,0,largeurMilieu/2>
          <longueurMilieu/2,10,largeurMilieu/2+50>
      }

      box{<-longueurMilieu/4,10,largeurMilieu/2>
          <longueurMilieu/4,20,largeurMilieu/2+25>
      }

      texture{ T_Stone3
              normal { agate 0.25 scale 0.15 rotate<0,0,0> }
              finish { phong 1 }
              rotate<0,0,0> scale 0.5 translate<0,0,0>
            } // end of texture

      translate<0,-1100/2,0>
    }
    //placement fenetre avant bas
    Fenetre(-longueur/2+210,y1,-largeur/2,1)
    Fenetre(-longueur/2+450,y1,-largeur/2,1)
    Fenetre(-longueur/2+690,y1,-largeur/2,1)

    Fenetre(-longueurMilieu/2+230,y1,-largeurMilieu/2,2)
    Fenetre(longueurMilieu/2-230,y1,-largeurMilieu/2,2)

    Fenetre(longueur/2-690,y1,-largeur/2,1)
    Fenetre(longueur/2-450,y1,-largeur/2,1)
    Fenetre(longueur/2-210,y1,-largeur/2,1)

    //placement fenetre derriere bas
    Fenetre(-longueur/2+210,y1,largeur/2,1)
    Fenetre(-longueur/2+450,y1,largeur/2,1)
    Fenetre(-longueur/2+690,y1,largeur/2,1)

    Fenetre(-longueurMilieu/2+230,y1,largeurMilieu/2,2)
    Fenetre(longueurMilieu/2-230,y1,largeurMilieu/2,2)

    Fenetre(longueur/2-690,y1,largeur/2,1)
    Fenetre(longueur/2-450,y1,largeur/2,1)
    Fenetre(longueur/2-210,y1,largeur/2,1)

    //placement fenetre avant haut
    Fenetre(-longueur/2+210,y2,-largeur/2,3)
    DecorationFenetreH(-longueur/2+210,y2+240,-largeur/2)
    Fenetre(-longueur/2+450,y2,-largeur/2,3)
    DecorationFenetreH2(-longueur/2+450,y2+240,-largeur/2)
    Fenetre(-longueur/2+690,y2,-largeur/2,3)
    DecorationFenetreH(-longueur/2+690,y2+240,-largeur/2)

    Fenetre(-longueurMilieu/2+230,y2,-largeurMilieu/2,3)
    Fenetre(0,y2,-largeurMilieu/2,3)
    Fenetre(longueurMilieu/2-230,y2,-largeurMilieu/2,3)

    Fenetre(longueur/2-690,y2,-largeur/2,3)
    DecorationFenetreH(longueur/2-690,y2+240,-largeur/2)
    Fenetre(longueur/2-450,y2,-largeur/2,3)
    DecorationFenetreH2(longueur/2-450,y2+240,-largeur/2)
    Fenetre(longueur/2-210,y2,-largeur/2,3)
    DecorationFenetreH(longueur/2-210,y2+240,-largeur/2)

    //placement fenetre derriere haut
    Fenetre(-longueur/2+210,y2,largeur/2,3)
    DecorationFenetreH(-longueur/2+210,y2+240,largeur/2)
    Fenetre(-longueur/2+450,y2,largeur/2,3)
    DecorationFenetreH2(-longueur/2+450,y2+240,largeur/2)
    Fenetre(-longueur/2+690,y2,largeur/2,3)
    DecorationFenetreH(-longueur/2+690,y2+240,largeur/2)

    Fenetre(-longueurMilieu/2+230,y2,largeurMilieu/2,3)
    Fenetre(0,y2,largeurMilieu/2,3)
    Fenetre(longueurMilieu/2-230,y2,largeurMilieu/2,3)

    Fenetre(longueur/2-690,y2,largeur/2,3)
    DecorationFenetreH(longueur/2-690,y2+240,largeur/2)
    Fenetre(longueur/2-450,y2,largeur/2,3)
    DecorationFenetreH2(longueur/2-450,y2+240,largeur/2)
    Fenetre(longueur/2-210,y2,largeur/2,3)
    DecorationFenetreH(longueur/2-210,y2+240,largeur/2)

    //porte avant
    union{
      box{<-45,-200,-2> <45,200,2>
          rotate<0,-90,0>
          translate<-90,220,-1800/2+1>
          texture{pigment{image_map {png "image/porte_gauche.png" map_type 0 interpolate 2} }
                  scale<100,400,100>
                  rotate<0,90,0>
                  translate<0,20,45>
              }

      }

      box{<-45,-200,-2> <45,200,2>
          rotate<0,90,0>
          translate<90,220,-1800/2+1>
          texture{pigment{image_map {png "image/porte_droite.png" map_type 0 interpolate 2} }
                  scale<100,400,100>
                  rotate<0,90,0>
                  translate<0,20,45>
              }

      }

      translate<0,-1100/2,0>
    }

    //porte arriere
    union{
      box{<-45,-200,-2> <45,200,2>

          rotate<0,90,0>
          translate<-90,220,1800/2-2>

          texture{pigment{image_map {png "image/porte_gauche.png" map_type 0 interpolate 2} }
                  scale<100,400,100>
                  rotate<0,90,0>
                  translate<0,20,45>
              }


      }

      box{<-45,-200,-2> <45,200,2>

          rotate<0,-90,0>
          translate<90,220,1800/2-2>

          texture{pigment{image_map {png "image/porte_droite.png" map_type 0 interpolate 2} }
                  scale<100,400,100>
                  rotate<0,90,0>
                  translate<0,20,45>
              }


      }

      translate<0,-1100/2,0>
    }

    object{interieur() translate<0,-1100/2,0>}

    translate<0,1100/2,0>
  }
  translate<X,Y,Z>
}

#end

#macro Bordure(longueur,largeur,hauteur)
#local longueurBasse = longueur+5;
#local longueurMilieu = longueur+10;
#local longueurHaute = longueur+15;

#local largeurBasse = largeur+10;
#local largeurMilieu = largeur+15;
#local largeurHaute = largeur+20;

#local hauteurBasse = 30;
#local hauteurMilieu = 22;
#local hauteurHaute = 17;

union{
  box{
    <-longueurBasse/2,-hauteurBasse/2,-largeurBasse/2>
    <longueurBasse/2,hauteurBasse/2,largeurBasse/2>

  }
  box{
    <-longueurMilieu/2,-hauteurMilieu/2,-largeurMilieu/2>
    <longueurMilieu/2,hauteurMilieu/2,largeurMilieu/2>

    translate<0,8,0>
  }
  box{
    <-longueurHaute/2,-hauteurHaute/2,-largeurHaute/2>
    <longueurHaute/2,hauteurHaute/2,largeurHaute/2>

    translate<0,13,0>
  }
  translate<0,hauteur,0>
}

#end

#macro ToitMilieu(longueur,largeur,hauteur)
#local hauteurHautToit = 100;
#local hauteurBaseToit = 250;
#local hauteurCylindre = 70;
#local rayon = 170;

union{
  prism{ -largeur/2, largeur/2, 4
    <-longueur/2, 0.00>,
    < longueur/2, 0.00>,
    < 0.00, hauteurHautToit>,
    <-longueur/2, 0.00>

    rotate<-90,0,0>
    scale<0.815,1,1>
    translate<0,hauteurBaseToit/2,0>
  }
  difference{
    box{
      <-longueur/2,-hauteurBaseToit/2,-largeur/2>
      <longueur/2,hauteurBaseToit/2,largeur/2>

    }
    cylinder{
      <-longueur/2,hauteurCylindre,-largeur/2>
      <longueur/2,hauteurCylindre,-largeur/2>
      rayon

      scale<1,2,1>
      rotate<-2,0,>
    }
    cylinder{
      <-longueur/2,hauteurCylindre,-largeur/2>
      <-longueur/2,hauteurCylindre,largeur/2>
      rayon

      scale<1,2,1>
      rotate<0,0,-2>
    }
    cylinder{
      <longueur/2,hauteurCylindre,-largeur/2>
      <longueur/2,hauteurCylindre,largeur/2>
      rayon

      scale<1,2,1>
      rotate<0,0,2>
    }
    cylinder{
      <-longueur/2,hauteurCylindre,largeur/2>
      <longueur/2,hauteurCylindre,largeur/2>
      rayon

      scale<1,2,1>
      rotate<2,0,0>
    }
    scale<1.2,1,1.2>

  }
  translate<0,hauteur+hauteurBaseToit/1.7,0>
}

#end

#macro ToitCentre(longueur,largeur,hauteur)
#local hauteurToit = 350;

prism{ -longueur/2, longueur/2, 4
  <-largeur/2, 0.00>,
  < largeur/2, 0.00>,
  < 0.00, hauteurToit>,
  <-largeur/2, 0.00>

  scale<1.025,1.005,1>
  rotate<-90,-90,0>
  translate<0,hauteur+20,0>
}


#end



#macro DecorationFenetreH(X,Y,Z)
#local longueur = 140;

#local largeur = 5;

#local hauteur = 50;

union{
  box{
    <-longueur/2,-hauteur/2,-largeur/2>
    <longueur/2,hauteur/2,largeur/2>
    texture{T_Wall scale<1500,1500,1500>}
  }

  Chaine()


  translate<X,Y,Z>
}

#end

#macro DecorationFenetreH2(X,Y,Z)
#local longueur = 120;
#local longueurB = 50;

#local largeur = 5;

#local hauteur = 50;
difference{
  union{
    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>

    }

    prism{ -largeur/2, largeur/2, 4
      <-longueurB/2, 0.00>,
      < longueurB/2, 0.00>,
      < 0.00, hauteur>,
      <-longueurB/2, 0.00>

      rotate<-90,0,90>
      translate<70,0,0>
    }

    prism{ -largeur/2, largeur/2, 4
      <-longueurB/2, 0.00>,
      < longueurB/2, 0.00>,
      < 0.00, hauteur>,
      <-longueurB/2, 0.00>

      rotate<-90,0,-90>
      translate<-70,0,0>
    }




  }
  box{
    <-1.5,-1.5,-3>
    <1.5,1.5,3>
    translate<-longueur/2,0,0>
  }

  box{
    <-1.5,-1.5,-3>
    <1.5,1.5,3>
    translate<longueur/2,0,0>
  }

  texture{T_Wall scale<1500,1500,1500>}

  translate<X,Y,Z>
}

#end

#macro Chaine()
  union{
    //chaine gauche
    sphere{ <0,0,0>, 5 translate<-63.5,-5,0>}
    sphere{ <0,0,0>, 5 translate<-62.5,0,0>}
    sphere{ <0,0,0>, 5 translate<-61.5,5,0>}
    sphere{ <0,0,0>, 5 translate<-60,10,0>}
    sphere{ <0,0,0>, 5 translate<-58.5,15,0>}
    sphere{ <0,0,0>, 5 translate<-57,20,0>}
    sphere{ <0,0,0>, 5 translate<-55.5,25,0>}

    //chaine droite
    sphere{ <0,0,0>, 5 translate<63.5,-5,0>}
    sphere{ <0,0,0>, 5 translate<62.5,0,0>}
    sphere{ <0,0,0>, 5 translate<61.5,5,0>}
    sphere{ <0,0,0>, 5 translate<60,10,0>}
    sphere{ <0,0,0>, 5 translate<58.5,15,0>}
    sphere{ <0,0,0>, 5 translate<57,20,0>}
    sphere{ <0,0,0>, 5 translate<55.5,25,0>}

    #local total = 40;

    #local j=0;
    #local x1 = -55.5;
    #local y1 = 30;

    //haut chaine gauche
    #while(j<total & y1>-7 & x1<-25)
      #local x1 = x1 + 1.25;
      #local y1 = y1 - 1;

      sphere{ <0,0,0>, 5 translate<x1,y1,0>}

      #local j = j+1;
    #end

    #local j=0;
    #while(j<total & y1>-5 & x1<0)
      #local x1 = x1 + 1.25;
      #local y1 = y1 - 0.315;

      sphere{ <0,0,0>, 5 translate<x1,y1,0>}

      #local j = j+1;
    #end

    //haut chaine droite
    #local j=0;
    #local x1 = 55.5;
    #local y1 = 30;

    #while(j<total & y1>-7 & x1>25)
      #local x1 = x1 - 1.25;
      #local y1 = y1 - 1;

      sphere{ <0,0,0>, 5 translate<x1,y1,0>}

      #local j = j+1;
    #end

    #local j=0;
    #while(j<total & y1>-5 & x1>0)
      #local x1 = x1 - 1.25;
      #local y1 = y1 - 0.315;

      sphere{ <0,0,0>, 5 translate<x1,y1,0>}

      #local j = j+1;
    #end

    texture{ Spun_Brass
      finish { phong 1 }
      scale 0.5
      translate<0,1,0>
    } // end of texture ---------------------------


    translate<0,-10,0>
  }

#end

#macro Carreau(X,Y,Z,T,Rx,Ry,Rz)

  #local largeur = 2;

  #if(T=1)
    #local longueur = 60;
    #local hauteur = 70;

    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>

      material{ M_Window}

      translate <X,Y,Z>
    }
  #else
    #local longueur = 65;
    #local hauteur = 53;

    prism{ -largeur/2, largeur/2, 4
      <-longueur/2, 0.00>,
      < longueur/2, 0.00>,
      < 0.00, hauteur>,
      <-longueur/2, 0.00>

      material{M_Window}

      rotate<Rx,Ry,Rz>

      translate <X,Y,Z>
    }
  #end


#end

#macro CadreFenetre(X,Y,Z,T)
#local longueur = 140;
#local hauteur = 330;
#local largeur = 4;

#local longueurC = 60;
#local hauteurC = 70;
#local largeurC = 5;

#local longueurC2 = 65;
#local hauteurC2 = 53;

union{
  difference{
    #if(T=1)
      box{
        <-longueur/2,-hauteur/2,-largeur/2>
        <longueur/2,hauteur/2,largeur/2>

      }

      //carreau premiere ligne
      box{
        <-longueurC/2,-hauteurC/2,-largeurC/2>
        <longueurC/2,hauteurC/2,largeurC/2>

        translate <-longueur/2+38,hauteur/2-47,0>
      }

      box{
        <-longueurC/2,-hauteurC/2,-largeurC/2>
        <longueurC/2,hauteurC/2,largeurC/2>

        translate <-longueur/2+(longueur-38),hauteur/2-47,0>
      }
    #else
      union{
        box{
          <-longueur/2,-hauteur/2,-largeur/2>
          <longueur/2,(hauteur-138)/2,largeur/2>
        }

        cylinder{
          <0,0,-largeur/2>
          <0,0,largeur/2>
          longueur/2
          translate <0,(hauteur-138)/2,0>
        }


      }
      //carreau premiere ligne
      prism{ -largeurC/2, largeurC/2, 4
        <-longueurC2/2, 0.00>,
        < longueurC2/2, 0.00>,
        < 0.00, hauteurC2>,
        <-longueurC2/2, 0.00>

        rotate<90,0,-57.5>
        translate <-longueur/2+50,hauteur/2-55,0>
      }

      prism{ -largeurC/2, largeurC/2, 4
        <-longueurC2/2, 0.00>,
        < longueurC2/2, 0.00>,
        < 0.00, hauteurC2>,
        <-longueurC2/2, 0.00>

        rotate<90,0,57.5>
        translate <-longueur/2+(longueur-50),hauteur/2-55,0>
      }

      prism{ -largeurC/2, largeurC/2, 4
        <-longueurC2/2, 0.00>,
        < longueurC2/2, 0.00>,
        < 0.00, hauteurC2>,
        <-longueurC2/2, 0.00>

        rotate<90,0,0>
        translate <0,hauteur/2-28,0>
      }
    #end

    #local j = 0;
    #local y1 = hauteur/2-65;


    #while(j<3)
      #local y1 = y1 - (longueurC+15);

      //carreau Gauche
      box{
        <-longueurC/2,-hauteurC/2,-largeurC/2>
        <longueurC/2,hauteurC/2,largeurC/2>

        translate <-longueur/2+38,y1,0>
      }

      //carreau droite
      box{
        <-longueurC/2,-hauteurC/2,-largeurC/2>
        <longueurC/2,hauteurC/2,largeurC/2>

        translate <-longueur/2+(longueur-38),y1,0>
      }

      #local j = j+1;
    #end


    texture{ White_Wood
      normal { wood 0.5 scale 0.3 turbulence 0.1}
      finish { phong 1 }
      rotate<60,0,45> scale 0.2
    } // end of texture



  }

  //carreau premiere ligne
  #if (T=1)
    Carreau(-longueur/2+38,hauteur/2-47,0,1,0,0,0)
    Carreau(-longueur/2+(longueur-38),hauteur/2-47,0,1,0,0,0)
  #else
    Carreau(-longueur/2+50,hauteur/2-55,0,2,90,0,-57.5)
    Carreau(-longueur/2+(longueur-50),hauteur/2-55,0,2,90,0,57.5)
    Carreau(0,hauteur/2-28,0,2,90,0,0)

  #end

  //carreau gauche

  Carreau(-longueur/2+38,hauteur/2-150,0,1,0,0,0)
  Carreau(-longueur/2+38,hauteur/2-220,0,1,0,0,0)
  Carreau(-longueur/2+38,hauteur/2-290,0,1,0,0,0)

  //carreau droite

  Carreau(-longueur/2+(longueur-38),hauteur/2-150,0,1,0,0,0)
  Carreau(-longueur/2+(longueur-38),hauteur/2-220,0,1,0,0,0)
  Carreau(-longueur/2+(longueur-38),hauteur/2-290,0,1,0,0,0)


  translate <X,Y,Z>
}

#end


#macro Contour(largeur,longueur,hauteur,T)
  #if(T=1)
    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>
      texture{T_Wall scale<100,100,100>}
    }

  #else
  #if (T=2)
    union{
      box{
        <-longueur/2,-hauteur/2,-largeur/2>
        <longueur/2,(hauteur-138)/2,largeur/2>
        texture{T_Wall scale<100,100,100>}
      }

      cylinder{
        <0,-largeur/2,0>
        <0,largeur/2,0>
        longueur/2
        rotate<90,0,0>
        translate <0,(hauteur-138)/2,0>
        texture{T_Wall scale<100,100,100>}

      }


    }
  #else
    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>
      texture{T_Wall scale<100,100,100>}
    }


    #end
  #end
#end

#macro OuvertureFenetre(X,Y,Z,T)
#local longueur = 160;
#local hauteur = 350;
#local largeur = 50;

#local longueur2 = 140;
#local hauteur2 = 330;
#local largeur2 = 61;

#local longueur3 = 180;
#local hauteur3 = 370;
#local largeur3 = 56;

difference{
  union{
    difference{
      #if(T=1)
        union{
          Contour(largeur3,longueur3,hauteur3,T)
          prism{ -largeur3/2, largeur3/2, 4
            <-longueur/2, 0.00>,
            < longueur/2, 0.00>,
            < 0.00, 150>,
            <-longueur/2, 0.00>
            texture{T_Wall rotate<90,0,0> scale<250,250,250>}
            rotate<90,0,0>
            translate <0,hauteur/2+50,0>
          }
        }
      #else
        Contour(largeur3,longueur3,hauteur3,T)
      #end

      Contour(largeur+10,longueur,hauteur,T)

    }

    Contour(largeur,longueur,hauteur,T)

    #if(T=1)
      prism{ -(largeur+10)/2, (largeur+10)/2, 4
        <-50/2, 0.00>,
        < 50/2, 0.00>,
        < 0.00, 200>,
        <-50/2, 0.00>
        texture{T_Wall rotate<90,0,0> scale<250,250,250>}
        rotate<90,0,0>
        translate <0,hauteur/2+50,0>
      }
    #else
    #if (T=2)
      prism{ -(largeur+10)/2, (largeur+10)/2, 4
        <-50/2, 0.00>,
        < 50/2, 0.00>,
        < 0.00, 200>,
        <-50/2, 0.00>
        texture{T_Wall rotate<90,0,0> scale<250,250,250>}
        rotate<90,0,0>
        translate <0,hauteur/2+50,0>
      }
    #end

    #end
  }

  Contour(largeur2,longueur2,hauteur2,T)

  translate <X,Y,Z>
}

#end

#macro TrouFenetre(X,Y,Z,T)

#local longueur = 160;
#local hauteur = 350;
#local largeur = 70;

#local longueur2 = 140;
#local hauteur2 = 330;
#local largeur2 = 81;

#local longueur3 = 180;
#local hauteur3 = 370;
#local largeur3 = 76;

union{
  union{
    union{
      #if(T=1)
        union{
          TrouContour(largeur3,longueur3,hauteur3,T)

          prism{ -largeur3/2, largeur3/2, 4
            <-longueur/2, 0.00>,
            < longueur/2, 0.00>,
            < 0.00, 150>,
            <-longueur/2, 0.00>
            rotate<90,0,0>
            translate <0,hauteur/2+50,0>
          }
      }
      #else
        TrouContour(largeur3,longueur3,hauteur3,T)
      #end


      TrouContour(largeur+10,longueur,hauteur,T)

    }

    TrouContour(largeur,longueur,hauteur,T)

    #if(T=1)
      prism{ -(largeur+10)/2, (largeur+10)/2, 4
        <-50/2, 0.00>,
        < 50/2, 0.00>,
        < 0.00, 200>,
        <-50/2, 0.00>
        rotate<90,0,0>
        translate <0,hauteur/2+50,0>
      }
    #else
    #if (T=2)
      prism{ -(largeur+10)/2, (largeur+10)/2, 4
        <-50/2, 0.00>,
        < 50/2, 0.00>,
        < 0.00, 200>,
        <-50/2, 0.00>
        rotate<90,0,0>
        translate <0,hauteur/2+50,0>
      }
    #end

    #end

  }

  TrouContour(largeur2,longueur2,hauteur2,T)

  translate <X,Y,Z>
}

#end

#macro TrouContour(largeur,longueur,hauteur,T)
  #if(T=1)
    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>
    }
  #else
    #if (T=2)
    union{
      box{
        <-longueur/2,-hauteur/2,-largeur/2>
        <longueur/2,(hauteur-138)/2,largeur/2>

      }

      cylinder{
        <0,-largeur/2,0>
        <0,largeur/2,0>
        longueur/2
        rotate<90,0,0>
        translate <0,(hauteur-138)/2,0>
      }
    }
    #else
    box{
      <-longueur/2,-hauteur/2,-largeur/2>
      <longueur/2,hauteur/2,largeur/2>
    }
    #end
  #end

#end

#macro Fenetre(X,Y,Z,T)

union{

  #if(T=1)
    OuvertureFenetre(0,0,0,1)
    CadreFenetre(0,0,0,1)

  #else
    #if (T=2)
    OuvertureFenetre(0,0,0,2)
    CadreFenetre(0,0,0,2)
    #else
    OuvertureFenetre(0,0,0,3)
    CadreFenetre(0,0,0,1)
    #end
  #end

  translate <X,Y,Z>
}

#end
