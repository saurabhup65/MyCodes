#include <iostream>
#include <cmath>  // for sin, cos, tan, log, sqrt, etc.
#include <limits> // for numeric_limits

using namespace std;

void displayMenu();
double performBasicArithmetic(double num1, double num2, char op);
double performAdvancedOperation(double num, char op);
void clearInputBuffer();

int main()
{
    int choice;
    double num1, num2;
    char operation;

    while (true)
    {
        displayMenu();

       
        cout << "Enter your choice: ";
        cin >> choice;

      
        if (cin.fail())
        {
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter operation (+, -, *, /): ";
            cin >> operation;
            cout << "Enter second number: ";
            cin >> num2;

            if (operation == '/' && num2 == 0)
            {
                cout << "Error! Division by zero is not allowed." << endl;
                break;
            }

            cout << "Result: " << performBasicArithmetic(num1, num2, operation) << endl;
            break;

        case 2:
            cout << "Enter number: ";
            cin >> num1;
            cout << "Choose operation (s for sin, c for cos, t for tan, l for log, r for sqrt): ";
            char advancedOp;
            cin >> advancedOp;

            if (advancedOp == 't' && cos(num1) == 0)
            {
                cout << "Error! tan(" << num1 << ") is undefined (division by zero)." << endl;
                break;
            }

            cout << "Result: " << performAdvancedOperation(num1, advancedOp) << endl;
            break;

        case 3: // Exponentiation
            cout << "Enter base: ";
            cin >> num1;
            cout << "Enter exponent: ";
            cin >> num2;
            cout << "Result: " << pow(num1, num2) << endl;
            break;

        case 4: // Logarithmic Operations
            cout << "Choose logarithm base (n for natural log, t for log base 10): ";
            char logOp;
            cin >> logOp;
            if (logOp == 'n')
            {
                cout << "Enter number: ";
                cin >> num1;
                if (num1 <= 0)
                {
                    cout << "Error! Natural logarithm is undefined for non-positive numbers." << endl;
                }
                else
                {
                    cout << "Result: " << log(num1) << endl;
                }
            }
            else if (logOp == 't')
            {
                cout << "Enter number: ";
                cin >> num1;
                if (num1 <= 0)
                {
                    cout << "Error! Logarithm is undefined for non-positive numbers." << endl;
                }
                else
                {
                    cout << "Result: " << log10(num1) << endl;
                }
            }
            else
            {
                cout << "Invalid operation choice!" << endl;
            }
            break;

        case 5: // Exit
            cout << "Exiting calculator. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please choose a number between 1 and 5." << endl;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << "\nAdvanced Calculator\n";
    cout << "====================\n";
    cout << "1. Basic Arithmetic (+, -, *, /)\n";
    cout << "2. Advanced Operations (sin, cos, tan, log, sqrt)\n";
    cout << "3. Exponentiation (x^y)\n";
    cout << "4. Logarithmic Operations (ln, log10)\n";
    cout << "5. Exit\n";
}

double performBasicArithmetic(double num1, double num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            cout << "Error! Division by zero!" << endl;
            return numeric_limits<double>::infinity(); // Return infinity to indicate error
        }
        return num1 / num2;
    default:
        cout << "Invalid operator!" << endl;
        return 0;
    }
}

// Perform advanced mathematical operations
double performAdvancedOperation(double num, char op)
{
    switch (op)
    {
    case 's': // sin
        return sin(num);
    case 'c': // cos
        return cos(num);
    case 't': // tan
        return tan(num);
    case 'l': // natural log (ln)
        if (num <= 0)
        {
            cout << "Error! Logarithm is undefined for non-positive numbers." << endl;
            return 0;
        }
        return log(num);
    case 'r': // square root
        if (num < 0)
        {
            cout << "Error! Square root of a negative number is undefined." << endl;
            return 0;
        }
        return sqrt(num);
    default:
        cout << "Invalid operation!" << endl;
        return 0;
    }
}

// Function to clear the input buffer in case of invalid input
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
