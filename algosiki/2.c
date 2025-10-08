#include <stdio.h>

int main(void) {
 int a,b,m, res;
 printf("a b m: ");
 scanf("%i %i %i", &a, &b, &m);
 
 res = ((a % m) * (b % m)) % m;
 printf("(%i * %i) mod %i = %i\n",a,b,m,res);
}
