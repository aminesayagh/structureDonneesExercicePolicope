#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100

typedef struct _Cellule{
    int val;
    int occ;
} Cellule;

int searchValue(Cellule *tabCellules, int size, int valeurRechercher){
    for(int i = 0; i < size; i++){
        if(tabCellules[i].val == valeurRechercher) return i;
    }
    return -1;
}

int main() {
    int nombreEntier = 0;
    int nombreCellule = 0;
    int celluleExist = -1;
    int tableauEntier[TAILLE_MAX];

    Cellule tabCellules[TAILLE_MAX] = malloc(sizeof(tabCellules) * TAILLE_MAX);

    printf("definiser la taille de votre tableau");
    scanf("%d", &nombreEntier);

    for(int i = 0; i < nombreEntier; i++){
        printf("case %d: ", i + 1);
        scanf("%d", tableauEntier[i]);
        celluleExist = searchValue(tabCellules, nombreCellule, tableauEntier[i]);
        if(celluleExist >= 0){
            tabCellules[celluleExist].occ++;
        } else {
            tabCellules[nombreCellule].val = tableauEntier[i];
            tabCellules[nombreCellule].occ = 0;
            nombreCellule++;
        }
    }

    

    free(tabCellules);
    return 0;
}