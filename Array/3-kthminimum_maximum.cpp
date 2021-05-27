#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 10000

bool smaller(int x, int y)
{
	return x < y;
}
bool greater_(int x, int y)
{
	return x > y;
}

int leftChildIndex(int parentIndex)
{
	return parentIndex * 2 + 1;
}
int rightChidIndex(int parentIndex)
{
	return parentIndex * 2 + 2;
}

void heapify(int* arr, int kthIndex, int parentIndex, bool (*compare)(int, int))
{
	int leftIndex = leftChildIndex(parentIndex);
	int rightIndex = rightChidIndex(parentIndex);

	int requiredIndex = parentIndex;

	if(leftIndex <= kthIndex and compare(arr[leftIndex], arr[requiredIndex]))
		requiredIndex = leftIndex;
	if(rightIndex <= kthIndex and compare(arr[rightIndex], arr[requiredIndex]))
		requiredIndex = rightIndex;

	if(requiredIndex == parentIndex)
		return;
	swap(arr[parentIndex], arr[requiredIndex]);
	heapify(arr, kthIndex, requiredIndex, compare);

}

int getRequiredElement(int* arr, int kthIndex, int lastIndex, bool (*compare)(int, int))
{
	for(int i = kthIndex + 1;i <= lastIndex;i++)
	{
		if(compare(arr[0], arr[i]))
		{
			swap(arr[0], arr[i]);
			heapify(arr, kthIndex, 0, compare);
		}
	}

	return arr[0];
}


int lastNonLeafNode(int lastIndex)
{
	return (lastIndex - 1) / 2;
}




void build_heap(int* arr, int kthIndex, bool (*compare)(int, int))
{
	for(int parentIndex = lastNonLeafNode(kthIndex); parentIndex >= 0;parentIndex--)
		heapify(arr, kthIndex, parentIndex, compare);
}

int main()
{
	int arr[MAX], n, k;
	bool (*compare)(int, int);
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Which element is to be found: ";
	cin >> k;
	cout << "Enter the elements of the array: ";
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	//For getting kthSmallest
	compare = greater_;
	build_heap(arr, k - 1, compare);
	int kthSmallest = getRequiredElement(arr, k - 1, n - 1, compare);
	cout << "The kth smallest element is: " << kthSmallest << endl;
	//for getting kthLargest
	compare = smaller;
	build_heap(arr, k - 1, compare);
	int kthLargest = getRequiredElement(arr, k - 1, n - 1, compare);
	cout << "The kth largest element is: " << kthLargest << endl;
	

	return 0;
}


