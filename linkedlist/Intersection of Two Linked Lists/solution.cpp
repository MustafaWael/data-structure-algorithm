#include <cstddef>
#include <cmath>
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
  int getLen(ListNode* head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }

public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int headALen = getLen(headA);
    int headBLen = getLen(headB);

    int skipCount = abs(headALen - headBLen);

    while (skipCount--) {
      if (headALen > headBLen) {
        headA = headA->next;
      }
      else {
        headB = headB->next;
      }
    }

    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }

      headA = headA->next;
      headB = headB->next;
    }

    return NULL;
  }
};

int main() {
  ListNode* headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  ListNode* headB = new ListNode(5);
  headB->next = new ListNode(0);
  headB->next->next = new ListNode(1);
  headB->next->next->next = headA->next->next;
  headB->next->next->next->next = new ListNode(4);
  headB->next->next->next->next->next = new ListNode(5);

  Solution solution;
  ListNode* result = solution.getIntersectionNode(headA, headB);

  std::cout << result->val << std::endl;

  return 1;
}