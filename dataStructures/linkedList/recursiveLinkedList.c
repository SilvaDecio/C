#include <stdio.h> // using: "printf"
#include <stdlib.h> // using: "mallloc"

// the basic structure for linking
typedef struct node {
    int key;
    struct node* next;
} node;

// "head->value" keeps the size of the linkedList
#define count head->key

node* linkedNode (int value) {
    node* nextNode = malloc(sizeof(node*));

    nextNode->key = value;
    nextNode->next = NULL;

    return nextNode;
}

// recursive method, called on "removeKey"
// goes until the last element, then: "last->next" = "newNode"
void insertRoutine (node* current, int value) {
    if (!current->next) {
        current->next = linkedNode(value);
    } else {
        insertRoutine(current->next, value);
    }
}

void insertKey (node* head, int key) {
    insertRoutine(head, key);
    ++count;
}

// recursive method, called on "removeKey"
// goes until the last node, searching by the given key
int removeRoutine (node* previous, int value) {
    node* current = previous->next;

    if (!current)
        return 0;
    else {
        if (current->key == value) {
            previous->next = current->next;
            return 1;
        } else
            return removeRoutine(current, value);
    }
}

int removeKey (node* head, int key) {
    if (removeRoutine(head, key)) {
        --count;
        return 1;
    } else
        return 0;
}

// recursive method, called on "containsKey"
int containsRoutine (node* current, int value) {
    if (!current)
        return 0;
    else {
        if (current->key == value)
            return 1;
        else
            return containsRoutine(current->next, value);
    }
}

int containsKey (node* head, int key) {
    return containsRoutine(head->next, key);
}

// recursive method, called on "indexOfKey"
int indexOfRoutine (node* current, int value, int previousIndex) {
    if (!current)
        return -1;
    else {
        ++previousIndex;

        if (current->key == value)
            return previousIndex;
        else
            return indexOfRoutine(current->next, value, previousIndex);
    }
}

int indexOfKey (node* head, int key) {
    return indexOfRoutine(head->next, key, -1);
}

void toArrayRoutine (node* current, int* array, int index) {
    if (current) {
        array[index] = current->key;
        //++index;
        toArrayRoutine(current->next, array, ++index);
    }
}

int* toArray (node* head) {
    //int* array[count];
    int* array = malloc(sizeof(int*[count]));

    toArrayRoutine(head->next, array, 0);

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

    printf("\n");

    return 0;
}
