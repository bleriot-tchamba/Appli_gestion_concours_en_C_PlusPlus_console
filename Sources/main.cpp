#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Candidat.h"
#include "Matiere.h"
#include "Evaluation.h"
using namespace std;

void menuPrincipal();

int main()
{
                                            /*INFO204:POO
                                            NOMS: BETNDAM TCHAMBA BLERIOT PAGNAUL
                                            matricule: 18T2491*/


    string choix;
    cout <<"                                               *******************************************************************************************************************\n\n";
    cout <<"                                               ******************************** BIENVENUE DANS VOTRE APLLICATION DE GESTION DE CONCOURS ****************************\n\n";
    cout <<"                                               *******************************************************************************************************************\n\n";
    do
    {
        menuPrincipal();
        cout << endl;
        cout << "  RETOUR AU MENU ??" << endl;
        cout << "  TAPEZ 1 POUR OUI ou 0 POUR NON \t";
        getline(cin,choix);
        while(choix != "1" && choix != "0")
        {
            cout << "  ERREUR !!! Entrez un choix valide \t";
            getline(cin,choix);
        }
        system("CLS");

    }while(choix=="1");
    cout <<"                                               ****************************************************************************************\n\n";
    cout <<"                                               ********************************  A VOUS REVOIR BIENTOT !!! ****************************\n\n";
    cout <<"                                               ****************************************************************************************\n\n";

    return 0;
}
 // FONCTION PERMETTANT D'AFFICHER LE MENU
void menuPrincipal()
{
    Candidat c;
    Matiere m;
    Evaluation e;
    string cniRecue,codeMatiere,choix,choix2;
    int tailleCniRecue,cni,compteur=0,guide=0,choixFinal,j;

    cout <<"                                               ****                        *****************************************************                              ****     \n\n";
    cout <<"                                               ****                        *************** ICI C'EST LE MENU PRINCIPAL**********                              ****      \n\n";
    cout <<"                                               ****                        *****************************************************                              ****       \n\n";
    cout <<"                                               ****                                                                                                           ****        \n\n";
    cout <<"                                               ****      1  : AJOUTER UN CANDIDAT                                                                             ****          \n\n";
    cout <<"                                               ****      2  : AJOUTER LES NOTES D'UN CANDIDAT (EVALUATION)                                                    ****         \n\n";
    cout <<"                                               ****      3  : AJOUTER UNE MATIERE                                                                             ****          \n\n";
    cout <<"                                               ****      4  : MODIFIER LES INFORMATIONS D'UN CANDIDAT(JUSTE ENTRER LE NUMERO DE SA CNI)                       ****          \n\n";
    cout <<"                                               ****      5  : MODIFIER LES NOTES D'UN CANDIDAT                                                                ****          \n\n";
    cout <<"                                               ****      6  : MODIFIER LES INFORMATIONS D'UNE MATIERE                                                         ****          \n\n";
    cout <<"                                               ****      7  : SUPPRIMER LES INFORMATIONS D'UN CANDIDAT(JUSTE ENTRER LE NUMERO DE SA CNI)                      ****          \n\n";
    cout <<"                                               ****      8  : SUPPRIMER LES INFORMATIONS D'UNE MATIERE                                                        ****          \n\n";
    cout <<"                                               ****      9  : MISE A JOUR DE LA LISTE DES CANDIDATS ADMIS (TOUT AGE CONFONDU)                                 ****           \n\n";
    cout <<"                                               ****      10 : MISE A JOUR DE LA LISTE DES CANDIDATS ADMIS ET AGES DE PLUS DE 20 ANS                           ****           \n\n";
    cout <<"                                               ****      11 : MISE A JOUR DE LA LISTE DES CANDIDATS ADMIS ET AGES DE 20 ANS AU MAXIMUM                        ****            \n\n";
    cout <<"                                               ****      12 : AFFICHER LES STATISTIQUES DES CANDIDATS                                                         ****             \n\n";
    cout <<"                                               ****      13 : AFFICHER LES CANDIDATS ADMIS PAR ORDRE DE MERITE                                                ****            \n\n\n";

    cout <<"                        Entrez votre choix: ";
    getline(cin,choix);
    while(choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "6" && choix != "7" && choix != "8" && choix != "9" && choix != "10" && choix != "11" && choix != "12" && choix != "13")
    {
        cout <<"           CHOIX NON VALIDE!!!" << endl;
        cout <<"           ENTREZ UN CHOIX VALIDE: \t";
        getline(cin,choix);
    }
    istringstream flux(choix);
    flux >> choixFinal;

    switch(choixFinal)
    {
        case 1:
            system("CLS");
            c.saisirCandidat();
            break;
        case 2:
            system("CLS");
            e.saisirEvaluation();
            e.resultat();
            break;
        case 3:
            system("CLS");
            m.saisirMatiere();
            break;
        case 4:
            system("CLS");
            c.modifierCandidat();
            e.resultat();
            break;
        case 5:
            system("CLS");
            e.modifierNote();
            e.resultat();
            break;
        case 6:
            system("CLS");
            m.modifierMatiere();
            e.resultat();
            break;

        case 7:

        {
            system("CLS");
            cout << endl;
            cout << "               ----------------------------------------------------------------------------------------------------------" << endl;//design
            cout << "               ****************************ICI VOUS SUPPRIMEZ LES INFORMATIONS D'UN CANDIDAT**************************** " << endl;//affichage pour orienter l'utilisateur
            cout << "               ----------------------------------------------------------------------------------------------------------\n\n" << endl;//design
            cout << endl;
            cout << "  Entrez le numero de CNI du candidat que vous voulez supprimer \t";
                getline(cin,cniRecue);
                        do
                      {

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
                                flux >> cni;
                                c.supprimerCandidat(cni);
                                e.resultat();
                                e.admis_sans_affichage();
                                cout << endl;
                                cout << "  SUPRESSION REUSSI DU CANDIDAT" << endl;
                                cout << endl;
                        cout << "  voulez vous supprimer un autre candidat ??  " << endl << endl;
                        cout << "  1 pour OUI ou 0 pour NON \t";
                        getline(cin,choix2);
                        while(choix2 != "0" && choix2 != "1")
                        {
                            cout << endl;
                            cout << "  Erreur !!! Entrez un choix valide \t";
                            getline(cin,choix2);
                        }
                        if(choix2 == "1")
                        {
                            system("CLS");
                            cout << endl;
                            cout << "               ----------------------------------------------------------------------------------------------------------" << endl;//design
                            cout << "               ****************************ICI VOUS SUPPRIMEZ LES INFORMATIONS D'UN CANDIDAT**************************** " << endl;//affichage pour orienter l'utilisateur
                            cout << "               ----------------------------------------------------------------------------------------------------------\n\n" << endl;//design
                            cout << endl;
                            cout << "  Entrez le numero de CNI du candidat que vous voulez supprimer\t";
                            getline(cin,cniRecue);
                        }

                    }while(choix2=="1");

                        break;
                }

        case 8:
           system("CLS");
            cout << endl;
            cout << "               ------------------------------------------------------<<" << endl;//design
            cout << "               ***ICI VOUS SUPPRIMEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            cout << endl;
            cout << "  Entrez le code de la matiere que vous voulez supprimer\t";
            getline(cin,codeMatiere);
            m.supprimerMatiere(codeMatiere);
            e.resultat();
            break;
        case 9:
            system("CLS");
            cout << endl;
            cout << "               ------------------------------------------------------<<" << endl;//design
            cout << "               ***LISTE DES CANDIDATS ADMIS (TOUT AGE CONFONDU)*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            e.resultat();
            e.admis ();
            break;
        case 10:
            system("CLS");
            cout << endl;
            cout << "               ------------------------------------------------------<<" << endl;//design
            cout << "               ***LISTE DES CANDIDATS ADMIS AYANT PLUS DE 20 ANS*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design

            e.resultat();
            e.admis_sans_affichage();
            e.attente();
            break;
        case 11:
            system("CLS");
            cout << endl;
            cout << "               -------------------------------------------------------" << endl;//design
            cout << "               ***LISTE DES CANDIDATS ADMIS AYANT POUR AGE MAXIMUM 20 ANS*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            e.resultat();
            e.admis_sans_affichage();
            e.supprimer();
            break;
        case 12:
            system("CLS");
            cout << endl;
            cout << "               -------------------------------------------------------" << endl;//design
            cout << "               **************STATISTIQUES DES RESULTATS************** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            e.resultat();
            e.statistique();
            break;
        case 13:
            system("CLS");
            cout << endl;
            cout << "               -------------------------------------------------------" << endl;//design
            cout << "               ***LISTE DES CANDIDATS ADMIS PAR ORDRE DE MERITE*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            e.resultat();
            e.afficheMerite();
            break;
        default:
            cout <<"           CHOIX NON VALIDE!!!" << endl;
            cout <<"           ENTREZ UN CHOIX VALIDE: \t";
            break;

    }

}







