#include <stdio.h>
#include <string.h>

int grid[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

void UpdateStatus(int row, int column){
    int bit, value, bitvalue, toggle;
    printf("Which bit do you want change ? Should be between 0 and 2\n");
    scanf("%d", &bit);
    value = grid[row][column];
    switch(bit){
        case 0:
            printf("Do you want to switch Power Status ON or OFF ? Enter 1 for ON and 0 for OFF\n");
            scanf("%d", &toggle);
            if(toggle){
                value |= (1 << bit);
                printf("Power Status is now ON");
            }else{
                value &= ~(1 << bit);
                printf("Power Status is now OFF");
            }
            grid[row][column] = value;
            break;
        case 1:
            printf("Do you want to change to Overload Warning to Overload or Normal ? Enter 1 and 0 for each respectively\n");
            scanf("%d", &toggle);
            if(toggle){
                value |= (1 << bit);
                printf("Overloaded warning is now Overloaded");
            }else{
                value &= ~(1 << bit);
                printf("Overload warning is now Normal");
            }
            grid[row][column] = value;
            break;
        case 2: 
            printf("Do you want to change Maintenance required to YES or NO ? Enter 1 and 0 for each respectively\n");
            scanf("%d", &toggle);
            if(toggle){
                value |= (1 << bit);
                printf("Maintanence required is now Yes");
            }else{
                value &= ~(1 << bit);
                printf("Maintanence required is now No");
            }
            grid[row][column] = value;
            break;
        default:
            printf("Bit entered should be between 0-2");
    }
}
void QueryStatus(int row, int column){
    int value = grid[row][column];
    int bit0, bit1, bit2;
    bit0 = value & (1 << 0);
    if(bit0){
        printf("Power Status is On\n");
    }else{
        printf("Power Status is Off\n");
    }
    bit1 = value & (1 << 1);
    if(bit1){
        printf("System is Overloaded\n");
    }else{
        printf("System is Normal\n");
    }
    bit2 = value & (1 << 2);
    if(bit2){
        printf("Maintanence is Required\n");
    }else{
        printf("Maintanence is Not Required\n");
    }
}
void SystemDiagnostics(){
    int value, bit0, bit1, bit2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            value = grid[i][j];
            bit0 = value & (1 << 0);
            bit1 = value & (1 << 1);
            bit2 = value & (1 << 2);
            printf("Sector [%d][%d] Status: \n", i , j);
            printf("Power is %s\n", bit0 ? "ON" : "OFF");
            printf("System is %s\n", bit1 ? "Overloaded" : "Normal");
            printf("Maintenance is %s\n", bit2 ? "Required" : "Not Required");
            printf("\n");
        }
    }
}
int main(){
    int choice, row, column;
    printf("What do you want to do ? Update Sector Status, Query Sector Status or Run System Diagnostics. Enter 1, 2, 3 for each respectively.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter Row and Column of Sector to update: \n");
            scanf("%d %d", &row, &column);
            UpdateStatus(row, column);
            break;
        case 2: 
            printf("Enter Row and Column of Sector to recieve it's status::\n");
            scanf("%d %d", &row, &column);
            QueryStatus(row, column);
            break;
        case 3: 
            SystemDiagnostics();
            break;
        default:
            printf("Input should be between 1-3");
    }
}
