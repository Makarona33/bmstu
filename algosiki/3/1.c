#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nn 10
#define NN nn+1

typedef char* Inf;
typedef int Key;

struct Rec {
    Inf II;
    Key KK;
};

struct Rec M[NN];
int p;

void Create() { p = 0; }

int IsEmpty() { return p == 0; }

int IsFull() { return p >= nn; }

int FindByKey(Key x) {
    int l = 1, r = p;
    while (l <= r) {
        int m = (l + r) / 2;
        if (M[m].KK == x) return m;
        if (M[m].KK < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int Add(Key x, Inf ii) {
    if (IsFull()) return 0;
    if (FindByKey(x)) return 0;
    
    int pos = 1;
    while (pos <= p && M[pos].KK < x) pos++;
    
    for (int i = p; i >= pos; i--)
        M[i + 1] = M[i];
    
    M[pos].KK = x;
    M[pos].II = malloc(strlen(ii) + 1);
    strcpy(M[pos].II, ii);
    
    p++;
    return 1;
}

int Delete(Key x) {
    int pos = FindByKey(x);
    if (pos == 0) return 0;
    
    free(M[pos].II);
    
    for (int i = pos; i < p; i++)
        M[i] = M[i + 1];
    
    p--;
    return 1;
}


void Print() {
    if (IsEmpty()) {
        printf("Таблица пуста\n");
        return;
    }
    for (int i = 1; i <= p; i++)
        printf("%d) %d: %s\n", i, M[i].KK, M[i].II);
}


int main() {
    Create(); // 2а2. – таблица, упорядоченная по ключу
    
    Add(10, "ааа");
    Add(50, "ддд");
    Add(30, "ввв");
    Add(20, "ббб");
    Add(40, "ггг");
    
    
    Print();
    
    printf("\nПорядковый номер ключей: 20 - %d, 99 - %d\n", FindByKey(20), FindByKey(99));
    
    printf("\nУдаление 20\n");
    Delete(20);
    Print();
    
    printf("\nДобавление 30\n");
    Add(30, "F");

    return 0;
}
