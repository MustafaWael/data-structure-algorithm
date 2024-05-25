#include <string>
using namespace std;

struct BrowserNode {
  string url;
  int pos;
  BrowserNode(string url, int pos) : url(url), pos(pos) {}
};

struct Node {
  Node* next;
  Node* prev;
  BrowserNode* val;
  Node(string url, int pos) : val(new BrowserNode(url, pos)), next(nullptr), prev(nullptr) {}
  ~Node() { delete val; }
};

class BrowserHistory {
private:
  Node* head;
  Node* tail;
  Node* current;
  int length;

  void clearForwardHistory(Node* node) {
    Node* temp;
    while (node) {
      temp = node;
      node = node->next;
      delete temp;
    }
  }

public:
  BrowserHistory(string homepage) : length(0) {
    head = tail = current = new Node(homepage, length++);
  }

  ~BrowserHistory() {
    clearForwardHistory(head);
  }

  void visit(string url) {
    clearForwardHistory(current->next);
    Node* node = new Node(url, length++);
    current->next = node;
    node->prev = current;
    current = node;
    tail = node;
  }

  string back(int steps) {
    while (steps > 0 && current->prev) {
      current = current->prev;
      steps--;
    }
    return current->val->url;
  }

  string forward(int steps) {
    while (steps > 0 && current->next) {
      current = current->next;
      steps--;
    }
    return current->val->url;
  }
};

int main() {
  BrowserHistory bh("leetcode");
  bh.visit("facebook");
  bh.visit("google");
  bh.visit("youtube");

  bh.back(1);
  bh.back(1);
  bh.forward(1);
  bh.visit("medium");
  bh.forward(1);
  bh.back(1);
  bh.back(1);


  return 1;
}