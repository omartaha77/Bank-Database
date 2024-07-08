#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void menu()
{
    printf("1-Add a new customer \n");
    printf("2-Edit customer information\n");
    printf("3-Delete customer \n");
    printf("4-Print customer information\n");
    printf("5-Cash transfer from customer to anouther \n");
    printf("6-Exit\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int counter;
account arr[5];

void create_customer()
{
    account new_account;
    printf("please enter the name of the customer number %i: ", counter + 1);
    fflush(stdin);
    gets(new_account.name);

enter_cash:
    printf("please enter the cash of the customer number %i: ", counter + 1);
    scanf("%f", &(new_account.cash));
    if (new_account.cash < 0)
    {
        printf("the cash should be positive number and greater than or equal zero ");
        goto enter_cash;
    }

    printf("please enter the type of the account for customer number %i: ", counter + 1);
    fflush(stdin);
    gets(new_account.type);

    printf("please enter the id of the customer number %i: ");
    scanf("%i", &new_account.id);

    printf("\n\n");
    arr[counter] = new_account;
    counter++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_customer(int id)
{
    int i;
    for (i = 0; i <= counter; i++)
    {
        if (id == arr[i].id)
        {
            printf("please enter the new name :");
            fflush(stdin);
            gets(arr[i].name);

            printf("please enter the new cash :");
            scanf("%f", &(arr[i].cash));

            printf("please enter the new type of account :");
            fflush(stdin);
            gets(arr[i].type);

            printf("please enter the new id :");
            scanf("%i", &arr[i].id);

            printf("\n\n");
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_customer_data(int id)
{
    int i;
    for (i = 0; i <= counter; i++)
    {
        if (id == arr[i].id)
        {
            printf("\nthe name of the customer number %i is: %s\n", i + 1, arr[i].name);
            printf("the cash of the customer number %i is: %.2lf\n", i + 1, arr[i].cash);
            printf("the type of the account of customer number %i is: %s\n", i + 1, arr[i].type);
            printf("the id of the customer number %i is: %i\n", i + 1, arr[i].id);
            printf("\n\n");
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void delete_customer(int id)
{
    int i, index;
    for (i = 0; i <= counter - 1; i++)
    {
        if (id == arr[i].id)
        {
            index = i;
            for (i = index; i <= counter - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }
    arr[counter].cash = -1;
    arr[counter].id = -1;
    strcpy(arr[counter].name, "-1");
    strcpy(arr[counter].type, "-1");
    counter--;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void transfer_money(int id_from, int id_to, double money)
{
    int i;
    int index_from = -1;
    int index_to = -1;
transfer:
    for (i = 0; i <= counter; i++)
    {
        if (arr[i].id == id_from)
        {
            index_from = i;
        }
        else if (arr[i].id == id_to)
        {
            index_to = i;
        }
        if ((index_from != -1) && (index_to != -1))
        {
            break;
        }
    }
    if ((index_from == -1) || (index_to == -1))
    {
        printf("please enter valid id\n");
    }
    if (money > arr[index_from].cash)
    {
        printf("the money transfered is greater than your cash \n");
        printf("please enter the money transfered again and take care :");
        scanf("%lf", &money);
        goto transfer;
    }

    arr[index_from].cash = arr[index_from].cash - money;
    arr[index_to].cash = arr[index_to].cash + money;
}