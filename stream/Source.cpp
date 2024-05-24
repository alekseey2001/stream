#include <iostream>
#include <fstream>

void readBinaryDataFromFile(const char* filename, char*& data, int& size) {
    std::ifstream inFile(filename, std::ios::binary); // Открываем файл для чтения в бинарном режиме

    if (inFile.is_open()) {
        inFile.seekg(0, std::ios::end); // Переходим к концу файла, чтобы узнать размер файла
        size = inFile.tellg(); // Получаем размер файла
        inFile.seekg(0, std::ios::beg); // Переходим обратно в начало файла

        data = new char[size]; // Выделяем память для данных

        inFile.read(data, size); // Читаем данные из файла
        inFile.close(); // Закрываем файл
        std::cout << "Данные успешно считаны из файла " << filename << " в двоичном виде." << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }
}

void writeBinaryDataToFile(const char* filename, const char* data, int size) {
    std::ofstream outFile(filename, std::ios::binary); // Открываем файл для записи в двоичном режиме

    if (outFile.is_open()) {
        outFile.write(data, size); // Записываем данные в файл
        outFile.close(); // Закрываем файл
        std::cout << "Данные успешно записаны в файл " << filename << " в двоичном виде." << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";
    char* data = nullptr;
    int size = 0;

    readBinaryDataFromFile(inputFilename, data, size); // Читаем данные из файла
    writeBinaryDataToFile(outputFilename, data, size); // Записываем данные в другой файл

    delete[] data; // Освобождаем память

    return 0;
}
