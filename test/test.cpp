#include "ip_address.h"

#include <gtest/gtest.h>

#include <iostream>


TEST(IP_ADDRESS, SORT) 
{
	ip_address ip1{0, 49, 124, 0};
	ip_address ip2{85, 54, 0, 7};

	EXPECT_TRUE(ip1 < ip2);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}