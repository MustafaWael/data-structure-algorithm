struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* current = head;

    while (current->next) {
      if (current->val == current->next->val) {
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
      }
      else {
        current = current->next;
      }

    }

    return head;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(3);

  Solution solution;
  ListNode* result = solution.deleteDuplicates(head);

  return 1;
}