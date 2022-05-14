#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _Nombre *Num;

struct _Nombre{
    int val;
    Num suivant;
};

Num ajouterCaseEnPremier(Num premier, int nouvelleValeur){
    Num nombreCourant = (Num)malloc(sizeof(Num));
    nombreCourant->val = nouvelleValeur;
    nombreCourant->suivant = premier;
    premier = nombreCourant;

    return premier;
}

Num creerListeNombre(){
    int nombreCases = 0, valeur = 0;
    Num nombrePremier = (Num)malloc(sizeof(Num));

    printf("Nombre de case a remplir : ");
    scanf("%d", &nombreCases);

    for(int i = 0; i < nombreCases; i++){
        printf("definise la %d valeur du numero : ", i + 1);
        scanf("%d", &valeur);

        nombrePremier = ajouterCaseEnPremier(nombrePremier, valeur);

    }

    return nombrePremier;
}

Num categoriserLesNombres(Num premier){
    Num nombreCourant = premier;
    Num premierNombrePair = (Num)malloc(sizeof(Num));
    Num premierNombreImpair = (Num)malloc(sizeof(Num));
    
    while(nombreCourant != NULL){
        if(nombreCourant->val % 2 == 0){
            ajouterCaseEnPremier(premierNombrePair, nombreCourant->val);
        }else {
            ajouterCaseEnPremier(premierNombreImpair, nombreCourant->val);
        }
        nombreCourant = nombreCourant->suivant;
    }
    

}

int main(){
    Num nombrePremier = creerListeNombre();
}