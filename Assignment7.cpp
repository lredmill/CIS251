//This program is a creates two dimensional array initilized with test data
   //
   // Taken from Starting Out With C++ from Control Structures through Objects (Ninth Edition) by Tony Gaddis (2018)
   //
   // Programmed by Langley Redmill, CIS251 student
   // July 7, 2024
#include <iostream>
#include <fstream>

const int ROWS = 2;
const int COLS = 5;

int getTotal(int arr[ROWS][COLS]) {
    int total = 0;
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            total += arr[r][c];
        }
    }
    return total;
}
float getAverage(int arr[ROWS][COLS]) {
    float total = getTotal(arr);
    return total / (ROWS * COLS);
}
int getRowTotal(int arr[ROWS][COLS], int row) {
    int total = 0;
    for(int c = 0; c < COLS; c++) {
        total += arr[row][c];
    }
    return total;
}

int getColumnTotal(int arr[ROWS][COLS], int col) {
    int total = 0;
    for(int r = 0; r < ROWS; r++) {
        total += arr[r][col];
    }
    return total;
}

int getHighestInRow(int arr[ROWS][COLS], int row) {
    int highest = arr[row][0];
    for(int c = 1; c < COLS; c++) {
        if(arr[row][c] > highest) {
            highest = arr[row][c];
        }
    }
    return highest;
}
int getLowestInRow(int arr[ROWS][COLS], int row) {
    int lowest = arr[row][0];
    for(int c = 1; c < COLS; c++) {
        if(arr[row][c] < lowest) {
            lowest = arr[row][c];
        }
    }
    return lowest;
}

int main()
{
    int data_array[ROWS][COLS] = {{5,10,8,7,3},{4,9,6,2,1}};
   
    double total;
    double row_total;
    double Average;
    double Column_Total;
    double Highest_In_Row;
    double Lowest_In_Row;
    
    total = getTotal(data_array);
    row_total = getRowTotal(data_array, 2);
    Average = getAverage(data_array);
     Column_Total = getColumnTotal(data_array,2);
    Highest_In_Row = getHighestInRow(data_array,2);
    Lowest_In_Row = getLowestInRow(data_array,2);

    int arr[ROWS][COLS];
    
    std::ifstream inputFile("Program7.txt");
    if(inputFile.is_open()) {
        for(int r= 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                inputFile >> arr[r][c];
            }
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file!" << std::endl;
        return 1;
    }
    
    std::cout << "Total: " << getTotal(arr) << std::endl;
    std::cout << "Average: " << getAverage(arr) << std::endl;
    std::cout << "Row Total (Row 0): " << getRowTotal(arr, 0) << std::endl;
    std::cout << "Row Total (Row 1): " << getRowTotal(arr, 1) << std::endl;
    std::cout << "Column Total (Column 0): " << getColumnTotal(arr, 0) << std::endl;
    std::cout << "Column Total (Column 1): " << getColumnTotal(arr, 1) << std::endl;
    std::cout << "Highest in Row 0: " << getHighestInRow(arr, 0) << std::endl;
    std::cout << "Lowest in Row 0: " << getLowestInRow(arr, 0) << std::endl;
    
    return 0;

}