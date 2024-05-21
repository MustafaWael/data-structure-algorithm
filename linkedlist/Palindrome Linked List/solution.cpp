#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true;
    }

    ListNode* current = head;
    ListNode* reversed = nullptr;

    while (current) {
      // prepend the current node to the reversed list
      ListNode* nextNode = new ListNode(current->val);
      nextNode->next = reversed;
      reversed = nextNode;
      
      // move to the next node
      current = current->next;
    }

    // reset the current pointer to the head
    current = head;

    while (current) {
      if (current->val != reversed->val) {
        return false;
      }
      current = current->next;
      reversed = reversed->next;
    }

    return true;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);

  Solution solution;
  bool result = solution.isPalindrome(head);
  std::cout << result;
  return 1;
}