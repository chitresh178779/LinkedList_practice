#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = "";

    // Step 1: Count frequencies using map
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }

    // Step 2: Copy map data to a vector of pairs for custom sorting
    vector<pair<char, int>> v(m.begin(), m.end());

    // Step 3: Sort vector by frequency in descending order
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second != b.second)
            return a.second > b.second; // Higher frequency first
        else
            return a.first > b.first;   // If frequency equal, higher char first
    });

    // Step 4: Build final string based on sorted characters and their frequency
    for (auto &pair : v) {
        s1.append(pair.second, pair.first);
    }

    cout << s1;
    return 0;
}
