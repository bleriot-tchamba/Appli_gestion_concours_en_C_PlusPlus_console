#ifndef CANDIDAT_H_INCLUDED
#define CANDIDAT_H_INCLUDED
#include "Evaluation.h"
using namespace std;

class Candidat
{
private:
    int NCIN;
    string Nom;
    string  Prenom;
    int  Age;
public:
    void saisirCandidat(); //fonction permettant d'enregistrer les informations d'un nouveau candidat
    void ajouterCandidat(Candidat c);//fonction permettant d'ecrire les informations d'un candidat dans le fichier candidat.txt
    bool VerifieCode(string code); //fonction permettant de verifier qu'un code de matiere se trouve dans le fichier matiere.txt
    bool VerifieCni(int cni);//fonction permettant de verifier qu'un numero de cni se trouve dans le fichier candidat.txt
    void supprimerCandidat(int NCNI);//fonction permettant de supprimer les informations d'un candidat
    void modifierCandidat();//fonction permettant de modifier les informations d'un candidat
};


#endif // CANDIDAT_H_INCLUDED
