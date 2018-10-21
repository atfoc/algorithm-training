#include <iostream>
#include <vector>
#include <unordered_set>

void solve(const std::vector<int> &v, int k);

int main()
{

    std::vector<int> v;
    int tmp;
    int k;

    /*Loading data*/
    std::cin >> k;

    while((std::cin >> tmp))
    {
        v.push_back(tmp);
    }


    solve(v, k);


    return 0;
}


void solve(const std::vector<int> &v, int k)
{
	std::unordered_set<int> set;

	for(auto &&it : v)
	{
		if(set.find(k - it) != set.end())
		{
			std::cout << "Found solution " << it << " + " << k - it << " = " << k << std::endl;
			return ;
		}
		set.insert(it);
	}

	std::cout << "Didn't find any solution" <<  std::endl;
}