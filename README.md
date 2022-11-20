# UALR - CPSC 2380-9S1: Algorithms - F22 - Project 2: Infix to Postfix Conversion

## CPSC 2380-9S1 Project 2 Topics:

> Algorithms Project 2: Infix to Postfix Conversion
> 
> &nbsp;&nbsp;[raj457036.github.io](https://raj457036.github.io/Simple-Tools/prefixAndPostfixConvertor.html)
> 
> &nbsp;&nbsp;[iamsajan.com](https://infixtopostfix.iamsajan.com/)
> 
> &nbsp;&nbsp;[calcont.in](https://www.calcont.in/Conversion/infix_to_postfix)

#### Instructions:

> Given the code of main.cpp, complete the function of InfixToPostfix(str). The main function will take an arithmetic expression using getline(). The arithmetic expression can have operators (+, -, (, ), *, /) and single digit numbers (0-9) only involved in arithmetic calculations. The arithmetic expression can take spaces or no spaces between operators and operands. The main function will invoke AddDelimetersToStr(str) to insert spaces to the expression to separate operators and operands if there is no spaces in it. Your task is to complete string InfixToPostfix(str) to return the arithmetic expression in postfix notation to the main(). The main in this program runs infinitely until you type control-c to exit the execution. You are welcome to use stack in C++ STL to implement this project. In addition, implement the functions all you need in the InfixToPostfix(str) function.
> 
> ```cpp
> #include <iostream>
> #include <string>
> #include <stack> 
> 
> 
> using namespace std;
> 
> string InfixToPostfix(char* str)
> {
>     return "";
> }
> 
> char* AddDelimetersToStr(char* str) {
>     int spacesNeeded = 0;
>     int length = 0;
>     while (str[length] != '\0')  // hit enter on my computer,
>     {
>         // it produces \0, maybe your computer may produce different
>         if (str[length] != ' ')
>             spacesNeeded = spacesNeeded + 1;
>         length = length + 1;
>     }
> 
>     int size = length + spacesNeeded + 1;
>     char *adjustedStr = new char[size];
> 
>     // insert delimeters between operands and operators
>     int newInx = 0;
>     for (int inx = 0; inx < length; inx++) {
>         if (str[inx] != ' ') {
>             adjustedStr[newInx] = str[inx];
>             newInx = newInx + 1;
>             adjustedStr[newInx] = ' ';
>             newInx = newInx + 1;
>         }
>     }
>     adjustedStr[newInx] = '\0';
> 
>     //cout << "string with delimteres: " << adjustedStr << endl;
>     // system("PAUSE");
>     return adjustedStr;
> }
> 
> int main()
> {
>     // input arithmetic expression should be less than 79 characters
>     char* str = new char[80];
>     while (1) // type ccontrol_c to exit the loop
>     {
>         // you can assume legal arithemic expressions only
>         cout << "Enter an arithmetic equation..." << endl; cin.getline(str, 80);
>         str = AddDelimetersToStr(str);
>         cout << InfixToPostfix(str) << endl;
>     }
> 
>     return 0;
> }
> ```

#### Submission Due Date:

>  Source Due: Thursday, December 1, 2022 10:50 AM
