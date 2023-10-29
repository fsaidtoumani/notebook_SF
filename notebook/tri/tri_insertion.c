#include <stdio.h>

void triInsertion(int tableau[], int taille) {
    int i, j, cle;
    for (i = 1; i < taille; i++) {
        cle = tableau[i];
        j = i - 1;

        // Déplace les éléments du tableau[0..i-1] qui sont plus grands que la clé
        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }
        tableau[j + 1] = cle;
    }
}

int main() {
    int tableau[] = {12, 11, 13, 5, 6};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    triInsertion(tableau, taille);
    printf("Tableau trié par insertion : \n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    return 0;
}
