#include <stdlib.h>
#include <stdio.h>


typedef struct _Noeud *Arbre;
typedef struct _NoeudBinaire *ArbreBinaire;

struct _Noeud {
    int val;
    int nombreFils;
    Arbre fils[100];
};

struct _NoeudBinaire {
    int val;
    ArbreBinaire premierFils;
    ArbreBinaire dernierFils;
};

Arbre ajouteArbreNAire(){
    Arbre arbreCourant = (Arbre)malloc(sizeof(Arbre));

    printf("Definiser la valeur de la Nouvelle branche: ");
    scanf("%d", &arbreCourant->val);

    printf("definiser le nombre de fils pour cette arbre parent (0 pour aucun): ");
    scanf("%d", &arbreCourant->nombreFils);

    for(int i = 0 ; i < arbreCourant->nombreFils; i++){
        printf("fils %d\n", i + 1);
        arbreCourant->fils[i] = ajouteArbreNAire();
        printf("\n");
    }
    printf("\n");
    return arbreCourant;
}

void afficherArbreNAire(Arbre sommet) {
    printf("valeurs: %d\n", sommet->val);

    printf("fils: \n");
    for(int i = 0; i < sommet->nombreFils; i++){
        afficherArbreNAire(sommet->fils[i]);
        printf("\n");
    }
}

void afficherArbreBinaire(ArbreBinaire sommet){
    printf("valeurs: %d", sommet->val);

    printf("fils: \n");
    printf("premier: \n");
    afficherArbreBinaire(sommet->premierFils);

    printf("dernier: \n");
    afficherArbreBinaire(sommet->dernierFils);

}

ArbreBinaire creeArbreBinaire(int valeur){
    ArbreBinaire noeudCourant = (ArbreBinaire)malloc(sizeof(ArbreBinaire));

    noeudCourant->val = valeur;
    noeudCourant->premierFils = NULL;
    noeudCourant->dernierFils = NULL;

    return noeudCourant;
}

ArbreBinaire lierBrancheArbreBinaire(ArbreBinaire premierFils, ArbreBinaire dernierFils, ArbreBinaire parent){
    parent->premierFils->val = premierFils->val;
    parent->dernierFils->val = dernierFils->val;

    return parent;
}

ArbreBinaire convertirArbreNAireEnBinaire(Arbre sommetArbreNAire, Arbre frereArbreNAire, int valeurSommet){
    ArbreBinaire sommet = (ArbreBinaire)malloc(sizeof(ArbreBinaire));

    sommet->val = valeurSommet;
    // premier etage
    sommet = lierBrancheArbreBinaire(sommetArbreNAire->fils[0], frereArbreNAire, sommet);
    sommet->premierFils = convertirArbreNAireEnBinaire(sommetArbreNAire->fils[0], sommetArbreNAire->fils[1], &sommetArbreNAire->val);
    return sommet;
}

int main(){
    printf("remplir arbre n-aire: \n");
    Arbre sommetArbreNAire = ajouteArbreNAire();

    afficherArbreNAire(sommetArbreNAire);

    ArbreBinaire sommetArbreBinaire = convertirArbreNAireEnBinaire(sommetArbreNAire, NULL, &sommetArbreNAire->val);

    return 0;
}