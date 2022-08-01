#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED
using namespace std;

class Matiere
{
 private:
     string code;
     string libelle;
     double coefficient;
 public:
     void saisirMatiere();//fonction permettant d'enregistrer les informations d'une nouvelle matiere
     void ajouterMatiere(Matiere m);//fonction permettant d'ecrire les informations d'une matiere dans le fichier matiere.txt
     bool VerifieCode(string code); //fonction permettant de verifier qu'un code de matiere se trouve dans le fichier matiere.txt
     void supprimerMatiere(string code); //fonction permettant de supprimer les informations d'une matiere
     void modifierMatiere(); //fonction permettant de modifier les informations d'une matiere
};

#endif // MATIERE_H_INCLUDED
