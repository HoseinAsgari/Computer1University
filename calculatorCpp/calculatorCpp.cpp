#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isNum(char c)
{
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

bool isAmalgar(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int Calculate(int num1, char amalgar, int num2)
{
    switch (amalgar)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
            cerr << "Error: devided by zero";
        return num1, num2;
    case '^':
        return pow(num1, num2);
    default:
        cerr << "Error in line 253";
        return 0;
    }
}

int SimpleCalculator()
{
    double num1, num2;
    char amalgar;
    cout << "\t+ - * / ^\nEnter a num, then amalgar and another num:\n";
    cin >> num1 >> amalgar >> num2;
    switch (amalgar)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
            return num1 / num2;
        else
            cerr << "Error: devided by zero";
    case '^':
        return pow(num1, num2);
    default:
        cout << "retry\n";
        SimpleCalculator();
        return 0;
    }
}

bool CheckPrime()
{
    int num;
    cout << "enter num: ";
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

int CalculateKmm()
{
    int num1, num2;
    cout << "enter two nums:\n";
    cin >> num1 >> num2;

    // set bigger one in num1
    if (num2 > num1)
    {
        num2 = num1 + num2;
        num1 = num2 - num1;
        num2 = num2 - num1;
    }

    for (int i = num1;; i++)
        if (i % num1 == 0 && i % num2 == 0)
            return i;
}

int CalculateBmm()
{
    int num1, num2;
    cout << "enter two nums:\n";
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

int CalculateMathPhrase(string phrase)
{
    int i;
    for (i = 0; i < phrase.length(); i++)
        if (isAmalgar(phrase[i]))
            break;

    if (i >= phrase.length())
    {
        cerr << "Error: No operator found in the phrase.\n";
        return 0;
    }

    string num1_str = phrase.substr(0, i);
    int num1 = atoi(num1_str.c_str());

    string num2_str = phrase.substr(i + 1);
    int num2 = atoi(num2_str.c_str());

    return Calculate(num1, phrase[i], num2);
}

int CalculatePhrase(string phrase)
{
    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] == '(')
        {
            int j = i + 1;
            while (phrase[j] != ')')
            {
                j++;
                if (j >= phrase.length())
                {
                    cerr << "Error: Missing closing parenthesis.\n";
                    return 0;
                }
            }
            string mini_phrase = phrase.substr(i + 1, j - (i + 1));
            int mini_result = CalculateMathPhrase(mini_phrase);
            phrase.replace(i, j - i + 1, to_string(mini_result));
            i=j;
        }
    }

    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] == '^')
        {
            int start = i - 1;
            while (isNum(phrase[start]) && start != 0)
                start--;
            int end = i + 1;
            while (isNum(phrase[end]) && end != phrase.length() - 1)
                end++;

            phrase.replace(start, end - start, to_string(CalculateMathPhrase(phrase.substr(start, end - start))));
        }
    }

    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] == '*' || phrase[i] == '/')
        {
            int start = i - 1;
            while (start > 0 && isNum(phrase[start]))
                start--;

            int end = i + 1;
            while (end < phrase.length() && isNum(phrase[end]))
                end++;

            int length = end - start;

            string result = to_string(CalculateMathPhrase(phrase.substr(start, length)));
            phrase.replace(start, length, result);

            i = start + result.length() - 1;
        }
    }

    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] == '+' || phrase[i] == '-')
        {
            int start = i - 1;
            while (start > 0 && isNum(phrase[start]))
                start--;

            int end = i + 1;
            while (end < phrase.length() && isNum(phrase[end]))
                end++;

            int length = end - start;

            string result = to_string(CalculateMathPhrase(phrase.substr(start, length)));
            phrase.replace(start, length, result);

            i = start + result.length() - 1;
        }
    }

    return atoi(phrase.c_str());
}

int HandleCalculatePhrase()
{
    string phrase;
    cout << "enter your mathematical phrase:";
    cin >> phrase;
    return CalculatePhrase(phrase);
}

int CreateFunction()
{
    int num;
    string function;
    cout << "Enter function(variable should be 'x'):";
    cin >> function;
    cout << "\nDone! Please enter a number:";
    cin >> num;

    for (int i = 0; i < function.length(); i++)
        if (function[i] == 'x')
            function.replace(i, 1, to_string(num));

    int result = CalculatePhrase(function);

    return result;
}

int main()
{
    int programType, result;
    cout << "Choose type of program\n1. simple calculator\n2. check prime\n3. calculate bmm\n"
         << "4. calculate kmm\n5. mathematical phrase\n6. make function\ntype: ";
    cin >> programType;

    switch (programType)
    {
    case 1:
        result = SimpleCalculator();
        cout << "\nresult: " << result;
        break;
    case 2:
        if (CheckPrime())
            cout << "The number is prime :)";
        else
            cout << "The number is not prime :(";
        break;
    case 3:
        result = CalculateBmm();
        cout << "\nresult: " << result;
        break;
    case 4:
        result = CalculateKmm();
        cout << "\nresult: " << result;
        break;
    case 5:
        result = HandleCalculatePhrase();
        cout << "\nresult: " << result;
        break;
    case 6:
        result = CreateFunction();
        cout << "\nresult: " << result;
    default:
        break;
    }
    return 0;
}
