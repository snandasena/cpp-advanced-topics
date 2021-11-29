//
// Created by sajith on 11/29/21.
//

#include <string>
#include <unordered_map>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

namespace copy_trans
{
    using std::string;

    enum class Designation
    {
        ENGINEER,
        IT_MANAGER,
        HR_MANAGER,
        DIRECTOR,
        CEO,
        CTO,
        CFO,
        COO
    };

    enum class Department
    {
        ENGINEERING,
        HR,
        SENIOR_MANAGEMENT,
        BOARD_OF_DIRECTORS,
    };

    class Location
    {
        string m_Location;
    public:
        explicit Location(string const &location);
    };


    class Employee
    {
        string m_ID;
        string m_Name;
        bool m_ActiveEmployee{true};
        double salary{0.0};
        Designation designation;
        Department department;
        Location *m_Location;

    public:
        explicit Employee(string const &ID);
        Employee(string const &ID, string const &name);
        Employee(string const &ID, string const &name, Designation employeeDesignation);
        Employee(string const &ID, string const &name, Designation employeeDesignation,
                 Department employeeDepartment);

        string GetId() const;
        string GetName() const;
        Designation GetDesignation() const;
        void UpdateDesignation(Designation employeeDesignation);
        void UpdateDepartment(Department employeeDepartment);
        void UpdateEmployeeLocation(Location const &location);
        const Location &GetEmployeeLocation() const;

        double GetSalary() const;
        void UpdateSalary(double salary);

        void UpdateEmployeeStatus(bool status);

        // destructor
        ~Employee();
    };


    class Company
    {
        std::string m_CompanyName;
        Location *m_CompanyLocation;
        // Key-> ID, Value -> Employee pointer
        std::unordered_map<std::string, Employee *> m_EmployeeDetails;

    public:
        explicit Company(string const &companyName);
        Company(string const &companyName, Location &);

        void AddEmployee(Employee &employee);
        void DeleteEmployee(string const &ID);
        const Employee &FindByEmployeeID(string &ID) const;

        string GetComapanyName() const;
        const Location &GetComapanyLocation() const;

        // destructor
        ~Company();

    };
}

#endif //EMPLOYEE_H
