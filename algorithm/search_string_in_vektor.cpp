#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

// https://ru.stackoverflow.com/questions/730577/Помогите-подобрать-алгоритм/730644#730644

using namespace std;

void test(const string t)
{
    for(size_t l = (t.length()-1)/2, i = l; i > 0; --i)
    {
        string s = t.substr(i);
        if (t.find(s) == 0)
        {
            cout << "YES\n" << s << endl;
            return;
        }
    }
    cout << "NO\n";
}


int main()
{
    vector<string> s =
    {
        "abrakadabrabrakadabra",
        "acacacaca",
        "abcabc",
        "abababab",
        "tatbt"
    };
    for(auto t: s)
    {
        cout << "---- " << t << endl;;
        test(t);
    }
}
/*
 ---- abrakadabrabrakadabra
 YES
 abrakadabra
 ---- acacacaca
 YES
 acaca
 ---- abcabc
 NO
 ---- abababab
 YES
 ababab
 ---- tatbt
 NO
 Program ended with exit code: 0
 */

