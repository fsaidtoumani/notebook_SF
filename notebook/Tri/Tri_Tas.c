#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int* a, int* b) { //O(n*log(n)) efficace lorsque que contraintes
                            //mémoire 
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour réorganiser le tas pour maintenir la propriété de tas max
void maxHeapify(int arr[], int n, int i) {
    int largest = i;  // Initialisation de la racine comme le plus grand élément
    int left = 2 * i + 1; // Indice du fils gauche
    int right = 2 * i + 2; // Indice du fils droit

    // Si le fils gauche est plus grand que la racine
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si le fils droit est plus grand que le plus grand élément jusqu'à présent
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si le plus grand élément n'est pas la racine
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Réorganiser récursivement le sous-arbre affecté
        maxHeapify(arr, n, largest);
    }
}

// Fonction pour trier un tableau en utilisant le tri par tas
void heapSort(int arr[], int n) {
    // Construire le tas (à partir du bas)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extraire les éléments un par un depuis le tas
    for (int i = n - 1; i > 0; i--) {
        // Déplacer la racine actuelle à la fin
        swap(&arr[0], &arr[i]);
        // Appel récursif pour réduire la taille du tas
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau non trié : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    heapSort(arr, n);

    printf("\nTableau trié : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}