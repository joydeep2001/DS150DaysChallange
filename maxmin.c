#include "utils.h"
#include<limits.h>
#define MAX 10000

typedef struct container
{
	int min, max;
}container;

//My first approach
container find_max_min(int* arr, int size)
{
	int i, j;
	container cont;
	cont.max = INT_MIN;
	cont.min = INT_MAX;

	for(i = 0;i < size;i++)
	{
		if(arr[i] < cont.min) cont.min = arr[i];
		if(arr[i] > cont.max) cont.max = arr[i];
	}
	return cont;
}

//Tournament method (Learnt from GFG)
container find_max_min(int* arr, int left, int right)
{
	
	container final;
	//base case
	//when only 1 element in the array
	if(left == right)
	{
		final.max = final.min = arr[left];
		return final;
	}

	int mid;
	mid = (left + right) / 2;
	container c1 = find_max_min(arr, left, mid);
	container c2 = find_max_min(arr, mid + 1, right);
	final.max = max(c1.max, c2.max);
	final.min = min(c1.min, c2.min);
	return final;

}

int main()
{
	container cont;
	int arr[MAX];
	printf("Enter the elements: ");
	int size = input(arr, MAX);
	//first approach
	//cont = find_max_min(arr, size);
	//better approach (Tournament method)
	cont = find_max_min(arr, 0, size - 1);
	printf("Max: %d Min: %d\n", cont.max, cont.min);
	return 0;	

}

