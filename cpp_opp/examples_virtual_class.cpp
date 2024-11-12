 #include <iostream>
  
class a {
public:
    a(){
    std::cout  << "a" << "\n";
    }
    virtual
        void   foo()  {
        std::cout  << "±a00" << "\n";
    }

~a() {
    std::cout  << "±a" << "\n";
    }
};

class b : public a{
public:
    b(){
    std::cout  << "b" << "\n";
    }

    void foo()  {
    std::cout  << "±b00" << "\n";
    }

~b() {
    std::cout  << "±b" << "\n";
    }

};

class c : public b{
public:
    c(){
    std::cout  << "c" << "\n";
    }
    void foo()   {
    std::cout  << "±c00" << "\n";
    }

    ~c() {
    std::cout  << "±c" << "\n";
    }
};


 int main()
 {
      auto start_time = std::chrono::high_resolution_clock::now();
     
     a A;
     b B;
     c C;

     a* BB = &C;
     BB->foo();

     a* BBB = &B;
     BBB->foo();

     A.foo();
     B.foo();
     C.foo();

     
     uint64_t aaa = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()-start_time).count();
     std::cout << "Time= " <<  aaa << "\n";
 
 }
 

