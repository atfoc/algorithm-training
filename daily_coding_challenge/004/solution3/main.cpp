#include <iostream>
#include <array>
#include <algorithm>

template <std::size_t N>
inline void invert(std::array<int, N> &arr, int index)
{
	if(index < 0 || index >= arr.size())
	{
		return;
	}

	if(arr[index] > 0)
	{
		arr[index] *= -1;
	}
}

int main()
{

	std::array<int, 6> v{3, 1, 5, -2, 2, 7};
	auto beg = v.begin();

	for(auto it = v.begin(), end = v.end(); it != end; ++it)
	{
		if(*it < 0)
		{
			std::swap(*beg, *it);
			++beg;
		}
	}

	int offset = static_cast<int>(std::distance(v.begin(), beg));
	for(auto it = beg, end = v.end(); it != end; ++it)
	{
		invert(v, *it-1 + offset);
	}

	std::cout <<
	std::distance(beg, std::find_if(beg, v.end(), [](auto &&x){ return x > 0;}))+1 << std::endl;


	return 0;
}
