#include <iostream>
using namespace std;
#include <iomanip>
#include <list>
#include <iterator>

int main() {
    class list <double> listDouble {23.74,72.875,56.99,5.5};

    listDouble.push_back(333.333);
    listDouble.push_front(111.11);

    list<double>::iterator it=listDouble.begin();

    it ++;
    it ++;
    it ++;
    cout<<*it<<endl;
    it--;
    cout<<*it<<endl;

    cout.precision(2);
    cout<<fixed;
    for (double v : listDouble) {
        cout << v << endl;
    }

    listDouble.sort();

    for (double v : listDouble) {
        cout << v << endl;
    }

    class list<double>listDb2{12.63,6.33,77.77,15.15};
    listDb2.sort();
    listDouble.merge(listDb2);

    for (double v : listDouble) {
        cout << v << endl;
    }

    return 0;
}