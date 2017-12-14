//Class Includes
#include "Application.hpp"

//Lib-Includes
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <algorithm>


int main(int argc, char* argv[])
{
    //Unique Application
    auto app = std::make_unique<Application>();

    const std::string filePath = argv[0];

    app->usage();

    //Argument Parsing
    std::vector<std::string> argv_s ;
    for(unsigned int i =  0; i < argc - 1; i++)
    {
        std::string tmp(argv[i]);
        argv_s.push_back(tmp);
        std::cout << argv_s.at(i) << std::endl;
    }

    //Printing Vector
    for(unsigned int i = 0; i < argv_s.size(); i++)
    {
        std::cout << &argv_s.at(i) << std::endl;
    }

    //Argument Processing
    if(argv_s.at(0) == "-h" || argv_s.at(0) == "--help")
    {
        app->usage();
    }
    else if(argv_s.at(0) == "-m" || argv_s.at(0) == "--menu")
    {
        app->menu();
    }
    else if(argv_s.at(0) == "-t" || argv_s.at(0) == "--type")
    {
        if(argc > 2)
        {
            //Checks for Integer(LENGTH)
            if(argv_s.at(1).length() == 1)
            {
                //String ->
                int tmp = std::atoi(argv_s.at(1).c_str());

                switch(tmp)
                {
                    case 1:
                        app->genFile(1, filePath);
                        break;


                    case 2:
                        app->genFile(2, filePath);
                        break;

                    case 3:
                        app->genFile(3, filePath);
                        break;

                    default:
                        std::cerr << "Param \"" << tmp << "\" not defined" << std::endl;
                        break;
                }
            }
            else
            {
                std::cerr << "Second Parameter is not an Number" << std::endl;
                return EXIT_FAILURE;
            }
        }
        else
        {
            std::cerr << "There are too few Arguments. Retry!" << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {

    }

    return EXIT_SUCCESS;
}