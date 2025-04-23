
































































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
