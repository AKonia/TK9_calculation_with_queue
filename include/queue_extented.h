#ifndef __QUEUE_EXTENTED__
#define __QUEUE_EXTENTED__
#include <queue>
using namespace std;

template <typename TypeOfElems>
TypeOfElems * getArrayOfAverageSums(queue<TypeOfElems> q, int &size, const int w)
{
	if(w > q.size())
		throw "Too big input of W";
	size = q.size() - w+1;
	TypeOfElems * arr = new TypeOfElems[size];
    queue<TypeOfElems> buf = q;
	for(int i = 0; i < size; i++)
        arr[i] = 0;

    for(int i = 0; i< w; i++)
    {
        arr[0] += q.front();
        q.pop();
    }
    for(int i = 1; i < size; i++)
    {
        arr[i] = arr[i-1] + q.front() - buf.front();
        q.pop();
        buf.pop();
    }
    for(int i = 0; i < size; i++)
        arr[i] /= w;
    return arr;
}
#endif  // __QUEUE_EXTENTED__
