#include "ip_address.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& str, char d)
{
	vector<string> r;

	string::size_type start = 0;
	string::size_type stop = str.find_first_of(d);
	while (stop != string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

int main()
{
	vector<ip_address> ip_pool;

	try
	{
		for (string line; std::getline(cin, line);)
		{
			vector<string> v = split(line, '\t');
			ip_pool.push_back(ParseIp(v.at(0)));
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}

	sort(ip_pool.begin(), ip_pool.end(), [](const ip_address& ip1, const ip_address& ip2) { return ip1 > ip2; });

	for (const auto& a : ip_pool)
	{
		cout << a << endl;
	}
	
	for (const auto& a : ip_pool)
	{
		if (a.n1 == 1)
		{ 
			cout << a << endl;
		}
		else if (a.n1 == 0)
		{
			break;
		}
	}

	for (const auto& a : ip_pool)
	{
		if (a.n1 == 46)// && a.n2 == 70)
		{
			if (a.n2 == 70)
			{
			cout << a << endl;
			}
			else if (a.n2 < 70)
			{
				break;
			}
		}
		else if (a.n1 < 46)
		{
			break;
		}
	}

	for (const auto& a : ip_pool)
	{
		if (a.n1 == 46 || a.n2 == 46 || a.n3 == 46 || a.n4 == 46)
		{
			cout << a << endl;
		}
	}

	return 0;
}

