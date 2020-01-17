
#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)

{
	int mid;
	while(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
		{
			return true;
		}
		else if(array[mid]>element)
		{
			return binarySearchReacursive(array,startIndex,mid-1,element);
		}
		else
		{
			return binarySearchReacursive(array,mid+1,lastIndex,element);
		}
	}
	return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)

{
	int mid;
	mid=(startIndex+lastIndex)/2;
	while(startIndex<=lastIndex)
	{
		if(array[mid]<element)
		{
			startIndex=mid+1;
		}
		else if(array[mid]>element)
		{
			lastIndex=mid-1;
		}
		else if(array[mid]==element)
		{
			return true;
		}
		mid=(startIndex+lastIndex)/2;
	}
	return false;
}



int main()

{
	int num,size;
	int first=0;
	int last;
	char ch;
	bool result;
	cout << "Enter the size of the array:";
	cin >> size;
	last=size;
	int arr[size];
	cout << "\nEnter the elements of the array:";
	for(int i=0;i<size;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+size);
	cout << "\nSEARCH MENU:";
	cout << "\n1.ITERATIVE";
	cout << "\n2.RECURSION";
	cout << "\nEnter the type of search to perform:";
	cin >> ch;
	cout << "\nEnter the element to be searched for:";
	cin >> num;
	if(ch==1)
	{
		result=binarySearchIterative(arr,first,last,num);
	}
	else if(ch==2)
	{
		result=binarySearchReacursive(arr,first,last,num);
	}
	if(result)
	{
		cout << "FOUND!";
	}
	else
	{
		cout << "NOT FOUND!";
	}
	return 0;
}
