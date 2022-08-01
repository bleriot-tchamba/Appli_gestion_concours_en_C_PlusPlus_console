#include <iostream>
#include <sstream>
#include "Candidat.h"
#include "Evaluation.h"
#include "Matiere.h"
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;



void Evaluation::resultat()
{
  int cni;
  int nbreNote = 0;
  string codeMatiere;
  string Decision;
  double note,coefficient;
  double somNoteFoisCoef=0.0;
  double somCoef = 0.0;
  double moyenne = 0.0;
  int compteur=0;//pour informer sur la fin de recuperation des notes d'un candidat
  int indicateurDecision = 0; // informe sur le nombre de note superieurs à 10
  ifstream fichierEvaluation("Evaluation.txt", ios::in);
  ifstream fichierMatiere("Matiere.txt", ios::in);
  ofstream fichierResultatNew("resultat.txt", ios::out | ios::trunc);
  ofstream fichierResultat("resultat.txt", ios::app | ios::out);
   while(fichierEvaluation >> cni)
   {
       nbreNote = retourneNbreNote(cni);
       if(compteur < nbreNote)
       {
           fichierEvaluation.get();
           fichierEvaluation >> codeMatiere;
           fichierEvaluation.get();
           fichierEvaluation.get();
           fichierEvaluation >> note;
           if(note >= 10)
           {
               indicateurDecision++;
           }
           coefficient = retourneCoef(codeMatiere);
           somNoteFoisCoef = somNoteFoisCoef + (coefficient*note);
           somCoef = somCoef + coefficient;
           compteur++;
        }
        if(compteur == nbreNote)
        {
               moyenne = somNoteFoisCoef/somCoef;
           if(moyenne >= 10 && indicateurDecision==nbreNote )
                Decision = "ADMIS";
           else if(moyenne >=10 && indicateurDecision < nbreNote )
                Decision = "AJOURNE";
           else
                Decision = "REFUSE";

           fichierResultat << cni << " ;" << moyenne << " ;" << Decision << endl;
           compteur = 0;
           indicateurDecision = 0;
           somNoteFoisCoef=0.0;
           somCoef = 0.0;
        }



   }
}

int Evaluation::retourneNbreNote(int cni)
{
    string codeMatiere;
    double note;
    int cni2;
    int compteur=0;
    ifstream fichierEvaluation("Evaluation.txt", ios::in);
    if(fichierEvaluation)
    {
        while(fichierEvaluation >> cni2)
        {
           fichierEvaluation.get();
           fichierEvaluation >> codeMatiere;
           fichierEvaluation.get();
           fichierEvaluation.get();
           fichierEvaluation >> note;
           if(cni2 == cni)
           {
               compteur++;
           }
        }
        fichierEvaluation.close();
        return compteur;
    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}

double Evaluation::retourneCoef(string codeMatiere)
{
    string codeMatiere2;
    string resteLigne;
    string coef;
    string coef2;
    char caract;
    char caract2;
    int taille;
    int taille2;
    int verif = 0;
    double coefficient;
    ifstream fichierMatiere("Matiere.txt", ios::in);
   if(fichierMatiere)
    {

       while (fichierMatiere >> codeMatiere2)
       {
           getline(fichierMatiere,resteLigne);
          taille = resteLigne.size();
          caract = resteLigne[taille-1];
          stringstream flux;
          flux << caract;
          flux >> coef;
          while(resteLigne[taille-2] != ';')
          {
              coef = coef + resteLigne[taille-2];
              taille--;
          }
          taille2 = coef.size();
          if(taille2 > 1)
          {
              caract2 = coef[taille2-1];
              stringstream flux2;
              flux2 << caract2;
              flux2 >> coef2;
              for(int i = taille2-2;i>=0;i--)
              {
                  coef2 = coef2 + coef[i];
              }
              verif = 1;
          }
          if(verif == 1)
          {
              istringstream fl(coef2);
              fl >> coefficient;
          }
          else if(verif == 0)
          {
                istringstream flu(coef);
                flu >> coefficient;
          }





            if(codeMatiere == codeMatiere2)
           {
               return coefficient;
           }


       }


    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Evaluation::admis()
{
    string resteLigne;
    int cni,informateur=0;
    int nbreCaractere = 0,i=0,j=1;
    double moyenne;
    string Decision;

    ofstream fichierAdmisNew("admis.txt", ios::out | ios::trunc);
    ofstream fichierAdmis("admis.txt", ios::app | ios::out);
    ifstream fichierResultat("resultat.txt", ios::in);

     if(fichierResultat)
    {

       while(fichierResultat >> cni)
       {
           fichierResultat.get();
           fichierResultat.get();
           fichierResultat >> moyenne;
           fichierResultat.get();
           fichierResultat.get();
           fichierResultat >> Decision;


            if(Decision == "ADMIS")
           {
               informateur++;
               resteLigne = retourneAdmis(cni);
               fichierAdmis << cni << ";" << resteLigne <<endl;
               cout << endl;
               cout << "   " << j << "-  " << cni << " " ; j++;
               nbreCaractere = resteLigne.size();
               for(i = 0; i <= nbreCaractere-4;i++)
                {
                    if(resteLigne[i] != ';')
                    {
                         cout << resteLigne[i];
                    }
                    else if(resteLigne[i] == ';')
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }


       }
               if(informateur == 0)
               {
                    cout << endl;
                    cout << "  ********************PAS DE CANDIDAT ADMIS************************" << endl;
               }


    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;


}

void Evaluation::admis_sans_affichage()
{

    string resteLigne;
    int cni;
    double moyenne;
    string Decision;

    ofstream fichierAdmisNew("admis.txt", ios::out | ios::trunc);
    ofstream fichierAdmis("admis.txt", ios::app | ios::out);
    ifstream fichierResultat("resultat.txt", ios::in);

     if(fichierResultat)
    {

       while(fichierResultat >> cni)
       {
           fichierResultat.get();
           fichierResultat.get();
           fichierResultat >> moyenne;
           fichierResultat.get();
           fichierResultat.get();
           fichierResultat >> Decision;


            if(Decision == "ADMIS")
           {
               resteLigne = retourneAdmis(cni);
               fichierAdmis << cni << ";" << resteLigne <<endl;
           }

       }

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}

string Evaluation::retourneAdmis(int cni)
{
    string resteLigne;
    int cni2;
   ifstream fichierCandidats("Candidats.txt", ios::in);
   if(fichierCandidats)
    {

       while(fichierCandidats >> cni2)
       {
           fichierCandidats.get();

           getline(fichierCandidats,resteLigne);


            if(cni == cni2)
           {
               return resteLigne;
           }

        }


    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Evaluation::attente()
{
    string ligne;// variable qui recupere chaque ligne du fichier admis.txt
    string debutLigne;// variable qui recupere la cni,nom et prenom de chaque candidat admis
    string finLigne; //variable qui recupere l'age d'un candidat admis sous forme de chaine de caractere
    char debut; //variable qui recupere le premier caractere de chaque ligne du fichier admis
    char fin; //variable qui recupere le premier chiffre de l'age
    int age,i,j=1,nbreCaractere;
    int taille;  //recupere le nombre de caractere de chaque ligne du fichier admis.txt
    int informateur=0;

    ifstream fichierAdmis("admis.txt", ios::in); // ouverture du fichier admis.txt en lecture
    ofstream fichierAttenteNew("attente.txt", ios::out | ios::trunc); // suppression du contenu du fichier attente
    ofstream fichierAttente("attente.txt", ios::app | ios::out); //ouverture du fichier attente en ecriture
    if(fichierAdmis) // test d'ouverture du fichier
    {
        while(getline(fichierAdmis,ligne)) //recuperation d'une ligne du fichier admis.txt
        {
            taille = ligne.size(); // recuperation du nombre de caractere d'une ligne du fichier admis.txt dans la variable taille
            debut = ligne[0]; //affectation du premier caractere d'une ligne du fichier admis.txt dans la variable debut
            stringstream flux; // creation d'un flux de conversion d'un caractere en chaine de caractere
            flux << debut; //recuperation du caractere dans le flux
            flux >> debutLigne; //conversion du caractere precedement recupere en chaine de caractere
            for(i=1;i<=taille-4;i++) //parcour de la chaine de caractere *ligne* jusqu'au dernier caractere du prenom
            {
                debutLigne = debutLigne + ligne[i]; //concatenation de chaque caractere dans la chaine de caractere *debutLigne*
            }
            fin = ligne[taille-2]; // affectation du premier chiffre de l'age dans la variable *fin*
            stringstream flux2; // creation d'un flux de conversion d'un caractere en chaine de caractere
            flux2 << fin; //recuperation du caractere dans le flux
            flux2 >> finLigne; //conversion du caractere precedement recupere en chaine de caractere
            finLigne = finLigne + ligne[taille-1]; //concatenation du deuxieme chiffre de l'age dans la chaine de caractere *finLigne*
            istringstream flux3(finLigne); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
            flux3 >> age; //conversion de la chaine de caractere en entier
            if(age>20) //test sur l'age
            {
               informateur++;
               fichierAttente << debutLigne << endl; //ecriture de la cni, nom et prenom dans le fichier attente.txt
               cout << endl;
               cout << "   " << j << "-  "; j++;
               nbreCaractere = debutLigne.size(); // affectation du nombre de caractere de la chaine de caractere contenant la cni,nom et prenom dans la variable entiere
               for(i = 0; i <= nbreCaractere-1;i++) //parcour de la chaine de caractere precedente jusqu'au dernier caractere
                {
                    if(debutLigne[i] != ';') //test de verification pour s'assurer que le caractere actuel est different du point virgurle (ceci dans le but de ne pas afficher un point virgule dans la console pour une meilleure presentation)
                    {
                         cout << debutLigne[i]; //affichage du caractere actuel dans la console
                    }
                    else if(debutLigne[i] == ';') // test de verification du caractere actuel
                    {
                        cout << " "; // si le caractere precedement testé est un point virgurle, alors on affiche un espace en remplacement de ce dernier en vue d'une meilleure presentation
                    }
                }
                cout << endl; //retour a la ligne (ceci pour l'affichage des informations d'un nouveau candidat)
            }

        }
            if(informateur == 0)
               {
                    cout << endl;
                    cout << "  ********************PAS DE CANDIDAT ADMIS AGE DE PLUS DE 20 ANS************************" << endl;
               }
    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Evaluation::statistique()
{
    int cni,informateur=0;
    double nbreCandidats=0,nbreAdmis=0,nbreAjourne=0,nbreRefuse=0;
    double moyenne;
    double pourcentageAdmis = 0, pourcentageAjourne=0, pourcentageRefuse=0;
    string decision;
    ifstream fichierResultat("resultat.txt",ios::in);
    while(fichierResultat >> cni)
    {
        informateur++;
        nbreCandidats++;
        fichierResultat.get();
        fichierResultat.get();
        fichierResultat >> moyenne;
        fichierResultat.get();
        fichierResultat.get();
        fichierResultat >> decision;
        if(decision == "ADMIS")
        {
            nbreAdmis++;
        }

        else if(decision == "AJOURNE")
        {
            nbreAjourne++;
        }
        else if(decision == "REFUSE")
        {
            nbreRefuse++;
        }
    }
    pourcentageAdmis = (nbreAdmis/nbreCandidats)*100;
    pourcentageAjourne = (nbreAjourne/nbreCandidats)*100;
    pourcentageRefuse = (nbreRefuse/nbreCandidats)*100;
    if(informateur>0)
    {
        cout << "   POURCENTAGE DES CANDIDATS ADMIS    : " << pourcentageAdmis << endl;
        cout << "   POURCENTAGE DES CANDIDATS AJOURNES : " << pourcentageAjourne << endl;
        cout << "   POURCENTAGE DES CANDIDATS REFUSES  : " << pourcentageRefuse << endl;
    }
    else if(informateur == 0)
    {
        cout << endl;
        cout << "  ********************PAS DE CANDIDAT ENREGISTRES************************" << endl;
    }

}

void Evaluation::supprimer()
{
    string ligne;// variable qui recupere chaque ligne du fichier admis.txt
    string debutLigne;// variable qui recupere la cni,nom et prenom de chaque candidat admis
    string finLigne; //variable qui recupere l'age d'un candidat admis sous forme de chaine de caractere
    char debut; //variable qui recupere le premier caractere de chaque ligne du fichier admis
    char fin; //variable qui recupere le premier chiffre de l'age
    int age,i,j=1,nbreCaractere;
    int taille;  //recupere le nombre de caractere de chaque ligne du fichier admis.txt
    int informateur=0;

    ifstream fichierAdmis("admis.txt", ios::in); // ouverture du fichier admis.txt en lecture
    ofstream fichierTempo("tempo.txt", ios::app | ios::out); //ouverture du fichier tempo en ecriture
    if(fichierTempo) // test d'ouverture du fichier
    {
        while(getline(fichierAdmis,ligne)) //recuperation d'une ligne du fichier admis.txt
        {
            taille = ligne.size(); // recuperation du nombre de caractere d'une ligne du fichier admis.txt dans la variable taille
            debut = ligne[0]; //affectation du premier caractere d'une ligne du fichier admis.txt dans la variable debut
            stringstream flux; // creation d'un flux de conversion d'un caractere en chaine de caractere
            flux << debut; //recuperation du caractere dans le flux
            flux >> debutLigne; //conversion du caractere precedement recupere en chaine de caractere
            for(i=1;i<=taille-4;i++) //parcour de la chaine de caractere *ligne* jusqu'au dernier caractere du prenom
            {
                debutLigne = debutLigne + ligne[i]; //concatenation de chaque caractere dans la chaine de caractere *debutLigne*
            }
            fin = ligne[taille-2]; // affectation du premier chiffre de l'age dans la variable *fin*
            stringstream flux2; // creation d'un flux de conversion d'un caractere en chaine de caractere
            flux2 << fin; //recuperation du caractere dans le flux
            flux2 >> finLigne; //conversion du caractere precedement recupere en chaine de caractere
            finLigne = finLigne + ligne[taille-1]; //concatenation du deuxieme chiffre de l'age dans la chaine de caractere *finLigne*
            istringstream flux3(finLigne); //creation d'un flux de conversion d'une chaine de caractere en entier et recuperation de la chaine de caractere
            flux3 >> age; //conversion de la chaine de caractere en entier
            if(age<=20) //test sur l'age
            {
              informateur++;
              fichierTempo << debutLigne << endl; //ecriture de la cni, nom et prenom dans le fichier tempo.txt
               cout << "   " << j << "-  "; j++;
               nbreCaractere = debutLigne.size(); // affectation du nombre de caractere de la chaine de caractere contenant la cni,nom et prenom dans la variable entiere
               for(i = 0; i <= nbreCaractere-1;i++) //parcour de la chaine de caractere precedente jusqu'au dernier caractere
                {
                    if(debutLigne[i] != ';') //test de verification pour s'assurer que le caractere actuel est different du point virgurle (ceci dans le but de ne pas afficher un point virgule dans la console pour une meilleure presentation)
                    {
                         cout << debutLigne[i]; //affichage du caractere actuel dans la console
                    }
                    else if(debutLigne[i] == ';') // test de verification du caractere actuel
                    {
                        cout << " "; // si le caractere precedement testé est un point virgurle, alors on affiche un espace en remplacement de ce dernier en vue d'une meilleure presentation
                    }
                }
                cout << endl << endl; //retour a la ligne (ceci pour l'affichage des informations d'un nouveau candidat)

            }

        }

        ofstream fichierAdmisNew("admis.txt", ios::out | ios::trunc); // suppression du contenu du fichier admis.txt
        ofstream fichierAdmisNew2("admis.txt", ios::app | ios::out ); //reouverture du fichier admis.txt en ecriture
        ifstream fichierTempoNew("tempo.txt", ios::in); //reouverture du fichier tempo.txt en lecture
        while(getline(fichierTempoNew,ligne)) //recuperation d'une ligne du fichier tempo.txt
        {
            fichierAdmisNew2 << ligne << endl; //ecriture de la ligne precedement récupérée dans le fichier admis.txt
        }
        ofstream fichierTempoNew2("tempo.txt", ios::out | ios::trunc); // suppression du contenu du fichier tempo.txt

           if(informateur == 0)
           {
                cout << endl;
                cout << "  ********************PAS DE CANDIDATS ADMIS AGES DE 20 ANS AU MAXIMUM************************" << endl;
           }

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl; // message affiché dans le cas d'erreur d'ouverture du fichier

}

bool Evaluation::VerificationCni(int cni)
{
    string resteLigne;
    int cni2;
    ifstream fichier("Candidats.txt", ios::in); // ouverture en écriture avec effacement du fichier ouvert

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

bool Evaluation::VerificationCode(string code)
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

void Evaluation::modifierNote()
{

    int aide=0,guide=0,guideCode=0,tailleCniRecue,tailleCodeRecue,tailleNoteNouvelle,j,compteur=0,compteurCode=0,cni2;
    string cniRecue,codeRecue,ligne;
    int cniEva;
    string codeEva,noteNouvelle,choix;
    double noteEva,noteFinale;

    cout << "               ------------------------------------------------------<<" << endl;//design
    cout << "               ***ICI VOUS MODIFIEZ LES NOTES D'UN CANDIDAT*** " << endl;//affichage pour orienter l'utilisateur
    cout << "               -------------------------------------------------------\n\n" << endl;//design

    do
    {
            cout << endl;
            cout << "  Entrez la cni du candidat dont vous voulez modifier la note \t";
            getline(cin,cniRecue);

        do
        {
           aide = 0;


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

             if (VerificationCni(cni2) && VerificationCniEva(cni2))
             {
                cout << endl;
                cout << "  Entrez le code de la matiere dont vous voulez modifier la note \t";
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
                                compteurCode++;
                                guideCode =1;

                            }
                        }

                        if(compteurCode>0)
                        {
                            cout << endl;
                            cout << "  ERREUR !!! Code de matiere invalide!!! " << endl;
                            cout << "  Veuillez entrer un code valide \t";
                            getline(cin,codeRecue);
                            compteurCode = 0;
                            guideCode = 1;
                        }
                        else
                        {
                            guideCode = 0;
                        }


                   }  while(guideCode != 0);



                    if(VerificationCode(codeRecue) && VerificationCodeEva(cni2,codeRecue))
                    {

                       //OUVERTURE DES FICHIERS Evaluation.txt ET tempo.txt
                       ifstream fichierEvaluation("Evaluation.txt",ios::in);
                       ofstream fichierTempo("tempo.txt", ios::out | ios::app);
                       if(fichierTempo && fichierEvaluation)
                       {
                           while(fichierEvaluation >> cniEva )
                           {
                               fichierEvaluation.get();
                               fichierEvaluation >> codeEva;
                               fichierEvaluation.get();
                               fichierEvaluation.get();
                               fichierEvaluation >> noteEva;

                               if(cniEva == cni2 && codeEva == codeRecue)
                               {
                                   cout << endl;
                                   cout << "  Entrer la nouvelle note \t";
                                   getline(cin,noteNouvelle);


                                    do
                                    {
                                        tailleNoteNouvelle = noteNouvelle.size();

                                        for(j=0;j<tailleNoteNouvelle;j++)
                                        {
                                            if(noteNouvelle[j] != '1' && noteNouvelle[j] != '2' && noteNouvelle[j] != '3' && noteNouvelle[j] != '4' && noteNouvelle[j] != '5' && noteNouvelle[j] != '6' && noteNouvelle[j] != '7' && noteNouvelle[j] != '8' && noteNouvelle[j] != '9' && noteNouvelle[j] != '0' && noteNouvelle[j] != '.')
                                            {
                                                compteur++;
                                                aide =1;

                                            }
                                        }
                                         istringstream isssf(noteNouvelle);
                                        isssf >> noteFinale;

                                        if(compteur>0 || noteFinale <0 || noteFinale >20)
                                        {
                                            cout << endl;
                                            cout << "  ERREUR !!!  !!! " << endl;
                                            cout << "  Veuillez entrer une note valide et au plus egale a 20 : \t";
                                            getline(cin,noteNouvelle);
                                            compteur = 0;
                                            aide = 1;
                                        }
                                        else
                                        {
                                            aide = 0;
                                            cout << endl;
                                            cout << "  MODIFICATION REUSSIE DE LA NOTE DE " << codeEva << endl;
                                        }


                                    }  while(aide != 0);


                                        fichierTempo << cniEva << ";" << codeEva << " ;" << noteFinale << endl;
                               }
                               else
                               {
                                    fichierTempo << cniEva << ";" << codeEva << " ;" << noteEva << endl;
                               }
                           }
                       }
                       else
                        cerr << "  Impossible d'ouvrir le fichier" << endl;
                    }
                    else
                    {
                        if(!VerificationCode(codeRecue))
                         {
                             cout << endl;
                             cout << "  Erreur !!! code de matiere introuvable" << endl;
                             cout << "  Veuillez entrer un code existant \t";
                             getline(cin,codeRecue);
                             aide = 1;
                         }
                         else if(!VerificationCodeEva(cni2,codeRecue))
                         {
                             cout << endl;
                             cout << "  Erreur !!! ce code n'existe pas parmis les matieres de votre evaluation" << endl;
                             cout << "  Veuillez entrer un code auquel vous avez ete evalue \t";
                             getline(cin,codeRecue);
                             aide = 1;
                         }
                    }
                }while(aide != 0);

                    ofstream fichierEvaluationNew("Evaluation.txt",ios::out | ios::trunc);
                    ofstream fichierEvaluationNewNew("Evaluation.txt",ios::out | ios::app);
                    ifstream fichierTempoNew("tempo.txt", ios::in);
                        if(fichierEvaluationNewNew && fichierTempoNew)
                        {
                            while(getline(fichierTempoNew,ligne))
                            {
                                fichierEvaluationNewNew << ligne << endl;
                            }
                            ofstream fichierTempoNewNew("tempo.txt", ios::out | ios::trunc);
                        }
                        else
                            cerr << " Impossible d'ouvrir le fichier" << endl;

            }
            else
             {
                 if(!VerificationCni(cni2))
                 {
                        cout << endl;
                        cout << "  Erreur !!! candidat introuvable !!!" << endl;
                        cout << "  Veuillez entrer un numero de CNI d'un candidat existant \t";
                        getline(cin,cniRecue);
                        aide = 1;
                 }
                else if(!VerificationCniEva(cni2))
                {
                        cout << endl;
                        cout << "  Erreur !!! ce numero de CNI n'a pas de note enregistree dans nos fichiers !!!" << endl;
                        cout << "  Veuillez entrer un numero de CNI d'un candidat ayant les notes enregistrees dans nos fichiers \t";
                        getline(cin,cniRecue);
                        aide = 1;
                }
             }

       }while(aide != 0);
        cout << endl;
        cout << "  voulez vous modifier une autre note de ce candidat ou une note d'un autre candidat ??  " << endl;
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
            cout << "               ***ICI VOUS MODIFIEZ LES NOTES D'UN CANDIDAT*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
        }
    }while(choix=="1");

}

string Evaluation::retourneAfficheMerite(int cni)
{
    string chaineCni,ligne;
    char debutCni;
    int cniFichier,i;
    ifstream fichierCandidat("Candidats.txt", ios::in);
    if(fichierCandidat)
    {
        while(getline(fichierCandidat,ligne))
        {
            debutCni = ligne[0];
            stringstream flux;
            flux << debutCni;
            flux >> chaineCni;
            i = 1;
            while(ligne[i] != ';')
            {
                chaineCni = chaineCni + ligne[i];
                i++;
            }
            istringstream flux2(chaineCni);
            flux2 >> cniFichier;
            if(cniFichier == cni)
            {
                return ligne;
            }
        }
    }
    else
        cout << "  Impossible d'ouvrir le fichier" << endl;
}

int Evaluation::retourneNbreAdmis()
{
    string decision;
    double moyenne;
    int cni,nbreAdmis=0;
    ifstream fichierResultat("resultat.txt",ios::in);
    if(fichierResultat)
    {
        while(fichierResultat >> cni)
            {
                fichierResultat.get();
                fichierResultat.get();
                fichierResultat >> moyenne;
                fichierResultat.get();
                fichierResultat.get();
                fichierResultat >> decision;
                if(decision == "ADMIS")
                {
                    nbreAdmis++;
                }

            }

    }
    else
        cout << "  Impossible d'ouvrir le fichier" << endl;
        return nbreAdmis;

}

void Evaluation::afficheMerite()
{
    int informateur=0;
    int tailleTableau = retourneNbreAdmis();
    int tailleTableauVrai = tailleTableau;
    string tabInformations[tailleTableau],decision,infoCandidat,auxInfo;
    double tabMoyenne[tailleTableau],moyenne,aux;
    int cni,i=0,j=0,k=0,m=1,taille;
    ifstream fichierResultat("resultat.txt",ios::in);
    if(fichierResultat)
    {
        while(fichierResultat >> cni)
            {
                fichierResultat.get();
                fichierResultat.get();
                fichierResultat >> moyenne;
                fichierResultat.get();
                fichierResultat.get();
                fichierResultat >> decision;
                if(decision == "ADMIS")
                {
                    informateur++;
                    infoCandidat = retourneAfficheMerite(cni);
                    tabMoyenne[i] = moyenne;
                    tabInformations[i] = infoCandidat;
                    i++;
                }


            }

    }
    else
        cout << "  Impossible d'ouvrir le fichier" << endl;


        if(tailleTableauVrai > 1)
        {
             do
            {

                for(i=0; i<= tailleTableau-2; i++)
                {
                    if (tabMoyenne[i]<tabMoyenne[i+1])
                    {
                        aux = tabMoyenne[i];
                        tabMoyenne[i] = tabMoyenne[i+1];
                        tabMoyenne[i+1] = aux;

                        auxInfo = tabInformations[i];
                        tabInformations[i] = tabInformations[i+1];
                        tabInformations[i+1] = auxInfo;
                    }
                }
                    tailleTableau = tailleTableau-1;

		    }while(tailleTableau != 1);
        }




		    for(j=0;j<tailleTableauVrai;j++)
            {
                cout << endl;
                cout << "  " << m << "e " << "- "; m++;
                int taille = tabInformations[j].size();
                for(k=0;k<taille-3;k++)
                {
                    if(tabInformations[j][k] != ';')
                    cout << tabInformations[j][k];
                    else if(tabInformations[j][k] == ';')
                        cout << " ";
                }
                cout << "   ";
                cout << tabMoyenne[j] << "/20" << endl;
            }
            if(informateur == 0)
               {
                    cout << endl;
                    cout << "  ********************PAS DE CANDIDAT ADMIS************************" << endl;
               }
}

void Evaluation::saisirEvaluation()
{
    Evaluation b;
    string cniRecue,noteNouvelle,code,choix;
    string code_de_matiere,resteLigne;

    int tailleCniRecue,tailleNoteNouvelle,cni,j,i,compteur=0,compt=0,guide=0,guide2=0,aide=0;
    double noteFinale;

        cout << endl;
        cout << "               ------------------------------------------------------" << endl;//design
        cout << "               ***ICI VOUS SAISISSEZ LES NOTES D'UN CANDIDAT*** " << endl;//affichage pour orienter l'utilisateur
        cout << "               -------------------------------------------------------\n\n" << endl;//design


    do
    {
        cout << endl;
        cout << "           LES DIFFERENTS CODE DE MATIERE ENREGISTRES EN BASES DE DONNEES SONT LES SUIVANTES : " << endl ;
        cout << "           ---------------------------------------------------------------------------------   " << endl<< endl;
        ifstream fichierMatiere("Matiere.txt",ios::in);
        if(fichierMatiere)
           {
                while(fichierMatiere >> code_de_matiere)
                {
                    getline(fichierMatiere,resteLigne);
                    cout << "  " <<code_de_matiere << " ; " ;
                }
           }
        else
        cout <<"  Impossible d'ouvrir le fichier" << endl;
        cout << endl << endl;
        cout << "     ET VOUS DEVEZ ENTRER 10(DIX) DE CES CODES EN ENTRANT A CHAQUE FOIS LA NOTE OBTENUE AU CODE DE MATIERE CORRESPONDANT " << endl;
        //Et vous devez entrer 10(dix) de ces codes en entrant a chaque fois la note obtenue au code de matiere correspondant
        string tabCode[10];
        cout << endl;
        cout << "  Veuillez entrez votre numero de CNI \t";
        getline(cin,cniRecue);
       do
       {
           aide = 0;

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
            flux >> cni;


         if(VerificationCni(cni) && !VerificationCniEva(cni))
         {

             b.NCIN = cni;
            cout << endl;
            cout << "  Entrez les codes et notes des matieres \n";
            int guide = 1;
            for(i = 0; i<10;i++)
            {
                cout << endl;
                cout << "  Entrez le code " << i+1 << ":\t";
                getline(cin,code);
                do
                {
                    do
                    {
                        if (VerificationCode(code))
                        {

                                for(j=0;j<10;j++)
                                {
                                    if(tabCode[j] == code)
                                    {
                                        compt++;
                                        guide2 =1;

                                    }
                                }

                                if(compt>0)
                                {
                                    cout << endl;
                                    cout << "  ERREUR !!! Vous avez deja eu a entrer ce code de matiere precedement!!! " << endl;
                                    cout << "  Veuillez entrer un autre code \t";
                                    getline(cin,code);
                                    compt = 0;
                                    guide2 = 1;
                                }
                                else
                                {
                                    guide2 = 0;
                                }

                        }
                         else
                        {
                            cout << endl;
                            cout << "  Erreur !!! Ce code n'existe pas parmis les matieres \n";
                            cout << "  Veuillez entrer un code existant parmis les matieres : \t";
                            getline(cin,code);
                            guide2 = 1;
                        }

                    } while(guide2 != 0);

                     b.code[i] = code;
                     tabCode[i] = code;
                     guide = 0;

                }while(guide != 0);
                  guide = 1;
                    cout << endl;
                    cout << "  Entrez la note " << i+1 << ": \t";
                        getline(cin,noteNouvelle);

                        do
                        {
                            tailleNoteNouvelle = noteNouvelle.size();

                            for(j=0;j<tailleNoteNouvelle;j++)
                            {
                                if(noteNouvelle[j] != '1' && noteNouvelle[j] != '2' && noteNouvelle[j] != '3' && noteNouvelle[j] != '4' && noteNouvelle[j] != '5' && noteNouvelle[j] != '6' && noteNouvelle[j] != '7' && noteNouvelle[j] != '8' && noteNouvelle[j] != '9' && noteNouvelle[j] != '0' && noteNouvelle[j] != '.')
                                {
                                    compteur++;
                                    aide =1;
                                }
                            }
                            istringstream isssf(noteNouvelle);
                            isssf >> noteFinale;

                            if(compteur>0 || noteFinale <0 || noteFinale >20)
                            {
                                cout << endl;
                                cout << "  ERREUR !!!  !!! " << endl;
                                cout << "  Veuillez entrer une note valide et au plus egale a 20 : \t";
                                getline(cin,noteNouvelle);
                                compteur = 0;
                                aide = 1;
                            }
                            else
                            {
                                aide = 0;

                            }


                        }  while(aide != 0);

                 b.note[i] = noteFinale;

            }
         }
         else
         {
             if(!VerificationCni(cni))
             {
                cout << endl;
                cout << "  Erreur !!! candidat introuvable !!!" << endl;
                cout << "  Veuillez entrer un numero de CNI d'un candidat existant \t";
                getline(cin,cniRecue);
                aide = 1;
             }
             else if(VerificationCniEva(cni))
             {
                 cout << endl;
                 cout << "  Erreur !!! le numero de CNI que vous avez entre possede deja des notes !!!" << endl;
                 cout << "  Veuillez entrer un autre numero de CNI \t";
                 getline(cin,cniRecue);
                 aide = 1;
             }

         }
      }while(aide != 0);
      ajouterEvaluation(b); // ajout des informations d'une evaluation dans le fichier evaluation.txt

        cout << endl;
        cout << "  AJOUT REUSSI DES NOTES DU CANDIDAT DE NUMERO DE CNI: " <<  b.NCIN << endl << endl;
        cout << "  Voulez-vous ajouter d'autres notes ?? "<< endl;
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
            cout << "               ***ICI VOUS SAISISSEZ LES NOTES D'UN CANDIDAT*** " << endl;//affichage pour orienter l'utilisateur
            cout << "               -------------------------------------------------------\n\n" << endl;//design
        }

    }while (choix == "1");



}

void Evaluation::ajouterEvaluation(Evaluation b)
{

     ofstream fichierEvaluation("Evaluation.txt", ios::app | ios::out); // ouverture en écriture avec effacement du fichier ouvert

    if(fichierEvaluation)
    {
        for(int i=0;i<10;i++)
        {
             fichierEvaluation << b.NCIN << ";" << b.code[i] << " ;" << b.note[i] << endl;
        }

        fichierEvaluation.close();
    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}


bool Evaluation::VerificationCniEva(int cni)
{
    string resteLigne;
    int cni2;
    ifstream fichier("Evaluation.txt", ios::in); // ouverture en écriture avec effacement du fichier ouvert

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

bool Evaluation::VerificationCodeEva(int cni,string code)
{
    string code2;
    double note;
    int cni2;
    ifstream fichier("Evaluation.txt", ios::in); // ouverture en écriture avec effacement du fichier ouvert

    if(fichier)
    {

       while(fichier >> cni2)
       {
           fichier.get();
           fichier >> code2;
           fichier.get();
           fichier.get();
           fichier >> note;

            if ((cni2 == cni) && (code2 == code))
           {
               return true;
           }


       }
       return false;

    }
    else
    cerr << "Impossible d'ouvrir le fichier !" << endl;

}






