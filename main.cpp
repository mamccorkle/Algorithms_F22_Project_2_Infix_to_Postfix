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
#include <iomanip>

#define ALIGN  std::setw(35) << std::left

int precedenceLevel(char o)
{
    switch( o )
    {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
//        default:
//            return 9;
    }
}

// you can type an arithmetic expression with no, one or more than one spaces
// between each operator and operand
// If no spaces is given between each operator and operand, this function will add
// spaces to them
std::string InfixToPostfix(char* str)
{
    std::stack<char> operatorStack;
    std::string returnExpression;

    int i{ 0 };
    while(str[i] != '\0')
    {
        if( isdigit(str[i]) || isalpha(str[i]) )
        {   // Add number or alpha characters to the end of the postfix expression:
            returnExpression += str[i];
            returnExpression += ' ';
        }
        else if(str[i] != ' ')
        {   // If the character is not alphanumeric or a space we proceed:
            switch (str[i])
            {
                case '(':
                    operatorStack.push(str[i]);
                    break;
                case ')':
                    // Loop till we find the beginning parentheses adding each stack element to the output expression:
                    while(operatorStack.top() != '(')
                    {
                        returnExpression += operatorStack.top();
                        returnExpression += ' ';
                        operatorStack.pop();
                    }

                    // Remove the remaining beginning parenthesis:
                    if(operatorStack.top() == '(')
                        operatorStack.pop();

                    break;
                case '*':   // Fall-through by design
                case '/':   //          |
                case '+':   //          |
                case '-':   //          v
                    // TODO: FILL IN NOTES HERE...

                    // Check if the stack is empty, if it is, add to the stack:
                    if(!operatorStack.empty())
                    {
                        // Check the precedence level of the top element on the stack and compare to the input character
                        // If the stacks top element is of lesser precedence, then push the character onto the stack.
                        //
//                        if (precedenceLevel(operatorStack.top()) < precedenceLevel(str[i]) || operatorStack.top() == '(')
//                            operatorStack.push(str[i]);
//                        else if(operatorStack.top() == '(')
//                            operatorStack.push(str[i]);
                        if (precedenceLevel(operatorStack.top()) < precedenceLevel(str[i]))
                            operatorStack.push(str[i]);
                        else if(operatorStack.top() == '(')    // This is here because the parenthesis has no precedence
                            operatorStack.push(str[i]);
                        else if (precedenceLevel(operatorStack.top()) == precedenceLevel(str[i]))
                        {
                            returnExpression += str[i];
                            returnExpression += ' ';
                        }
                        else
                        {
                            returnExpression += operatorStack.top();
                            returnExpression += ' ';
                            operatorStack.pop();

                            if (precedenceLevel(operatorStack.top()) == precedenceLevel(str[i]) ||
                                precedenceLevel(operatorStack.top()) < precedenceLevel(str[i]))
                            {
                                returnExpression += operatorStack.top();
                                returnExpression += ' ';
                                operatorStack.pop();
                            }

                            operatorStack.push(str[i]);
                        }
                    }
                    else
                        operatorStack.push(str[i]);
                    break;
                default:
                    break;
            }
        }

        i++;
    }

    // Empty the remainder of the stack:
    while(!operatorStack.empty())
    {
        returnExpression += operatorStack.top();
        returnExpression += ' ';
        operatorStack.pop();
    }

    // Remove the last space from the string:
    if(returnExpression[returnExpression.size() - 1] == ' ')
        returnExpression.pop_back();

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

    //std::cout << "String with delimiters: " << adjustedStr << std::endl;
    //system("PAUSE");
    return adjustedStr;
}

void printExample()
{
    std::cout << '\n';

    std::cout << ALIGN << "1+2" << " == " << ALIGN << "1 2 +" << ": ";
    InfixToPostfix("1+2") == "1 2 +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "1 + (2)" << " == " << ALIGN << "1 2 +" << ": ";
    InfixToPostfix("1 + (2)") == "1 2 +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "(1)-(2)" << " == " << ALIGN << "1 2 -" << ": ";
    InfixToPostfix("(1)-(2)") == "1 2 -" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "3 + (4/2) * (5 * 6)" << " == " << ALIGN << "3 4 2 / 5 6 * * +" << ": ";
    InfixToPostfix("3 + (4/2) * (5 * 6)") == "3 4 2 / 5 6 * * +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "((1+2))" << " == " << ALIGN << "1 2 +" << ": ";
    InfixToPostfix("((1+2))") == "1 2 +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "(1 * (4 / 2))" << " == " << ALIGN << "1 4 2 / *" << ": ";
    InfixToPostfix("(1 * (4 / 2))") == "1 4 2 / *" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "A+B*C+(D*E+F)*G" << " == " << ALIGN << "A B C * + D E * F + G * +" << ": ";
    InfixToPostfix("A+B*C+(D*E+F)*G") == "A B C * + D E * F + G * +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "A+B*(C/D-E)*(F+G*H)-I" << " == " << ALIGN << "A B C D / E - * F G H * + * + I -" << ": ";
    InfixToPostfix("A+B*(C/D-E)*(F+G*H)-I") == "A B C D / E - * F G H * + * + I -" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << ALIGN << "3+(4/2)*(5*6)" << " == " << ALIGN << "3 4 2 / 5 6 * * +" << ": ";
    InfixToPostfix("3+(4/2)*(5*6)") == "3 4 2 / 5 6 * * +" ? std::cout << "Pass\n" : std::cout << "*** FAIL ***\n";

    std::cout << '\n';
}

int main()
{
    // input arithmetic expression should be less than 79 characters
    char* str = new char[80];

    printExample();

    // Type control-c to exit the loop:
    while (1)
    {
        // you can assume legal arithemic expressions only
        std::cout << "Enter an arithmetic equation..." << std::endl;
        std::cin.getline(str, 80);
        str = AddDelimitersToStr(str);
        std::cout << InfixToPostfix(str) << std::endl;
    }

    return 0;
}
