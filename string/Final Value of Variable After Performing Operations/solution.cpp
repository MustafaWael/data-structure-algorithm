#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;

    for (string operation : operations) {
      if (operation == "++X" || operation == "X++") {
        x++;
      }
      else {
        x--;
      }
    }

    return x;
  }
};

int main() {
  vector<string> list{ "++X","++X","X++" };
  Solution solution;
  cout << solution.finalValueAfterOperations(list);
  return 1;
}