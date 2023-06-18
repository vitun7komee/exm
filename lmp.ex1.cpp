#include<iostream>
#include<fstream>
#include<map>
#include<functional>
#include<vector>
#include<algorithm>

void print(std::vector < std::pair < std::string, int>> map)
{
    std::cout << map[0].first << " - " << map[0].second << '\n';
}
void task1(std::ifstream& file, std::function<bool(char, std::string)> lambda)
{
    std::map<std::string, int> map;
    char letter = 'q';
    std::string word;
    while (file >> word)
    {
        if (lambda(letter, word))
            ++map[word];
    }
    std::vector < std::pair < std::string, int>> m(map.begin(), map.end());
    std::sort(m.begin(), m.end(), [](auto a, auto b) {return a.second > b.second; });
    print(m);
}
int main()
{
    std::ifstream file("file123.txt");
    auto lambda = [](char letter, std::string word)
    {
        bool flag = false;
        for (int i = 0; i < word.length(); ++i)
            if (word[i] == letter)
                flag = true;
        return flag;
    };
    task1(file, lambda);
}


