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

	void remove_duplicate(const string& stringA, vector<char>& totalalpha)
	{
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
	}

	int GetAlphaScore(const string& stringA, const string& stringB)
	{
		vector<char> totalalpha = {};

		remove_duplicate(stringA, totalalpha);
		remove_duplicate(stringB, totalalpha);
		
		vector<char> samealpha = {};
		for(char ch1 :stringA)
		{
			for (char ch2 : stringB)
			{
				if (ch1 == ch2) {
					bool flag = true;
					for(char ch3: samealpha)
					{
						if (ch3 == ch1)
							flag = false;
					}
					if (!flag) break;
					samealpha.push_back(ch1);
					break;
				}
			}
		}

		 return ((double)samealpha.size()/totalalpha.size())*40;
	}

	int GetCompareResult(const string& stringA, const string& stringB)
	{
		return GetLengthScore(GetLengthStruct(stringA.length(), stringB.length())) + GetAlphaScore(stringA, stringB);
	}
};