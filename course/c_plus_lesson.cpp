#include <iostream>
#include <cstdlib>
#include <memory.h>

namespace mn
{

class biteset
{
private:
	using T = unsigned;
	enum { SIZET = 32 };
	T* data;
	size_t N;
public:
	biteset(size_t N_): N(N_)
	{
		data = (T*)calloc((N + SIZET - 1) / SIZET , sizeof(T));
	}
	~biteset()
	{
		free(data);
	}
	bool insert(size_t k)
	{
		if (k >= N)
			return false;
		data[k / SIZET] |= (T)1 << k % SIZET;
		return true;
	}

	bool erase(size_t k)
	{
		if (k >= N)
			return false;
		data[k / SIZET] &= ~((T)1 << k % SIZET);
		return true;
	}

	bool in(size_t k)
	{
		if (k >= N)
			return false;
		return (data[k / SIZET] >> k % SIZET) & 1;
	}


};

}

int main()
{
	return 0;
}