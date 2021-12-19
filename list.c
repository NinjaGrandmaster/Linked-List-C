#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* create new node */
struct Node* newNode(int key, int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->data = data;
    node->next = NULL;

    return node;
}
/* print list */
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d, %d\n", current->key, current->data);
        current = current->next;
    }
}
/* add to end of list */
void append(struct Node** head, int key, int data) {
    struct Node* current = *head;
    struct Node* node = newNode(key, data);

    if(current == NULL) {
        *head = node;
    } else {
        /* find last node */
        while (current->next != NULL) {
            current = current->next;
        }
        /* add new node at end */
        current->next = node;   
    }
}
/* free memory used by list */
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* tmp = 0;

    while (current) {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}