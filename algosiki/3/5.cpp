#include <iostream>
using namespace std;

typedef int Inf;

class Elem {
public:
    Inf x;
    Elem* next;
};

class Stack {
public:
    Elem* head;
    
    Stack() {
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
        el->next = head;
        head = el;
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
    Stack st;
    st.create();
    
    st.add(10);
    st.add(20);
    st.add(30);
    
    cout << "readHead: " << st.readHead() << endl;
    cout << "get: " << st.get() << endl;
    cout << "get: " << st.get() << endl;
    
    cout << "isEmpty: " << (st.isEmpty() ? "да" : "нет") << endl;
    
    return 0;
}
