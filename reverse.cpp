#include<iostream>
using namespace std;
#define MAX 100000 

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void reverse(int* arr, int n)
{
	int i = 0, j = n - 1;
	while(i < j)
	{
		swap(arr[i], arr[j]);
		i++, j--;
	}
}
void print(int* arr, int n)
{
	for(int i = 0;i < n;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() 
{
	int arr[MAX], n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the elements of the array: ";
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	reverse(arr, n);
	print(arr, n);
	return 0;
}

