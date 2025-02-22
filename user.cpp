#include "user.h"
#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;



void outputMatrix(const vector<vector<double>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> inputMatrix(int n){


    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and right-hand side):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}