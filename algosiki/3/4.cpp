#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
typedef int Inf;

class StackArray {
private:
    Inf data[MAX_SIZE];
    int topIndex;
    
public:
    StackArray() {
        create();
    }
    
    void create() {
        topIndex = -1;
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    void add(Inf x) {
        if (isFull()) return;
        data[++topIndex] = x;
    }
    
    Inf get() {
        if (isEmpty()) return -1;
        return data[topIndex--];
    }
    
    Inf readHead() {
        if (isEmpty()) return -1;
        return data[topIndex];
    }
    
private:
    bool isFull() {
        return topIndex >= MAX_SIZE - 1;
    }
};

int main() {
    StackArray s;
    
    s.add(10);
    s.add(20);
    s.add(30);
    
    cout << "readHead: " << s.readHead() << endl;
    
    cout << "get: " << s.get() << endl;
    cout << "get: " << s.get() << endl;
    
    cout << "isEmpty?: " << (s.isEmpty() ? "да" : "нет") << endl;
    
    return 0;
}
