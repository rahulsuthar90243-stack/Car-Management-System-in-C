#include "../car_manag.h"


void update_price(Car *car){
    FILE *file = fopen("cars.dat", "r+b");
    if(file == NULL){
        printf("\n%sError opening file!%s\n", RED, COLOR_END);
    }

    int id;
    float price;
    int found = 0;

    printf("\nEnter Car Id: ");
    scanf("%d", &id);
    getchar();

    while (fread(car, sizeof(Car), 1, file)){
        if(car->car_id == id){
            
            printf("Enter New Car Price/Day: ");
            scanf("%f", &car->price_per_day);

            fseek(file, -sizeof(Car), SEEK_CUR);
            fwrite(car, sizeof(Car), 1, file);

            fflush(file);
            found = 1;
            break;
        }
    }

    
   fclose(file);
   if(found == 0 ){
    printf("\n%sNo cars found!%s\n", YELLOW, COLOR_END);
   }else{
    printf("\n%sUpdated car price per day successfully.%s\n", GREEN, COLOR_END);
    update_view(car);
   }
}