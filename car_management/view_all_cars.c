#include "../car_manag.h"

// Function to view all cars
void view_all_cars(Car * cars){
    FILE *file = fopen("cars.dat", "rb");
    if(file == NULL){
        printf("\n%sError opening file!\n%s", RED, COLOR_END);
        return;
    }

    int found = 0;
    int id;
    int num;
    printf("%sPress 1 for all list cars, 2 for a specific car: %s", CYAN, COLOR_END);
    scanf("%d", &num);

    if(num == 2){
        printf("Enter Car ID to search: ");
        scanf("%d", &id);
    }
    
        printf("\n%-5s %-15s %-19s %-14s %-10s", CYAN,
               "ID", "Name", "Model", "Price/Day", "Available", COLOR_END);
        printf("\n%s------------------------------------------------------------------%s", CYAN, COLOR_END);

        while (fread(cars, sizeof(Car), 1, file)){
            if (num == 1){
            printf("\n%-5d %-15s %-19s %-14.2f %-10s\n",
                   cars->car_id,
                   cars->car_name,
                   cars->car_model,
                   cars->price_per_day,
                   cars->available ? "Yes" : "No");
            found = 1;
            }
            else if (num == 2){
            if (cars->car_id == id){
                printf("\n%-5d %-15s %-19s %-14.2f %-10s\n",
                       cars->car_id,
                       cars->car_name,
                       cars->car_model,
                       cars->price_per_day,
                       cars->available ? "Yes" : "No");
                found = 1;
            }
        }
    }
    found == 0 ? printf("\n%sNo cars found.\n%s", YELLOW, COLOR_END) : printf("\n%sEnd of car List.%s\n", CYAN, COLOR_END);
    
    fclose(file);
}