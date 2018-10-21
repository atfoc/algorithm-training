#include <iostream>
#include <vector>

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
    for(auto it = v.begin(), end = v.end(); it != end; ++it)
    {
        for(auto it1 = v.begin(), end1 = v.end(); it1 != end1; ++it1)
        {
            if(*it + *it1 == k)
            {
                std::cout << "Found solution " << *it << " + " << *it1 << " = " << k << std::endl;
                return ;
            }
        }
    }
    std::cout << "Didn't find any solutions." << std::endl;
}