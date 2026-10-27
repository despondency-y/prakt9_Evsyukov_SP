// prakt9_Evsyukov_SP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void increaseVolume(double* data, int size) {
    double k;
    cout << "Введите коэффициент увеличения: ";
    cin >> k;
    for (int i = 0; i < size; i++) {
        data[i] *= k;
    }
}

void decreaseVolume(double* data, int size) {
    double k;
    cout << "Введите коэффициент уменьшения: ";
    cin >> k;
    for (int i = 0; i < size; ++i) {
        data[i] *= k;
    }
}

void zeroSmallValues(double* data, int size) {
    double porog;
    cout << "Введите порог: ";
    cin >> porog;
    for (int i = 0; i < size; i++) {
        if (data[i] < porog) data[i] = 0.0;
    }
}

void limitAmplitude(double* data, int size) {
    double maxValue;
    cout << "Введите максимально допустимую амплитуду: ";
    cin >> maxValue;
    for (int i = 0; i < size; i++) {
        if (data[i] > maxValue) data[i] = maxValue;
    }
}


void applyProcessing(double* data, int size, void (*processor)(double*, int)) {
    if (processor != nullptr) processor(data, size);
}


void printMas(double* data, int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void fillRandom(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = ((rand() % 2001) - 1000) / 10.0;
    }
}

void copyMas(double* copy, double* orig, int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = orig[i];
    }
}






int main() {

    setlocale(LC_ALL, "Russian");

    srand(time(0)); 





    const int SIZE = 8;

    double data[SIZE];
    double original[SIZE];

    fillRandom(data, SIZE);
    copyMas(original, data, SIZE);

    void (*processors[])(double*, int) = {
        increaseVolume,
        decreaseVolume,
        zeroSmallValues,
        limitAmplitude
    };


    int choice = 0;
    do {
        cout << "\n\tМЕНЮ\n";
        cout << "1. Показать данные" << endl;
        cout << "2. Выбрать и выполнить обработку" << endl;
        cout << "3. Восстановить исходные данные" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printMas(data, SIZE);
            break;

        case 2: {
            cout << "1. Увеличить громкость" << endl;
            cout << "2. Уменьшить громкость" << endl;
            cout << "3. Обнулить слишком малые значения" << endl;
            cout << "4. Ограничить амплитуду" << endl;
            cout << "Выберите пункт: ";

            int op;
            cin >> op;

            if (op >= 1 && op <= 4) {
                void (*selected)(double*, int) = processors[op - 1];

                cout << "\nДо обработки:" << endl;
                printMas(data, SIZE);

                applyProcessing(data, SIZE, selected);

                cout << "После обработки:" << endl;
                printMas(data, SIZE);
            }
            else {
                cout << "----- Неверный номер обработки" << endl;
            }
            break;
        }

        case 3:
            copyMas(data, original, SIZE);
            cout << "----- Исходные данные восстановлены" << endl;
            printMas(data, SIZE);
            break;

        case 4:
            cout << "----- Выход из программы";
            break;

        default:
            cout << "----- Неверный пункт меню" << endl;
        }

    } while (choice != 4);

    return 0;
}

