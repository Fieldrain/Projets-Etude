/*
 * Initialisation au chargement de la page
 */


//Initialisation de la gestion des événements onClick sur la page
function initialiser()
{
	//Création d'un tableau associant l'id d'un élément et la fonction à appeler en cas de clic sur cet élement
	window.evenementsClic = {
		btnCarre : carre,
		btnTriangle : triangle,
		btnPoly1 : poly1,								
		btnPoly2 : poly2,
		btnPoly3 : poly3,
		btnPoly4 : poly4,
		btnCercle : cercle,
		btnCube : cube,
		btnCubeTex : cubeTex,
		btnSphere : sphere,
		btnTorus : torus
	};

	//Ajout d'un écouteur d'événement onClick sur la page
	window.addEventListener('click', gererClic, true);
	document.getElementById('html5colorpicker').onchange = refresh;

	start();
}

//Gestion des événements onClick de la page
function gererClic(evenement)
{
	//Récupère l'id de l'élément sur lequel l'utilisateur a cliqué
	var targetID = evenement.target.id;
    
	//Exécute le gestionnaire d'événement onClick correspondant à l'élément cible
	if(window.evenementsClic[targetID])
	{
		window.evenementsClic[targetID](evenement);
	}
}

//Lie la fonction initialiser au gestionnaire d'événément onLoad de la page
window.onload = initialiser;