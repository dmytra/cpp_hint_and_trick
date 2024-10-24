#include <iostream>
class Foo {
public: 
explicit Foo(char) {}
public: 
int value() const { 
return 10; 
}
}; 

template<typename T>
class Sum { 
public: 
// Calculate type returned by the function 'T::value() 
using Value = decltype(std::declval<T>().value()); 
public: 
Value result() const{ 
return m_value; 
}
void add(const T &value){ 
m_value += value.value(); 
}
private:
 Value m_value = {}; 
};
 
int main() { 
auto sum = Sum<Foo>{}; 
sum.add(Foo{'a'}); 
sum.add(Foo{'b'}); 
std::cout << sum.result() << std::endl; 
return 0; 
}
// https://www.linkedin.com/feed/update/urn:li:activity:7254386012154474496/?updateEntityUrn=urn%3Ali%3Afs_updateV2%3A%28urn%3Ali%3Aactivity%3A7254386012154474496%2CFEED_DETAIL%2CEMPTY%2CDEFAULT%2Cfalse%29

/*
 * 𝚜𝚝𝚍::𝚍𝚎𝚌𝚕𝚟𝚊𝚕 and 𝚍𝚎𝚌𝚕𝚝𝚢𝚙𝚎 often go hand in hand. 𝚜𝚝𝚍::𝚍𝚎𝚌𝚕𝚟𝚊𝚕 is used in metaprogramming to convert a type parameter into a reference. It can be especially useful when a type does not have a default constructor. The resulting reference can be used further, for example, to deduce the return type of a member function.

𝚍𝚎𝚌𝚕𝚝𝚢𝚙𝚎, on the other hand, is mainly used to detect the type of an expression. Moreover, you can specify a return type as 𝚍𝚎𝚌𝚕𝚝𝚢𝚙𝚎(𝚊𝚞𝚝𝚘) for perfect forwarding.

In the snippet below, the template class 𝚂𝚞𝚖 provides logic to sum up values from the passed objects. The resulting type is deduced based on the result of the 𝚃::𝚟𝚊𝚕𝚞𝚎() method.
*/


