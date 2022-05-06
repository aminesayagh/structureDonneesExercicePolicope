#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Cellule *Cellule;

struct _Cellule
{
    int val;
    int occ;
    Cellule suivant;
};

Cellule rechercheCellule(Cellule premier, int valeurRechercher){
    Cellule celluleCourant = premier;

    while(celluleCourant != NULL){
        if(celluleCourant->val == valeurRechercher){
            return celluleCourant;
        }
        celluleCourant = celluleCourant->suivant;
    }
    return NULL;
}

Cellule listValeurParOccurence(int tableauElement[], int nombreElement){
    Cellule premierElemet = (Cellule)malloc(sizeof(Cellule));

    for(int i = 0; i < nombreElement; i++){
        Cellule celluleExist = rechercheCellule(premierElemet, tableauElement[i]);
        if(celluleExist != NULL){
            celluleExist->occ++;
        }else{
            Cellule nouveauCellule = (Cellule)malloc(sizeof(Cellule));
            nouveauCellule->val = tableauElement[i];
            nouveauCellule->occ = 1;
            nouveauCellule->suivant = premierElemet;
            premierElemet = nouveauCellule;
        }
    }

    return premierElemet;
}

void afficherList(Cellule premier){
        Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

        celluleCourant = premier;
        while(celluleCourant != NULL){
            printf("valeur: %d, occ: %d -> ", celluleCourant->val, celluleCourant->occ);
            celluleCourant = celluleCourant->suivant;
        }
        printf("NULL\n");
    }

int main()
{
    int nombreElement;
    int tableauElement[TAILLE_MAX];
    printf("repliser votre tableau: ");
    scanf("%d", &nombreElement);

    for (int i = 0; i < nombreElement; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &tableauElement[i]);
    }

    Cellule cellulePremier = listValeurParOccurence(tableauElement, nombreElement);
    afficherList(cellulePremier);


    return 0;
}