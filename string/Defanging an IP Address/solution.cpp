#include <string>
#include <iostream>
#include <unordered_map>
#include <regex>
#include <algorithm>

using namespace std;

// +++ SOLUTION WITH REGEX +++
// class Solution {
// public:
//   string defangIPaddr(string address) {
//     string replacer = "[.]";
//     regex pattern("[.]");
//     return regex_replace(address, pattern, replacer);
//   }
// };

class Solution {
public:
  string defangIPaddr(string address) {
    int i = 0;
    while (i < address.length()) {
      if (address[i] == '.') {
        address.insert(i, "[");
        address.insert(i + 2, "]");
        i += 3;
      }
      else {
        i++;
      }
    }

    return address;
  }
};

int main() {
  Solution solution;
  cout << solution.defangIPaddr("1.1.1.1");
  return 1;
}