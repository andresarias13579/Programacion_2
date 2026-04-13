#include <iostream>
#include <iomanip>

using namespace std;
//ejemplo de variables STATIC
void f() {
    int a=3;
    static int b=3;
    ++a;
    ++b;
    cout << "a = " <<setw(4)<< a << "   b = " <<setw(4)<< b << endl;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        f();
    }
    return 0;
}
/*
* a =    4   b =    4
a =    4   b =    5
a =    4   b =    6
a =    4   b =    7
a =    4   b =    8
 */