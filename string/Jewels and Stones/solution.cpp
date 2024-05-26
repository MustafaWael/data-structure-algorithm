#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_map<char, int> stones_map;
    int sum = 0;

    for (char stone : stones) {
      stones_map[stone]++;
    }

    for (char jewel : jewels) {
      sum += stones_map[jewel];
    }

    return sum;
  }
};

int main() {
  Solution solution;
  cout << solution.numJewelsInStones("z", "ZZ");
  return 1;
}