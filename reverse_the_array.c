#include "utils.h"

#define MAX 100000 

void reverse(int* arr, int min_index, int max_index) 
{
	if(min_index >= max_index) return;
	swap(arr, min_index, max_index);
	reverse(arr, min_index + 1, max_index - 1);
}

int main() 
{
	int arr[MAX];
	
	printf("Enter the Elements: ");
	int size = input(arr, MAX);
	reverse(arr, 0, size - 1);
	print(arr, size);

	return 0;
}

