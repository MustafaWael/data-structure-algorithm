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
  // ################### Fist Solution ###################
  // ListNode* deleteMiddle(ListNode* head) {
  //   if (!head->next) return nullptr;
  //   int count = 0;

  //   ListNode* current = head;

  //   while (current) {
  //     count++;
  //     current = current->next;
  //   }

  //   ListNode* midNode = head;

  //   for (int i = 1; i < count / 2; i++) {
  //     midNode = midNode->next;
  //   }

  //   midNode->next = midNode->next->next;

  //   return head;
  // }

  ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }

    prev->next = slow->next;

    return head;
  }
};

int main() {
  Solution solution;
  ListNode* node = new ListNode(1);
  node->next = new ListNode(3);
  node->next->next = new ListNode(4);
  node->next->next->next = new ListNode(7);
  node->next->next->next->next = new ListNode(1);
  node->next->next->next->next->next = new ListNode(2);
  node->next->next->next->next->next->next = new ListNode(6);

  ListNode* result = solution.deleteMiddle(node);

  ListNode* current = result;

  while (current) {
    std::cout << current->val << " ";
    current = current->next;
  }
  return 1;
}