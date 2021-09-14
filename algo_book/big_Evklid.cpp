#include <iostream>

int rem(int a , int b); // return a/b
int gcd(int a , int b);
int big_gcd(int a , int b , int& x , int& y);

int main()
{
	int a = 0 , b = 0 , x = 0 , y = 0;
	std::cin >> a >> b;
	int res = big_gcd(a , b , x , y);
	std::cout << x << " * " << a << " + " 
			  << y << " * " << b << " = " << res << std::endl;
	return 0;
}

int big_gcd(int a , int b , int& x , int& y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1 , y1;
	int res = big_gcd(rem(b , a) , a , x1 , y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return res;

}

int gcd(int a , int b)
{
	int m = a , n = b , r = rem(m , n);

	while (r > 0)
	{
		m = n;
		n = r;
		r = rem(m , n);
	}
	return n;
}

int rem(int a , int b)
{
	int q = 0 , r = a;

	while (b <= r)
	{
		r = r - b;
		q++;
	}

	return r;
}