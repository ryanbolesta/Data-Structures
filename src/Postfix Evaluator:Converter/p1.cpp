/****************************************************************************
   Author:               Ryan Bolesta                                     
   Due Date:             September 22, 2016                               
   Course:               CSC237                                           
   Professor Name:       Dr. Zhang                                        
   Assignment:           #1                                               
   File Name:            p1.cpp                                           
   Purpose:              Program gives user the option to evaluate a      
                         postfix expression of their choice, and convert  
                         an infix expression to postfix. Both operations  
                         are done via a C++ stack.                        
*****************************************************************************/	

#include<iostream>
#include<stack>
#include<string>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*
Function:     convert
Type:         string
Description:  Performs various stack operations to convert an infix expression
              to a postfix expression
Parameters:   string - expression - the infix expression
Returns:      string - postfix expression
*/ 
string convert(string expression);

/*
Function:     evaluate
Type:         int
Description:  Performs various stack operations to evaluate a postfix expression
Parameters:   string - expression - the user entered postfix expression
Returns:      int - the value of the expression
*/ 
int evaluate(string expression);

/*
Function:     isOperator
Type:         bool
Description:  checks if character is a +, -, or * operator.
Parameters:   char c - the character being checked
Returns:      true - character is an operator | false  - char is not operator
*/ 
bool isOperator(char c);

/*
Function:     doOperation
Type:         int
Description:  performs designated operation on two numbers
Parameters:   char c - the operator, num1 - first number, num2 - second number
Returns:      int - the result of the specified operation
*/ 
int doOperation(char op, int num1, int num2);

/*
Function:     priority
Type:         int
Description:  returns an integer value to designate the priority of an operator.
              used to determine stack operations in convert function
Parameters:   char c - the operator
Returns:      int - the priority of the operator
*/ 
int priority( char c);

int main(){



  cout<<"Please select an option: \n";
        cout<<"1) Evaluate Postfix Expression \n";
        cout<<"2) Convert infix to postfix \n";
        char cmd;
        cin>>cmd;
        cin.ignore();
        cout<<endl;
        
        switch(cmd){
         
                 case '1' :{
                         string expression;
                         cout<<"Enter postfix expression"<<endl;
                         getline(cin, expression);
                         int result = evaluate(expression);
                         cout<<"Output: "<<result<<endl;
                         break;
                         }
                 case '2' :{
                         string infix;
                         cout<<"Enter infix expression"<<endl;
                         getline(cin, infix);
                         string newExpression = convert(infix);
                         cout<<"Converted expression is: "<<newExpression<<endl;
                   break;
                         }
                 default:
                         cout<<"Invalid command, program terminating";
                         break;
        }
}
       
/*
Function:     convert
Type:         string
Description:  Performs various stack operations to convert an infix expression
              to a postfix expression
Parameters:   string - expression - the infix expression
Returns:      string - postfix expression
*/        
string convert(string expression){
        
        stack<char> operators;
        string newExpression;
        
        for(int i = 0; i < expression.length(); i++){
                char c = expression[i];
                
                if(c == ' ')
                        continue;
                else if(isdigit(c) || (c > 64 && c <= 90) || (c > 96 && c <= 122))
                        newExpression += c;
                else if(c == '(')
                        operators.push(c);
                else if (c == ')')
                {
                        while(!operators.empty() && operators.top() != '(')
                        {
                                newExpression += operators.top();
                                operators.pop();
                        }
                        operators.pop();
                }
                else if(isOperator(c))
                {
                        while (!operators.empty() && priority(operators.top()) <= priority(c))
                        {
                                newExpression += operators.top();
                                operators.pop();
                        }
                        operators.push(c);
                }
        }
        while (!operators.empty()) {
                newExpression += operators.top();
                operators.pop();
        }
        
        return(newExpression);    
}

/*
Function:     evaluate
Type:         int
Description:  Performs various stack operations to evaluate a postfix expression
Parameters:   string - expression - the user entered postfix expression
Returns:      int - the value of the expression
*/         
int evaluate(string expression){
        stack<int> numbers;

        for(int i = 0; i < expression.length(); i++){
                char c = expression[i];
                
                if(c == ' ')
                        continue;
                if(isdigit(c))
                        numbers.push(c - '0');
                else if(isOperator(c)){
                        int num2 = numbers.top();
                        numbers.pop();
                        int num1 = numbers.top();
                        numbers.pop();
                        numbers.push(doOperation(c, num1, num2));
                }
        }
        return(numbers.top());                    
}


/*
Function:     isOperator
Type:         bool
Description:  checks if character is a +, -, or * operator.
Parameters:   char c - the character being checked
Returns:      true - character is an operator | false  - char is not operator
*/ 
bool isOperator(char c){
        if(c == '+' || c == '-' || c == '*')
                return(true);
        return(false);
}

/*
Function:     doOperation
Type:         int
Description:  performs designated operation on two numbers
Parameters:   char c - the operator, num1 - first number, num2 - second number
Returns:      int - the result of the specified operation
*/ 
int doOperation(char op, int num1, int num2){
        if(op == '+')
                return(num1 + num2);
        if(op == '-')
                return(num1 - num2);
        else
                return(num1 * num2);
}

/*
Function:     priority
Type:         int
Description:  returns an integer value to designate the priority of an operator.
              used to determine stack operations in convert function
Parameters:   char c - the operator
Returns:      int - the priority of the operator
*/ 
int priority(char c){
        int p;
        if(c == '*')
                p = 1;     
        else if(c == '+' || c == '-')
                p = 2;    
        return p;
}
        