#include <string>
#include <vector>

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

	int GetAlphaScore(const string& stringA, const string& stringB)
	{
		double samechar = 0;
		for(char ch1 :stringA)
		{
			for (char ch2 : stringB)
			{
				if (ch1 == ch2) {
					samechar++;
					break;
				}
			}
		}
		
		vector<char> totalalpha = {};

		for (char ch : stringA)
		{
			bool flag = true;
			for(char compare : totalalpha)
			{
				if(ch == compare)
				{
					flag = false;
				}
			}
			if (!flag) continue;
			totalalpha.push_back(ch);
		}
		for (char ch : stringB)
		{
			bool flag = true;
			for (char compare : totalalpha)
			{
				if (ch == compare)
				{
					flag = false;
				}
			}
			if (!flag) continue;
			totalalpha.push_back(ch);
		}

		if (totalalpha.size() == 0) return 0;
		
		 return (samechar/totalalpha.size())*40;
	}

	int GetCompareResult(const string& stringA, const string& stringB)
	{
		return GetLengthScore(GetLengthStruct(stringA.length(), stringB.length())) + GetAlphaScore(stringA, stringB);
	}
};