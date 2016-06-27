#include <gtest/gtest.h>
#include <mips/util/structure/queue.hpp>

using namespace MIPS;

TEST(Queue, add_and_pop) {
	int a = 3, b = 5;
	Queue<int> ints;
	ints.push(a);
	ints.push(b);
	ASSERT_EQ(ints.pop(), a);
	ASSERT_EQ(ints.pop(), b);
}

TEST(Queue, add_and_get) {
	int a = 3, b = 5;
	Queue<int> ints;
	ints.push(a);
	ints.push(b);
	ASSERT_EQ(ints.get(0), a);
	ASSERT_EQ(ints.get(1), b);
	ASSERT_EQ(ints.get(33), b);
	while (ints.size()) {
		ints.pop();
	}
}

TEST(Queue, add_pointer) {
	int a = 3, b = 5;
	int *pa = &a, *pb = &b;
	Queue<int*> ints;
	ints.push(pa);
	ints.push(pb);
	*(ints.get(0)) = 10;
	*(ints.get(1)) = *(ints.get(0)) + 3;
	ASSERT_EQ(a, 10);
	ASSERT_EQ(b, 13);
}
