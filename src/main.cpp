#include "Resources.h"
#include "DebugUtils.h"
#include"Board.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

#include <iostream>

int main() 
{
    try {

        Menu m1;
        m1.run();


       
    }
    catch (std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return EXIT_FAILURE;
    }

}
