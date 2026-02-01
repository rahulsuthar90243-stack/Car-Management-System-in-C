#include "../car_manag.h"

void add_customer(Customer *customers){
    FILE *file = fopen("customer.dat", "ab");
    if(file == NULL){
        printf("\n%sError opening file!%s\n", RED, COLOR_END);
        return;
    }

    printf("\nEnter Customer ID: ");
    scanf("%d", &customers->customer_id);
    getchar(); // to consume the newline character

    printf("\nEnter Customer Name: ");
    fgets(customers->customer_name, sizeof(customers->customer_name), stdin);
    customers->customer_name[strcspn(customers->customer_name, "\n")] = 0; // Remove newline character

    printf("\nEnter Phone Number: ");
    fgets(customers->phone, sizeof(customers->phone), stdin);
    customers->phone[strcspn(customers->phone, "\n")] = 0;
    


    fwrite(customers, sizeof(Customer), 1, file);
    fclose(file);

    printf("\n%sCustomer added successfully!%s\n", GREEN, COLOR_END);
}