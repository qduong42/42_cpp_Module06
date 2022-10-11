#include <cstdlib>
#include <string>
#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return 0;
	}
	try{
	Convert c(argv[1]);
	std::cout << c;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}

//promotion cast => smaller data type to bigger. other way loses accuracy.
