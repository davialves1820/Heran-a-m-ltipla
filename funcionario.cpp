/*Crie uma classe base Funcionario com atributos como nome, salario.
Crie classes derivadas para representar diferentes tipos de funcionários: Assalariado, Horista, Comissionado.
Crie uma classe Gerente que herda de Assalariado e Comissionado.
Implemente métodos para calcular o salário de cada tipo de funcionário.*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Employee {
    string name;
protected:
    double salary;
public:
    Employee(const string& n, double s) : name(n), salary(s) {}

    string get_name() const {
        return name;
    }

    double get_salary() const {
        return salary;
    }

    virtual double calculates_salary() const {
        return salary;
    }
};

class Salaried_employee : public virtual Employee {
protected:
    double bonus;
public:
    Salaried_employee(const string& name, double salary, double b) : Employee(name, salary), bonus(b) {}

    double calculates_salary() const override {
        return salary + bonus;
    }
};

class Hourly_employee : public Employee {
    int hours_worked;
public:
    Hourly_employee(const string& name, double salary, int hours) : Employee(name, salary), hours_worked(hours) {}

    double calculates_salary() const override {
        return salary * hours_worked;
    }
};

class Commissioned_employee : public virtual Employee {
protected:
    double sales;
    double percentage;
public:
    Commissioned_employee(const string& name, double salary, double s, double p) : Employee(name, salary), sales(s), percentage(p) {}

    double calculates_salary() const override {
        return salary + sales * percentage;
    }
};

class Manager : public Salaried_employee, public Commissioned_employee {
    string sector;
public:
    Manager(const string& name, double salary, double bonus, double sales, double percentage, const string& s) : Employee(name, salary) , Salaried_employee(name, salary,bonus), Commissioned_employee(name, salary, sales, percentage),  sector(s) {}

    double calculates_salary() const override {
        return salary + bonus + (salary * percentage);
    }
};

void show_salary(Employee* e) {
    cout << "name:" << e->get_name() << endl;
    cout << "salary: " << e->calculates_salary() << endl;
}

int main(void) {
    
    Hourly_employee h1("david",10, 60);
    Commissioned_employee c1("daniel", 1000, 500, 0.05);
    Salaried_employee s1("val", 800, 100);
    Manager m1("John", 1200, 100, 600, 0.1, "banking");
    
    show_salary(&h1);
    show_salary(&c1);
    show_salary(&s1);
    show_salary(&m1);

    return 0;
}