#include <iostream>
#include <cmath>

using namespace std;

// توابع ریاضی
double jam(double num1, double num2)
{
    return num1 + num2;
}

double tafrigh(double num1, double num2)
{
    return num1 - num2;
}

double zarb(double num1, double num2)
{
    return num1 * num2;
}

double taghsim(double num1, double num2)
{
    return num1 / num2;
}

double tavan(double paye, double tavanNum)
{
    return pow(paye, tavanNum);
}

double radical(double num)
{
    if (num >= 0)
        return sqrt(num);
    else
        return -1;
}

int main()
{
    int programType;
    cout << "Choose type of program\n1. simple calculator\n2. check prime\n3. calculate bmm\n"
         << "4. calculate kmm\n5. mathematical phrase\n6. make function";
    cin >> programType;

    switch (programType)
    {
    case 1:
        cout << "\nresult: " << SimpleCalculator();
        break;
    case 2:
        if (CheckPrime())
            cout << "The number is prime :)";
        else
            cout << "The number is not prime :(";
        break;
    case 3:
        cout << "\nresult: " << CalculateKmm();
        break;
    case 4:
        cout << "\nresult: " << CalculateBmm();
        break;
    case 5:
        cout << "\nresult: " << CalCualtePhrase();
        break;
    default:
        break;
    }

    return 0;
}

int SimpleCalculator()
{
    double num1, num2;
    char amalgar;
    cout << "\t+ - * / ^ |\nyek adad, amalgar va adad vard konid: ";
    cin >> num1 >> amalgar >> num2;
    switch (amalgar)
    {
    case '+':
        cout << jam(num1, num2);
        break;
    case '-':
        cout << tafrigh(num1, num2);
        break;
    case '*':
        cout << zarb(num1, num2);
        break;
    case '/':
        if (num2 != 0)
            cout << taghsim(num1, num2);
        else
            cout << "makhraje sefr nadarim :)\n";
        break;
    case '^':
        cout << tavan(num1, num2);
        break;
    case '|':
        int j = jazr(num1);
        if (j > 0)
            cout << jazr(num1);
        else
            cout << "jazre manfi nadaarim :)\n";
        break;
    default:
        cout << "retry\n";
        HandleAmalgar();
    }
}

bool CheckPrime()
{
    int num;
    cout << "enter num";
    cin >> num;
    int num_sqrt = sqrt(num);
    bool isPrime = true;

    for (int i = 2; i <= num_sqrt; i++)
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    return isPrime;
}

bool CalculateKmm()
{
    int num1, num2;
    cout << "enter two nums";
    cin >> num1 >> num2;

    // set bigger one in num1
    if (num2 > num1)
    {
        num2 = num1 + num2;
        num1 = num2 - num1;
        num2 = num2 - num1;
    }

    for (int i = num1;; i++)
        if (num1 % i == 0 && num2 % i == 0)
            return i;
}

bool CalculateBmm()
{
    int num1, num2;
    cout << "enter two nums";
    cin >> num1 >> num2;

    // set bigger one in num1
    if (num2 > num1)
    {
        num2 = num1 + num2;
        num1 = num2 - num1;
        num2 = num2 - num1;
    }

    for (int i = num2;; i--)
        if (num1 % i == 0 && num2 % i == 0)
            return i;
}

int CalCualtePhrase()
{
    string phrase;
    cout << "enter your mathematical phrase";
    cin >> phrase;

    while (!isAmalgar(phrase[i]))
    {
        while (isAmalgar(phrase))
        {
            
            /* code */
        }
        
    }
}

bool isAmalgar(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}