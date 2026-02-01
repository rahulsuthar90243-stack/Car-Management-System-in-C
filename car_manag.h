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
void booking_menu();

//car management function prototypes
void add_new_car(Car *cars);
void view_all_cars(Car *cars);
void search_car(Car *cars);

void delete_car(Car *cars);


// update functon  prototype
void update_car(Car *cars);
void update_menu();
void update_id(Car *car);
void update_name(Car *car);
void update_price(Car *car);
void update_model(Car *car);
void update_Availability(Car *car);
void update_view(Car *car);


// Customer Management Prototype
void customer_manag_menu();
void add_customer(Customer *customer);
void view_customer(Customer *customer);
void search_customer(Customer *customer);


//Booking car Management Prototype
void booking_menu();
void book_car(Car *car, Booking *book);
void return_car();
void view_bookings(Booking *book);
void update_vil(int id, int status);



extern const char* COLOR_END;
extern const char* RED;
extern const char* GREEN;
extern const char* YELLOW;
extern const char* CYAN;


#endif