#include "../car_manag.h"


void search_car(Car *car){
FILE *file = fopen("cars.dat", "rb");
if(file == NULL){
    printf("\nError opening file");
    return;
}

int id;
int found = 0;
printf("\n===Search Car Detail===");
printf("\nEnter Car Id: ");
scanf("%d", &id);

printf("\n%-5s %-15s %-19s %-14s %-10s",
       "ID", "Name", "Model", "Price/Day", "Available");
printf("\n------------------------------------------------------------------");

while (fread(car, sizeof(Car), 1, file)){
    if (car->car_id == id){
        printf("\n%-5d %-15s %-19s %-14.2f %-10s\n",
               car->car_id,
               car->car_name,
               car->car_model,
               car->price_per_day,
               car->available ? "Yes" : "No");
        found = 1;
        }
    }
 
    found == 0 ? printf("\nNo cars found.\n") : printf("\nEnd of car List.\n");
    fclose(file);

}