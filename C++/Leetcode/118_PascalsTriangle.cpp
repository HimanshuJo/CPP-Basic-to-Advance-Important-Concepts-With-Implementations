#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> llist;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0) {
                vector<int> list;
                list.push_back(1);
                llist.push_back(list);
            } else if (i == 1) {
                vector<int> list;
                list.push_back(1);
                list.push_back(1);
                llist.push_back(list);
            } else {
                vector<int> list(i + 1, 0);
                list.at(0) = 1;
                list.at(list.size() - 1) = 1;
                vector<int> temp = llist.at(i - 1);
                int index = 0;
                for (int x = 1; x < i; ++x) {
                    list.at(x) = temp.at(index) + temp.at(index + 1);
                    index++;
                }
                llist.push_back(list);
            }
        }
        return llist;
    }
};