#include "../car_manag.h"

void return_car(){

    Car cars;
    Booking book;

    FILE *file = fopen("booking.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if(file == NULL || temp == NULL){
     printf("\nError opening file!");
    }

    int book_id, found = 0;
    int returnedCarId = 0;
    int deleted = 0;
    printf("\nPlease, enter booking Id: ");
    scanf("%d", &book_id);

    while (fread(&book, sizeof(Booking), 1, file)){
        if(book.booking_id == book_id){
         returnedCarId = book.car_id;
         deleted = 1;
        }else{
            fwrite(&book, sizeof(Booking), 1, temp);
            fflush(temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!deleted){
        remove("temp.dat");
        printf("\nCar is now available for booking!\n");
        return;
    }

    remove("booking.dat");
    rename("temp.dat", "booking.dat");
 
    update_vil(returnedCarId, deleted);

    printf("\nCar returned successfully.\n\n");

    
}