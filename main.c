#include<stdio.h>
#include<ctype.h>
struct order{
    char name[100];
    int qt;
    float price;
};
struct customer{
    char c_name[20];
    int Phno;
};
int main(){
    int choice;
    printf("==== FOOD MONITORING SYSTEM ====\n");
    printf("1: View Inventory\n");
    printf("2: Place  Order\n");
    printf("3: Generate Bill\n");
    printf("4: Feedback\n");
    printf("5: Exit\n");
    switch(choice){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Exiting system...\n");
            break;
        default:
            printf("WRONG choice entered\n");
            break;
    }
    return 0;
}