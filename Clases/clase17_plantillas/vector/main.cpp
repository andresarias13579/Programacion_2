#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    // class vector<int> vecInt {15,91,14,66,31,5,18,21,74};
    // class vector<int>vecInt (10,70);
    // cout << vecInt[0] << endl;
    class vector<int> vecInt;
    vecInt.push_back(16);
    vecInt.push_back(12);
    vecInt.push_back(81);
    vecInt.push_back(41);
    vecInt.push_back(25);
    vecInt.push_back(22);
    vecInt.push_back(17);
    vecInt.push_back(9);
    vecInt.push_back(29);

    vecInt[3]=777;

    vecInt.at(5)=555;

    vector<int>::iterator it1=vecInt.begin();
    vector<int>::iterator it2=vecInt.begin();
    it1 +=3;
    it2 +=5;
    vecInt.insert(it1,3,101);

    for (int v: vecInt) {
        cout << v << endl;
    }

    cout<<"Numero de elementos: "<<vecInt.size()<<endl;
    cout<<"Capacidad: "<<vecInt.capacity()<<endl;

    vecInt.shrink_to_fit();
    cout<<"Numero de elementos: "<<vecInt.size()<<endl;
    cout<<"Capacidad: "<<vecInt.capacity()<<endl;

    return 0;
}