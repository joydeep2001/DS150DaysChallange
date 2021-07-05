#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution {
public:
	
	int getMinDiff(int arr[], int n, int k)
	{
		sort(arr, arr + n);
		int minEl, maxEl; 
		int lastId = n - 1;
		int result = arr[0] + arr[lastId]; 

		for(int i = 1;i < n;i++) 
		{
			maxEl = max(arr[lastId] - k, arr[i - 1] + k);//16
			minEl = min(arr[0] + k, arr[i] - k);//4
			if(maxEl > 0 && minEl > 0)
				result =  min(result, maxEl - minEl);
		}
		return result;
		
	}
};

// Driver Code
int main()
{
	int t = 1;

	while (t--) {
		int k = 6;
		int n = 3;
		int arr[n] = { 1, 15, 10 };

		Solution ob;
		auto ans = ob.getMinDiff(arr, n, k);
		cout << ans << "\n";
	}
	return 0;
}
