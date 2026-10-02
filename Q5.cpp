// Name: Muhammad Abdullah
// Registration No: 553410
// Section: BSCS-15D
// Lab 04 - Task 5: Deleting a node by value
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

    // Removes only the first node containing delData
    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "Cannot delete " << delData << ": list is empty." << endl;
            return;
        }
        // Case: first node (also covers the only node)
        if (head->data == delData) {
            node* temp = head;
            head = head->next;               // reconnect first
            delete temp;                     // then release
            cout << "Deleted " << delData << endl;
            return;
        }
        // Case: middle / last node - keep a pointer to the previous node
        node* prev = head;
        node* curr = head->next;
        while (curr != nullptr && curr->data != delData) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Cannot delete " << delData << ": value not found." << endl;
            return;
        }
        prev->next = curr->next;             // bypass the node (works for last too)
        delete curr;
        cout << "Deleted " << delData << endl;
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

    cout << "Test 1: delete from an empty list\n";
    list.DeleteNode(10);
    list.PrintList();

    cout << "\nTest 2: list 10, 20, 20, 30 - delete 20 once\n";
    list.AddNode(10); list.AddNode(20); list.AddNode(20); list.AddNode(30);
    list.PrintList();
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nTest 3: delete the first node (10)\n";
    list.DeleteNode(10);
    list.PrintList();

    cout << "\nTest 4: delete the last node (30)\n";
    list.DeleteNode(30);
    list.PrintList();

    cout << "\nTest 5: delete a missing value (99)\n";
    list.DeleteNode(99);
    list.PrintList();

    cout << "\nTest 6: delete the only node (20)\n";
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nTest 7: middle node - list 1, 2, 3, delete 2\n";
    list.AddNode(1); list.AddNode(2); list.AddNode(3);
    list.DeleteNode(2);
    list.PrintList();

    list.ClearList();
    return 0;
}
