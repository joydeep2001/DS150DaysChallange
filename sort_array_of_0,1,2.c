#include"utils.h"
#define MAX 10000
void sort_and_print(int* arr, int size)
{
	int counter[3] = {0};
	for(int i = 0;i < size;i++)
		counter[arr[i]]++;
	for(int i = 0;i < 3;i++)
		while(counter[i]--)
			printf("%d ", i);
}
int main()
{
	int arr[MAX];
	printf("Enter the elements\n");
	int size = input(arr, MAX);
	sort_and_print(arr, size);

}