#include "queue_extented.h"
#include <iostream>
using namespace std;

int main()
{
    queue<int> q;
	for(int i = 1; i < 10; i++)
		q.push(i);
	int sizeOfArr = 0; 
	int * arr = getArrayOfAverageSums(q, sizeOfArr, 3);
	for(int i = 0; i < sizeOfArr; i++)
		cout << arr[i]  << " ";
	delete [] arr;
    return 0;
}
