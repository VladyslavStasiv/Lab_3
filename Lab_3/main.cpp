#include "PhoneBook.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\t\t\t\t\t\tЛабораторна робота № 3" << endl;
    unsigned choice;
    bool stopWork = false;
    PhoneBook phoneBook1;
    while (stopWork == false)
    {
        cout << "1. Вихід" << endl;
        cout << "2. Переглянути телефонну книгу" << endl;
        cout << "3. Додати контакт до телефонної книги" << endl;
        cout << "4. Пошук номера телефону абонента" << endl;
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
        case 4: cout << "Як ви хочете шукати абонента?" << endl;
            cout << "1. За прізвищем" << endl;
            cout << "2. За прізвищем та ім'ям" << endl;
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
                cout << "Введіть прізвище: ";
                cin >> surname;
                phoneBook1.findPhoneNumber(surname);
            }
            else if (choice1 == 2)
            {
                string name, surname;
                cout << "Введіть ім'я: ";
                cin >> name;
                cout << "Введіть прізвище: ";
                cin >> surname;
                phoneBook1.findPhoneNumber(name, surname);
            }
            else cout << "Помилка при виборі пункту меню." << endl; break;
        default: cout << "Помилка при виборі пункту меню." << endl; break;
        }
    }
    return 0;
}