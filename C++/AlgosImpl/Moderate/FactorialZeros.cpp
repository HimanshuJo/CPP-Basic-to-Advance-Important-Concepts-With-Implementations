/*
    Algo to compute the number of trailing zeros in N factorial
*/
/*
    A trailing zero is created with multiples of 10, and multiples of 10 are created with
    pairs of 5-multiples and 2-multiples

    For example:

        in 19!, the following terms create the trailing zeros

            29!=2*.....*5*.....*10*....*15*16*...

        Therefore to count the number of zeros, we only need to count the pairs of multiples
        of 5 and 2

        There will be more multiples of 2 than 5, though, so simply counting the number of
        multiples of 5 is sufficient

    -------

    First way:

        Iterating through all the numbers from 2 through n, counting the number of times
        that 5 goes into each number
*/

#include<iostream>
using namespace std;

int factorialOf5(int i){
    int count=0;
    while(i%5==0){
        count++;
        i/=5;
    }
    return count;
}

int countFactZeros(int num){
    int count=0;
    for(int i=2; i<=num; ++i){
        count+=factorialOf5(i);
    }
    return count;
}

int main(){
    int num=5;
    int ans=countFactZeros(num);
    cout<<ans<<endl;
}