//Class Includes
#include "Application.hpp"
#include "external.hpp"

//Lib-Includes
#include <memory>
#include <vector>
#include <chrono>
#include <algorithm>


ext::OS os = ext::getOS();

int main(int argc, char* argv[])
{
    //Unique Application
    auto app = std::make_unique<Application>();
    const std::string filePath = argv[0];

    //Testzone
    app->menu(filePath);

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
        app->menu(filePath);
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
        std::cerr << "Command Not Found. Retry!" << std::endl;
        return EXIT_FAILURE;
    }
}