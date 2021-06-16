// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <wtypes.h>

extern "C" {
  __declspec(dllexport) BSTR Densecap_ProcessFile(BSTR key, BSTR filename);
  __declspec(dllexport) BSTR Densecap_ProcessUrl(BSTR key, BSTR url);
}

#pragma comment(lib, "../Release/DeepAIClrWrapper.lib")


int main()
{
    std::wstring key, filename, url;
    std::cout << "Enter key or press Enter for default: ";
    std::getline(std::wcin, key);
    if (key.empty()) key = L"quickstart-QUdJIGlzIGNvbWluZy4uLi4K";
    std::wcout << "Entered " << key << "\n";
    BSTR bkey = SysAllocString(key.c_str());

    std::cout << "Enter filename or press Enter to skip: ";
    std::getline(std::wcin, filename);
    if (filename.empty()) {
      std::cout << "Empty filename - skipped\n";
    }
    else {
      std::wcout << "Entered " << filename << "\n";
      BSTR bfilename = SysAllocString(filename.c_str());
      BSTR bresultfile = Densecap_ProcessFile(bkey, bfilename);

      std::wstring resultfile(bresultfile, SysStringLen(bresultfile));
      std::wcout << resultfile << "\n";
      SysFreeString(bfilename);
      SysFreeString(bresultfile);
    }

    std::cout << "Enter URL or press Enter to skip: ";
    std::getline(std::wcin, url);
    if (url.empty()) {
      std::cout << "Empty URL - skipped\n";
    }
    else {
      std::wcout << "Entered " << url << "\n";
      BSTR burl = SysAllocString(url.c_str());
      BSTR bresulturl = Densecap_ProcessUrl(bkey, burl);

      std::wstring resulturl(bresulturl, SysStringLen(bresulturl));
      std::wcout << resulturl << "\n";
      SysFreeString(burl);
      SysFreeString(bresulturl);
    }

    SysFreeString(bkey);
    std::cout << "Press Enter to exit\n";
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
