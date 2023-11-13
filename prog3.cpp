#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;


class Node
{
public:
    Node(int value) { data = value; }
    Node* nextNode;
    int data;
};


class Stack
{
public:
    Stack() { top = nullptr; }

    static void EmptyAccess()
    {
        cout << "Error trying to pop on empty stack" << endl;
        exit(42);
    }

    bool isEmpty() { return top == nullptr; }

    void push(int value)
    {
        if (isEmpty()) { top = new Node(value); }
        else
        {
            Node* oldTop = top;
            top = new Node(value);
            top->nextNode = oldTop;
        }
    }

    int pop()
    {
        if(isEmpty()) { Stack::EmptyAccess(); }
        else
        {
            Node* topReturning = top;
            top = top->nextNode;
            int returningData = topReturning->data;
            delete topReturning;
            return returningData;
        }
    }

protected:
    Node* top;
};


void postfixStackAdd(Stack* stack)
{
    int add1 = stack->pop();
     int add2 = stack->pop();
    stack -> push(add2+add1);
}


void postfixStackMultiAdd(Stack* stack)
{
  int sum = 0;
  int count = stack->pop();
    for(int i=0; i<count; i++)
      {
         int add = stack->pop();
          sum += add;
      }
  stack->push(sum);
  
}


void postfixStackMultiply(Stack* stack)
{
  int mult1 = stack->pop();
     int mult2 = stack->pop();
   
    stack -> push(mult2*mult1);
}


void postfixStackSubtract(Stack* stack)
{
    int sub1 = stack->pop();
     int sub2 = stack->pop();
    
    stack -> push(sub2-sub1);
}


void postfixStackDivide(Stack* stack)
{
    int div1 = stack->pop();
     int div2 = stack->pop();
  
    stack -> push(div2/div1);
}


void postfixStackPower(Stack* stack)
{
  int pow1 = stack->pop();
     int pow2 = stack->pop();
    stack -> push(pow(pow2,pow1));
}


void postfixStackFactorial(Stack* stack)
{
      int fac = stack->pop();
      int num = 1;
    for(int i=1;i<=fac;i++)
    {    
      num=num*i;    
  }    
    stack -> push(num);
}


void postfixStackIncrement(Stack* stack)
{
  int inc = stack->pop();
  inc++;
  stack -> push(inc);

}


void postfixStackModulo(Stack* stack)
{
  int mod1 = stack->pop();
     int mod2 = stack->pop();
    stack -> push(mod2%mod1);
}


void postfixStackDecrement(Stack* stack)
{
  int dinc = stack->pop();
  dinc--;
  stack -> push(dinc);
}


void postfixStackAbsoluteValue(Stack* stack)
{
    int abs = stack->pop();
      if(abs < 0)
      {
        stack -> push(abs*-1);
      }
    else
        stack -> push(abs);
     
}


// Don't edit any of the code below this.
void postfixStackPrint(Stack* stack)
{
    cout << stack->pop() << endl;
}


void processTerm(string term, Stack* stack)
{
    if (term == "+")        postfixStackAdd(stack);

    else if (term == "&+")  postfixStackMultiAdd(stack);

    else if (term == "*")   postfixStackMultiply(stack);

    else if (term == "-")   postfixStackSubtract(stack);

    else if (term == "/")   postfixStackDivide(stack);

    else if (term == "^")   postfixStackPower(stack);

    else if (term == "!")   postfixStackFactorial(stack);

    else if (term == "++")  postfixStackIncrement(stack);

    else if (term == "%")   postfixStackModulo(stack);

    else if (term == "--")  postfixStackDecrement(stack);

    else if (term == "||")  postfixStackAbsoluteValue(stack);

    else if (term == "p")   postfixStackPrint(stack);

    else stack->push(stoi(term));
}


void processPostfixExpression(string inputString)
{
    Stack* stack = new Stack();

    char space = ' ';
    stringstream sstream(inputString);
    string term;

    while (getline(sstream, term, space)) { processTerm(term, stack); }
}


int main()
{
    string postfixInputString;
    getline(cin, postfixInputString);
    processPostfixExpression(postfixInputString);
}