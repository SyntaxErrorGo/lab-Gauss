#ifndef FOLDERS_H
#define FOLDERS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>


using namespace std;

double determinant(vector<vector<double>> matrix);

vector<double> gauss(vector<vector<double>> matrix, bool ShowItterations);

vector<double> calculatingResidual(const vector<vector<double>>& matrix,
     const vector<double>& solution);

vector<double> MatrixOnWec(const vector<vector<double>>& matrix, vector<double>& vec);


#endif