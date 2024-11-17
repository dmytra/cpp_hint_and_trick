class Employee {
public:
    virtual double calculatePay() const = 0;
};

class FullTimeEmployee : public Employee {
public:
    double calculatePay() const override {
        return 5000.0; // фиксированная зарплата
    }
};

class ContractEmployee : public Employee {
public:
    double calculatePay() const override {
        return 3000.0; // фиксированная зарплата
    }
};

class Payroll {
public:
    double calculateTotalPay(const std::vector<Employee*>& employees) {
        double totalPay = 0.0;
        for (const auto& employee : employees) {
            totalPay += employee->calculatePay();
        }
        return totalPay;
    }
};


/*

 Какова суть принципа open closed? 

Является одним из пяти принципов SOLID, разработанных Робертом Мартином (Robert C. Martin). OCP гласит, что программные сущности (классы, модули, функции) должны быть открыты для расширения, но закрыты для модификации. Это означает, что поведение модуля можно расширить без изменения его исходного кода.

https://t.me/easy_c_plus/549
 


class Employee {
public:
    virtual double calculatePay() const = 0;
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
public:
    double calculatePay() const override {
        return 5000.0; // фиксированная зарплата
    }
};

class ContractEmployee : public Employee {
public:
    double calculatePay() const override {
        return 3000.0; // фиксированная зарплата
    }
};

class Intern : public Employee {
public:
    double calculatePay() const override {
        return 1500.0; // фиксированная зарплата
    }
};

class Payroll {
public:
    double calculateTotalPay(const std::vector<Employee*>& employees) {
        double totalPay = 0.0;
        for (const auto& employee : employees) {
            totalPay += employee->calculatePay();
        }
        return totalPay;
    }
};

 */
