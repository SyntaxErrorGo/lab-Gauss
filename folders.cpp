#include "user.h"
#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
#include "user.h"
#include "folders.h"

using namespace std;

vector<double> MatrixOnWec(const vector<vector<double>>& matrix, vector<double>& vec){
    int n = matrix.size();

    vector<double> result(n, 0.0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

vector<double> calculatingResidual(const vector<vector<double>>& matrix, const vector<double>& solution) {
    int n = matrix.size();
    vector<double> residual(n, 0.0);

    for (int i = 0; i < n; ++i) {
        residual[i] = matrix[i][n];
        for (int j = 0; j < n; ++j) {
            residual[i] -= matrix[i][j] * solution[j];
        }
    }

    return residual;
}

vector<double> gauss(vector<vector<double>> matrix, bool ShowItterations) {
    int n = matrix.size();

    if( n == 0 || matrix[0].size() != n + 1)
    {
        throw invalid_argument("Matrix is lost");
    }

    for(int i = 0; i < n; ++i) {
        int maxRow = i;
        for(int k = i+1; k < n; ++k){
            if(abs(matrix[k][i]) > abs(matrix[maxRow][i])){
                maxRow = k;
            }
        }

        if(maxRow != i){
            swap(matrix[i], matrix[maxRow]);
        }

        if(abs(matrix[i][i]) < 1e-10){
            throw runtime_error("Matrix is singular");
        }

        for(int k = i+1; k < n; ++k){
            double factor = matrix[k][i] / matrix[i][i];
            for(int j = i; j <= n; ++j){
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
        if(ShowItterations){
            cout << "Step" << i+1 << " " << endl;
            outputMatrix(matrix);
        }
    }


        vector<double> solution(n);
        for (int i = n - 1; i >= 0; --i) {
            solution[i] = matrix[i][n];
            for (int j = i + 1; j < n; ++j) {
                solution[i] -= matrix[i][j] * solution[j];
            }
            solution[i] /= matrix[i][i];
        }
        return solution;
    }




double determinant(vector<vector<double>> matrix){
    int n = matrix.size();

    if(n == 1){
        return matrix[0][0];
    }

    if(n == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;

    for(int col = 0; col < n; ++col){
        vector<vector<double>> submatrix(n, vector<double>(n-1));
        for(int i = 1; i < n; ++i){
            int subcol = 0;
            for(int j = 0; j < n; ++j){
                if( j == subcol) continue;
            submatrix[i-1][subcol] = matrix[i][j];
            subcol++;
        }
        }
    double subdet = determinant(submatrix);
    det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * subdet;
    }
    return det;
}


