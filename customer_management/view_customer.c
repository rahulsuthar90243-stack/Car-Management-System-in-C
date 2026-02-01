#include "../car_manag.h"

void view_customer(Customer *customers){
     FILE *file = fopen("customer.dat", "rb");
    if(file == NULL){
        printf("\n%sError opening file!%s\n", RED, COLOR_END);
        return;
    }

    int found = 0;
    int id;
    int num;
    printf("\n%sPress 1 for all list customer, 2 for a specific customer: %s", CYAN, COLOR_END);
    scanf("%d", &num);

    if(num == 2){
        printf("Enter Customer ID to search: ");
        scanf("%d", &id);
    }
    
        printf("%s\n%-5s %-15s %-17s%s", CYAN,
               "ID", "Name", "Phone", COLOR_END);
        printf("\n%s--------------------------------%s", CYAN, COLOR_END);

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
    found == 0 ? printf("\n%sNo customer found.%s\n", YELLOW, COLOR_END) : printf("\n%sEnd of Customer List.%s\n", CYAN, COLOR_END);
    
    fclose(file);
}