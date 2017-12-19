//Class Includes
#include "Application.hpp"
//#include "external.hpp"
#include <iostream>

//Lib-Includes
#include <memory>
#include <vector>
#include <chrono>
#include <algorithm>

int main(int argc, char* argv[])
{
    //Unique Application
    auto app = std::make_unique<Application>();
    const std::string filePath = argv[0];


    //Argument Parsing
    std::vector<std::string> argv_s;
    for(int i = 0; i < argc; i++)
    {
        std::string tmp(argv[i]);
        argv_s.push_back(tmp);
        std::cout << i << argv_s.at(i) << std::endl;
    }

    //Argument Processing
    if(argv_s.size() > 0 && argc == 1) {
        app->usage();
        return EXIT_SUCCESS;
    }
    else if((argv_s.at(1) == "-h" || argv_s.at(1) == "--help" ))
    {
        app->usage();
        return EXIT_SUCCESS;
    }
    else if(argv_s.at(1) == "-m" || argv_s.at(1) == "--menu")
    {
        app->menu(filePath);
        return EXIT_SUCCESS;
    }
    else if(argv_s.at(1) == "-t" || argv_s.at(1) == "--type")
    {
        if(argc > 2)
        {
            //Checks for Integer(LENGTH)
            if(argv_s.at(2).length() == 1)
            {
                //String ->
                int tmp = std::atoi(argv_s.at(1).c_str());
                std::cout << tmp << std::endl;

                switch(tmp)
                {
                    case 1:
                        app->genFile(1, filePath);
                        return EXIT_SUCCESS;

                    case 2:
                        app->genFile(2, filePath);
                        return EXIT_SUCCESS;

                    case 3:
                        app->genFile(3, filePath);
                        return EXIT_SUCCESS;

                    default:
                        std::cerr << "Param \"" << tmp << "\" not defined" << std::endl;
                        return EXIT_SUCCESS;
                }
            }
            else
            {
                std::cerr << "Second Parameter is not a Number" << std::endl;
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
        std::cerr << "Command Not Found. Retry!" << std::endl;
        return EXIT_FAILURE;
    }
}

