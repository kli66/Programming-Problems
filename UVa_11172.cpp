#include <iostream>

using namespace std;

int main(){
    int a,b,TC;
    cin >> TC;
    while (TC--){
        cin >> a >> b;
        (a > b)?cout<<">\n":(a < b)?cout<<"<\n":cout<<"=\n";
    }
}
