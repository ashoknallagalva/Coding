#include<bits/stdc++.h>

using namespace std;

void sieve(vector<int>& primes);

int main()
{
		int t ;
		cin>>t;
		vector<int> primes;
		sieve(primes);
		while(t--)
		{
			int n,m;
			cin>>m>>n;
			if(m==1)
			{
				if(m==n)
				{
					cout<<endl;
					continue;
				} 
				else 
				{
					m = 2;
				}
					
			}
			for(int i = m; i<=n;i++)
			{
				bool isPrime = true;
				for(int j=0;j<primes.size() && primes[j] < i;j++){
					if((i%primes[j]) == 0)
						isPrime = false;
				}
				if(isPrime)
					cout<<i<<endl;
			}
			
			cout<<endl;
			
		}
		return 0;
}

void sieve(vector<int>& primes)
{
	int MAX_VALUE = 31623;
	vector<bool> numbers(MAX_VALUE,false);
	for(int p=2;p<=MAX_VALUE;)
	{
		primes.push_back(p);
		
		for(int i=2;(i*p)<MAX_VALUE;i++)
		{
			numbers[i*p] = true;
		}
		
		int ptemp = p;
		
		do 
		{
			ptemp++;
			
		}while(ptemp < MAX_VALUE && numbers[ptemp] != false);
		
		p = ptemp;
	}
	
}
