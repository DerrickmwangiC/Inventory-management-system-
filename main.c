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

void addItem() {
    if(itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf(" %[^\n]s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void removeItem() {
    int id, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].id == id) {
            for(int j = i; j < itemCount-1; j++) {
                inventory[j] = inventory[j+1];
            }
            itemCount--;
            found = 1;
            printf("Item removed successfully!\n");
            break;
        }
    }
    
    if(!found) {
        printf("Item not found!\n");
    }
}

void updateQuantity() {
    int id, newQuantity, found = 0;
    printf("Enter item ID: ");
    scanf("%d", &id);
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            found = 1;
            printf("Quantity updated successfully!\n");
            break;
        }
    }
    
    if(!found) {
        printf("Item not found!\n");
    }
}

void displayInventory() {
    if(itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < itemCount; i++) {
        printf("%d\t%-16s%d\t\t%.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void searchItem() {
    int id, found = 0;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Item not found!\n");
    }
}

    

