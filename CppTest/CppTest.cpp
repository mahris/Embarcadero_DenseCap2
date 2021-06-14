// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <wtypes.h>

extern "C" {
  __declspec(dllexport) BSTR Densecap_ProcessFile(BSTR key, BSTR filename);
}

#pragma comment(lib, "../Release/DeepAIClrWrapper.lib")


int main()
{
  OutputDebugString(L"qqq");
    std::cout << "Hello World!\n"; 
    std::wstring key, filename;
    std::cout << "Enter key or press Enter for default: ";
    std::getline(std::wcin, key);
    if (key.empty()) key = L"quickstart-QUdJIGlzIGNvbWluZy4uLi4K";
    std::wcout << "Entered " << key << "\n";
    std::cout << "Enter filename: ";
    std::getline(std::wcin, filename);
    if (filename.empty()) filename = L"elephant.jpg";
    std::wcout << "Entered " << filename << ";\n";
    BSTR bkey = SysAllocString(key.c_str());
    BSTR bfilename = SysAllocString(filename.c_str());
    BSTR bresult = Densecap_ProcessFile(bkey, bfilename);

    std::wstring result(bresult, SysStringLen(bresult));
    std::wcout << "Ented " << result << "\n";
    SysFreeString(bkey);
    SysFreeString(bfilename);
    getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
