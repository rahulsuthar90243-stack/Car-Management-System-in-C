#include "../car_manag.h"

// Function to add a new car
void add_new_car(Car *cars){
    FILE *file = fopen("cars.dat", "ab");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Car ID: ");
    scanf("%d", &cars->car_id);
    getchar(); // to consume the newline character

    printf("\nEnter Car Name: ");
    fgets(cars->car_name, sizeof(cars->car_name), stdin);
    cars->car_name[strcspn(cars->car_name, "\n")] = 0; // Remove newline character

    printf("\nEnter Car Model: ");
    fgets(cars->car_model, sizeof(cars->car_model), stdin);
    cars->car_model[strcspn(cars->car_model, "\n")] = 0; // Remove newline character

    printf("\nEnter Price Per Day: ");
    scanf("%f", &cars->price_per_day);

    printf("\nIs the car available? (1 for yes / 0 for no): ");
    scanf("%d", &cars->available);

    fwrite(cars, sizeof(Car), 1, file);
    fclose(file);

    printf("\nCar added successfully!\n");
}