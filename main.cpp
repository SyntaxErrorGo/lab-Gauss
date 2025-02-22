#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include "user.h"
#include "folders.h"

using namespace std;


int main(){
    while(true){
        cout << "Menu" << endl;
        cout << "1. New Matrix" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose option" << endl;

        int s;
        cin >> s;

        if(s == 2 ){
            break;
        }
        else if( s != 1){
            cout << "Invalid Choice. Repeat" << endl;
            continue;
        }

        int n;
        cout << "Enter size of Matrix" << endl;
        cin >> n;
        vector<vector<double>> matrix = inputMatrix(n);

        bool ShowItterations;
        cout << "Show Itterations?(1-Yes, 0-No)" << endl;
        int temp;
        cin >> temp;
        ShowItterations = (temp ==1);

        try{
            vector<double> solution = gauss(matrix, ShowItterations);
            cout << "Solution: ";
            for (double x : solution) {
                cout << x << " ";
            }
            cout << endl;

            vector<double> residual = calculatingResidual(matrix, solution);
            cout << "Residual:" << endl;
            for(double x : residual){
                cout << x << " ";
            }
            cout << endl;

        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}