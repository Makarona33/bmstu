#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Inf;
typedef int Key;

struct Elem {
    Key key;
    Inf inf;
    struct Elem* next;
};

struct Elem* head = NULL;

void Create() { head = NULL; }

int IsEmpty() { return head == NULL; }

struct Elem* FindByKey(Key x) {
    struct Elem* p = head;
    while (p != NULL && p->key != x) {
        p = p->next;
    }
    return p;
}

void Add(Key x, Inf ii) {
    if (FindByKey(x) != NULL) return;
    
    struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
    newElem->key = x;
    newElem->inf = malloc(strlen(ii) + 1);
    strcpy(newElem->inf, ii);
    
    if (head == NULL || head->key > x) {
        newElem->next = head;
        head = newElem;
        return;
    }
    
    struct Elem* current = head;
    while (current->next != NULL && current->next->key < x) {
        current = current->next;
    }
    
    newElem->next = current->next;
    current->next = newElem;
}

int Delete(Key x) {
    if (head == NULL) return 0;
    
    if (head->key == x) {
        struct Elem* temp = head;
        head = head->next;
        free(temp->inf);
        free(temp);
        return 1;
    }
    
    struct Elem* current = head;
    while (current->next != NULL && current->next->key != x) {
        current = current->next;
    }
    
    if (current->next == NULL) return 0;
    
    struct Elem* temp = current->next;
    current->next = current->next->next;
    free(temp->inf);
    free(temp);
    return 1;
}

void Print() {
    struct Elem* p = head;
    while (p != NULL) {
        printf("%d: %s\n", p->key, p->inf);
        p = p->next;
    }
}


int main() {
    Create(); // 2б2 – таблица, упорядоченная по ключу (динамическая цепочка)
    
    Add(10, "ааа");
    Add(50, "ддд");
    Add(30, "ввв");
    Add(20, "ббб");
    Add(40, "ггг");
    
    Print();
    
    printf("\nПоиск элемента 30: ");
    struct Elem* found = FindByKey(30);
    if (found) printf("%s\n", found->inf);
    else printf("не найден\n");
    
    printf("Поиск элемента 99: ");
    found = FindByKey(99);
    if (found) printf("%s\n", found->inf);
    else printf("не найден\n");
    
    printf("\nУдаление 20\n");
    Delete(20);
    Print();
    
    printf("\nДобавление 30 (уже есть)\n");
    Add(30, "новое значение");
    Print();

    return 0;
}
