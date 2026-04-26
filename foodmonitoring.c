#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

//STRUCTURES
struct inventoryitem{
    char name[50];
    int stock;
    float rate;
};

struct order{
    int order_id;
    char cus_name[50];
    int itemIndex;
    int quantity;
    float total;
};

struct feedback{
    char customer[50];
    int rating;
    char comment[100];
};

struct Bill {
    int order_id;
    char cus_name[50];
    char item[50];
    int quantity;
    float total_price;
};

struct order orders[MAX];
struct inventoryitem inventory[MAX];
struct feedback feedbacks[MAX];
struct Bill bills[MAX];

int order_count=0;
int item_count=0;
int feedback_count=0;
int bill_count= 0;

//INVENTORY
void save_inventory(){
    FILE *f=fopen("inventory.txt","w");
    fprintf(f,"%d\n",item_count);
    for(int i=0;i<item_count;i++){
        fprintf(f,"%s %d %.2f\n",
            inventory[i].name,
            inventory[i].stock,
            inventory[i].rate);
    }
    fclose(f);
}
void load_inventory(){
    FILE *f=fopen("inventory.txt","r");
    if(f==NULL) return;

    fscanf(f,"%d",&item_count);
    for(int i=0;i<item_count;i++){
        fscanf(f,"%s %d %f",
            inventory[i].name,
            &inventory[i].stock,
            &inventory[i].rate);
    }
    fclose(f);
}

void add_item(){
    if(item_count>=MAX){
        printf("INVENTORY IS FULL!");
        return;
    }

    printf("Enter item name: ");
    scanf(" ");
    fgets(inventory[item_count].name,50,stdin);
    inventory[item_count].name[strcspn(inventory[item_count].name,"\n")] = '\0';

    printf("Enter Stock: ");
    scanf("%d",&inventory[item_count].stock);

    printf("Enter Rate: ");
    scanf("%f",&inventory[item_count].rate);

    item_count++;
    save_inventory();

    printf("Item added!\n");
}

void view_inventory(){
    if(item_count==0){
        printf("INVENTORY IS EMPTY Y.Y\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-10s\n","NO.","ITEM","STOCK","PRICE");
    printf("----------------------------------------------\n");

    for(int i=0;i<item_count;i++){
        printf("%-5d %-20s %-10d %.2f\n",
            i+1,
            inventory[i].name,
            inventory[i].stock,
            inventory[i].rate);
    }
}

void inventory_menu(){
    int ch;
    do{
        printf("\nINVENTORY\n");
        printf("1.Add Item\n2.View Inventory\n0.Back\nChoice: ");
        scanf("%d",&ch);

        if(ch==1) add_item();
        else if(ch==2) view_inventory();

    } while(ch!=0);
}

// ORDER
void save_orders(){

}
void load_orders(){
    
}
void place_order(){
    if(item_count==0){
        printf("No items available!\n");
        return;
    }
    printf("Enter Order ID: ");
    scanf("%d",&orders[order_count].order_id);
    printf("Enter Customer Name: ");
    scanf("%s",orders[order_count].cus_name);
    view_inventory();
    int choice;
    printf("Select item number: ");
    scanf("%d",&choice);
    if(choice<1 || choice>item_count){
        printf("Invalid choice!\n");
        return;
    }
    int index=choice-1;
    printf("Enter quantity: ");
    scanf("%d",&orders[order_count].quantity);
    if(inventory[index].stock < orders[order_count].quantity){
        printf("Not enough stock!\n");
        return;
    }
    inventory[index].stock -= orders[order_count].quantity;
    orders[order_count].itemIndex = index;
    orders[order_count].total =orders[order_count].quantity * inventory[index].rate;
    order_count++;
    save_inventory();
    printf("Order placed successfully!\n");
}

void order_menu(){
    int ch;
    do{
        printf("\nORDER MENU\n");
        printf("1.Place Order\n0.Back\nChoice: ");
        scanf("%d",&ch);
        if(ch==1) place_order();
    }while(ch!=0);
}

//BILL
void bills_menu(){

}

//FEEDBACK
void save_feedback(){
    FILE *f=fopen("feedback.txt","w");
    fprintf(f,"%d\n",feedback_count);
    for(int i=0;i<feedback_count;i++){
        fprintf(f,"%s\n %d\n %s\n",
            feedbacks[i].customer,
            feedbacks[i].rating,
            feedbacks[i].comment);
    }
    fclose(f);
}
void load_feedback(){
    FILE *f=fopen("feedback.txt","r");
    if(f==NULL) return;
    fscanf(f,"%d",&feedback_count);
    for(int i=0;i<feedback_count;i++){
        fscanf(f,"%s %d %s",
            feedbacks[i].customer,
            &feedbacks[i].rating,
            feedbacks[i].comment
            );
    }
    fclose(f);
}

void give_feedback(){
    if(feedback_count>=MAX){
        printf("Feedback limit reached!");
        return;
    }
    printf("Enter your name: ");
    scanf(" ");
    fgets(feedbacks[feedback_count].customer,50,stdin);
    feedbacks[feedback_count].customer[strcspn(feedbacks[feedback_count].customer,"\n")] = '\0';
    printf("Enter rating(1-5): ");
    scanf("%d",&feedbacks[feedback_count].rating);
    printf("Enter comment: ");
    scanf(" ");
    fgets(feedbacks[feedback_count].comment,100,stdin);
    feedbacks[feedback_count].comment[strcspn(feedbacks[feedback_count].comment,"\n")] = '\0';
    feedback_count++;
    save_feedback();
    printf("Feedback submitted!");
}
void view_feedback(){
    if(feedback_count==0){
        printf("No feedback yet!");
        return;
    }
    printf("%-15s %-8s %s\n",
        "CUSTOMER",
        "RATING",
        "COMMENT");
    printf("----------------------------------------------\n");
    for(int i=0;i<feedback_count;i++){
        printf("%-15s %-8d %s\n",
            feedbacks[i].customer,
            feedbacks[i].rating,
            feedbacks[i].comment);
    }
}
void feedback_menu(){
    int ch;
    do{
        printf("\nCUSTOMER FEEDBACK MENU\n");
        printf("1.Give Feedback\n");
        printf("2.View Feedback\n");
        printf("0.Back\n");
        printf("Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                give_feedback(); 
                break;
            case 2: 
                view_feedback(); 
                break;
        }
    }while(ch!=0);
}


int main(){
    load_inventory();
    load_feedback();
    int ch;
    do{
        printf("ONLINE FOOD MONITORING SYSTEM\n");
        printf("1.Inventory Management\n");
        printf("2.Place Order\n");
        printf("3.Bill\n");
        printf("4.Customer feedback\n");
        printf("0.Exit\n");
        printf("Choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch){
            case 1:
                inventory_menu(); 
                break;
            case 2: 
                order_menu(); 
                break;
            case 3:
                bills_menu();
                break;
            case 4:
                feedback_menu();
                break;
            case 0:
                printf("HAVE A NICE DAY"); 
                break;
            default: 
                printf("INVALID choice.\n");
        }
    }while(ch!=0);
    return 0;
}
