// header containing methods signatures and global variables (this file don't compiles)

// "head->value" keeps the size of the linkedList
#define count head->key

// a "newNode", to be linked at the list's end
// parameter: the node's key
// return: the new node, containing the key
node* linkedNode (int value)

// inserts the "key" number at the end of the linkedList
// parameters: the linkedList head node; the key to be inserted in the linkedList
void insertKey (node* head, int key)

// removes the first occurrence of a number in the list (from head to end)
// parameters: the linkedList head node; the key to be removed of the linkedList
// return: '1' when removes the key, '0' when the key was not found in the linkedList
int removeKey (node* head, int key)

// checks if the key exists in the linkedList
// parameters: the linkedList head node; the key to be checked in the linkedList
// return: '1'if contains; '0' if not
int containsKey (node* head, int key)

// the position of key's first occurrence (from head to end)
// parameters: the linkedList head node; the key to be searched in the linkedList
// return: '0' >= "key's index" < "count"; '-1' if "key" don't exists in the linkedList
int indexOfKey (node* head, int key)

// an array containing all the keys stored in the linkedList
// parameter: the linkedList head node
// return: a pointer to the first array element
int* toArray (node* head)


// using while instead of for

/* int containsKey (node* head, int key) {
    node* current = head->next;

    while (current) {
        if (current->key == key)
            return 1;
        else
            current = current->next;
    }

    return 0;
} */


/*int indexOfKey (node* head, int key) {
    node* current = head->next;

    int index = 0;

    while (current) {
        if (current->key == key)
            return index;
        else {
            current = current->next;
            ++index;
        }
    }

    return -1;
} */
