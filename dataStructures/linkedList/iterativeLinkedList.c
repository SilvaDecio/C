#include <stdio.h> // using: "printf"
#include <stdlib.h> // using: "mallloc"

// the basic structure for linking
typedef struct node {
    int key;
    struct node* next;
} node;

#define count head->key

node* linkedNode (int value) {
    node* nextNode = malloc(sizeof(node*));

    nextNode->key = value;
    nextNode->next = NULL;

    return nextNode;
}

void insertKey (node* head, int key) {
    node* current = head;

    while (current->next)
        current = current->next;

    current->next = linkedNode(key);

    ++count;
}

int removeKey (node* head, int key) {
    node* previous = head;

    while (previous->next) {
        node* current = previous->next;

        if(current->key == key) {
            previous->next = current->next;

            --count;

            return 1;
        } else
            previous = current;
    }

    return 0;
}

int containsKey (node* head, int key) {
    for (node* current = head->next; current; current = current->next)
        if (current->key == key)
            return 1;

    return 0;
}

int indexOfKey (node* head, int key) {
    node* current = head->next;

    for (int i = 0; (i < count && current); (i++, current = current->next))
        if (current->key == key)
            return i;

    return -1;
}

int* toArray (node* head) {
    int* array = malloc(sizeof(int*[count]));

    node* current = head->next;

    for (int i = 0; i < count && current; i++) {
        array[i] = current->key;
        current = current->next;
    }

    return array;
}

int main () {
    printf("\n");

    // the head with Count starting as '0'
    node* head = linkedNode(0);

    printf("headAddress: %p\n", head);

    for (int i = 0; i < 10; i++) {
        insertKey(head, i+1);
    }

    printf("Count: %d\n\n", count);

    node* aux = head->next;

    while (aux) {
        printf("%p %d\n", aux, aux->key);
        aux = aux->next;
    }

    return 0;
}
