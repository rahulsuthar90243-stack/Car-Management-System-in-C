#include "../car_manag.h"

void search_customer(Customer *customers){
    FILE *file = fopen("customer.dat", "rb");
    if (file == NULL)
    {
        printf("\nError opening file");
        return;
    }

    int id;
    int found = 0;
    printf("\n===Search Customer Detail===");
    printf("\nEnter Customer Id: ");
    scanf("%d", &id);

    printf("\n%-5s %-15s %-17s",
           "ID", "Name", "Phone");
    printf("\n--------------------------------");

    while (fread(customers, sizeof(Customer), 1, file)){
        if (customers->customer_id == id)
        {
             printf("\n%-5d %-15s %-17s\n",
                  customers->customer_id,
                  customers->customer_name,
                  customers->phone);
            found = 1;
        }
    }

    found == 0 ? printf("\nNo customer found.\n") : printf("\nEnd of customer List.\n");
    fclose(file);
}