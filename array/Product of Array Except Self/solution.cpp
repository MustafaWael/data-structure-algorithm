#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int runningProduct = 1;
    vector<int> prefix(n, 1);

    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
      prefix[i] = runningProduct * prefix[i];
      runningProduct = runningProduct * nums[i];
    }

    return prefix;
  }
};

int main() {
  vector<int> vec{ 1, 2, 3, 4 };
  Solution solution;

  for (int item : solution.productExceptSelf(vec)) {
    cout << item << " ";
  }

  return 1;
}