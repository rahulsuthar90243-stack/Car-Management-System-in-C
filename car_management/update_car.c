#include "../car_manag.h"


void update_car(Car *car){
FILE *file = fopen("cars.dat", "rb");
if(file == NULL){
    printf("\n%sError opening file!%s", RED, COLOR_END);
    return;
}

int id;
int found = 0;

printf("\n==Update Car Management==");
printf("\nPlease, enter car id: ");
scanf("%d", &id);

printf("\n%-5s %-15s %-19s %-14s %-10s", CYAN,
       "ID", "Name", "Model", "Price/Day", "Available", COLOR_END);
printf("\n%s------------------------------------------------------------------%s", CYAN, COLOR_END);

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

found = 0 ? printf("\n%sNo car found.%s", YELLOW, COLOR_END) : printf("\n%sEnd car list.%s\n", CYAN, COLOR_END);

while (1){
    update_menu();
    int press;
    printf("\n\nPress Option: ");
    scanf("%d", &press);

    switch (press){
    case 1: update_id(car);
        break;
    case 2:   update_name(car);
        break;
    case 3:   update_price(car);
        break;
    case 4:   update_model(car);
        break;
    case 5:   update_Availability(car);
        break;
    case 0:
        return;    
    default:
        if(press > 5 || press < 1){
            printf("\n%sInvalid option , Please try again.%s\n", YELLOW, COLOR_END);
        }
    }
    update_view(car);
}


}