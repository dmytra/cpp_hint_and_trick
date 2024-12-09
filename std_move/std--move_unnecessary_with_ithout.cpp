#include <iostream>

class Thing
{
public:
	Thing() { std::cout << " Thing() " << this << '\n'; }

	Thing(const Thing&) { std::cout << " Thing(const Thing&)\n"; }
	Thing& operator=(const Thing&)
	{
		std::cout << " operator=(const Thing&)\n";
		return *this;
	}

	Thing(Thing&&) noexcept { std::cout << " Thing(Thing&&)\n"; }
	Thing& operator=(Thing&&) noexcept
	{
		std::cout << " operator=(Thing&&)\n";
		return *this;
	}

	~Thing() { std::cout << "~Thing() " << this << '\n'; }
};

Thing func()
{
    Thing t;
    // ...
    return std::move(t); // BAD: don’t do this
}

int main() 
{
    Thing t =  func();
    return 0; 
}

/*
Avoid unnecessary 𝐬𝐭𝐝::𝐦𝐨𝐯𝐞
godbolt.org/z/K3TocfdEP (with 𝐬𝐭𝐝::𝐦𝐨𝐯𝐞)
godbolt.org/z/brf63n94h (without 𝐬𝐭𝐝::𝐦𝐨𝐯𝐞)
https://www.linkedin.com/feed/

#include <iostream>

class Thing
{
public:
	Thing() { std::cout << " Thing() " << this << '\n'; }

	Thing(const Thing&) { std::cout << " Thing(const Thing&)\n"; }
	Thing& operator=(const Thing&)
	{
		std::cout << " operator=(const Thing&)\n";
		return *this;
	}

	Thing(Thing&&) noexcept { std::cout << " Thing(Thing&&)\n"; }
	Thing& operator=(Thing&&) noexcept
	{
		std::cout << " operator=(Thing&&)\n";
		return *this;
	}

	~Thing() { std::cout << "~Thing() " << this << '\n'; }
};

Thing func()
{
    Thing t;
    // ...
    return t; // Best performance (return value optimization (RVO) or move)
}

int main() 
{
    Thing t =  func();
    return 0; 
}

*/
