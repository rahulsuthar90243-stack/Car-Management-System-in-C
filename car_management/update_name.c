#include "../car_manag.h"


void update_name(Car *car){
 FILE *file = fopen("cars.dat", "r+b");
    if(file == NULL){
        printf("\nError opening file!\n");
    }

    int id;
    char new_name[50];
    int found = 0;

    printf("\nEnter Car Id: ");
    scanf("%d", &id);
    getchar();

    while (fread(car, sizeof(Car), 1, file)){
        if(car->car_id == id){
            
            printf("Enter New Car Name: ");
            fgets(new_name, sizeof(new_name), stdin);
            new_name[strcspn(new_name, "\n")] = 0;

            strcpy(car->car_name, new_name);

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
    printf("\nCar name update successfully.\n");
    update_view(car);
   }
    
}