



        	**************** INFO204 : PROGRAMMATION ORIENTEE OBJET *****************



Prérequis 

pour pouvoir exécuter notre application il faudrait avoir installé le compilateur gcc!

        


		  ********* Vérification de l'installation : ********** 

    

Ouvrez une console et tapez la commande gcc --version . Si vous obtenez comme résultat "commande introuvable", alors vous devriez installer gcc . 

Dépendant de votre système d'exploitation, suivez les étapes suivantes :

 

Sur Windows :
     nous ne disposons pas de ce compilateur par défaut, il va alors falloir l'installer ! 

  Nous allons installer gcc grâce à l'IDE Code::Blocks qui est gratuit et livrée avec notre compilateur . Pour ce faire, nous irons à l'adresse http://www.codeblocks.org/downloads/binaries pour la télécharger et nous choisirons la version ayant MINGW (codeblocks-20.03mingw-32bit-setup.exe version la plus récente actuellement ) . Puis on nous l'installerons .





		********** Exécution de l'application ***********

     Les différents fichiers de l'application sont:

	-- Les fichiers du code source suivants: Candidat.cpp, Candidat.h, Matiere.cpp, Matiere.h, Evaluation.cpp, Evaluation.h et main.cpp
	-- Les fichiers de données suivants: Candidat.txt, Evaluation.txt, Matiere.txt, resultat.txt, admis.txt, attente.txt, tempo.txt et tempoAide.txt
	-- Le fichier readme.txt
	-- Le fichier makefile

	Pour executer l'application, tapez la commande 'make'
	
	  Apres l'avoir fait, une console s'affichera sur votre ecran avec un menu principal de l'application, dès lors vous pourrez alors naviguer dans l'application à votre guise. 
	 Dans l'option 2 du menu principal, il vous est proposé d'enregistrer les notes d'un candidat, pour le faire il faudra que les matieres de ces notes soient enregistrées à
	l'avance dans le fichier Matiere.txt, raison pour laquelle nous avons enregistré quelques matières à l'aide de l'option 3 (AJOUTER UNE MATIERE) et vous pourez en ajouter 
	si vous le souhaitez.
	Les fichiers de données tempo.txt et tempoAide.txt servent de fichier temporels dans la manipulation de mes fonctions.		
 





Édité le 12/06/2020 par :

	-BETNDAM TCHAMBA BLERIOT PAGNAUL 18T2491

