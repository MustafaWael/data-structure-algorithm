#include <unordered_map>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode* head) {
    std::unordered_map<ListNode*, int> visitCount;
    ListNode* current = head;

    while (current) {
      visitCount[current]++;
      if (visitCount[current] > 1) {
        return true;
      }
      current = current->next;
    }

    return false;
  }
};

int main() {
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);

  // Create a cycle
  head->next->next->next->next = head->next;

  Solution solution;
  bool result = solution.hasCycle(head);

  return 1;
}