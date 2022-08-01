#include <iostream>
#include <sstream>
#include "Candidat.h"
#include "Evaluation.h"
#include "Matiere.h"
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

// FONCTION PERMETTANT DE RECUPERER LES INFORMATIONS D'UN CANDIDAT

void Candidat::saisirCandidat()
{
    cout << "               ------------------------------------------------------<<" << endl;//design
    cout << "               ***ICI VOUS SAISISSEZ LES INFORMATIONS DES CANDIDATS*** " << endl;//affichage pour orienter l'utilisateur
    cout << "               -------------------------------------------------------\n\n" << endl;//design
    int cpt,i,j;
    int guide2 = 1,guide=0,compteur=0,aide=0,tailleCniRecue,tailleNom,taillePrenom,tailleAge,ageFinal,cni;
    string code,cniRecue,nom,prenom,age;
    Candidat a;
    string choix;

    do
    {
            cout << endl;
            cout << "  Entrer votre numero de CNI: \t";
            getline(cin,cniRecue);
         do
        {
            guide2 = 1;
            //CONTROLE DU NUMERO DE CNI ENTRE PAR L'UTILISATEUR
            do
           {
                tailleCniRecue = cniRecue.size();

                for(j=0;j<tailleCniRecue;j++)
                {
                    if(cniRecue[j] != '1' && cniRecue[j] != '2' && cniRecue[j] != '3' && cniRecue[j] != '4' && cniRecue[j] != '5' && cniRecue[j] != '6' && cniRecue[j] != '7' && cniRecue[j] != '8' && cniRecue[j] != '9' && cniRecue[j] != '0')
                    {
                        compteur++;
                        guide =1;

                    }
                }

                if(compteur>0 || tailleCniRecue > 9)
                {
                    cout << endl;
                    cout << "  ERREUR !!! Numero de CNI errone ou trop long!!! " << endl;
                    cout << "  Veuillez entrer une cni valide \t";
                    getline(cin,cniRecue);
                    compteur = 0;
                    guide = 1;
                }
                else
                {
                    guide = 0;
                }


            }while(guide != 0);

            istringstream flux(cniRecue); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
            flux >> cni; //conversion proprement dite de la chaine de caractere en entier


            if(VerifieCni(cni)) //test de verification du numero de cni precedement entre par l'utilisateur pour s'assurer qu'il n'entre pas une cni qui se trouve deja dans le fichier
            {
                cout << endl;
                cout << "  Desole !!! La CNI que vous avez choisie est deja prise par un autre etudiant" << endl;
                cout << "  Entrez une nouvelle CNI \t";
                getline(cin,cniRecue);
                guide2 = 0;
            }
        }while(guide2 == 0 );

         a.NCIN = cni;

            cout << endl;
            cout << "  Entrez le nom: \t" ;//pour saisir le nom
             getline(cin,nom);
                //controle du nom entre par l'utilisateur
                do
                {
                    tailleNom = nom.size();

                    for(j=0;j<tailleNom;j++)
                    {
                        if(nom[j] == ';')
                        {
                            compteur++;
                            aide =1;

                        }
                    }

                    if(compteur > 0)
                    {
                        cout << endl;
                        cout << "  ERREUR !!! Votre nom contient un point virgule!!! " << endl;
                        cout << "  Veuillez entrer un nom valide \t";
                        getline(cin,nom);
                        compteur = 0;
                        aide = 1;
                    }
                    else
                    {
                        aide = 0;
                    }

                }  while(aide != 0);

                    a.Nom = nom;

            cout << endl;
            cout << "  Entrez le prenom: \t";//pour saisir le prenom
                getline(cin,prenom);
                //controle du prenom entre par l'utilisateur

                do
                {
                    taillePrenom = prenom.size();

                    for(j=0;j<taillePrenom;j++)
                    {
                        if(prenom[j] == ';')
                        {
                            compteur++;
                            aide =1;

                        }
                    }

                    if(compteur > 0)
                    {
                        cout << endl;
                        cout << "  ERREUR !!! Votre prenom contient un point virgule!!! " << endl;
                        cout << "  Veuillez entrer un prenom valide \t";
                        getline(cin,prenom);
                        compteur = 0;
                        aide = 1;
                    }
                    else
                    {
                        aide = 0;
                    }


                }  while(aide != 0);

                a.Prenom = prenom;

            cout << endl;
            cout << "  Entrer l'age: \t";//pour saisir l'age
                 getline(cin,age);
                //controle de l'age entre par l'utilisateur

                do
                {
                    tailleAge = age.size();

                    for(j=0;j<tailleAge;j++)
                    {
                        if(age[j] != '1' && age[j] != '2' && age[j] != '3' && age[j] != '4' && age[j] != '5' && age[j] != '6' && age[j] != '7' && age[j] != '8' && age[j] != '9' && age[j] != '0')
                        {
                            compteur++;
                            aide =1;

                        }
                    }

                    if(compteur>0 || tailleAge != 2)
                    {
                        cout << endl;
                        cout << "  ERREUR !!!  !!! " << endl;
                        cout << "  Veuillez entrer un age raisonnable : \t";
                        getline(cin,age);
                        compteur = 0;
                        aide = 1;
                    }
                    else
                    {
                        aide = 0;
                    }


                }  while(aide != 0);

                   istringstream isss(age); //creation du flux de la chaine de caractere "age" en entier
                    isss >> ageFinal; //conversion de l'age en entier

                    a.Age = ageFinal;

                    ajouterCandidat(a); //fonction permettant d'ecrire les informations d'un candidat dans le fichier Candidat.txt

        cout << "\n                            CANDIDAT BIEN ENREGISTRE...\n\n"<< endl;
        cout << "  voulez vous continuer la saisie ??  " << endl;
        cout << "  1 pour OUI et 0 pour NON \t";
        getline(cin,choix);
        while(choix != "0" && choix != "1")
        {
            cout << endl;
            cout << "  Erreur !!! Entrez un choix valide \t";
            getline(cin,choix);
        }
        if(choix == "1")
            {
                system("CLS");
                cout << "               ------------------------------------------------------<<" << endl;//design
                cout << "               ***ICI VOUS SAISISSEZ LES INFORMATIONS DES CANDIDATS*** " << endl;//affichage pour orienter l'utilisateur
                cout << "               -------------------------------------------------------\n\n" << endl;//design
            }
    }while(choix=="1"); //condition permettant de repeter l'execution de cette fonction

    cout << endl;
    cout <<"             SAISIE EFFECTUEE AVEC SUCCES                               "<< endl;
}




//fonction prenant en parametre un candidat et permettant d'ecrire ses informations dans le fichier Candidat.txt

void Candidat::ajouterCandidat(Candidat a)
{
     ofstream fichierCandidats("Candidats.txt", ios::app | ios::out); // ouverture en écriture du fichier Candidat.txt

    if(fichierCandidats)
    {
        fichierCandidats << a.NCIN << ";" << a.Nom << ";" << a.Prenom << ";" << a.Age << endl; //ecriture dans le fichier
        fichierCandidats.close();//fermeture du fichier
    }
    else
    cerr << " Impossible d'ouvrir le fichier !" << endl;


}



//fonction permettant de verifier si un code de matiere se trouve dans le fichier Matiere.txt

bool Candidat::VerifieCode(string code)
{
    string codeMatiere;
    string resteLigne;

    ifstream fichier("Matiere.txt", ios::in); // ouverture en lecture du fichier Matiere.txt

    if(fichier)
    {

       while(fichier >> codeMatiere)
       {
           fichier.get();

            if(codeMatiere == code)
           {
               return true;
           }
           getline(fichier,resteLigne);

       }
       return false;

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}

//fonction prenant en parametre le numero de cni d'un candidat et permettant de supprimer les informations ce dernier
void Candidat::supprimerCandidat(int NCNI)

{

    int NCNI2=0,tailleCniRecue,compteur=0,guide=0,j;
    string resteLigne,choix,cniRecue;
    string ligne;
    string ligne2;
    string ligne3;
    string ligne4;
    string ligne5;
    int guide2 = 1; // variable permettant de verifier que l'utilisateur a entre un numero de cni correct


       do
       {
        //controle du numero de cni entre par l'utilisateur
           do
           {

                tailleCniRecue = cniRecue.size();

                for(j=0;j<tailleCniRecue;j++)
                {
                    if(cniRecue[j] != '1' && cniRecue[j] != '2' && cniRecue[j] != '3' && cniRecue[j] != '4' && cniRecue[j] != '5' && cniRecue[j] != '6' && cniRecue[j] != '7' && cniRecue[j] != '8' && cniRecue[j] != '9' && cniRecue[j] != '0')
                    {
                        compteur++;
                        guide =1;

                    }
                }

                if(compteur>0 || tailleCniRecue > 9)
                {
                    cout << endl;
                    cout << "  ERREUR !!! Numero de CNI errone ou trop long!!! " << endl;
                    cout << "  Veuillez entrer une cni valide \t";
                    getline(cin,cniRecue);
                    compteur = 0;
                    guide = 1;
                }
                else
                {
                    guide = 0;
                }


           }  while(guide != 0);

            istringstream flux(cniRecue); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
            flux >> NCNI; //conversion de la chaine de caracter en entier


         if(VerifieCni(NCNI)) //fonction permettant de verifier qu'un numero de cni existe dans le ficher Candidat.txt
            {
                //SUPPRESSION DES INFORMATIONS D'UN CANDIDAT DANS LE FICHIER Candidats.txt
                ifstream fichierCandidats("Candidats.txt", ios::in); //ouverture du fichier Candidat.txt en mode lecture
                ofstream fichierTempo("tempo.txt", ios::app | ios::in); //ouverture du fichier tempo.txt en mode ecriture
                if(fichierCandidats && fichierTempo)
                {
                   while(fichierCandidats >> NCNI2) //recuperation d'un numero de cni dans le fichier Candidat.txt
                   {
                       getline(fichierCandidats,resteLigne); // recuperation du nom, prenon et age du candidat


                       if(NCNI2 != NCNI) // test de comparaison entre le numero de cni precedement recupere dans le fichier et celui envoye en parametre
                       {
                           fichierTempo << NCNI2 << resteLigne << endl; //ecriture du numero de cni,nom,prenom et age dans le fichier tempo.txt (fichier temporel)
                       }

                   }

                }
                else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

                ofstream fichierCandidatsNew("Candidats.txt", ios::out | ios::trunc); //effacement du contenu du fichier Candidat.txt
                ofstream fichierCandidatsNewNew("Candidats.txt", ios::out | ios::app);//reouverture en ecriture du fichier Candidat.txt
                ifstream fichierTempoNew("tempo.txt", ios::in); //ouverture du fichier tempo.txt en mode lecture
                if(fichierCandidatsNewNew)
                {

                    while(getline(fichierTempoNew,ligne)) //recuperation numero de cni,nom,prenom et age d'un candidat dans le fichier tempo.txt
                    {
                        fichierCandidatsNewNew << ligne << endl; //ecriture dans le fichier candidat.txt des inforations precedements recuperees
                    }
                }
                ofstream fichierTempoNewNew("tempo.txt", ios::out | ios::trunc);//effacement du contenu du ficher tempo

                //SUPPRESSION DES NOTES D'UN CANDIDAT DANS LE FICHIER Evaluation.txt
                ofstream fichierTempo1("tempo.txt", ios::out | ios::app);

                ifstream fichier("Evaluation.txt", ios::in);
                int cni3 = 0;
                string resteLigne2;
                if(fichier)
               {
                        while(fichier >> cni3)
                    {
                        getline(fichier,resteLigne2);

                        if(cni3 != NCNI)
                       {
                           fichierTempo1 << cni3 << resteLigne2 << endl;
                       }
                    }
               }
               else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

                 ofstream fichier1("Evaluation.txt", ios::out | ios::trunc);
                ofstream fichier2("Evaluation.txt", ios::out | ios::app);
                ifstream fichierTempo2("tempo.txt", ios::in);
                if(fichier2)
                {

                    while(getline(fichierTempo2,ligne2))
                    {
                        fichier2 << ligne2 << endl;
                    }
                }
                ofstream fichierTempo3("tempo.txt", ios::out | ios::trunc);

                //SUPPRESSION DES INFORMATIONS DU MEME CANDIDAT DANS LE FICHIER resultat.txt

                ofstream fichierTempoResul("tempo.txt", ios::out | ios::app);

                ifstream fichierResultat("resultat.txt", ios::in);
                int cni4 = 0;
                string resteLigne3;
                if(fichierTempoResul && fichierResultat)
               {
                        while(fichierResultat >> cni4)
                    {
                        getline(fichierResultat,resteLigne3);

                        if(cni4 != NCNI)
                       {
                           fichierTempoResul << cni4 << resteLigne3 << endl;
                       }
                    }
               }
               else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

                 ofstream fichierResultat2("resultat.txt", ios::out | ios::trunc);
                ofstream fichierResultat3("resultat.txt", ios::out | ios::app);
                ifstream fichierTempoResul2("tempo.txt", ios::in);
                if(fichierResultat3)
                {

                    while(getline(fichierTempoResul2,ligne3))
                    {
                        fichierResultat3 << ligne3 << endl;
                    }
                }
                ofstream fichierTempoResul3("tempo.txt", ios::out | ios::trunc);

                //SUPPRESSION DES INFORMATIONS DU MEME CANDIDAT DANS LE FICHIER admis.txt SI JAMAIS IL S'IL TROUVE

                ofstream fichierTempoAdmis("tempo.txt", ios::out | ios::app);

                ifstream fichierAdmis("admis.txt", ios::in);
                int cni5 = 0;
                string resteLigne4;
                if(fichierTempoAdmis)
               {
                        while(fichierAdmis >> cni5)
                    {
                        getline(fichierAdmis,resteLigne4);

                        if(cni5 != NCNI)
                       {
                           fichierTempoAdmis << cni5 << resteLigne4 << endl;
                       }
                    }
               }
               else
                cerr << "  Impossible d'ouvrir le fichier !" << endl;

                 ofstream fichierAdmis2("admis.txt", ios::out | ios::trunc);
                ofstream fichierAdmis3("admis.txt", ios::out | ios::app);
                ifstream fichierTempoAdmis2("tempo.txt", ios::in);
                if(fichierAdmis3)
                {

                    while(getline(fichierTempoAdmis2,ligne4))
                    {
                        fichierAdmis3 << ligne4 << endl;
                    }
                }
                ofstream fichierTempoAdmis3("tempo.txt", ios::out | ios::trunc);

                //SUPPRESSION DES INFORMATIONS DU MEME CANDIDAT DANS LE FICHIER attente.txt

                ofstream fichierTempoAttente("tempo.txt", ios::out | ios::app);

                ifstream fichierAttente("attente.txt", ios::in);
                int cni6 = 0;
                string resteLigne5;
                if(fichierTempoAttente)
               {
                        while(fichierAttente >> cni6)
                    {
                        getline(fichierAttente,resteLigne5);

                        if(cni6 != NCNI)
                       {
                           fichierTempoAttente << cni6 << resteLigne5 << endl;
                       }
                    }
               }
               else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

                ofstream fichierAttente2("attente.txt", ios::out | ios::trunc);
                ofstream fichierAttente3("attente.txt", ios::out | ios::app);
                ifstream fichierTempoAttente2("tempo.txt", ios::in);
                if(fichierAttente3)
                {

                    while(getline(fichierTempoAttente2,ligne5))
                    {
                        fichierAttente3 << ligne5 << endl;
                    }
                }
                ofstream fichierTempoAttente3("tempo.txt", ios::out | ios::trunc);

               guide2 = 0;
            }
            else
            {
                cout << endl;
                cout << "  Erreur !!! candidat introuvable !!!" << endl;
                cout << "  Veuillez entrer un numero de CNI d'un candidat existant \t";
                getline(cin,cniRecue);
            }
    }while(guide2!=0);



}

//FONCTION PERMETTANT DE VERIFIER QU'UN NUMERO DE CNI SE TROUVE DANS LE FICHIER candidat.txt
bool Candidat::VerifieCni(int cni)
{
    string resteLigne;
    int cni2;

    ifstream fichier("Candidats.txt", ios::in); // ouverture en lecture du fichier candidat.txt

    if(fichier)
    {

       while(fichier >> cni2)
       {
           getline(fichier,resteLigne);

            if(cni2 == cni)
           {
               return true;
           }


       }
       return false;

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}
//FONCTION PERMETTANT DE MODIFIER LES INFORMATIONS D'UN CANDIDAT
void Candidat::modifierCandidat()
{
    int cniFinal,cniFinal2,cniVrai,cni2,ageFinal,i,j,taille,tailleCniRecue,compteur = 0,guide = 0,aide = 0,aider = 0,indicateur=0;
    string nom,prenom,age,ligne,cni;
    string cniRecue,choix,line;
    char debutNom,debutPrenom,debutAge,debutCni;
    cout << endl;
    cout << "               -------------------------------------------------------" << endl;//design
    cout << "               ***ICI VOUS MODIFIEZ LES INFORMATIONS DES CANDIDATS*** " << endl;//affichage pour orienter l'utilisateur
    cout << "               -------------------------------------------------------\n\n" << endl;//design


        cout << endl;
        cout << "  Entrez la cni du candidat dont vous voulez modifier les informations \t";
        getline(cin,cniRecue);
    do
    {
        indicateur = 0;
       do
       {
           aide = 0;
            //Controle du numero de cni entre par l'utilisateur
           do
           {
                tailleCniRecue = cniRecue.size();

                for(j=0;j<tailleCniRecue;j++)
                {
                    if(cniRecue[j] != '1' && cniRecue[j] != '2' && cniRecue[j] != '3' && cniRecue[j] != '4' && cniRecue[j] != '5' && cniRecue[j] != '6' && cniRecue[j] != '7' && cniRecue[j] != '8' && cniRecue[j] != '9' && cniRecue[j] != '0')
                    {
                        compteur++;
                        guide =1;

                    }
                }

                if(compteur>0 || tailleCniRecue > 9)
                {
                    cout << endl;
                    cout << "  ERREUR !!! Numero de CNI errone ou trop long!!! " << endl;
                    cout << "  Veuillez entrer une cni valide \t";
                    getline(cin,cniRecue);
                    compteur = 0;
                    guide = 1;
                }
                else
                {
                    guide = 0;
                }


           }  while(guide != 0);

            istringstream flux(cniRecue); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
            flux >> cni2; //conversion de la chaine de caractere en entier

            if(VerifieCni(cni2))
            {
                ifstream fichierCandidat("Candidats.txt", ios::in);
                ofstream fichierCandidat2("Candidats.txt",ios::out | ios::app);

                if(fichierCandidat)
                {
                    while(getline(fichierCandidat,ligne)) //boucle de recuperation des informations contenues dans chaque ligne du fichier candidat.txt
                  {
                        taille = ligne.size();
                        debutCni = ligne[0];
                        stringstream flux; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        flux << debutCni; //recuperation du caractere dans le flux
                        flux >> cni; //conversion du caractere precedement recupere en chaine de caractere
                        i=1;
                        while(ligne[i] != ';')
                        {
                            cni = cni + ligne[i];
                            i++;
                        }
                        istringstream fluxCni(cni); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
                        fluxCni >> cniFinal; //conversion de la chaine de caractere en entier
                        i++;

                        debutNom = ligne[i];
                        stringstream flux2; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        flux2 << debutNom; //recuperation du caractere dans le flux
                        flux2 >> nom; //conversion du caractere precedement recupere en chaine de caractere
                        i++;
                        while(ligne[i] != ';')
                        {
                            nom = nom + ligne[i];
                            i++;
                        }
                        i++;

                        debutPrenom = ligne[i];
                        stringstream flux3; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        flux3 << debutPrenom; //recuperation du caractere dans le flux
                        flux3 >> prenom; //conversion du caractere precedement recupere en chaine de caractere
                        i++;
                        while(ligne[i] != ';')
                        {
                            prenom = prenom + ligne[i];
                            i++;
                        }
                        i++;
                        debutAge = ligne[taille-2];
                        stringstream flux4;
                        flux4 << debutAge;
                        flux4 >> age;
                        age = age + ligne[taille-1];
                        istringstream flux5(age); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
                        flux5 >> ageFinal; //conversion de la chaine de caractere en entier

                        string choix ,cniNouvelle;
                        int choixFinal,tailleCniNouvelle,tailleNom,taillePrenom,tailleAge;

                        if(cniFinal == cni2)
                        {

                            cout << endl;
                            cout << "  Voulez vous modifier votre numero de CNI ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! entrer un choix valide \t";
                                getline(cin,choix);
                            }
                        //modification du numero de cni
                            if(choix == "1")
                            {
                                indicateur++;
                                cout << endl;
                                cout << "  Entrez le nouveau numero de CNI : \t";
                                getline(cin,cniNouvelle);

                                do
                                {

                                        do
                                        {
                                            tailleCniNouvelle = cniNouvelle.size();

                                            for(j=0;j<tailleCniNouvelle;j++)
                                            {
                                                if(cniNouvelle[j] != '1' && cniNouvelle[j] != '2' && cniNouvelle[j] != '3' && cniNouvelle[j] != '4' && cniNouvelle[j] != '5' && cniNouvelle[j] != '6' && cniNouvelle[j] != '7' && cniNouvelle[j] != '8' && cniNouvelle[j] != '9' && cniNouvelle[j] != '0')
                                                {
                                                    compteur++;
                                                    aide =1;

                                                }
                                            }

                                            if(compteur>0 || tailleCniNouvelle > 9)
                                            {
                                                cout << endl;
                                                cout << "  ERREUR !!! Numero de CNI errone ou trop long!!! " << endl;
                                                cout << "  Veuillez entrer une cni valide \t";
                                                getline(cin,cniNouvelle);
                                                compteur = 0;
                                                aide = 1;
                                            }
                                            else
                                            {
                                                aide = 0;
                                            }


                                        }  while(aide != 0);

                                   istringstream iss(cniNouvelle);
                                    iss >> cniFinal;
                                    if(VerifieCni(cniFinal))
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!! la CNI que vous venez de choisir appartient deja a un autre candidat" <<endl;
                                        cout << "  Entrez une autre CNI \t";
                                        getline(cin,cniNouvelle);
                                        aider = 1;
                                    }
                                    else
                                    {
                                        aider = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU NUMERO DE CNI" << endl;
                                    }
                                }while(aider == 1 );


                            }
                            cout << endl;
                            cout << "  Voulez vous modifier votre nom ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! Veuillez entrer un choix valide \t";
                                getline(cin,choix);
                            }
                            //modification du nom
                            if(choix == "1")
                            {
                                   cout << endl;
                                   cout << "  Entrez le nouveau nom : \t";
                                getline(cin,nom);

                                do
                                {
                                    tailleNom = nom.size();

                                    for(j=0;j<tailleNom;j++)
                                    {
                                        if(nom[j] == ';')
                                        {
                                            compteur++;
                                            aide =1;

                                        }
                                    }

                                    if(compteur > 0)
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!! Votre nom contient un point virgule!!! " << endl;
                                        cout << "  Veuillez entrer un nom valide \t";
                                        getline(cin,nom);
                                        compteur = 0;
                                        aide = 1;
                                    }
                                    else
                                    {
                                        aide = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU NOM !!!" << endl;
                                    }


                                }  while(aide != 0);
                            }
                            cout << endl;
                            cout << "  Voulez vous modifier votre prenom ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! Veuillez entrer un choix valide \t";
                                getline(cin,choix);
                            }
                            //modification du prenom
                            if(choix == "1")
                            {
                                   cout << endl;
                                   cout << "  Entrez le nouveau prenom : \t";
                                   getline(cin,prenom);

                                do
                                {
                                    taillePrenom = prenom.size();

                                    for(j=0;j<taillePrenom;j++)
                                    {
                                        if(prenom[j] == ';')
                                        {
                                            compteur++;
                                            aide =1;

                                        }
                                    }

                                    if(compteur > 0)
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!! Votre prenom contient un point virgule!!! " << endl;
                                        cout << "  Veuillez entrer un prenom valide \t";
                                        getline(cin,prenom);
                                        compteur = 0;
                                        aide = 1;
                                    }
                                    else
                                    {
                                        aide = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU PRENOM !!!" << endl;
                                    }


                                }  while(aide != 0);
                            }

                            cout << endl;
                            cout << "  Voulez vous modifier votre age ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! Veuillez entrer un choix valide \t";
                                getline(cin,choix);
                            }

                            //modification de l'age
                            if(choix == "1")
                            {
                                cout << endl;
                                cout << "  Entrez le nouvel age : \t";
                                getline(cin,age);

                                do
                                {
                                    tailleAge = age.size();

                                    for(j=0;j<tailleAge;j++)
                                    {
                                        if(age[j] != '1' && age[j] != '2' && age[j] != '3' && age[j] != '4' && age[j] != '5' && age[j] != '6' && age[j] != '7' && age[j] != '8' && age[j] != '9' && age[j] != '0')
                                        {
                                            compteur++;
                                            aide =1;

                                        }
                                    }

                                    if(compteur>0 || tailleAge != 2)
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!!  !!! " << endl;
                                        cout << "  Veuillez entrer un age raisonnable : \t";
                                        getline(cin,age);
                                        compteur = 0;
                                        aide = 1;
                                    }
                                    else
                                    {
                                        aide = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DE L'AGE" << endl;
                                    }


                                }  while(aide != 0);

                                   istringstream isss(age);
                                    isss >> ageFinal;
                            }

                                cniFinal2 = cniFinal;

                                  // MODIFICATION DE LA NOUVELLE CNI DANS LE FICHIER Evaluation.txt
                          int cniEva;
                          string resteLigne;
                          ofstream fichierTempoAide4("tempoAide.txt", ios::out | ios::trunc);
                          ofstream fichierTempoAide("tempoAide.txt", ios::out | ios::app);
                          ofstream fichierTempoEva2("tempo.txt", ios::out | ios::trunc);
                          ofstream fichierTempoEva("tempo.txt", ios::out | ios::app);
                          ifstream fichierEvaluation("Evaluation.txt", ios::in);
                          if(fichierTempoEva && fichierEvaluation)
                          {
                              while(fichierEvaluation >> cniEva)
                              {
                                  getline(fichierEvaluation,resteLigne);
                                  if(cni2 == cniEva)
                                  {
                                      fichierTempoEva << cniFinal2 <<resteLigne << endl;
                                      fichierTempoAide << cniFinal2 <<resteLigne<< endl;
                                  }
                                  else
                                  {
                                      fichierTempoEva << cniEva << resteLigne << endl;
                                  }
                              }
                          }
                          else
                            cerr << "  Impossible d'ouvrir le fichier !" << endl;

                          ofstream fichierEvaluationNew("Evaluation.txt", ios::out | ios::trunc);
                          ofstream fichierEvaluationNewNew("Evaluation.txt", ios::out | ios:: app);
                          ifstream fichierTempoEvaNew("tempo.txt", ios::in);
                          if(fichierEvaluationNewNew)
                            {
                              while(getline(fichierTempoEvaNew,ligne))
                              {
                                  fichierEvaluationNewNew << ligne <<endl;
                              }
                              ofstream fichierTempoEvaNewNew("tempo.txt", ios::out | ios::trunc);
                            }
                          else
                         cerr << "  Impossible d'ouvrir le fichier !" << endl;
                         if( indicateur >0)
                         {
                             supprimerCandidat(cni2);
                             fichierCandidat2 << cniFinal << ";" << nom << ";" << prenom << ";" << ageFinal << endl;
                         }
                         else if( indicateur == 0)
                         {
                             supprimerCandidat(cni2);
                             fichierCandidat2 << cniFinal << ";" << nom << ";" << prenom << ";" << ageFinal << endl;
                             ofstream fichierEvaluationAide("Evaluation.txt", ios::out | ios:: app);
                             ifstream fichierTempoAide2("tempoAide.txt", ios::in);
                                if(fichierEvaluationAide)
                                {
                                    while(getline(fichierTempoAide2,line))
                                    {
                                        fichierEvaluationAide << line << endl;
                                    }
                                }
                                else
                                {
                                    cerr << "  Impossible d'ouvrir le fichier !" << endl;
                                }

                                ofstream fichierTempoAide3("tempoAide.txt", ios::out | ios::trunc);
                         }


                      }

                    }

                    cout << endl;
                    cout << "                  ******MODIFICATION FAITE AVEC SUCCES******   " << endl;
                }
                else
                cerr << "  Impossible d'ouvrir le fichier !" << endl;


            }
            else
            {
                    cout << endl;
                    cout << "  Erreur !!! candidat introuvable !!!" << endl;
                    cout << "  Veuillez entrer un numero de CNI d'un candidat existant \t";
                    getline(cin,cniRecue);
                    aide = 1;
            }

        }while(aide != 0);

      cout << endl;
      cout << "  voulez vous modifier un autre candidat ??  " << endl;
      cout << "  1 pour OUI et 0 pour NON \t";
        getline(cin,choix);
        while(choix != "0" && choix != "1")
        {
            cout << endl;
            cout << "  Erreur !!! Entrez un choix valide \t";
            getline(cin,choix);
        }
        if(choix == "1")
        {
            system("CLS");
            cout << endl;
            cout << "               ------------------------------------------------------<<" << endl;//design
            cout << "               ***ICI VOUS MODIFIEZ LES INFORMATIONS DES CANDIDATS*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            cout << endl;
            cout << "  Entrez la cni du candidat dont vous voulez modifier les informations \t";
            getline(cin,cniRecue);
        }
    }while(choix=="1");



}


