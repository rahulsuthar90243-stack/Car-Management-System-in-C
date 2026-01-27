#include "../car_manag.h"


void delete_car(Car *car){
 FILE *file = fopen("cars.dat", "rb");
 FILE *temp = fopen("temp.dat", "wb");

 if(file == NULL || temp == NULL){
    printf("\nError opening file!");
    return;
 }


 int id; 
 int found = 0, deleted = 0;

 char name[15];

 printf("\nEnter Car ID: ");
 scanf("%d", &id);
 getchar();

 printf("Enter Car Name: ");
 fgets(name, sizeof(name), stdin);
 name[strcspn(name, "\n")] = '\0';

 printf("\n%-5s %-15s %-19s %-14s %-10s",
        "ID", "Name", "Model", "Price/Day", "Available");
 printf("\n------------------------------------------------------------------");

 while (fread(car, sizeof(Car), 1, file)){
            if (car->car_id == id && strcmp(car->car_name, name) == 0){
            printf("\n%-5d %-15s %-19s %-14.2f %-10s\n",
                   car->car_id,
                   car->car_name,
                   car->car_model,
                   car->price_per_day,
                   car->available ? "Yes" : "No");
            found = 1;
            }

        }

    if(!found){
        printf("\nCar not found!!!");
        fclose(file);
        fclose(temp);
        return;
    }

    rewind(file);   

    while (fread(car, sizeof(Car), 1, file)){
        if(car->car_id == id && strcmp(car->car_name, name) == 0){
            deleted = 1;  
        } else {
            fwrite(car, sizeof(Car), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!deleted){
        remove("temp.dat");
        printf("\nCar not found!\n\n");
        return;
    }

    remove("cars.dat");
    rename("temp.dat", "cars.dat");

    printf("\nCar removed successfully.\n\n");

}