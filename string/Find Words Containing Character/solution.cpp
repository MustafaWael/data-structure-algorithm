#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> indices;

    for (int i = 0; i < words.size(); i++) {
      for (char c : words[i]) {
        if (x == c) {
          indices.push_back(i);
          break;
        }
      }
    }

    return indices;
  }
};


int main() {
  vector<string> words = { "abc","bcd","aaaa","cbc" };
  char x = 'z';

  Solution solution;
  solution.findWordsContaining(words, x);
  return 1;
}