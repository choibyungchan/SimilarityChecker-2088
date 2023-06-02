#include <string>

using namespace std;

struct Length
{
	int longlength;
	int shortlength;
};

class SimilarityChecker
{
public:
	int GetLengthScore(Length st_length)
	{
		int result = (1.0 - ((double)(st_length.longlength - st_length.shortlength) / st_length.shortlength)) * 60;
		if (result < 0) return 0;
		return result;
	}

	Length GetLengthStruct(int stringAlength, int stringBlength)
	{
		Length st_length;
		if (stringAlength >= stringBlength)
		{
			st_length.longlength = stringAlength;
			st_length.shortlength = stringBlength;
		}
		else
		{
			st_length.longlength = stringBlength;
			st_length.shortlength = stringAlength;
		}
		return st_length;
	}

	int GetCompareResult(const string& stringA, const string& stringB)
	{
		return GetLengthScore(GetLengthStruct(stringA.length(), stringB.length()));
	}
};