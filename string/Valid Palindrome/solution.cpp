#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

class Solution {
private:
  string to_lower_case(string& str) {
    for (char& c : str) {
      c = tolower(c);
    }
    return str;
  }

  void reverse_string(string& str) {
    int l = 0, r = str.length() - 1;

    while (l < r) {
      char temp = str[l];
      str[l] = str[r];
      str[r] = temp;

      l++;
      r--;
    }
  }
public:
  bool isPalindrome(string s) {
    to_lower_case(s);
    regex pattern("[^a-zA-Z0-9]");
    string cleaned = regex_replace(s, pattern, "");
    string reversed(cleaned.rbegin(), cleaned.rend());

    return cleaned == reversed;
  }
};

int main() {
  Solution solution;

  cout << solution.isPalindrome("race a car");
  return 1;
}