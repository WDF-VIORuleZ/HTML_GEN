//
// Created by mxhdrm on 13.12.17.
//

//Class Includes
#include "external.hpp"

//Lib-Includes
#include "Application.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <curses.h> //Only Linux
#include <unistd.h> //Only Linux


Application::Application()
{

}

Application::Application(std::string nHTML)
{
    if (!nHTML.empty())this->_HTML_src = nHTML;
}

Application::~Application()
{

}

//GETTER
const std::string Application::getHTML()const
{
    return this->_HTML_src;
}

//SETTER
void Application::setHTML(std::string nHTML)
{
    if (!nHTML.empty())this->_HTML_src = nHTML;
}

//METHODS
void Application::genFile(unsigned int num, std::string nPath)
{
    std::vector<std::string> src  = {std::string("<!DOCTYPE HTML>\n<html>\n<head>\n<title>Hier Kommt dein titel hin!</title>\n</head>\n<body>\n\nHier ensteht der Hauptteil deiner Website!\n\n</body>\n</html>"),
                                     std::string("<!DOCTYPE HTML>\n<html>\n<head>\n<title>Website</title>\n</head>\n<body>\n\n\n\n</body>\n</html>"),
                                     std::string("<!DOCTYPE HTML>\n<html>\n<body>\n\n\n\n</body>\n</html>")
                                    };

    std::string fileName = genFileName(num);
    std::cout << &src.at(num) << std::endl;

    std::ofstream output(nPath + fileName);
    if(output.is_open())
    {
        if(!output.fail())
        {
            output << &src.at(num);
            std::cout << "Successfully created file " << fileName << std::endl;
        }
        else
        {
            std::cerr << "An Error accursed while transmitting Data . . ." << std::endl;
        }
    }
    else
    {
        std::cerr << "Unable to create File " << fileName << std::endl;
    }
    output.close();
}

std::string Application::genFileName(unsigned int type)
{
    std::time_t res = std::time(nullptr);
    std::string str = std::asctime(std::localtime(&res));

    //Remove Whitespaces
    str.erase(std::remove (str.begin(), str.end(), ' '), str.end());
    //Remove Backspace
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    std::string filePath = "Beispiel[";
    filePath.append(std::to_string(type) + "]" + std::string(str) + ".html");

    return filePath;
}

void Application::usage()
{
    std::cout << "HTML-Generator [Options]" << std::endl << "Options: " << std::endl <<
         "-h       | --help\t\t\t Zeigt diese Hilfestellung" << std::endl <<
         "-m       | --menu\t\t\t Menu" << std::endl <<
         "-t [INT] | --type\t\t\t Benutze verscheidene Vorseinstellungen" << std::endl <<
         "\t[1]: Komplettes Geruest| minimale Vorschlaege| leichter Einstieg " << std::endl <<
         "\t[2]: Mittleres Geruest | keine Vorschlaege   | mittlerer Einstieg" << std::endl <<
         "\t[3]: Minimalgeruest    | keine Vorschlaege 	 | schwerer Einstieg " << std::endl;
}

void Application::menu(std::string nPath)
{
    system("clear");
    std::cout << std::string(" _     _____  _      _           _____ _____")                    << std::endl;
    std::cout << std::string("/ \\ /|/__ __\\/ \\__/|/ \\         /  __//  __// \\  /|")        << std::endl;
    std::cout << std::string("| |_||  / \\  | |\\/||| |   _____ | |  _|  \\  | |\\ ||")            << std::endl;
    std::cout << std::string("| | ||  | |  | |  ||| |_/\\\\____\\| |_//|  /_ | | \\||")         << std::endl;
    std::cout << std::string("\\_/ \\|  \\_/  \\_/  \\|\\____/      \\____\\\\____\\\\_/  \\|") << std::endl;

    std::string barrier = "####################################################" ;

    int _key;

    //TODO OS DETECTION
    std::cout << '\n' << barrier << std::endl;
    std::cout << "             |### HTML-GEN v.1 Menu ##|" << std::endl;
    std::cout << barrier << std::endl;
    std::cout << "Enter The Number Of Your Preferred File-Type :> ";
    std:: cin >> _key;

    //Process Input
    if(!std::cin.fail() && (_key > 0 && _key < 4) || _key == -1)
    {
        genFile(_key, nPath);
    }
    else if(_key == 99)
    {
        std::cout << "Program Stopped" << std::endl;
        sleep(2);
        exit(1);
    }
    else
    {
        std::cerr << "Error Getting Input. Retry" << std::endl;
        sleep(3.5);
        _key = -1;
        menu(nPath);

    }
}