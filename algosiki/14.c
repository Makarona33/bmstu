#include <stdio.h>

int main(void) {
    char str[1000];
    fgets(str, 1000, stdin);
    int w = 0;
    
    if (str[0] != ' ') w += 1;
    
    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i] != ' ') && (str[i-1] == ' ')) w += 1;
    }
    
    printf("%d", w);
    return 0;
}
