#include "../car_manag.h"


void update_menu(){
    printf("\n[1]. Car ID");
    printf("\n[2]. Car Name");
    printf("\n[3]. Car Price");
    printf("\n[4]. Car Model");
    printf("\n[5]. Car Availability");
    printf("\n[%s0%s]. Back to menu", CYAN, COLOR_END);
}