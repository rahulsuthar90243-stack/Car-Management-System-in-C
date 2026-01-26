#include "../car_manag.h"



void update_id(Car *car){
    FILE *file = fopen("cars.dat", "r+b");
    if(file == NULL){
        printf("\nError opening file!\n");
    }

    int id;
    int found = 0;

    printf("\nEnter Car Id: ");
    scanf("%d", &id);

    while (fread(car, sizeof(Car), 1, file)){
        if(car->car_id == id){
            printf("\nEnter New Car ID: ");
            scanf("%d", &car->car_id);

            fseek(file, -sizeof(Car), SEEK_CUR);
            fwrite(car, sizeof(Car), 1, file);
            found = 1;
            break;
        }
    }
   if(found == 0 ){
    printf("\nNo cars found!\n");
   }else{
    printf("\nCar ID update successfully.\n");
    update_view(car);
   }
    fclose(file);
}