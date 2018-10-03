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

procedure march�s;

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
      march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
        march�s;
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
    modif_chapitre('Ch�teau');
    modif_checkpoint(1);
    rewrite(save);
    sauvegarde;
    texte('Apr�s avoir travers� une for�t �tonnamment ',
      'paisible, vous arrivez au beau milieu d''un ',
      'village dans lequel un homme vous aborde.', '',
      '"Ho h� �tranger, es-tu un de ces jeunes fou ',
      'pr�t � mettre votre vie en jeu en esp�rant trouver',
      'le tr�sor de l''ancien ch�teau du duch� de ', 'Lapalud ?".', '', '', '',
      '', '');
    texte_choix_2_histoire('1. Oui oui, je suis de ceux la !', '2. Non');
    readln(selection);
    if selection = 1 then
    begin
      texte('"Bon j''imagine que ce n�est pas la peine ',
        'de tenter de te dissuader...', '', 'Quel est ton nom ? ', '',
        'Non pas que �a m''int�resse vraiment mais ',
        'il faut bien graver un nom sur ta future ', 'tombe !"', '', '', '',
        '', '');
      texte_choix_2_histoire('Votre nom: ', '');
      readln(reponse);
      modif_nom_perso(reponse);
      texte_nom('"Tr�s bien mon cher ', ', je vais ',
        't''accompagner au ch�teau, par contre ',
        'je te laisse � l''entr�e, pas ',
        'particuli�rement envie de mettre ma vie en ',
        'danger pour des prunes gamins !"', '',
        'En entrant dans le ch�teau vous vous ',
        'retrouvez dans un hall sombre �clair� par ',
        'd''�tranges torches br�lant d''un feu violet, ',
        'il vous est impossible de voir plus loin que ',
        'le bout de vos pieds, cependant, vous avez ',
        'l''impression d''�tre observ� pire, que ',
        'quelques chose se d�place dans l''ombre...', get_nom_perso);
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('N''�coutant que votre courage ',
        '(ou votre stupidit� c''est au choix) vous',
        'vous mettez un pied devant l''autre et...', '', '', '', '', '', '', '', '',
        '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
    end
    Else if selection = 2 then
    begin
      texte('"Alors va-t''en tu g�nes !"', '',
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
        'Il semble qu�on vous appelle, mais la voix ',
        'est �touff�e, vous avez du mal � comprendre.', '',
        '"Mais r�veille-toi bordel, ', ' !"', '',
        'La voix est bien plus compr�hensible, le ton',
        'indique que la personne est de plus en plus ', 'en col�re.', '', '',
        '', get_nom_perso);
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Cette voix, vous la reconnaissez... Mais oui',
        'c''est celle de votre p�re !!', '',
        'Vos yeux s''ouvrent d''un coup, par chance, il ',
        'fait suffisament sombre pour ne pas �tre ', '�bloui.', '',
        'Votre regard se balade dans le vague, ',
        'vous distinguez vos effets personnels, ', 'est-ce votre chambre ?',
        '', '"Enfin... Prends ton temps hein, enfin bref, ',
        'je t''attends dans le couloir, d�p�che-toi."');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous vous levez de votre lit.', '',
        'Bien que votre chambre soit faiblement ',
        '�clair�e vous vous regardez dans le miroir', '� cot� de votre lit',
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
      texte_choix_3_histoire('1. Allumer la lumi�re', '2. Observer la pi�ce',
        '3. Quitter la pi�ce');
      readln(selection);
      condition := 0;
      while (selection_1 <> 2) and (selection <> 3) do
      begin
        if selection = 1 then
        begin
          texte('La lumi�re est maintenant allum�e', '', '', '', '', '', '',
            '', '', '', '', '', '');
          condition := 1;
          texte_choix_2_histoire('1. Observer la pi�ce', '2. Quitter la pi�ce');
          readln(selection_1);
        end;
        if (selection = 2) and (condition = 1) or (selection_1 = 1) and
          (condition = 1) then
        begin
          texte('La pi�ce est petite, plut�t en d�sordre avec ',
            'votre lit dans le fond, une toute petite ',
            'table sur laquelle la lampe de bureau que ',
            'vous venez d''allumer tr�ne.', '',
            'Sur la table un briquet en forme de balle, ',
            'un plan usag�, quelques livres ab�m�s.', '',
            'Dans un coin est pos� une vieille guitare ',
            's�che griff�e, sur les murs sont accroch�s ',
            'des cartes postales et dans l''autre coin une',
            'vieille armoire r�cup�r�e on ne sait o�, ',
            'rafistol�e tant bien que mal.');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          selection_1 := 2;
        end
        else if (selection = 2) and (condition = 0) then
        begin
          texte('Il vous est impossible de distinguer quoi que',
            'ce soit, moins que dans le ch�teau de votre ', 'r�ve.', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('1. Allumer la lumi�re', '');
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
        'quatres hommes vous salue, votre p�re vous ',
        'attend un peu plus loin, sans un mot vous ',
        'vous mettez � le suivre', '',
        'En arpentant les couloirs, vous croisez un ',
        'homme tentant d''occuper sa fille en lui ',
        'demandant de dessiner la maison dans laquelle',
        'elle souhaiterait vivre avec ses parents, ',
        'et une femme visiblement m�contente de ', 'nettoyer le sol.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('En quittant le couloir vous tombez sur une ',
        'longue file d''attente devant la lourde porte',
        'de ce qui sert d''h�pital, probablement des',
        'parents venus demander des nouvelles de ',
        'leurs maris fils etc... Suite � la derni�re', ' attaque des Sombres.',
        '', 'Quelques "soldats" mal �quip�s tentent de ',
        'les emp�cher d''entrer.', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Votre p�re frappe trois sur la porte en fer ', 'rouill�e.', '',
        'Une sorte de visi�re s''ouvre, derri�re un ',
        'homme semble le reconna�tre.', '',
        'Pendant ce temps une femme vous interpelle, ',
        'elle est visiblement affol�e, vous demande ',
        'si vous avez des nouvelles du front, si son ',
        'mari se trouve derri�re cette porte.',
        'Pas le temps de r�pondre, votre p�re vous ',
        'pose la main sur l''�paule vous indiquant de ', 'le suivre.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous entrez dans une sorte de bureau, la ',
        'pi�ce est un poil plus grande que votre ',
        'chambre, � votre gauche sont accroch�es ',
        'plusieurs blouses jaunies par le temps et ', 'tach�es de sang.', '',
        'Trois hommes sont �galement pr�sents, ils ',
        'racontent que l''avant-poste a �t� attaqu� ',
        'par les Sombres il y a quelques heures et ',
        'que plus aucun des gars stationn�s n''est en ',
        'mesure de r�pondre de quoi que ce soit.', '',
        '"Enfin tu verras par toi-m�me Soukho�..."');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('L''un d''eux ouvre une petite porte en bois ',
        'dans le fond de la pi�ce, imm�diatement ',
        'l''odeur de la mort emplit vos narines, bien',
        'que n''ayant pas envie de voir ce qu''il y a ',
        'dans la pi�ce suivante, vous continuez de ', 'suivre votre p�re.', '',
        'L''odeur est de plus en plus forte, vous ',
        'entendez des plaintes venant de derri�res ',
        'les draps blancs tach�s servant � s�parer ', 'les lits', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Certains sont arrach�s, exposant quelques ',
        'hommes le regard dans le vague, des bandages',
        'un peu partout tandis que d''autres se mettent',
        '� hurler en vous voyant passer.', '',
        'D''autres encore ne bougent pas, il sont morts,', ' tout simplement.',
        '', 'Le m�decin vous accompagne vers la pi�ce ',
        'suivant correpondant � l''entr�e de votre ',
        'station tout en expliquant � votre p�re que ',
        'la station ne tiendrait pas longtemps si on ',
        'ne r�soud pas le probl�me des Sombres.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('L''entr�e de la station est gard�e par deux ',
        'hommes arm�es et visiblement tendues.', '',
        'Apres un court rapport � votre p�re, un bruit',
        'sourd fait sont apparition, quelqu''un semble ',
        'frapper � la lourde porte en acier de la ', 'station...', '',
        'Un des deux hommes arme son AK-47 le seconde ',
        'exprime sa crainte que ce ne soit des Nosalis ',
        'ou des Sombres mais Soukho� les interromps ',
        'leur rappelant que les monstres ne frappent ',
        'pas aux portes avant d''entrer.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Il ordonne l''ouverture de la porte.', '',
        'Une fois la porte suffisamment ouverte, vous ',
        'reconnaissait Hunter, un Ranger de Polis que ',
        'vous connaissez depuis un longtemps.', '',
        'Ce dernier explique venir suite aux rumeurs ',
        'd''attaque de VDNKh par "des cr�atures ',
        'nomm�es Sombres" dont Polis a eu vent.', '',
        'Son r�le est de v�rifier si les faits sont ', 'bien r�els.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Les lumi�res s''�teignent, la lumi�re rouge ',
        'indiquant un danger s''allumer, le silence ', 's''installe...', '',
        'Votre p�re ouvre rapidement un casier et vous ',
        'tend un revolver us� et trois douzaines de ', 'balles.', '',
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
          '"Probablement attir�s par l''odeur du sang de ', 'l''h�pital !"',
          '', '"Mais ils ne viennent jamais aussi proche de ',
          'la station..."', '', 'Un homme entre en courant dans la pi�ce en ',
          'hurlant.', '"Des Sombres, des Sombres ont attaqu� ',
          'l''avant-poste !"', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Sans attendre, vous courez en direction de ', 'l''avant poste.',
          '', 'Celui-ci est cribl� de balle, les soldats ',
          'sont � terre, certains morts, d''autres ',
          'totalement d�connect�s par la peur.', '',
          'Hunter d�cide de partir par le tunnel par ',
          'lequel les Sombres sont arriv�s, il vous fait ',
          'promettre que si dans deux jours in n''est pas ',
          'revenu, vous partirez pour Polis expliquer au ',
          'Conseil la menace que repr�sente les Sombres.',
          'Il vous remet �galement sa plaque d''identification.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        rewrite(save);
        sauvegarde;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
      texte('Hunter n''est �videmment pas revenu, vous ',
        'devez donc partir rejoindre Polis et les ', 'informer de la menace.',
        '', 'Vous partez pour Riga, une station voisine ',
        'avec laquelle VDNKh a pass� un nouvel ',
        'accord commercial afin de relier les deux ',
        'station par un c�ble t�l�phonique.', '',
        'Ce n''est qu''une excuse pour partir sans ',
        'que votre p�re (qui n''est pas au courant ',
        'de votre promesse) ne vous retienne.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Mais avant tout le vous faut de ',
        'l''�quipement au march� de VDNKh !', '', '', '', '', '', '', '', '',
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
          'l''�quipement au march� de VDNKh !', '', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_4_histoire('1. Parler � un Homme et son fils',
          '2. Regarder les �tals', '3. Acheter de l''�quipement',
          '4. Partir pour Riga');
        readln(selection);
        if (selection = 1) then
        begin
          texte('Celui-ci vous demande deux balles afin ',
            'd''acheter quelques m�dicaments', '', '', '', '', '', '', '', '',
            '', '', '');
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if (selection_1 = 1) then
          begin
            modif_argent_perso(get_argent_perso - 3);
            texte('Perte de trois balles car vous �tes ', 'g�n�reux !', '',
              'Merci , merci infiniment !', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin
            texte('"Je comprendre... D�sol� de t''avoir ', 'd�rang�', '', '',
              '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if selection = 2 then
        begin
          texte('Il y a de tout, des champignons, du porc, ',
            'des herbes qui font rire mais tout est cher ',
            'et pas forc�ment utile pour votre voyage.', '', '', '', '', '',
            '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 3 then
        begin
          texte_nom('"Salut ', ' ! Tu vas bien ?', '',
            'Tu viens chercher un peu d''�quipement pour ', 'ta mission ?"',
            '', '', '', '', '', '', '', '', '', get_nom_perso);
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if (selection_1 = 1) then
          begin
            texte('"Voil�, cinq m�dipacks et VSxxxxxxxxxxxx"', '', '',
              '"Et voila, tu es pr�t."', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 5);
            readln;
            condition := 1;
          end
          Else if selection_1 = 2 then
          begin
            texte('"D''accord, passe le bonjour de ma part � ',
              'ton p�re alors !"', '', '', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            texte('Vous prenez la direction des quais.', '', '', '', '', '',
              '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            texte('Un soldat vous emp�che de passer sous ',
              'pr�texte que vous n''�tes pas �quip�.', '', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end
        Else if selection = 4 then
        begin
        end;
      end;
      texte('Une fois �quip� vous prenez la direction des ', 'quais.', '', '',
        '', '', '', '', '', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('"Ah bah enfin, je vois que tu prends ton ', 'temps mon gars !',
        '', 'Allez, magne toi de monter dans la draisine ',
        'qu''on partent !"', '', '',
        'Vous montez dans la draisine et celle-ci ', 'd�marre.', '', '', '',
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
        'vous ne faites qu''�couter.', '',
        'Quelques minutes apr�s avoir franchi le ',
        'dernier point de contr�le de VDNKh, un ',
        'sentiment �trange s''empare de vous, le temps ',
        'semble ralentit, vos compagnons commencent � ',
        'tomber dans les bras de Morph�e, puis vint ', 'votre tour.', '', '',
        '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Combien de temps s''est pass�, vous n''en ',
        'n''avez aucune id�e, seulement, les plaintes ',
        'des Nosalis vous ont r�veill�, ni une ni deux ',
        'vous commencez � r�veiller le reste du groupe, ',
        'les Nosalis arrivent � grands pas.', '',
        'La draisine repart mais c''est trop tard, les ',
        'Nosalis vous attaquent !', '',
        'Un de vos compagnons vous donne son fusil ',
        '� pompe en vous suppliant de vous en servir',
        'correctement pendant que lui et un autre ',
        'actionne le levier pour acc�l�rer');
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
          'coin sombre � l''abri de leur vue.', '',
          'Une fois la meute pass�e, vous courrez dans ',
          'la direction de la draisine, celle-ci est ',
          'ariv�e � l''avant-poste de Riga et une odeur ',
          'de chaire br�l�e emplit vos narines.', '',
          'Un lance flamme est install� et � ses pieds ',
          'plusieurs dizaines de cadavres de Nosalis ', 'calcin�s', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Vous �tes enfin arriv�s � la station et pour ',
          'f�ter �a, vos compagagnons d''infortune et ',
          'vous allez boire un verre au bar de la ', 'station.', '', '', '',
          '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        'donnent 10 Balles', '', 'Vous d�cidez de partir pendant qu''ils ',
        'continuent � boire, en arrivant pr�s des quais, ',
        'vous constatez que ces derniers sont ferm�s et ',
        'surveill�s, impossible de passer donc.', '',
        'Un enfant vous regarde et vous demande de le ',
        'suivre, d''apr�s lui, un homme souhaite vous ', 'parler.',
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
          '2. Rentrer � VDNKh', '3. Suivre l''enfant', '4. Visiter la station');
        readln(selection);
        if selection = 1 then
        begin
          texte('En vous rendant vers le bureau du chef de ',
            'la station, un milicien vous d�gage de devant la',
            'porte, en effet, le chef est "�occup�" et',
            'vous devez lui "�foutre la paix�"', '', '', '', '', '', '', '',
            '', '');
          texte_choix_3_histoire('Insister', 'Provoquer', 'Laisser tomber');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('"T''es bouch� ?', 'J''ai dit DEGAGE !"', '', '', '', '', '',
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
              texte('Vous avez tricher c''est �a !!', '', '', '', '', '', '',
                '', '', '', '', '', '');
            end
            Else if (get_victoire = 0) then
            begin
              texte('Vous avez �chou�... Vous �tes faible... ',
                'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '',
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
          texte('Vous voil� rentr� � VDNKh apr�s deux jours ',
            'de dur labeur, seulement la station est ', 'd�serte...', '',
            'Enfin sauf si on compte les nombreux ',
            'corps fig�s d''horreur les yeux grands ',
            'ouverts et les mares de sang.', '',
            'Gr�ce � votre faible volont� vous avez ',
            'men� cette station � la ruine, d''ailleurs ',
            '� l''autre bout de la station, vous sentez ',
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
            '"quartier r�sidentiel" de la station.', '',
            'Une fois dans ce quartier, vous constatez la ',
            'pauvret� de la station.', '',
            'Un homme vous demande une balle pour manger', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;

        end
        Else if selection = 4 then
        begin
          texte('La station ressemble � VDNKh, � la diff�rence ',
            'pr�s qu''il y a des miliciens un peu partout ',
            'bloquant de nombreux acc�s', '',
            'Au loin une charmante demoiselle vous appelle, ',
            'elle semble l�g�rement v�tue sous son ',
            'imperm�able beige ab�m�.', '',
            'Ses intentions sembles claires, souhaitez-vous ',
            '"jouer" avec elle ?', '', '', '');
          texte_choix_2_histoire('1. Oh oui j''attendais que �a !',
            '2. Non merci... Vraiment...');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            modif_argent_perso(0);
            texte('Cette derni�re vous emm�ne vers de nombreuses ',
              'tentes, vous ouvre l''une d''entres elles et au ',
              'moment o� vous alliez entrer, un homme surgit ',
              'derri�re vous et vous frappe avec une barre de ',
              'fer au niveau de la nuque.', '',
              'Quelques minutes apr�s, vous vous r�veillez en ',
              'ayant mal au cr�ne et la bourse totalement vide.', '', '', '',
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
          texte('Vous donnez deux Balles � l''homme.', '',
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
        texte('Vous arrivez devant ce qui semble �tre une ',
          'cuisine, l''enfant vous informe que l''homme qui ',
          'est sur la chaise � cot� de la table est celui ',
          'qui vous cherche.',
          'L''enfant s''en va content d''avoir sa Balle.', '',
          'Cet homme s''appellent Bourbon, du moins, c''est ',
          'comme �a qu''il se fait appeler.', '',
          'C''est un trentenaire ayant s�rement vu(et bu au ',
          'vu de l''odeur qui l''entoure) beaucoup de choses, ',
          'il ne semble pas dou� pour les relations humaines',
          'mais il semble avoir besoin d''aide.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Il souhaite rejoindre la station Aride pour ',
          '"affaires", il vous explique qu''il conna�t un ',
          'moyen de passer outre les barrages en suivant ',
          'le "Tunnel Maudit".', '',
          'Cependant il a besoin de vous car il semble ',
          'que les ph�nom�nes �tranges des tunnels ne ', 'vous impacte pas.',
          '', 'En �change de ce service, il vous donnera son ', 'AK-47.', '',
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
            'Il vous indique o� le retrouver et surtout quand, ',
            'voyant qu''il vous reste quelques heures avant le ',
            'd�part, vous choisissez de:', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          texte_choix_2_histoire('1. D''aller vous reposer',
            '2. D''aller vous saouler avant le grand d�part');
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
          texte('En refusant d''aider Bourbon, vous d�cidez de ',
            'mener � bien votre mission consistant � relier ',
            'VDNKh et Riga.', '',
            'Apr�s deux jours de dur labeur vous rentrez chez ',
            'vous, seulement la station est d�serte... Enfin ',
            'sauf si on compte les nombreux corps fig�s ',
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
        'celui-ci ressemble � tous les autres � ',
        'l''exception de champignons fluorescents.', '',
        'En avan�ant, vous tombez sur un cadavre en ',
        'd�composition avanc�e.', '', '', '', '', '', '', '');
      texte_choix_2_histoire('1. Le fouiller', '2. Continuer');
      readln(selection);
      if selection = 1 then
      begin
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
        texte('Vous trouvez 2 m�dipack', '', '', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
      end;
      texte('Bourbon vous raconte une l�gende � propose de ce ',
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
      texte('Vous croisez un R�deur, ce dernier fuit en vous ', 'voyant.', '',
        '"Y''a rien � craindre, seul comme �a il nous ',
        'attaquera pas, mais fais gaffe si tu te balade ', 'seul"', '',
        'Quelques m�tres plus loin une seconde voie ',
        's''offre � vous, Bourbon semble occup�.', '',
        'Suivre la seconde voie ?', '', '');
      texte_choix_2_histoire('1. Oui', '2. Attendre Bourbon');
      readln(selection);
      if selection = 1 then
      begin
        texte('Cette voie est pleine de trous, au sol et au ', 'plafond. ', '',
          'Une sorte de lumi�re fluorescente l''illumine,  ',
          'probablement � cause des champignons.', '',
          'Peu rassur�e, vous avancez prudemment, vous ',
          'voyer un peu plus loin deux cadavres dont un ',
          'derri�re une grande grille.', '', '', '', '');
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
          'engouffrez dans un tunnel annexe dont l''entr�e ',
          'ce trouve derri�re le campement.', '', '', '', '', '', '', '', '',
          '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
      texte('Le tunnels est long, tr�s long, apparement ',
        'personne ne semble y �tre pass� depuis un bon ', 'moment.', '',
        'Plus vous avancez, plus une odeur naus�abonde ',
        's''installe autour de vous.', '',
        'La travers�e s''effectue dans un silence total, ',
        'Bourbon ne semble pas �tre du genre � tenir de ',
        'longue discussion, ce qui vous arrange, apr�s tout',
        'vous ne le connaissez que depuis quelques heures.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Le temps semble de nouveau ralentir, Bourbon ',
        'semble chantonner, votre vision se trouble.', '',
        'Un hurlement ce fait entendre dans le tunnel... ', 'Des Nosalis�!',
        '', 'Bourbon a arr�t� de chantonner.', '',
        '"Faut qu''on se barre rapidement, ',
        'mais fais gaffe, y''a s�rement�',
        'des pi�ges, saloperie de bandits."'
          , '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('Le temps semble de nouveau ralentir, Bourbon ',
        'semble chantonner, votre vision se trouble.', '',
        'Un hurlement ce fait entendre dans le tunnel... ', 'Des Nosalis�!',
        '', 'Bourbon a arr�t� de chantonner.', '',
        '"Faut qu''on se barre rapidement, ',
        'mais fais gaffe, y''a s�rement�',
        'des pi�ges, saloperie de bandits."'
          , '', '');
      texte_choix_2_histoire('1. �couter Bourbon et courir comme jamais',
        '2. �couter Bourbon mais faire attention');
      readln(selection);
      if selection = 1 then
      begin
        texte('En ayant fonc� comme un bourrin dans le tunnel, ',
          'vous avez d�clench� des pi�ges qui vous ont retir�',
          'des points de sant�.', '', '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        modif_PV_perso(get_pv_perso - 35, 0);
        combat(1, 0);
        rewrite(save);
        sauvegarde;
      end
      Else if selection = 2 then
      begin
        texte('En ayant fait attention, sous avez �vit� tous ',
          'les pi�ges, bien visibles, du tunnel.', '', '', '', '', '', '', '',
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
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Le sol craque sous vos pieds, vous tombez ',
        'dans une pi�ce remplie de gaz, de ', 'champignons et de cadavres.',
        '', 'Bourbon va directement dans le fond de la ',
        'pi�ce o� il essaie d''ouvrir une grille ',
        'en tournant une manivelle.', '', '', '',
        '', '', '');
      texte_choix_2_histoire('1. Fouiller les cadavres', '2. Aider Bourbon');
      readln(selection);
      if selection = 1 then
      begin
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 1);
        texte('Vous trouvez 1 m�dipack encore en bon �tat', '', '', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
        texte_nom_nom_2('Vous vous sentez mal, Bourbon semble avoir du ',
          'mal � ouvrir la grille.', 'Une voix vous appel au loin.', '',
          '... ', ' ...', '', 'Vous reprenez vos esprits, Bourbon semble ',
          'aller mal, il essaie de s�duire la grille,',
          'malgr� votre �tat, vous sentez une pr�sence ',
          'sombre, inqui�tante, peut �tre hostile, en ',
          'rassemblant vos derni�res forces, vous �cartez un ',
          'Bourbon totalement � l''ouest de sa grille bien ',
          'aim�e et parvenez � l''ouvrir.', get_nom_perso);
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

        texte('Vous vous engouffrez dans le passage en le ',
          'tra�nant avant que celle-ci ne se referme.', '',
          'Bourbon reprend ses esprits, quant � vous, ', '',
          'vous retrouvez toutes vos forces, Bourbon vous ',
          'remercie � sa mani�re.', '',
          'Par miracle, vous �tes proche d�une station ',
          'que Bourbon conna�t bien, seulement en approchant ',
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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

procedure march�s;
begin
  condition := 0;
  selection := 0;
  selection_1 := 0;
  modif_victoire(3);
  chapitre_suivant := 0;
  while (game_over = 0) and (chapitre_suivant = 0) do
  begin
    modif_chapitre('March�s');
    modif_checkpoint(9);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous �tes accueilli par le garde en chef � qui',
        'Bourbon semble devoir de l''argent, celui-ci ',
        'vous laisse avec les gardes pendant qu''il ',
        'marchande un droit de passage dans la station.', '',
        'Au bout de quelques (longues) minutes, Bourbon',
        'revient vous chercher et vous fait entrer dans le ', 'march�.', '',
        'Ayant une autre affaire � r�gler, Bourbon vous ',
        'laisse quartier libre pour visiter la station.', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Celle-ci est tr�s diff�rente de la v�tre, bien',
        'plus anim�e mais �galement tr�s sale, les murs',
        'sont couverts de suie, le sol est r�pugnant... ', '',
        'Mais cela ne vous emp�che pasde partir en ', 'exploration !', '', '',
        '', '', '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;

    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      while (selection <> 3) or (selection_1 <> 1) do
      begin
        texte('Celle-ci est tr�s diff�rente de la v�tre, bien',
          'plus anim�e mais �galement tr�s sale, les murs',
          'sont couverts de suie, le sol est r�pugnant... ', '',
          'Mais cela ne vous emp�che pasde partir en ', 'exploration !', '',
          '', '', '', '', '', '');
        texte_choix_3_histoire('1. Regarder les �tals', '2. Aller au bar',
          '3. Rejoindre Bourbon');
        readln(selection);
        if selection = 1 then
        begin
          texte('Le march� regorge de choses � acheter, cela va de ',
            'la nourriture aux pi�ces d�tach�es de rame de ',
            'm�tro sans oublier les v�tements, les armes et ',
            'diff�rentes substances aux effets �tranges.', '', '', '', '', '',
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
          texte('"Je vous sers quelques chose � boire ?"', '', '', '', '', '',
            '', '', '', '', '', '', '');
          texte_choix_2_histoire('1. Prendre une bi�re', '');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('Vous d�cidez de prendre une bi�re', '', '', '', '', '', '',
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
            'devant l''imposante porte ouvrant sur l''ext�rieur ',
            'de la station.', '',
            'Alors qu''un des gars ouvre la porte, un second ',
            'demande de l''argent � Bourbon, celui-ci refuse ',
            'en expliquant avoir pay� le chef.', '',
            'Enfin bref, la porte est ouverte, Bourbon ',
            'se tourne vers vous et', '', 'Es-tu pr�t�?', '');
          texte_choix_2_histoire('1. Oui', '2. Non');
          readln(selection_1);
          if selection_1 = 1 then
          begin
            texte('La porte est maintenant ouverte, pour la ',
              'premi�re fois depuis longtemps, vous allez voir ',
              'la surface�!', '', '', '', '', '', '', '', '', '',
              '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection_1 = 2 then
          begin
            texte('Vous repartez vers le march�.', '', '', '', '', '', '', '',
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
      texte('L''entr�e de la station est immense, le b�timent ',
        'est dans un �tat pitoyable mais vous n�avez aucun ',
        'mal � imaginer sa grandeur d�antan.', '',
        '"�Bienvenue chez toi mon gars�"', '',
        'Bourbon vous explique que des personnes font des ',
        'excursions � la surface et parfois y restent, mais',
        'souvent elles finissent "d�gomm�es" par les ',
        '"bestioles" qui nous remplacent � la surface. ', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('Il en profite pour vous rappeler de n''enlever',
        'votre masque � gaz sous aucun pr�texte, l''air ',
        '�tant pollu�, vous ne tiendriez pas longtemps ', 'sans.', '',
        'En avan�ant vous voyez deux corps vers ',
        'les grandes portes en bois de la station.', '', 'Les fouiller�?', '',
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
          'Bourbon re�oit 50 Balles.', '', '', '', '', '', '', '', '', '', '',
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
      texte('Apr�s avoir fouill� le b�timent et �vit� quelques ',
        'pi�ges vous sortez de la station.', '',
        'Moscou, enfin ce qu''il en reste, s�offre ',
        'maintenant � vous, le ciel est gris, les ',
        'b�timents noircis, il fait froid, la neige est ',
        'm�me la, hormis le fait qu''elle est vide et en',
        'piteuse �tat, la description des livres de ',
        'g�ographie est bien d�actualit�!', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;

      texte('En faisant quelques pas, vous entendez un cri, ',
        'Bourbon vous traine derri�re une colonne devant',
        'l''entr�e de la station et vous demande "de la fermer".', '',
        'Une cr�ature volante immense passe pr�s des colonnes', '',
        'Bourbon vous explique que ces cr�atures sont appel�es ',
        '"D�mons" mais que lui les appelle "Saloperie".', '',
        'Une fois la "Saloperie" pass�e, vous vous dirigez ',
        'vers la gauche, et essayez de sauter d''une voiture ',
        'dans la crevasse, vous remontez avec du mal mais ',
        'maintenant plus moyens de le rejoindre par ce c�t�.');
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
        ', vous commencez directement � suivre l''itin�raire ', '',
        'd�crite par Bourbon.Vous devez passer par un grand b�timent,', '',
        'Vous devez passer par un grand b�timent',
        'dans l''entr�e, un corps git entour� de ', 'traces de sang.', '', '',
        '', '');
      texte_choix_2_histoire('1. Le fouiller', '2. Continuer');
      readln(selection);
      if selection = 1 then
      begin
        modif_argent_perso(get_argent_perso + 30);
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
        texte('Vous fouillez le corps sans regret, ', 'esp�ce de monstre !',
          '', 'Non je plaisante j''aurais fait pareil.', '',
          'Du coup vous trouvez 2 m�dipack et 30 balles', '', '', '', '', '',
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
      texte('Vous devez passer par l''�tage pour en sortir.', '',
        'En avan�ant vers la cage d''escalier vous tombez sur ',
        'une de ces "bestioles" dont Bourbon vous a parl�.', '', '', '', '',
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
        texte('Une fois la cr�ature morte, vous sortez du b�timent, ',
          'vous �tes entour� d''immeubles, pas tr�s grands ',
          'mais suffisamment pour vous sentir un peu mal � l''aise.', '',
          'En avan�ant vous arrivez pr�s d''un jardin d''enfants,',
          'celui-ci est �trangement pr�serv� bien qu''un peu sale,',
          'en marchant dans ce qui devait �tre de l''herbe, vous ',
          'entendez des rires d�enfants.', '',
          'Sur le qui-vive, vous tournez la t�te dans toutes les ',
          'directions, ne voyant aucun enfant vous vous dites ',
          'que vous avez d� les imaginer.', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Enfin bref, il faut se d�p�cher !', '',
          'Un d�mon vous bloque le chemin,',
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
            'vous avez peut-�tre rat� une bonne occasion ',
            'de tuer un D�mon mais au moins vous �tes en vie.', '', '', '', '',
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
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
      begin
        texte('Vous passez par-dessus une grande grille, Bourbon',
          'est un peu plus loin, occup� � fouiller un cadavre.', '',
          '"Ah enfin, t''as pris ton temps, enfin peu importe,',
          'on peut y aller."', '',
          'Vous suivez Bourbon en silence, les lieux ne',
          'sont pas s�curis�s et il semble qu''on vous �pie�', '',
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
            'ayant compris vous n''arriverez jamais � rester en vie ',
            '� ce rythme, Bourbon cours vers une bouche ',
            'd�a�ration du m�tro.', '',
            'Il vous demande de l''aide, il veut que vous lui ',
            'fassiez la courte �chelle pendant que les Nosalis ',
            'sont occup�s par un nouveau venu, un d�mon.', '', '', '', '', '');
          texte_choix_2_histoire('1. Aider Bourbon', '2. Ne pas aider Bourbon');
          readln(selection);
          if selection = 1 then
          begin
            texte('Vous voici en s�curit�, du moins pour le moment.', '', '',
              '', '', '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection = 2 then
          begin
            texte('Au moment de faire la courte �chelle � Bourbon, vous ',
              'd�cidez qu''il n''est pas digne de confiance, ',
              'qu''il ne vous aidera pas � monter � votre tour.', '',
              'Cette erreur de jugement vous conduit � votre perte, ',
              'vous et Bourbon finissez dans l''estomac de gentils b�b�s D�mons.'
                , '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        'Il d�cide de sortir du conduit mais vous demande ',
        'de rester au cas o�.', '',
        'Il reviendra vous chercher si tout est bon.',
        'Il vous confie son sac en gage de confiance.', '',
        'En sortant il se fait intercepter par des gardes, ',
        'ces derniers surpris lui expliquent que la ',
        'station a chang� de chef et lui rappels qu''il a ',
        'quelques comptes � r�gler avec le nouveau patron.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Comprenant que rien ne se passe comme pr�vu, ',
        'vous laissez les gardes emmener Bourbon et vous ',
        '�loignez de la sortie du conduit.', '', '', '', '', '', '', '', '',
        '', '');
      while selection <> 1 do
      begin
        texte_choix_3_histoire('1. Sortir du conduit',
          '2.Fouiller le sac de Bourbon', 'Attendre');
        readln(selection);
        if selection = 1 then
        begin
          texte('Vous semblez n''avoir �veill� aucun soup�on ',
            'pour le moment, vous avancez discr�tement ',
            'vers les lieux de d�tention de Bourbon', '', '', '', '', '', '',
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
            texte('Vous d�cidez de prendre du mat�riel dans ',
              'le sac de Bourbon, il ne vous en voudra ',
              'surement pas si vous parvenez � le lib�rer.', '',
              'Vous trouvez 5 m�dipack et du th�', '', '', '', '', '', '', '',
              '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            condition := 1;
          end
          Else
          begin
            texte('Vous avez d�j� fouill� le sac', '', '', '', '', '', '', '',
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
      texte('Un garde sonne l''alerte, malgr� toutes ',
        'les pr�cautions prises il vous a vu, ',
        'vous le tuez d''une balle dans la t�te',
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
        texte('Vous parvenez � attirer l�attention des autres ',
          'gardes dans la mauvaise direction en tirant sur une ',
          'lanterne ce qui vous permet de vous faufiler ',
          'jusqu''au lieu de captivit� de Bourbon.', '',
          'En entrant dans la pi�ce, vous surprenez le chef ',
          'de la station, arme braqu�e sur Bourbon ce qui ',
          'lui laisse le temps de saisir une arme.', '',
          'En plein �lan Bourbon tire sur le chef qui lui tire �galement dessus.'
            , '', 'Les deux sont morts.',
          'Les gardes sont � la porte, pr�t � la d�foncer et vous tuer.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('C''est � ce moment que la porte au fond de la pi�ce s''ouvre, ',
          'un homme plus �g�, peut-�tre la cinquantaine, ',
          'se tient � la place de la porte.', '',
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
          texte('Sois vous �tes idiot, sois suicidaire...', 'Ou les deux...',
            '', 'En tout cas vous voil� pendu les tripes � l�air.', '',
            'Bravo !', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
      texte('Vous suivez cet homme dans un couloir plong� dans ',
        'le noir, uniquement �clair� par sa lampe.', '',
        'Il se pr�sente, son nom est Khan, il vous explique ',
        '�tre en chemin pour la "Station Maudite" qui subit ',
        'depuis quelques temps des attaques r�p�t�s de Nosalis ',
        'et de R�deurs.', '',
        'Il vous promet qu''en partant de cette station, vous pourriez ',
        'suivre un itin�raire vers Polis, votre destination finale.', '', '',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Le couloir se termine sur un nouveau tunnel, ',
        'ce dernier semble totalement vide et en tr�s mauvais ',
        '�tat, surement non parcouru depuis un long moment.', '',
        'En avan�ant, vous voyez des ombres, des ombres sans que qui ',
        'que ce soit ne soit pr�sent.', '',
        'Khan vous explique d''un air triste que ce sont sont les ',
        'ombres des morts revivant sans cesse leurs derniers instants.', '',
        '', '', '');
      texte_choix_2_histoire('1. Les laisser tranquilles', '2. En toucher une');
      readln(selection);
      if selection = 1 then
      begin
        texte('Khan vous explique qu''il ne faut sous aucun pr�texte ',
          'en toucher une, elles auraient un effet ', 'l�tal sur les vivants.',
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
          'Vous voil� mort vous aussi.', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 2) then
    begin
      texte('En continuant votre travers�e du tunnel, un ',
        'grand bruit retentit, comme une rame qui ',
        'serait en marche, Khan vous regarde et vous colle ',
        'contre une paroi du tunnel.', '',
        'A peine avait-il fait �a qu''une ombre immense ',
        'repr�sentant une rame passe � toute vitesse ',
        'pr�s de vous, les passagers crient, pleurent, ',
        'un enfant semble chercher sa m�re...', '',
        'Sans Khan vous seriez mort, vous le remercier ',
        'et voulez lui donner quelques balles mais ', 'ce dernier refuse.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Continuant, vous vous retrouvez entour�s d''ombres ',
        'bloquant le passage, Khan, le regard plein de ',
        'compassion, vous explique que ce sont les ombres ',
        'ombres d''anciens soldats ayant donn� leurs vies ',
        'pour prot�ger la station.', '',
        'Murmurant quelque chose d''incompr�hensible, ',
        'il parvint � d�gager le passage, les ombres ',
        'se retournent et disparaissent.', '',
        'Quelques m�tres plus loin, Khan vous fait passez ',
        'par une porte donnant sur un couloir, dans ce dernier vous',
        'trouvez plusieurs cadavres.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Khan se met � acc�l�rer et vous le suivez ', 'tant bien que mal.',
        '', 'Vous sortez de l''ensemble de couloir ressemblant',
        'au final � un petit labyrinthe et ', 'arrivez dans un nouveau tunnel',
        '', 'En suivant les rails, vous constatez ',
        'que de l''�lectricit� statique les parcourts.', '',
        'Khan s''en �loigne le plus possible;', '', '');
      texte_choix_2_histoire('1. Rester en plein milieu',
        '2. S''�loigner aussi');
      readln(selection);
      if selection = 1 then
      begin
        texte('Une �norme boule apparemment faite d''�lectricit� apparait,',
          'elle s''avance vers vous.', '', '', '', '', '', '', '', '', '', '',
          '');
        texte_choix_2_histoire('1. Tirer sur cette chose',
          '2. S''�loigner des rails');
        readln(selection_1);
        if selection_1 = 1 then
        begin
          texte('Vous �tes mort �lectrocut�.', '', '', '', '', '', '', '', '',
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
        '�tranget� est nomm�e "Anomalie" et qu''on ne peut pas ',
        'gagner contre elle.', '',
        'Plus loin le tunnel est bouch�, vous changez de tunnel ',
        '� une bifurcation, cependant, des Nosalis arrivent .', '', '', '', '',
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
          'l''approche d''une nouvelle anomalie', 'pour s''en d�barrasser.',
          '', 'En effet, vous entendez au loin des Nosalis ',
          'hurler, peu de temps apr�s, une nouvelle anomalie ',
          'apparait, vous la laissez passer ',
          'tranquillement et reprenez votre chemin.', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;

      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
      texte('La station est totalement ravag�e, partout des cadavres ',
        'd''humains et de Nosalis, vous suivez Khan vers un groupe ',
        'lourdement arm�s.', '',
        'Ces derniers semblent soulag�s de voir Khan arriver, ',
        'ce dernier leur demande l''�tat de la situation.', '',
        'Sans grande surprise, ils sont � bout et ',
        'n''ont presque plus de munitions.', '', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Ils expliquent � Khan avoir envoy� deux artificiers ',
        'pour faire sauter les passages utilis�s par les Nosalis ',
        'et des R�deurs afin de les emp�cher d''entrer de nouveau ',
        'dans la station mais qu''ils sont surement morts ',
        'avant d''avoir r�ussi.', '',
        'Khan se tourne vers vous et vous demande de finir ',
        'le travail, lui doit rester avec les gardes pour prot�ger ',
        'la population derri�re le barrage.', '', '', '', '');
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
        'un vers l''h�pital et l''autre en suivant les rails.', '',
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
        texte_choix_2_histoire('1. Aller � l''h�pital', '2. Suivre les rails');
        readln(selection);
        if selection = 1 then
        begin
          modif_sous_checkpoint(4);
          rewrite(save);
          sauvegarde;
          if (nouvelle_partie = 1) or (get_sous_checkpoint = 4) then
          begin
            texte('Vous vous dirigez vers l''h�pital, sur le chemin vous ',
              'croisez des morts, du sang, des bestioles mortes le tout ',
              'dans un environnement totalement saccag�.', '', '', '', '', '',
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
                  texte('Vous vous rendez compte une fois l''endroit nettoy� ',
                    'que le seul moyen pour bloquer le passage et de faire ',
                    'sauter les colonnes.', '',
                    'Vous y placez donc les charges et courrez-vous',
                    'mettre � l''abri', '',
                    'Vous entendez une forte d�tonation preuve que vos ',
                    'explosifs ont bien fonctionn�.', '', '', '', '');
                  texte_choix_2_histoire('Appuyer sur entrer', '');
                  readln;
                  condition := 1;
                end;
              end
              Else if (get_victoire = 0) then
              begin
                texte('Vous avez �chou�... Vous �tes faible... ',
                  'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '',
                  '', '', '', '', '', '', '', '', '');
                texte_choix_2_histoire('Appuyer sur entrer', '');
                readln;
                game_over := 1;
              end;
            end
            Else if (get_victoire = 0) then
            begin
              texte('Vous avez �chou�... Vous �tes faible... ',
                'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '',
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
                  'et vous mettez � les suivre.', '',
                  'Ils sont jonch�s de douilles, de sang ',
                  'et les murs pr�sentent des impacts', '', '', '', '', '', '',
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
                    texte('Il semble que les habitants ont essay� ',
                      'bloquer le passage en cr�ant des barri�res.', '',
                      'Ces derni�res n''ont semble-t-il pas ',
                      'surv�cu au passage des Nosalis.', '',
                      'En arrivant au bout, vous placez ',
                      'les charges et partez-vous mettre � l''abri.', '',
                      'Vous entendez une forte d�tonation preuve ',
                      'que vos explosifs ont bien fonctionn�.', '', '');
                    texte_choix_2_histoire('Appuyer sur entrer', '');
                    readln;
                    condition_2 := 1;
                  end;
                end
                Else if (get_victoire = 0) then
                begin
                  texte('Vous avez �chou�... Vous �tes faible... ',
                    'Vous �tes nul... Mais je vous propose ', 'de rejouer�!',
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
        'pr�sentes,ce dernier leur parle et elles partent lentement.', '',
        'Le passage est maintenant d�gag�, Khan vous explique devoir ',
        'rester ici pour les aider mais vous conseille ',
        'de chercher un certain forgeron nomm� Andre�',
        '� la prochaine station.', '',
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
    modif_chapitre('Station ind�pendante');
    modif_checkpoint(15);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous n''avez �trangement rencontr� aucun ',
        'probl�me durant la travers� du tunnel',
        'Vous voici maintenant � l''entr�e de la station Ind�pendante.',
        'la Station Ind�pendante.', '',
        'En entrant, un homme vous met en garde, cette station',
        'n''a d''ind�pendante que le nom, les Rouges, enfin les ',
        'communistes, ont la main mise sur cette station et ',
        'font souvent des contr�les d''identit�, ceux n''�tant ',
        'pas identifi�s sont emmen�s et ne r�apparaissent jamais.', '', '', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Continuant votre progression dans la station, ',
        'vous tombez sur un homme se faisant contr�ler, ce ',
        'dernier provoque l''homme le fouillant en faisant ',
        'allusion au fait que ce dernier aime tripoter les hommes.', '',
        'En vous voyant le Rouge vous demande "poliment" ',
        'si vous �tes un ami de ce comique mais vous n''avez ',
        'pas le temps de r�pondre.', '',
        'Le "comique" s''est empar� d''une barre de fer et ',
        'frappe le soldat au niveau du visage.',
        'Ce dernier tombe mais un autre apparait � ce moment ',
        'mena�ant de vous tuer avec son arme.');
      texte_choix_2_histoire('1. R�pliquer', '2. Courir');
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
          '� ne subir aucun d�g�t mais au d�tour d�une passerelle, ',
          'l''homme devant vous se fait assommer.', '',
          'Vous parvenez � esquiver mais le sol se d�robe sous',
          'vos pieds et vous perdez connaissance.', '',
          'Vous vous r�veillez douloureusement, un homme vous',
          'demande de ne pas faire trop de bruit.', '',
          'Il vous apprend que vous �tes recherch�.');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Il se pr�sente, il s''appelle Andre� et est forgeron.',
          'Heureux d��tre tomb� sur lui, vous lui expliquez la situation.', '',
          'Ce dernier apr�s vous avoir �cout� vous explique ',
          'qu''une caravane part pour le front t�t ',
          'demain et qu''il va falloir en profiter pour vous faufiler ',
          'au travers des champs de bataille pour continuer votre route.', '',
          'En attendant que tout soit pr�t, vous  partez dans la station, ',
          'd�guis� afin qu''on ne puisse vous reconnaitre.', '',
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
        texte('Andre� vous rejoint, il vous demande si ',
          'vous souhaitez changer d''�quipement et vous ',
          'en propose deux autres.', '', '', '', '', '', '', '', '', '', '');
        while (selection <> 3) and (condition = 0) do
        begin
          texte_choix_3_histoire('1. Soldat', '2. Espion', '3. Non merci');
          readln(selection);
          if selection = 1 then
          begin
            texte('En choisissant l''�quipement Soldat vous choisissez ',
              'd''augmenter votre r�sistance et votre dur�e de vie.', '',
              'Choisir cet �quipement ?', '', '', '', '', '', '', '', '', '');
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
            texte('Cette tenue l�g�re vous permettras de vous d�placer plus ',
              'silencieusement et d''�viter ainsi de vous faire rep�rer.', '',
              'Choisir cet �quipement ?', '', '', '', '', '', '', '', '', '');
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
            texte('Vous choisissez de garder votre �quipement.', '', '', '',
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
      texte('Maintenant pr�t � partir, Andre� est ',
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
        texte('Vous remerciez Andre� et l''homme pour leur aide.', '', '', '',
          '', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if selection = 2 then
      begin
        texte('Vous faites comprendre � Andre� et ',
          'son coll�gue que non, vous n''allez pas risquer ',
          'votre vie sous une draisine et vous partez',
          'sur les champs de bataille par le tunnel en',
          'profitant de l''inattention d''un garde.', '',
          'Proche des champs de bataille, vous vous faites ',
          'percuter par une draisine lanc�e � toute vitesse ',
          'ce qui vous coute la vie.', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Vous passez sous la draisine ou est install� une ',
          'cachette de fortune qui ne parait pas vraiment solide.', '',
          'Quelques minutes apr�s sa mise en place, plusieurs ',
          'jeunes recrues s''installent et commence � parler ',
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
      texte('Vous voil� presque arriv�, l''endroit est bruyant et ',
        'surtout plein de Rouges pr�s � vous', 'tuer au moindre faux pas.', '',
        'Cependant, le plancher de la cachette se brise ',
        'vous laissant sur les rails, par chance, personne',
        'personne ne l''a remarqu� et vous �tes entier,',
        '�a tient presque du miracle !', '',
        'Reprenant votre esprit vous partez en ',
        'direction des champs de bataille.',
        'Vous constatez que la bataille se trouve sur l''autre ',
        'voie de m�tro, il vous faut donc la rejoindre.');
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
            texte('Vous avez �chou�... Vous �tes faible... ',
              'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 6) then
    begin
      texte('Vous assistez de loin � l''ex�cution ',
        'd''un soldat pour d�sertion tandis que ce dernier ',
        'tente d''expliquer qu''il n''a pas d�sert�',
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
          texte('En passant du cot� ennemi vous tombez sur deux Faschos.', '',
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
            texte('Vous avez �chou�... Vous �tes faible... ',
              'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        texte('Profitant de l''information laiss�e par ',
          'l''ex�cut�, vous passez par un petit couloir de',
          'service difficilement accessible.', '',
          'En suivant ce couloir vous d�bouchez dans une ',
          'salle de service cot� Reich.', '', '', '', '', '', '', '');
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
          texte('Quelques hommes sont post�s pour garder le camp, ',
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
          texte('La majorit� des hommes �tant partis au front, ',
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
          texte('Quelques hommes sont post�s pour garder le camp, ',
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
            texte('Vous avez �chou�... Vous �tes faible... ',
              'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
      texte('Ayant pass� leur camp, vous avancez vers une porte.', '',
        'Alors que vous alliez tourner la poign�e, celle-ci ',
        's''ouvre violemment vous projetant en arri�re.', '',
        'Deux Fachos entrent alors dans la pi�ce et vous traine ',
        'derri�re la porte.', '', '', '', '', '', '');
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
    modif_chapitre('Une aide inesp�r�');
    modif_checkpoint(17);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous voil� par terre face � des Faschos cherchant visiblement �',
        'vous faire supplier pour qu''ils vous �pargnent.', '',
        'Cependant le plus vieux du groupe semble vouloir en finir ',
        'au plus vite, il sort son arme et la pointe sur votre t�te.', '',
        'Lorsqu''il commence � presser la d�tente, un groupe d''homme entre ',
        'par l''arri�re et prend par surprise les Faschos',
        'les mettant ais�ment � terre.', '',
        'En les voyants faire, vous comprenez que ce sont des Rangers...',
        'Des Rangers de Polis !',
        'Un des hommes vous tend la main pour vous aider � vous relever.');
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
        'ici �tant donn� que vous n''�tes ni', 'un Rouge, ni un Fascho.', '',
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
          'que vous �tes bien envoy� par Hunter.', '', '', '', '', '', '', '',
          '', '', '');
        texte_choix_2_histoire('1. Montrer la plaque',
          '2. Ne pas montrer la plaque');
        readln(selection_1);
        if selection_1 = 1 then
        begin
          texte('Apres avoir bien observ� ',
            'la plaque, ils comprennent que vous �tes',
            'bel et bien envoy� par Hunter.', '', '', '', '', '', '', '', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          modif_sous_checkpoint(3);
          rewrite(save);
          sauvegarde;
        end
        Else if selection_1 = 2 then
        begin
          texte('N''ayant pas de preuve, les Rangers d�cident de partir ',
            'sans vous mais en vous ayant lib�r�.', '',
            'Quelques m�tres plus loin, vous vous faites arr�ter ',
            'par des Faschos qui d�cident de vous faire subir',
            'un proc�s sans une quelconque chance de gagner votre libert�.',
            '', 'Vous finissez dos au mur perfor� de plusieurs balles.', '',
            '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end
      Else if selection = 2 then
      begin
        texte('N''ayant pas de justification de votre part, ',
          'les Rangers d�cident de partir sans vous mais ',
          'en vous ayant lib�r�.', '',
          'Quelques m�tres plus loin, vous vous faites arr�ter ',
          'par des Faschos qui d�cident de vous faire subir un proc�s',
          'sans une quelconque chance de gagner votre libert�.', '',
          'Vous finissez dos au mur perfor� de plusieurs balles.', '', '', '',
          '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 3) then
    begin
      texte('Ils d�cident de vous escorter jusque Polis ',
        'afin d''�tre s�r que vous puissiez bien transmettre ',
        'les suppos�es derni�res volont�s d''Hunter au Conseil.', '',
        'Ces derniers vous conduisent jusqu''une draisine arm�e ',
        'prise aux Faschos.', '',
        'Le groupe se s�pare, vous restez avec celui qui s''appelle Boris, ',
        'tandis que les autres passent par un autre ',
        'chemin, ils vous attendront au niveau de la Station Noire.', '',
        'Boris vous demande de vous installer au niveau de la tourelle.', '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Une fois install�, la draisine d�marre.', '',
        'En route pour la station noire, vous arrivez',
        '� un poste de contr�le Fascho.', '',
        'Boris tente tant bien que mal de se faire passer pour un soldat ',
        'mais sa couverture et rapidement grill�e, sous une pluie de balle, ',
        'la draisine repart � toute vitesse, traversant des cl�tures de fortune.'
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
        texte('Croyant �tre sortis d�affaire, vous ',
          '�tes attaqu�s par un Panzer. ', '',
          'Boris vous ordonne de viser les piliers, maintenant ',
          'le chemin de fer sur lequel repose le Panzer.', '',
          'En les d�truisant, vous faites tomber le Panzer dans le vide.', '',
          'Vous reprenez votre chemin, vous avez �chapp� de peu � ',
          'la mort mais vous �tes content de vous en �tre sorti.',
          'Votre draisine vous l�che, il vous en faut une nouvelle par ',
          'chance une autre se trouve � proximit�, ',
          'seulement elle est non arm�e.');
        texte_choix_2_histoire('1. Changer de draisine', '2. Garder la votre');
        readln(selection);
        if selection = 1 then
        begin
          texte(
            'Une fois dedans, Boris actionne le m�canisme, la draisine avance, '
              , 'cependant lors d''une descente, elle part ',
            'dans la mauvaise direction...', '', '', '', '', '', '', '', '',
            '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if selection = 2 then
        begin
          texte('Votre draisine vous l�che ',
            'compl�tement quelques m�tres plus loin.', '',
            'Etant hors de question de continuer ',
            '� pied, vous revenez sur vos pas.', '', '', '', '', '', '', '',
            '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(2, 1);
          if get_victoire = 1 then
          begin
            rewrite(save);
            sauvegarde;
            texte('Une fois dedans, Boris actionne le m�canisme, ',
              'la draisine avance, cependant lors d�une ',
              'descente, elle part dans la mauvaise direction...', '', '', '',
              '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez �chou�... Vous �tes faible... ',
              'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
        end;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
    modif_chapitre('Le d�pot');
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
        'Boris reconnait l''endroit et parait �merveill�, ',
        'il s''agit selon lui du d�p�t, l� o� vont les rames ',
        'qui ne sont pas en fonction.', '',
        'Cependant l''�merveillement est de courte dur�e, ',
        'vous entendez des bruits dans les rames, ',
        'et quelque chose vous observe.', '',
        'Boris acc�l�re le rythme mais trop tard, ',
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
        texte('Faisant de votre mieux pour prot�ger Boris, ',
          'celui-ci finit par ce faire attraper par ',
          'un Nosalis qui l''entraine dans les profondeurs du d�p�t.', '',
          'Comprenant que vous ne pouvez pas le sauver, ',
          'vous continuez votre chemin sans vous retourner.', '',
          'La draisine va vite, tr�s vite, trop vite...', '',
          'Vous percutez un obstacle sur la voie ce qui ',
          'vous �jecte de votre draisine.', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        texte('Vous vous relevez difficilement, ',
          'vous ne savez pas ou vous �tes ',
          'mais vous ne pouvez qu''aller tout droit ', 'devant vous.', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
    modif_chapitre('Station de la Br�che');
    modif_checkpoint(19);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('Vous tombez sur un barrage, des hommes sont � terre ',
        'baignant dans leur propre sang.', '',
        'En vous approchant des hommes, vous �tes mis en joue.', '',
        'Vous apprenez que la station est en cours d''�vacuation, ',
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
        texte('Vous vous mettez en position, pr�t � en d�coudre.', '',
          'C''est alors qu''une �norme rafale traverse le ',
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
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        texte('Une �norme rafale traverse le ', 'tunnel vous faisant tomber.',
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
      texte('Les Nosalis ont arr�t� d''attaquer, une rafale arrive,',
        'cette fois vous vous mettez bien � l''abri.', '', '', '', '', '', '',
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
        texte('Ayant les nerfs � fleur de peau, les rescap�s ',
          'vous attaquent suite � votre refus.', '', '', '', '', '', '', '',
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
        texte('Une fois tous morts, plus ', 'rien ne vous emp�che de passer.',
          '', 'Mais un dernier miliciens arrive ',
          'et vous poignarde dans le dos.', '', '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end
      Else if (get_victoire = 0) then
      begin
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        'que celle-ci est dans le m�me �tat que la Station Maudite,',
        'cependant celle-ci est infest�e de R�deurs.', '', '', '', '', '', '',
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
          texte('Apres avoir travers� la station, vous ',
            'trouvez un enfant assis � c�t� d''un corps', 'ensanglant�.', '',
            'En vous approchant, ce dernier vous demande ', 'qui vous �tes.',
            '', 'Vous lui dites que vous venez de VDNKh et que ',
            'vous vous rendez � Polis.', '',
            'Le gar�on vous demande si vous pouvez le ',
            'prendre avec vous vous jusque la prochaine ',
            'station ou se trouve trouve sa m�re.');
          texte_choix_2_histoire('1. Prot�ger le gar�on',
            '2. Le laisser � son sort');
          readln(selection);
          if selection = 1 then
          begin
            condition := 1;
            texte('Vous le prenez sur vos �paules, ',
              'ce dernier dit s''appeler Sasha.', '', '', '', '', '', '', '',
              '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end
          Else if selection = 2 then
          begin
            texte('Vous d�cidez de laisser l''enfant � c�t� du cadavre.', '',
              'A croire que vous n''avez pas de coeur !', '', '', '', '', '',
              '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
          end;
          texte('Le tunnel que vous ',
            'empruntez est lui aussi infest� de R�deurs.', '', '', '', '', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          combat(3, 1);
          if get_victoire = 1 then
          begin
            if condition = 1 then
            begin
              texte('En arrivant dans une petite pi�ce remplie de casiers, ',
                'Sasha vous indique que celui de son oncle, ',
                'l''homme mort de tout � l''heure, contient ',
                'peut �tre quelque chose d''utile.', '', '', '', '', '', '',
                '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              modif_argent_perso(get_argent_perso + 40);
              modif_quantite_objet_1_perso(get_quantite_objet_1_perso + 2);
              readln;
              texte('Une voix r�sonne au loin, vous ',
                'acc�l�rez le pas et tombez sur ',
                'des soldats retenant une femme.', '',
                'Cette derni�re semble vouloir aller � la station ',
                'pr�c�dente chercher son fils.', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              texte('Sasha saute dans les bras de sa m�re, ',
                'celle-ci vous remercie d''avoir sauv� son ',
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
              texte('Une voix r�sonne au loin, vous ',
                'acc�l�rez le pas et tombez sur ',
                'des soldats retenant une femme.', '',
                'Cette derni�re semble vouloir aller � la station ',
                'pr�c�dente chercher son fils.', '', '', '', '', '', '', '');
              texte_choix_2_histoire('Appuyer sur entrer', '');
              readln;
              modif_sous_checkpoint(9);
              rewrite(save);
              sauvegarde;
            end;
          end
          Else if (get_victoire = 0) then
          begin
            texte('Vous avez �chou�... Vous �tes faible... ',
              'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
              '', '', '', '', '', '', '', '');
            texte_choix_2_histoire('Appuyer sur entrer', '');
            readln;
            game_over := 1;
          end;
        end;
        if (nouvelle_partie = 1) or (get_sous_checkpoint = 9) then
        begin
          texte('Un soldat vous demande la raison de votre pr�sence.', '',
            'Indiquant d''o� vous venez et ou vous allez il ',
            'vous indique par ou passer pour rejoindre Polis.', '',
            'Un trajet dangereux car passant par la surface.', '',
            'Avant de partir, il vous dit �galement que quelques ',
            'marchands sont bloqu�s ici et qu''ils seraient ',
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
        texte('Vous avez �chou�... Vous �tes faible... ',
          'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
          '', '', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
        game_over := 1;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
    modif_chapitre('Retour � la surface');
    modif_checkpoint(20);
    if (get_sous_checkpoint = 0) then
    begin
      modif_sous_checkpoint(1);
    end;
    rewrite(save);
    sauvegarde;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte('En sortant du m�tro, vous tombez malheureusement sur ',
        'un camp de Faschos, ces derniers semblent vouloir entrer ',
        'et prendre d''assaut les personnes vous ayant aid�.', '', '', '', '',
        '', '', '', '', '', '');
      modif_sous_checkpoint(2);
      rewrite(save);
      sauvegarde;
    end;
    if (nouvelle_partie = 1) or (get_sous_checkpoint = 1) then
    begin
      texte_choix_2_histoire('1. Les emp�cher de passer',
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
        'des rues d�sol�es de l''ancienne capitale Russe.', '',
        'Au d�tour d''une rue vous tombez de nouveau ', 'sur des Faschos.', '',
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
        texte('Vous arrivez finalement � ',
          'l''entr�e secondaire de la Station Noire.', '', '', '', '', '', '',
          '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
        'seulement il est derri�re une grille, ',
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
        texte('Vous parvenez � revenir dans l''ombre, ',
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
            'les priver de lumi�re afin de passer parmi eux',
            'sans vous faire remarquer.', '',
            'Vous partez donc vers l''�tage inf�rieur, ',
            'le g�n�rateur est l�, tout proche.',
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
          texte('Vous �teignez le g�n�rateur ',
            'plongeant la station dans le noir.', '',
            'Vous pouvez ainsi rejoindre Oulman sans trop vous ',
            'soucier des gardes totalement perdus ne ',
            'pouvant pas faire la diff�rence entre un des leurs et vous.', '',
            '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
        end
        Else if (get_victoire = 0) then
        begin
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
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
          texte('Vous avez �chou�... Vous �tes faible... ',
            'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '',
            '', '', '', '', '', '', '', '');
          texte_choix_2_histoire('Appuyer sur entrer', '');
          readln;
          game_over := 1;
        end;
      end;
      if (nouvelle_partie = 1) or (get_sous_checkpoint = 5) then
      begin
        texte('Vous rejoignez Oulman, celui-ci ',
          'vous attendait pr�s d�une draisine', 'motoris�e.', '',
          'Vous pouvez enfin vous reposer un peu.', '',
          'Bient�t... Vous donnerez le message d�Hunter, ',
          'votre station sera sauv�e... Bient�t...', '', '', '', '', '');
        texte_choix_2_histoire('Appuyer sur entrer', '');
        readln;
      end;
    end
    Else if (get_victoire = 0) then
    begin
      texte('Vous avez �chou�... Vous �tes faible... ',
        'Vous �tes nul... Mais je vous propose ', 'de rejouer�!', '', '', '',
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
      texte('Le voyage ne fut pas tr�s long, en approchant ',
        'de la station, un garde vous hurle ',
        'de vous identifier, c''est Oulman qui r�pond.', '',
        'La porte s''ouvre, vous entrez enfin ', 'dans Polis "la Magnifique".',
        'Son nom est bien trouv�e, la station est propre, ',
        'totalement �clair�e, un soin particulier ',
        'est donn�e � son entretien.', '',
        'La draisine s''arr�te devant une porte, ', 'Oulman entre avec vous.',
        '');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('La pi�ce contient un bureau, derri�re ce ',
        'trouve un homme d''une quarantaine d''ann�e, ',
        'un homme de terrain, �a se voit au premier coup', 'd''oeil !', '',
        'Il s''appelle Melnik apparemment', '',
        'Oulman parle � votre place, il explique la',
        'situation et vous demande de montrer la ', 'plaque d�Hunter.', '',
        'Sans plus attendre, Melnik utilise un micro et',
        'demande aux membres du Conseils de ce r�unir.');
      texte_choix_2_histoire('Appuyer sur entrer', '');
      readln;
      texte('Vous �tes devant l''immense porte en bois ',
        'de la chambre du conseil.', '', 'Elle commence � s''ouvrir et...', '',
        '', '', 'La suite un jour peut-�tre .', '', '', '', '', '');
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
