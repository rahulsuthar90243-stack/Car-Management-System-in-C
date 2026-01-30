#include "../car_manag.h"

Car car;
Booking book;

void booking_menu(){
    while(1){
    int choice;
    printf("\n\n===Booking Car Management==\n");
    printf("[1].Book Car\n");
    printf("[2].Return Car\n");
    printf("[3].View Booking\n");
    printf("[4].Back\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Here you can booking functionality based on the user's choice
    switch(choice){
        case 1:  book_car(&car, &book);
        break;
        case 2:  return_car();
        break;
        case 3:   view_bookings(&book);
        break;
        case 4:   //back
        return;

        default:
            if(choice < 1 || choice > 4){
                printf("\nInvalid choice . Please try again.\n");
            }

        }
    }
    }




