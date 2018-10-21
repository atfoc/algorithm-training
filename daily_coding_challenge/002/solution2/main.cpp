#include <iostream>
#include <vector>
#include <numeric>

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
	int accum(0);
	bool has_zero(false);

	accum = std::accumulate(v.begin(), v.end(), 1, [&](const auto &fst, const auto &snd)
	{
		if(fst == 0 || snd == 0)
		{
			has_zero = true;
			return (fst == 0 ? 1 : fst) * (snd == 0 ? 1 : snd);
		}
		return fst * snd;
	});

	for(auto it = v.begin(), end = v.end(); it != end; ++it, ++oit)
	{
		if(*it == 0)
		{
			*oit = accum;
			continue;
		}

		*oit = has_zero ? 0 : (accum / *it);
	}

	return result;
}

