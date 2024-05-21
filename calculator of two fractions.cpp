/*
# algorithm for fraction calculator #

Function GCD(a, b)
    While b != 0
        temp = b
        b = a % b
        a = temp
    End while
    Return a
End Function

Function isValidInput(num)
    For Each Character c in num
        If c Is Not a digit Or c is Not '/' Or c is Not '-' Or c is Not ' ' Then
            Return false
        End if
    End for
    Return true
End Function

Function getValidNumber(prompt)
    input = ""
    repeat this
        output prompt
        read input
    until isValidInput(input)
    Return input
End Function

Function parseArithmeticProcess(left1, left2, right1, right2, oper):
    output "Enter the arithmetic process like this ((n1/n2 + n3/n4) or (n1 * n2) or (n1 / n2/n3)): "
    input input_line
    Read first_num, oper, second_num FROM input_line
    cou1 = 0

    repeat this:
        if second_num = "0" And oper = "/":
            Output "Invalid input. Please enter valid numbers: "
            Read first_num, oper, second_num FROM input_line

        For Each character c in input_line:
            if c is a space:
                cou1++

        if cou1 != 2:
            repeat this:
                Output "Please make sure you enter only one space between the first number and operation and between operation and the second number: "
                input input_line
                Read first_num, oper, second_num from (input_line)

                Reset cou1 To 0

                For Each character c In input_line:
                    if c is a space:
                        cou1++

        if Not isValidInput(first_num) OR NOT isValidInput(second_num):
            Repeat:
                Output "Invalid input. Please enter valid operation: "
                input input_line
                Read first_num, oper, second_num FROM input_line
        else:
            Exit loop

    if '/' is found in first_num:
        left1 = stoi(Substr(first_num, 0, Find('/') in first_num))
        right1 = stoi(Substr(first_num, Find('/') + 1, End Of first_num))
    else:
        left1 = stoi(first_num)
        right1 = 1

    if '/' is found in second_num:
        left2 = stoi(Substr(second_num, 0, Find('/') in second_num))
        right2 = stoi(Substr(second_num, Find('/') + 1, End Of second_num))
    else:
        left2 = stoi(second_num)
        right2 = 1
    End Function
            

Main Function():
    left1 = left2 = right2 = 0
    While true:
        call parseArithmeticProcess(left1, left2, right1, right2, oper)
        if left2 = 0 Or left1 = 0 Or right2 = 0:
            output "Please enter a valid operation"
            Continue
       else:
            Break


    initialization left1, right1, left2, right2
    parse first_num
    parse second_num

    Switch oper[0]
        Case '+':
            numerator = (left1 * right2) + (left2 * right1)
            denominator = right1 * right2
        Case '-':
            numerator = (left1 * right2) - (left2 * right1)
            denominator = right1 * right2
        Case '*':
            numerator = left1 * left2
            denominator = right1 * right2
        Case '/':
            numerator = left1 * right2
            denominator = right1 * left2
        Defualt:
            output "Invalid choice."
            Return 1
    End Switch

    division = GCD(numerator, denominator)
    numerator = numerator / division
    denominator = denominator / division

    if absolute value of numerator > absolute value of denominator then
        sum = numerator % denominator
        output "Result: " + numerator / denominator + " " + sum + "/" + denominator
    else
        output "Result: " + numerator + "/" + denominator
    End if
End Function

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

// Function to find the greatest common divisor
int GCD(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if the input string is a valid number or fraction
bool isValidInput(const string& num) 
{
    for (char c : num) 
    {
        if (!(isdigit(c) || c == '/' || c == '-' || c == ' '))  // Check if the character is a digit, '/', '-', or space
        { 
            return false;
        }
    }
    return true;
}

// Function to handle input errors and prompt the user to enter a valid number
string getValidNumber(const string& prompt) 
{
    string input;
    do 
    {
        cout << prompt; // Prompt the user for input
        getline(cin, input); // Get input from the user
    } 
    while (!isValidInput(input)); // Repeat until valid input is received
    return input; // Return the valid input
}

// Function to parse and validate the arithmetic process
void parseArithmeticProcess(int& left1, int& left2,int &right1,int &right2 ,string& oper) 
{
    string input_line;
    cout << endl;
    cout << "Enter the arithmetic process like this ((n1/n2 + n3/n4) or (n1 * n2) or (n1 / n2/n3)) : ";
    cout << endl;

    // Input the first number, operation, and second number in one line
    getline(cin, input_line);
    stringstream calc(input_line);
    string first_num, second_num;
    calc >> first_num >> oper >> second_num;

    int cou1 = 0;

    // Validate the input numbers
    while (true) 
    {
        if (second_num == "0" && oper == "/") // this condition used to check if user input for ex: 1 / 0
        {
            cout << endl;
            input_line = getValidNumber("Invalid input. Please enter valid numbers: ");
            stringstream calc(input_line);
            calc >> first_num >> oper >> second_num;
        }

        for (int i = 0; i < input_line.length(); i++) // this loop to check how many spaces in the arithmetic process.
        {
            if (isspace(input_line[i])) 
            {
                cou1++;
            }
        }

        if (cou1 != 2) 
        {
            while (true) 
            {
                cou1 = 0;
                cout << endl;
                cout << "Please make sure you enter only one space between the first number and operation and between operation and the second number: ";
                cout << endl;
                getline(cin, input_line);
                stringstream calc(input_line);
                calc >> first_num >> oper >> second_num;

                for (int i = 0; i < input_line.length(); i++)
                {
                    if (isspace(input_line[i])) 
                    {
                        cou1++;
                    }
                }

                if (cou1 == 2){break;} 
                else {continue;}
            }
        }

        if (!isValidInput(first_num) || !isValidInput(second_num)) // this condition used to check if user input any thing except int numbers or fractions
        {
            while (true) 
            {
                cout << endl;
                input_line = getValidNumber("Invalid input. Please enter valid operation: ");
                stringstream calc(input_line);
                calc >> first_num >> oper >> second_num;
                if (isValidInput(first_num) && isValidInput(second_num)) 
                {
                    break;
                }
            }
        } 
        else {break;}
    }

    
    // Parsing the first number
    if (first_num.find('/') != string::npos) 
    {
        left1 = stoi(first_num.substr(0, first_num.find('/')));
        right1 = stoi(first_num.substr(first_num.find('/') + 1));
    }
    else 
    {
        left1 = stoi(first_num);
        right1 = 1;
    }

    // Parsing the second number
    if (second_num.find('/') != string::npos) 
    {
        left2 = stoi(second_num.substr(0, second_num.find('/')));
        right2 = stoi(second_num.substr(second_num.find('/') + 1));
    }
    else 
    {
        left2 = stoi(second_num);
        right2 = 1;
    }
}

int main() 
{
    int left1, left2, right1, right2;
    left1=left2=right2=0;
    string oper;
    while (true) 
    {
        parseArithmeticProcess(left1, left2,right1,right2 ,oper);
        if(left2 == 0 or left1 == 0 or right2 == 0)
        {
            cout << "please enter a valid operation"<<endl;
            continue;
        }
        else{break;}
    }

    int numerator, denominator;
    switch (oper[0]) 
    {
        case '+':
            numerator = (left1 * right2) + (left2 * right1);
            denominator = right1 * right2;
            break;
        case '-':
            numerator = (left1 * right2) - (left2 * right1);
            denominator = right1 * right2;
            break;
        case '*':
            numerator = left1 * left2;
            denominator = right1 * right2;
            break;
        case '/':
            numerator = left1 * right2;
            denominator = right1 * left2;
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    int division = GCD(numerator, denominator);
    numerator /= division;
    denominator /= division;

    if (abs(numerator) > abs(denominator)) 
    {
        int sum;
        sum = numerator % denominator;
        cout << endl;
        cout << "Result: " << numerator / denominator << " " << sum << "/" << denominator << endl;
    } 
    else 
    {
        cout << endl;
        cout << "Result: " << numerator << "/" << denominator << endl;
    }
    
}
