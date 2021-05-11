#include<iostream>
using namespace std;
#define MAX 100000 



void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(int* arr, int size)
{
	for(int left = 0, right = size - 1;left < right;left++,right--)
		swap(&arr[left], &arr[right]);


}
void print(int* arr, int size)
{	
	for(int i = 0;i < size;i++)
		cout << arr[i] << " ";
}
int main() 
{
	int arr[MAX];
	int n;
	cout << "Enter the number of Elements: ";
	cin >> n;
	cout << "Enter the Elements: ";
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	reverse(arr, n);

	print(arr, n);

	return 0;
}

