#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_CARACTER 100

typedef struct _Personne *Personne;

// a-
struct _Personne{
    int age;
    char nom[TAILLE_MAX_CARACTER];
    Personne frereDroit;
    Personne premierfils;
};

// b-
int maxHauteur(int valeur1, int valeur2){
    return valeur1 >= valeur2 ? valeur1 : valeur2;
}

int hauteur(Personne pere){
    if(pere == NULL){
        return 0;
    }

    return maxHauteur(1 + hauteur(pere->premierfils), hauteur(pere->frereDroit));
}

Personne filtrerRecherche(Personne *premier, Personne *dexieme){
    return *premier != NULL ? *premier : *dexieme;
}

// c-
Personne rechercheAdress(Personne *pere, char nom[]){
    if(*pere != NULL){
        if(strcmp((*pere)->nom, nom) == 0){
            return pere; // return adress
        }

        return filtrerRecherche(rechercheAdress((*pere)->premierfils, nom), rechercheAdress((*pere)->frereDroit, nom));
    }
}

// d-
int nombrePersonne(Personne pere){
    if(pere == NULL){
        return 0;
    }

    return 1 + nombrePersonne(pere->premierfils, pere->frereDroit);
}

// e-
int rechercherFils(Personne pere, char nomFils[]){
    return rechercheAdress(pere->premierfils, nomFils) != NULL ? 1 : 0;
}

// f-
void naissanceFils(Personne grandPere, Personne *fils, char nomPere[]){
    int filsAjouter = 0;
    Personne *pere = rechercheAdress(grandPere, nomPere);
    Personne *filsCourant = &(*pere)->premierfils;
    if(*filsCourant != NULL){
        do{
            if(&(*filsCourant)->frereDroit == NULL && filsAjouter == 0){
                (*fils)->frereDroit = NULL;
                (*filsCourant)->frereDroit = *fils;
                filsAjouter = 1;
            }
            if(&(*filsCourant)->frereDroit->age > (*fils)->age && filsAjouter == 0){
                (*fils)->frereDroit = (*filsCourant)->frereDroit;
                (*filsCourant)->frereDroit = *fils;
                filsAjouter = 1;
            }
            *filsCourant = (*filsCourant)->frereDroit;
        }while(filsCourant != NULL);
    } else {
        (*pere)->premierfils = *fils;
    }
}