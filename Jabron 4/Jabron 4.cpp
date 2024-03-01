#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
    string word;
    int choice;

    setlocale(LC_ALL, "Russian");

    cout << "Введите слово: ";
    cin >> word;

    cout << "Выберите действие:" << endl;
    cout << "1. Перевернуть слово задом наперед" << endl;
    cout << "2. Удалить гласные буквы из слова" << endl;
    cout << "3. Удалить согласные буквы из слова" << endl;
    cout << "4. Перемешать буквы в слове" << endl;
    cout << "Введите свой выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        reverse(word.begin(), word.end());
        cout << "Перевернутое слово: " << word << endl;
        break;
    case 2:
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я'; }), word.end());
        cout << "Слово без гласных: " << word << endl;
        break;
    case 3:
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return c != 'а' && c != 'е' && c != 'ё' && c != 'и' && c != 'о' && c != 'у' && c != 'ы' && c != 'э' && c != 'ю' && c != 'я'; }), word.end());
        cout << "Слово без согласных: " << word << endl;
        break;
    case 4:
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        random_shuffle(word.begin(), word.end());
        cout << "Перемешанное слово: " << word << endl;
        break;
    default:
        cout << "Неверный выбор" << endl;
    }

    return 0;
}