#include "../car_manag.h"

void book_car(Car *car, Booking *book)
{
    FILE *file = fopen("cars.dat", "rb");
    if (file == NULL)
    {
        printf("\nError Opening File!");
        return;
    }

    printf("\n%-5s %-15s %-19s %-14s %-10s",
           "ID", "Name", "Model", "Price/Day", "Available");
    printf("\n------------------------------------------------------------------");

    while (fread(car, sizeof(Car), 1, file))
    {
        if (car->available == 1)
        {
            printf("\n%-5d %-15s %-19s %-14.2f %-10s",
                   car->car_id,
                   car->car_name,
                   car->car_model,
                   car->price_per_day,
                   "Yes");
        }
    }
    fclose(file);

    int id;
    int found = 0;

    printf("\n\nEnter Car ID to Book: ");
    scanf("%d", &id);

    file = fopen("cars.dat", "rb");
    if (file == NULL)
    {
        printf("\nError opening file!");
        return;
    }

    while (fread(car, sizeof(Car), 1, file))
    {
        if (car->car_id == id && car->available == 1)
        {
            found = 1;

            book->car_id = car->car_id;

            printf("Enter Customer ID: ");
            scanf("%d", &book->customer_id);

            printf("Enter Number of Rental Days: ");
            scanf("%d", &book->day);

            book->total_amount = car->price_per_day * book->day;
            break;
        }
    }
    fclose(file);

    if (!found)
    {
        printf("\nCar not available or invalid Car ID!");
        return;
    }

    FILE *newFile = fopen("booking.dat", "ab");
    if (newFile == NULL)
    {
        printf("\nError opening booking file!");
        return;
    }

    fwrite(book, sizeof(Booking), 1, newFile);
    fclose(newFile);

    printf("\n\nCar booked successfully!");
    printf("\nTotal Rent Amount: %.2f\n", book->total_amount);
}





