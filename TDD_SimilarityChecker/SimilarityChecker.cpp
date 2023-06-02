#include <string>

using namespace std;
class SimilarityChecker
{
public:
	int GetCompareResult(const string& stringA, const string& stringB)
	{
		return (1 - (stringA.length() - stringB.length()) / stringB.length()) * 60;
	}
};