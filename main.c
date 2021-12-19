#include <stdio.h>
#include "list.h"

int main() {
   
   struct Node* items = NULL;

   append(&items, 1, 2);
   append(&items, 2, 2);
   append(&items, 3, 5);
   append(&items, 4, 2);
   append(&items, 5, 2);

   printList(items);

   freeList(items);
}