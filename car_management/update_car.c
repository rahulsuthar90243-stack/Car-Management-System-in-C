#include "../car_manag.h"


void update_car(Car *car){
FILE *file = fopen("cars.dat", "rb");
if(file == NULL){
    printf("\nError opening file!");
    return;
}

int id;
int found = 0;

printf("\n==Update Car Management==");
printf("\nPlease, enter car id: ");
scanf("%d", &id);

printf("\n%-5s %-15s %-19s %-14s %-10s",
       "ID", "Name", "Model", "Price/Day", "Available");
printf("\n------------------------------------------------------------------");

while (fread(car, sizeof(Car), 1, file)){
    if(car->car_id == id){
        printf("\n%-5d %-15s %-19s %-14.2f %-10s\n",
               car->car_id,
               car->car_name,
               car->car_model,
               car->price_per_day,
               car->available ? "Yes" : "No");
        found = 1;
    }
}
fclose(file);

found = 0 ? printf("\nNo car found.") : printf("\nEnd car list.\n");

while (1){
    update_menu();
    int press;
    printf("\n\nPress Option: ");
    scanf("%d", &press);

    switch (press){
    case 1: update_id(car);
        break;
    case 2:  // update_name();
        break;
    case 3:  // update_price();
        break;
    case 4:  // update_model();
        break;
    case 5:   // update_availability
        break;
    case 0:    // back to menu
        return;    
    default:
        if(press > 5 || press < 1){
            printf("\nInvalid option , Please try again.\n");
        }
    }
    update_view(car);
}


}