#define BOOST_TEST_DYN_LINK           // A ajouter dans le cas d'une liaison dynamique à Boost Test
#define BOOST_TEST_MODULE rayon_test      // Nom du module de test

#include <boost/test/unit_test.hpp>
#include "../src/Vecteur/Vecteur.cpp"
#include "../src/Rayon/Rayon.cpp"

BOOST_AUTO_TEST_CASE(construteur_test) {
    Rayon testRayon(Vect(0,0,0),Vect(1,1,1));
    //BOOST_CHECK_EQUAL(test_Scene.GetCouleurAmbiante(),Vect(0,0,0));
}