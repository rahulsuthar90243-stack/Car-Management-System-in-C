#include "../car_manag.h"




void update_vil(int bookedCarId)
{
    FILE *file = fopen("cars.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    Car car;

    if (file == NULL || temp == NULL)
    {
        printf("\nError updating car availability!");
        return;
    }

    while (fread(&car, sizeof(Car), 1, file))
    {
        if (car.car_id == bookedCarId)
        {
            car.available = 0;   // mark unavailable
        }


        fwrite(&car, sizeof(Car), 1, temp);
        fflush(temp);
    }

    fclose(file);
    fclose(temp);

    remove("cars.dat");
    rename("temp.dat", "cars.dat");
}
