#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int findPermutationDifference(string s, string t) {
    unordered_map<char, int> s_map;
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      s_map[s[i]] = i;
    }

    for (int j = 0; j < t.length(); j++) {
      result += abs(j - s_map[t[j]]);
    }

    return result;
  }
};

int main() {
  Solution solution;
  cout << solution.findPermutationDifference("abcde", "edbac");
  return 1;
}