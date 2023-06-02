#include <string>

using namespace std;
class SimilarityChecker
{
public:
	int GetCompareResult(const string& stringA, const string& stringB)
	{
		if (stringA.length() >= stringB.length())
			return (1 - (stringA.length() - stringB.length()) / stringB.length()) * 60;
		else
			return (1 - (stringB.length() - stringA.length()) / stringA.length()) * 60;
	}
};