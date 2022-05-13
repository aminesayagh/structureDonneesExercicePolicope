#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Etudiant *Etudiant;
typedef struct _Livre *Livre;

struct _Etudiant{
    char nom[TAILLE_MAX];

};

struct _Livre{
    char nom[TAILLE_MAX];
    Etudiant etudiantEmpruntent;
    int periodeEmprunte;
    int jourDEmprunte;
    Livre suivant;
};

int emprunte(Livre premier,char nomLivre[], int jour){
    Livre livreCourant = premier;

    while(livreCourant != NULL){
        if(strcmp(livreCourant->nom, nomLivre) == 0) {
            if(livreCourant->periodeEmprunte + livreCourant->jourEmprunte <= jour && livreCourant->etudiantEmpruntent != NULL){
                return 1;
            }else{
                return 0;
            }
        }
        
        livreCourant = livreCourant->suivant;
    }
    return -1;
}

void ajouteLivre(Livre *livrePremier, Livre livreAjouter){
    Livre nouveauLivre = (Livre)malloc(sizeof(Livre));

    nouveauLivre = livreAjouter;

    nouveauLivre->suivant = &(*livrePremier);
    *livrePremier = nouveauLivre;
}

void partageLivreParEmprunte(Livre premier, Livre *livreEmprunter, Livre *livreNonEmprunter) {
    Livre livreCourant = premier;
    int etatLivreEmprunter = 0;

    while(livreCourant != NULL){
        etatLivreEmprunter = emprunte();
        
        if(etatLivreEmprunter == -1){
            printf("livre non existent");
        }else if(etatLivreEmprunter == 1){
            ajouteLivre(&(*livreEmprunter), livreCourant);
        }else{
            ajouteLivre(&(*livreNonEmprunter), livreCourant);
        }

        livreCourant = livreCourant->suivant;
    }
}