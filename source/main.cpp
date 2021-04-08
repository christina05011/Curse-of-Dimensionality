#include <iostream>
#include <vector>
#include <random>
#include <cmath>
//#include <iomanip>
#include <chrono>
using namespace std;

vector<int> tams = { 10,15,20,25 };
vector<double> TAMS = { 10000,15000,20000,25000 };

int main() {
    for (int ii = 0; ii < 4; ii++) {    //TAMS
        for (int jj = 0; jj < 4; jj++) {   //tams
            vector<vector<double>> v(TAMS[ii]);
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dis(1, 2);

            for (double i = 0; i < TAMS[ii]; i++)
            {
                v[i] = vector<double>(tams[jj]);
                for (double j = 0; j < tams[jj]; j++)
                {
                    v[i].push_back(dis(gen));   /// v[i][j]=dis(gen);
                }
            }
            double x;
            chrono::time_point<chrono::high_resolution_clock> start, end;
            start = chrono::high_resolution_clock::now();
            /// 
            for (double i = 0; i < TAMS[ii]; i++) {
                for (double j = i + 1; j < TAMS[ii]; j++) {
                    x = 0;
                    for (double k = 0; k < tams[jj]; k++) {
                        x += pow(v[i][k] - v[j][k], 2);
                    }
                    x = sqrt(x);
                }
            }
            /// 
            end = chrono::high_resolution_clock::now();
            int64_t duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            cout << "Vector de size: " << TAMS[ii] << "-- con datos de size: " << tams[jj] << "-- duration: " << duration << endl;
            v.clear();
        }
    }

	return 0;
}
