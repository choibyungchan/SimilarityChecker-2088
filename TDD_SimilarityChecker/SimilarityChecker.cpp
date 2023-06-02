#include <string>
#include <vector>
#define MAX_LEGNTH_SCORE 60

using namespace std;

struct Length
{
	int longlength;
	int shortlength;
};




class SimilarityChecker
{
public:
	int GetCompareResult(const string& stringA, const string& stringB)
	{
		return GetLengthScore(GetLengthStruct(stringA.length(), stringB.length())) + GetAlphaScore(stringA, stringB);
	}

	int GetLengthScore(Length st_length)
	{
		int result = (1.0 - ((double)(st_length.longlength - st_length.shortlength) / st_length.shortlength)) * MAX_LEGNTH_SCORE;
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

	int GetAlphaScore(const string& stringA, const string& stringB)
	{
		vector<char> samealpha = {};
		for (char ch1 : stringA)
		{
			for (char ch2 : stringB)
			{
				if (ch1 != ch2) continue;
				RemovesameAlpha(samealpha, ch1);
				break;
			}
		}

		vector<char> totalalpha = remove_duplicate(stringA, stringB);

		return ((double)samealpha.size()/totalalpha.size())*40;
	}

	void RemovesameAlpha(vector<char>& samealpha, char ch1)
	{
		for (char ch : samealpha)
		{
			if (ch != ch1) continue;
			
			return;
		}

		samealpha.push_back(ch1);
	}

	vector<char> remove_duplicate(const string& stringA, const string& stringB)
	{
		vector<char> totalalpha = {};
		for (char ch : stringA)
		{
			RemovesameAlpha(totalalpha, ch);
		}

		for (char ch : stringB)
		{
			RemovesameAlpha(totalalpha, ch);
		}
		return totalalpha;
	}
};