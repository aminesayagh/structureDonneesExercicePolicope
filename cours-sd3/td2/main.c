
#include <stdlib.h>
#include <stdlib.h>

typedef struct _Cellule *Cellule;

struct _Cellule{
    int val;
    Cellule suivant;
};

Cellule creationListEnPremier(int tabValeur[], int tailleTableau){
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));

    cellulePremier->val = tabValeur[0];
    cellulePremier->suivant = NULL;

    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
    celluleCourant->val = tabValeur[1];
    celluleCourant->suivant = cellulePremier;

    cellulePremier = celluleCourant;

    for(int i = 1; i < tailleTableau; i++){
        
        celluleCourant->val = tabValeur[i];
        celluleCourant->suivant = cellulePremier;
        cellulePremier = celluleCourant;
    }

    free(celluleCourant);
    return cellulePremier;
}

Cellule creationListEnDernier(int tabValeur[], int tailleTableau){
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));

    Cellule celluleDernier = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    cellulePremier = celluleDernier;

    celluleDernier->val = tabValeur[0];
    celluleDernier->suivant = celluleCourant;
    for(int i = 1; i < tailleTableau; i++){
        celluleCourant->val = tabValeur[i];
        celluleCourant->suivant = NULL;

        celluleDernier = celluleCourant;
    }

    return cellulePremier;
}

void supprimerCellule(Cellule cellulePremier, int valeurSupprimer){
    Cellule cellulePrecedent = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleSuivant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant = cellulePremier;
    celluleSuivant = celluleCourant->suivant;

    while(celluleCourant != NULL){
        if(celluleCourant->val == valeurSupprimer){
            if(cellulePrecedent == NULL){
                cellulePremier = celluleSuivant; // case premier
            }else {
                cellulePrecedent->suivant = celluleSuivant;
            }
        }
        cellulePrecedent = celluleCourant;
        celluleCourant = celluleSuivant;
        if(celluleSuivant != NULL){
            celluleSuivant = celluleSuivant->suivant; // case
        }
    }
    
    free(cellulePrecedent);
    free(celluleCourant);
    free(celluleSuivant);
}

void afficherList(Cellule premier){
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant = premier;
    while(celluleCourant != NULL){
        printf("%d -> ", celluleCourant->val);
        celluleCourant = celluleCourant->suivant;
    }
}