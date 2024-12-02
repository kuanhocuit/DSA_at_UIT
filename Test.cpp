#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int maxx=0;
		for (int  i = prices.size();i>0; i--)
		{
			for (int j = i-1; j > 0; j--)
			{
				if(prices[i]-prices[j]>maxx)maxx=prices[i]-prices[j];
			}
		}
		return maxx;
	}
};
int main()
{
	cout << "Hello World";
}
