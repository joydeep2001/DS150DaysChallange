#include"utils.h"
#include<limits.h>
#include<stdlib.h>
#define MAX 10000

typedef struct Children {
	int left, right;
}Children;

Children getChildrenIndex(int i)
{
	Children index;
	index.left = 2 * i + 1;
	index.right = 2 * i + 2;
	return index;
}

Children getChildren(int* arr, int i, int size)
{
	Children c, index;
	index = getChildrenIndex(i);
	
	if(index.left < size)
		c.left = arr[index.left];
	else 
		c.left = INT_MAX;
	if(index.right < size)
		c.right = arr[index.right];
	else 
		c.right = INT_MAX;

	return c;

}

int isGreaterThanChildren(int i, int* arr, int size)
{
	Children children = getChildren(arr, i, size); 
	if(arr[i] > children.left || arr[i] > children.right)
		return 1;
	return 0;

}

int lastNonLeafNode(int size_of_arr)
{
	return size_of_arr / 2 - 1;
}


int leafNode(int i, int size)
{
	if(i > lastNonLeafNode(size))
		return 1;
	return 0;
}



void minify(int* arr, int size, int parent)
{
	if(leafNode(parent, size))
		return;
	if(!isGreaterThanChildren(parent, arr, size))
		return;

	Children index = getChildrenIndex(parent);
	int minChildIndex;

	if(index.left >= size)
		minChildIndex = index.right;
	else if(index.right >= size)
		minChildIndex = index.left;
	else
		minChildIndex = indexOfMin(arr, index.left, index.right);

	swap(arr, parent, minChildIndex);
	minify(arr, size, minChildIndex);
	
}
int extractMin(int* heap, int* size)
{
	if(*size < 1)
	{
		printf("No elements in the heap");
		exit(1);
	}

	int min = heap[0];
	heap[0] = heap[*size - 1];
	(*size)--;
	minify(heap, *size, 0);

	return min;

}	
int getKthSmalestElement(int* heap, int* size, int k)
{
	if(k > *size)
	{
		printf("Invalid location");
		exit(1);
	}
	for(int i = 1;i < k;i++)
		extractMin(heap, size);
	return heap[0];
}
void buildHeap(int* arr, int size)
{
	for(int parent = lastNonLeafNode(size);parent >= 0;parent--)
		minify(arr, size, parent);
}

int main()
{
	int arr[MAX], k;
	printf("Enter the elements\n");
	int size = input(arr, MAX);
	printf("Enter k");
	scanf("%d", &k);
	buildHeap(arr, size);
	// k < size / 2 : minify(arr, size) : maxify(arr, size);
	int result = getKthSmalestElement(arr, &size, k);
	printf(">>%d\n", result);
	print(arr, size);
	return 0;
}


