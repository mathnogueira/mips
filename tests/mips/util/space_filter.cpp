#include <gtest/gtest.h>
#include <mips/util/filter/space_filter.hpp>
#include <string>

using namespace MIPS;

TEST(SpaceFilter, filterTabs) {
	std::string str("\t\tThis\t is\t a string!");
	SpaceFilter filter;
	ASSERT_STREQ("This is a string!", filter.filter(str).c_str());
}

TEST(SpaceFilter, filterSpaces) {
	std::string str("       This is a string!    ");
	SpaceFilter filter;
	ASSERT_STREQ("This is a string!", filter.filter(str).c_str());
}

TEST(SpaceFilter, nothingToFilter) {
	std::string str("");
	SpaceFilter filter;
	ASSERT_STREQ("", filter.filter(str).c_str());
}
