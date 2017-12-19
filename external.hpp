//
// Created by mxhdrm on 14.12.17.
//

#ifndef CONSOLE_EXTERNAL_HPP
#define CONSOLE_EXTERNAL_HPP

#endif //CONSOLE_EXTERNAL_HPP

#include <string>
#include <iostream>

namespace ext
{

    enum class OS
    {
        WINDOWS = 1,
        LINUX,
        UNIX,
        MACOS,
    };


    /*
    void setTitle(std::string titleMsg, OS os)
    {
        switch(os)
        {
            case OS::WINDOWS:
                std::string title = titleMsg.c_str();
                system(title.c_str());
                break;

            case OS::LINUX:
                char esc_start[] = {0x1b, ']', '0', ';', 0};
                char esc_end[] = {0x07, 0};
                std::cout << esc_start << titleMsg << esc_end;
                break;


            case OS::MACOS:
                auto $title = titleMsg;
                system("echo -n -e "\033]0;$title\007"");
                break;


            default:
                break;
        }

    }
    */

    OS getOS()
    {
#ifdef _WIN32
        #include <Windows.h>
        return OS::WINDWOS;
#elif __APPLE__
        //#include "TargetConditionals.h"
#elif TARGET_OS_MAC
        //INCLUDES
           return OS::MACOS
#elif __linux__
        return OS::LINUX;
#elif __unix__
        return OS::UNIX;
    #else
    #   error "Unknown compiler"
#endif
    }


}



