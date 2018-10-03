#include "colors.inc"
#include "textures.inc"
#include "stones.inc"

#declare T_Wall = texture{
                            pigment{image_map {
                                              png "image/I_Wall.png" // the file to read (iff/tga/gif/png/jpeg/tiff/sys)
                                              map_type 0        // 0=planar, 1=spherical, 2=cylindrical, 5=torus
                                              interpolate 2     // 0=none, 1=linear, 2=bilinear, 4=normalized distance
                                              }

                                   }
                            normal{bump_map {
                                              png "image/BM_Wall.png" // the file to read (iff/tga/gif/png/jpeg/tiff/sys)
                                              map_type 0        // 0=planar, 1=spherical, 2=cylindrical, 5=torus
                                              interpolate 2
                                              }
                                    }

                    }

#declare M_Window = material{texture{ pigment{ rgbf <0.98, 0.98, 0.98, 0.9> }
                                      finish { diffuse 0.1 reflection 0.2
                                      specular 0.8 roughness 0.0003 phong 1 phong_size 400}
                                     }
                             interior{ ior 1.5 caustics 0.5}

}

#declare T_Roof = texture{ pigment{ brick color Gray10                // color mortar
                                    color Gray10    // color brick
                  									brick_size <0.5, 0.125, 0.25> // format in x ,y and z- direction
                  									mortar 0.01                      // size of the mortar
                             } // end of pigment
                   normal {wrinkles 0.75 scale 0.01}
                   finish {ambient 0.15 diffuse 0.95 phong 0.2}
                   scale 3
                   rotate<0,0,0>  translate<0.01, 0.04,-0.10>

}
