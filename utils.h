
#include<stdio.h>

/*PRINT FUNCTION
>>Arguments: 2
#1 The pointer of the array
#2 index of the array upto 
which it is to be printed
>>Return type void
*/
void print(int* arr, int size)
{
	int i;
	printf("\n");
	for(i = 0;i < size;i++) 
		printf("%d ", arr[i]);
	printf("\n");
}
/*SWAP function 
>>Arguments: 3
#1 The pointer of the array
#2 & 3 two indexs of the array
which will be swapped
>>Return type void
*/
void swap(int* arr, int i, int j) 
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/* INPUT FUNCTION
>>Arguments : 2
#1 The Pointer of the array
#2 Max size of the array
>>Return type int
>>Description
It reads the input untill Enter key is pressed
or the size of the array is exosted
It returns the total number of element
added in the array in other words the size of the 
array
*/
int input(int* arr, int max_size)
{
	int size;
	char c = 0;
	for(size = 0; size < max_size && c != '\n';size++) 
		scanf("%d%c", &arr[size], &c);	
	return size;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int indexOfMax(int* arr, int i, int j)
{
	return arr[i] > arr[j] ? i : j;
}

int indexOfMin(int* arr, int i, int j)
{
	return arr[i] < arr[j] ? i : j;
}

