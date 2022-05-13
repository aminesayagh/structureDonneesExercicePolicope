#include <stdlib.h>
#include <stdio.h>

typedef struct _Cellule *Cellule;

struct _Cellule{
    int exposent;
    int coefficient;
    Cellule suivant;
};

Cellule creerCellule(int exposent, int coefficient){
    Cellule nouvelleCellule = (Cellule)malloc(sizeof(Cellule));

    nouvelleCellule->exposent = exposent;
    nouvelleCellule->coefficient = coefficient;
    nouvelleCellule->suivant = NULL;

    return nouvelleCellule;
}



Cellule sommeDeuxPolynome(Cellule premierPolynome1, Cellule premierPolynome2){
    Cellule premierSomme = (Cellule)malloc(sizeof(Cellule));

    Cellule courantPolynome1 = premierPolynome1;
    Cellule courantPolynome2 = premierPolynome2;

    Cellule courantSomme = premierSomme;

    while(courantPolynome1 != NULL || courantPolynome2 != NULL){
        if(courantPolynome1->exposent == courantPolynome2->exposent){
            courantSomme = creerCellule(courantPolynome1->exposent, courantPolynome1->coefficient + courantPolynome2->coefficient);
        }else if(courantPolynome1->exposent > courantPolynome2->exposent){
            courantSomme = creerCellule(courantPolynome1->exposent, courantPolynome1->coefficient);
            courantPolynome1 = courantPolynome1->suivant;
        }else{
            courantSomme = creerCellule(courantPolynome2->exposent, courantPolynome2->coefficient);
            courantPolynome2 = courantPolynome2->suivant;
        }

        courantSomme = courantSomme->suivant;
    }
    return premierSomme;
}

Cellule deriverPolynome(Cellule premierPolynome){
    Cellule celluleCourant = premierPolynome;

    while(celluleCourant != NULL){
        if(celluleCourant->exposent > 0){
            celluleCourant->coefficient*=celluleCourant->exposent;
            celluleCourant->exposent--;
        }else {
            celluleCourant = NULL;
        }
    }

    return premierPolynome;
}