#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Vous pouvez ajuster cette valeur selon vos besoins

typedef struct {
    int front, rear;
    int items[MAX_SIZE];
} Queue;

// Fonction pour initialiser une file vide
void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Fonction pour vérifier si la file est vide
int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// Fonction pour vérifier si la file est pleine
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Fonction pour ajouter un élément à la file (à l'arrière)
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("La file est pleine, impossible d'ajouter un élément.\n");
    } else if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->items[q->rear] = item;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = item;
    }
}

// Fonction pour supprimer un élément de la file (du front)
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("La file est vide, impossible de supprimer un élément.\n");
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

// Fonction pour obtenir l'élément à l'avant de la file sans le supprimer
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("La file est vide, pas d'élément en avant.\n");
        return -1;
    }
    return q->items[q->front];
}

int main() {
    Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front of the queue: %d\n", front(&myQueue));

    dequeue(&myQueue);
    printf("Front of the queue after dequeue: %d\n", front(&myQueue));

    return 0;
}
