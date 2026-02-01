#include "../car_manag.h"



void view_bookings(Booking *book){

    FILE *file = fopen("booking.dat", "rb");
    if(file == NULL){
        printf("\n%sError opening file!%s", RED, COLOR_END);
        return;
    }

    int id, num;
    int found = 0;

    printf("\n%sPress 1 for all bookings list, 2 for a specific booking: %s", CYAN, COLOR_END);
    scanf("%d", &num);

    if(num == 2){
    printf("Enter booking Id: ");
    scanf("%d", &id);
    }

printf("%s\n| %-10s | %-8s | %-11s | %-5s | %-12s |\n%s", CYAN,
       "Booking ID", "Car ID", "Customer ID", "Days", "Amount", COLOR_END);
printf("%s---------------------------------------------------------------\n%s", CYAN, COLOR_END);

    while(fread(book, sizeof(Booking), 1, file)){
        if(num == 2){
        if(book->booking_id == id){
        printf("| %-10d | %-8d | %-11d | %-5d | %-12.2f |\n",
                book->booking_id,
                book->car_id,
                book->customer_id,
                book->day,
                book->total_amount);
                found = 1;
                break;

       }
        }else if(num == 1){
        printf("| %-10d | %-8d | %-11d | %-5d | %-12.2f |\n",
                book->booking_id,
                book->car_id,
                book->customer_id,
                book->day,
                book->total_amount);
                found = 1; 
        }
    }

    found == 0 ? printf("\n%sNo booking%s", YELLOW, COLOR_END) : printf("\n\n%sEnd of list%s", CYAN, COLOR_END);
    fclose(file);

}