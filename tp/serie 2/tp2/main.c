#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Mot *Mot; // list l
typedef struct _Page *Page;

struct _Mot{
      char mot[50];
      Mot suivant;
      Page premier;
};

struct _Page{
      int numPage;
      Page suivant;
};

// l: motPremmier
// LPAGE: pagePremier
void ajouteMot(Mot *motPremier, Page *pagePremier, int motAjouter){

    Mot *motCourant = *motPremier;
    while(*motCourant != NULL){
        if(strcmp(&(*motCourant)->mot, motAjouter) == 0){
            (*motCourant)->premier = pagePremier;
        }
        *motCourant = (*motCourant)->suivant;
    }
}

void supprimerMot(Mot *motPremier, int motSuppimer){
    Mot *motCourant = *motPremier;
    Mot *motSuivant = (*motPremier)->suivant;
    while(*motCourant != NULL){
        if(strcmp(&(*motSuivant)->mot, motSuppimer) == 0){
            (*motCourant)->suivant = motSuivant;
            
        }
        *motCourant = (*motCourant)->suivant;
    }
}