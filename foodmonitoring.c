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
    char customer[50];
    int item[50];
    int quantity;
    float price;
};

struct feedback{
    char customer[50];
    int rating;
    char comment[100];
};

struct Bill {
    int   order_id;
    char  customer[50];
    char  item[50];
    int   quantity;
    float subtotal;
    float gst;
    float grand_total;
};

struct order orders[MAX];
struct inventoryitem inventory[MAX];
struct feedback feedback[MAX];
struct Bill bills[MAX];

int order_count=0;
int item_count=0;
int feedback_count=0;
int bill_count= 0;

void save_inventory(){
    FILE *f=fopen("inventory.txt","w+");
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
            inventory[i].stock,
            inventory[i].rate);
    }
    fclose(f);

}

void add_item(){
    
}

void view_inventory(){

}