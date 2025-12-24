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
        topIndex = -1;
    }
    
    void create() {
        topIndex = -1;
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    bool isFull() {
        return topIndex >= MAX_SIZE - 1;
    }
    
    void push(Inf x) {
        if (isFull()) return;
        data[++topIndex] = x;
    }
    
    Inf pop() {
        if (isEmpty()) return -1;
        return data[topIndex--];
    }
    
    Inf top() {
        if (isEmpty()) return -1;
        return data[topIndex];
    }
};

int main() {
    StackArray s;
    s.create();
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Текущий элемент: " << s.top() << endl;
    
    cout << "Удаление: " << s.pop() << endl;
    cout << "Удаление: " << s.pop() << endl;
    
    cout << "Пустой?: " << (s.isEmpty() ? "да" : "нет") << endl;
    
    return 0;
}
