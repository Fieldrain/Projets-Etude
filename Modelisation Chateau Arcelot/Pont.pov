#include "colors.inc"
#include "textures.inc"
#include "woods.inc"         

/*sky_sphere{
           pigment{
                   gradient <0,1,0> color_map{ [0 color rgb<0.75,0.75,0.75>]
                                               [0.4 color rgb<0.14,0.14,0.56>]
                                               [0.6 color rgb<0.14,0.14,0.56>]
                                               [1.0 color rgb<0.75,0.75,0.75>]
                                             }
                   scale 2 
                  }
}
    
       
light_source{<0,200,0> color White}  
                          
camera{ location  <6.5,150,-800>  //<6.5,150,-800> -> face  // <-900,80,0> -> côté  //<-500,80,-250> -> côté avant pont 
        look_at   <-6.5,40,0>  //<-6.5,40,0> -> face  // <0,40,0> -> côté  //<0,40,-250> -> côté avant pont  
      }  


plane{<0,1,0>, 0 pigment {color White}}  */



#macro PoteauAvecSphere(X,Y,Z)
    union{
        box{<-3,-32.5,-3><3,32.5,3> pigment{color Red} translate<0,32.5,0>}      
        cone{<0,-1,0> 3 <0,1,0> 0 pigment{color Red} translate<0,66,0>}
        sphere{<0,0,0> 5 pigment{color Red} translate<0,71.5,0>}
        translate<X,Y,Z>
    }
#end 

#macro PoteauSimple(X,Y,Z)
    box{<-3,-32.5,-3><3,32.5,3> pigment{color Red} translate<0,32.5,0> translate<X,Y,Z>}      
#end 

#macro Grille(angleR,X,Y,Z)
    intersection{
        box{<-50,-17.5,-1.6><50,17.5,1.6> pigment{color Black}} //legerement plus profond (en z) pour l'intersection
        union{
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<0,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<-25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<-51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<0,0,0>} 
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<-25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<-51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<51,0,0>}
        }
        rotate<0,0,angleR> rotate<0,90,0> translate<X,Y,Z>
    }
#end

#macro GrilleExcentre(angleRX,angleRY,X,Y,Z)
    intersection{
        box{<-50,-17.5,-1.6><50,17.5,1.6> pigment{color Black}} //legerement plus profond (en z) pour l'intersection
        union{
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<0,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<-25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<-51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,45> translate<51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<0,0,0>} 
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<-25.5,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<-51,0,0>}
            box{<-40,-2.5,-1><40,2.5,1> pigment{color Black} rotate<0,0,-45> translate<51,0,0>}
        }
        rotate<0,0,angleRX> rotate<0,angleRY,0> translate<X,Y,Z>
    }
#end

        
#macro toutesBarresHorizontales()      
    //lien entre deux premiers poteaux gauches   
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,12,0> translate<-110,67.5,-430>} 
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,12,0> translate<-110,52.5,-430>}  
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,12,0> translate<-110,17.5,-430>} 
    
    //lien entre deux premiers poteaux droits    
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,-12,0> translate<110,67.5,-430>} 
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,-12,0> translate<110,52.5,-430>}  
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-12,-12,0> translate<110,17.5,-430>}
    
    //lien entre deux derniers poteaux gauches     
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,-12,0> translate<-110,67.5,430>} 
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,-12,0> translate<-110,52.5,430>}  
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,-12,0> translate<-110,17.5,430>} 
      
    //lien entre deux premiers poteaux droits    
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,12,0> translate<110,67.5,430>} 
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,12,0> translate<110,52.5,430>}  
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<12,12,0> translate<110,17.5,430>}
    
           
    //barres du haut partie gauche
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<-100,95,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<-100,118,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<-100,128,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<-100,132,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<-100,132,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<-100,128,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<-100,118,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<-100,95,330>}
    
    //barres du haut partie droite
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<100,95,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<100,118,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<100,128,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<100,132,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<100,132,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<100,128,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<100,118,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<100,95,330>}
    
    //barres du milieu gauche
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<-100,80,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<-100,103,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<-100,113,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<-100,117,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<-100,117,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<-100,113,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<-100,103,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<-100,80,330>}
    
    //barres du milieu droit
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<100,80,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<100,103,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<100,113,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<100,117,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<100,117,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<100,113,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<100,103,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<100,80,330>} 
    
    //barres du bas gauche
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<-100,45,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<-100,68,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<-100,78,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<-100,82,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<-100,82,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<-100,78,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<-100,68,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<-100,45,330>}
    
    //barres du bas droit
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-18,0,0> translate<100,45,-330>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-8,0,0> translate<100,68,-235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-4,0,0> translate<100,78,-140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<-2,0,0> translate<100,82,-45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<2,0,0> translate<100,82,45>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<4,0,0> translate<100,78,140>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<8,0,0> translate<100,68,235>}
    box{<0,-2.5,-50><0,2.5,50> pigment{color Red} rotate<18,0,0> translate<100,45,330>}

#end
                                                                                    
           
#macro toutesGrilles()   
    //grilles gauches
    Grille(-18,-98.5,62,-331) 
    Grille(-8,-98.5,85,-236)
    Grille(-4,-98.5,95,-141)
    Grille(-2,-98.5,99,-46)
    Grille(2,-98.5,99,46) 
    Grille(4,-98.5,95,141) 
    Grille(8,-98.5,85,236)
    Grille(18,-98.5,62,331)
    
    
    //grilles droites
    Grille(-18,98.5,62,-331) 
    Grille(-8,98.5,85,-236)
    Grille(-4,98.5,95,-141)
    Grille(-2,98.5,99,-46)
    Grille(2,98.5,99,46) 
    Grille(4,98.5,95,141) 
    Grille(8,98.5,85,236)
    Grille(18,98.5,62,331)   
    
    //grilles excentrés (avant et arriere pont)
    GrilleExcentre(-12,102,-108.5,34.5,-431)
    GrilleExcentre(-12,78,108.5,34.5,-431)
    GrilleExcentre(12,78,-108.5,34.5,431)
    GrilleExcentre(12,102,108.5,34.5,431)
#end 

#macro Pont(X,Y,Z,angleRotation)
    union{
        //plancher pont
        difference{                                                                                    
            difference{                                                                                    
                cylinder{<0,-410,0><0,410,0> 100  rotate<90,90,0> scale<1/4,3/4,4> 
                    texture{ pigment{image_map {png "image/planche.png" map_type 2}  rotate<90,0,0> scale<1,1,50>}} 
                }      
                cylinder{<0,-411,0><0,411,0> 90 rotate<90,90,0> scale<1/4,3/4,4>
                    texture{ pigment{image_map {png "image/planche.png" map_type 2}  rotate<90,0,0> scale<1,1,50>}}  
                }
            }
            
            box{<-110,-100,-500><110,0,500>}
            
        }
        
        PoteauAvecSphere(-120,0,-480) //poteau excentré avant gauche
        PoteauAvecSphere(-100,20,-380)//premier poteau boule avant gauche  
        PoteauAvecSphere(120,0,-480)  //poteau excentré avant droit 
        PoteauAvecSphere(100,20,-380) //premier poteau boule avant droit 
    
        PoteauSimple(-100,52,-285)    //tous les poteaux gauches
        PoteauSimple(-100,65,-190)
        PoteauAvecSphere(-100,72,-95) 
        PoteauSimple(-100,76,0)
        PoteauAvecSphere(-100,72,95)
        PoteauSimple(-100,65,190)
        PoteauSimple(-100,52,285)  
    
        PoteauSimple(100,52,-285)    //tous les poteaux droits
        PoteauSimple(100,65,-190)
        PoteauAvecSphere(100,72,-95) 
        PoteauSimple(100,76,0)
        PoteauAvecSphere(100,72,95)
        PoteauSimple(100,65,190)
        PoteauSimple(100,52,285)
    
        PoteauAvecSphere(-120,0,480) //poteau excentré arriere gauche
        PoteauAvecSphere(-100,20,380)//premier poteau boule arriere gauche  
        PoteauAvecSphere(120,0,480)  //poteau excentré arriere droit 
        PoteauAvecSphere(100,20,380) //premier poteau boule arriere droit   
        
        toutesGrilles()
        toutesBarresHorizontales()  
        
        rotate<0,angleRotation,0> translate<X,Y,Z> 
    }
 
#end 
           