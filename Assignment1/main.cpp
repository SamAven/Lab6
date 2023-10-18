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

int main(){
    std::ifstream file("matrix_input.txt"); //opens input file
    if (file.is_open()){ //checks if file was opened succesfully, This is also done so we know when we are accessing the file
        
        
        file.close(); //close the input file when finished
    }

    return 0;
}