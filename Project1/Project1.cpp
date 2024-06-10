#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
struct Delo
{
    string name;
    int priority;
    string description;
    string deadline;
};

vector<Delo> Dela;

void addDelo() {
    Delo newDelo;
    cout << " Введите название вашего дела: ";
    cin >> newDelo.name;
    cout << "Введите  приоретет вашего дела: ";
    cin >> newDelo.priority;
    cout << "Введите описание вашего дела : ";
    cin >> newDelo.description;
    cout << " Введите дату, до которой нужно выполнить дело:";
    cin >> newDelo.deadline;
    Dela.push_back(newDelo);
    cout << "Дело добавлено успешно!\n";
}

void deleteDelo() {
    string DeloName;
    cout << "Введите дело,которое хотите удалите: ";
    cin >> DeloName;
    auto it = find_if(Dela.begin(), Dela.end(), [DeloName](const Delo& Delo) {
        return Delo.name == DeloName;
        });
    if (it != Dela.end()) {
        Dela.erase(it);
        cout << "Дело удалено\n";
    }
    else {
        cout << "Дело не найдено...\n";
    }
}

void editDelo() {
    string DeloName;
    cout << "Введите дело, которое хотите редактировать: ";
    cin >> DeloName;
    auto it = find_if(Dela.begin(), Dela.end(), [DeloName](const Delo& Delo) {
        return Delo.name == DeloName;
        });
    if (it != Dela.end()) {
        Delo& Delo = *it;
        cout << "Введите новое дело,которое хотите редактировать: ";
        cin >> Delo.name;
        cout << "Введите новый приоретет: ";
        cin >> Delo.priority;
        cout << "Введите новое описание вашего дела: ";
        cin >> Delo.description;
        cout << "Введите новую дату, до которой нужно выполнить дело: ";
        cin >> Delo.deadline;
        cout << "Дело добавлено успешно!\n";
    }
    else {
        cout << "Дело не найдено...\n";
    }
}

void displayDela() {
    for (const Delo& Delo : Dela) {
        cout << "Название: " << Delo.name << "\n";
        cout << "Приоретет: " << Delo.priority << "\n";
        cout << "Описание: " << Delo.description << "\n";
        cout << "Дата: " << Delo.deadline << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "1. Добавить дело \n";
        cout << "2. Удалить дело\n";
        cout << "3. Редактировать дело \n";
        cout << "4. Вывести дело\n";
        cout << "5. Выход\n";
        cout << "Введите что выхотите сделать: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addDelo();
            break;
        case 2:
            deleteDelo();
            break;
        case 3:
            editDelo();
            break;
        case 4:
            displayDela();
            break;
        case 5:
            cout << "Выйти из программы...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

