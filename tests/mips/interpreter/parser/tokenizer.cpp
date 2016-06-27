#include <mips/interpreter/parser/tokenizer.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace MIPS;

TEST(Tokenizer, alright_mips) {
	char cmd[60] = "addi $s0, $zero, 2";
	Tokenizer tokenizer;
	std::vector<char*> tokens;
	tokenizer.tokenize(cmd, tokens);
	ASSERT_EQ(tokens.size(), 4);
	ASSERT_STREQ(tokens.at(0), "addi");
	ASSERT_STREQ(tokens.at(1), "$s0");
	ASSERT_STREQ(tokens.at(2), "$zero");
	ASSERT_STREQ(tokens.at(3), "2");
}

TEST(Tokenizer, empty_mips) {
	char cmd[60] = "";
	Tokenizer tokenizer;
	std::vector<char*> tokens;
	tokenizer.tokenize(cmd, tokens);
	ASSERT_EQ(tokens.size(), 0);
}

TEST(Tokenizer, whitespace_mips) {
	char cmd[60] = "   \t\t\t               ";
	Tokenizer tokenizer;
	std::vector<char*> tokens;
	tokenizer.tokenize(cmd, tokens);
	ASSERT_EQ(tokens.size(), 0);
}

TEST(Tokenizer, tab_mips) {
	char cmd[60] = "\t\t\t\taddi \t\t\t$t0, \t$zero,\t 3";
	Tokenizer tokenizer;
	std::vector<char*> tokens;
	tokenizer.tokenize(cmd, tokens);
	ASSERT_EQ(tokens.size(), 4);
	ASSERT_STREQ(tokens.at(0), "addi");
	ASSERT_STREQ(tokens.at(1), "$t0");
	ASSERT_STREQ(tokens.at(2), "$zero");
	ASSERT_STREQ(tokens.at(3), "3");
}
