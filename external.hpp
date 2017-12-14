//
// Created by mxhdrm on 14.12.17.
//

#ifndef CONSOLE_EXTERNAL_HPP
#define CONSOLE_EXTERNAL_HPP

#endif //CONSOLE_EXTERNAL_HPP

#include <string>
#include <iostream>

//System Specifications
void setTitle(std::string titleMsg)
{
#ifdef WIN32
    string title = "title ";
	title += titleMsg.c_str();
	system(title.c_str());
#else
    char esc_start[] = { 0x1b, ']', '0', ';', 0 };
    char esc_end[]   = { 0x07, 0 };
    std::cout << esc_start << titleMsg << esc_end;
#endif
