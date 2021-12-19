#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

struct Node {
    int key;
    int data;
    struct Node *next;
};

/* function to create new nodes */
struct Node* newNode(int key, int data);
/* display the list */
void printList(struct Node* head);
/* add item to list */
void append(struct Node** head, int data, int key);
/* free memeory after using list */
void freeList();

#endif