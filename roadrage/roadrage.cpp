#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
	int x;
	int v;
	int index;
	Node(int x1,int v1,int index1)
	{
		x= x1;
		v = v1;
		index = index1;
	}
};

class BinaryHeap
{

public:
		vector<Node> arr;
	int size;
	void exch(int i, int j)
	{
		Node temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	int getParent(int i)
	{
		if(i > 0 )
			return (i-1)/2;
		else 
			return -1;
	}
	int getLeft(int i)
	{
		return 2*i+1;
	}
	int getRight(int i)
	{
		return 2*i + 2;
	}

	void heapify(int i)
	{
		
		if( i <=  getParent(size-1))
		{
			int min = i;
			if(arr[getLeft(i)].v > arr[i].v)
			{
				min = getLeft(i);
			}

			if(getRight(i) < size)
			{
				
				if(arr[getRight(i)].v > arr[min].v)
					min = getRight(i);
			}

//			cout << min << "WORK" << i << endl;
			if(min != i)
			{
				exch(min,i);
				heapify(min);
			}
			else
				return;
		}

	}

/*	void build(vector<int> arr)
	{
		size = arr.size();
		int index= getParent(size-1);
		while(index >=0 )
		{
			this->arr = arr;
			heapify(index);
			index--;
		}
	}*/

	void insert(Node node)
	{

/*		 node.v = i;
		 node.x = x;
		 node.index = index;
*/		arr.push_back(node);
		size++;
		int index = size-1;
		while(getParent(index) >= 0)
		{
	//		cout << "KAMAL " << index << endl;
			heapify(getParent(index));
			index = getParent(index);
		}
	}

	Node extractTop()
	{
		Node returnVal = arr[0];
		arr[0] = arr[size-1];
		size--;
		heapify(0);
		return returnVal;
	}
};


int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int P;
		cin >> P;
		BinaryHeap heap;
		int j =0;

		while(P--)
		{
			cout << "Hii" << endl;
			int x,v;
			cin >> x;
			cin >> v;
			
			heap.insert(Node(x,v,j));
			j++;
		}
		int count = 0;

		while(1)
		{
		if(heap.size != 0)
		{
			Node n1  = heap.extractTop();
			cout << n1.index << "KK" << endl;
			count = count + P - n1.index -1;
		}
		else
			break;
		}
		cout << count << endl;

		//Take out the elements from heap one by one and then do it




	}
}