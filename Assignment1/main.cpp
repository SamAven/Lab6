/*
EECS 348 Software Engineering 1
About: Modifying given matricies from file
Inputs: File with matricies
Outputs: manipulated matricies
Author: Sam Aven
Creation Date: 10/18/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Function to read and resize a matrix from a file
std:: vector<std:: vector<int>> readMatrix(std:: ifstream& file){
    int rows, cols;

    //read the size of the matrix
    if (!(file >> rows)){
        std:: cerr << "Failed to retrieve matrix size" << std::endl; //if size is unable to be determined print error message
        exit(1);
    }
    cols = rows; //Since the input file only contains one value to determine the dimensions we can assume they are the same

    //Create a vector of vectors with the specified size
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    //Read and populate the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> matrix[i][j])) {
                std::cerr << "Failed to read matrix data." << std::endl;
                exit(1);
            }
        }
    }

    return matrix;
}

int main(){
    std::ifstream file("matrix_input.txt"); //opens input file
    
    if (!file.is_open()){ //checks if we fail to open the input file
        std:: cerr << "Input file failed to open" << std:: endl;
        return 1;
    }

    //Read and store the first matrix
    std::vector<std::vector<int>> matrix1 = readMatrix(file);

    //Read and store the second matrix
    std::vector<std::vector<int>> matrix2 = readMatrix(file);

    //Close file
    file.close();

    // Printing the matrices
    std::cout << "Matrix 1:" << std::endl;
    for (const auto& row : matrix1) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }
    

    return 0;
}