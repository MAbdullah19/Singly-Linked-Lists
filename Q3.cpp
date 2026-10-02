// Name: Muhammad Abdullah
// Registration No: 553410
// Section: BSCS-15D
// Lab 04 - Task 3: Searching and accessing the second node
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

    int CountNodes() const {
        int count = 0;
        for (node* curr = head; curr != nullptr; curr = curr->next)
            count++;
        return count;
    }

    // Displays the position (first node = 1) of the first match
    void SearchNode(int searchData) const {
        int pos = 1;
        node* curr = head;
        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << searchData << " found at position " << pos << endl;
                return;
            }
            curr = curr->next;
            pos++;
        }
        cout << "Value not found" << endl;
    }

    void PrintSecondNode() const {
        if (head == nullptr || head->next == nullptr) {
            cout << "The list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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

// Runs the required checks on one list
static void runChecks(const char* title, List& list) {
    cout << "--- " << title << " ---\n";
    cout << "List: ";
    list.PrintList();
    list.PrintSecondNode();
    cout << "Search 20: ";
    list.SearchNode(20);
    cout << "Search 99: ";
    list.SearchNode(99);
    cout << endl;
}

int main() {
    List empty;
    runChecks("Empty list", empty);

    List one;
    one.AddNode(10);
    runChecks("One-node list", one);

    List many;
    many.AddNode(10);
    many.AddNode(20);
    many.AddNode(30);
    many.AddNode(20);
    runChecks("List 10, 20, 30, 20", many);

    empty.ClearList();
    one.ClearList();
    many.ClearList();
    return 0;
}
