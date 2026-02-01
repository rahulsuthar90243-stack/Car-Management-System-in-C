#include "../car_manag.h"

void update_view(Car *car){
    int num;
    while(num > 1 || num < 0)
    {
        printf("\n\n%sPress 1 to view car | Press 0 to return: %s", CYAN, COLOR_END);
        scanf("%d", &num);
        if (num == 1){
            view_all_cars(car);
        }
        else if (num == 0){
            return;
        }
        else{
            printf("\n%sInvalid choice!%s", YELLOW, COLOR_END);
        }
    }
}