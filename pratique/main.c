#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100
#define TAILLE_MAX_CARACTER 30

typedef struct _Personne *Personne;
typedef struct _Voiture *Voiture;
typedef struct _Location *Location;

struct _Personne {
    int cin;
    char nom[TAILLE_MAX_CARACTER];
    char prenom[TAILLE_MAX_CARACTER];
};

struct _Voiture {
    int matricule;
    char marque[TAILLE_MAX_CARACTER];
    int prixJour;   
    int dureeLocation;
    Voiture suivant;
};

struct _Location {
    int identificateurLocation;
    Personne client;
    Voiture premierVoitureLouee;
    Location suivant;
};

Personne ajoutPersonne(){
    Personne personne = (Personne)malloc(sizeof(Personne));
    char nom[TAILLE_MAX_CARACTER], prenom[TAILLE_MAX_CARACTER];

    printf("CIN: ");
    scanf("%d", &personne->cin);

    printf("nom: ");
    scanf("%s", nom);
    strcpy(nom, personne->nom);

    printf("prenom: ");
    scanf("%s", prenom);
    strcpy(prenom, personne->prenom);

    printf("\n");

    return personne;
}

Voiture ajoutVoiture(){
    Voiture voiture = (Voiture)malloc(sizeof(Voiture));
    char marque[TAILLE_MAX_CARACTER];

    printf("Matricule : ");
    scanf("%d", &voiture->matricule);

    printf("Marque : ");
    scanf("%s", marque);
    strcpy(voiture->marque, marque);

    printf("Prix par jour: ");
    scanf("%d", &voiture->prixJour);


    printf("Duree Location: ");
    scanf("%d", &voiture->dureeLocation);

    printf("\n");

    return voiture;
}

Location ajoutLocation() {
    Location locationCourant = (Location)malloc(sizeof(Location));
    int nombreVoiture;

    printf("Identificateur localisation: ");
    scanf("%d", &locationCourant->identificateurLocation);

    printf("Client: \n");
    locationCourant->client = ajoutPersonne();

    printf("Voitures louee: \n");

    printf("definiser le nombre de voiture a ajouter: ");
    scanf("%d", &nombreVoiture);

    locationCourant->premierVoitureLouee = ajoutVoiture();

    Voiture voitureCourant = locationCourant->premierVoitureLouee;
    for(int i = 1; i < nombreVoiture; i++){
        voitureCourant->suivant = ajoutVoiture(); // unitil d'allouer dynamic, la fonction ajoute le fait, il nous suffit de recevoir le pointeur
        voitureCourant = voitureCourant->suivant;
    }

    return locationCourant;
}

int calculPrixTotal(Location premier){
    int prixTotal = 0;
    int prixParJour = 0;
    int duree = 0;

    Voiture voitureCourant = premier->premierVoitureLouee;
    while(voitureCourant != NULL){
        prixParJour = voitureCourant->prixJour;
        duree = voitureCourant->dureeLocation;
        prixTotal += prixParJour * duree;
        voitureCourant = voitureCourant->suivant;
    }

    return prixTotal;
}

void enregistrerLocation(Location location) {
    char nomFichier[TAILLE_MAX_CARACTER];
    printf("Definiser le nom du ficher :");
    scanf("%s", nomFichier);

    FILE *fichier = NULL;

    fichier = fopen(nomFichier, "r");


    if(fichier != NULL){
        fscanf(fichier, "Identification de la location : %d ", location->identificateurLocation);
        fscanf(fichier, "Informations sur le client\n");
        Personne personneCourant = location->client;
        fscanf(fichier, "CIN du client : %d\nNom du client : %s\nPrenon du client : %s\n\n", personneCourant->cin, personneCourant->nom, personneCourant->prenom);

        // ................

        fclose(fichier);
    }
}

void afficherListeLocations(Location location){
      // remplacer fscanf par printf 
}

Location rechercherLocation(Location location, char cinClient[]){
    Location locationCourant = location;

    while(locationCourant != NULL){
        Personne clientCourant = locationCourant->client;

        // https://www.programiz.com/c-programming/library-function/string.h/strcmp
        if(strcmp(clientCourant->cin, cinClient) == 0){
            return locationCourant;
        }
    }
    return NULL;
}

void supprimerLocation(Location location){
    int cinClient;
    printf("Identifier le cinClient du location a supprimer");
    scanf("%d",&cinClient);

    Location locationCourant = location;
    Location locationPrecedent = NULL;
    Location locationSupprimer;

    while(locationCourant != NULL){
        if(strcmp(locationCourant->client->cin, cinClient) == 0){
            locationSupprimer = locationCourant;
            if(locationPrecedent == NULL){
                location = locationCourant->suivant;
            }else{
                locationPrecedent->suivant = locationCourant->suivant;
                locationCourant = locationCourant->suivant;
            }
        }
        locationPrecedent = locationCourant;
        locationCourant = locationCourant->suivant;
    }
    free(locationSupprimer);
}

int menuGeneral(){
    // .........
}

int main(){
    printf("ajouter location: \n");
    Location locationCourant = ajoutLocation();
    int prixTotalClient = calculPrixTotal(locationCourant);

    

    return 0;
}