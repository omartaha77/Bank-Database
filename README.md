# Bank-Database

This project simulates a simple banking system with functionalities like creating, editing, deleting customers, printing customer data, and transferring money between customers. The project is written in C.

Features
Add a new customer
Edit customer information
Delete a customer
Print customer information
Transfer money between customers
Getting Started

Prerequisites
GCC (GNU Compiler Collection) to compile the C code.
Installing
Clone the repository:
bash
Copy code
git clone [https://github.com/your-username/simple-banking-system.git](https://github.com/omartaha77/Bank-Database.git)
cd simple-banking-system
Compile the code:
bash
Copy code
gcc -o app main.c functions.c
Run the executable:
bash
Copy code
./app
Usage
When you run the program, you will see a menu with the following options:

1- Add a new customer
2- Edit customer information
3- Delete customer
4- Print customer information
5- Cash transfer from customer to another
6- Exit
Adding a New Customer
Choose option 1.
Follow the prompts to enter the customer's name, cash, account type, and ID.
Editing Customer Information
Choose option 2.
Enter the customer's ID.
Follow the prompts to enter the new name, cash, account type, and ID.
Deleting a Customer
Choose option 3.
Enter the customer's ID.
Printing Customer Information
Choose option 4.
Enter the customer's ID.
Transferring Money Between Customers
Choose option 5.
Enter the ID of the customer who sends money.
Enter the ID of the customer who receives money.
Enter the amount of money to be transferred.
Exiting the Program
Choose option 6.
