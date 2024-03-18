#include "rbtree.hxx"
#include <iostream>
#include <exception>

int main()
{
    try
    {
        RBTree rbt;
        for(int i = 1; i < 10; i++)
        {
            rbt.Insert(i);
            rbt.Display();
            std::cout << std::endl;
        }
        rbt.Delete(4);
        rbt.Delete(7);
        rbt.Display();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
