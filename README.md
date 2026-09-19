# C++ Programming Project – OOPs

## Student Details

- **Student Name:** Prachi Pramod Zade
- **Roll Number:** AD2262
- **PRN:** 125UAD1095
- **Class/Division:** SY/B
- **Course Name:** OOPs

## List of Programs

# Unit 1 – C++ Programming Basics

### 1. Basic Data Types
A simple program using basic data types like `int`, `char`, and `float` to store and display student details.

### 2. If-Else
Uses an `if-else` statement to check whether a student has passed or failed based on marks.

### 3. Loop and Array
Uses an array to store marks of five students and a `for` loop to display them.

### 4. Functions
Shows how a user-defined function can be used to add two numbers.

### 5. Class and Object
Creates a `Student` class and an object to store and display student information.

### 6. Constructor and Destructor
Shows the working and execution order of a constructor and destructor.

### 7. Static Member
Uses a static data member to keep track of the number of objects created.

### 8. Inline and Friend Function
Uses an inline function and a friend function to access and display class data.

# Unit 2 – Inheritance and Related OOP Concepts

### 1. Basic Single Inheritance
Shows single inheritance where `Student` inherits properties and functions from `Person`.

### 2. Protected Member Access
Shows how a derived class can access a protected member of its base class.

### 3. Public versus Private Inheritance
Shows the difference between public and private inheritance and how they affect member accessibility.

### 4. Multilevel Inheritance
Shows multilevel inheritance using the hierarchy `Person → Employee → Manager`.

### 5. Hierarchical Inheritance
Shows how two derived classes, `Car` and `Bike`, can inherit from the same `Vehicle` class.

### 6. Multiple Inheritance
Shows multiple inheritance where `Student` inherits from both `Academic` and `Sports`.

### 7. Resolving Multiple-Inheritance Ambiguity
Shows how the scope-resolution operator can be used to select the required function when two base classes have functions with the same name.

### 8. Constructor and Destructor Order
Shows the order in which constructors and destructors are called when working with inheritance.

### 9. Parameterized Base Constructor
Shows how a derived-class constructor can pass values to a parameterized constructor of the base class.

### 10. Function Overriding
Shows function overriding using virtual functions and different implementations in derived classes.

### 11. Abstract Class
Shows the use of an abstract class containing a pure virtual function.

### 12. Virtual Base Class and Diamond Inheritance
Shows how virtual inheritance helps avoid duplicate copies of a base class in diamond inheritance.

### 13. Friend Class
Shows how a friend class can access the private members of another class.

### 14. Nested Class
Shows how a class can be declared and used inside another class.

### 15. Mini-Project – Vehicle Rental System
A simple vehicle rental system using inheritance, function overriding, and rental calculations for different vehicles.

### 16. Mini-Project – Employee Payroll System
A simple employee payroll system using abstract classes, inheritance, function overriding, and polymorphism.

## Repository Structure

```text
OOP_Programs
│
├── Unit_1
│   ├── Program_01_Basic_Data_Types
│   ├── Program_02_if_else
│   ├── Program_03_Loop_and_Array
│   ├── Program_04_Functions
│   ├── Program_05_Class_and_Object
│   ├── Program_06_Constructor_and_Destructor
│   ├── Program_07_Static_Member
│   └── Program_08_Inline_and_Friend_Function
│
└── Unit_2
    ├── Program_01_Basic_Single_Inheritance
    ├── Program_02_Protected_Member_Access
    ├── Program_03_Public_vs_Private_Inheritance
    ├── Program_04_Multilevel_Inheritance
    ├── Program_05_Hierarchical_Inheritance
    ├── Program_06_Multiple_Inheritance
    ├── Program_07_Ambiguity_Resolution
    ├── Program_08_Constructor_and_Destructor_Order
    ├── Program_09_Parameterized_Base_Constructor
    ├── Program_10_Function_Overriding
    ├── Program_11_Abstract_Class
    ├── Program_12_Virtual_Base_Class
    ├── Program_13_Friend_Class
    ├── Program_14_Nested_Class
    ├── Program_15_Vehicle_Rental_System
    └── Program_16_Employee_Payroll_System
