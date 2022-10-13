#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

Base* generate(void)
{
    int i;
    i = (std::rand() % 3); // 0, 1, 2
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    A* a = NULL;
    a = dynamic_cast<A*>(p);
    if (a)
    {
        std::cout << "A" << std::endl;
        return ;
    }
    B* b = NULL;
    b = dynamic_cast<B*>(p);
    if (b)
    {
        std::cout << "B" << std::endl;
        return ;
    }
    C* c = NULL;
    c = dynamic_cast<C*>(p);
    if (c)
    {
        std::cout << "C" << std::endl;
        return ;
    }
}

/*
    catch bad_cast or std::exception => both work on mac
    on linux: need <typeinfo>
    error: catching polymorphic type 'class std::bad_cast' by value
    => change to catch by ref
*/
void identify(Base& p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast const&){
    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(std::bad_cast const&){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(std::bad_cast const&){}
}

int main()
{
    srand(time(NULL));
    Base* base;
    Base* base2;
    base = generate();
    base2 = generate();
    identify(base);
    identify(*base2);
    delete base;
    delete base2;
}
