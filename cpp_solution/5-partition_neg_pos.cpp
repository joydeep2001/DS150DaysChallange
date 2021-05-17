#include<iostream>
#include<algorithm>
using namespace std;
/*Swagoto Check this function*/
void rearrange(int* arr, int n)
{
	int i, j;
	i = -1;

	for(j = 0;j < n;j++)
	{
		//if arr[j] is positive
		//considering that 0 is also positive
		if(arr[j] >= 0){
			//checking arr[i] < 0 or not coz 
			//if already arr[i] is >= 0 (positive) then
			//the arr[j] we encountered is not
			//the left most positive value
			if(i == -1 || arr[i] < 0)
				i = j;
		}
		//for negetive
		else
		{
			if(i != -1){
				swap(arr[i], arr[j]);
				//incrementing i so that it keep
				//pointing to the left most positive
				//index
				i++;
			}
		}
	}
}

void rearrange_double_pointer(int arr[],int n)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(arr[left] >= 0)
         left++;
        else if(arr[right] < 0)
          right--;
        else
            swap(arr[left], arr[right]);
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
	int arr[] = {-12, -13, 11, -5, 6, -7, 5, -3, -6};
	int size = sizeof(arr) / sizeof(int);
	rearrange(arr, size);
	cout << "After Rearrange: " << endl;
	print(arr, size);
}
/*
-12, -13, -5, 6, 11, -7, 5, -3, -6
i = 4
j = 4

*/