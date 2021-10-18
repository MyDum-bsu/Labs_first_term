#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

int main() {
    const int MAX_N = 53;
    int n;
    cout << "Enter the number of array elements" << endl;
    cin >> n;
    if (n > MAX_N || n <= 0) {
        cout << "ERROR" << endl << "TRY AGAIN, PLEASE";
        return main();
    }
    double *mas = new double[n];
    cout << "Сhoose the method of filling the array:" << endl
         << "1. Random numbers -> Enter 1" << endl
         << "2. Using the keyboard -> Enter 2" << endl;
    int filling;
    cin >> filling;
    if (filling == 1) {

        cout << "Сhoose: real or integer numbers" << endl
             << "1. Real numbers -> Enter Real" << endl
             << "2. Integer numbers -> Enter Int" << endl;
        string c;
        cin >> c;
        cout << "Enter the boundaries of the range of values that the array elements accept:" << endl;
        mt19937 gen(time(NULL));
        if (c == "Real") {
            double k, l;
            cin >> k >> l;

            uniform_real_distribution<double> dist(k, l);
            cout << "Array elements:" << endl;
            for (int i = 0; i < n; ++i) {
                //*(mas + i) = (double)k + (double)(l-k)*rand()/RAND_MAX;//dist(gen);
                *(mas + i) = dist(gen);
                cout << (double) *(mas + i) << "\t";
            }
        } else if (c == "Int") {
            int k, l;
            cin >> k >> l;
            uniform_int_distribution<int> dist(k, l);
            cout << "Array elements:" << endl;
            for (int i = 0; i < n; ++i) {
                //*(mas + i) = (double)k + (double)(l-k)*rand()/RAND_MAX;//dist(gen);
                *(mas + i) = dist(gen);
                cout << (double) *(mas + i) << "\t";
            }


        }
        cout << endl;
    }
    if (filling == 2) {
        cout << "Enter the array elements:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> *(mas + i);
        }
        cout << endl;

    }


    double sum = 0;
    double mini = fabs(*mas), maxi = fabs(*mas);
    int flag_max, flag_min;
    for (int i = 0; i < n; ++i) {
        if (*(mas + i) > 0) {
            sum += *(mas + i);
        }
        maxi = max(maxi, fabs(*(mas + i)));
    }
    cout << "The sum of the positive elements of the array:" << endl;
    cout << sum << endl;

    for (int i = 0; i < n; ++i) {
        if (fabs(*(mas + i)) == maxi) {
            flag_max = i;
            break;
        }
    }
    for (int i = n - 1; i > 0; --i) {

        mini = min(mini, fabs(*(mas + i)));
    }
    for (int i = n - 1; i > 0; --i) {
        if (fabs(*(mas + i)) == mini) {
            flag_min = i;
            break;
        }
    }

    double composition = 1;
    if (flag_max < flag_min) {
        for (int i = flag_max + 1; i < flag_min; ++i) {
            composition *= *(mas + i);
        }
    } else {
        for (int i = flag_min + 1; i < flag_max; ++i) {
            composition *= *(mas + i);
        }
    }
    if (flag_max == flag_min + 1 || flag_min == flag_max + 1) {
        cout
                << "The first maximum and the last minimum modulo numbers are next to each other - the answer cannot be calculated"
                << endl;

    } else {
        cout
                << "The composition of the array elements that are between the first maximum and the last minimum modulo numbers:"
                << endl
                << composition << endl;
    }
    cout << "Array elements in odd positions, descending:" << endl;

    double t;
    for (int i = 1; i < n / 2; ++i) {
        for (int j = 1; j < n; j += 2) {
            if ((n % 2 == 0 && j + 2 >= n) || (n % 2 == 1 && j + 2 >= n - 1)) {

                break;
            } else if (*(mas + j) < *(mas + j + 2)) {

                t = *(mas + j);
                *(mas + j) = *(mas + j + 2);
                *(mas + j + 2) = t;

            }


        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {


            cout << *(mas + i) << "\t";
        }
    }
    delete[]mas;
    return 0;
}