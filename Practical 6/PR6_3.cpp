#include<iostream>
#include<stack> 
#include<string>
using namespace std; 

int precedence(char op) // Returns the priority of an operator
{
    if(op=='+'||op=='-') // Checks for addition or subtraction
        return 1; // Gives lower precedence

    if(op=='*'||op=='/') // Checks for multiplication or division
        return 2; // Gives higher precedence

    if(op=='^') // Checks for exponentiation
        return 3; // Gives highest precedence

    return 0; // Returns zero for brackets or unknown characters
}

string infixToPostfix(string infix) // Converts infix expression to postfix
{
    stack<char> s; // Creates a stack to store operators
    string postfix=""; // Stores the final postfix expression

    for(char ch:infix) // Processes every character of the expression
    {
        if(ch==' ') // Checks for spaces
            continue; // Ignores spaces

        if(isalnum(ch)) // Checks whether the character is a number or letter
        {
            postfix+=ch; // Directly adds the operand to postfix
        }
        else if(ch=='(') // Checks for an opening bracket
        {
            s.push(ch); // Pushes opening bracket onto the stack
        }
        else if(ch==')') // Checks for a closing bracket
        {
            while(!s.empty()&&s.top()!='(') // Removes operators until opening bracket
            {
                postfix+=s.top(); // Adds the top operator to postfix
                s.pop(); // Removes that operator from the stack
            }

            if(!s.empty()&&s.top()=='(') // Checks whether opening bracket exists
                s.pop(); // Removes the opening bracket from the stack
        }
        else // Handles arithmetic operators
        {
            while(!s.empty()&&s.top()!='('&&precedence(s.top())>=precedence(ch)) // Checks operator precedence
            {
                postfix+=s.top(); // Adds higher or equal precedence operator
                s.pop(); // Removes that operator from the stack
            }

            s.push(ch); // Pushes the current operator onto the stack
        }
    }

    while(!s.empty()) // Processes remaining operators
    {
        postfix+=s.top(); // Adds the remaining operator to postfix
        s.pop(); // Removes the operator from the stack
    }

    return postfix; // Returns the converted postfix expression
}

int main() // Main function starts here
{
    string infix; // Stores the input infix expression
    getline(cin,infix); // Reads the complete expression including spaces

    cout<<"Postfix: "<<infixToPostfix(infix)<<endl; // Converts and prints postfix expression

    return 0;
}