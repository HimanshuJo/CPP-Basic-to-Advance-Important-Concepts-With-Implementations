/*
std::string::c_str

Get C string equivalent
Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) 
representing the current value of the string object.

This array includes the same sequence of characters that make up the value of the string object 
plus an additional terminating null-character ('\0') at the end.
*/

// strings and c-strings
#include <iostream>
#include <cstring>
#include <string>

void cStrTest1(std::string &str){
    char *cstr = new char [str.length()+1];
    std::strcpy(cstr, str.c_str());

    // cstr now contains a c-string copy of str

    char *p = std::strtok(cstr," ");
    while(p!=0)
    {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
    }

    delete[] cstr;
}

void cStrTest2(std::string &str){
    char *cstr=new char[str.length()+1];
    strcpy(cstr, str.c_str());
    char *ptr=cstr;
    while(*ptr!='\0'){
    std::cout<<(*ptr)<<std::endl;
    *ptr++;
    }
    delete[] cstr;
}

int main ()
{
  std::string str ("Please split this sentence into tokens");
  cStrTest1(str);
  std::string str2 ("- This, a sample string.");
  std::cout<<std::endl;
  cStrTest2(str2);
  return 0;
}

/*
Output:
Please
split
this
sentence
into
tokens
*/

/*
Output:

-
 
T
h
i
s
,

a
 
s
a
m
p
l
e
 
s
t
r
i
n
g
.
*/