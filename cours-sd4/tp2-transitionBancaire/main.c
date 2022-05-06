#include <stdlib.h>
#include <stdio.h>

typedef struct _Transition *Transition;
typedef struct _Emetteur *Emetteur;

#define TAILLE_MAX 100

struct _Transition{
    int emetteur;
    int destinataire;
    float montant;
    Transition suivant;
};

struct _Emetteur{
    int emetteur;
    float montant;
    Emetteur suivant;
};

Emetteur rechercheEmetteur(Emetteur emetteurPremier, int emetteur){
    Emetteur emetteurCourant = emetteurPremier;
    while(emetteurCourant != NULL){
        if(emetteurCourant->emetteur == emetteur){
            return emetteurCourant;
        }
        emetteurCourant = emetteurCourant->suivant;
    }
    return NULL;
}

Emetteur creerListEmetteurTransition(Transition transitionPremier){
    Emetteur emetteurCourant = (Emetteur)malloc(sizeof(Emetteur));
    Emetteur emetteurPremier = emetteurCourant;

    Transition transitionCourant = transitionPremier;

    while(transitionCourant != NULL){
        Emetteur emetteurExist = rechercheEmetteur(emetteurPremier, transitionCourant->emetteur);
        
        if(emetteurExist != NULL){
            emetteurExist->montant += transitionCourant->montant;
        }else{
            Emetteur nouveauEmetteur = (Emetteur)malloc(sizeof(Emetteur));
            nouveauEmetteur->emetteur = transitionCourant->emetteur;
            nouveauEmetteur->montant = transitionCourant->montant;
            nouveauEmetteur->suivant = emetteurPremier;
            emetteurPremier = nouveauEmetteur;
        }

        transitionCourant = transitionCourant->suivant;
    }


    return emetteurPremier;
}

Emetteur emetteurDuPlusGrandMontant(Emetteur emetteurPremier){
    Emetteur emetteurCourant = emetteurPremier;
    Emetteur emetteurAvecPlusGrandMontant = emetteurPremier;

    while(emetteurCourant != NULL){
        if(emetteurCourant->montant > emetteurAvecPlusGrandMontant->montant){
            emetteurAvecPlusGrandMontant = emetteurCourant;
        }
    }

    return emetteurAvecPlusGrandMontant;
}