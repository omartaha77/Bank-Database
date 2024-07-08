#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct customer
{
    char name[50];
    int id;
    float cash;
    char type[50];
} account;

void menu();
void create_customer();
void edit_customer(int id);
void print_customer_data(int id);
void delete_customer(int id);
void transfer_money(int source_id, int destination_id, double money);
#endif
