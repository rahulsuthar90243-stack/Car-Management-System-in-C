#ifndef CAR_MANG_H
#define CAR_MANG_H

#include <stdio.h>

typedef struct Car{
    int car_id;
    char car_name[50];
    char car_model[50];
    float price_per_day;
    int available;
}Car;

typedef struct Customer{
   int customer_id;
   char customer_name[50];
   char phone[15];
}Customer;

typedef struct Booking{
    int booking_id;
    int car_id;
    int customer_id;
    int day;
    float total_amount;
}Booking;

void main_menu();
void car_manag_menu();
void customer_manag_menu();
void booking_manag_menu();


#endif