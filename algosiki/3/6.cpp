#include <iostream>
using namespace std;

typedef int Inf;

class Elem {
public:
    Inf x;
    Elem* next;
};

class Queue {
public:
    Elem* head;
    Elem* tail;
    
    Queue() {
        head = NULL;
        tail = NULL;
    }
    
    void create() {
        head = NULL;
        tail = NULL;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void add(Inf x) {
        Elem* el = new Elem();
        el->x = x;
        el->next = NULL;
        
        if (isEmpty()) {
            head = tail = el;
        } else {
            tail->next = el;
            tail = el;
        }
    }
    
    Inf get() {
        if (isEmpty()) return -1;
        
        Elem* pl = head;
        Inf i = head->x;
        head = head->next;
        
        if (head == NULL) {
            tail = NULL;
        }
        
        delete pl;
        return i;
    }
    
    Inf readHead() {
        if (isEmpty()) return -1;
        return head->x;
    }
};

int main() {
    Queue q;
    q.create();
    
    q.add(100);
    q.add(200);
    q.add(300);
    q.add(400);
    
    cout << "readHead: " << q.readHead() << endl;
    cout << "get: " << q.get() << endl;
    cout << "get: " << q.get() << endl;
    cout << "get: " << q.get() << endl;
    
    cout << "isEmpty?: " << (q.isEmpty() ? "да" : "нет") << endl;
    
    return 0;
}
