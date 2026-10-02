// Name: Muhammad Abdullah
// Registration No: 553410
// Section: BSCS-15D
// Lab 04 - Task 1: Creating and traversing a list
#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    List() : head(nullptr) {}
    ~List() { ClearList(); }
    List(const List&) = delete;            // copying is not allowed in this lab
    List& operator=(const List&) = delete;

    // Reads three integers and links them in input order (call on an empty list)
    void CreateThreeNodes() {
        if (head != nullptr) {
            cout << "List is not empty; CreateThreeNodes() must be called once on an empty list.\n";
            return;
        }
        node* tail = nullptr;
        for (int i = 1; i <= 3; i++) {
            node* n = new node;
            cout << "Enter value " << i << ": ";
            cin >> n->data;
            n->next = nullptr;
            if (head == nullptr) head = n;   // first node
            else tail->next = n;             // link after previous node
            tail = n;
        }
    }

    void PrintList() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        node* curr = head;                   // local pointer; head is unchanged
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> NULL\n";
    }

    void ClearList() {
        while (head != nullptr) {
            node* temp = head;
            head = head->next;               // save link before deleting
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    List list;
    cout << "Before creation:\n";
    list.PrintList();

    list.CreateThreeNodes();

    cout << "After creation:\n";
    list.PrintList();

    list.ClearList();
    return 0;
}
