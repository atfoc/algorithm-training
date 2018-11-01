#include <iostream>
#include <array>
#include <algorithm>


int main()
{

	std::array<int, 6> v{3, 1, 5, -2, 2, 7};

	for(int i = 1; i <= v.size(); ++i)
	{
		if(std::find(v.begin(), v.end(), i) == v.end())
		{
			std::cout << "Solution is: " << i << std::endl;
			break;
		}
	}

	return 0;
}
