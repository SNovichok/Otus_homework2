#pragma once

#include <iostream>
#include <string>

struct ip_address
{
	unsigned int n1, n2, n3, n4;
};

bool operator<(const ip_address& lhs, const ip_address& rhs);

bool operator>(const ip_address& lhs, const ip_address& rhs);

std::ostream& operator<<(std::ostream& os, const ip_address& ip);

ip_address ParseIp(const std::string& str);