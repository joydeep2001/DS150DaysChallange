#include"utils.h"
#include<stdlib.h>
#define MAX 10000


int union_(int* arr, int* arr1,int n, int* arr2, int m)
{
	int i, j, k;
	for(i = 0, j = 0,k = 0;i < n && j < m;)
	{
		if(k == 0)
		{
			arr[k++] = min(arr1[i++], arr2[j++]);
			continue;
		}
		if(arr[k - 1] == arr1[i])
			i++;
		else if(arr[k - 1] == arr2[j])
			j++;
		else if(arr1[i] < arr2[j])
			arr[k++] = arr1[i++];
		else if(arr[k - 1] != arr2[j])
			arr[k++] = arr2[j++];
	}
	while(i < n)
	{
		if(arr[k - 1] == arr1[i])
		{
			i++;
			continue;
		}
		arr[k++] = arr1[i++];
	}
	while(j < m)
	{
		if(arr[k - 1] == arr2[j])
		{
			j++;
			continue;
		}
		arr[k++] = arr2[j++];
	}
		

	return k;
}

int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int arr1[MAX], arr2[MAX], arr[2 * MAX];
	printf("Enter the elements of first array: ");
	int n = input(arr1, MAX);
	printf("Enter the elements of second array: ");
	int m = input(arr2, MAX);
	qsort(arr1, n, sizeof(int), compare);
	qsort(arr2, m, sizeof(int), compare);
	int result =  union_(arr, arr1, n, arr2, m);
	print(arr, result);
	printf("%d", result);
}