#include "../car_manag.h"

void search_customer(Customer *customers){
    FILE *file = fopen("customer.dat", "rb");
    if (file == NULL)
    {
        printf("\n%sError opening file%s", RED, COLOR_END);
        return;
    }

    int id;
    int found = 0;
    printf("\n===Search Customer Detail===");
    printf("\nEnter Customer Id: ");
    scanf("%d", &id);

    printf("\n%-5s %-15s %-17s", CYAN,
           "ID", "Name", "Phone", COLOR_END);
    printf("\n%s--------------------------------%s", CYAN, COLOR_END);

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

    found == 0 ? printf("\n%sNo customer found.%s\n", YELLOW, COLOR_END) : printf("\n%sEnd of customer List.%s\n", CYAN, COLOR_END);
    fclose(file);
}