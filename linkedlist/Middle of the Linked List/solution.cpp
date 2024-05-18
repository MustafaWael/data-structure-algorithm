#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    std::vector<ListNode*> list;

    ListNode* current = head;

    while (current) {
      list.push_back(current);
      current = current->next;
    }

    return list[list.size() / 2];
  }
};