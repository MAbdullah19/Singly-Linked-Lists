// Name: Muhammad Abdullah
// Registration No: 553410
// Section: BSCS-15D
// Lab 04 - Task 2: Appending nodes using a loop
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

    // Inserts a new node at the end of the list
    void AddNode(int addData) {
        node* n = new node;
        n->data = addData;
        n->next = nullptr;                   // new node is always the last one
        if (head == nullptr) {
            head = n;
            return;
        }
        node* curr = head;
        while (curr->next != nullptr)        // walk to the last node
            curr = curr->next;
        curr->next = n;
    }

    int CountNodes() const {
        int count = 0;
        node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
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
    int n, value;
    cout << "How many integers do you want to add (n >= 0)? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter integer " << i << ": ";
        cin >> value;
        list.AddNode(value);
    }

    cout << "List : ";
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;

    list.ClearList();
    return 0;
}
