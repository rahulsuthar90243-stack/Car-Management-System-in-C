
# 🚗 Car Management System in C

A **menu-driven Car Management System** developed in **C programming** using **structures, file handling, and modular programming**. This project is designed for **college students and beginners** to understand how real-world management systems work at a basic level.

---

## 📌 Project Overview

The Car Management System allows users to manage:

* Cars (add, view, update availability)
* Customers (store customer details)
* Bookings (book cars, calculate rent, view bookings)

All data is stored permanently using **binary files**, making the project closer to real-life applications.

---

## ✨ Features

### 🚘 Car Management

* Add new cars
* View all cars
* Update car availability
* Delete car records
* search car

### 👤 Customer Management

* Add customer details
* View customer list
* customer-menu
* search customer

### 📅 Booking Management

* View available cars
* Book a car for specific days
* Calculate total rent automatically
* View booking history

---

## 🧠 Concepts Used

* C Structures (`struct`)
* File Handling (`fopen`, `fread`, `fwrite`, `fclose`)
* Modular Programming (multiple `.c` and `.h` files)
* Conditional Statements
* Loops
* Pointer Usage
* Menu-driven programming

---

## 📂 Project Structure

```
Car-Management-System-in-C/
│
├── main.c
├── car_manag.h
├── main_menu.c
├── color.c
│
├── car_management/
│   ├── car_manag_menu.c
│   ├── car_operations.c
│
├── customer_management/
│   ├── customer_manag_menu.c
│   ├── customer_operations.c
│
├── Booking_car_management/
│   ├── booking_menu.c
│   ├── booking_operations.c
│
├── cars.dat
├── customer.dat
├── booking.dat
└── README.md
```
## 📸 Project Preview

![Car Management System Preview](image/img%205.png);
![Booking Preview](image/img%204.png);
![](image/img%201.png)
![](image/img%202.png)
![](image/img%203.png)
---

## ⚙️ How to Compile and Run

### 🔹 Compile

```bash
gcc *.c car_management/*.c customer_management/*.c Booking_car_management/*.c -o app
```

### 🔹 Run

```bash
./app
```

(Use `app.exe` on Windows)

---

## 🧮 Rent Calculation Logic

```
Total Rent = Price Per Day × Number of Rental Days
```

Example:

* Price per day: 1200
* Rental days: 3
* Total rent: 3600

---

## 🎓 Who Can Use This Project?

* BCA / BSc IT / CS students
* Beginners learning C programming
* Students preparing for practical exams or viva
* Anyone learning file handling in C

---

## 📖 Learning Outcomes

By completing this project, you will understand:

* How real-world systems are designed in C
* How to store and retrieve data using files
* How to use structures with file handling
* How to design clean and modular programs

---

## 🚀 Future Improvements

* Login system (Admin/User)
* Date-based booking
* Fine calculation for late return
* Search and filter options
* Report generation

---



## 👨‍💻 Author

**Rahul Suthar**
C Programming | Beginner Developer

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub and feel free to fork or contribute!
