#include <stdlib.h>
#include <stdio.h>

typedef struct _Cellule *Cellule;

struct _Cellule{
    int val;
    Cellule suivant;
};

Cellule ajouterCaseEnPremier(Cellule premier, int nouvelleValeur){
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant->val = nouvelleValeur;
    celluleCourant->suivant = premier;
    premier = celluleCourant;

    return premier;
}

Cellule creerListNombre(){
    int nombreCases = 0, valeur = 0;
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));

    printf("Nombre de case a remplir : ");
    scanf("%d", &nombreCases);

    for(int i = 0; i < nombreCases; i++){
        printf("definise la %d valeur de la liste : ", i + 1);
        scanf("%d", &valeur);

        cellulePremier = ajouterCaseEnPremier(cellulePremier, valeur);
    }

    return cellulePremier;
}

int rechercherEnList(Cellule premier, int valeur){
    Cellule celluleCourant = premier;

    while(celluleCourant != NULL){
        if(celluleCourant->val == valeur){
            return 1;
        }

        celluleCourant = celluleCourant->suivant;
    }
    return 0;
}

void fusionnerDeuxCellule(){
    Cellule cellulePremierListA = creerListNombre();
    Cellule cellulePremierListB = creerListNombre();

    Cellule celluleCourant = cellulePremierListB;

    while(celluleCourant != NULL){
        if(rechercherEnList(cellulePremierListA, celluleCourant->val) == 1){
            ajouterCaseEnPremier(cellulePremierListA, celluleCourant->val);
        }

        celluleCourant = celluleCourant->suivant;
    }
    return cellulePremierListA;
}