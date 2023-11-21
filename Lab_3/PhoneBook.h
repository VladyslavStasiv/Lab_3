#pragma once
#include "Contact.h"
#include <vector>
#include <cctype> 


class PhoneBook
{
	std::vector<Contact> contacts;
	void AddContactFromConsole(const Contact& contact);
public:
	PhoneBook operator+(const Contact& other);
	std::string findPhoneNumber(const std::string& name, const std::string& surname);
	std::string findPhoneNumber(const std::string& surname);
	std::vector<Contact> AddContactFromConsole();
	void ShowInformation();
};