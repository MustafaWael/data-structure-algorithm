struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
  void addNode(ListNode*& tail, int value) {
    tail->next = new ListNode(value);
    tail = tail->next;
  }

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    ListNode* result = &dummy;
    ListNode* tail = result;

    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      addNode(tail, sum % 10);

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    return result->next;
  }
};

int main() {
  Solution solution;
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  ListNode* result = solution.addTwoNumbers(l1, l2);

  return 1;
}