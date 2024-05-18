struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;

    while (list1 && list2) {
      if (list1->val <= list2->val) {
        current->next = list1;
        list1 = list1->next;
      }
      else {
        current->next = list2;
        list2 = list2->next;
      }
      current = current->next;
    }

    // Append remaining nodes
    if (list1) {
      current->next = list1;
    }
    else {
      current->next = list2;
    }

    ListNode* merged = dummy->next;
    delete dummy;
    return merged;

  }

};


int main() {
  ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(5, new ListNode(6)))));
  ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  Solution solution;
  ListNode* merged = solution.mergeTwoLists(list1, list2);

  return 1;
}