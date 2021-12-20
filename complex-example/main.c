#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

#include "list.h"


int main() {
   
   struct Node* items = NULL;

   append(&items, 1, "Apple", 2);
   append(&items, 2, "Chips", 2);
   append(&items, 3, "Cookie", 5);
   append(&items, 4, "Almonds", 2);
   append(&items, 5, "Peanuts", 2);

   int itemCount = 5;

   int action;
   int itemNum;
   char str[25];
   double price;

   while(1) {

        printf("Select an action \n1: Select item\n2: Add to List\n3: Exit\n");
        scanf("%d", &action);

        switch (action) {
            case 1:
                printList(items);
                printf("Select an item\n");
                scanf("%d", &itemNum); /* get item selected by user */

                bool itemExists = exists(items, itemNum);

                if (itemExists)
                {
                    char* itemName = getName(items, itemNum);
                    double itemPrice = getPrice(items, itemNum);

                    printf("Selected: %s - $%.2f\n", itemName, itemPrice);
                } else {
                    printf("Invalid Choice\n");
                }
                
                break;
            
            case 2:
                printf("Enter item name: ");
                scanf("%s", str);

                printf("Enter item price: ");
                scanf("%lf", &price);

                itemCount += 1;

                append(&items, itemCount, str, price);

                printf("Item added: %s - $%.2f\n", str, price);
                
                break;

            case 3:
                freeList(items);
                exit(0);
                break;

            default:
                printf("Invaid Choice\n");
                break;
        }
    }

}