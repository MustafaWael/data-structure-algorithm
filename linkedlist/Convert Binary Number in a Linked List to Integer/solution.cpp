struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  int getDecimalValue(ListNode* head) {
    ListNode* current = head;
    int result = 0;

    while (current) {
      // Shift the result to the left by 1 bit and add the current node's value
      result = (result << 1) | current->val;
      current = current->next;
    }

    return result;
  }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(0, new ListNode(1)));
  Solution solution;
  int result = solution.getDecimalValue(head);
  return 0;
}