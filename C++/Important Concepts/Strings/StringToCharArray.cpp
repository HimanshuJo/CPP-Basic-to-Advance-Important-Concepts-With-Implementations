#include <iostream>
#include <string>

using namespace std;

void stringToCharArrayOne(string s){
	// declaring character array : p
	char p[s.length()];

	int i;

	for (i = 0; i < sizeof(p); i++) {
		p[i] = s[i];
		cout << p[i];
	}
}

void stringToCharArrayTwo(string s){
    char cstr[s.size() + 1];

    std::copy(s.begin(), s.end(), cstr);
    cstr[s.size()] = '\0';

    for (auto &ch : cstr)
    {
        cout << ch << "\n";
    }
}

int main()
{
	// assigning value to string s
	string s("geeksforgeeks");
    stringToCharArrayOne(s);
    cout<<endl;
	std::string s2 = "Hello World!";
    stringToCharArrayTwo(s2);
	return 0;
}

/*
geeksforgeeks
H
e
l
l
o
 
W
o
r
l
d
!
*/