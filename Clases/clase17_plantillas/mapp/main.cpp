#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>

using namespace std;

int main() {
    class map<int,double> mapa;

    mapa[9]=13.56;
    mapa[5]=103.55;
    mapa[3]=67.98;
    mapa[7]=123.45;

    for (auto m:mapa)
        cout<<setw(5)<<m.first<<setw(10)<<m.second<<endl;

    map<int,double>::iterator it;
    it = mapa.find(7); // it = mapa[7];
    if (it != mapa.end())
        cout<<setw(5)<<it->first
            <<setw(10)<<it->second<<endl;



    return 0;
}