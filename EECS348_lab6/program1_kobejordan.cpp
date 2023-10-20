#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

// Function prototypes
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* fileName);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    
    // Read matrix data from file
    readMatrixFromFile(matrixA, matrixB, size, "/Users/kobejordan/Desktop/EECS 348/Lab 5/EECS348_lab6/matrix_input.txt");

    // Print the matrices
    std::cout << "Kobe Jordan" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;
    
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    // Add matrices and print the result
    addMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(resultMatrix, size);

    // Multiply matrices and print the result
    multiplyMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(resultMatrix, size);

    // Subtract matrices and print the result
    subtractMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(resultMatrix, size);

    return 0;
}

// Function to read matrix data from a file
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrixA[i][j];
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrixB[i][j];
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        exit(1);
    }
}

// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
