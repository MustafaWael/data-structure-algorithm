#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1) return;
    int m = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        m++;
      }

      else if (m > 0) {
        swap(nums, i, i - m);
      }
    }

  }

private:
  void swap(vector<int>& vec, int left, int right) {
    int temp = vec[left];
    vec[left] = vec[right];
    vec[right] = temp;
  }
};

int main() {
  vector<int> vec{ 0, 1, 0, 3, 12 };
  Solution solution;
  solution.moveZeroes(vec);

  for (int i : vec) {
    cout << i << " ";
  }
  return 1;
}