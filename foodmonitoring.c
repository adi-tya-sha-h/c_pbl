#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50



struct inventoryitem{
    char name[50];
    int stock;
    float rate;
};

struct order{
    int id;
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
    struct inventoryitem *it=&inventory[item_count];
    printf("Enter item name :");
    scanf(" ");
    fgets(it->name,sizeof(it->name),stdin);
    it->name[strcspn(it->name, "\n")] = '\0';
    printf("Enter Stock:");
    scanf("%d",&it->stock);
    printf("Enter Rate:");
    scanf("%f",&it->rate);
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
        printf("1.Add Item\n2.View Inventory\n0.Back\n Choice: ");
        scanf("%d",&ch);
        if(ch==1){
            add_item();
        }
        else if(ch==2){
            view_inventory();
        }
    } while(ch!=0);
}

void place_order(){
    if(item_count==0){
        printf("No items available!\n");
        return;
    }

    struct order *o=&orders[order_count];

    printf("Enter Order ID: ");
    scanf("%d",&o->id);

    printf("Enter Customer Name: ");
    scanf("%s",o->cus_name);

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
    scanf("%d",&o->quantity);

    if(inventory[index].stock < o->quantity){
        printf("Not enough stock!\n");
        return;
    }

    inventory[index].stock -= o->quantity;

    o->itemIndex = index;
    o->total = o->quantity * inventory[index].rate;

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

int main(){
    load_inventory();

    int ch;
    do{
        printf("ONLINE FOOD MONITORING SYSTEM\n");
        printf("1.Inventory Management\n");
        printf("2.Order Management\n");
        printf("3.Bill\n");
        printf("4.Customer feedback\n");
        printf("0.Exit\n");
        printf("Choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch){
            case 1:inventory_menu(); break;
            case 0:printf("HAVE A NICE DAY"); break;
            default: printf("INVALID choice.\n");
        }
    }while(ch!=0);
    return 0;
}
