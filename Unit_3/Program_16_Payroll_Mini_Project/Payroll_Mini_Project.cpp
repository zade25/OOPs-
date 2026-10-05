#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// Abstract base class for all employees
class Employee
{
protected:
    string name;
    double basicSalary;

public:
    // Constructor to initialize employee name and basic salary
    Employee(string n, double salary)
    {
        name = n;
        basicSalary = salary;
    }

    // Pure virtual function for salary calculation
    virtual double calculateSalary() const = 0;

    // Virtual function to display basic employee details
    virtual void display() const
    {
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: Rs. " << basicSalary << endl;
    }

    // Virtual destructor for safe deletion through base pointer
    virtual ~Employee() {}
};

// Permanent employee class
class PermanentEmployee : public Employee
{
private:
    double allowance;
    double taxRate;

public:
    // Constructor to initialize permanent employee details
    PermanentEmployee(string n, double salary, double a, double tax)
        : Employee(n, salary)
    {
        allowance = a;
        taxRate = tax;
    }

    // Calculate salary after adding allowance and deducting tax
    double calculateSalary() const override
    {
        double grossSalary = basicSalary + allowance;
        double tax = grossSalary * taxRate / 100;
        return grossSalary - tax;
    }

    // Display permanent employee details
    void display() const override
    {
        Employee::display();

        double grossSalary = basicSalary + allowance;
        double tax = grossSalary * taxRate / 100;

        cout << "Allowance: Rs. " << allowance << endl;
        cout << "Tax: Rs. " << tax << endl;
        cout << "Net Salary: Rs. " << calculateSalary() << endl;
    }
};

// Contract employee class
class ContractEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor to initialize contract employee details
    ContractEmployee(string n, double rate, int hours)
        : Employee(n, rate * hours)
    {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    // Calculate salary based on hourly rate and hours worked
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }

    // Display contract employee details
    void display() const override
    {
        cout << "Employee Name: " << name << endl;
        cout << "Hourly Rate: Rs. " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: Rs. " << calculateSalary() << endl;
    }
};

// Freelance employee class
class FreelanceEmployee : public Employee
{
private:
    double projectPayment;

public:
    // Constructor to initialize freelance employee details
    FreelanceEmployee(string n, double payment)
        : Employee(n, payment)
    {
        projectPayment = payment;
    }

    // Calculate freelance project payment
    double calculateSalary() const override
    {
        return projectPayment;
    }

    // Display freelance employee details
    void display() const override
    {
        cout << "Employee Name: " << name << endl;
        cout << "Project Payment: Rs. " << projectPayment << endl;
        cout << "Total Salary: Rs. " << calculateSalary() << endl;
    }
};

int main()
{
    // Create a vector of unique pointers to Employee objects
    // This demonstrates polymorphic storage
    vector<unique_ptr<Employee>> employees;

    // Add different types of employees to the vector
    employees.push_back(
        make_unique<PermanentEmployee>("Prachi", 30000, 5000, 10));

    employees.push_back(
        make_unique<ContractEmployee>("Rahul", 500, 80));

    employees.push_back(
        make_unique<FreelanceEmployee>("Aarav", 25000));

    // Set decimal output to two places
    cout << fixed << setprecision(2);

    // Display program title and student name
    cout << "Payroll Mini-Project Using Polymorphism" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------" << endl;

    // Variable to store total payroll amount
    double totalPayroll = 0;

    // Display details of all employees
    for (const auto& employee : employees)
    {
        cout << "\nEmployee Details:" << endl;

        // Runtime polymorphism calls the correct display() function
        employee->display();

        // Add the employee salary to total payroll
        totalPayroll += employee->calculateSalary();
    }

    // Display total payroll amount
    cout << "\n----------------------------------------" << endl;
    cout << "Total Payroll Amount: Rs. " << totalPayroll << endl;

    return 0;
}