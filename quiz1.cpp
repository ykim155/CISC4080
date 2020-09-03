#include <iostream>
using namespace std;
int expo(int a, int n){
    int r = 0;
    if(n==0)
        return 1;
    r = expo(a, n-1);
    return a*r;
}
int main(){
    cout << expo(2,3);
}