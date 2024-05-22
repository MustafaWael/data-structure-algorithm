struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* current = dummy;

    while (current->next) {
      if (current->next->val == val) {
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
      }
      else {
        current = current->next;

      }

    }

    ListNode* temp = dummy->next;
    delete dummy;

    return temp;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);

  Solution solution;
  ListNode* result = solution.removeElements(head, 6);

  return 1;
}