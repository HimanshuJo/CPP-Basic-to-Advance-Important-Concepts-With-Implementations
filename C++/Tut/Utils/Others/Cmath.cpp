/*
sqrt, sqrtl and sqrtf in C++

    The cmath header defines two more inbuilt functions for calculating square root of 
    a number (apart from sqrt which takes double as an argument) which has an argument 
    of type float and long double.

    double sqrt(double arg): It returns the square root of a number to type double
    Syntax : double sqrt(double arg)

    -------

    float sqrtf(float arg):

        It returns the square root of a number to type float
        
        Syntax : float sqrtf(float arg)

    -------

    long double sqrtl(long double arg):

        It returns the square root of a number to type long double with more precision. 
        
        Advantage of using this function is that when working with integers of the order 10^18, 
        calculating its square root with sqrt function may give an incorrect answer due to 
        precision errors as default functions in programming language works with floats/doubles. 
        
        But this will always give an accurate answer.
        
        Syntax : long double sqrtl(long double arg)
*/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	double val1 = 225.0;
	double val2 = 300.0;

	cout << fixed << setprecision(12) << sqrt(val1) << endl;
	cout << fixed << setprecision(12) << sqrt(val2) << endl;

    float val3 = 225.0;
	float val4 = 300.0;

	cout << fixed << setprecision(12) << sqrtf(val3) << endl;
	cout << fixed << setprecision(12) << sqrtf(val4) << endl;

    long long int val5 = 1000000000000000000;
	long long int val6 = 999999999999999999;

	cout << fixed << setprecision(12) << sqrt(val5) << endl;
	cout << fixed << setprecision(12) << sqrt(val6) << endl;

    long long int val7 = 1000000000000000000;
	long long int val8 = 999999999999999999;

	cout << fixed << setprecision(12) << sqrtl(val7) << endl;
	cout << fixed << setprecision(12) << sqrtl(val8) << endl;

	return (0);
}

/*
Output:
15.000000000000
17.320508075689

-------

15.000000000000
17.320508956909

-------

1000000000.000000000000
1000000000.000000000000

-------

1000000000.000000000000
999999999.999999999476
*/
