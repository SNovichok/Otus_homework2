#include "ip_address.h"

#include <cctype>
#include <exception>
#include <sstream>
#include <tuple>
#include <vector>

bool operator<(const ip_address& lhs, const ip_address& rhs)
{
	return std::tie(lhs.n1, lhs.n2, lhs.n3, lhs.n4) < std::tie(rhs.n1, rhs.n2, rhs.n3, rhs.n4);
}

bool operator>(const ip_address& lhs, const ip_address& rhs)
{
	return rhs < lhs;
}

std::ostream& operator<<(std::ostream& os, const ip_address& ip)
{
	os << ip.n1 << "." << ip.n2 << "." << ip.n3 << "." << ip.n4;
	return os;
}

ip_address ParseIp(const std::string& str)
{
	if (str == "")
	{
		throw std::invalid_argument("Incorrect address\n");
	}
	std::stringstream ss(str);
	char c;
	std::vector<unsigned int> Ns;
	size_t i = 0;

	ss >> c;
	while(c != EOF)
	{
		if (i > 4)
		{
			throw std::invalid_argument("Incorrect address\n");
		}
		if (c == '.')
		{
			Ns.push_back(0);
		}
		else if (!isdigit(c))
		{
			throw std::invalid_argument("Incorrect address\n");
		}
		else
		{
			std::string str_n;
			str_n += c;
			while (isdigit(ss.peek()))
			{
				ss >> c;
				str_n += c;
			}
			Ns.push_back(stoi(str_n));
			if (Ns.back() > 255)
			{
				throw std::invalid_argument("Incorrect address\n");
			}
		}
		if (ss.peek() == EOF)
		{
			break;
		}
		ss >> c;
		if (c == '.')
		{
			ss >> c;
		}
		else
		{
			throw std::invalid_argument("Incorrect address\n");
		}
		++i;
	}
	if (Ns.size() != 4)
	{
		std::cout << str << std::endl;
		throw("Incorrect address\n");
	}
	return { Ns[0], Ns[1], Ns[2], Ns[3] };
}