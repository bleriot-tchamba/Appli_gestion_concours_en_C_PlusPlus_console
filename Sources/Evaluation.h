#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include "Candidat.h"
using namespace std;

class Evaluation
{
 private:
     int NCIN;
     string code[10];
     double note[10];
 public:
 int retourneNbreNote(int cni);
 double retourneCoef(string codeMatiere);
 void resultat();
 string retourneAdmis(int cni);
 void admis();
 void admis_sans_affichage();
 void attente();
 void statistique();
 void supprimer();
 bool VerificationCni(int cni);
 bool VerificationCode(string code);
 void modifierNote();
 string retourneAfficheMerite(int cni);
 void afficheMerite();
 int retourneNbreAdmis();
 void saisirEvaluation();
 void ajouterEvaluation(Evaluation e);
 bool VerificationCniEva(int cni);
 bool VerificationCodeEva(int cni,string code);
};


#endif // EVALUATION_H_INCLUDED
