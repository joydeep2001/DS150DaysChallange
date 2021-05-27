#include <iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
#define MAX 10000
int maxSum(int* arr, int n)
{
	int maxSoFar = INT_MIN;
	int maxEndingHere = 0;
	for(int i = 0;i < n;i++)
	{
		maxEndingHere += arr[i];

		if(maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
		if(maxEndingHere < 0)
			maxEndingHere = 0;
	}
	
	return maxSoFar;
}

int main()
{
	int arr[MAX];
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	for(int i =0;i < n;i++)
		cin >> arr[i];


	cout << maxSum(arr, n);
}