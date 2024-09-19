#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Animal {
    int age;
public:
    Animal(int a) : age(a) { 
        cout << "Animal(" << age << ")" << endl;
    }
    int get_age() const { return age;}
};

class Bird : public virtual Animal {
    double wingspan;
public:
    Bird(int a, double ws) : Animal(a), wingspan(ws) {
        cout << "Bird(" << a << ")" << endl;
        cout << "Bird(" << wingspan << ")" << endl;
    }
    double get_winspan() const { return wingspan;}
};

class Mammal : public virtual Animal {
    int coat;
public:
    Mammal(int a, int c) : Animal(a), coat(c) {
        cout << "Mammal(" << a << ")" << endl;
        cout << "Mammal(" << coat << endl;
    }
    int get_coat() const { return coat;}
};

class Bat : public Bird ,public Mammal {
    bool hematophagous;
public:
    Bat(int a, double ws, int c, bool h) : Animal(a), Bird(a,ws), Mammal(a,c), hematophagous(h) {
        cout << "Bat(" << a << ")" << endl;
        cout << "Bat(" << ws << ")" << endl;
        cout << "Bat(" << c << ")" << endl;
        cout << "Bat(" << hematophagous << ")" << endl;
    }

    void print_info() const {
        cout << "age: " << get_age() << endl;
        cout << "wingspan: " << get_winspan() << endl;
        cout << "coat: " << get_coat() << endl;
        cout << "hematophagous: " << hematophagous << endl;
    }
};

class Vampire : public Bat {
public:
    Vampire(int a, double ws, int c, bool h) : Animal(a), Bat(a,ws,c,h) {
        cout << "age: " << get_age() << endl;
        cout << "wingspan: " << get_winspan() << endl;
        cout << "coat: " << get_coat() << endl;
        cout << "hematophagous: " << h << endl;
    }
};


int main() {
    Vampire v1(1, 10.5, 5, false);

    Animal* a1 = &v1;
    Mammal* m1 = &v1;
    Bird* bd1 = &v1;
    cout << a1->get_age() << endl;
    
    cout << m1->get_age() << endl;
    cout << m1->get_coat() << endl;
    
    cout << bd1->get_age() << endl;
    cout << bd1->get_winspan() << endl;

    return 0;
}