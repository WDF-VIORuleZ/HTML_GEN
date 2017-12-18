//
// Created by mxhdrm on 13.12.17.
//

#ifndef CONSOLE_APPLICATION_HPP
#define CONSOLE_APPLICATION_HPP

#include <string>

class Application
{
private:
    std::string _HTML_src;
    std::string genFileName(unsigned int type);

public:
    //CS
    Application();
    explicit Application(std::string nHTML);

    //DS
    virtual ~Application();

    //GETTER
    const std::string getHTML()const;

    //Setter
    void setHTML(std::string nHTML);
    void addCode(std::string nHTML); //Coming Soon

    //Methods
    void genFile(unsigned int num, std::string nPath); // <-- Bool für Main!
    void usage();
    void menu(std::string path);
};


#endif //CONSOLE_APPLICATION_HPP
