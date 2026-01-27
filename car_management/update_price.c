#include "../car_manag.h"


void update_price(Car *car){
    FILE *file = fopen("cars.dat", "r+b");
    if(file == NULL){
        printf("\nError opening file!\n");
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
    printf("\nNo cars found!\n");
   }else{
    printf("\nUpdated car price per day successfully.\n");
    update_view(car);
   }
}