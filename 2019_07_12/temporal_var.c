#include <stdio.h>

int a;

int sum(int x, int y){
	int z;
	z=x+y;
	a=a+6;
	return z;
}

int main (int argc, char** argv){
	a=4;
	printf("suma: %d\n", sum(4,5));
	printf("A: %d\n",a);
	return 0;
}
