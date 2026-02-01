#include "../car_manag.h"



void update_id(Car *car){
    FILE *file = fopen("cars.dat", "r+b");
    if(file == NULL){
        printf("\n%sError opening file!%s\n", RED, COLOR_END);
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
            fflush(file);
            found = 1;
            break;
        }
    }
   if(found == 0 ){
    printf("\n%sNo cars found!\n%s", YELLOW, COLOR_END);
   }else{
    printf("\n%sCar ID update successfully.%s\n", GREEN, COLOR_END);
    update_view(car);
   }
    fclose(file);
}