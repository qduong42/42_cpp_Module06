#include "Serial.hpp"
#include <stdint.h>
#include <iostream>

/*reinterpret_cast keyword is used to simply cast one type bitwise to another.
unsafe when casting from 1 data type to another not large enough to hold it */

/**
 * @brief takes pointer and convert to unsigned int type uintptr_t
 * 
 * @param ptr 
 * @return uintptr_t 
 */
uintptr_t serialize(t_serial* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief takes unsinged int param and convert to pointer to Data
 * 
 * @param raw 
 * @return t_serial* 
 */
t_serial *deserialize(uintptr_t raw)
{
    return (reinterpret_cast<t_serial*>(raw));
}

int main()
{
	t_serial s;
    uintptr_t a;
    a = serialize(&s);

	s.example = 42;
    std::cout << "t_serial ptr:" << &s << std::endl;
    std::cout << "uintptr_t ptr" << &a << std::endl;
    std::cout << "serialized: " << a << std::endl;
    std::cout << "deserialized: " << deserialize(a) << std::endl;
	std::cout << "Serialized & Deserialized: " << deserialize(serialize(&s))->example << std::endl;
	return (0);
}
