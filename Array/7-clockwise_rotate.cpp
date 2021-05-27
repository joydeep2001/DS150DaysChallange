#include<iostream>
using namespace std;
#define MAX 100000

void rotate(int* arr, int n)
{

	int current, next;
	current = arr[0];
	next = current;
	for(int i = 0;i < n -1;i++)
	{
		next = arr[i + 1];
		arr[i + 1] = current;
		current = next;
	}
	arr[0] = next;

}

int main()
{
	int arr[MAX];
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	for(int i =0;i < n;i++)
		cin >> arr[i];


	rotate(arr, n);
	
	for(int i = 0;i < n;i++)
		cout << arr[i] << " "; 
}