#include<iostream>
using namespace std;
int main(){
    double num1, num2;
    char op;
    double result;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout <<"Choose an operation (+, -, *, /):";
    cin >> op;

    switch(op){
        case '+':
            result = num1 + num2 ;
            break;

        case '-':
            result = num1 - num2 ;
            break;

        case '*':
            result = num1 * num2 ;
            break;

        case '/':
            if(num2 != 0){
                result = num1 / num2 ;
            }else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            return 1;
    }
    cout << "The result is: " << result << endl;

    return 0;
}