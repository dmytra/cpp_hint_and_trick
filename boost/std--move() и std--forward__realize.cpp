#include <iostream>

// https://lnkd.in/dR6rHtiR
// https://www.linkedin.com/posts/quasar-chunawala_how-are-%F0%9D%9A%9C%F0%9D%9A%9D%F0%9D%9A%8D%F0%9D%9A%96%F0%9D%9A%98%F0%9D%9A%9F%F0%9D%9A%8E-and-%F0%9D%9A%9C%F0%9D%9A%9D%F0%9D%9A%8D%F0%9D%9A%8F-activity-7266462317679177730-FeJN?utm_source=share&utm_medium=member_desktop

// How are std::move() and std::forward() implemented?

// std::move unconditionally casts its input to an rvalue reference.

// std::move is implemented as:
// static_cast<std::remove_reference_t<T>&&>(arg)

// It removes any referenceness and converts to the corresponding
// rvalue reference type (removes any & and adds &&)

// std::forward is implemented as:
// static_cast<T&&>(arg)

// It only adds rvalue refereness to the passed type parameter.

template <typename T>
void f(T&& arg) {}

template <typename T>
void g(T&& arg)
{
    f(std::forward<T>(arg));
}

struct X {};

int main()
{
    X v;
    const X c;

    g(v);  // T and arg are deduced as X&, forward has no effect and calls f(X&)
    g(c);  // T and arg deduced as const X&, forward has no effect and calls f(const X&)
    g(X{}); //T and arg are deduced as X, forward is equivalent to move and calls f(X&&)
    g(std::move(v)); // T and arg are deduced as X, forward is equivalent to move and Calls f(X&&)
    g(std::move(c)); // T and arg are deduced as const X, Calls f(const X&&)
    return 0;
}

