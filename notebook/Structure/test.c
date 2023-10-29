#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 10

struct node
{
    int nb, color, numChildren;
    struct node* children[MAX_CHILDREN];
};

typedef struct node arbre_t;

arbre_t* find_node(arbre_t* node, int target_nb)
{
    if (node == NULL)
        return NULL;

    if (node->nb == target_nb)
        return node;

    for (int i = 0; i < node->numChildren; i++)
    {
        arbre_t* result = find_node(node->children[i], target_nb);
        if (result != NULL)
            return result;
    }

    return NULL;
}

void add_child_to_node(arbre_t* parent_node, int child_nb, int child_color)
{
    if (parent_node->numChildren < MAX_CHILDREN)
    {
        arbre_t* new_child = (arbre_t*)malloc(sizeof(arbre_t));
        new_child->nb = child_nb;
        new_child->color = child_color;
        new_child->numChildren = 0;

        parent_node->children[parent_node->numChildren] = new_child;
        parent_node->numChildren++;
    }
    else
    {
        printf("Nombre maximal d'enfants atteint pour le nœud %d\n", parent_node->nb);
    }
}

void print_tree(arbre_t* node)
{
    if (node == NULL)
        return;

    // Afficher le nœud actuel
    printf("Nœud %d (Couleur : %d)\n", node->nb, node->color);

    // Afficher les enfants récursivement
    for (int i = 0; i < node->numChildren; i++)
    {
        printf("Enfant de %d : ", node->nb);
        print_tree(node->children[i]);
    }
}

void free_tree(arbre_t* node)
{
    if (node == NULL)
        return;

    for (int i = 0; i < node->numChildren; i++)
    {
        free_tree(node->children[i]);
    }

    free(node);
}

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    int tabColor[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tabColor[i]);
    }

    int parent, child;
    scanf("%d %d", &parent, &child);

    arbre_t* root = (arbre_t*)malloc(sizeof(arbre_t));
    root->nb = parent;
    root->color = tabColor[parent - 1];
    root->numChildren = 0;

    add_child_to_node(root, child, tabColor[child - 1]);

    for (int i = 0; i < n - 2; ++i)
    {
        scanf("%d %d", &parent, &child);
        arbre_t* parent_node = find_node(root, parent);

        if (parent_node != NULL)
        {
            add_child_to_node(parent_node, child, tabColor[child - 1]);
        }
        else
        {
            printf("Nœud parent non trouvé : %d\n", parent);
        }
    }

    // Afficher l'arbre
    printf("Arbre :\n");
    print_tree(root);

    // Libérer la mémoire de l'arbre
    free_tree(root);

    return 0;
}
