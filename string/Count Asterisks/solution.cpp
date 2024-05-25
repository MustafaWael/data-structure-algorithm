#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int countAsterisks(string s) {
    int numbOfPipe = 0;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '|') {
        numbOfPipe++;
      }

      if (numbOfPipe % 2 == 0 && s[i] == '*') {
        count++;
      }

    }

    return count;
  }
};

int main() {
  Solution solution;
  cout << solution.countAsterisks("yo|uar|e**|b|e***au|tifu|l");
  return 1;
}