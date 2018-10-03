CFLAGS = `pkg-config --cflags opencv` `pkg-config --cflags aruco`
LIBS = `pkg-config --libs opencv` `pkg-config --libs aruco` -lGL -lGLU -lglut
ALLO = O/main.o O/fenetreprincipal.o O/camera.o O/constructeurpiece.o O/constructeurpiecei.o O/constructeurpiecej.o O/constructeurpiecel.o O/constructeurpieceo.o O/constructeurpieces.o O/constructeurpiecet.o O/constructeurpiecez.o O/controleur.o O/couleur.o O/fabriquepiece.o O/gestionmarker.o O/objet.o O/piece.o O/scene.o O/sujet.o O/tetrisframe.o O/video.o

all : $(ALLO) 
	g++ -std=c++11 $(CFLAGS) $(LIBS) $(ALLO) -o Projet

O/main.o : Main.cpp
	g++ -std=c++11 -c Main.cpp -o O/main.o

O/fenetreprincipal.o : FenetrePrincipal.cpp
	g++ -std=c++11 -c FenetrePrincipal.cpp -o O/fenetreprincipal.o

O/camera.o : Camera.cpp
	g++ -std=c++11 -c Camera.cpp -o O/camera.o

O/constructeurpiece.o : ConstructeurPiece.cpp
	g++ -std=c++11 -c ConstructeurPiece.cpp -o O/constructeurpiece.o

O/constructeurpiecei.o : ConstructeurPieceI.cpp
	g++ -std=c++11 -c ConstructeurPieceI.cpp -o O/constructeurpiecei.o

O/constructeurpiecej.o : ConstructeurPieceJ.cpp
	g++ -std=c++11 -c ConstructeurPieceJ.cpp -o O/constructeurpiecej.o

O/constructeurpiecel.o : ConstructeurPieceL.cpp
	g++ -std=c++11 -c ConstructeurPieceL.cpp -o O/constructeurpiecel.o

O/constructeurpieceo.o : ConstructeurPieceO.cpp
	g++ -std=c++11 -c ConstructeurPieceO.cpp -o O/constructeurpieceo.o

O/constructeurpieces.o : ConstructeurPieceS.cpp
	g++ -std=c++11 -c ConstructeurPieceS.cpp -o O/constructeurpieces.o

O/constructeurpiecet.o : ConstructeurPieceT.cpp
	g++ -std=c++11 -c ConstructeurPieceT.cpp -o O/constructeurpiecet.o

O/constructeurpiecez.o : ConstructeurPieceZ.cpp
	g++ -std=c++11 -c ConstructeurPieceZ.cpp -o O/constructeurpiecez.o

O/controleur.o : Controleur.cpp
	g++ -std=c++11 -c Controleur.cpp -o O/controleur.o

O/couleur.o : Couleur.cpp
	g++ -std=c++11 -c Couleur.cpp -o O/couleur.o

O/fabriquepiece.o : FabriquePiece.cpp
	g++ -std=c++11 -c FabriquePiece.cpp -o O/fabriquepiece.o

O/gestionmarker.o : GestionMarker.cpp
	g++ -std=c++11 -c GestionMarker.cpp -o O/gestionmarker.o

O/objet.o : Objet.cpp
	g++ -std=c++11 -c Objet.cpp -o O/objet.o

O/piece.o : Piece.cpp
	g++ -std=c++11 -c Piece.cpp -o O/piece.o

O/scene.o : Scene.cpp
	g++ -std=c++11 -c Scene.cpp -o O/scene.o

O/sujet.o : Sujet.cpp
	g++ -std=c++11 -c Sujet.cpp -o O/sujet.o

O/tetrisframe.o : TetrisFrame.cpp
	g++ -std=c++11 -c TetrisFrame.cpp -o O/tetrisframe.o

O/video.o : Video.cpp
	g++ -std=c++11 -c Video.cpp -o O/video.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf Projet
