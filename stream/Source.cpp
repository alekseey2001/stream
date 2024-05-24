#include <iostream>
#include <fstream>

void readBinaryDataFromFile(const char* filename, char*& data, int& size) {
    std::ifstream inFile(filename, std::ios::binary); // ��������� ���� ��� ������ � �������� ������

    if (inFile.is_open()) {
        inFile.seekg(0, std::ios::end); // ��������� � ����� �����, ����� ������ ������ �����
        size = inFile.tellg(); // �������� ������ �����
        inFile.seekg(0, std::ios::beg); // ��������� ������� � ������ �����

        data = new char[size]; // �������� ������ ��� ������

        inFile.read(data, size); // ������ ������ �� �����
        inFile.close(); // ��������� ����
        std::cout << "������ ������� ������� �� ����� " << filename << " � �������� ����." << std::endl;
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

void writeBinaryDataToFile(const char* filename, const char* data, int size) {
    std::ofstream outFile(filename, std::ios::binary); // ��������� ���� ��� ������ � �������� ������

    if (outFile.is_open()) {
        outFile.write(data, size); // ���������� ������ � ����
        outFile.close(); // ��������� ����
        std::cout << "������ ������� �������� � ���� " << filename << " � �������� ����." << std::endl;
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";
    char* data = nullptr;
    int size = 0;

    readBinaryDataFromFile(inputFilename, data, size); // ������ ������ �� �����
    writeBinaryDataToFile(outputFilename, data, size); // ���������� ������ � ������ ����

    delete[] data; // ����������� ������

    return 0;
}
