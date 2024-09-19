/*Crie uma classe base ContaBancaria com atributos como saldo, numeroConta.
Crie classes derivadas para representar diferentes tipos de contas: ContaCorrente, ContaPoupanca, ContaInvestimento.
Crie uma classe ContaEspecial que herda de ContaCorrente e ContaInvestimento.
Implemente métodos para realizar depósitos, saques e transferências.*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Bank_account {
    string account_number;
protected:
    double balance;
public:
    Bank_account(const string& a_n, double b) : account_number(a_n), balance(b) {} 

    string get_account_number() const {
        return account_number;
    }

    void deposit(double value) {
        balance += value;
    }

    virtual double cashout(double value) {
        if (value > balance) {
            cout << "insufficient balance." << endl;
            return 0;
        }
        balance -= value;
        return value;
    }

    void transfer(double value, Bank_account* b1) {
        if (value > balance) {
            cout << "insufficient balance." << endl;
            return;
        }
        balance -= value;
        b1->deposit(value);
        cout << "The transfer was a success." << endl;
    }

    virtual void show_balance() const {
        cout << "Account number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Checking_account : public virtual Bank_account {
protected:
    double rate;
public:
    Checking_account(const string& account_n, double balance, double r) : Bank_account(account_n, balance), rate(r) {}

    double cashout(double value) override {
        double value_before = value;
        value += value * rate;
        if (value > balance) {
            cout << "Insufficient balance." << endl;
            return 0;
        }
        balance -= value;
        return value_before;
    }
};

class Savings_account : public Bank_account {
protected:
    double yield_rate;
public:
    Savings_account(const string& account_n, double balance, double y_r) : Bank_account(account_n, balance), yield_rate(y_r) {} 

    void calculate_yield() {
        balance += balance * yield_rate;
    }
};

class Investment_account : public virtual Bank_account {
    string type_of_investment;
public:
    Investment_account(const string& account_n, double balance, const string& t_i) : Bank_account(account_n, balance), type_of_investment(t_i) {}

    void calculate_investment(double rate) const {
        double future_balance = balance + (balance * rate);
        cout << "If you invest in this rate your balance will out this " << balance << " to " << future_balance << endl;
    }

};

class Special_account : public Checking_account, public Investment_account {
    double invest_rate;
    double balance_for_yield;
public:
    Special_account(const string& name, double b, double rate, const string& type_i, double invest_r) : Bank_account(name, b), Checking_account(name, b, rate), Investment_account(name, b, type_i), invest_rate(invest_r), balance_for_yield(balance * invest_rate) {
        balance -= balance_for_yield;
    }

    void calculate_yield() {
        balance_for_yield += balance_for_yield * 0.03;
    }

    void cushout_invest() {
        balance += invest_rate;
        invest_rate = 0;
    }

    void add_balance_invest(double value) {
        if (value > balance) {
            cout << "Insufficient balance." << endl;
        }
        balance_for_yield += value;
        balance -= value;
        cout << "Value add to savings." << endl;
    }

    void show_balance() const override {
        Bank_account::show_balance();
        cout << "Balance on invest box: " << balance_for_yield << endl;
    }
};

void show_account(Bank_account* b) {
    cout << "Firt time" << endl;
    b->show_balance();
    b->cashout(10);
    cout << "After cashout" << endl;
    b->show_balance();
    b->deposit(10);
    cout << "After deposit" << endl;
    b->show_balance();
}

int main(void) {

    Checking_account c1("11234", 1000,0.02);
    Savings_account s1("36911", 340, 0.07);
    Investment_account inv1("97385", 520, "Fixed income");
    Special_account sp1("94770",1000, 0.15, "Fixed income", 0.4);

    sp1.calculate_yield();
    sp1.show_balance();

    //inv1.calculate_investment(0.08);

    //s1.show_balance();
    //s1.calculate_yield();
    //s1.show_balance();

    //c1.transfer(100,&sp1);
    //c1.show_balance();
    //sp1.show_balance();
    //show_account(&c1);
    //show_account(&s1);
    //show_account(&inv1);
    //show_account(&sp1);    
    return 0;
} 