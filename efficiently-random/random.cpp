#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

class RandomDS
{
	unordered_map<int,int> Pmap;
	unordered_map<int,int> Omap;

	unordered_map<int,int> umap1;
	unordered_map<int,int> umap2;
	int size = 0;
public:
/*	RandomDS()
	{
		Pmap = &umap1;
		Omap = &umap2;
	}*/
	void insert(int x)
	{
		if( (Pmap).find(x) == (Pmap).end())
		{
			umap1[x] = x;
			(Pmap)[x] = x;
		}
	}	

	bool search(int x)
	{
		if((Pmap).find(x) == (Pmap).end())
			return false;
		else
			return true;
	}


	bool deletes(int x)
	{
		if((Pmap).find(x) == Pmap.end())
			return false;
		else
		{
			(Pmap).erase(x);
			umap1.erase(x);
		}
	}

	int uniform_random()
	{
		unordered_map<int,int>:: iterator itr;
		int reqNumber;
		for (itr = umap1.begin(); itr != umap1.end(); ++itr)
		{
			reqNumber = itr->first; 
			break;
		}

		Omap[reqNumber] = reqNumber;
		umap1.erase(reqNumber);
		if(umap1.size() == 0)
			swap(umap1,Omap);
		return reqNumber;

	}

};

int main()
{
	RandomDS random;
	while(1)
	{
		string line;
		cin >> line;
		if(line[0] == 'I')
			random.insert();
		if(line[0] == 'D')

		if(line[0] == 'S')

		if(line[0] == '')


	}


/*	while(1)
	{


	}*/

return 0;
}