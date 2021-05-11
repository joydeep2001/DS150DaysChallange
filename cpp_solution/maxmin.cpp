#include<iostream>

using namespace std;
#define MAX 10000

typedef struct Pair {
	int max, min;
}Pair;

Pair find_min_max(int* arr, int n)
{
	Pair minmax;
	int i;
	if(n % 2 == 0)
	{
		//1 comparism
		if(arr[0] > arr[1])
		{
			minmax.max = arr[0];
			minmax.min = arr[1];
		}
		else
		{
			minmax.max = arr[1];
			minmax.min = arr[0];
		}

		i = 2;
	}

	else 
	{
		minmax.max = minmax.min = arr[0];
		i = 1;
	}

	//3(n - 1) comparism 
	for(;i < n - 1;i += 2)
	{
		if(arr[i] > arr[i + 1])
		{
			minmax.max = max(arr[i], minmax.max);
			minmax.min = min(arr[i + 1], minmax.min);
		}
		else
		{
			minmax.max = max(arr[i + 1], minmax.max);
			minmax.min = min(arr[i], minmax.min);
		}
	}

	
	return minmax;


}

int main()
{
	int n;
	int arr[MAX];
	cout << "Enter the number of Elements: ";
	cin >> n;
	cout << "Enter the elements: ";
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	Pair p = find_min_max(arr, n);

	cout << "Min element: "<< p.min << "\nMax Element: " << p.max;


}