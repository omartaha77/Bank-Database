#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int counter;
account arr[5];
int main()
{
    char choice;
    int id;
    int id_from;
    int id_to;
    double money_transfer;
    while (1)
    {
        printf("\n");
        menu();
        printf("\nChoose one of these options: ");
        fflush(stdin);
        scanf("%c", &choice);
        printf("\n\n");
        switch (choice)
        {
        case '1':
            if (counter >= 5)
            {
                printf("the maximum number of customers is 5 so you can't add anymore\n");
                break;
            }
            create_customer();
            break;

        case '2':
            printf("please enter the id of the customer who you need to change its data :");
            scanf("%i", &id);
            edit_customer(id);
            break;

        case '3':
            printf("please enter the id of the customer who you need to delete its data :");
            scanf("%i", &id);
            delete_customer(id);
            break;
        case '4':
            printf("please enter the id of the customer who you need to print its data :");
            scanf("%i", &id);
            print_customer_data(id);
            break;
        case '5':
            printf("please enter the id of the customer who the money will transfer from his cash  :");
            scanf("%i", &id_from);
            printf("please enter the id of the customer who the money will transfer to his cash  :");
            scanf("%i", &id_to);
        L2:
            printf("please enter the money which will be transfered  :");
            scanf("%lf", &money_transfer);

            if (money_transfer <= 0)
            {
                printf("the money transfered should be positive number and greater than zero \n");
                goto L2;
            }
            transfer_money(id_from, id_to, money_transfer);
            break;

        case '6':
            exit(0);
        default:
            printf("wrong choice\n\n");
        }
    }

    return 0;
}

// gcc -o app main.c functions.c