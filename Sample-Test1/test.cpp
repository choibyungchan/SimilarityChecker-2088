#include "pch.h"
#include"../TDD_SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityTC, CompareSameLength) {
	string A = "ABC";
	string B = "HHH";

	int score = 60;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A,B));
}

TEST(SimilarityTC, CompareDoubleGapLength) {
	string A = "ABCDFG";
	string B = "HHH";

	int score = 0;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}

TEST(SimilarityTC, CompareBisLongLength) {
	string A = "HHH";
	string B = "ABCDFG";

	int score = 0;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}

TEST(SimilarityTC, ComparesimilarLength) {
	string A = "HHHG";
	string B = "ABCDFU";

	int score = 30;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}

TEST(SimilarityTC, CompareTripeGapLength) {
	string A = "HHH";
	string B = "ABCDFGGGG";

	int score = 0;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}


TEST(SimilarityTC, CompareSameAlpha) {
	string A = "ABC";
	string B = "ABC";

	int score = 100;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}


TEST(SimilarityTC, CompareAlphaCase1) {
	string A = "ABCD";
	string B = "ABHH";

	int score = 76;
	EXPECT_EQ(score, SimilarityChecker().GetCompareResult(A, B));
}
