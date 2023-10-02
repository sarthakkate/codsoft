
//************ TASK--2 *****************//

/*Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform*/

#include <iostream>

using namespace std;

int main()
{
    float num1,num2,result;
    char operation;

    cout<<"Entre First Number"<<endl;
    cin>>num1;


    cout<<"Entre An Operation(+,-*,/)"<<endl;
    cin>>operation;

    cout<<"Entre Second Number"<<endl;
    cin>>num2;

    switch(operation)
    {
        case '+':
            result=num1 + num2;
            cout<<"Result"<<num1<<"+"<<num2<<"="<<result<<endl;
            break;
        case '-':
            result=num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } 
            else 
            {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }
    return 0;
}
