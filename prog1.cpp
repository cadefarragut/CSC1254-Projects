#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <iterator>
using namespace std;


void fizzbuzzy(int max, int step, int divisorOne, int divisorTwo)
{
  if(step>0 && max>0 && divisorOne>=2 && divisorTwo>=2 && divisorOne!=divisorTwo)
  {
    
for(int i=1;  i<=max; i+=step)
  {
    if(i%42==0)
    {
      cout<<"Answered"<<endl; break; }
    if(i%divisorOne == 0 && i%divisorTwo == 0)
      cout<<"FizzBuzz"<<endl;
    else if (i%divisorOne==0 && i%divisorTwo != 0)
      cout<<"Fizz"<<endl;
      
    else if (i%divisorOne!=0 && i%divisorTwo == 0)
    
      cout<<"Buzz"<<endl;
    
    else 
        cout<<i<<endl;
    }
}
  else
    cout<<"Bad Input"<<endl;
  }


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Don't edit the main function
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main()
{
    string inputString;
    getline(cin, inputString);
    istringstream ss(inputString);

    string tempVariable;
    
    ss >> tempVariable;
    int max = stoi(tempVariable);
    
    ss >> tempVariable;
    int step = stoi(tempVariable);
    
    ss >> tempVariable;
    int divisorOne = stoi(tempVariable);
    
    ss >> tempVariable;
    int divisorTwo = stoi(tempVariable);

    fizzbuzzy(max, step, divisorOne, divisorTwo);
}

// Example Input 1:
// 12 1 3 4
//
// Example Output 1:
// 1
// 2
// Fizz
// Buzz
// 5
// Fizz
// 7
// Buzz
// Fizz
// 10
// 11
// FizzBuzz

// Example Input 2:
// 0 0 2 4
//
// Example Output 2:
// Bad Input

// Example Input 3:
// 24 5 4 8
//
// Example Output 3:       
// 1
// 6
// 11
// FizzBuzz
// 21