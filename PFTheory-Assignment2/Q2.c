#include <stdio.h>
#include <string.h>

char name[50];
int inventory[4][3] = {{1, 50, 100}, {2, 10, 200}, {3, 20, 300}, {4, 8, 150}};
int cart[30][2];
int cnic, inventoryindex = 4, cartindex = 0;

void CustomerInfo(){
    printf("Enter your CNIC and Name:\n");
    scanf("%d", &cnic);
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

}
void DisplayInv(){
    for(int i = 0; i < inventoryindex; i++){
        printf("Product code: %d   Quantity In Stock: %d   Price Per Product: %d\n", inventory[i][0], inventory[i][1], inventory[i][2]);
    }
}
void UpdateInv(int code, int quantity){
    int found = 0, foundat = 0;
    for(int i = 0; i < inventoryindex; i++){
        if(inventory[i][0] == code){
            foundat = i;
            found = 1;
            break;
        }
    }
    if(found){
        if(inventory[foundat][1] < quantity){
            printf("Not Enough Stock");
        }else{
            if(inventory[foundat][1] == quantity){
                printf("Stock updated and but is not out of Stock\n");
            }else{
                inventory[foundat][1] -= quantity;
                printf("Stock updated\n");
            }
        }
    }else{
        printf("Product Not Found\n");
    }
}
void AddToCart(int code, int quantity){
    int found = 0, foundat = 0;
    for(int i = 0; i < cartindex; i++){
        if(cart[i][0] == code){
            foundat = i;
            found = 1;
            break;
        }
    }
    if(found == 1){
        cart[foundat][1] += quantity;
    }else{
        cart[cartindex][0] = code;
        cart[cartindex][1] = quantity;
        cartindex++;
    }
    UpdateInv(code, quantity);
    printf("Item added to cart");
}
int FindInventoryPrice(int code){
    int price, index = -1;
    for(int i = 0; i < inventoryindex; i++){
        if(inventory[i][0] == code){
            index = i;
            break;
        }
    }
    if(index == -1){
        return -1;
    }else{
        price = inventory[index][2];
        return price;
    }
}

void DisplayBill(){
    int total = 0, cartquantity, cartprice;
    float discounttotal;
    char promocode[15];
    printf("Do you have any promocodes ?\n");
    fgets(promocode, 15, stdin);
    promocode[strcspn(promocode,"\n")] = '\0';
    if (strcmp(promocode, "Eid2025") == 0){
        for(int i = 0; i < cartindex; i ++){
            cartquantity = cart[i][1];
            cartprice = FindInventoryPrice(cart[i][0]);
            if(cartprice == -1){
                printf("Wrong Product Code");
            }else{
                total += cartquantity * cartprice;
            }
        }
        discounttotal = 0.75 * total;
    }else{
        for(int i = 0; i < cartindex; i ++){
            cartquantity = cart[i][1];
            cartprice = FindInventoryPrice(cart[i][0]);
            if(cartprice == -1){
                printf("Wrong Product Code");
            }else{
                total += cartquantity * cartprice;
            }
        }
    }
    if(strcmp(promocode, "Eid2025") == 0){
        printf("Your Total Bill Before Discount is : %d\nYour Total Bill After Discount Is: %.2f", total, discounttotal);
    }else{
        printf("Your Total Bill Is: %d", total);
    }
}
void Invoice(){
    printf("Name: %s\nCNIC: %d\n", name, cnic);
    DisplayBill();
}
int main(){
    int code, quantity, restart, complete;
    CustomerInfo();
    DisplayInv();
    do{
        printf("Enter Product Code to add to cart and amount:\n");
        scanf("%d %d", &code, &quantity);
        AddToCart(code, quantity);
        printf("Do you want to add another item or is your Order complete ? Press 1 if you want to add and 0 if complete\n");
        scanf("%d", &restart);
    }while(restart == 1);
    Invoice();
}