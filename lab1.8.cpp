#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    /* Вычислить приближённое значение функции, используя представление ее в виде ряда Тейлора.
     * Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа , где 0 <  < 10-k, k – натуральное число, k > 1.
     * Сравнить полученный результат со значением, вычисленным  с помощью стандартных функций.
     * Значение  x и k ввести по запросу.
     * Результат вывести с заданным количеством цифр после запятой.
       minifoo = n-ый член ряда Тейлора
      function = сумма n членов ряда Тейлора
     k = точность вычисления) {
*/

    // (1+x)^(0.5)
    double x;
    double minifoo;
    int k, n;
    cout << "Enter x" << endl;
    cin >> x;
    if(x>1||x<-1) {
        cout<<"ERROR"<<endl;
        return 0;
    }

    cout << "Enter the calculation accuracy - k" << endl;
    cin >> k;
    double function=1;
    minifoo=1;
    for (n = 1; fabs(minifoo) > (pow(10, -k)); n++) {
        minifoo*= (double) x*n*(2*n-1) /(2*n*n);
        if(n%2==0) {
            function += (double)minifoo/(1-2*n);
        }
        else {
            function -= (double)minifoo/(1-2*n);
        }
    }
    cout<<"Result:\n";
    cout << fixed << setprecision(k) << function << endl
         << "The result calculated by the standard function:"<<endl<<
         pow(1+x, 0.5)<<endl<<"Calculation error:"<<endl<<"\u0394 = "<<
         fabs(function - pow(1+x, 0.5))<<endl;
    return 0;
}