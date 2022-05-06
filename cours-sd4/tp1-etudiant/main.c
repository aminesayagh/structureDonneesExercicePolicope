#include <stdlib.h>
#include <stdio.h>

typedef struct _Etudiant *Etudiant;

#define TAILLE_MAX 100

struct _Etudiant {
    int cne;
    int resultS1;
    int resultS2;
    Etudiant suivant;
};

int calculNombreEtudiantValiderIterative(Etudiant premier){
    Etudiant etudiantCourant = premier;
    int nombreEtudiantValider = 0;

    while(etudiantCourant != NULL){
        if(etudiantCourant->resultS1 > 10 && etudiantCourant->resultS2 > 10){
            nombreEtudiantValider++;
        }
        etudiantCourant = etudiantCourant->suivant;
    }
}

int calculNombreEtudiantValiderRecursive(Etudiant etudiant){
    if(etudiant == NULL) return 0;
    if(etudiant->resultS1 >= 10 && etudiant->resultS2 >= 10){
        return 1 + calculNombreEtudiantValiderRecursive(etudiant->suivant);
    }
    return calculNombreEtudiantValiderRecursive(etudiant->suivant);
}


Etudiant etudiantsValidentSectionDeuxUniquement(Etudiant premier){
    Etudiant etudiantCourant = premier;

    Etudiant etudiantValidantPremier = (Etudiant)malloc(sizeof(Etudiant));
    while(etudiantValidantPremier != NULL){
        if(etudiantCourant->resultS2 >= 10 && etudiantCourant->resultS1 < 10){
            Etudiant etudiantValidCourant = (Etudiant)melloc(sizeof(Etudiant));

            etudiantValidCourant->cne = etudiantCourant->cne;
            etudiantValidCourant->resultS1 = etudiantCourant->resultS1;
            etudiantValidCourant->resultS2 = etudiantCourant->resultS2;
            etudiantValidCourant->suivant = etudiantValidantPremier;

            etudiantValidantPremier = etudiantValidCourant;
        }
    }
    return etudiantValidantPremier;
}