#include <gtest/gtest.h>
#include <mips/util/file_reader.hpp>
#include <mips/util/filter/space_filter.hpp>

using namespace MIPS;

TEST(FileReader, openFile) {
	FileReader fr("../tests/input/test1.asm");
	SUCCEED();
}

TEST(FileReader, getLine) {
	FileReader fr("../tests/input/test1.asm");
	ASSERT_STREQ("add r0 $zero r1", fr.next());
}

TEST(FileReader, getIndentedLine) {
	SpaceFilter f;
	FileReader fr("../tests/input/teste_tabs.asm", f);
	ASSERT_STREQ("add r0 $zero r1", fr.next());
}

TEST(FileReader, skipEmptyLines) {
	SpaceFilter f;
	FileReader fr("../tests/input/teste_lbreaks.asm", f);
	ASSERT_STREQ("add r0 $zero r1", fr.next());
}
