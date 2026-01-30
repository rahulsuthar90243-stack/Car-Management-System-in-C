#include "car_manag.h"

int main(){
  Car cars;
  Customer customers;
  Booking Bookings;

  // Main loop
  while (1){
    int choice;
    main_menu();
    printf("Please, enter your choice: ");
    scanf("%d", &choice);

    // Handle user choice
    switch (choice){
    case 1: car_manag_menu();
      break;
    case 2: customer_manag_menu();
      break;
    case 3: booking_menu();
      break;
    case 4: printf("Exiting the program. Goodbye!\n");
      return 0;

    default:
        if(choice < 1 || choice > 4){
          printf("Invalid choice. Please try again.\n");
        }
      
    }
  }
  

}