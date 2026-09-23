#include <format>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

struct Employee {   // Created a structure for an employee
    std::string name;
    int employeeID;
    double hourly_rate;
    double weekly_hours;
    double gross_pay;
};

// Make declarations of functions
double readEmployeeData(std::vector<Employee> &employees);
void parseString(std::string &line, std::string &field);
void printEmpTable(std::vector<Employee> &employees);
void empRandomize(std::vector<Employee> &employees);
void sortGrossPay(std::vector<Employee> &employees);

int main() {
    std::vector <Employee> employees; // Create the vector to store the employees
    // Call functions in order:
    readEmployeeData(employees);
    printEmpTable(employees);
    empRandomize(employees);
    printEmpTable(employees);
    sortGrossPay(employees);
    printEmpTable(employees);
    return 0;
}

double readEmployeeData(std::vector<Employee> &employees) {
    // Open EmployeeData.csv & check for any errors while opening
    std::ifstream file("../EmployeeData.csv");
    //file.open("../EmployeeData.csv");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    // Define temporary strings for double values in the Employee struct
    std::string empID;
    std::string hr;
    std::string wh;

    // Define line & skip the first line of EmployeeData.csv
    std::string line;
    std::getline(file, line);
    // Read and parse each line into the employee vector
    while (std::getline(file, line)) {
        Employee emp;
        std::stringstream ss(line);
        //std::string nametkn, empID, hr, wh;

        // Call parseString Function for each variable EXCEPT for gross_pay
        parseString(line, emp.name);
        parseString(line, empID);
        parseString(line, hr);
        parseString(line, wh);

        // Convert the empID back into a integer, and hr + wh back into doubles
        emp.employeeID = std::stoi(empID);
        emp.hourly_rate = std::stod(hr);
        emp.weekly_hours = std::stod(wh);

        // Calculate gross pay
        emp.gross_pay = emp.hourly_rate * emp.weekly_hours;

        // Store inside of the employee vector
        employees.push_back(emp);
    }
    file.close(); // Close file
    return 0;
}

void parseString(std::string &line, std::string &field) {
    int location;
    location = line.find(',');
    field = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    // Whole function is finding the next comma, reading up to the next comma and parsing it, then moving to the next comma.
}

void printEmpTable(std::vector<Employee> &employees) {
    std::cout << std::fixed << std::setprecision(2); // For decimal accuracy

    // Table header
    std::cout << std::left << std::setw(15) << "NAME";
    std::cout << std::left << std::setw(15) << "EMPNUMBER";
    std::cout << std::left << std::setw(15) << "HOURLY RATE";
    std::cout << std::left << std::setw(15) << "HOURS WORKED";
    std::cout << std::left << std::setw(15) << "GROSS PAY" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    // Printing each struct value from the employee vector on repeat until the last line
    for (Employee& emp : employees) {
        std::cout << std::left << std::setw(17) << emp.name
        << std::setw(15) << emp.employeeID
        << "$" << std::setw(15) << emp.hourly_rate
        << std::setw(13) << emp.weekly_hours
        << "$" << std::setw(15) << emp.gross_pay << std::endl;
    }
    std::cout << std::endl;
}

void empRandomize(std::vector<Employee> &employees) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(employees.begin(), employees.end(), gen);
    // Whole function randomizes employee vector values with a Mercine Twister generator
}

void sortGrossPay(std::vector<Employee> &employees) {
    std::sort(employees.begin(), employees.end(),
        [](Employee a, Employee b) {
            return a.gross_pay > b.gross_pay;
        }
    );
    // Whole function sorts the employee vector values by highest to lowest gross pay
}
