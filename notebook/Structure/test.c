#include <stdio.h>
#include <stdlib.h>

struct node
{
    int nb, color, numChildren;
    struct node * next[MAX];
};

int main(int argc, char const *argv[])
{
    int n, parent, child;
    scanf("%d", &n);
    int tabColor[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tabColor[i]);
    }

    scanf("%d %d", &parent, &child);

    arbre_t * new1 = (arbre_t*)malloc(sizeof(arbre_t));
    new1->nb = child;
    new1->color = tabColor[child-1];
    new1->numChildren = 0;

    arbre_t * a = (arbre_t*)malloc(sizeof(arbre_t));
    a->nb = parent;
    a->color = tabColor[parent-1];
    a->next[parent] = new1;
    a->numChildren++;

    for (int i = 0; i < n-2; ++i)
    {
        scanf("%d %d", &parent, &child);

        arbre_t * new = (arbre_t*)malloc(sizeof(arbre_t));
        new->nb = child;
        new->numChildren = 0;
        new->color = tabColor[child-1];

        a->next[parent] = new;
        a->next[parent]->numChildren++;
        a->numChildren++;
    }
}