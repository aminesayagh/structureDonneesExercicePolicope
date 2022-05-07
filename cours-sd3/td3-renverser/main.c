#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Cellule *Cellule;

struct _Cellule
{
    int val;
    Cellule suivant;
};

Cellule creationListEnPremier(int tabElement[], int nombreElement)
{
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));
    for (int i = 0; i < nombreElement; i++)
    {
        Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = cellulePremier;
        cellulePremier = celluleCourant;
    }

    return cellulePremier;
}

// 1 2 3 4 5 6



// 2 1 3 4 5 6

// 2 3 1 4 5 6

// 2 3 4 1 5 6

// 2 3 4 5 1 6

// 2 3 4 5 6 1


// 3 2 4 5 6 1

// 3 4 2 5 6 1

// 3 4 5 2 6 1

// 3 4 5 6 2 1


// 4 3 5 6 2 1

// 4 5 3 6 2 1

// 4 5 6 3 2 1


// 5 4 6 3 2 1

// 5 6 4 3 2 1


// 6 5 4 3 2 1

int calculLongeurList(Cellule premier){
    int longeur = 0;
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant= premier;

    while(celluleCourant != NULL){
        longeur++;
        celluleCourant = celluleCourant->suivant;
    }
    longeur--;
    return longeur;
}

void afficherList(Cellule premier)
{
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant = premier;
    while (celluleCourant != NULL)
    {
        printf("%d -> ", celluleCourant->val);
        celluleCourant = celluleCourant->suivant;
    }
    printf("NULL\n");
}

Cellule inverseCellule(Cellule celluleAvant){
    Cellule celluleCourant = celluleAvant->suivant;
    Cellule celluleSuivant = celluleAvant->suivant->suivant;
    
    celluleCourant->suivant = celluleAvant;
    celluleAvant->suivant = celluleSuivant;
    return celluleCourant;
}
Cellule inverserList(Cellule premier){
    int nombreInversion = 0;
    nombreInversion = calculLongeurList(premier);
    int nombreNav = nombreInversion;
    printf("n: %d \n",nombreInversion);
    for(int i = 1; i < nombreNav; i++){
        premier =  inverseCellule(premier);
        Cellule celluleAvant = premier;
        Cellule celluleCourant = celluleAvant->suivant;
        nombreInversion--;
        for(int j = 1; j < nombreInversion && celluleCourant->suivant->suivant != NULL; j++){
            celluleAvant->suivant = inverseCellule(celluleCourant);
            celluleAvant = celluleAvant->suivant;
            celluleCourant = celluleAvant->suivant;
        }
        afficherList(premier);
    }
    
    return premier;
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

    Cellule cellulePremier = creationListEnPremier(tableauElement, nombreElement);

    printf("avant: ");
    afficherList(cellulePremier);
    
    Cellule nouvelleCellulePremier = inverserList(cellulePremier);

    printf("apres: ");
    afficherList(nouvelleCellulePremier);



    return 0;
}