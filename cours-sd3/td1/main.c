
#include <stdlib.h>
#include <stdio.h>

typedef struct _Cellule *Cellule;

#define TAILLE_MAX 100
struct _Cellule
{
    int val;
    Cellule suivant;
};

Cellule remplirListEnPremier(int tabElement[], int nombreElement)
{
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));
    for (int i = 0; i < nombreElement; i++)
    {
        Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = cellulePremier;
        cellulePremier = celluleCourant;
    }

    return cellulePremier;
}

Cellule remplirListEnDernier(int tabElement[], int nombreElement)
{
    Cellule cellulePremier = (Cellule)malloc(sizeof(Cellule));
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    cellulePremier->val = tabElement[0];
    cellulePremier->suivant = celluleCourant;

    for (int i = 1; i < nombreElement; i++)
    {
        Cellule celluleSuivant = (Cellule)malloc(sizeof(Cellule));
        celluleCourant->val = tabElement[i];
        celluleCourant->suivant = celluleSuivant;
        celluleCourant = celluleSuivant;
    }

    return cellulePremier;
}

void afficherList(Cellule premier)
{
    Cellule celluleCourant = (Cellule)malloc(sizeof(Cellule));

    celluleCourant = premier;
    while (celluleCourant != NULL)
    {
        printf("%d -> ", celluleCourant->val);
        celluleCourant = celluleCourant->suivant;
    }
    printf("NULL\n");
}
void afficherCellule(Cellule cellule)
{
    printf("valeur cellule %d\n", cellule->val);
}

void supprinerCellule(Cellule premier, int valSupprimer)
{
    Cellule celluleCourant = premier;
    Cellule cellulePrecedent = NULL;
    Cellule celluleSupprimer;

    while (celluleCourant != NULL)
    {
        if (celluleCourant->val == valSupprimer)
        {
            celluleSupprimer = celluleCourant;
            if (cellulePrecedent == NULL)
            {
                premier = celluleCourant->suivant;
            }
            else
            {
                cellulePrecedent->suivant = celluleCourant->suivant;
                celluleCourant = celluleCourant->suivant;
            }
        }
        cellulePrecedent = celluleCourant;
        celluleCourant = celluleCourant->suivant;
    }
    free(celluleSupprimer);
}

Cellule localiserPremierOccurence(Cellule premier, int valeurRechercher)
{
    Cellule celluleCourant = premier;

    while (celluleCourant != NULL)
    {
        if (celluleCourant->val == valeurRechercher)
        {
            return celluleCourant;
        }
        celluleCourant = celluleCourant->suivant;
    }
    return NULL;
}

Cellule localiserDernierOccurence(Cellule premier, int valeurRechercher)
{
    Cellule celluleCourant = premier;

    Cellule dernierOccurance = NULL;

    while (celluleCourant != NULL)
    {
        if (celluleCourant->val == valeurRechercher)
        {
            dernierOccurance = celluleCourant;
        }
        celluleCourant = celluleCourant->suivant;
    }
    return dernierOccurance;
}

int longeurList(Cellule premier)
{
    Cellule celluleCourant = premier;
    int compteurCellule = 0;

    while (celluleCourant != NULL)
    {
        compteurCellule++;
    }

    return compteurCellule;
}

int main()
{
    int nombreElement;
    int tableauElement[TAILLE_MAX];
    printf("nombre de case du tableau: ");
    scanf("%d", &nombreElement);

    for (int i = 0; i < nombreElement; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &tableauElement[i]);
    }

    Cellule cellulePremier = remplirListEnPremier(tableauElement, nombreElement);
    Cellule celluleDernier = remplirListEnDernier(tableauElement, nombreElement);

    supprinerCellule(cellulePremier, tableauElement[0]);
    supprinerCellule(celluleDernier, tableauElement[1]);

    afficherList(cellulePremier);
    afficherList(celluleDernier);

    Cellule premierOccurence = localiserPremierOccurence(celluleDernier, tableauElement[2]);
    afficherCellule(premierOccurence);
    Cellule dernierOccurence = localiserDernierOccurence(celluleDernier, tableauElement[3]);
    afficherCellule(dernierOccurence);

    return 0;
}