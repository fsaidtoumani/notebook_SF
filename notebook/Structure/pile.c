#include <stdio.h>
#include <stdlib.h>

struct pile {
    int sommet, taille;
    int *reste;
};

typedef struct pile pile;

int estVide(pile *p) {
    if (p->taille == 0) return 1;
    else return 0;
}

void empiler(pile *p, int element) {
    p->reste[p->taille] = element;
    p->taille++;
    p->sommet = element;
}

int depiler(pile *p) {
    if (estVide(p)) {
        printf("Impossible de dépiler pile vide\n");
        return -1;
    }
    else {
        int sommet = p->sommet;
        p->reste[p->taille - 1] = -1;
        p->taille--;
        if (p->taille > 0) {
            p->sommet = p->reste[p->taille - 1];
        } else {
            p->sommet = -1;
        }
        return sommet;
    }
}

int sommet(pile * p){
	if(estVide(p)){
		printf("pile vide\n");
        return -1;
	}
	else return p->sommet;
}

void ecrirePile(pile *p) {
    for (int i = p->taille - 1; i >= 0; i--) {
        printf("%d ", p->reste[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    pile p;
    p.taille = 0;
    p.sommet = -1;
    p.reste = (int *)malloc(sizeof(int) * 100); // Allouez de l'espace pour 100 éléments, par exemple

    empiler(&p, 1);
    empiler(&p, 5);
    empiler(&p, 7);
    empiler(&p, 8);
    ecrirePile(&p);
    printf("sommet depiler : %d\n", depiler(&p));
    ecrirePile(&p);

    free(p.reste); // Libérez la mémoire allouée pour le tableau

    return 0;
}
