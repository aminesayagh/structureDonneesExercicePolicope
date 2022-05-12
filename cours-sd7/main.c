#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_TABLE 100

typedef struct _NouedBinaire *NouedBinaire;

struct _NouedBinaire {
    int val;
    NouedBinaire filsGauche;
    NouedBinaire filsDroit;
};

NouedBinaire initialiserArbreBinaire(int valeur){
    NouedBinaire noeudCourannt =  (NouedBinaire)malloc(sizeof(NouedBinaire));

    if(valeur == NULL) return NULL;

    noeudCourannt->val = valeur;
    noeudCourannt->filsGauche = NULL;
    noeudCourannt->filsDroit = NULL;

    return noeudCourannt;
}



NouedBinaire ajouteArbreBinaire(){
    int nouvelleValeur = 0, nouveauNoeud;
    printf("Ajoute Nouvelle Noeud: ");
    scanf("%d", &nouvelleValeur);

    NouedBinaire noeudCourannt = initialiserArbreBinaire(nouvelleValeur);

    printf("Voulez vous ajouter un noeud gauche du parent %d: \n", nouvelleValeur);
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d", &nouveauNoeud);

    if(nouveauNoeud == 1){
        noeudCourannt->filsGauche = ajouteArbreBinaire();
    }

    printf("Voulez vous ajouter un noeud droit du parent %d: \n", nouvelleValeur);
    printf("1- Oui\n");
    printf("2- Non\n");
    scanf("%d", &nouveauNoeud);

    if(nouveauNoeud == 1){
        noeudCourannt->filsDroit = ajouteArbreBinaire();
    }

    return noeudCourannt;
}

void afficherArbreBinaire(NouedBinaire sommet){
    printf("Valeurs: %d", sommet->val);

    printf("Fils: \n");
    printf("Premier: \n");
    afficherArbreBinaire(sommet->filsGauche);

    printf("Dernier: \n");
    afficherArbreBinaire(sommet->filsDroit);
}

int tailleArbreBinaire(NouedBinaire sommet){
    if(sommet != NULL){
        return 1 + tailleArbreBinaire(sommet->filsGauche) + tailleArbreBinaire(sommet->filsDroit);
    } else {
        return 0;
    }
}

int nombreFeuilleArbreBinaire(NouedBinaire sommet){
    if(sommet == NULL){
        return 0;
    }

    if(sommet->filsGauche == NULL && sommet->filsDroit == NULL){
        return 1;
    }

    return nombreFeuilleArbreBinaire(sommet->filsGauche) + nombreFeuilleArbreBinaire(sommet->filsDroit);
}

int hauteurArbreBinaire(NouedBinaire sommet){
    int hauteurFilsDroit, hauteurFilsGauche;
    if(sommet == NULL){
        return 0;
    }

    hauteurFilsDroit = hauteurArbreBinaire(sommet->filsDroit) + 1;
    hauteurFilsGauche = hauteurArbreBinaire(sommet->filsGauche) + 1;
    
    if(hauteurFilsDroit > hauteurFilsGauche){
        return hauteurFilsDroit;
    }else{
        return hauteurFilsGauche;
    }
}

NouedBinaire rechercheArbreBinaire(NouedBinaire sommet, int valeurRechercher){
    NouedBinaire noeudRechercher = NULL;
    if(sommet == NULL) return NULL;

    if(sommet->val == valeurRechercher){
        return sommet;
    }else{
        noeudRechercher = rechercheArbreBinaire(sommet->filsGauche, valeurRechercher);
        if(noeudRechercher == NULL){
            noeudRechercher = rechercheArbreBinaire(sommet->filsDroit, valeurRechercher);
        }
    }

    return noeudRechercher;
}

NouedBinaire rechercheArbreBinaireDeRecherche(NouedBinaire sommet, int valeurRechercher){
    if(sommet == NULL) return NULL;

    if(sommet->val == valeurRechercher){
        return sommet;
    } else if(sommet->val > valeurRechercher){
        return rechercheArbreBinaireDeRecherche(sommet->filsGauche, valeurRechercher);
    } else if(sommet->val < valeurRechercher){
        return rechercheArbreBinaireDeRecherche(sommet->filsDroit, valeurRechercher);
    }
}

void ajouterNoeud(NouedBinaire sommet, int valeurAjouter){
    if(sommet != NULL){
        ajouterValeurArbreBinaire(sommet->filsGauche, valeurAjouter);
    }else {
        sommet->filsGauche = initialiserArbreBinaire(valeurAjouter);
    }
}

void ajouterValeurArbreBinaire(NouedBinaire sommet, int valeurAjouter){
    if(sommet != NULL){
        if(sommet->val > valeurAjouter){
            ajouterNoeud(sommet->filsGauche, valeurAjouter);
        }else if(sommet->val < valeurAjouter) {
            ajouterNoeud(sommet->filsDroit, valeurAjouter);
        }
    }
}

int remplirTableau(){
    int nombreCases;
    int tab[TAILLE_MAX_TABLE];
    printf("definiser le nombre des cases du tableau ");
    scanf("%d", &nombreCases);

    for(int i = 0; i < nombreCases; i++){
        printf("Rempliser %d case : ", i + 1);
        scanf("%d", tab[i]);
    }
    return tab;
}

NouedBinaire convertirTableauEnABR(int tab[], int tailleTab){
    NouedBinaire noeudNouveau = initialiserArbreBinaire(tab[0]);
    for(int i = 1; i < tailleTab; i++){
        ajouterValeurArbreBinaire(noeudNouveau, tab[i]);
    }
    return noeudNouveau;
}

void convertirArbreABREnTabTrie(NouedBinaire sommet, int tabTrier[], int caseVide){
    // parcours infixe
    convertirArbreABREnTabTrie(sommet->filsGauche, tabTrier, caseVide);
    tabTrier[caseVide] = sommet->val;
    caseVide++;
    convertirArbreABREnTabTrie(sommet->filsGauche, tabTrier, caseVide);
};

void trieTableau(int tab[], int tailleTab){
    int tabTrier[TAILLE_MAX_TABLE];
    NouedBinaire sommet = convertirTableauEnABR(tab , tailleTab);

    convertirArbreABREnTabTrie(sommet , tabTrier, 0); // parcour infixe
}

void minMaxABR(NouedBinaire sommet ,int *min, int *max){
    if(sommet != NULL){
        minMaxABR(sommet->filsGauche ,min, max);
        if(min == NULL) *min = sommet->val;
        minMaxABR(sommet->filsDroit, min, max);
        if(max == NULL) *max = sommet->val;
    }
}

void supprimerNoeud(NouedBinaire *sommet, int val){
    NouedBinaire tmp;
    if(*sommet != NULL){
        // rechercher
        if(val < (*sommet)->val) supprimerNoeud(&(*sommet)->filsGauche, val);
        else if(val > (*sommet)->val) supprimerNoeud(&(*sommet)->filsDroit, val);
        else {
            // supprimer
            if((*sommet)->filsDroit == NULL){
                *sommet = (*sommet)->filsGauche;
            } else if((*sommet)->filsGauche == NULL) {
                *sommet = (*sommet)->filsDroit;
            } else {
                tmp = noeudMax(sommet->);
            }
        }
    }
}

int main() {
    NouedBinaire sommetArbre = ajouteArbreBinaire();
    afficherArbreBinaire(sommetArbre);    
}