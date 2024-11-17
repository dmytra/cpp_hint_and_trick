class Base {
public:
    int baseMember;
};

class Intermediate1 : virtual public Base {
public:
    int int1Member;
};

class Intermediate2 : virtual public Base {
public:
    int int2Member;
};

class Derived : public Intermediate1, public Intermediate2 {
public:
    int derivedMember;
};

/*
 #include <iostream>

 class Base {
 public:
     int baseMember;
 };

 class Derived : public Base {
 public:
     int derivedMember;
 };

 int main() {
     Derived d;
     d.baseMember = 1;
     d.derivedMember = 2;

     std::cout << "Base member offset: " << offsetof(Derived, baseMember) << std::endl;
     std::cout << "Derived member offset: " << offsetof(Derived, derivedMember) << std::endl;

     return 0;
 }

 */

// https://t.me/easy_c_plus/592
