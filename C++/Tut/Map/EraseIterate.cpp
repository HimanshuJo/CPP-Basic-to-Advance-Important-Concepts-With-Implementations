//Remove entries from a map while iterating
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
 
template<typename K, typename V>
void remove_keys(std::unordered_map<K, V> &m, const std::unordered_set<K> &keys)
{
    auto it = m.cbegin();
    while (it != m.cend())
    {
        if (keys.find(it->first) != keys.cend())
        {
            // supported in C++11
            it = m.erase(it);
        }
        else {
            ++it;
        }
    }
}
 
int main()
{
    std::unordered_map<std::string, std::string> u_map =
    {
        {"C", "C99"},
        {"C++", "C++17"},
        {"Java", "Java SE 9"},
        {"PHP", "PHP 7.0"}
    };
    std::unordered_set<std::string> keys = { "Java", "PHP" };
 
    remove_keys(u_map, keys);
 
    for (const auto &entry: u_map) {
        std::cout << "{" << entry.first << ", " << entry.second << "}" << std::endl;
    }
 
    return 0;
}
