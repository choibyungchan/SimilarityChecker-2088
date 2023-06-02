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