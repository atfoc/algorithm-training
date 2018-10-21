#include <iostream>
#include <vector>


std::vector<int> solve(const std::vector<int> &v);

int main()
{

	std::vector<int> v;
	int tmp;

	while((std::cin >> tmp))
	{
		v.push_back(tmp);
	}

	auto result = solve(v);

	for(auto &&it : result)
	{
		std::cout << it << " ";
	}

	std::cout << std::endl;

	return 0;
}

std::vector<int> solve(const std::vector<int> &v)
{
	std::vector<int> result(v.size());
	auto oit = result.begin();
	int tmp(0);

	for(auto it = v.begin(), end = v.end(); it != end; ++it, ++oit)
	{
		tmp = 1;
		for(auto it1 = v.begin(), end = v.end(); it1 != end; ++it1)
		{
			if(it == it1)
			{
				continue;
			}

			tmp *= *it1;
		}
		*oit = tmp;
	}

	return result;
}

