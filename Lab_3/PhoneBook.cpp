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
                std::cout << "Номер телефону абонента " << name << " " << surname << ": " << contact.GetPhoneNumber() << std::endl;
                found = true;
                return contact.GetPhoneNumber();
                break;
            }
        }

        if (!found) 
        {
            std::cout << "Контакт з ім'ям " << name << " та прізвищем " << surname << " не знайдений в телефонній книзі." << std::endl;
            return "";
        }
    }
    catch (const std::exception& exp) 
    {
        std::cerr << "Помилка при пошуку номера телефону: " << exp.what() << std::endl;
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
                std::cout << "Номер телефону абонента " << contact.GetName() << " " << surname << ": " << contact.GetPhoneNumber() << std::endl;
                found = true;
                return contact.GetPhoneNumber();
                break;
            }
        }

        if (!found) 
        {
            std::cout << "Контакт з прізвищем " << surname << " не знайдений в телефонній книзі." << std::endl;
            return "";
        }
    }
    catch (const std::exception& exp) 
    {
        std::cerr << "Помилка при пошуку номера телефону: " << exp.what() << std::endl;
    }
}

std::vector<Contact> PhoneBook::AddContactFromConsole()
{
    std::string name, surname, phoneNumber;
    std::cout << "Введіть ім'я абонента, якого хочете додати у книгу: ";
    std::cin >> name;   
    std::cout << "Введіть прізвище абонента, якого хочете додати у книгу: ";
    std::cin >> surname;  
    std::cout << "Введіть номер телефону абонента, якого хочете додати у книгу: ";
    std::cin >> phoneNumber;
    Contact contacts1(name, surname);
    contacts1 = phoneNumber;
    *this = *this + contacts1;
    return std::vector<Contact>(contacts);
}