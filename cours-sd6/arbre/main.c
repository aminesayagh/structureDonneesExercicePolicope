#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Arbre *Arbre;

struct _Arbre{
    int valeur;
    Arbre noeudAvant;
    Arbre noeudApres;
    Arbre noeudParent;
};

Arbre nouvelleArbre(int nouvelleValeur){
    Arbre noeudCourant = (Arbre)malloc(sizeof(Arbre));

    noeudCourant->valeur = nouvelleValeur;
    noeudCourant->noeudAvant = NULL;
    noeudCourant->noeudApres = NULL;
    noeudCourant->noeudParent = NULL;

    return noeudCourant;
}

void supprimerArbre(Arbre noeud){

    if(noeud == NULL) return;
    supprimerArbre(noeud->noeudApres);
    supprimerArbre(noeud->noeudAvant);

    free(noeud);
}

Arbre lierArbre(Arbre avant, Arbre apres, Arbre parent){
    parent->noeudApres = apres;
    parent->noeudAvant = avant;

    apres->noeudParent = parent;
    avant->noeudParent = parent;

    return parent;
}

int main(){
    Arbre parent = lierArbre(nouvelleArbre(2), nouvelleArbre(3), nouvelleArbre(1));

    return 0;
}