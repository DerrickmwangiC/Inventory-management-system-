#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Structure to represent an inventory item
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Global inventory array and count
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void removeItem();
void updateQuantity();
void displayInventory();
void searchItem();

int main() {
    int choice;
    
    while(1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Quantity\n");
        printf("4. Display Inventory\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


    

