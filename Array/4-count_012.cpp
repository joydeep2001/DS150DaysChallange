#include<iostream>
#define MAX 10000
using namespace std;

void sort(int* arr, int n)
{
	int count0 = 0, count2 = 0;
	for(int i = 0;i < n;i++)
	{
		if(arr[i] == 0)
			count0++;
		else if(arr[i] == 2)
			count2++;
	}
	count2 = n - count2;
	for(int i = 0;i < n;i++)
	{
		if(i < count0)
			arr[i] = 0;
		else if(i >= count2)
			arr[i] = 2;
		else
			arr[i] = 1;
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

	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr, n);
	print(arr, n);
}