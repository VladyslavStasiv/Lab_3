#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <Windows.h>

class Contact
{
    std::string name;
    std::string surname;
    std::string phoneNumber;
public:
    Contact(std::string name, std::string surname);
    Contact();

    void operator=(const std::string& number);
    bool operator ==(const Contact& other);
    std::string GetName();
    void SetName(std::string name);
    void SetSurname(std::string surname);
    std::string GetSurname();
    std::string GetPhoneNumber();
    void ShowInformation();
};