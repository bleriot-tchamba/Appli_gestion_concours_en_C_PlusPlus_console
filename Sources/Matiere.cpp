#include <iostream>
#include <sstream>
#include "Matiere.h"
#include "Candidat.h"
#include "Evaluation.h"
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void Matiere::saisirMatiere()
{
    string choix;
    int aide = 0,tailleCodeRecu,tailleLibelleRecu,taillecoefRecu,j,compteur=0,guide=0;
    string codeRecu,libelleRecu,coefRecu;
    double coefFinal;
    Matiere a;
        cout << endl;
        cout << "               ------------------------------------------------------" << endl;//design
        cout << "               ***ICI VOUS SAISISSEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
        cout << "               -------------------------------------------------------\n\n" << endl;//design

    do
    {

        cout << endl;
        cout << "  Entrez le code de la matiere (ex:info201): \t";
        getline(cin,codeRecu);
        do
        {
            do
            {
                    tailleCodeRecu = codeRecu.size();

                    for(j=0;j<tailleCodeRecu;j++)
                    {
                        if(codeRecu[j] == ';' || codeRecu[j] == ' ' || codeRecu[j] == ',' || codeRecu[j] == '.' || codeRecu[j] == '[' || codeRecu[j] == ']' || codeRecu[j] == '/' || codeRecu[j] == '?' || codeRecu[j] == '|' || codeRecu[j] == '*' || codeRecu[j] == '+' || codeRecu[j] == '-' || codeRecu[j] == '"')
                        {
                            compteur++;
                            guide =1;

                        }
                    }

                    if(compteur>0)
                    {
                        cout << endl;
                        cout << "  ERREUR !!! Code de matiere invalide!!! " << endl;
                        cout << "  Veuillez entrer un code valide \t";
                        getline(cin,codeRecu);
                        compteur = 0;
                        guide = 1;
                    }
                    else
                    {
                        guide = 0;
                    }


            }  while(guide != 0);


            if(VerifieCode(codeRecu))
            {
                cout << endl;
                cout << "  Erreur !!! Ce code de matiere fait deja partie des matieres existantes " << endl << endl;
                cout << "  Veuillez entrer un autre code \t";
                getline(cin,codeRecu);
                aide = 1;
            }
            else
                {
                    aide = 0;
                }
        }while(aide != 0);

        a.code = codeRecu;

        cout << endl;
        cout << "  Entrez son libelle: \t";
        getline(cin,libelleRecu);

        do
        {
                tailleLibelleRecu = libelleRecu.size();

                for(j=0;j<tailleLibelleRecu;j++)
                {
                    if(libelleRecu[j] == ';')
                    {
                        compteur++;
                        guide =1;

                    }
                }

                if(compteur>0)
                {
                    cout << endl;
                    cout << "  ERREUR !!! Libelle de matiere invalide car il contient un point virgule!!! " << endl;
                    cout << "  Veuillez entrer un libelle valide \t";
                    getline(cin,libelleRecu);
                    compteur = 0;
                    guide = 1;
                }
                else
                {
                    guide = 0;
                }


        }  while(guide != 0);

            a.libelle = libelleRecu;
        cout << endl;
        cout << "  Entrez son coefficient: \t";
        getline(cin,coefRecu);

            do
            {
                taillecoefRecu = coefRecu.size();

                for(j=0;j<taillecoefRecu;j++)
                {
                    if(coefRecu[j] != '1' && coefRecu[j] != '2' && coefRecu[j] != '3' && coefRecu[j] != '4' && coefRecu[j] != '5' && coefRecu[j] != '6' && coefRecu[j] != '7' && coefRecu[j] != '8' && coefRecu[j] != '9' && coefRecu[j] != '0' && coefRecu[j] != '.')
                    {
                        compteur++;
                        aide =1;

                    }
                }
                istringstream isss(coefRecu);
                isss >> coefFinal;

                if(compteur>0 || coefFinal>99)
                {
                    cout << endl;
                    cout << "  ERREUR !!!  !!! " << endl;
                    cout << "  Veuillez entrer un coefficient raisonnable : \t";
                    getline(cin,coefRecu);
                    compteur = 0;
                    aide = 1;
                }
                else
                {
                    aide = 0;
                }


            }  while(aide != 0);



                a.coefficient = coefFinal;

        ajouterMatiere(a);
        cout << endl;
        cout << "  AJOUT REUSSI DE LA MATIERE " << "***" << a.libelle << "***" << " DE CODE " << "***" << a.code << "***" << endl << endl;
        cout << "  Voulez-vous ajouter une autre matiere ?? "<< endl;
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
            cout << "               ------------------------------------------------------" << endl;//design
            cout << "               ***ICI VOUS SAISISSEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design

        }

    }while (choix == "1");


}

 void Matiere::ajouterMatiere(Matiere m)
 {

      ofstream fichier("Matiere.txt", ios::app | ios::in); // ouverture en écriture avec effacement du fichier ouvert
    if(fichier)
    {
        fichier << m.code << " ;" << m.libelle << " ;" << m.coefficient << endl;
        fichier.close();
    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
 }

 void Matiere::supprimerMatiere(string code)
 {
     string code2;
     string resteLigne;
     string ligne,choix;
     int guide = 1;
    do
    {
        guide = 1;
     do
     {
         if(VerifieCode(code))
            {
                ifstream fichierMatiere("Matiere.txt", ios::in);
                ofstream fichierTempo("tempo.txt", ios::app | ios::out);
                if(fichierMatiere && fichierTempo)
                {
                   while(fichierMatiere >> code2)
                   {
                       fichierMatiere.get();
                       getline(fichierMatiere,resteLigne);


                       if(code != code2)
                       {
                           fichierTempo << code2 << " " << resteLigne << endl;
                       }

                   }

                }
                else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
                ofstream fichierMatiereNew("Matiere.txt", ios::out | ios::trunc);
                ofstream fichierMatiereNewNew("Matiere.txt", ios::out | ios::app);
                ifstream fichierTempoNew("tempo.txt", ios::in);
                if(fichierMatiereNewNew)
                {

                    while(getline(fichierTempoNew,ligne))
                    {
                        fichierMatiereNewNew << ligne << endl;
                    }
                }
                ofstream fichierTempoNewNew("tempo.txt", ios::out | ios::trunc);
                 ofstream fichierTempo1("tempo.txt", ios::out | ios::app);

                ifstream fichier("Evaluation.txt", ios::in);
                int cni3 = 0; //cni dans le fichier evaluation.txt
                string codeEva; //code de la matiere dans le fichier evaluation.txt
                int note; //note d'une matiere dans le fichier evaluation
                string ligne; // variable qui recupere chaque ligne du fichier tempo.txt pour copier dans le fichier evaluation.txt
                if(fichier)
               {
                        while(fichier >> cni3)
                    {
                        fichier.get();
                        fichier >> codeEva;
                        fichier.get();
                        fichier.get();
                        fichier >> note;

                        if(codeEva != code)
                       {
                           fichierTempo1 << cni3 << ";" << codeEva << " ;" << note << endl;
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

                    while(getline(fichierTempo2,ligne))
                    {
                        fichier2 << ligne << endl;
                    }
                }
                ofstream fichierTempo3("tempo.txt", ios::out | ios::trunc);
                cout << endl << endl;
                cout << "  BRAVO !!! SUPPRESSION REUSSIE DE LA MATIERE" << endl;

                guide = 0;
            }
            else
            {
                cout << endl;
                cout << "  Erreur !!! Code de matiere introuvable" << endl;
                cout << "  Veuillez entrer un code de matiere correct\t";
                getline(cin, code);

            }
       }while(guide != 0);
        cout << endl;
        cout << "  voulez vous supprimer une autre matiere ??  " << endl;
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
            cout << "               ***ICI VOUS SUPPRIMEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
            cout << "  Entrez le code de la matiere que vous voulez supprimer\t";
            getline(cin,code);
        }

    }while(choix=="1");


 }

 bool Matiere::VerifieCode(string code)
{
    string resteLigne;
    string code2;
    ifstream fichier("Matiere.txt", ios::in); // ouverture en écriture avec effacement du fichier ouvert

    if(fichier)
    {

       while(fichier >> code2)
       {
           fichier.get();
           getline(fichier,resteLigne);

            if(code == code2)
           {
               return true;
           }


       }
       return false;

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Matiere::modifierMatiere()
{

    int cniFinal,cniFinal2,cniVrai,cni2,i,j,taille,tailleCodeRecue,compteur = 0,guide = 0,aide = 0,aider = 0,tailleLibelleAvant=0,m,k;
    double coefFinal;
    string libelleAvant,libelle,prenom,coef,ligne,code,code2;
    string codeRecue,choix;
    char debutLibelleAvant,debutLibelle,debutPrenom,debutCoef,debutCode;
    cout << "               ------------------------------------------------------<<" << endl;//design
    cout << "               ***ICI VOUS MODIFIEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
    cout << "               -------------------------------------------------------\n\n" << endl;//design
    do
    {
        cout << endl;
        cout << "  Entrez le code de la matiere dont vous voulez modifier les informations \t";
        getline(cin,codeRecue);
       do
       {
           aide = 0;

           do
           {
                tailleCodeRecue = codeRecue.size();

                for(j=0;j<tailleCodeRecue;j++)
                {
                    if(codeRecue[j] == ';' || codeRecue[j] == ' ')
                    {
                        compteur++;
                        guide =1;

                    }
                }

                if(compteur>0)
                {
                    cout << endl;
                    cout << "  ERREUR !!! Code de matiere invalide!!! " << endl;
                    cout << "  Veuillez entrer un code valide \t";
                    getline(cin,codeRecue);
                    compteur = 0;
                    guide = 1;
                }
                else
                {
                    guide = 0;
                }


           }  while(guide != 0);



            if(VerifieCode(codeRecue))
            {
                ifstream fichierMatiere("Matiere.txt", ios::in);
                ofstream fichierTempo("tempo.txt", ios::out | ios::app);

                if(fichierMatiere)
                {
                    while(getline(fichierMatiere,ligne))
                  {
                        taille = ligne.size();
                        debutCode = ligne[0];
                        stringstream flux; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        flux << debutCode; //recuperation du caractere dans le flux
                        flux >> code; //conversion du caractere precedement recupere en chaine de caractere
                        i=1;
                        while(ligne[i] != ' ')
                        {
                            code = code + ligne[i];
                            i++;
                        }
                        i++;
                        i++;

                        debutLibelleAvant = ligne[i];
                        stringstream flux2; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        flux2 << debutLibelleAvant; //recuperation du caractere dans le flux
                        flux2 >> libelleAvant; //conversion du caractere precedement recupere en chaine de caractere
                        i++;
                        while(ligne[i] != ';')
                        {
                            libelleAvant = libelleAvant + ligne[i];
                            i++;
                        }
                        tailleLibelleAvant = libelleAvant.size();
                        debutLibelle = libelleAvant[0];
                        stringstream fluxLib; // creation d'un flux de conversion d'un caractere en chaine de caractere
                        fluxLib << debutLibelle ; //recuperation du caractere dans le flux
                        fluxLib >> libelle; //conversion du caractere precedement recupere en chaine de caractere
                        for(m=1;m<tailleLibelleAvant-1;m++)
                        {
                            libelle = libelle + libelleAvant[m];
                        }
                        i++;


                        debutCoef = ligne[i];
                        stringstream flux4;
                        flux4 << debutCoef;
                        flux4 >> coef;
                        i++;
                        k = i;
                        for(i=k;i<taille;i++)
                        {
                            coef = coef + ligne[i];
                        }

                        istringstream flux5(coef); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
                        flux5 >> coefFinal; //conversion de la chaine de caractere en double

                        string choix;
                        int choixFinal,tailleCode,tailleLibelle,taillePrenom,tailleCoef;

                        if(codeRecue == code)
                        {
                            cout << endl;
                            cout << "  Voulez vous modifier le code de cette matiere ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! entrer un choix valide \t";
                                getline(cin,choix);
                            }

                            if(choix == "1")
                            {
                                cout << endl;
                                cout << "  Entrez le nouveau code de matiere : \t";
                                getline(cin,code);

                                do
                                {

                                    do
                                   {
                                        tailleCode = code.size();

                                        for(j=0;j<tailleCode;j++)
                                        {
                                            if(code[j] == ';' || code[j] == ' ')
                                            {
                                                compteur++;
                                                guide =1;

                                            }
                                        }

                                        if(compteur>0)
                                        {
                                            cout << endl;
                                            cout << "  ERREUR !!! Code de matiere invalide!!! " << endl;
                                            cout << "  Veuillez entrer un code valide \t";
                                            getline(cin,code);
                                            compteur = 0;
                                            guide = 1;
                                        }
                                        else
                                        {
                                            guide = 0;
                                        }


                                   }  while(guide != 0);


                                    if(VerifieCode(code))
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!! le code que vous venez de choisir appartient deja a une autre matiere" <<endl;
                                        cout << "  Entrez un autre code de matiere  \t";
                                        getline(cin,code);
                                        aider = 1;
                                    }
                                    else
                                    {
                                        aider = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU CODE DE MATIERE" << endl;
                                    }
                                }while(aider == 1 );


                            }
                            cout << endl;
                            cout << "  Voulez vous modifier le libelle de cette matiere ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! Veuillez entrer un choix valide \t";
                                getline(cin,choix);
                            }
                            if(choix == "1")
                            {
                                   cout << endl;
                                   cout << "  Entrez le nouveau libelle : \t";
                                getline(cin,libelle);

                                do
                                {
                                    tailleLibelle = libelle.size();

                                    for(j=0;j<tailleLibelle;j++)
                                    {
                                        if(libelle[j] == ';')
                                        {
                                            compteur++;
                                            aide =1;

                                        }
                                    }

                                    if(compteur > 0)
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!! le libelle de cette matiere contient un point virgule!!! " << endl;
                                        cout << "  Veuillez entrer un libelle valide \t";
                                        getline(cin,libelle);
                                        compteur = 0;
                                        aide = 1;
                                    }
                                    else
                                    {
                                        aide = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU LIBELLE !!!" << endl;
                                    }


                                }  while(aide != 0);
                            }

                            cout << endl;
                            cout << "  Voulez vous modifier le coefficient ?? " << endl;
                            cout << "  tapez 1 pour OUI ou tapez 0 pour NON \t ";
                            getline(cin,choix);
                            while(choix != "1" && choix != "0")
                            {
                                cout << endl;
                                cout << "  ERREUR !!! Veuillez entrer un choix valide \t";
                                getline(cin,choix);
                            }

                            if(choix == "1")
                            {
                                cout << endl;
                                cout << "  Entrez le nouveau coefficient : \t";
                                getline(cin,coef);

                                do
                                {
                                    tailleCoef = coef.size();

                                    for(j=0;j<tailleCoef;j++)
                                    {
                                        if(coef[j] != '1' && coef[j] != '2' && coef[j] != '3' && coef[j] != '4' && coef[j] != '5' && coef[j] != '6' && coef[j] != '7' && coef[j] != '8' && coef[j] != '9' && coef[j] != '0' && coef[j] != '.')
                                        {
                                            compteur++;
                                            aide =1;

                                        }
                                    }

                                    if(compteur>0)
                                    {
                                        cout << endl;
                                        cout << "  ERREUR !!!  !!! " << endl;
                                        cout << "  Veuillez entrer un coefficient valide : \t";
                                        getline(cin,coef);
                                        compteur = 0;
                                        aide = 1;
                                    }
                                    else
                                    {
                                        aide = 0;
                                        cout << endl;
                                        cout << "  MODIFICATION REUSSIE DU COEFFICIENT" << endl;
                                    }


                                }  while(aide != 0);

                                   istringstream isss(coef);
                                    isss >> coefFinal;
                            }
                            fichierTempo << code << " ;" << libelle << " ;" << coefFinal << endl;
                                code2 = code;

                        }
                        else
                        {
                            fichierTempo << ligne << endl;
                        }

                  }
                    cout << endl;
                    cout << "                  ******MODIFICATION FAITE AVEC SUCCES******   " << endl;
            }
            else
            cerr << "  Impossible d'ouvrir le fichier !" << endl;



                  ofstream fichierMatiereNew("Matiere.txt", ios::out | ios::trunc);
                  ofstream fichierMatiereNewNew("Matiere.txt", ios::out | ios:: app);
                  ifstream fichierTempoNew("tempo.txt", ios::in);
                      if(fichierMatiereNewNew)
                      {
                          while(getline(fichierTempoNew,ligne))
                          {
                              fichierMatiereNewNew << ligne <<endl;
                          }
                          ofstream fichierTempoNewNew("tempo.txt", ios::out | ios::trunc);
                       }
                      else
                     cerr << "  Impossible d'ouvrir le fichier !" << endl;


                        // MODIFICATION DU NOUVEAU CODE DANS LE FICHIER Evaluation.txt
                          int cniEva;
                          string codeEva;
                          double noteEva;
                          ofstream fichierTempoEva("tempo.txt", ios::out | ios::app);
                          ifstream fichierEvaluation("Evaluation.txt", ios::in);
                          if(fichierTempoEva && fichierEvaluation)
                          {
                              while(fichierEvaluation >> cniEva)
                              {
                                  fichierEvaluation.get();
                                  fichierEvaluation >> codeEva;
                                  fichierEvaluation.get();
                                  fichierEvaluation.get();
                                  fichierEvaluation >> noteEva;
                                  if(codeRecue == codeEva)
                                  {
                                      fichierTempoEva << cniEva << ";" << code2 << " ;" << noteEva << endl;
                                  }
                                  else
                                  {
                                      fichierTempoEva << cniEva << ";" <<codeEva << " ;" << noteEva << endl;
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






            }
            else
             {
                    cout << endl;
                    cout << "  Erreur !!! matiere introuvable !!!" << endl;
                    cout << "  Veuillez entrer un code de matiere existant \t";
                    getline(cin,codeRecue);
                    aide = 1;
             }

       }while(aide != 0);
        cout << endl;
        cout << "  voulez vous modifier une autre matiere ??  " << endl;
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
            cout << "               ***ICI VOUS MODIFIEZ LES INFORMATIONS D'UNE MATIERE*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
        }


    }while(choix=="1");



}
