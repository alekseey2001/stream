#include <iostream>
#include <fstream>

void readBinaryDataFromFile(const char* filename, char*& data, int& size) {
    std::ifstream inFile(filename, std::ios::binary); // Opening the file for reading in binary mode

    if (inFile.is_open()) {
        inFile.seekg(0, std::ios::end); // Go to the end of the file to find out the file size
        size = inFile.tellg(); // Getting the file size
        inFile.seekg(0, std::ios::beg); //Go back to the beginning of the file

        data = new char[size]; // Allocating memory for data

        inFile.read(data, size); // Reading data from a file
        inFile.close(); 
        std::cout << "The data was successfully read from the file" << filename << " in binary form." << std::endl;
    }
    else {
        std::cerr << "The file could not be opened for reading" << std::endl;
    }
}

void writeBinaryDataToFile(const char* filename, const char* data, int size) {
    std::ofstream outFile(filename, std::ios::binary); 

    if (outFile.is_open()) {
        outFile.write(data, size); 
        outFile.close(); 
        std::cout << "The data has been successfully written to the file " << filename << "in binary form." << std::endl;
    }
    else {
        std::cerr << "The file could not be opened for writing." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";
    char* data = nullptr;
    int size = 0;

    readBinaryDataFromFile(inputFilename, data, size); // Reading data from a file
    writeBinaryDataToFile(outputFilename, data, size); // Writing the data to another file

    delete[] data; 

    return 0;
}
