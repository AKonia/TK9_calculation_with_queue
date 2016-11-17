// Copyright 2016 AuthorName. All rights reserved.
#ifndef INCLUDE_QUEUE_EXTENTED_H_
#define INCLUDE_QUEUE_EXTENTED_H_
#include <queue>
using std::queue;
template <typename TypeOfElems>
TypeOfElems * getArrayOfAverageSums(queue<TypeOfElems> q,
int &size, const int w) {
  if (w > q.size())
    throw "Too big input of W";
  size = q.size() - w+1;
  TypeOfElems * arr = new TypeOfElems[size];
    queue<TypeOfElems> buf = q;
  for (int i = 0; i < size; i++)
        arr[i] = 0;
    for (int i = 0; i< w; i++) {
        arr[0] += q.front();
        q.pop();
    }
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i-1] + q.front() - buf.front();
        q.pop();
        buf.pop();
    }
    for (int i = 0; i < size; i++)
        arr[i] /= w;
    return arr;
}
#endif  // INCLUDE_QUEUE_EXTENTED_H_
