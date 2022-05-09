#include <bits/stdc++.h>
typedef long long ll;

#define endl "\n"
#define cust                     \
    ios_base::sync_withstdio(0); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;

template<typename Vector>
auto split_vector(const Vector& v, unsigned number_lines) {
    using Iterator = typename Vector::const_iterator;
    std::vector<Vector> rtn;
    Iterator it = v.cbegin();
    const Iterator end = v.cend();
    while (it != end) {
        Vector v;
        std::back_insert_iterator<Vector> inserter(v);
        const auto num_to_copy = std::min(static_cast<unsigned>(std::distance(it, end)), number_lines);
        std::copy(it, it + num_to_copy, inserter);
        rtn.push_back(std::move(v));
        std::advance(it, num_to_copy);
    }
    return rtn;
}


vector<vector<int>> getChunk(vector<int> v, int chunkSize)
{
    int n = chunkSize;
    int size = (v.size() - 1) / n + 1;
    vector<int> vec[size];
    for (int k = 0; k < size; ++k)
    {
        // get range for the next set of `n` elements
        auto start_itr = std::next(v.cbegin(), k * n);
        auto end_itr = std::next(v.cbegin(), k * n + n);

        // allocate memory for the sub-vector
        vec[k].resize(n);

        // code to handle the last sub-vector as it might
        // contain fewer elements
        if (k * n + n > v.size())
        {
            end_itr = v.cend();
            vec[k].resize(v.size() - k * n);
        }

        // copy elements from the input range to the sub-vector
        std::copy(start_itr, end_itr, vec[k].begin());
    }

    vector<vector<int>> res;

    for (int i = 0; i < size; ++i) {

        vector<int> final;

        for (int i = 0; i < size; ++i)
        {
            for (auto it = vec[i].begin(); it != vec[i].end(); it++)
            {
                final.push_back(*it);
            }
        }

        res.push_back(final);

    }

    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> uni;
        for (int i = 0; i < n; ++i)
        {
            int num_;
            cin >> num_;
            uni.push_back(num_);
        }
        vector<int> skill;
        for (int i = 0; i < n; ++i)
        {
            int num_;
            cin >> num_;
            skill.push_back(num_);
        }
        unordered_map<int, int> countMap;
        for (int i = 0; i < uni.size(); ++i)
        {
            countMap[uni.at(i)]++;
        }
        int max = INT_MAX;
        for (auto x : countMap)
        {
            if (x.second > max)
            {
                max = x.second;
            }
        }
        map<int, vector<int>> map;
        for (int i = 0; i < uni.size(); ++i)
        {
            map.insert(pair<int, vector<int>>(uni.at(i), vector<int>()));
        }
        for (int i = 0; i < uni.size(); ++i)
        {
            if (map.find(uni.at(i)) != map.end())
            {
                map[uni.at(i)].push_back(skill.at(i));
            }
        }
        for (auto x : map)
        {
            vector<int> temp = x.second;
            sort(temp.begin(), temp.end(), greater<>());
        }

        // for (auto map_iter = map.cbegin(); map_iter != map.cend(); ++map_iter)
        // {
        //     std::cout << "key: " << map_iter->first << "  value: ";
        //     for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
        //         std::cout << *vec_iter << " ";
        //     std::cout << "\n";
        // }

        vector<int> res(n, 0);
        for (int i = 0; i < max; ++i)
        {
            int sum = 0;
            for (auto x : map)
            {
                vector<int> temp = x.second;
                int chunkSize = i;
                for (vector<int> temp__ : split_vector(temp, chunkSize))
                {
                    int size = temp__.size();
                    if (size == i)
                    {
                        for (int num : temp__)
                        {
                            sum += num;
                        }
                    }
                }
            }
            res.at(i - 1) = sum;
        }
        for (int num : res)
        {
            cout << num;
        }
    }
}