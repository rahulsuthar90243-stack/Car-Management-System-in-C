#include "../car_manag.h"

void update_view(Car *car){
    int num;
    while(num > 1 || num < 0)
    {
        printf("\n\nPress 1 to view students | Press 0 to return: ");
        scanf("%d", &num);
        if (num == 1){
            view_all_cars(car);
        }
        else if (num == 0){
            return;
        }
        else{
            printf("\nInvalid choice!");
        }
    }
}