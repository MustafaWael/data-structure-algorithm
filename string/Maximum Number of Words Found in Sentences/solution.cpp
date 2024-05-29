#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int mostWordsFound(vector<string>& sentences) {
    int max_words = 0;

    for (string sentence : sentences) {
      int word_count = 0;
      for (char c : sentence) {
        if (c == ' ') {
          word_count++;
        }
      }
      word_count++;
      if (word_count > max_words) {
        max_words = word_count;
      };
    }

    return max_words;
  }
};

int main() {
  vector<string> sentences = { "alice and bob love leetcode", "i think so too", "this is great thanks very much" };
  Solution solution;

  cout << solution.mostWordsFound(sentences);

  return 1;
}