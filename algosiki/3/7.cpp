#include <iostream>
using namespace std;

typedef int Inf;

class Elem {
public:
    Inf x;
    Elem* next;
};

class PriorityQueue {
public:
    Elem* head;
    
    PriorityQueue() {
        head = NULL;
    }
    
    void create() {
        head = NULL;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void add(Inf x) {
        Elem* el = new Elem();
        el->x = x;
        
        if (isEmpty() || head->x < x) {
            el->next = head;
            head = el;
            return;
        }
        
        Elem* current = head;
        while (current->next != NULL && current->next->x >= x) {
            current = current->next;
        }
        
        el->next = current->next;
        current->next = el;
    }
    
    Inf get() {
        if (isEmpty()) return -1;
        
        Elem* pl = head;
        Inf i = head->x;
        head = head->next;
        delete pl;
        return i;
    }
    
    Inf readHead() {
        if (isEmpty()) return -1;
        return head->x;
    }
};

int main() {
    PriorityQueue pq;
    pq.create();
    
    pq.add(30);
    pq.add(50);
    pq.add(10);
    pq.add(40);
    pq.add(20);
    
    cout << "readHead: " << pq.readHead() << endl;
    cout << "get: " << pq.get() << endl;
    cout << "get: " << pq.get() << endl;
    cout << "get: " << pq.get() << endl;
    
    cout << "isEmpty?: " << (pq.isEmpty() ? "да" : "нет") << endl;
    
    return 0;
}
