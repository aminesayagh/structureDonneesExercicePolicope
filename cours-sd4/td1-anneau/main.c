
#include <stdlib.h>
#include <stdio.h>

typedef struct _Cellule *Cellule;
#define TAILLE_MAX 100

struct _Cellule {
    int val;
    Cellule suivant;
};

Cellule remplirAnneau(int tabElement[], int nombreElement)
{
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    cellulePremier->val = tabElement[0];
    cellulePremier->suivant = celluleCourant;

    for (int i = 1; i < nombreElement; i++)
    {
        Cellule celluleSuivant = (Cellule)malloc(sizeof(Cellule));
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = celluleSuivant;
        celluleCourant = celluleSuivant;
    }

    celluleCourant->suivant = cellulePremier;

    return cellulePremier;
}

void afficherAnneau(Cellule premier)
{
    Cellule celluleCourant = premier;
    if(celluleCourant != NULL){
        do{
            printf("%d -> ", celluleCourant->val);
            celluleCourant = celluleCourant->suivant;
        }while(celluleCourant != premier);
    }
    printf("NULL\n");
}



int main(){
    int nombreElement;
    int tableauElement[TAILLE_MAX];
    printf("nombre de case du tableau: ");
    scanf("%d", &nombreElement);

    for (int i = 0; i < nombreElement; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &tableauElement[i]);
    }

    Cellule cellulePremier = remplirAnneau(tableauElement, nombreElement);

    afficherAnneau(cellulePremier);
    
    return 0;
}