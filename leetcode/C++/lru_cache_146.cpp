#include "common.hpp"

// idea: use an int to simulate time ticking

// time: get: O(1), put: O(n)
// space: O(n)
class LRUCache {
  typedef int Tick;
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    tickcounter = 0;
  }
    
  int get(int key) {
    if (data.find(key) != data.end()) {
      data[key].first = tickcounter++;

      return data[key].second;
    } else {
      return -1;
    }
  }
    
  void put(int key, int value) {
    if (data.find(key) != data.end()) {
      data[key] = std::make_pair(tickcounter++, value);
      return;
    }

    if (data.size() >= capacity) {
      int lru_key;
      auto max_time = std::numeric_limits<int>::max();

      for (const auto& keyval : data) {
        if (keyval.second.first < max_time) {
          max_time = keyval.second.first;
          lru_key = keyval.first;
        }
      }

      data.erase(lru_key);
    }
    data[key] = std::make_pair(tickcounter++, value);
  }

private:
  int capacity;
  Tick tickcounter;
  unordered_map<int, pair<Tick, int>> data;
};

struct Node {
  int key;
  int val;
  Node* next;
  Node* prev;

  Node () {
    next = nullptr;
    prev = nullptr;
  }

  Node (int k, int v) {
    key = k;
    val = v;
    next = nullptr;
    prev = nullptr;
  }
};

class LRUCache2 {
private:
  void appendToEnd(Node* node) {
    node->next = tail;
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
  }

  int removeFirst() {
    Node* removed_node = head->next;
    int removed_key = removed_node->key;
    head->next = removed_node->next;
    removed_node->next->prev = head;
    free(removed_node);
    return removed_key;
  }

  void moveToEnd(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    tail->prev->next = node;
    node->prev = tail->prev;
    node->next = tail;
    tail->prev = node;
  }

public:
  LRUCache2(int capacity) {
    this->capacity = capacity;
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (table.find(key) != table.end()) {
      moveToEnd(table[key]);
      return table[key]->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (table.find(key) != table.end()) {
      table[key]->val = value;
      moveToEnd(table[key]);
      return;
    }

    if (table.size() >= capacity) {
      int removed_key = removeFirst();
      cout << "removed key: " << removed_key << endl;
      table.erase(removed_key);
    }
    table[key] = new Node(key, value);
    appendToEnd(table[key]);
  }

  void printList() {
    Node* runner = head->next;
    cout << "List: ";
    while (runner != tail) {
      cout << "(" << runner->key << ", " << runner->val << ") ";
      runner = runner->next;
    }
    cout << endl;
  }

private:
  int capacity;
  Node* head;
  Node* tail;
  unordered_map<int, Node*> table;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main()
{
  LRUCache2 cache(2);
  int val;

  cache.put(1, 1);
  cache.put(2, 2);
  cache.printList();
  val = cache.get(1);       // returns 1
  cout << val << endl;
  cache.printList();
  cache.put(3, 3);    // evicts key 2
  val = cache.get(2);       // returns -1 (not found)
  cout << val << endl;
  cache.put(4, 4);    // evicts key 1
  val = cache.get(1);       // returns -1 (not found)
  cout << val << endl;
  val = cache.get(3);       // returns 3
  cout << val << endl;
  val = cache.get(4);       // returns 4
  cout << val << endl;
}
