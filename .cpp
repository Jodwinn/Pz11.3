#include <windows.h>;
#include <iostream>
using namespace std;


bool* initializeSeats(int seatCount) {
    bool* seat = new bool[seatCount];
    for (int i = 0; i < seatCount; i++) {
        seat[i] = false;
    }
    return seat;
}

bool bookOfseat(bool* seats, int seatNumber, int seatCount) {
    if (seatNumber < 1 || seatNumber > seatCount) {
        cout << "Неправильний номер місця." << endl;
        return false;
    }
    if (seats[seatNumber - 1]) {
        cout << "Місце вже зайняте" << endl;
        return false;
    }
    else {
        seats[seatNumber - 1] = true;
        return true;
    }
}

bool cancelSeat(bool* seats, int seatNumber, int seatCount) {
    if (seatNumber < 1 || seatNumber > seatCount) {
        cout << "Неправильний номер місця." << endl;
        return false;
    }
    if (!seats[seatNumber - 1]) {
        cout << "Місце вже вільне" << endl;
        return false;
    }
    else {
        seats[seatNumber - 1] = false;
        return true;
    }
}


string displayOfseat(const bool* seats, int seatCount) {
    string result = "Стан місць: ";
    for (int i = 0; i < seatCount; i++) {
        result += (seats[i] ? "[Зайняте]" : "[Вільне]");
        result += " ";
    }
    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int seatCount;
    cout << "Введіть кількість місць в автобусі: ";
    cin >> seatCount;


    bool* seat = initializeSeats(seatCount);

    int choice, seatnum;
    do {
        cout << "\nОберіть операцію:\n1. Бронювання місця\n2. Відміна бронювання\n3. Показати стан місць\n0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть номер місця для бронювання: ";
            cin >> seatnum;
            if (bookOfseat(seat, seatnum, seatCount)) {
                cout << "Місце " << seatnum << " успішно заброньовано." << endl;
            }
            break;

        case 2:
            cout << "Введіть номер місця для скасування бронювання: ";
            cin >> seatnum;
            if (cancelSeat(seat, seatnum, seatCount)) {
                cout << "Бронювання місця " << seatnum << " скасовано." << endl;
            }
            break;

        case 3:
            cout << displayOfseat(seat, seatCount) << endl;
            break;

        case 0:
            cout << "Вихід з програми." << endl;
            break;

        default:
            cout << "Некоректний вибір. Спробуйте знову." << endl;
            break;
        }
    } while (choice != 0);


    delete[] seat;

    return 0;
}
