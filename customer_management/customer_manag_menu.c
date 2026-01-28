#include "../car_manag.h"

void customer_manag_menu(){
     while (1){
    int option;
    printf("\n=== Customer Management Menu ===\n");
    printf("[1]. Add Customer\n");
    printf("[2]. View Customers\n");
    printf("[3]. Search Customers\n");
    printf("[4]. Back to Main Menu\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    // Here you can add functionality based on the user's choice
    switch(option){
        case 1: // add_customer();
        break;
        case 2:  // view_customer();
        break;
        case 3:  // Search_customer();
        break;
        case 4:  // back
        return;

        default:
            if(option < 1 || option > 4){
                printf("Invalid option . Please try again.\n");
            }

        }
    }
}