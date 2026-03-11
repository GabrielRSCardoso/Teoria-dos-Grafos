/*
Read 2 variables, named A and B and make the sum of these two variables, assigning its result to the variable X. Print X as shown below. Print endline after the result otherwise you will get “Presentation Error”.

Input
The input file will contain 2 integer numbers.

Output
Print the letter X (uppercase) with a blank space before and after the equal signal followed by the value of X, according to the following example.

Obs.: don't forget the endline after all.
*/

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