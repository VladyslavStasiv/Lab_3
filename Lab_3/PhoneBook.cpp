#include "PhoneBook.h"

PhoneBook PhoneBook::operator+(const Contact& other)
{
    PhoneBook newBook = *this;
    newBook.AddContactFromConsole(other);
    return newBook;
}

void PhoneBook::AddContactFromConsole(const Contact& contact) 
{
    contacts.push_back(contact);
}

void PhoneBook::ShowInformation()
{
    for (auto& temp : contacts)
    {
        temp.Contact::ShowInformation();
        std::cout << std::endl;
    }
}

std::string PhoneBook::findPhoneNumber(const std::string& name, const std::string& surname)
{
    try 
    {
        bool found = false;
        for (Contact& contact : contacts) 
        {
            if (contact.GetName() == name && contact.GetSurname() == surname) 
            {
                std::cout << "����� �������� �������� " << name << " " << surname << ": " << contact.GetPhoneNumber() << std::endl;
                found = true;
                return contact.GetPhoneNumber();
                break;
            }
        }

        if (!found) 
        {
            std::cout << "������� � ��'�� " << name << " �� �������� " << surname << " �� ��������� � ��������� ����." << std::endl;
            return "";
        }
    }
    catch (const std::exception& exp) 
    {
        std::cerr << "������� ��� ������ ������ ��������: " << exp.what() << std::endl;
    }
}

std::string PhoneBook::findPhoneNumber(const std::string& surname)
{
    try 
    {
        bool found = false;
        for (Contact& contact : contacts) 
        {
            if (contact.GetSurname() == surname) 
            {
                std::cout << "����� �������� �������� " << contact.GetName() << " " << surname << ": " << contact.GetPhoneNumber() << std::endl;
                found = true;
                return contact.GetPhoneNumber();
                break;
            }
        }

        if (!found) 
        {
            std::cout << "������� � �������� " << surname << " �� ��������� � ��������� ����." << std::endl;
            return "";
        }
    }
    catch (const std::exception& exp) 
    {
        std::cerr << "������� ��� ������ ������ ��������: " << exp.what() << std::endl;
    }
}

std::vector<Contact> PhoneBook::AddContactFromConsole()
{
    std::string name, surname, phoneNumber;
    std::cout << "������ ��'� ��������, ����� ������ ������ � �����: ";
    std::cin >> name;   
    std::cout << "������ ������� ��������, ����� ������ ������ � �����: ";
    std::cin >> surname;  
    std::cout << "������ ����� �������� ��������, ����� ������ ������ � �����: ";
    std::cin >> phoneNumber;
    Contact contacts1(name, surname);
    contacts1 = phoneNumber;
    *this = *this + contacts1;
    return std::vector<Contact>(contacts);
}