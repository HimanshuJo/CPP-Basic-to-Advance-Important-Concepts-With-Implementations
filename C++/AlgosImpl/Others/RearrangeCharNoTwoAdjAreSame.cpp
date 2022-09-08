// Rearrange characters in a string such that no two adjacent are same
/*
Given a string with repeated characters, the task is to rearrange characters 
in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.

Examples: 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible
*/

/*
The idea is to put the highest frequency character first (a greedy approach). 
We use a priority queue (Or Binary Max Heap) and put all characters and ordered 
by their frequencies (highest frequency character at root). We one by one take 
the highest frequency character from the heap and add it to result.

After we add, we decrease the frequency of the character and we temporarily 
move this character out of priority queue so that it is not picked next time.
We have to follow the step to solve this problem, they are:

1. Build a Priority_queue or max_heap, pq that stores characters and their frequencies. 
    …… Priority_queue or max_heap is built on the bases of the frequency of character.

2. Create a temporary Key that will be used as the previously visited element 
  (the previous element in the resultant string. Initialize it { char = ‘#’ , freq = ‘-1’ }

3. While pq is not empty. 
    ….. Pop an element and add it to the result. 
    ….. Decrease frequency of the popped element by ‘1’ 
    ….. Push the previous element back into the priority_queue if it’s frequency > ‘0’ 
    ….. Make the current element as the previous element for the next iteration. 

4. If the length of the resultant string and original string is not equal, 
   print “not possible”. Else print result.
*/

// C++ program to rearrange characters in a string
// so that no two adjacent characters are same.

#include <bits/stdc++.h>
using namespace std;

char getMaxCountChar(const vector<int> &count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            ch = 'a' + i;
        }
    }

    return ch;
}

string rearrangeString(string S)
{

    int n = S.size();
    if (!n)
        return "";

    vector<int> count(26, 0);
    for (auto ch : S)
        count[ch - 'a']++;

    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];

    // check if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";

    string res(n, ' ');

    int ind = 0;
    // filling the most frequently occurring char in the even
    // indices
    while (maxCount)
    {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;

    // now filling the other Chars, first filling the even
    // positions and then the odd positions
    for (int i = 0; i < 26; i++)
    {
        while (count[i] > 0)
        {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}

int main()
{
    string str = "bbbaa";
    string res = rearrangeString(str);
    if (res == "")
        cout << "Not valid string" << endl;
    else
        cout << res << endl;
    return 0;
}
