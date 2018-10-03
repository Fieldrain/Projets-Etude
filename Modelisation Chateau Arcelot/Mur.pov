#include "colors.inc"
#include "textures.inc"

/*background {<0.4, 0.4, 0.8>}

light_source {<15, 15, -15>   color White }
light_source {<-15, 15, -15>   color White }


//vue devant
camera {location <-400,300, 600>    look_at <2000, 200, 0>  }
//camera {location <300,200, -1000>    look_at <1000, 200, 0>  }

//vue derriere
//camera {location <0,300, 1000>    look_at <0,100, 0>  }

//vue gauche
//camera {location <-25,5, 0>    look_at <0, 4, 0>  }

//vue droite
//camera {location <25,5, 0>    look_at <0, 4, 0>  }

//vue interieur
//camera {location <0,5, 3>    look_at <0, 4, -3>  }


// sol
plane  { <0,1,0>,0 pigment {Tan_Wood }}
               */
//-------scene

//--------------------------------------------------creaation des ouvertures de la piece
#macro ouvertures()
    union{
            //porte de devant
            box{
                     <-1,0.1,-10.5> <1,4,-6.5>
                     pigment{Grey}
            }
            //porte de derriere
            box{
                     <-0.9,0.1,10.5> <0.9,4,6.5>
                     pigment{Grey}
            }
            //fenetre devant gauche
            box{
                     <-3.9,0.7,-8> <-2.5,4,-10>
                     pigment{Grey}
            }
            //fenetre devant droite
            box{
                     <3.9,0.7,-8> <2.5,4,-10>
                     pigment{Grey}
            }
            //fenetre derriere gauche
            box{
                     <-3.9,0.7,8> <-2.5,4,10>
                     pigment{Grey}
            }
            //fenetre derriere droite
            box{
                     <3.9,0.7,8> <2.5,4,10>
                     pigment{Grey}
            }
            scale 100
    }

#end

//---------------------------------boite qui represente la piece
#macro boitePiece()
    box{
             <-5.4,0.1,-8.4> <5.4,5.7,8.4>
             pigment{Red}
             scale 100
    }

#end



//--------------------------------------------------------on cree la piece avec ses ouvertures
#macro piece()
    union {
        difference {
            difference {
                    //chateau
                    box{
                             <-5.5,0,-8.5> <5.5,6,8.5>
                             pigment{White}
                    }
                    boitePiece()
            }

            ouvertures()
         }
    }

#end



//--------------------------------------------------------lumieres interieures
#macro lumieres()

    light_source {<0, 5.4, 4.5>   color White }
    light_source {<0, 5.4, -4.5>   color White }
#end


//--------------------------------------------------------murs sol et plafond
#macro murs()
    //sol
    box{
             <-5.49,0,-8.99> <5.49,0.201,8.99>
             //rotate qui permet de plaquer la texture comme il faut
             rotate <90,0,0>
             texture {pigment{image_map{png "image/text_carrelage.png" map_type 0}} scale <1,1,1>}
             rotate <-90,0,0>

    }

    //plafond
    box{
             <-5.49,5.675,-8.99> <5.49,6.0,8.99>
             rotate <-90,0,0>
             texture {pigment{image_map{jpeg "image/text_plafond3.jpg" map_type 0} scale <1,1,1> } }
             rotate <90,0,0>

    }

    //mur de gauche
    box{
             <-5.49,0.201,-8.99> <-5.23,5.675,8.99>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/text_mur.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>

    }

    //mur de droite
    box{
             <5.23,0.201,-8.99> <5.49,5.675,8.99>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/text_mur.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>

    }

    //mur du fond
    box{  <-5.49,0.201,8.73> <5.49,5.675,8.99>
          texture {pigment{image_map{jpeg "image/text_mur.jpg" map_type 0} scale <1,1,1> } }

    }


    //mur de devant
    box{
             <-5.49,0.201,-8.99> <5.0,5.625,-8.73>
             texture {pigment{image_map{jpeg "image/text_mur.jpg" map_type 0} scale <1,1,1> } }

    }


    //mur central
    difference {
            difference {
                    //mur
                    box{
                             <-5.5,0.201,-0.25> <5.5,5.825,0.25>
                             texture {pigment{image_map{jpeg "image/text_mur.jpg" map_type 0} scale <1,1,1> } }

                    }
                    //porte
                    box{
                             <-1,0.2,-0.5> <1,4,0.5>
                             pigment{Grey}
                    }
            }

            //voute
            sphere{
                            <0,0,0>, 1.2
                            scale<1,0.5,1>
                            translate <0,4,0>
                            pigment{Grey}
            }
    }

#end


//-------------------------------------------------------pilliers de la porte centrale
#macro pillierDroit()
    union
    {
            //base
            box
            {
                    <0.1,0,-0.05> <0.9,0.4,0.4>
                    texture
                    {
                            pigment{image_map {png "image/text_brillant.png" map_type 0 once} }
                            scale <1, 1.6, 1>
                    }
            }

            //pillier
            box
            {
                    <0.2,0,0> <0.8,4,0.4>
                    texture
                    {
                            pigment{image_map {png "image/text_pillier.png" map_type 0 once} }
                            scale <1, 4, 1>
                    }
            }

            //1ere d�co
            box
            {
                    <0.15,1.35,-0.05> <0.85,1.65,0.45>
                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 1.65, 1>
                    }
            }

            //2eme d�co
            box
            {
                    <0.1,1.4,-0.1> <0.9,1.6,0.5>
                    texture
                    {
                            pigment{image_map {png "image/text_brillant.png" map_type 0 once} }
                            scale <1, 1.6, 1>
                    }
            }

            //bec haut
            difference
            {
                    box
                    {
                            <0,3.6,0> <0.8,4,0.4>
                    }

                    cylinder
                    {
                            <-0.005,3.6,-0.05> <-0.005,3.6,0.405> 0.4
                            scale <-0.4,1,1>
                    }
                    texture
                    {
                            pigment{image_map {png "image/text_pillier.png" map_type 0 once} }
                            scale <1, 4, 1>
                    }
            }

            //1er trait
            union
            {
                    box
                    {
                            <0.2,3.5,-0.1> <0.8,3.6,0.5>
                    }

                    cylinder
                    {
                            <0.2,3.55,-0.1> <0.2,3.55,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,3.55,-0.1> <0.8,3.55,0.5> 0.05

                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 3.6, 1>
                    }
            }




            //2eme trait
            union
            {
                    box
                    {
                            <0.15,3.75,-0.1> <0.8,3.85,0.5>
                    }

                    cylinder
                    {
                            <0.15,3.8,-0.1> <0.15,3.8,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,3.8,-0.1> <0.8,3.8,0.5> 0.05

                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 3.85, 1>
                    }
            }

            //3eme trait
            union
            {
                    box
                    {
                            <0.05,3.95,-0.1> <0.8,4.05,0.5>

                    }

                    cylinder
                    {
                            <0.05,4,-0.1> <0.05,4,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,4,-0.1> <0.8,4,0.5> 0.05
                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 4.05, 1>
                    }
            }

            translate <8.2,0,0>

    }
#end

//-----------------------------------------------pillier gauche
#macro pillierGauche()
    union
    {
            //base
            box
            {
                    <0.1,0,0> <0.9,0.4,0.45>
                    texture
                    {
                            pigment{image_map {png "image/text_brillant.png" map_type 0 once} }
                            scale <1, 1.6, 1>
                    }
            }

            //pillier
            box
            {
                    <0.2,0,0> <0.8,4,0.4>
                    texture
                    {
                            pigment{image_map {png "image/text_pillier.png" map_type 0 once} }
                            scale <1, 4, 1>
                    }
            }

            //1ere d�co
            box
            {
                    <0.15,1.35,-0.05> <0.85,1.65,0.45>
                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 1.65, 1>
                    }
            }

            //2eme d�co
            box
            {
                    <0.1,1.4,-0.1> <0.9,1.6,0.5>
                    texture
                    {
                            pigment{image_map {png "image/text_brillant.png" map_type 0 once} }
                            scale <1, 1.6, 1>
                    }
            }

            //bec haut
            difference
            {
                    box
                    {
                            <0,3.6,0> <0.8,4,0.4>
                    }

                    cylinder
                    {
                            <-0.005,3.6,-0.05> <-0.005,3.6,0.405> 0.4
                            scale <-0.4,1,1>
                    }

                    texture
                    {
                            pigment{image_map {png "image/text_pillier.png" map_type 0 once} }
                            scale <1, 4, 1>
                    }
            }

            //1er trait
            union
            {
                    box
                    {
                            <0.2,3.5,-0.1> <0.8,3.6,0.5>
                    }

                    cylinder
                    {
                            <0.2,3.55,-0.1> <0.2,3.55,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,3.55,-0.1> <0.8,3.55,0.5> 0.05

                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 3.6, 1>
                    }
            }




            //2eme trait
            union
            {
                    box
                    {
                            <0.15,3.75,-0.1> <0.8,3.85,0.5>
                    }

                    cylinder
                    {
                            <0.15,3.8,-0.1> <0.15,3.8,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,3.8,-0.1> <0.8,3.8,0.5> 0.05

                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 3.85, 1>
                    }
            }

            //3eme trait
            union
            {
                    box
                    {
                            <0.05,3.95,-0.1> <0.8,4.05,0.5>

                    }

                    cylinder
                    {
                            <0.05,4,-0.1> <0.05,4,0.5> 0.05
                    }

                    cylinder
                    {
                            <0.8,4,-0.1> <0.8,4,0.5> 0.05
                    }

                    texture
                    {
                            pigment{image_map {png "image/text_noir.png" map_type 0 once} }
                            scale <1, 4.05, 1>
                    }
            }





            translate <-5.75,0,-0.4>
            rotate <0,180,0>

    }
#end


//--------------------------------------------------------porte centrale
#macro porteCentrale()
    union
    {

            //porte gauche
            union
            {
                    box
                    {
                            <0,0,0> <1,4,0.05>
                            texture
                            {
                                    pigment{image_map {png "image/porte_gauche.png" map_type 0 interpolate 2} }
                                    scale <1, 4, 1>
                            }
                    }

                    box
                    {
                            <0.1,3.4,0.04> <0.9,3.8,0.05>
                            texture{Glass}
                            //pigment{color Red}
                    }

                    box
                    {
                            <0.1,3.4,0> <0.9,3.8,0.02>
                            texture{Glass}
                            //pigment{color Red}
                    }

                    rotate<0,-90,0>
                    translate <6,0,0.395>
            }

            union
            {
                    box
                    {
                            <0,0,0> <1,4,0.05>
                            texture
                            {
                                    pigment{image_map {png "image/porte_droite.png" map_type 0 interpolate 2} }
                                    scale <1, 4, 1>
                            }
                            translate <1,0,0>
                    }

                    box
                    {
                            <1.1,3.4,0.04> <1.9,3.8,0.05>
                            texture{Glass}
                            //pigment{color Red}
                    }

                    box
                    {
                            <1.1,3.4,0> <1.9,3.8,0.02>
                            texture{Glass}
                            //pigment{color Red}
                    }

                    rotate<0,90,0>
                    translate <8,0,2.395>
            }


    }
#end

//-------------------------------------------------------------------porte pi�ce 2
#macro porte2()
    union
    {
            //entourage
            difference{
                box{
                        <-4.6,0,2.5> <-5,5,5.5>
                        texture
                        {
                                pigment{image_map {jpeg "image/bois3.jpg"} rotate<0,90,0>}

                        }
                }
                box{
                        <-4.5,0,3> <-5.2,4.5,5>
                }
            }
            //porte
            box
            {
                    <-4.9,0,3> <-5,4.5,5>
                    texture
                    {
                            pigment{image_map {png "image/porte2.png"}}
                            rotate<0,90,0>
                            scale<1,5,2>
                            translate<0,0,1>
                    }
            }

    }
#end

//---------------------------------------------------------------------entourage de la porte
#macro entouragePorte()
    union
    {
            box
            {
                    <0,0,0> <0.2,4,0.05>
                    texture
                    {
                            pigment{image_map {png "image/text_bois.png" map_type 0 once} }
                            scale <1, 4, 1>
                    }
                    rotate<0,0,0>
            }

            box
            {
                    <2.2,0,0> <2.4,4,0.05>
                    texture
                    {
                            pigment{image_map {png "image/text_bois.png" map_type 0 once} }
                            scale <2.4, 4., 1>
                    }
                    rotate<0,0,0>
            }

            box
            {
                    <0,4,0> <2.4,4.2,0.05>
                    texture
                    {
                            pigment{image_map {png "image/text_bois.png" map_type 0 once} }
                            scale <2.4, 4.2, 1>
                    }
                    rotate<0,0,0>
            }


            union
            {

                    difference
                    {

                            difference
                            {
                                    cylinder
                                    {
                                            <1.97,9.45,0> <1.97,9.45,0.1> 2.2
                                            scale<0.6,0.4,1>

                                    }

                                    box
                                    {
                                            <-2,2,-0.05> <4,4.2,0.105>
                                    }
                            }


                            cylinder
                            {
                                    <1.97,9.25,-0.05> <1.97,9.25,0.205> 2
                                    scale<0.6,0.4,1>
                            }
                    }

                    difference
                    {
                            cylinder
                            {
                                    <1.97,9.25,0.1> <1.97,9.25,0.15> 2
                                    scale<0.6,0.4,1>
                            }


                            box
                            {
                                    <-2,2,0.05> <4,4.2,0.2>
                            }


                            texture{Glass3}

                    }


                    texture
                    {
                            pigment{image_map {png "image/text_bois.png" map_type 0 once} }
                            scale <2.5, 9.45, 1>
                    }

            }

            translate <5.8,0,0.36>
    }
#end



//------------------------------------------------------------------------arc
#macro arc()

            difference
            {


                            difference
                            {
                                    cylinder
                                    {
                                            <0.8,4,0> <0.8,4,0.4> 2
                                            scale<1,0.6,1>
                                            translate <6.18,1.6,0>
                                    }

                                    box
                                    {
                                            <-1.5,0,-0.05> <3,4,0.405>
                                            translate <6.18,0,0>
                                    }
                            }


                    cylinder
                    {
                            <0.8,4,-0.05> <0.8,4,0.405> 2.2
                            scale<0.6,0.4,1>
                            translate <6.5,2.2,0>
                    }

                    texture
                    {
                            pigment{image_map {png "image/text_voute3.png" map_type 0 once} }
                            scale <11, 6, 1>
                    }
            }

#end

//----------------------------------------------------------------------totalit� de la porte centrale
#macro porteGlobale()
    union{
        pillierDroit()
        pillierGauche()
        porteCentrale()
        entouragePorte()
        arc()
        translate <-7,0,-0.65>
    }
#end

//------------------------------------------------------meuble en bois
#macro meubles()
    union{
        difference{
            box {
                <4,0,-3> <5,2.1,-6>
                 texture {pigment{image_map{jpeg "image/bois3.jpg" map_type 0}}}
            }
            box{
                <3.9,0.5,-3.5> <4.8,1.9,-5.5>
                 texture {pigment{image_map{jpeg "image/bois3.jpg" map_type 0}}}
            }
        }
        box {
            <4,0,-1> <5,1,-2>
             texture {pigment{image_map{jpeg "image/bois3.jpg" map_type 0}}}
        }
    }
#end

//------------------------------------------------------oiseaux

#declare i=0 ;

#macro oiseaux()

    #while (i<0.05)
        box{
                 <4.5+i,2.1,-5> <4.501+i,3,-6>
                 rotate <0,90,0>
                 texture {pigment{image_map{png "image/avocette2.png" map_type 0} scale <1,1,1> } }
                 rotate <0,-90,0>
        }
        box{
                 <4.5+i,2.1,-3> <4.501+i,3,-4>
                 rotate <0,90,0>
                 texture {pigment{image_map{png "image/sarcelle2.png" map_type 0} scale <1,1,1> } }
                 rotate <0,-90,0>
        }
        box{
                 <4+i,2.1,-4> <4.01+i,3,-5>
                 rotate <0,90,0>
                 texture {pigment{image_map{png "image/becassine2.png" map_type 0} scale <1,1,1> } }
                 rotate <0,-90,0>
        }
        box{
                  <4.5+i,1,-1> <4.51+i,2,-2>
                 rotate <0,90,0>
                 texture {pigment{image_map{png "image/pilet2.png" map_type 0} scale <1,1,1> } }
                 rotate <0,-90,0>
        }
        #declare i = i+0.005;
    #end
#end

//----------------------------------------------------------------------tableaux
#macro tableaux()
    //tableau 1
    box{
             <-5.2,3,-3> <-4.9,4,-2>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/canard1.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }

    //tableau 2
    box{
             <-5.2,3,-5> <-4.9,4,-4>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/canard2.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }

    //tableau 3
    box{
             <-5.2,3,-4> <-4.9,4,-3>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/canard3.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }
    //tableau 4
    box{
             <5.2,3,4> <4.9,4,3>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/tableau2.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }
    //tableau 5
    box{
             <5.2,3,5> <4.9,4,6>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/tableau1.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }
    //tableau 5
    box{
             <5.2,3,5> <4.9,4,4>
             rotate <0,90,0>
             texture {pigment{image_map{jpeg "image/tableau3.jpg" map_type 0} scale <1,1,1> } }
             rotate <0,-90,0>
    }
#end

//---------------------------------------------------------------------table
#macro table()
    union{
        cylinder{ <0,0,4> <0,0.3,4> 0.5 texture {pigment{
                                                        image_map{jpeg "image/marbre1.jpg" map_type 0 }
                                                      }
                                                  rotate <90,0,0>
                                                }
                }
        cylinder{ <0,0.3,4><0,1.5,4> 0.1 texture {pigment{
                                                          image_map{jpeg "image/marbre1.jpg" map_type 0}
                                                        }
                                                  }
                }
        cylinder{ <0,1.5,4> <0,1.6,4> 1.4 texture {pigment{
                                                            image_map{jpeg "image/marbre1.jpg" map_type 0 }
                                                        }
                                                  rotate <90,0,0>
                                                  scale <0.7,1,1>
                                                  }
        }
    }
#end

//------------------------------------------------------------------------AGENCEMENT DE LA PIECE
#macro interieur()
    union {
        lumieres()
        porteGlobale()
        porte2()
        tableaux()
        meubles()
        oiseaux()
        table()
        scale 100
    }
#end


//-------------MAIN
