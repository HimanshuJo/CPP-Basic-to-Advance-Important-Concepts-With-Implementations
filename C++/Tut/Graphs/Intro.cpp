#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> num{{1, 2}, {3, 4}, {5, 6}};
    unordered_map<int, vector<int>> gr;
    int sz = num.size();
    for (int i = 0; i < sz; ++i)
    {
        if (gr.find(num[i][0]) == gr.end())
        {
            gr.insert(pair<int, vector<int>>(num[i][0], vector<int>()));
            gr[num[i][0]].push_back(num[i][1]);
        }
        else
        {
            gr[num[i][0]].push_back(num[i][1]);
        }
        if (gr.find(num[i][1]) == gr.end())
        {
            gr.insert(pair<int, vector<int>>(num[i][1], vector<int>()));
            gr[num[i][1]].push_back(num[i][0]);
        }
        else
        {
            gr[num[i][1]].push_back(num[i][0]);
        }
    }
    // option 1: range-based loops
    for (const auto &pair : gr)
    {
        std::cout << "key: " << pair.first << "  value: [  ";

        for (int d : pair.second)
            std::cout << d << "  ";

        std::cout << "]\n";
    }
    std::cout << "----------------\n";
    // option 2: iterators
    for (auto map_iter = gr.cbegin(); map_iter != gr.cend(); ++map_iter)
    {
        std::cout << "key: " << map_iter->first << "  value: [  ";

        for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
            std::cout << *vec_iter << "  ";

        std::cout << "]\n";
    }
    // option 3: range-based loop for map,
    // subscript operator for vector
    std::cout << "----------------\n";
    for (const auto &pair : gr)
    {
        std::cout << "key: " << pair.first << "  value: [  ";

        for (std::size_t i = 0; i < pair.second.size(); ++i)
            std::cout << pair.second[i] << "  ";

        std::cout << "]\n";
    }
}

/*
Output:

key: 6  value: [  5  ]
key: 5  value: [  6  ]
key: 4  value: [  3  ]
key: 3  value: [  4  ]
key: 1  value: [  2  ]
key: 2  value: [  1  ]
----------------
key: 6  value: [  5  ]
key: 5  value: [  6  ]
key: 4  value: [  3  ]
key: 3  value: [  4  ]
key: 1  value: [  2  ]
key: 2  value: [  1  ]
----------------
key: 6  value: [  5  ]
key: 5  value: [  6  ]
key: 4  value: [  3  ]
key: 3  value: [  4  ]
key: 1  value: [  2  ]
key: 2  value: [  1  ]
*/