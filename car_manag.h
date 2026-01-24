#ifndef CAR_MANG_H
#define CAR_MANG_H

#include <stdio.h>
#include<string.h>

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

//menu function prototypes
void main_menu();
void car_manag_menu();
void customer_manag_menu();
void booking_manag_menu();

//car management function prototypes
void add_new_car(Car *cars);
void view_all_cars(Car *cars);
void search_car(Car *cars);
void update_car(Car *cars);
void delete_car(Car *cars);

#endif