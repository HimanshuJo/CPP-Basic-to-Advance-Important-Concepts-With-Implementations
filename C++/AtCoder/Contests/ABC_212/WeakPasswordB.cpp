#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        string in;
        cin >> in;
        int temp = stoi(in);
        vector<int> nums;
        for (int i = 0; i < 4; ++i)
        {
            int temp_ = temp % 10;
            temp /= 10;
            nums.push_back(temp_);
        }
        reverse(nums.begin(), nums.end());
        int begin = nums[0];
        int count = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (nums[i] == begin)
            {
                count++;
            }
        }
        if (count == 4)
        {
            cout << "Weak";
            continue;
        }
        else if (begin == 9)
        {
            bool flag = false;
            if (nums[1] == 0)
            {
                for (int i = 2; i < 3; ++i)
                {
                    if (nums[i + 1] == nums[i] + 1)
                    {
                        flag = true;
                    }
                }
            }
            if (flag)
            {
                cout << "Weak";
                continue;
            }
        }
        if (nums[3] == 0 && nums[2] == 9)
        {
            bool flag = false;
            if (nums[1] == nums[0] + 1 && nums[2] == nums[1] + 1) {
                flag = true;
            }
            if (flag)
            {
                cout << "Weak";
                continue;
            }
        }
        if (nums[2] == 0 && nums[3] == 1) {
            if (nums[0] == 8 && nums[1] == 9) {
                cout << "Weak";
                continue;
            }
        }
        int counter = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (nums[i + 1] == nums[i] + 1)
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            if (nums[3] == nums[0] + 3)
                cout << "Weak";
        }
        else
        {
            cout << "Strong";
        }
    }
}