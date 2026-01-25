#include "car_manag.h"

Car cars;

void car_manag_menu() {
    while (1){
    int option;
    printf("\n=== Car Management Menu ===\n");
    printf("[1]. Add New Car\n");
    printf("[2]. View All Cars\n");
    printf("[3]. Search Car\n");
    printf("[4]. Update Car\n");
    printf("[5]. Delete Car\n");
    printf("[6]. Back to Main Menu\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    // Here you can add functionality based on the user's choice
    switch(option){
        case 1: add_new_car(&cars);
        break;
        case 2: view_all_cars(&cars);
        break;
        case 3: search_car(&cars);
        break;
        case 4: update_car(&cars);
        break;
        case 5: // Delete Car functionality
        break;
        case 6: // Back to Main Menu
        return;

        default:
            if(option < 1 || option > 6){
                printf("Invalid option . Please try again.\n");
            }

        }
    }
}