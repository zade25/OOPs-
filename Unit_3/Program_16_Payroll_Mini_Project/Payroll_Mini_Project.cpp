#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
protected:
    string name;
    double basicSalary;

public:
    Employee(string n, double salary)
    {
        name = n;
        basicSalary = salary;
    }

    virtual double calculateSalary() = 0;

    virtual void display()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: Rs. " << basicSalary << endl;
    }

    virtual ~Employee() {}
};

class Developer : public Employee
{
private:
    double bonus;

public:
    Developer(string n, double salary, double b)
        : Employee(n, salary)
    {
        bonus = b;
    }

    double calculateSalary() override
    {
        return basicSalary + bonus;
    }

    void display() override
    {
        Employee::display();
        cout << "Bonus: Rs. " << bonus << endl;
        cout << "Total Salary: Rs. " << calculateSalary() << endl;
    }
};

class Manager : public Employee
{
private:
    double allowance;

public:
    Manager(string n, double salary, double a)
        : Employee(n, salary)
    {
        allowance = a;
    }

    double calculateSalary() override
    {
        return basicSalary + allowance;
    }

    void display() override
    {
        Employee::display();
        cout << "Allowance: Rs. " << allowance << endl;
        cout << "Total Salary: Rs. " << calculateSalary() << endl;
    }
};

int main()
{
    Developer developer("Prachi", 30000, 5000);
    Manager manager("Rahul", 40000, 8000);

    Employee* employees[2];

    employees[0] = &developer;
    employees[1] = &manager;

    cout << fixed << setprecision(2);

    cout << "Payroll Mini-Project Using Polymorphism" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------" << endl;

    cout << "\nDeveloper Details:" << endl;
    employees[0]->display();

    cout << "\nManager Details:" << endl;
    employees[1]->display();

    return 0;
}