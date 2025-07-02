#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>

#define NAME "Xadia\n"

int main()
{
	//float deg = whermst::radToDeg(whermst::pi);
	whermst::math::min(5, 3);
	std::cout << NAME;
	std::cout << "Hello, World!\n";
	std::cout << whermst::math::pi << std::endl;
	//std::cout << deg << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << whermst::random::getRandomFloat() << std::endl;
	}

}
