#include<iostream>
#include<bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//#define ONLINE_JUDGE
using namespace std;

#ifndef ONLINE_JUDGE
	#include "debugger.h"
#endif


#define MAX 10000

int main()
{
	
	vector<int> a, b;
	int a_size, b_size;
	__debug_init();
	__input();

	cin >> a_size >> b_size;
	a.resize(a_size);
	b.resize(b_size);

	for(int i = 0;i < a_size;i++)
		cin >> a[i];
	for(int i = 0;i < b_size;i++)
		cin >> b[i];

	debug(a_size);




}