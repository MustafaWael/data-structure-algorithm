struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyNode = new ListNode(-1, head);
    ListNode* first = dummyNode;
    ListNode* second = dummyNode;

    for (int i = 0; i < n; i++) {
      first = first->next;
    }

    while (first->next != nullptr) {
      first = first->next;
      second = second->next;
    }

    if (second->next != nullptr) {
      ListNode* temp = second->next;
      second->next = second->next->next;
      delete temp;
    }

    return dummyNode->next;
  }
};

int main() {
  return 0;
}
