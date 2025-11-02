#include <stdio.h>
#include <string.h>

int choice, isbn, quantity, isbnfound, bookindex = 0;
int isbns[100];
char titles[100][50], title[50];
float prices[100], price;
int quantities[100];

void AddBook(int isbn, char title[], float price, int quantity){
    isbnfound = 0;
    for(int i = 0; i < bookindex; i++){
        if(isbns[i] == isbn){
            isbnfound = 1;
            break;
        }
    }
    if(isbnfound == 1){
        printf("Book is already added");
    }else{
        isbns[bookindex] = isbn;
        strcpy(titles[bookindex], title);
        prices[bookindex] = price;
        quantities[bookindex] = quantity;
        bookindex++;
        printf("Book has been added successfully.");
    }
}

void ProcessSale(int isbn, int quantity){
    int found = 0, foundat = 0;
    for(int i = 0; i < bookindex; i++){
        if(isbns[i] == isbn){
            foundat = i;
            found = 1;
            break;
        }
    }
    if (found == 1){
        if(quantities[foundat] < quantity){
            printf("Not Enough Book.");
        }else{
            if(quantities[foundat] == quantity){
                quantities[foundat] -= quantity;
                printf("Book is now out of stock");
            }else{
                quantities[foundat] -= quantity;
                printf("Quantity updated");
            }
        }
    }else{
        printf("Book not found");
    }
}

void LowStockReport(){
    for(int i  = 0; i < bookindex; i++){
        if(quantities[i] < 5){
            printf("ISBN: %d\nTitle: %s\nPrice: %f\n Quantity: %d", isbns[i], titles[i], prices[i], quantities[i]);
            printf("\n");
        }   
    }
}

int main(){
    int repeat;
    do{
        repeat = 0;
        printf("\nWhat do you want to do ? To Add New Book, Process a Sale or Generate Low-Stock Report, press 1, 2, 3 respectively.\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter ISBN, Price and Quantity of the book:\n");
                scanf("%d %f %d", &isbn, &price, &quantity);
                getchar();
                printf("Enter title of the book: \n");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = '\0';
                AddBook(isbn, title, price, quantity);
                break;
            case 2:
                printf("Enter ISBN number and number of copies sold:\n");
                scanf("%d %d", &isbn, &quantity);
                ProcessSale(isbn, quantity);
                break;
            case 3:
                LowStockReport();
                break;
            default:
                printf("Input should range from 1-3");
                break;
        }
        printf("\nDo you want to continue ? Press 1 for YES and 0 for NO\n");
        scanf("%d", &repeat);
    }while(repeat == 1);
}