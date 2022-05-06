
#include <stdlib.h>
#include <stdio.h>

typedef struct _Cellule *Cellule;
#define TAILLE_MAX 100

struct _Cellule {
    int val;
    Cellule avant;
    Cellule suivant;
};

Cellule remplirListEnPremier(int tabElement[], int nombreElement){
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));

    for(int i = 0; i < nombreElement; i++){
        Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = cellulePremier;
        celluleCourant->avant = NULL;
        cellulePremier->avant = celluleCourant;
        cellulePremier = celluleCourant;
    }

    return cellulePremier;
}

Cellule remplirListEnDernier(int tabElement[], int nombreElement){
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleAvant = (Cellule)malloc(sizeof(Cellule));

    cellulePremier->val = tabElement[0];
    cellulePremier->suivant = NULL;
    cellulePremier->avant = NULL;

    celluleAvant = cellulePremier;
    for(int i = 1; i < nombreElement; i++) {
        Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
        celluleAvant->suivant = celluleCourant;
        celluleCourant->avant = celluleAvant;
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = NULL;
        celluleAvant = celluleCourant;
    }
    return cellulePremier;
}

void remplirListEnMillieu(Cellule premier, int elementInserer, int apresValeur){
    Cellule celluleCourant = premier;

    while(celluleCourant != NULL && celluleCourant->val == apresValeur) celluleCourant = celluleCourant->suivant;
    
    Cellule celluleNouvelle = (Cellule)malloc(sizeof(Cellule));

    celluleNouvelle->val = elementInserer;
    celluleNouvelle->suivant = celluleCourant->suivant;
    celluleCourant->suivant->avant = celluleNouvelle;
    celluleNouvelle->avant = celluleCourant;
    celluleCourant->suivant = celluleNouvelle;

}

void supprimerCellule(Cellule premier, int valSupprimer){
    printf("here");
    Cellule celluleCourant = premier;
    Cellule celluleSupprimer;
    

    while(celluleCourant != NULL){
        if(celluleCourant->val == valSupprimer){
            celluleSupprimer = celluleCourant;
            if(celluleCourant->avant == NULL){
                premier = celluleCourant->suivant;
                premier->avant = NULL;
            } else {
                celluleCourant->avant->suivant = celluleCourant->suivant;
                celluleCourant->suivant->avant =  celluleCourant->avant;
            }
            celluleCourant = celluleCourant->suivant;
        }
    }
    free(celluleSupprimer);
}

void afficherList(Cellule premier){
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant = premier;

    while(celluleCourant != NULL){
        printf("%d ->", celluleCourant->val);
        celluleCourant = celluleCourant->suivant;
    }
    printf("NULL\n");
}

int main() {
    int nombreElements;
    int tableauElements[TAILLE_MAX];
    printf("nombre de case du tableau: ");
    scanf("%d", &nombreElements);

    for (int i = 0; i < nombreElements; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &tableauElements[i]);
    }

    Cellule cellulePremier = remplirListEnDernier(tableauElements, nombreElements);
    afficherList(cellulePremier);

    remplirListEnMillieu(cellulePremier, 12, tableauElements[1]);

    afficherList(cellulePremier);
    supprimerCellule(cellulePremier, 12);
    afficherList(cellulePremier);
    
    return 0;
}