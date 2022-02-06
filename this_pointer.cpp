#include <iostream>
#include <string>

class	Bar
{
public:
	Bar(int value)
	: nbr(value)
	{
		std::cout << "contructor called" << std::endl;
	}
	~Bar()
	{
		std::cout << "destructor called" << std::endl;
	}

	void	modify_this(Bar& other)
	{
		Bar*	tmp;

		tmp = this;
//		tmp = &other;

		std::cout << tmp->nbr << std::endl;
	}

private:
	int	nbr;
};

int main()
{
	Bar	a(1);
	Bar	b(5);

	a.modify_this(b);
	return 0;
}
