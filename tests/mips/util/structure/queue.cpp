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
