//
// Created by mxhdrm on 13.12.17.
//

#include "Application.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <curses.h>

Application::Application()
{

}

Application::Application(std::string nHTML)
{
    if (nHTML != "")this->_HTML_src = nHTML;
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
    if (nHTML != "")this->_HTML_src = nHTML;
}

//METHODS
void Application::genFile(unsigned int num, std::string nPath)
{
    //Standard Codes
    std::vector<std::string> src = { "<!DOCTYPE HTML>\n<html>\n<head>\n<title>Hier Kommt dein titel hin!</title>\n</head>\n<body>\n\nHier ensteht der Hauptteil deiner Website!\n\n</body>\n</html>",
                                     "<!DOCTYPE HTML>\n<html>\n<head>\n<title>Website</title>\n</head>\n<body>\n\n\n\n</body>\n</html>",
                                     "<!DOCTYPE HTML>\n<html>\n<body>\n\n\n\n</body>\n</html>"
                                    };

    //Clock for unique Filename
    std::time_t res = std::time(nullptr);
    std::string str = std::asctime(std::localtime(&res));

    //Remove Whitespaces
    str.erase (std::remove (str.begin(), str.end(), ' '), str.end());

    const std::string fileName = std::string("Beispiel" + '[' + num + '|') + str + "].html";

    std::ofstream output(nPath + fileName);

    if(output.is_open())
    {
        if(!output.fail())
        {
            output << src.at(num);
            std::cout << "Successfully created file" << std::endl;
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

void Application::usage()
{
    std::cout << "HTML-Generator [Options]" << std::endl << "Options: " << std::endl <<
         "-h       | --help\t\t\t Zeigt diese Hilfestellung" << std::endl <<
         "-t [INT] | --type\t\t\t Benutze verscheidene Vorseinstellungen" << std::endl <<
         "\t[1]: Komplettes Geruest| minimale Vorschlaege| leichter Einstieg " << std::endl <<
         "\t[2]: Komplettes Geruest| keine Vorschlaege   | mittlerer Einstieg" << std::endl <<
         "\t[3]: Minimalgeruest    | keine Vorschlaege 	 | schwerer Einstieg " << std::endl;
}

void Application::menu()
{
    std::cout << std::string(" _     _____  _      _           _____ _____")                    << std::endl;
    std::cout << std::string("/ \\ /|/__ __\\/ \\__/|/ \\         /  __//  __// \\  /|")        << std::endl;
    std::cout << std::string("| |_||  / \\  | |\\/||| |   _____ | |  _|  \\  | |\\ ||")            << std::endl;
    std::cout << std::string("| | ||  | |  | |  ||| |_/\\\\____\\| |_//|  /_ | | \\||")         << std::endl;
    std::cout << std::string("\\_/ \\|  \\_/  \\_/  \\|\\____/      \\____\\\\____\\\\_/  \\|") << std::endl;

    int key;
    do
    {

    }
    while(key != 1);
}