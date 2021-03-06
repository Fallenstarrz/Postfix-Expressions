// Postfix Expressions.cpp : Defines the entry point for the console application.
// Write a program that evaluates a postfix expression.  
// You may assume it is a valid expression such as 6 2 + 5 * 8 4 / -
// The program should read a postfix expression consisting of digits and operators into a string.
// Using a stack, the program should scan the expression and evaluate it.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	// Create stack
	stack<int> myStack;
	// Store expression
	string expression;

	// Get expression from user
	cout << "Please enter a Postfix Expression: ";
	getline(cin, expression);
	cout << expression;
	cout << endl;

	// Loop through the expression
	for (int i = 0; i < expression.length(); i++)
	{
		// If the char in the expression is a space, go to next char
		if (expression[i] == ' ')
		{
			continue;
		}
		// if char in expression is a number, push it onto the stack
		else if (isdigit(expression[i]))
		{
			// -'0' is to subtract the ascii character (48) from the number to make it the actual number we input
			myStack.push(expression[i] - '0');
			cout << "Added: " << myStack.top() << endl;
		}
		// If char in expression is an operator
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '%')
		{
			// Pop top of the stack and store it in variable num1
			int num1 = myStack.top();
			myStack.pop();
			// Pop top of the stack and store it in variable num2
			int num2 = myStack.top();
			myStack.pop();
			// Switch on the operator to perform operation
			switch (expression[i])
			{
				case '+':
				{
					myStack.push(num1 + num2);
					break;
				}
				case'-':
				{
					myStack.push(num1 - num2);
					break;
				}
				case '*':
				{
					myStack.push(num1 * num2);
					break;
				}
				case '/':
				{
					myStack.push(num1 / num2);
					break;
				}
				case '^':
				{
					myStack.push(pow(num1, num2));
					break;
				}
				case '%':
				{
					myStack.push(num1 % num2);
					break;
				}
			}
		}
	}
	// Print result
	int result = myStack.top();
	cout << "Result: " << result << endl;

	system("pause");

	return 0;
}

