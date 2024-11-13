 
// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-pointers-stdbind-activity-7262101937850929153-eNb-/?utm_source=share&utm_medium=member_desktop

#include <functional>
#include <string>

int fn( int a, int & b ) { return a+b; }

struct Fn_struct {
    std::string name {};
    std::function<int(int &)> my_fn{};
};

int main()
{
    Fn_struct my_fn_struct4 {"fn(a,b)", {std::bind( fn, 1, std::placeholders::_1) }};
    
}

/*
 
#include <functional>
#include <string>
  
 using namespace std;

 int fn( int a, const int & b ) {            // const qualifier
   return a+b; }

 struct Fn_struct {
     string name {};
     // function<int (int,int&)> my_fn {};
     function<decltype(fn)> my_fn {};
 };

 int main()
 {
     Fn_struct my_fn_struct1 {"fn(a,b)", function<decltype (fn)> {fn} };
     Fn_struct my_fn_struct2 {"fn(a,b)", {fn} };
     Fn_struct my_fn_struct3 {"fn(a,b)", {bind( fn, 1, 2) }};
     auto fn_b = bind( fn, 1, placeholders::_1 );
       // obj names edited
     Fn_struct my_fn_struct4 {"fn(a,b)", {fn_b} };
     Fn_struct my_fn_struct5 {"fn(a,b)", {bind( fn, 1, placeholders::_1) }};

 }
 
 */
