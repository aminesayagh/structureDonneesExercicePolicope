#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_CARACTER 100

typedef struct _Mot *Mot;
typedef struct _Page *Page;
struct _Mot{
    char mot[TAILLE_MAX_CARACTER];
    Page premier;
    Mot filsGauche;
    Mot filsDroit;
};

struct _Page{
    int num;
    Page suivant;
};

Mot creerMot(Page *premierPage, char motAjouter){
    Mot nouvelleMot = (Mot)malloc(sizeof(Mot));

    nouvelleMot->premier = *premierPage;

    nouvelleMot->filsGauche = NULL;
    nouvelleMot->filsDroit = NULL;

    return nouvelleMot;
}

void ajouteMot(Mot *motSommet, Page *pagePremier, char motAjouter[]){
    if(*motSommet != NULL){
        if(strcmp(&(*motSommet)->mot, motAjouter) > 0){
            if((*motSommet)->filsGauche != NULL){
                ajouteMot((*motSommet)->filsGauche, pagePremier, motAjouter);
            }else{
                (*motSommet)->filsGauche = creerMot(pagePremier, motAjouter);
            }
        }else if(strcmp(&(*motSommet)->mot, pagePremier) < 0){
            if((*motSommet)->filsGauche != NULL){
                ajouteMot((*motSommet)->filsDroit, pagePremier, motAjouter);
            }else{
                (*motSommet)->filsDroit = creerMot(pagePremier, motAjouter);
            }
        }
    }
}

