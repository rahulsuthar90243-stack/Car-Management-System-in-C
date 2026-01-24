#include "../car_manag.h"

// Function to view all cars
void view_all_cars(Car * cars){
    FILE *file = fopen("cars.dat", "rb");
    if(file == NULL){
        printf("\nError opening file!\n");
        return;
    }

    int found = 0;
    int id;
    int num;
    printf("Press 1 for all list cars, 2 for a specific car: ");
    scanf("%d", &num);

    if(num == 2){
        printf("Enter Car ID to search: ");
        scanf("%d", &id);
    }
    
        printf("\n%-5s %-15s %-15s %-10s %-10s",
               "ID", "Name", "Model", "Price/Day", "Available");
        printf("\n------------------------------------------------------------");

        while (fread(cars, sizeof(Car), 1, file)){
            if (num == 1){
            printf("\n%-5d %-15s %-15s %-10.2f %-10s\n",
                   cars->car_id,
                   cars->car_name,
                   cars->car_model,
                   cars->price_per_day,
                   cars->available ? "Yes" : "No");
            found = 1;
            }
            else if (num == 2){
            if (cars->car_id == id){
                printf("\n%-5d %-15s %-15s %-10.2f %-10s\n",
                       cars->car_id,
                       cars->car_name,
                       cars->car_model,
                       cars->price_per_day,
                       cars->available ? "Yes" : "No");
                found = 1;
            }
        }
    }
    found == 0 ? printf("\nNo cars found.\n") : printf("\nEnd of car List.\n");
    
    fclose(file);
}