#include <stdio.h>

void push(int stack[], int *top, int maxSize){
    if(*top + 1 >= maxSize){
        printf("Stack is full");
    }else{
        int value;
        printf("Enter your value: ");
        scanf("%d", &value);
        *top += 1;
        stack[*top] = value;
    }
}

void pop(int stack[], int *top){
    if (*top < 0){
        printf("Stack is empty");
    }else{
        int value = stack[*top];
        *top -= 1;
        printf("%d", value);
    }
}

void peek(int stack[], int top){
    if (top < 0){
        printf("Stack is empty");
    }else{
        int value = stack[top];
        printf("%d", value);
    }
}

void display(int stack[], int top){
    if (top < 0){
        printf("Stack is empty");
    }else{
        for(int i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
    }
}

int main(){
    int value, top, maxSize;
    top = -1;
    printf("What is the size of your array? ");
    scanf("%d", &maxSize);
    int stack[maxSize];

    printf("What do you want to do? Push, Pop, Peek or Display. Press 1, 2, 3 or 4 for each respectively: ");
    scanf("%d", &value);

    switch(value){
        case 1:
            printf("Enter Top value: ");
            scanf("%d", &top);
            push(stack, &top, maxSize);
            break;
        case 2: 
            printf("Enter Top value: ");
            scanf("%d", &top);
            pop(stack, &top);
            break;
        case 3: 
            printf("Enter Top value: ");
            scanf("%d", &top);
            peek(stack, top);
            break;
        case 4:
            printf("Enter Top value: ");
            scanf("%d", &top);
            display(stack, top);
            break;
        default:
            printf("Wrong Input. Should be between 1-4");
    }
}
