#include<bits/stdc++.h> 
using namespace std;

class base {
    int arr[15];
};

class b1: public base {};
class b2: public base {};
class derived: public b1, public b2 {};

int main(void) {
    
    cout<< sizeof(derived);
    
    return 0;
}