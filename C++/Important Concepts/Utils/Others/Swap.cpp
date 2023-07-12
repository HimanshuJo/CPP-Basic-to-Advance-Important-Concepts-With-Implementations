/*
The swap() function is used to swap two numbers. 

By using this function, you do not need any third variable to swap two numbers.

Here is the syntax of swap() in C++ language,

   void swap(int variable_name1, int variable_name2);

If we assign the values to variables or pass user-defined values, 
   it will swap the values of variables but the value of variables 
   will remain same at the actual place.
*/

#include <bits/stdc++.h>

using namespace std;

void swapValue(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

void swapValueUsingXor(int *a, int *b){
   *a=*a^*b;
   *b=*a^*b;
   *a=*a^*b;
}

int main() {
   int x = 35, y = 75;
   int *ptr1=&x, *ptr2=&y;
   swapValue(x, y);
   cout<<x<<" "<<y<<endl;
   cout<<"-------"<<endl;
   swapValueUsingXor(ptr1, ptr2);
   cout<<x<<" "<<y<<endl;
}
