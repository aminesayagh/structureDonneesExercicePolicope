#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_CARACTER 100

typedef struct _Etudiant *Etudiant;

struct _Etudiant{
    char cne[TAILLE_MAX_CARACTER];
    int validationS3;
    int validationS4;
    int nombreLivresEmprunter;
    Etudiant suivant;
};

Etudiant creerEtudiant(){
    char cne[TAILLE_MAX_CARACTER];
    Etudiant etudiantCourant = (Etudiant)malloc(sizeof(Etudiant));

    printf("cne d'etudiant : ");
    scanf("%d", cne);
    strcpy(etudiantCourant->cne, cne);
    
    printf("Resultat validation s3 : ");
    scanf("%d", &etudiantCourant->validationS3);

    printf("Resultat validation s4 : ");
    scanf("%d", &etudiantCourant->validationS4);

    printf("Nombre livres emprunter : ");
    scanf("%d", &etudiantCourant->nombreLivresEmprunter);
    return etudiantCourant;
}

Etudiant ajouterEtudiantPremier(Etudiant premier, Etudiant nouveauEtudiant){
    Etudiant etudiantCourant = nouveauEtudiant;
    etudiantCourant->suivant = premier;
    premier = etudiantCourant;

    return premier;
}

Etudiant creerListEtudiant(){
    int nombreEtudiant = 0;
    Etudiant etudiantPremier = (Etudiant)malloc(sizeof(Etudiant));

    printf("Nombre d'etudiant a saisir");
    scanf("%d", &nombreEtudiant);

    for(int i = 0;i < nombreEtudiant; i++){
        printf("Definir l'etudiant %d : ", i + 1);
        etudiantPremier = ajouterEtudiantPremier(etudiantPremier, creerEtudiant());
    }
    return etudiantPremier;
}

int nombreLivresMax(Etudiant premier){
    int nombreLivreMax = 0;
    Etudiant etudiantCourant = creerListEtudiant();

    while(etudiantCourant != NULL){
        if(etudiantCourant->nombreLivresEmprunter > nombreLivreMax){
            nombreLivreMax = etudiantCourant->nombreLivresEmprunter;
        }
        etudiantCourant = etudiantCourant->suivant;
    }

    return nombreLivreMax;
}

Etudiant etudiantAvecMaxLivreEmprunter(Etudiant premier){
    int nombreLivreMax = 0;
    Etudiant premierEtudiantMaxLivres = (Etudiant)malloc(sizeof(Etudiant));
    nombreLivreMax = nombreLivresMax(premier);

    Etudiant etudiantCourant = premier;

    while(etudiantCourant != NULL){
        if(etudiantCourant->nombreLivresEmprunter == nombreLivreMax){
            premierEtudiantMaxLivres = ajouterEtudiantPremier(premierEtudiantMaxLivres, etudiantCourant);
        }

        etudiantCourant = etudiantCourant->suivant;
    }

    return premierEtudiantMaxLivres;
}


