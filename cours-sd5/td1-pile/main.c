#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Cellule *Cellule;

struct _Cellule{
    int val;
    Cellule suivant;
};

void empiler(Cellule premier, int nouveau){
    Cellule celluleNouvelle = (Cellule)malloc(sizeof(Cellule));

    celluleNouvelle->val = nouveau;
    celluleNouvelle->suivant = premier;
    premier = celluleNouvelle;
}

void viderPile(Cellule premier){
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleSuivant = (Cellule)malloc(sizeof(Cellule));
    celluleCourant = premier;
    celluleSuivant = celluleCourant->suivant;
    if(celluleSuivant != NULL) {
        free(celluleCourant);
        celluleCourant = celluleSuivant;
        celluleSuivant = celluleSuivant->suivant;
    }
    free(celluleCourant);
}

int premierPile(Cellule premier){
    return premier->val;
}

void depilerPile(Cellule premier){
    
}

