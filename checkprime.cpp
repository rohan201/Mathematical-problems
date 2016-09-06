#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#define MAX 10000


using namespace std;

int LeastPrimeDivisor(int n);

bool b[MAX];
int lp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	
	lp[i] = 2; //even numbers have smallest prime factor 2
	for (int i = 3; i < MAX; i += 2)
	{
		if (!b[i]){
			lp[i] = i;
			for (int j = i; (j*i) < MAX; j += 2)
			{
				if (!b[j*i])	b[j*i] = true, lp[j*i] = i;
			}
		}
	}
}

int main()
{
	int a,t;
	Sieve();
	cin>>t; // number of test cases
	while(t--)
	{
	cin>>a;
	int p=LeastPrimeDivisor(a);
	cout<<p<<endl;
    }
}


int LeastPrimeDivisor(int n)
{
    int a=lp[n];
    return a;
}

