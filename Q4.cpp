// Name: Muhammad Abdullah
// Registration No: 553410
// Section: BSCS-15D
// Lab 04 - Task 4: Inserting at the beginning
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
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    // Insert at the end
    void AddNode(int addData) {
        node* n = new node;
        n->data = addData;
        n->next = nullptr;
        if (head == nullptr) {
            head = n;
            return;
        }
        node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = n;
    }

    // Insert at the beginning: connect to old first node, then update head
    void InsertAtBeginning(int addData) {
        node* n = new node;
        n->data = addData;
        n->next = head;
        head = n;
    }

    void PrintList() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        node* curr = head;
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
            head = head->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    List list;
    cout << "Initial list: ";
    list.PrintList();

    list.InsertAtBeginning(20);
    cout << "After InsertAtBeginning(20): ";
    list.PrintList();

    list.InsertAtBeginning(10);
    cout << "After InsertAtBeginning(10): ";
    list.PrintList();

    list.AddNode(30);
    cout << "After AddNode(30):           ";
    list.PrintList();

    list.ClearList();
    return 0;
}
