#include <iostream>
#include <cstdlib>
#include <vector>
#include <cfloat>
#include <cmath>

const float d = 1;

class page
{
public:
	float rank;
	int num_ref;
	page(float rank_ , int num): rank(rank_) , num_ref(num) {};
};

void PageRank(std::vector<std::vector<bool>>& network , std::vector<page>& pages , int num);
void AllRanks(std::vector<std::vector<bool>>& network , std::vector<page>& pages);
bool check_lim(std::vector<page>& now, std::vector<page>& bef);

int main()
{
	int N = 0;
	std::cin >> N;
	std::vector<std::vector<bool>> network;
	std::vector<page> pages;

	for (int i = 0 ; i < N ; ++i)
		pages.push_back(page{1.0f / N , 0});

	for (int i = 0 ; i < N ; ++i)
	{
		std::vector<bool> per;
		for (int j = 0 ; j < N ; ++j)
			per.push_back(std::rand() % 2);
		network.push_back(per);
	}

	for (int i = 0 ; i < N ; ++i)
	{
		for (int j = 0 ; j < N ; ++j)
			if(network[i][j] == 1)
				pages[i].num_ref++;
	}
			
	for (int i = 0 ; i < N ; ++i)
	{
		for (int j = 0 ; j < N ; ++j)
			std::cout << network[i][j] << " ";
		std::cout << std::endl;
	}

	AllRanks(network , pages);

	for (int i = 0 ; i < pages.size() ; ++i)
	{
		std::cout << pages[i].rank << " ";
	}
	std::cout << std::endl;

	return 0;
}

void PageRank(std::vector<std::vector<bool>>& network , std::vector<page>& pages , int num)
{
	float sum = 0;
	for (int i = 0 ; i < pages.size() ; ++i)
	{
		if (network[i][num] == 1)
			sum += (pages[i].rank / pages[i].num_ref);
	}

	pages[num].rank = (1 - d) + d * sum;
}

void AllRanks(std::vector<std::vector<bool>>& network , std::vector<page>& pages)
{
	std::vector<page> last_copy;
	for (int i = 0 ; i < pages.size() ; ++i)
	{
		last_copy.push_back(page(pages[i].rank , pages[i].num_ref));
	}

	while (true)
	{
		for (int i = 0 ; i < pages.size() ; ++i)
		{
			last_copy[i] = page(pages[i].rank , pages[i].num_ref);
		}

		for (int i = 0 ; i < pages.size() ; ++i)
		{
			PageRank(network , pages , i);
		}

		if (!check_lim(pages , last_copy))
			break;
	}
}

bool check_lim(std::vector<page>& now, std::vector<page>& bef)
{
	for (int i = 0 ; i < now.size() ; ++i)
	{
		if (std::abs(now[i].rank - bef[i].rank) > DBL_EPSILON)
		{
			return true;
		}
	}
	return false;
}

