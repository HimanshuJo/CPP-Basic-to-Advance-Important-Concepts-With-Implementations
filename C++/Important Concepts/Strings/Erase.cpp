#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    // Syntax 1: Erasing an entire string
    string str1="This is the first test string";
    str1.erase();
    cout<<str1<<endl; // 

    // Syntax 2: Removing all the occurrences of a single character in a given string
    string st2="This is a the second test string";
    str2.erase(remove(str2.begin(), str2.end(), 'a'), str2.end());
    cout<<str2<<endl; // This is the second test string

    // Syntax 3: Erasing all the characters from a specified position(0 based indexing)
    string str3="This is the third test string";
    str3.erase(1);
    cout<<str3<<endl; // T

    // Syntax 4: Erasing at most len characters from a specified position(0 based indexing)
    string str4="This is the fourth test string";
    str4.erase(1, 4);
    cout<<str4<<endl; // Tis the fourth test string

    // Syntax 5: Erasing a single character at the position specified by the iterator
    string str5="This is the fifth test string";
    str5.erase(str5.begin()+1);
    cout<<str5<<endl; // Tis is the fifth test string
    str5.erase(str5.end()-1);
    cout<<str5<<endl; // Tis is the fifth test strin

    // Syntax 6: Erasing characters between iterator pos1(inclusive) to iterator pos2(exclusive)
    string str6="This is the sixth test string";
    str6.erase(str6.begin()+1, str6.end()-6);
    cout<<str6<<endl; // Tstring

    // Syntax 7: Trims the string after the first occurrence of the character provided in the parameter
    string str7="This is the seventh test string";
    str7.erase(str7.find(' '));
    cout<<str7<<endl; // This

    // Syntax 8: Erase the first occurrence of the character specified in the parameter
    string str8="This is the eigth test string";
    str8.erase(find(str8.begin(), str8.end(), ' '));
    cout<<str8<<endl; // Thisis the eigth test string 
}