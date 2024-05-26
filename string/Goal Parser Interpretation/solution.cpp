#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string interpret(string command) {
    for (int i = 0; i < command.length(); i++) {
      if (command[i] == '(' && command[i + 1] == ')') {
        command.erase(i, 2);
        command.insert(i, "o");
      }
      else if (
        command[i] == '(' &&
        command[i + 1] == 'a' &&
        command[i + 2] == 'l' &&
        command[i + 3] == ')'
        ) {
        command.erase(i, 1);
        command.erase(i + 2, 1);
      }
    }

    return command;
  }
};

int main() {
  Solution solution;
  cout << solution.interpret("G()(al)");
  return 1;
}