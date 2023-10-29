#include <stdio.h>
#include <stdlib.h>

void fusion(int tableau[], int gauche, int milieu, int droite) { //O(n*log(n)) rapide mais utilise
                                                                // beaucoup de mémoire
    int i, j, k;
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    // Créer des tableaux temporaires
    int L[n1], R[n2];

    // Copier les données dans les tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++)
        L[i] = tableau[gauche + i];
    for (j = 0; j < n2; j++)
        R[j] = tableau[milieu + 1 + j];

    // Fusionner les tableaux temporaires de nouveau dans le tableau[gauche..droite]
    i = 0;
    j = 0;
    k = gauche;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tableau[k] = L[i];
            i++;
        } else {
            tableau[k] = R[j];
            j++;
        }
        k++;
    }

    // Copier les éléments restants de L[], s'il y en a
    while (i < n1) {
        tableau[k] = L[i];
        i++;
        k++;
    }

    // Copier les éléments restants de R[], s'il y en a
    while (j < n2) {
        tableau[k] = R[j];
        j++;
        k++;
    }
}

void triFusion(int tableau[], int gauche, int droite) {
    if (gauche < droite) {
        // Trouver le point milieu du tableau
        int milieu = gauche + (droite - gauche) / 2;

        // Trier la première et la deuxième moitié
        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        // Fusionner les deux moitiés triées
        fusion(tableau, gauche, milieu, droite);
    }
}

int main() {
    int tableau[] = {12, 11, 13, 5, 6, 7, 5, 60, 2, 1, 8};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    triFusion(tableau, 0, taille - 1);
    printf("Tableau trié par tri fusion : \n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    return 0;
}
