#include "car_manag.h"

int main(){
  Car cars;
  Customer customers;
  Booking Bookings;

printf("%s\n\n=====================================\n%s", CYAN, COLOR_END);
printf("%s|       CAR MANAGEMENT SYSTEM       |\n%s", CYAN, COLOR_END);
printf("%s=====================================\n%s", CYAN, COLOR_END);

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
    case 4:
    
    printf("%s\nThank you! Program closed successfully.\n%s", CYAN, COLOR_END);
    printf("%s\n----------------------------------\n%s", CYAN, COLOR_END);
    printf("%s|       Developed by Rahul       |\n%s", CYAN, COLOR_END);
    printf("%s----------------------------------\n%s", CYAN, COLOR_END);

      return 0;

    default:
        if(choice < 1 || choice > 4){
          printf("%sInvalid choice. Please try again.\n%s", YELLOW, COLOR_END);
        }
      
    }
  }
  

}