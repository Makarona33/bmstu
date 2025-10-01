#include <stdio.h>

int main(void) {
    int height, width;
    scanf("%d %d ", &height, &width);
    
    char str[1000];
    fgets(str, 1000, stdin);
    
    int len_str = 0;
    while (str[len_str] != '\0') len_str++;

    if (((len_str > (width - 2)) || (height < 3))) {
        printf("Error");
        return 0;
    } 
    
    int dy = height - 3, dx = width - 2 - len_str;
    int dy_1 = dy / 2, dx_1 = dx / 2;
    int dy_2 = dy - dy_1, dx_2 = dx - dx_1;
    
    for (int i = 0; i < width; i++) printf("*");
    printf("\n");
    
    for (int i = 0; i < dy_1; i++) {
        printf("*");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("*\n");
    }
    
    printf("*");
    for (int i = 0; i < dx_1; i++) printf(" ");
    printf("%s", str);
    for (int i = 0; i < dx_2; i++) printf(" ");
    printf("*\n");
    
    for (int i = 0; i < dy_2; i++) {
        printf("*");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("*\n");
    }
    
    for (int i = 0; i < width; i++) printf("*");
    
    return 0;
}
