#include "queue_extented.h"
#include "gtest.h"

TEST(UsingOfQueue, can_calculate_the_array)
{
	const int queueSize = 7;
	queue<int> q;
	for(int i = 1; i < queueSize; i++)
		q.push(i);
	int size;
    int * arr;
	EXPECT_NO_THROW(arr = getArrayOfAverageSums(q, size, 3));
}

TEST(UsingOfQueue, is_calculation_correct)
{
	const int queueSize = 7;
    queue<int> q;
	for(int i = 1; i < queueSize; i++)
		q.push(i);
	int size;
    int * arr = getArrayOfAverageSums(q, size, 3);
	for(int i = 0; i < size; i++)
		EXPECT_EQ(i+2, arr[i]);
}

TEST(UsingOfQueue, throws_when_w_bigger_than_)
{
	const int queueSize = 7;
    queue<int> q;
	for(int i = 1; i < queueSize; i++)
		q.push(i);
	int size;
    int * arr;
	EXPECT_ANY_THROW(arr = getArrayOfAverageSums(q, size, 20));
}



