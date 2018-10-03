unit scenario;

interface

uses SysUtils, Windows, personnage, ennemi, GestionEcran, gameplay_metro,
  save_chargement, gestion_inventaire, montype;

var
  fermer, nouvelle_partie, continuer, chapitre_suivant: smallint;
  selection, selection_1: smallint;
  reponse: machaine;
  condition, condition_2: smallint;
  game_over: smallint;

procedure histoire; // permet de lancer le jeu

// chaque procedure si dessous correspond a un chapitre

procedure intro_chateau;

procedure intro_metro;

procedure trois_jour_plus_tard;

procedure En_route_pour_Riga;

procedure Riga;

procedure tunnel_maudit;

procedure campement_de_bandit;

procedure catacombes;

procedure marchés;

procedure bienvenue_chez_toi;

procedure la_ville_morte;

procedure retour_metro;

procedure khan;

procedure station_maudite;

procedure station_independante;

procedure communisme;

procedure aide;

procedure depot;

procedure station_de_la_breche;

procedure retour_a_la_surface;

procedure ligne_droite;

procedure polis;

implementation

procedure histoire;

begin
  fermer := 0;
  assign(save, 'sav.txt');
  while fermer = 0 do
  begin
    accueil;
    attendre(2000);
    menu;
    readln(selection);
    if selection = 1 then // nouvelle partie
    begin
      nouvelle_partie := 1;
      initialisation;
      rewrite(save);
      sauvegarde;
      game_over := 0;
      intro_chateau;
      intro_metro;
      trois_jour_plus_tard;
      En_route_pour_Riga;
      Riga;
      tunnel_maudit;
      campement_de_bandit;
      catacombes;
      marchés;
      bienvenue_chez_toi;
      la_ville_morte;
      retour_metro;
      khan;
      station_maudite;
      station_independante;
      communisme;
      aide;
      depot;
      station_de_la_breche;
      retour_a_la_surface;
      ligne_droite;
      polis;
    end
    Else if selection = 2 then // continuer partie
    begin
      nouvelle_partie := 0;
      continuer := 1;
      game_over := 0;
      if get_checkpoint = 1 then
      begin
        intro_chateau;
        intro_metro;
        trois_jour_plus_tard;
        En_route_pour_Riga;
        Riga;
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 2 then
      begin
        intro_metro;
        trois_jour_plus_tard;
        En_route_pour_Riga;
        Riga;
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 3 then
      begin
        trois_jour_plus_tard;
        En_route_pour_Riga;
        Riga;
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 4 then
      begin
        En_route_pour_Riga;
        Riga;
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 5 then
      begin
        Riga;
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 6 then
      begin
        tunnel_maudit;
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 7 then
      begin
        campement_de_bandit;
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 8 then
      begin
        catacombes;
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 9 then
      begin
        marchés;
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 10 then
      begin
        bienvenue_chez_toi;
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 11 then
      begin
        la_ville_morte;
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 12 then
      begin
        retour_metro;
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 13 then
      begin
        khan;
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 14 then
      begin
        station_maudite;
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 15 then
      begin
        station_independante;
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 16 then
      begin
        communisme;
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 17 then
      begin
        aide;
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 18 then
      begin
        depot;
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 19 then
      begin
        station_de_la_breche;
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 20 then
      begin
        retour_a_la_surface;
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 21 then
      begin
        ligne_droite;
        polis;
      end
      Else if get_checkpoint = 22 then
      begin
        polis;
      end;

    end
    Else if selection = 3 then
    begin
      bestiaire;
      readln; // afficher bestiaire
    end
    Else if selection = 4 then
    begin
      credit;
      readln; // credit
    end
    Else
      fermer := 1;
  end;
end;

procedure intro_chateau;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Château');
    modif_checkpoint(1);
    rewrite(save);
    sauvegarde;
    texte('Après avoir traversé une forêt étonnamment ',
      'paisible, vous arrivez au beau milieu d''un ',
      'village dans lequel un homme vous aborde.', '',
      '"Ho hé étranger, es-tu un de ces jeunes fou ',
      'prêt à mettre votre vie en jeu en espérant trouver',
      'le trésor de l''ancien château du duché de ', 'Lapalud ?".', '', '', '',
      '', '');
    texte_choix_2_histoire('1. Oui oui, je suis de ceux la !', '2. Non');
    readln(selection);
    if selection = 1 then
    begin
      texte('"Bon j''imagine que ce n’est pas la peine ',
        'de tenter de te dissuader...', '', 'Quel est ton nom ? ', '',
        'Non pas que ça m''intéresse vraiment mais ',
        'il faut bien graver un nom sur ta future ', 'tombe !"', '', '', '',
        '', '');
      texte_choix_2_histoire('Votre nom: ', '');
      readln(reponse);
      modif_nom_perso(reponse);
      texte_nom('"Très bien mon cher ', ', je vais ',
        't''accompagner au château, par contre ',
        'je te laisse à l''entrée, pas ',
        'particulièrement envie de mettre ma vie en ',
        'danger pour des prunes gamins !"', '',
        'En entrant dans le château vous vous ',
        'retrouvez dans un hall sombre éclairé par ',
        'd''étranges torches brûlant d''un feu violet, ',
        'il vous est impossible de voir plus loin que ',
        'le bout de vos pieds, cependant, vous avez ',
        'l''impression d''être observé pire, que ',
        'quelques chose se déplace dans l''ombre...', get_nom_perso);
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('N''écoutant que votre courage ',
        '(ou votre stupidité c''est au choix) vous',
        'vous mettez un pied devant l''autre et...', '', '', '', '', '', '', '', '',
        '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end
    Else if selection = 2 then
    begin
      texte('"Alors va-t''en tu gênes !"', '',
        'C''est sur cette merveilleuse phrase ',
        'que votre histoire se termine.', '', '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure intro_metro;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Metro');
    modif_checkpoint(2);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) and (continuer = 1)
      then
    begin
      texte_nom_nom('" ', '... ', '... "', '',
        'Il semble qu’on vous appelle, mais la voix ',
        'est étouffée, vous avez du mal à comprendre.', '',
        '"Mais réveille-toi bordel, ', ' !"', '',
        'La voix est bien plus compréhensible, le ton',
        'indique que la personne est de plus en plus ', 'en colère.', '', '',
        '', get_nom_perso);
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Cette voix, vous la reconnaissez... Mais oui',
        'c''est celle de votre père !!', '',
        'Vos yeux s''ouvrent d''un coup, par chance, il ',
        'fait suffisament sombre pour ne pas être ', 'ébloui.', '',
        'Votre regard se balade dans le vague, ',
        'vous distinguez vos effets personnels, ', 'est-ce votre chambre ?',
        '', '"Enfin... Prends ton temps hein, enfin bref, ',
        'je t''attends dans le couloir, dépêche-toi."');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous vous levez de votre lit.', '',
        'Bien que votre chambre soit faiblement ',
        'éclairée vous vous regardez dans le miroir', 'à coté de votre lit',
        '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      ajout_stat(24);
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) and (continuer = 1)
      then
    begin
      texte('', '', '', '', '', '', '', '', '', '', '', '', '');
      texte_choix_3_histoire('1. Allumer la lumière', '2. Observer la pièce',
        '3. Quitter la pièce');
      readln(selection);
      condition := 0;
      while (selection_1 <> 2) and (selection <> 3) do
      begin
        if selection = 1 then
        begin
          texte('La lumière est maintenant allumée', '', '', '', '', '', '',
            '', '', '', '', '', '');
          condition := 1;
          texte_choix_2_histoire('1. Observer la pièce', '2. Quitter la pièce');
          readln(selection_1);
        end;
        if (selection = 2) and (condition = 1) or (selection_1 = 1) and
          (condition = 1) then
        begin
          texte('La pièce est petite, plutôt en désordre avec ',
            'votre lit dans le fond, une toute petite ',
            'table sur laquelle la lampe de bureau que ',
            'vous venez d''allumer trône.', '',
            'Sur la table un briquet en forme de balle, ',
            'un plan usagé, quelques livres abîmés.', '',
            'Dans un coin est posé une vieille guitare ',
            'sèche griffée, sur les murs sont accrochés ',
            'des cartes postales et dans l''autre coin une',
            'vieille armoire récupérée on ne sait où, ',
            'rafistolée tant bien que mal.');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          selection_1 := 2;
        end
        else if (selection = 2) and (condition = 0) then
        begin
          texte('Il vous est impossible de distinguer quoi que',
            'ce soit, moins que dans le château de votre ', 'rêve.', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('1. Allumer la lumière', '');
          readln(selection);
        end;
      end;
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('En sortant de votre chambre, un groupe de ',
        'quatres hommes vous salue, votre père vous ',
        'attend un peu plus loin, sans un mot vous ',
        'vous mettez à le suivre', '',
        'En arpentant les couloirs, vous croisez un ',
        'homme tentant d''occuper sa fille en lui ',
        'demandant de dessiner la maison dans laquelle',
        'elle souhaiterait vivre avec ses parents, ',
        'et une femme visiblement mécontente de ', 'nettoyer le sol.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('En quittant le couloir vous tombez sur une ',
        'longue file d''attente devant la lourde porte',
        'de ce qui sert d''hôpital, probablement des',
        'parents venus demander des nouvelles de ',
        'leurs maris fils etc... Suite à la dernière', ' attaque des Sombres.',
        '', 'Quelques "soldats" mal équipés tentent de ',
        'les empêcher d''entrer.', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Votre père frappe trois sur la porte en fer ', 'rouillée.', '',
        'Une sorte de visière s''ouvre, derrière un ',
        'homme semble le reconnaître.', '',
        'Pendant ce temps une femme vous interpelle, ',
        'elle est visiblement affolée, vous demande ',
        'si vous avez des nouvelles du front, si son ',
        'mari se trouve derrière cette porte.',
        'Pas le temps de répondre, votre père vous ',
        'pose la main sur l''épaule vous indiquant de ', 'le suivre.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous entrez dans une sorte de bureau, la ',
        'pièce est un poil plus grande que votre ',
        'chambre, à votre gauche sont accrochées ',
        'plusieurs blouses jaunies par le temps et ', 'tachées de sang.', '',
        'Trois hommes sont également présents, ils ',
        'racontent que l''avant-poste a été attaqué ',
        'par les Sombres il y a quelques heures et ',
        'que plus aucun des gars stationnés n''est en ',
        'mesure de répondre de quoi que ce soit.', '',
        '"Enfin tu verras par toi-même Soukhoï..."');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('L''un d''eux ouvre une petite porte en bois ',
        'dans le fond de la pièce, immédiatement ',
        'l''odeur de la mort emplit vos narines, bien',
        'que n''ayant pas envie de voir ce qu''il y a ',
        'dans la pièce suivante, vous continuez de ', 'suivre votre père.', '',
        'L''odeur est de plus en plus forte, vous ',
        'entendez des plaintes venant de derrières ',
        'les draps blancs tachés servant à séparer ', 'les lits', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Certains sont arrachés, exposant quelques ',
        'hommes le regard dans le vague, des bandages',
        'un peu partout tandis que d''autres se mettent',
        'à hurler en vous voyant passer.', '',
        'D''autres encore ne bougent pas, il sont morts,', ' tout simplement.',
        '', 'Le médecin vous accompagne vers la pièce ',
        'suivant correpondant à l''entrée de votre ',
        'station tout en expliquant à votre père que ',
        'la station ne tiendrait pas longtemps si on ',
        'ne résoud pas le problème des Sombres.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('L''entrée de la station est gardée par deux ',
        'hommes armèes et visiblement tendues.', '',
        'Apres un court rapport à votre père, un bruit',
        'sourd fait sont apparition, quelqu''un semble ',
        'frapper à la lourde porte en acier de la ', 'station...', '',
        'Un des deux hommes arme son AK-47 le seconde ',
        'exprime sa crainte que ce ne soit des Nosalis ',
        'ou des Sombres mais Soukhoï les interromps ',
        'leur rappelant que les monstres ne frappent ',
        'pas aux portes avant d''entrer.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Il ordonne l''ouverture de la porte.', '',
        'Une fois la porte suffisamment ouverte, vous ',
        'reconnaissait Hunter, un Ranger de Polis que ',
        'vous connaissez depuis un longtemps.', '',
        'Ce dernier explique venir suite aux rumeurs ',
        'd''attaque de VDNKh par "des créatures ',
        'nommées Sombres" dont Polis a eu vent.', '',
        'Son rôle est de vérifier si les faits sont ', 'bien réels.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Les lumières s''éteignent, la lumière rouge ',
        'indiquant un danger s''allumer, le silence ', 's''installe...', '',
        'Votre père ouvre rapidement un casier et vous ',
        'tend un revolver usé et trois douzaines de ', 'balles.', '',
        'Des Nosalis sortent des conduits d''aerations', '...', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      modif_id_arme_principale(2);
      modif_quantite_arme_4_perso(1);
      modif_sous_checkpoint(4);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
    begin
      combat(3, 1);
    end;
    if (get_victoire = 1) then
    begin
      modif_sous_checkpoint(5);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
      begin
        texte('"Des Nosalis ?! Ici ?!"', '',
          '"Probablement attirés par l''odeur du sang de ', 'l''hôpital !"',
          '', '"Mais ils ne viennent jamais aussi proche de ',
          'la station..."', '', 'Un homme entre en courant dans la pièce en ',
          'hurlant.', '"Des Sombres, des Sombres ont attaqué ',
          'l''avant-poste !"', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Sans attendre, vous courez en direction de ', 'l''avant poste.',
          '', 'Celui-ci est criblé de balle, les soldats ',
          'sont à terre, certains morts, d''autres ',
          'totalement déconnectés par la peur.', '',
          'Hunter décide de partir par le tunnel par ',
          'lequel les Sombres sont arrivés, il vous fait ',
          'promettre que si dans deux jours in n''est pas ',
          'revenu, vous partirez pour Polis expliquer au ',
          'Conseil la menace que représente les Sombres.',
          'Il vous remet également sa plaque d''identification.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        rewrite(save);
        sauvegarde;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure trois_jour_plus_tard;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Trois jour plus tard');
    modif_checkpoint(3);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Hunter n''est évidemment pas revenu, vous ',
        'devez donc partir rejoindre Polis et les ', 'informer de la menace.',
        '', 'Vous partez pour Riga, une station voisine ',
        'avec laquelle VDNKh a passé un nouvel ',
        'accord commercial afin de relier les deux ',
        'station par un câble téléphonique.', '',
        'Ce n''est qu''une excuse pour partir sans ',
        'que votre père (qui n''est pas au courant ',
        'de votre promesse) ne vous retienne.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Mais avant tout le vous faut de ',
        'l''équipement au marché de VDNKh !', '', '', '', '', '', '', '', '',
        '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      while (selection <> 4) or (condition = 0) do
      begin
        texte('Mais avant tout le vous faut de ',
          'l''équipement au marché de VDNKh !', '', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_4_histoire('1. Parler à un Homme et son fils',
          '2. Regarder les étals', '3. Acheter de l''équipement',
          '4. Partir pour Riga');
        readln(selection);
        if (selection = 1) then
        begin
          texte('Celui-ci vous demande deux balles afin ',
            'd''acheter quelques médicaments', '', '', '', '', '', '', '', '',
            '', '', '');
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if (selection_1 = 1) then
          begin
            modif_argent_perso(get_argent_perso - 3);
            texte('Perte de trois balles car vous êtes ', 'généreux !', '',
              'Merci , merci infiniment !', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin
            texte('"Je comprendre... Désolé de t''avoir ', 'dérangé', '', '',
              '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if selection = 2 then
        begin
          texte('Il y a de tout, des champignons, du porc, ',
            'des herbes qui font rire mais tout est cher ',
            'et pas forcément utile pour votre voyage.', '', '', '', '', '',
            '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 3 then
        begin
          texte_nom('"Salut ', ' ! Tu vas bien ?', '',
            'Tu viens chercher un peu d''équipement pour ', 'ta mission ?"',
            '', '', '', '', '', '', '', '', '', get_nom_perso);
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if (selection_1 = 1) then
          begin
            texte('"Voilà, cinq médipacks et VSxxxxxxxxxxxx"', '', '',
              '"Et voila, tu es prêt."', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 5);
            readln;
            condition := 1;
          end
          Else if selection_1 = 2 then
          begin
            texte('"D''accord, passe le bonjour de ma part à ',
              'ton père alors !"', '', '', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            texte('Vous prenez la direction des quais.', '', '', '', '', '',
              '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            texte('Un soldat vous empêche de passer sous ',
              'prétexte que vous n''êtes pas équipé.', '', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if selection = 4 then
        begin
        end;
      end;
      texte('Une fois équipé vous prenez la direction des ', 'quais.', '', '',
        '', '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('"Ah bah enfin, je vois que tu prends ton ', 'temps mon gars !',
        '', 'Allez, magne toi de monter dans la draisine ',
        'qu''on partent !"', '', '',
        'Vous montez dans la draisine et celle-ci ', 'démarre.', '', '', '',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure En_route_pour_Riga;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('En route pour Riga');
    modif_checkpoint(4);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Les passages de la draisine discutent, vous, ',
        'vous ne faites qu''écouter.', '',
        'Quelques minutes après avoir franchi le ',
        'dernier point de contrôle de VDNKh, un ',
        'sentiment étrange s''empare de vous, le temps ',
        'semble ralentit, vos compagnons commencent à ',
        'tomber dans les bras de Morphée, puis vint ', 'votre tour.', '', '',
        '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Combien de temps s''est passé, vous n''en ',
        'n''avez aucune idée, seulement, les plaintes ',
        'des Nosalis vous ont réveillé, ni une ni deux ',
        'vous commencez à réveiller le reste du groupe, ',
        'les Nosalis arrivent à grands pas.', '',
        'La draisine repart mais c''est trop tard, les ',
        'Nosalis vous attaquent !', '',
        'Un de vos compagnons vous donne son fusil ',
        'à pompe en vous suppliant de vous en servir',
        'correctement pendant que lui et un autre ',
        'actionne le levier pour accélérer');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      modif_quantite_arme_3_perso(get_quantite_arme_3_perso + 1);
      modif_id_arme_principale(1);
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      combat(3, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte('Vous tombez de la draisine, voyant d''autres ',
          'Nosalis arriver, vous vous cachez dans un ',
          'coin sombre à l''abri de leur vue.', '',
          'Une fois la meute passée, vous courrez dans ',
          'la direction de la draisine, celle-ci est ',
          'arivée à l''avant-poste de Riga et une odeur ',
          'de chaire brûlée emplit vos narines.', '',
          'Un lance flamme est installé et à ses pieds ',
          'plusieurs dizaines de cadavres de Nosalis ', 'calcinés', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Vous êtes enfin arrivés à la station et pour ',
          'fêter ça, vos compagagnons d''infortune et ',
          'vous allez boire un verre au bar de la ', 'station.', '', '', '',
          '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure Riga;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Riga');
    modif_checkpoint(5);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      modif_argent_perso(get_argent_perso + 10);
      texte('Autour d''une bonne Vodka, vos compagnons vous ',
        'donnent 10 Balles', '', 'Vous décidez de partir pendant qu''ils ',
        'continuent à boire, en arrivant près des quais, ',
        'vous constatez que ces derniers sont fermés et ',
        'surveillés, impossible de passer donc.', '',
        'Un enfant vous regarde et vous demande de le ',
        'suivre, d''après lui, un homme souhaite vous ', 'parler.',
        'Cependant il vous demande une balle pour ', 'vous y conduire.');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      while selection <> 3 do
      begin
        texte_choix_4_histoire('1. Aller voir le chef de la station',
          '2. Rentrer à VDNKh', '3. Suivre l''enfant', '4. Visiter la station');
        readln(selection);
        if selection = 1 then
        begin
          texte('En vous rendant vers le bureau du chef de ',
            'la station, un milicien vous dégage de devant la',
            'porte, en effet, le chef est " occupé " et',
            'vous devez lui " foutre la paix "', '', '', '', '', '', '', '',
            '', '');
          texte_choix_3_histoire('Insister', 'Provoquer', 'Laisser tomber');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('"T''es bouché ?', 'J''ai dit DEGAGE !"', '', '', '', '', '',
              '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin
            texte('Vous insultez copieusement les gardes !', '', '', '', '',
              '', '', '', '', '', '', '', '');
            combat(30, 1);
            if get_victoire = 1 then
            begin
              texte('Vous avez tricher c''est ça !!', '', '', '', '', '', '',
                '', '', '', '', '', '');
            end
            Else if (get_victoire = 0) then
            begin
              texte('Vous avez échoué... Vous êtes faible... ',
                'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '',
                '', '', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              game_over := 1;
            end;
          end
          Else if selection_1 = 3 then
          begin
          end;
        end
        Else if selection = 2 then
        begin
          texte('Vous voilà rentré à VDNKh après deux jours ',
            'de dur labeur, seulement la station est ', 'déserte...', '',
            'Enfin sauf si on compte les nombreux ',
            'corps figés d''horreur les yeux grands ',
            'ouverts et les mares de sang.', '',
            'Grâce à votre faible volonté vous avez ',
            'mené cette station à la ruine, d''ailleurs ',
            'à l''autre bout de la station, vous sentez ',
            'qu''on vous observe...', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end
        Else if selection = 3 then
        begin
          modif_argent_perso(get_argent_perso - 1);
          texte('Vous perdez une Balle.', '',
            'L''enfant vous demande de le suivre dans le ',
            '"quartier résidentiel" de la station.', '',
            'Une fois dans ce quartier, vous constatez la ',
            'pauvreté de la station.', '',
            'Un homme vous demande une balle pour manger', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;

        end
        Else if selection = 4 then
        begin
          texte('La station ressemble à VDNKh, à la différence ',
            'près qu''il y a des miliciens un peu partout ',
            'bloquant de nombreux accès', '',
            'Au loin une charmante demoiselle vous appelle, ',
            'elle semble légèrement vêtue sous son ',
            'imperméable beige abîmé.', '',
            'Ses intentions sembles claires, souhaitez-vous ',
            '"jouer" avec elle ?', '', '', '');
          texte_choix_2_histoire('1. Oh oui j''attendais que ça !',
            '2. Non merci... Vraiment...');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            modif_argent_perso(0);
            texte('Cette dernière vous emmène vers de nombreuses ',
              'tentes, vous ouvre l''une d''entres elles et au ',
              'moment où vous alliez entrer, un homme surgit ',
              'derrière vous et vous frappe avec une barre de ',
              'fer au niveau de la nuque.', '',
              'Quelques minutes après, vous vous réveillez en ',
              'ayant mal au crâne et la bourse totalement vide.', '', '', '',
              '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
          end
          Else if selection_1 = 2 then
          begin
          end;
        end;
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte_choix_2_histoire('1. Donner deux Balles',
          '2. Continuer de suivre l''enfant');
        readln(selection);
        if selection = 1 then
        begin
          modif_argent_perso(get_argent_perso - 2);
          texte('Vous donnez deux Balles à l''homme.', '',
            '"Merci monsieur merci !"', '', '', '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          texte('Vous ignorez ce pauvre homme.', '', '', '', '', '', '', '',
            '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end;
        texte('Vous arrivez devant ce qui semble être une ',
          'cuisine, l''enfant vous informe que l''homme qui ',
          'est sur la chaise à coté de la table est celui ',
          'qui vous cherche.',
          'L''enfant s''en va content d''avoir sa Balle.', '',
          'Cet homme s''appellent Bourbon, du moins, c''est ',
          'comme ça qu''il se fait appeler.', '',
          'C''est un trentenaire ayant sûrement vu(et bu au ',
          'vu de l''odeur qui l''entoure) beaucoup de choses, ',
          'il ne semble pas doué pour les relations humaines',
          'mais il semble avoir besoin d''aide.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Il souhaite rejoindre la station Aride pour ',
          '"affaires", il vous explique qu''il connaît un ',
          'moyen de passer outre les barrages en suivant ',
          'le "Tunnel Maudit".', '',
          'Cependant il a besoin de vous car il semble ',
          'que les phénomènes étranges des tunnels ne ', 'vous impacte pas.',
          '', 'En échange de ce service, il vous donnera son ', 'AK-47.', '',
          '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte_choix_2_histoire('1. Accepter', '2. Refuser');
        readln(selection);
        if selection = 1 then
        begin
          modif_argent_perso(get_argent_perso + 20);
          texte('Ravis de vous entendre accepter, ce dernier vous ',
            'donne 20 Balles, une avance comme il dit.', '',
            'Il vous indique où le retrouver et surtout quand, ',
            'voyant qu''il vous reste quelques heures avant le ',
            'départ, vous choisissez de:', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          texte_choix_2_histoire('1. D''aller vous reposer',
            '2. D''aller vous saouler avant le grand départ');
          readln(selection_1);
          if (selection_1 = 1) then
          begin
            modif_PV_perso(get_max_pv, 0);
          end
          Else if selection = 2 then
          begin
          end;
        end
        Else if (selection = 2) then
        begin
          texte('En refusant d''aider Bourbon, vous décidez de ',
            'mener à bien votre mission consistant à relier ',
            'VDNKh et Riga.', '',
            'Après deux jours de dur labeur vous rentrez chez ',
            'vous, seulement la station est déserte... Enfin ',
            'sauf si on compte les nombreux corps figés ',
            'd''horreur les yeux grands ouverts et les mares de ', 'sang.', '',
            '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure tunnel_maudit;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Tunnel Maudit');
    modif_checkpoint(6);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous voici dans le fameux "Tunnel Maudit", ',
        'celui-ci ressemble à tous les autres à ',
        'l''exception de champignons fluorescents.', '',
        'En avançant, vous tombez sur un cadavre en ',
        'décomposition avancée.', '', '', '', '', '', '', '');
      texte_choix_2_histoire('1. Le fouiller', '2. Continuer');
      readln(selection);
      if selection = 1 then
      begin
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
        texte('Vous trouvez 2 médipack', '', '', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
      end;
      texte('Bourbon vous raconte une légende à propose de ce ',
        'tunnel selon laquelle en collant une oreille sur ',
        'les tuyaux, il est possible d''entendre la voix des', 'morts.', '',
        '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('1. Ecouter', '2. Continuer');
      readln(selection);
      if selection = 1 then
      begin
        texte('Vous entendez un rire d''enfant.', '', '', '', '', '', '', '',
          '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
      end;
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Vous croisez un Rôdeur, ce dernier fuit en vous ', 'voyant.', '',
        '"Y''a rien à craindre, seul comme ça il nous ',
        'attaquera pas, mais fais gaffe si tu te balade ', 'seul"', '',
        'Quelques mètres plus loin une seconde voie ',
        's''offre à vous, Bourbon semble occupé.', '',
        'Suivre la seconde voie ?', '', '');
      texte_choix_2_histoire('1. Oui', '2. Attendre Bourbon');
      readln(selection);
      if selection = 1 then
      begin
        texte('Cette voie est pleine de trous, au sol et au ', 'plafond. ', '',
          'Une sorte de lumière fluorescente l''illumine,  ',
          'probablement à cause des champignons.', '',
          'Peu rassurée, vous avancez prudemment, vous ',
          'voyer un peu plus loin deux cadavres dont un ',
          'derrière une grande grille.', '', '', '', '');
        texte_choix_2_histoire('1. Fouiller les cadavres',
          '2. Rebrousser chemin et retourner vers Bourbon');
        readln(selection_1);
        if selection_1 = 1 then
        begin
          combat(3, 1);
          rewrite(save);
          sauvegarde;
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
          if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
          begin

          end;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if selection = 2 then
      begin
      end;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure campement_de_bandit;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Campement de bandit');
    modif_checkpoint(7);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('En continuant de suivre le tunnel, vous tombez ',
        'sur un campement de bandits, Bourbon n''ayant ',
        'visiblement pas envie de se battre vous envoie ', 'au charbon', '',
        '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      combat(5, 1);
      rewrite(save);
      sauvegarde;
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte('Profitant d''un moment de "calme", vous vous ',
          'engouffrez dans un tunnel annexe dont l''entrée ',
          'ce trouve derrière le campement.', '', '', '', '', '', '', '', '',
          '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure catacombes;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Catacombes');
    modif_checkpoint(8);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Le tunnels est long, très long, apparement ',
        'personne ne semble y être passé depuis un bon ', 'moment.', '',
        'Plus vous avancez, plus une odeur nauséabonde ',
        's''installe autour de vous.', '',
        'La traversée s''effectue dans un silence total, ',
        'Bourbon ne semble pas être du genre à tenir de ',
        'longue discussion, ce qui vous arrange, après tout',
        'vous ne le connaissez que depuis quelques heures.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Le temps semble de nouveau ralentir, Bourbon ',
        'semble chantonner, votre vision se trouble.', '',
        'Un hurlement ce fait entendre dans le tunnel... ', 'Des Nosalis !',
        '', 'Bourbon a arrêté de chantonner.', '',
        '"Faut qu''on se barre rapidement, ',
        'mais fais gaffe, y''a sûrement ',
        'des pièges, saloperie de bandits."'
          , '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Le temps semble de nouveau ralentir, Bourbon ',
        'semble chantonner, votre vision se trouble.', '',
        'Un hurlement ce fait entendre dans le tunnel... ', 'Des Nosalis !',
        '', 'Bourbon a arrêté de chantonner.', '',
        '"Faut qu''on se barre rapidement, ',
        'mais fais gaffe, y''a sûrement ',
        'des pièges, saloperie de bandits."'
          , '', '');
      texte_choix_2_histoire('1. Écouter Bourbon et courir comme jamais',
        '2. Écouter Bourbon mais faire attention');
      readln(selection);
      if selection = 1 then
      begin
        texte('En ayant foncé comme un bourrin dans le tunnel, ',
          'vous avez déclenché des pièges qui vous ont retiré',
          'des points de santé.', '', '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_PV_perso(get_pv_perso - 35, 0);
        combat(1, 0);
        rewrite(save);
        sauvegarde;
      end
      Else if selection = 2 then
      begin
        texte('En ayant fait attention, sous avez évité tous ',
          'les pièges, bien visibles, du tunnel.', '', '', '', '', '', '', '',
          '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(1, 0);
        rewrite(save);
        sauvegarde;
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Le sol craque sous vos pieds, vous tombez ',
        'dans une pièce remplie de gaz, de ', 'champignons et de cadavres.',
        '', 'Bourbon va directement dans le fond de la ',
        'pièce où il essaie d''ouvrir une grille ',
        'en tournant une manivelle.', '', '', '',
        '', '', '');
      texte_choix_2_histoire('1. Fouiller les cadavres', '2. Aider Bourbon');
      readln(selection);
      if selection = 1 then
      begin
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 1);
        texte('Vous trouvez 1 médipack encore en bon état', '', '', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
        texte_nom_nom_2('Vous vous sentez mal, Bourbon semble avoir du ',
          'mal à ouvrir la grille.', 'Une voix vous appel au loin.', '',
          '... ', ' ...', '', 'Vous reprenez vos esprits, Bourbon semble ',
          'aller mal, il essaie de séduire la grille,',
          'malgré votre état, vous sentez une présence ',
          'sombre, inquiétante, peut être hostile, en ',
          'rassemblant vos dernières forces, vous écartez un ',
          'Bourbon totalement à l''ouest de sa grille bien ',
          'aimée et parvenez à l''ouvrir.', get_nom_perso);
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Vous vous engouffrez dans le passage en le ',
          'traînant avant que celle-ci ne se referme.', '',
          'Bourbon reprend ses esprits, quant à vous, ', '',
          'vous retrouvez toutes vos forces, Bourbon vous ',
          'remercie à sa manière.', '',
          'Par miracle, vous êtes proche d’une station ',
          'que Bourbon connaît bien, seulement en approchant ',
          'l''alarme retentit...', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(5, 1);
        rewrite(save);
        sauvegarde;
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
        begin
          combat(1, 1);
          rewrite(save);
          sauvegarde;
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(5);
          rewrite(save);
          sauvegarde;
          if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
          begin
            texte('Voyant que la voie est libre, les gardes ',
              'ouvrent la porte.', '', '', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure marchés;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Marchés');
    modif_checkpoint(9);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous êtes accueilli par le garde en chef à qui',
        'Bourbon semble devoir de l''argent, celui-ci ',
        'vous laisse avec les gardes pendant qu''il ',
        'marchande un droit de passage dans la station.', '',
        'Au bout de quelques (longues) minutes, Bourbon',
        'revient vous chercher et vous fait entrer dans le ', 'marché.', '',
        'Ayant une autre affaire à régler, Bourbon vous ',
        'laisse quartier libre pour visiter la station.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Celle-ci est très différente de la vôtre, bien',
        'plus animée mais également très sale, les murs',
        'sont couverts de suie, le sol est répugnant... ', '',
        'Mais cela ne vous empêche pasde partir en ', 'exploration !', '', '',
        '', '', '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      while (selection <> 3) or (selection_1 <> 1) do
      begin
        texte('Celle-ci est très différente de la vôtre, bien',
          'plus animée mais également très sale, les murs',
          'sont couverts de suie, le sol est répugnant... ', '',
          'Mais cela ne vous empêche pasde partir en ', 'exploration !', '',
          '', '', '', '', '', '');
        texte_choix_3_histoire('1. Regarder les étals', '2. Aller au bar',
          '3. Rejoindre Bourbon');
        readln(selection);
        if selection = 1 then
        begin
          texte('Le marché regorge de choses à acheter, cela va de ',
            'la nourriture aux pièces détachées de rame de ',
            'métro sans oublier les vêtements, les armes et ',
            'différentes substances aux effets étranges.', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('1. Aller voir les marchands', '');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('"Salut mon gars, tu veux changer de matos ?',
              'J''ai tout ce qu''y te faut pour, crois-moi !"', '', '', '', '',
              '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            modif_quantite_objet_1_v(5);
            modif_quantite_objet_2_v(2);
            modif_quantite_objet_3_v(3);
            modif_quantite_arme_1_v(1);
            modif_quantite_arme_2_v(1);
            modif_quantite_arme_3_v(1);
            modif_quantite_arme_4_v(1);
            modif_quantite_arme_5_v(1);
            vendeur;
            rewrite(save);
            sauvegarde;
          end
          Else if selection_1 = 2 then
          begin

          end
        end
        Else if selection = 2 then
        begin
          texte('"Je vous sers quelques chose à boire ?"', '', '', '', '', '',
            '', '', '', '', '', '', '');
          texte_choix_2_histoire('1. Prendre une bière', '');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('Vous décidez de prendre une bière', '', '', '', '', '', '',
              '', '', '', '', '', '');
            modif_argent_perso(get_argent_perso - 3);
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin

          end;
        end
        Else if selection = 3 then
        begin
          texte('Vous retrouvez Bourbon avec plusieurs gardes ',
            'devant l''imposante porte ouvrant sur l''extérieur ',
            'de la station.', '',
            'Alors qu''un des gars ouvre la porte, un second ',
            'demande de l''argent à Bourbon, celui-ci refuse ',
            'en expliquant avoir payé le chef.', '',
            'Enfin bref, la porte est ouverte, Bourbon ',
            'se tourne vers vous et', '', 'Es-tu prêt ?', '');
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('La porte est maintenant ouverte, pour la ',
              'première fois depuis longtemps, vous allez voir ',
              'la surface !', '', '', '', '', '', '', '', '', '',
              '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin
            texte('Vous repartez vers le marché.', '', '', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end;
      end;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure bienvenue_chez_toi;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Bienvenue chez toi');
    modif_checkpoint(10);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('L''entrée de la station est immense, le bâtiment ',
        'est dans un état pitoyable mais vous n’avez aucun ',
        'mal à imaginer sa grandeur d’antan.', '',
        '" Bienvenue chez toi mon gars "', '',
        'Bourbon vous explique que des personnes font des ',
        'excursions à la surface et parfois y restent, mais',
        'souvent elles finissent "dégommées" par les ',
        '"bestioles" qui nous remplacent à la surface. ', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Il en profite pour vous rappeler de n''enlever',
        'votre masque à gaz sous aucun prétexte, l''air ',
        'étant pollué, vous ne tiendriez pas longtemps ', 'sans.', '',
        'En avançant vous voyez deux corps vers ',
        'les grandes portes en bois de la station.', '', 'Les fouiller ?', '',
        '', '', '');

      texte_choix_2_histoire('1. Oui', '2. Non');
      readln(selection);
      if selection = 1 then
      begin
        modif_argent_perso(get_argent_perso + 50);
        texte('Vous trouvez 50 balles en les fouillants', '', '', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
      end
      Else if selection = 2 then
      begin
        texte('"Tant pis pour toi, je prends ce qu''ils ont !"',
          'Bourbon reçoit 50 Balles.', '', '', '', '', '', '', '', '', '', '',
          '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Après avoir fouillé le bâtiment et évité quelques ',
        'pièges vous sortez de la station.', '',
        'Moscou, enfin ce qu''il en reste, s’offre ',
        'maintenant à vous, le ciel est gris, les ',
        'bâtiments noircis, il fait froid, la neige est ',
        'même la, hormis le fait qu''elle est vide et en',
        'piteuse état, la description des livres de ',
        'géographie est bien d’actualité !', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('En faisant quelques pas, vous entendez un cri, ',
        'Bourbon vous traine derrière une colonne devant',
        'l''entrée de la station et vous demande "de la fermer".', '',
        'Une créature volante immense passe près des colonnes', '',
        'Bourbon vous explique que ces créatures sont appelées ',
        '"Démons" mais que lui les appelle "Saloperie".', '',
        'Une fois la "Saloperie" passée, vous vous dirigez ',
        'vers la gauche, et essayez de sauter d''une voiture ',
        'dans la crevasse, vous remontez avec du mal mais ',
        'maintenant plus moyens de le rejoindre par ce côté.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Celui-ci vous indique un autre chemin, seulement, ',
        'il faudra faire attention, il y aura surement ', 'des "bestioles"',
        '', '', '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure la_ville_morte;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('La ville morte');
    modif_checkpoint(11);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous voici maintenant seul dans cette grande ville, ',
        'bon pas le moment de faire du tourisme, ',
        ', vous commencez directement à suivre l''itinéraire ', '',
        'décrite par Bourbon.Vous devez passer par un grand bâtiment,', '',
        'Vous devez passer par un grand bâtiment',
        'dans l''entrée, un corps git entouré de ', 'traces de sang.', '', '',
        '', '');
      texte_choix_2_histoire('1. Le fouiller', '2. Continuer');
      readln(selection);
      if selection = 1 then
      begin
        modif_argent_perso(get_argent_perso + 30);
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
        texte('Vous fouillez le corps sans regret, ', 'espèce de monstre !',
          '', 'Non je plaisante j''aurais fait pareil.', '',
          'Du coup vous trouvez 2 médipack et 30 balles', '', '', '', '', '',
          '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin

      end;
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Vous devez passer par l''étage pour en sortir.', '',
        'En avançant vers la cage d''escalier vous tombez sur ',
        'une de ces "bestioles" dont Bourbon vous a parlé.', '', '', '', '',
        '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(1, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte('Une fois la créature morte, vous sortez du bâtiment, ',
          'vous êtes entouré d''immeubles, pas très grands ',
          'mais suffisamment pour vous sentir un peu mal à l''aise.', '',
          'En avançant vous arrivez près d''un jardin d''enfants,',
          'celui-ci est étrangement préservé bien qu''un peu sale,',
          'en marchant dans ce qui devait être de l''herbe, vous ',
          'entendez des rires d’enfants.', '',
          'Sur le qui-vive, vous tournez la tête dans toutes les ',
          'directions, ne voyant aucun enfant vous vous dites ',
          'que vous avez dû les imaginer.', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Enfin bref, il faut se dépêcher !', '',
          'Un démon vous bloque le chemin,',
          'celui-ci est en train de manger un Nosalis.', '', '', '', '', '',
          '', '', '', '');
        texte_choix_2_histoire('1. Essayer de le tuer', '2. Attendre');
        readln(selection);
        if selection = 1 then
        begin
          combat(1, 1);
        end
        Else if selection = 2 then
        begin
          texte('En choisissant de ne pas combattre, ',
            'vous avez peut-être raté une bonne occasion ',
            'de tuer un Démon mais au moins vous êtes en vie.', '', '', '', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          modif_sous_checkpoint(4);
          rewrite(save);
          sauvegarde;
        end;
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Vous passez par-dessus une grande grille, Bourbon',
          'est un peu plus loin, occupé à fouiller un cadavre.', '',
          '"Ah enfin, t''as pris ton temps, enfin peu importe,',
          'on peut y aller."', '',
          'Vous suivez Bourbon en silence, les lieux ne',
          'sont pas sécurisés et il semble qu''on vous épie…', '',
          'Vous tombez dans un guet-apens !', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(3, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(5);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
        begin
          texte('Les Nosalis sont de plus en plus nombreux,',
            'ayant compris vous n''arriverez jamais à rester en vie ',
            'à ce rythme, Bourbon cours vers une bouche ',
            'd’aération du métro.', '',
            'Il vous demande de l''aide, il veut que vous lui ',
            'fassiez la courte échelle pendant que les Nosalis ',
            'sont occupés par un nouveau venu, un démon.', '', '', '', '', '');
          texte_choix_2_histoire('1. Aider Bourbon', '2. Ne pas aider Bourbon');
          readln(selection);
          if selection = 1 then
          begin
            texte('Vous voici en sécurité, du moins pour le moment.', '', '',
              '', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection = 2 then
          begin
            texte('Au moment de faire la courte échelle à Bourbon, vous ',
              'décidez qu''il n''est pas digne de confiance, ',
              'qu''il ne vous aidera pas à monter à votre tour.', '',
              'Cette erreur de jugement vous conduit à votre perte, ',
              'vous et Bourbon finissez dans l''estomac de gentils bébés Démons.'
                , '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure retour_metro;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Retour dans le metro');
    modif_checkpoint(12);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous rampez dans les conduits, vous semblez ',
        'au-dessus d''une station que Bourbon connait.', '',
        'Il décide de sortir du conduit mais vous demande ',
        'de rester au cas où.', '',
        'Il reviendra vous chercher si tout est bon.',
        'Il vous confie son sac en gage de confiance.', '',
        'En sortant il se fait intercepter par des gardes, ',
        'ces derniers surpris lui expliquent que la ',
        'station a changé de chef et lui rappels qu''il a ',
        'quelques comptes à régler avec le nouveau patron.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Comprenant que rien ne se passe comme prévu, ',
        'vous laissez les gardes emmener Bourbon et vous ',
        'éloignez de la sortie du conduit.', '', '', '', '', '', '', '', '',
        '', '');
      while selection <> 1 do
      begin
        texte_choix_3_histoire('1. Sortir du conduit',
          '2.Fouiller le sac de Bourbon', 'Attendre');
        readln(selection);
        if selection = 1 then
        begin
          texte('Vous semblez n''avoir éveillé aucun soupçon ',
            'pour le moment, vous avancez discrètement ',
            'vers les lieux de détention de Bourbon', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          if condition = 0 then
          begin
            modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 5);
            modif_quantite_objet_3_perso(get_quantite_objet_3_perso + 1);
            texte('Vous décidez de prendre du matériel dans ',
              'le sac de Bourbon, il ne vous en voudra ',
              'surement pas si vous parvenez à le libérer.', '',
              'Vous trouvez 5 médipack et du thé', '', '', '', '', '', '', '',
              '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            condition := 1;
          end
          Else
          begin
            texte('Vous avez déjà fouillé le sac', '', '', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if selection = 3 then
        begin
        end;
      end;

      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Un garde sonne l''alerte, malgré toutes ',
        'les précautions prises il vous a vu, ',
        'vous le tuez d''une balle dans la tête',
        '(coup de chance ?) mais d''autres arrivent.', '', '', '', '', '', '',
        '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(3, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        texte('Vous parvenez à attirer l’attention des autres ',
          'gardes dans la mauvaise direction en tirant sur une ',
          'lanterne ce qui vous permet de vous faufiler ',
          'jusqu''au lieu de captivité de Bourbon.', '',
          'En entrant dans la pièce, vous surprenez le chef ',
          'de la station, arme braquée sur Bourbon ce qui ',
          'lui laisse le temps de saisir une arme.', '',
          'En plein élan Bourbon tire sur le chef qui lui tire également dessus.'
            , '', 'Les deux sont morts.',
          'Les gardes sont à la porte, prêt à la défoncer et vous tuer.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('C''est à ce moment que la porte au fond de la pièce s''ouvre, ',
          'un homme plus âgé, peut-être la cinquantaine, ',
          'se tient à la place de la porte.', '',
          'Cette homme vous propose de le suivre rapidement ',
          'ou de laisser entrer les gardes.', '', '', '', '', '', '', '');
        texte_choix_2_histoire('1. Le suivre', '2. Ouvrir aux gardes');
        readln(selection);
        if selection = 1 then
        begin
          texte('Vous choisissez de suivre l''homme qui vient ',
            'pour le coup de vous sauver la vie.', '', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          texte('Sois vous êtes idiot, sois suicidaire...', 'Ou les deux...',
            '', 'En tout cas vous voilà pendu les tripes à l’air.', '',
            'Bravo !', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure khan;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Khan');
    modif_checkpoint(13);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous suivez cet homme dans un couloir plongé dans ',
        'le noir, uniquement éclairé par sa lampe.', '',
        'Il se présente, son nom est Khan, il vous explique ',
        'être en chemin pour la "Station Maudite" qui subit ',
        'depuis quelques temps des attaques répétés de Nosalis ',
        'et de Rôdeurs.', '',
        'Il vous promet qu''en partant de cette station, vous pourriez ',
        'suivre un itinéraire vers Polis, votre destination finale.', '', '',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Le couloir se termine sur un nouveau tunnel, ',
        'ce dernier semble totalement vide et en très mauvais ',
        'état, surement non parcouru depuis un long moment.', '',
        'En avançant, vous voyez des ombres, des ombres sans que qui ',
        'que ce soit ne soit présent.', '',
        'Khan vous explique d''un air triste que ce sont sont les ',
        'ombres des morts revivant sans cesse leurs derniers instants.', '',
        '', '', '');
      texte_choix_2_histoire('1. Les laisser tranquilles', '2. En toucher une');
      readln(selection);
      if selection = 1 then
      begin
        texte('Khan vous explique qu''il ne faut sous aucun prétexte ',
          'en toucher une, elles auraient un effet ', 'létal sur les vivants.',
          '', '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_sous_checkpoint(2);
        rewrite(save);
        sauvegarde;
      end
      Else if selection = 2 then
      begin
        texte('En posant votre doigt sur l''une d''elles, vous ',
          'ressentez un froid intense et...', '', 'Plus rien.', '',
          'Vous voilà mort vous aussi.', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('En continuant votre traversée du tunnel, un ',
        'grand bruit retentit, comme une rame qui ',
        'serait en marche, Khan vous regarde et vous colle ',
        'contre une paroi du tunnel.', '',
        'A peine avait-il fait ça qu''une ombre immense ',
        'représentant une rame passe à toute vitesse ',
        'près de vous, les passagers crient, pleurent, ',
        'un enfant semble chercher sa mère...', '',
        'Sans Khan vous seriez mort, vous le remercier ',
        'et voulez lui donner quelques balles mais ', 'ce dernier refuse.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Continuant, vous vous retrouvez entourés d''ombres ',
        'bloquant le passage, Khan, le regard plein de ',
        'compassion, vous explique que ce sont les ombres ',
        'ombres d''anciens soldats ayant donné leurs vies ',
        'pour protéger la station.', '',
        'Murmurant quelque chose d''incompréhensible, ',
        'il parvint à dégager le passage, les ombres ',
        'se retournent et disparaissent.', '',
        'Quelques mètres plus loin, Khan vous fait passez ',
        'par une porte donnant sur un couloir, dans ce dernier vous',
        'trouvez plusieurs cadavres.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Khan se met à accélérer et vous le suivez ', 'tant bien que mal.',
        '', 'Vous sortez de l''ensemble de couloir ressemblant',
        'au final à un petit labyrinthe et ', 'arrivez dans un nouveau tunnel',
        '', 'En suivant les rails, vous constatez ',
        'que de l''électricité statique les parcourts.', '',
        'Khan s''en éloigne le plus possible;', '', '');
      texte_choix_2_histoire('1. Rester en plein milieu',
        '2. S''éloigner aussi');
      readln(selection);
      if selection = 1 then
      begin
        texte('Une énorme boule apparemment faite d''électricité apparait,',
          'elle s''avance vers vous.', '', '', '', '', '', '', '', '', '', '',
          '');
        texte_choix_2_histoire('1. Tirer sur cette chose',
          '2. S''éloigner des rails');
        readln(selection_1);
        if selection_1 = 1 then
        begin
          texte('Vous êtes mort électrocuté.', '', '', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end
        Else if selection_1 = 2 then
        begin
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
        end;
      end
      Else if selection = 2 then
      begin
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Khan vous demande de rester immobile lors de son passage.', '',
        'Une fois cette chose partie, il vous explique que cette ',
        'étrangeté est nommée "Anomalie" et qu''on ne peut pas ',
        'gagner contre elle.', '',
        'Plus loin le tunnel est bouché, vous changez de tunnel ',
        'à une bifurcation, cependant, des Nosalis arrivent .', '', '', '', '',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(3, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(4);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Khan se lance dans l''autre tunnel repoussant ',
          'les Nosalis, il vous dit vouloir profiter de ',
          'l''approche d''une nouvelle anomalie', 'pour s''en débarrasser.',
          '', 'En effet, vous entendez au loin des Nosalis ',
          'hurler, peu de temps après, une nouvelle anomalie ',
          'apparait, vous la laissez passer ',
          'tranquillement et reprenez votre chemin.', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure station_maudite;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Station maudite');
    modif_checkpoint(14);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('La station est totalement ravagée, partout des cadavres ',
        'd''humains et de Nosalis, vous suivez Khan vers un groupe ',
        'lourdement armés.', '',
        'Ces derniers semblent soulagés de voir Khan arriver, ',
        'ce dernier leur demande l''état de la situation.', '',
        'Sans grande surprise, ils sont à bout et ',
        'n''ont presque plus de munitions.', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Ils expliquent à Khan avoir envoyé deux artificiers ',
        'pour faire sauter les passages utilisés par les Nosalis ',
        'et des Rôdeurs afin de les empêcher d''entrer de nouveau ',
        'dans la station mais qu''ils sont surement morts ',
        'avant d''avoir réussi.', '',
        'Khan se tourne vers vous et vous demande de finir ',
        'le travail, lui doit rester avec les gardes pour protéger ',
        'la population derrière le barrage.', '', '', '', '');
      while selection <> 1 do
      begin
        texte_choix_2_histoire('1. Oui', '2. Non');
        readln(selection);
        if selection = 1 then
        begin
          texte('Les gardes vous remercient.', '', '', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          texte('Les gardes vous expliquent qu''il ',
            'est impossible de passer car des ombres bloquent ',
            'le passage et que sans vous la station ',
            'est perdue, sans parler des centaines de morts',
            'qu''il y aurait.', '', '', '', '', '', '', '',
            '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end;
      end;
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Ils vous expliquent qu''ils y a deux passages, ',
        'un vers l''hôpital et l''autre en suivant les rails.', '',
        'Ils vous remettent trois bombes artisanales et ',
        'vous souhaitent bonne chance.', '', '', '', '', '', '', '', '');
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      while (condition = 0) or (condition_2 = 0) do
      begin
        texte_choix_2_histoire('1. Aller à l''hôpital', '2. Suivre les rails');
        readln(selection);
        if selection = 1 then
        begin
          modif_sous_checkpoint(4);
          rewrite(save);
          sauvegarde;
          if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
          begin
            texte('Vous vous dirigez vers l''hôpital, sur le chemin vous ',
              'croisez des morts, du sang, des bestioles mortes le tout ',
              'dans un environnement totalement saccagé.', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            combat(2, 1);
            if get_victoire = 1 then
            begin
              modif_sous_checkpoint(5);
              rewrite(save);
              sauvegarde;
              if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) and
                (continuer = 1) then
              begin
                texte('En arrivant au passage vous tombez sur ',
                  'd''autres bestioles.', '', '', '', '', '', '', '', '', '',
                  '', '');
                texte_choix_2_histoire('Appuyer sur entrer', '');
                readln;
                combat(2, 1);
              end;
              if get_victoire = 1 then
              begin
                modif_sous_checkpoint(6);
                rewrite(save);
                sauvegarde;
                if (nouvelle_partie = 1) or (get_sous_checkpoint = 6) and
                  (continuer = 1) then
                begin
                  texte('Vous vous rendez compte une fois l''endroit nettoyé ',
                    'que le seul moyen pour bloquer le passage et de faire ',
                    'sauter les colonnes.', '',
                    'Vous y placez donc les charges et courrez-vous',
                    'mettre à l''abri', '',
                    'Vous entendez une forte détonation preuve que vos ',
                    'explosifs ont bien fonctionné.', '', '', '', '');
                  texte_choix_2_histoire('Appuyer sur entrer', '');
                  readln;
                  condition := 1;
                end;
              end
              Else if (get_victoire = 0) then
              begin
                texte('Vous avez échoué... Vous êtes faible... ',
                  'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '',
                  '', '', '', '', '', '', '', '', '');
                texte_choix_2_histoire('Appuyer sur entrer', '');
                readln;
                game_over := 1;
              end;
            end
            Else if (get_victoire = 0) then
            begin
              texte('Vous avez échoué... Vous êtes faible... ',
                'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '',
                '', '', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              game_over := 1;
            end;
          end
          Else if selection = 2 then
          begin
            begin
              modif_sous_checkpoint(7);
              rewrite(save);
              sauvegarde;
              if (nouvelle_partie = 1) or (get_sous_checkpoint = 7) and
                (continuer = 1) then
              begin
                texte('Vous descendez au niveau des rails ',
                  'et vous mettez à les suivre.', '',
                  'Ils sont jonchés de douilles, de sang ',
                  'et les murs présentent des impacts', '', '', '', '', '', '',
                  '', '');
                texte_choix_2_histoire('Appuyer sur entrer', '');
                readln;
                combat(2, 1);
                if get_victoire = 1 then
                begin
                  modif_sous_checkpoint(8);
                  rewrite(save);
                  sauvegarde;
                  if (nouvelle_partie = 1) or (get_sous_checkpoint = 8) and
                    (continuer = 1) then
                  begin
                    texte('Il semble que les habitants ont essayé ',
                      'bloquer le passage en créant des barrières.', '',
                      'Ces dernières n''ont semble-t-il pas ',
                      'survécu au passage des Nosalis.', '',
                      'En arrivant au bout, vous placez ',
                      'les charges et partez-vous mettre à l''abri.', '',
                      'Vous entendez une forte détonation preuve ',
                      'que vos explosifs ont bien fonctionné.', '', '');
                    texte_choix_2_histoire('Appuyer sur entrer', '');
                    readln;
                    condition_2 := 1;
                  end;
                end
                Else if (get_victoire = 0) then
                begin
                  texte('Vous avez échoué... Vous êtes faible... ',
                    'Vous êtes nul... Mais je vous propose ', 'de rejouer !',
                    '', '', '', '', '', '', '', '', '', '');
                  texte_choix_2_histoire('Appuyer sur entrer', '');
                  readln;
                  game_over := 1;
                end;
              end;
            end;
          end;
        end;
      end;
      modif_sous_checkpoint(9);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 9) then
    begin
      modif_argent_perso(get_argent_perso + 20);
      modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 3);
      texte('Vous revenez vers le groupe, celui-ci vous remercie ',
        'et vous indique par ou passer pour continuer votre ',
        'chemin vers Polis', '',
        'Khan vous accompagne, en effet les ombres sont toujours  ',
        'présentes,ce dernier leur parle et elles partent lentement.', '',
        'Le passage est maintenant dégagé, Khan vous explique devoir ',
        'rester ici pour les aider mais vous conseille ',
        'de chercher un certain forgeron nommé Andreï',
        'à la prochaine station.', '',
        'Vous partez donc seul dans un nouveau tunnel.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure station_independante;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Station indépendante');
    modif_checkpoint(15);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous n''avez étrangement rencontré aucun ',
        'problème durant la traversé du tunnel',
        'Vous voici maintenant à l''entrée de la station Indépendante.',
        'la Station Indépendante.', '',
        'En entrant, un homme vous met en garde, cette station',
        'n''a d''indépendante que le nom, les Rouges, enfin les ',
        'communistes, ont la main mise sur cette station et ',
        'font souvent des contrôles d''identité, ceux n''étant ',
        'pas identifiés sont emmenés et ne réapparaissent jamais.', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Continuant votre progression dans la station, ',
        'vous tombez sur un homme se faisant contrôler, ce ',
        'dernier provoque l''homme le fouillant en faisant ',
        'allusion au fait que ce dernier aime tripoter les hommes.', '',
        'En vous voyant le Rouge vous demande "poliment" ',
        'si vous êtes un ami de ce comique mais vous n''avez ',
        'pas le temps de répondre.', '',
        'Le "comique" s''est emparé d''une barre de fer et ',
        'frappe le soldat au niveau du visage.',
        'Ce dernier tombe mais un autre apparait à ce moment ',
        'menaçant de vous tuer avec son arme.');
      texte_choix_2_histoire('1. Répliquer', '2. Courir');
      readln(selection);
      if selection = 1 then
      begin
        modif_sous_checkpoint(2);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
        begin
          combat(1, 1);
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
          texte('Vous devez partir avant que d''autres ',
            'gardes n''arrivent !', '', '', '', '', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if selection = 2 then
      begin
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte('S''en suit une course au travers de ',
          'la station, durant laquelle les soldats ',
          'tentent de vous tuer, vous parvenez miraculeusement',
          'à ne subir aucun dégât mais au détour d’une passerelle, ',
          'l''homme devant vous se fait assommer.', '',
          'Vous parvenez à esquiver mais le sol se dérobe sous',
          'vos pieds et vous perdez connaissance.', '',
          'Vous vous réveillez douloureusement, un homme vous',
          'demande de ne pas faire trop de bruit.', '',
          'Il vous apprend que vous êtes recherché.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Il se présente, il s''appelle Andreï et est forgeron.',
          'Heureux d’être tombé sur lui, vous lui expliquez la situation.', '',
          'Ce dernier après vous avoir écouté vous explique ',
          'qu''une caravane part pour le front tôt ',
          'demain et qu''il va falloir en profiter pour vous faufiler ',
          'au travers des champs de bataille pour continuer votre route.', '',
          'En attendant que tout soit prêt, vous  partez dans la station, ',
          'déguisé afin qu''on ne puisse vous reconnaitre.', '',
          'Vous arrivez au niveau des marchands.', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('"Salut, quoi que tu cherches je l''ai forcement !"', '', '', '',
          '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_quantite_arme_1_v(0);
        modif_quantite_arme_2_v(0);
        modif_quantite_arme_3_v(1);
        modif_quantite_arme_4_v(1);
        modif_quantite_arme_5_v(1);
        modif_quantite_objet_1_v(10);
        modif_quantite_objet_2_v(10);
        modif_quantite_objet_3_v(10);
        vendeur;
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Andreï vous rejoint, il vous demande si ',
          'vous souhaitez changer d''équipement et vous ',
          'en propose deux autres.', '', '', '', '', '', '', '', '', '', '');
        while (selection <> 3) and (condition = 0) do
        begin
          texte_choix_3_histoire('1. Soldat', '2. Espion', '3. Non merci');
          readln(selection);
          if selection = 1 then
          begin
            texte('En choisissant l''équipement Soldat vous choisissez ',
              'd''augmenter votre résistance et votre durée de vie.', '',
              'Choisir cet équipement ?', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('1. Oui', '2. Non');
            readln(selection_1);
            if selection_1 = 1 then
            begin
              modif_id_armure(1);
              condition := 1;
            end
            Else if selection_1 = 2 then
            begin
            end;
          end
          Else if selection = 2 then
          begin
            texte('Cette tenue légère vous permettras de vous déplacer plus ',
              'silencieusement et d''éviter ainsi de vous faire repérer.', '',
              'Choisir cet équipement ?', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('1. Oui', '2. Non');
            readln(selection_1);
            if selection_1 = 1 then
            begin
              modif_id_armure(2);
              condition := 1;
            end
            Else if selection_1 = 2 then
            begin
            end;
          end
          Else if selection = 3 then
          begin
            texte('Vous choisissez de garder votre équipement.', '', '', '',
              '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end;
        modif_sous_checkpoint(5);
        rewrite(save);
        sauvegarde;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
    begin
      texte('Maintenant prêt à partir, Andreï est ',
        'rejoint par un autre homme, ce dernier vous explique ',
        'que pour rejoindre les champs de bataille, ',
        'vous allez devoir vous installer sous la draisine.', '',
        'Il vous assure que c''est la seule solution mais que ',
        'ce ne sera pas un trajet des plus confortables.', '', '', '', '', '',
        '');
      texte_choix_2_histoire('1. Accepter', '2. Refuser');
      readln(selection);
      if selection = 1 then
      begin
        texte('Vous remerciez Andreï et l''homme pour leur aide.', '', '', '',
          '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
        texte('Vous faites comprendre à Andreï et ',
          'son collègue que non, vous n''allez pas risquer ',
          'votre vie sous une draisine et vous partez',
          'sur les champs de bataille par le tunnel en',
          'profitant de l''inattention d''un garde.', '',
          'Proche des champs de bataille, vous vous faites ',
          'percuter par une draisine lancée à toute vitesse ',
          'ce qui vous coute la vie.', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Vous passez sous la draisine ou est installé une ',
          'cachette de fortune qui ne parait pas vraiment solide.', '',
          'Quelques minutes après sa mise en place, plusieurs ',
          'jeunes recrues s''installent et commence à parler ',
          'de cette guerre en les Rouges et les Faschos.', '',
          'La draisine part...', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1
      end;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure communisme;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Communisme contre le Reich');
    modif_checkpoint(16);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous voilà presque arrivé, l''endroit est bruyant et ',
        'surtout plein de Rouges près à vous', 'tuer au moindre faux pas.', '',
        'Cependant, le plancher de la cachette se brise ',
        'vous laissant sur les rails, par chance, personne',
        'personne ne l''a remarqué et vous êtes entier,',
        'ça tient presque du miracle !', '',
        'Reprenant votre esprit vous partez en ',
        'direction des champs de bataille.',
        'Vous constatez que la bataille se trouve sur l''autre ',
        'voie de métro, il vous faut donc la rejoindre.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    if (get_id_armure = 1) then
    begin
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        combat(1, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
        begin
          texte('Vous empruntez un escalier donnant sur un ',
            'passage passant sous l''autre voie.', '', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(1, 1);
          if get_victoire = 1 then
          begin
            modif_sous_checkpoint(6);
            rewrite(save);
            sauvegarde;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez échoué... Vous êtes faible... ',
              'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if (get_id_armure = 2) then
    begin
      modif_sous_checkpoint(4);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Vous empruntez un escalier donnant sur un ',
          'passage passant sous l''autre voie.', '', '', '', '', '', '', '',
          '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_sous_checkpoint(6);
        rewrite(save);
        sauvegarde;
      end;
    end
    Else
    begin
      modif_sous_checkpoint(5);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
      begin
        texte('Vous empruntez un escalier donnant sur un ',
          'passage passant sous l''autre voie.', '', '', '', '', '', '', '',
          '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(1, 1);
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(6);
          rewrite(save);
          sauvegarde;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 6) then
    begin
      texte('Vous assistez de loin à l''exécution ',
        'd''un soldat pour désertion tandis que ce dernier ',
        'tente d''expliquer qu''il n''a pas déserté',
        'mais qu''il cherchait un autre moyen pour attaquer',
        'de revers les Faschos.', '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('1. Passer les champs de bataille',
        '2. Contourner les champs de bataille');
      readln(selection);
    end;
    if selection = 1 then
    begin
      modif_sous_checkpoint(7);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 7) then
      begin
        texte('Evidemment vous tombez sur plusieurs soldats.', '', '', '', '',
          '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(2, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(8);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 8) then
        begin
          texte('En passant du coté ennemi vous tombez sur deux Faschos.', '',
            '', '', '', '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(2, 1);
          if get_victoire = 1 then
          begin
            modif_sous_checkpoint(10);
            rewrite(save);
            sauvegarde;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez échoué... Vous êtes faible... ',
              'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if selection = 2 then
    begin
      modif_sous_checkpoint(9);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 9) then
      begin
        texte('Profitant de l''information laissée par ',
          'l''exécuté, vous passez par un petit couloir de',
          'service difficilement accessible.', '',
          'En suivant ce couloir vous débouchez dans une ',
          'salle de service coté Reich.', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(2, 1);
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(10);
          rewrite(save);
          sauvegarde;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 10) then
    begin
      if (get_id_armure = 1) then
      begin
        modif_sous_checkpoint(11);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 11) then
        begin
          texte('Quelques hommes sont postés pour garder le camp, ',
            'cependant vous pouvez passer sans tous les tuer.', '', '', '', '',
            '', '', '', '', '', '', '');
          texte_choix_2_histoire('1. EXTERMINER !', '2. Tuer le minimum');
          readln(selection);
          if selection = 1 then
          begin
            combat(6, 1);
          end
          Else if selection = 2 then
          begin
            texte('Vous pouvez passer en tuant deux gardes.', '', '', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            combat(2, 1);
          end;
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(15);
          rewrite(save);
          sauvegarde;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if (get_id_armure = 2) then
      begin
        modif_sous_checkpoint(13);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 13) then
        begin
          texte('La majorité des hommes étant partis au front, ',
            'vous passez facilement leur camp.', '', '', '', '', '', '', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          modif_sous_checkpoint(15);
          rewrite(save);
          sauvegarde;
        end;
      end
      Else
      begin
        modif_sous_checkpoint(14);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 14) then
        begin
          texte('Quelques hommes sont postés pour garder le camp, ',
            'cependant vous choisissez de passer en ', 'tuant deux gardes.',
            '', '', '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(2, 1);
          if get_victoire = 1 then
          begin
            modif_sous_checkpoint(15);
            rewrite(save);
            sauvegarde;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez échoué... Vous êtes faible... ',
              'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 15) then
    begin
      texte('Ayant passé leur camp, vous avancez vers une porte.', '',
        'Alors que vous alliez tourner la poignée, celle-ci ',
        's''ouvre violemment vous projetant en arrière.', '',
        'Deux Fachos entrent alors dans la pièce et vous traine ',
        'derrière la porte.', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure aide;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Une aide inespéré');
    modif_checkpoint(17);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous voilà par terre face à des Faschos cherchant visiblement à',
        'vous faire supplier pour qu''ils vous épargnent.', '',
        'Cependant le plus vieux du groupe semble vouloir en finir ',
        'au plus vite, il sort son arme et la pointe sur votre tête.', '',
        'Lorsqu''il commence à presser la détente, un groupe d''homme entre ',
        'par l''arrière et prend par surprise les Faschos',
        'les mettant aisément à terre.', '',
        'En les voyants faire, vous comprenez que ce sont des Rangers...',
        'Des Rangers de Polis !',
        'Un des hommes vous tend la main pour vous aider à vous relever.');
      texte_choix_2_histoire('1. Saisir la main', '2. Se relever seul');
      readln(selection);
      if selection = 1 then
      begin
        texte('"Allez mon gars, faut se lever"', '', '', '', '', '', '', '',
          '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
      end;
      texte('Un autre Rangers vous demande ce que vous faites ',
        'ici étant donné que vous n''êtes ni', 'un Rouge, ni un Fascho.', '',
        '', '', '', '', '', '', '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte_choix_2_histoire('1. Expliquer votre mission', '2. Ne rien dire');
      readln(selection);
      if selection = 1 then
      begin
        texte('Vous expliquez votre mission aux Rangers, ',
          'ce dernier, un peu dubitatif, vous demande de prouver ',
          'que vous êtes bien envoyé par Hunter.', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_2_histoire('1. Montrer la plaque',
          '2. Ne pas montrer la plaque');
        readln(selection_1);
        if selection_1 = 1 then
        begin
          texte('Apres avoir bien observé ',
            'la plaque, ils comprennent que vous êtes',
            'bel et bien envoyé par Hunter.', '', '', '', '', '', '', '', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
        end
        Else if selection_1 = 2 then
        begin
          texte('N''ayant pas de preuve, les Rangers décident de partir ',
            'sans vous mais en vous ayant libéré.', '',
            'Quelques mètres plus loin, vous vous faites arrêter ',
            'par des Faschos qui décident de vous faire subir',
            'un procès sans une quelconque chance de gagner votre liberté.',
            '', 'Vous finissez dos au mur perforé de plusieurs balles.', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if selection = 2 then
      begin
        texte('N''ayant pas de justification de votre part, ',
          'les Rangers décident de partir sans vous mais ',
          'en vous ayant libéré.', '',
          'Quelques mètres plus loin, vous vous faites arrêter ',
          'par des Faschos qui décident de vous faire subir un procès',
          'sans une quelconque chance de gagner votre liberté.', '',
          'Vous finissez dos au mur perforé de plusieurs balles.', '', '', '',
          '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Ils décident de vous escorter jusque Polis ',
        'afin d''être sûr que vous puissiez bien transmettre ',
        'les supposées dernières volontés d''Hunter au Conseil.', '',
        'Ces derniers vous conduisent jusqu''une draisine armée ',
        'prise aux Faschos.', '',
        'Le groupe se sépare, vous restez avec celui qui s''appelle Boris, ',
        'tandis que les autres passent par un autre ',
        'chemin, ils vous attendront au niveau de la Station Noire.', '',
        'Boris vous demande de vous installer au niveau de la tourelle.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Une fois installé, la draisine démarre.', '',
        'En route pour la station noire, vous arrivez',
        'à un poste de contrôle Fascho.', '',
        'Boris tente tant bien que mal de se faire passer pour un soldat ',
        'mais sa couverture et rapidement grillée, sous une pluie de balle, ',
        'la draisine repart à toute vitesse, traversant des clôtures de fortune.'
          , '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(2, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(4);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Croyant être sortis d’affaire, vous ',
          'êtes attaqués par un Panzer. ', '',
          'Boris vous ordonne de viser les piliers, maintenant ',
          'le chemin de fer sur lequel repose le Panzer.', '',
          'En les détruisant, vous faites tomber le Panzer dans le vide.', '',
          'Vous reprenez votre chemin, vous avez échappé de peu à ',
          'la mort mais vous êtes content de vous en être sorti.',
          'Votre draisine vous lâche, il vous en faut une nouvelle par ',
          'chance une autre se trouve à proximité, ',
          'seulement elle est non armée.');
        texte_choix_2_histoire('1. Changer de draisine', '2. Garder la votre');
        readln(selection);
        if selection = 1 then
        begin
          texte(
            'Une fois dedans, Boris actionne le mécanisme, la draisine avance, '
              , 'cependant lors d''une descente, elle part ',
            'dans la mauvaise direction...', '', '', '', '', '', '', '', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          texte('Votre draisine vous lâche ',
            'complètement quelques mètres plus loin.', '',
            'Etant hors de question de continuer ',
            'à pied, vous revenez sur vos pas.', '', '', '', '', '', '', '',
            '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(2, 1);
          if get_victoire = 1 then
          begin
            rewrite(save);
            sauvegarde;
            texte('Une fois dedans, Boris actionne le mécanisme, ',
              'la draisine avance, cependant lors d’une ',
              'descente, elle part dans la mauvaise direction...', '', '', '',
              '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez échoué... Vous êtes faible... ',
              'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure depot;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Le dépot');
    modif_checkpoint(18);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Apres une longue chute aux enfers, vous arrivez ',
        'dans un grand espace, rempli de rames.', '',
        'Boris reconnait l''endroit et parait émerveillé, ',
        'il s''agit selon lui du dépôt, là où vont les rames ',
        'qui ne sont pas en fonction.', '',
        'Cependant l''émerveillement est de courte durée, ',
        'vous entendez des bruits dans les rames, ',
        'et quelque chose vous observe.', '',
        'Boris accélère le rythme mais trop tard, ',
        'des Nosalis sortent de toutes les rames !');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(3, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        texte('Faisant de votre mieux pour protéger Boris, ',
          'celui-ci finit par ce faire attraper par ',
          'un Nosalis qui l''entraine dans les profondeurs du dépôt.', '',
          'Comprenant que vous ne pouvez pas le sauver, ',
          'vous continuez votre chemin sans vous retourner.', '',
          'La draisine va vite, très vite, trop vite...', '',
          'Vous percutez un obstacle sur la voie ce qui ',
          'vous éjecte de votre draisine.', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Vous vous relevez difficilement, ',
          'vous ne savez pas ou vous êtes ',
          'mais vous ne pouvez qu''aller tout droit ', 'devant vous.', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure station_de_la_breche;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Station de la Brèche');
    modif_checkpoint(19);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous tombez sur un barrage, des hommes sont à terre ',
        'baignant dans leur propre sang.', '',
        'En vous approchant des hommes, vous êtes mis en joue.', '',
        'Vous apprenez que la station est en cours d''évacuation, ',
        'car des Nosalis attaquent la station depuis plusieurs jours.', '',
        'On vous demande alors d''aider les gardes.', '', '', '', '');
      texte_choix_2_histoire('1. D''accord', '2. Nan !');
      readln(selection);
    end;
    if selection = 1 then
    begin
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        texte('Vous vous mettez en position, prêt à en découdre.', '',
          'C''est alors qu''une énorme rafale traverse le ',
          'tunnel vous faisant tomber.', '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(3, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if selection = 2 then
    begin
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
      begin
        texte('Une énorme rafale traverse le ', 'tunnel vous faisant tomber.',
          '', 'Des Nosalis arrivent vers vous mais vous ',
          'n''avez pas le temps de vous saisir de votre ',
          'arme pour les abattre.', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
    begin
      texte('Les Nosalis ont arrêté d''attaquer, une rafale arrive,',
        'cette fois vous vous mettez bien à l''abri.', '', '', '', '', '', '',
        '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Les hommes composants la garde sont ',
        'affaiblis, peu sont encore en vie.', '',
        'L''un d''entre eux vous demande d''entrer',
        'dans la station et d''aller jusque Polis pour ',
        'demander de l''aide, il vous remet une cassette contenant ',
        'un enregistrement expliquant la situation.', '', '', '', '', '', '');
      texte_choix_2_histoire('1. Refuser', '2. Accepter');
      readln(selection);
    end;
    if selection = 1 then
    begin
      modif_sous_checkpoint(5);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
      begin
        texte('Ayant les nerfs à fleur de peau, les rescapés ',
          'vous attaquent suite à votre refus.', '', '', '', '', '', '', '',
          '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(5, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(6);
        rewrite(save);
        sauvegarde;
        texte('Une fois tous morts, plus ', 'rien ne vous empêche de passer.',
          '', 'Mais un dernier miliciens arrive ',
          'et vous poignarde dans le dos.', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if selection = 2 then
    begin
      modif_sous_checkpoint(6);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 6) then
    begin
      texte('En arrivant dans leur Station, vous constatez ',
        'que celle-ci est dans le même état que la Station Maudite,',
        'cependant celle-ci est infestée de Rôdeurs.', '', '', '', '', '', '',
        '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(3, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(7);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 7) then
      begin
        texte('Vous traversez la station.', '', '', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        combat(3, 1);
      end;
      if get_victoire = 1 then
      begin
        modif_sous_checkpoint(8);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 8) then
        begin
          texte('Apres avoir traversé la station, vous ',
            'trouvez un enfant assis à côté d''un corps', 'ensanglanté.', '',
            'En vous approchant, ce dernier vous demande ', 'qui vous êtes.',
            '', 'Vous lui dites que vous venez de VDNKh et que ',
            'vous vous rendez à Polis.', '',
            'Le garçon vous demande si vous pouvez le ',
            'prendre avec vous vous jusque la prochaine ',
            'station ou se trouve trouve sa mère.');
          texte_choix_2_histoire('1. Protéger le garçon',
            '2. Le laisser à son sort');
          readln(selection);
          if selection = 1 then
          begin
            condition := 1;
            texte('Vous le prenez sur vos épaules, ',
              'ce dernier dit s''appeler Sasha.', '', '', '', '', '', '', '',
              '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection = 2 then
          begin
            texte('Vous décidez de laisser l''enfant à côté du cadavre.', '',
              'A croire que vous n''avez pas de coeur !', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
          texte('Le tunnel que vous ',
            'empruntez est lui aussi infesté de Rôdeurs.', '', '', '', '', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(3, 1);
          if get_victoire = 1 then
          begin
            if condition = 1 then
            begin
              texte('En arrivant dans une petite pièce remplie de casiers, ',
                'Sasha vous indique que celui de son oncle, ',
                'l''homme mort de tout à l''heure, contient ',
                'peut être quelque chose d''utile.', '', '', '', '', '', '',
                '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              modif_argent_perso(get_argent_perso + 40);
              modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
              readln;
              texte('Une voix résonne au loin, vous ',
                'accélérez le pas et tombez sur ',
                'des soldats retenant une femme.', '',
                'Cette dernière semble vouloir aller à la station ',
                'précédente chercher son fils.', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              texte('Sasha saute dans les bras de sa mère, ',
                'celle-ci vous remercie d''avoir sauvé son ',
                'enfant et vous donne 20 Balles.', '', '', '', '', '', '', '',
                '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              modif_argent_perso(get_argent_perso + 20);
              readln;
              modif_sous_checkpoint(9);
              rewrite(save);
              sauvegarde;
            end
            Else
            begin
              texte('Une voix résonne au loin, vous ',
                'accélérez le pas et tombez sur ',
                'des soldats retenant une femme.', '',
                'Cette dernière semble vouloir aller à la station ',
                'précédente chercher son fils.', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              modif_sous_checkpoint(9);
              rewrite(save);
              sauvegarde;
            end;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez échoué... Vous êtes faible... ',
              'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 9) then
        begin
          texte('Un soldat vous demande la raison de votre présence.', '',
            'Indiquant d''où vous venez et ou vous allez il ',
            'vous indique par ou passer pour rejoindre Polis.', '',
            'Un trajet dangereux car passant par la surface.', '',
            'Avant de partir, il vous dit également que quelques ',
            'marchands sont bloqués ici et qu''ils seraient ',
            'surement contents de faire un peu affaire.', '', '', '');
          while selection <> 2 do
          begin
            texte_choix_2_histoire('1. Voir les marchands',
              '2. Rejoindre la surface');
            readln(selection);
            if selection = 1 then
            begin
              modif_quantite_objet_1_v(10);
              modif_quantite_objet_2_v(10);
              modif_quantite_objet_3_v(10);
              modif_quantite_arme_1_v(1);
              modif_quantite_arme_2_v(1);
              modif_quantite_arme_3_v(1);
              modif_quantite_arme_4_v(1);
              modif_quantite_arme_5_v(1);
              vendeur;
            end
            Else if selection = 2 then
            begin
            end;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez échoué... Vous êtes faible... ',
          'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure retour_a_la_surface;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Retour à la surface');
    modif_checkpoint(20);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('En sortant du métro, vous tombez malheureusement sur ',
        'un camp de Faschos, ces derniers semblent vouloir entrer ',
        'et prendre d''assaut les personnes vous ayant aidé.', '', '', '', '',
        '', '', '', '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte_choix_2_histoire('1. Les empêcher de passer',
        '2. Les laisser passer');
      readln(selection);
    end;
    if selection = 1 then
    begin
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        combat(5, 1);
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
          texte('Maintenant qu''ils sont mort, vous reprenez votre ',
            'route l''esprit tranquille.', '', '', '', '', '', '', '', '', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end
      end
    end
    Else if selection = 2 then
    begin
      texte('Vous aurez le sang des victimes sur les mains !', '', '', '', '',
        '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      modif_sous_checkpoint(3);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Vous reprenez votre chemin au travers ',
        'des rues désolées de l''ancienne capitale Russe.', '',
        'Au détour d''une rue vous tombez de nouveau ', 'sur des Faschos.', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(2, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(4);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Vous arrivez finalement à ',
          'l''entrée secondaire de la Station Noire.', '', '', '', '', '', '',
          '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure ligne_droite;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Ligne droite');
    modif_checkpoint(21);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Oulman, un des Rangers vous attend, ',
        'seulement il est derrière une grille, ',
        'il vous explique que la station est envahie par les ',
        'Faschos et qu''il vous faut la traverser seul.', '',
        'La station est belle et bien remplie de Faschos, ',
        'vous avancez prudemment mais quelques gardes ', 'vous remarquent.',
        '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      combat(2, 1);
    end;
    if get_victoire = 1 then
    begin
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
      begin
        texte('Vous parvenez à revenir dans l''ombre, ',
          'cependant vous avez le choix.', '', '', '', '', '', '', '', '', '',
          '', '');
        texte_choix_2_histoire('1. Passer la station sans combattre',
          '2. Tuer tous les Faschos');
        readln(selection);
      end;
      if selection = 1 then
      begin
        modif_sous_checkpoint(3);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
        begin
          texte('Vous vous collez aux murs,',
            'faisant le moins de bruit possible.', '',
            'Afin de progresser, vous comprenez qu''il vous faut ',
            'les priver de lumière afin de passer parmi eux',
            'sans vous faire remarquer.', '',
            'Vous partez donc vers l''étage inférieur, ',
            'le générateur est là, tout proche.',
            'Mais des gardes sont autour.', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(2, 1);
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(5);
          rewrite(save);
          sauvegarde;
          texte('Vous éteignez le générateur ',
            'plongeant la station dans le noir.', '',
            'Vous pouvez ainsi rejoindre Oulman sans trop vous ',
            'soucier des gardes totalement perdus ne ',
            'pouvant pas faire la différence entre un des leurs et vous.', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if selection = 2 then
      begin
        modif_sous_checkpoint(4);
        rewrite(save);
        sauvegarde;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
        begin
          combat(10, 1);
        end;
        if get_victoire = 1 then
        begin
          modif_sous_checkpoint(5);
          rewrite(save);
          sauvegarde;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez échoué... Vous êtes faible... ',
            'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
      begin
        texte('Vous rejoignez Oulman, celui-ci ',
          'vous attendait près d’une draisine', 'motorisée.', '',
          'Vous pouvez enfin vous reposer un peu.', '',
          'Bientôt... Vous donnerez le message d’Hunter, ',
          'votre station sera sauvée... Bientôt...', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez échoué... Vous êtes faible... ',
        'Vous êtes nul... Mais je vous propose ', 'de rejouer !', '', '', '',
        '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      game_over := 1;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

procedure polis;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('Polis');
    modif_checkpoint(22);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Le voyage ne fut pas très long, en approchant ',
        'de la station, un garde vous hurle ',
        'de vous identifier, c''est Oulman qui répond.', '',
        'La porte s''ouvre, vous entrez enfin ', 'dans Polis "la Magnifique".',
        'Son nom est bien trouvée, la station est propre, ',
        'totalement éclairée, un soin particulier ',
        'est donnée à son entretien.', '',
        'La draisine s''arrête devant une porte, ', 'Oulman entre avec vous.',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('La pièce contient un bureau, derrière ce ',
        'trouve un homme d''une quarantaine d''année, ',
        'un homme de terrain, ça se voit au premier coup', 'd''oeil !', '',
        'Il s''appelle Melnik apparemment', '',
        'Oulman parle à votre place, il explique la',
        'situation et vous demande de montrer la ', 'plaque d’Hunter.', '',
        'Sans plus attendre, Melnik utilise un micro et',
        'demande aux membres du Conseils de ce réunir.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous êtes devant l''immense porte en bois ',
        'de la chambre du conseil.', '', 'Elle commence à s''ouvrir et...', '',
        '', '', 'La suite un jour peut-être .', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end;
    modif_sous_checkpoint(0);
    rewrite(save);
    sauvegarde;
    chapitre_suivant := 1;
  end;
  chapitre_suivant := 0;
end;

end.
