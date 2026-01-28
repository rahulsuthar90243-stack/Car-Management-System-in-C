#include "../car_manag.h"

void view_customer(Customer *customers){
     FILE *file = fopen("customer.dat", "rb");
    if(file == NULL){
        printf("\nError opening file!\n");
        return;
    }

    int found = 0;
    int id;
    int num;
    printf("Press 1 for all list customer, 2 for a specific customer: ");
    scanf("%d", &num);

    if(num == 2){
        printf("Enter Customer ID to search: ");
        scanf("%d", &id);
    }
    
        printf("\n%-5s %-15s %-17s",
               "ID", "Name", "Phone");
        printf("\n--------------------------------");

        while (fread(customers, sizeof(Customer), 1, file)){
            if (num == 1){
            printf("\n%-5d %-15s %-17s\n",
                  customers->customer_id,
                  customers->customer_name,
                  customers->phone);
            found = 1;
            }
            else if (num == 2){
            if (customers->customer_id == id){
                printf("\n%-5d %-15s %-19s\n",
                       customers->customer_id,
                       customers->customer_name,
                       customers->phone);
                found = 1;
            }
        }
    }
    found == 0 ? printf("\nNo customer found.\n") : printf("\nEnd of Customer List.\n");
    
    fclose(file);
}