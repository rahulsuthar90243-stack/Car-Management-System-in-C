#include "../car_manag.h"

void update_model(Car *car){
    FILE *file = fopen("cars.dat", "r+b");
    if (file == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }

    int id;
    char new_model[15];
    int found = 0;

    printf("\nEnter Car Id: ");
    scanf("%d", &id);
    getchar();

    while (fread(car, sizeof(Car), 1, file))
    {
        if (car->car_id == id)
        {

            printf("Enter New Car Model: ");
            fgets(new_model, sizeof(new_model), stdin);
            new_model[strcspn(new_model, "\n")] = 0;

            strcpy(car->car_model, new_model);

            fseek(file, -sizeof(Car), SEEK_CUR);
            fwrite(car, sizeof(Car), 1, file);

            fflush(file);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (found == 0)
    {
        printf("\nNo cars found!\n");
    }
    else
    {
        printf("\nCar model update successfully.\n");
        update_view(car);
    }
}