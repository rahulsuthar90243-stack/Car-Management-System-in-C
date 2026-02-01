#include "../car_manag.h"

void return_car()
{
    FILE *file = fopen("booking.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Booking book;

    int book_id, found = 0;
    int returnedCarId = 0;

    if (file == NULL || temp == NULL)
    {
        printf("\n%sError opening booking file!%s", RED, COLOR_END);
        return;
    }

    printf("\nEnter Booking ID: ");
    scanf("%d", &book_id);

    while (fread(&book, sizeof(Booking), 1, file))
    {
        if (book.booking_id == book_id)
        {
            returnedCarId = book.car_id;
            found = 1;
        }
        else
        {
            fwrite(&book, sizeof(Booking), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found)
    {
        remove("temp.dat");
        printf("\n%sInvalid Booking ID!%s", YELLOW, COLOR_END);
        return;
    }

    remove("booking.dat");
    rename("temp.dat", "booking.dat");

    update_vil(returnedCarId, 1);   // 🟢 RETURN → available

    printf("\n%sCar returned successfully!%s", GREEN, COLOR_END);
}
