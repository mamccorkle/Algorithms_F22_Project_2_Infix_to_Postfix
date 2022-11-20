// University of Arkansas at Little Rock
// Department of Computer Science
// CPSC 2380-9S1: Algorithms
// Fall 2022
// Project 2: Infix to Postfix Conversion
// Due Date: December 1, 2022
// Name: Mark McCorkle
// T-number (Last 4 Digits): 4926

// Description of the Program (2-3 sentences): This program converts infix
// arithmetic expressions to postfix. Each operator and operand is
// separated by at least one spaces

// Date Written: 20221112
// Date Revised: 202211??

// Based on Code Provided by Dr. Chia-Chu Chiang

// Written Using:
//
//      IDE: CLion 2021.2.3     - VERIFIED
//      IDE: XCode              - UNVERIFIED
//      IDE: Visual Studio 2022 - UNVERIFIED
//      IDE: Linux via g++      - UNVERIFIED
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// you can type an arithmetic expression with no, one or more than one spaces
// between each operator and operand
// If no spaces is given between each operator and operand, this function will add
// spaces to them
string InfixToPostfix(char* str)
{
    stack<char> operatorStack;
    string returnExpression{ "" };

    int i{ 0 };
    while(str[i] != '\0')
    {
        //std::cout << str[i] << ' ';

        if( isdigit(str[i]) )
        {
            //std::cout << "digit ";
            returnExpression += str[i];
        }
        else if( isalpha(str[i]) )
        {   // Add number to end of postfix expression
            //std::cout << "alpha ";
            returnExpression += str[i];
        }
        else
        {
            // if the token is a '('
            if(str[i] == '(')
            {
                // push onto stack
                //std::cout << '(' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }

            // if the token is a ')'
            if(str[i] == ')')
            {   // push onto stack
                //std::cout << ')' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }

            // if the token is a '+'
            if(str[i] == '+')
            {   // push onto stack
                //std::cout << '+' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }

            // if the token is a '-'
            if(str[i] == '-')
            {   // push onto stack
                //std::cout << '-' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }

            // if the token is a '*'
            if(str[i] == '*')
            {   // push onto stack
                //std::cout << '*' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }

            // if the token is a '/'
            if(str[i] == '/')
            {   // push onto stack
                //std::cout << '/' << ' ';
                returnExpression += str[i];
                operatorStack.push(str[i]);
            }
        }

        i++;
    }
    std::cout << '\n';

    return returnExpression;
}

char* AddDelimitersToStr(char* str)
{
    int spacesNeeded = 0;
    int length = 0;
    while (str[length] != '\0')  // hit enter on my computer,
    {
        // it produces \0, maybe your computer may produce different
        if (str[length] != ' ')
            spacesNeeded = spacesNeeded + 1;
        length = length + 1;
    }

    int size = length + spacesNeeded + 1;
    char *adjustedStr = new char[size];

    // insert delimiters between operands and operators
    int newInx = 0;
    for (int inx = 0; inx < length; inx++) {
        if (str[inx] != ' ') {
            adjustedStr[newInx] = str[inx];
            newInx = newInx + 1;
            adjustedStr[newInx] = ' ';
            newInx = newInx + 1;
        }
    }
    adjustedStr[newInx] = '\0';

    //cout << "string with delimteres: " << adjustedStr << endl;
    // system("PAUSE");
    return adjustedStr;
}

int main()
{
    // input arithmetic expression should be less than 79 characters
    char* str = new char[80];

    // Type control-c to exit the loop:
    while (1)
    {
        // you can assume legal arithemic expressions only
        cout << "Enter an arithmetic equation..." << endl;
        cin.getline(str, 80);
        str = AddDelimitersToStr(str);
        cout << InfixToPostfix(str) << endl;
    }

    return 0;
}
