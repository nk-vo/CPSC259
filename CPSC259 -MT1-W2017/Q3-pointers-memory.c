#include <stdio.h>
#include <stdlib.h>
#inlcude <string>
int main(void) {
	int a = 9;
	int** b = (int**) malloc(2*sizeof(int*));
  
	int* c = &a;
  
	int** d = &c;
  
	**d = 3;
	b[0] = (int*) malloc(sizeof(int));
	b[1] = (int*) malloc(a*sizeof(int));
	d = b;
	*(d+1) [0] = 8;
	b[1][1] = 6;
	b[1][2] = 4;
	c = *(b+1);
	printf("a: %d \n", a);
	printf("*c: %d\n", *c);
}