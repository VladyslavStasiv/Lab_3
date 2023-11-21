#include "Contact.h"

Contact::Contact(std::string name, std::string surname)
{
	this->name = name;
	this->surname = surname;
}

Contact::Contact()
{

}

void Contact::operator=(const std::string& number)
{
    try
    {
        if (number.empty() || std::any_of(number.begin(), number.end(), [](unsigned char c) { return !std::isdigit(c); }))
        {
            throw std::invalid_argument("����� �������� �� ���� ��������� �������� ������.");
        }
        phoneNumber = number;
    }
    catch (const std::invalid_argument& exp)
    {
        std::cerr << "������� ��� ����������� ������ ��������: " << exp.what() << std::endl;
    }
}

bool Contact::operator==(const Contact& other)
{
    return this->phoneNumber == other.phoneNumber;
}

std::string Contact::GetName()
{
    return std::string(name);
}

void Contact::SetName(std::string name)
{
    this->name = name;
}

void Contact::SetSurname(std::string surname)
{
    this->surname = surname;
}

std::string Contact::GetSurname()
{
    return std::string(surname);
}

std::string Contact::GetPhoneNumber()
{
    return std::string(phoneNumber);
}

void Contact::ShowInformation()
{
    std::cout << "��'�: " << name << std::endl;
    std::cout << "�������: " << surname << std::endl;
    std::cout << "����� ��������: " << phoneNumber << std::endl;
}