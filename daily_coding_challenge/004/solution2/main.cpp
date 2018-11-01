#include <iostream>
#include <array>
#include <algorithm>


int main()
{

	std::array<int, 6> v{3, 1, 5, -2, 2, 7};

	std::sort(v.begin(), v.end());

	int sol(1);

	for (auto &&it : v)
	{
		if(it <= 0)
		{
			continue;
		}

		if(it == sol)
		{
			++sol;
		}

	}

	std::cout << "Solution is: " << sol << std::endl;
	return 0;
}
