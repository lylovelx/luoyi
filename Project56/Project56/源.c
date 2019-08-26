#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void permutation(int* a,int start,int end ) {
	if (start==end){
		for (int i = 0; i <= end;++i){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else{
		for (int i = start; i <= end;++i){
			swap(&a[i],&a[start]);
			permutation(a,start+1,end);
			swap(&a[start],&a[i]);
		}
	
	}

}
int main() {

	int a[] = { 1, 2, 3 ,4,5};
	permutation(a, 0, 4);
	system("pause");
	return 0;

}