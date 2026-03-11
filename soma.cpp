#include <iostream>

using namespace std;

int soma(int a, int b){
    return a + b;
}

int main(){
    int A, B;
    cin >> A;
    cin >> B;
    cout << "X = " << soma(A, B) << "\n";
    return 0;
}