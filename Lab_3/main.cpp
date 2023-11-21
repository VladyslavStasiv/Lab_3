#include "PhoneBook.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\t\t\t\t\t\t����������� ������ � 3" << endl;
    unsigned choice;
    bool stopWork = false;
    PhoneBook phoneBook1;
    while (stopWork == false)
    {
        cout << "1. �����" << endl;
        cout << "2. ����������� ��������� �����" << endl;
        cout << "3. ������ ������� �� ��������� �����" << endl;
        cout << "4. ����� ������ �������� ��������" << endl;
        cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        switch (choice)
        {
        case 1: stopWork = true; break;
        case 2: phoneBook1.ShowInformation(); break;
        case 3: phoneBook1.AddContactFromConsole(); break;
        case 4: cout << "�� �� ������ ������ ��������?" << endl;
            cout << "1. �� ��������" << endl;
            cout << "2. �� �������� �� ��'��" << endl;
            int choice1;
            cin >> choice1;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            if (choice1 == 1)
            {
                string surname;
                cout << "������ �������: ";
                cin >> surname;
                phoneBook1.findPhoneNumber(surname);
            }
            else if (choice1 == 2)
            {
                string name, surname;
                cout << "������ ��'�: ";
                cin >> name;
                cout << "������ �������: ";
                cin >> surname;
                phoneBook1.findPhoneNumber(name, surname);
            }
            else cout << "������� ��� ����� ������ ����." << endl; break;
        default: cout << "������� ��� ����� ������ ����." << endl; break;
        }
    }
    return 0;
}