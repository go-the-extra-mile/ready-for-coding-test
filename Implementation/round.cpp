#include <iostream>
#include <cmath>
using namespace std;
#include <limits>
#include <iomanip>


int main(){
    // double r = round(-0.1);
    // double num = -0.14999;
    // 둘째자리에서 반올림
    // double rr = (double)((int)round(num*10)) / 10;
    // // cout << r << '\n';
    // cout << rr << '\n';

    
    // auto my_round = [](double num, int round_at) -> double { 
    //     int multiple = pow(10, round_at-1);
    //     return (double)((int)round(num*multiple)) / multiple; 
    // };
    // cout << my_round(1.2345, 2) << '\n'; // 1.2
    // cout << my_round(1.456, 2) << '\n'; // 1.5
    // cout << my_round(5.789, 2) << '\n'; // 5.8
    // cout << my_round(-0.012, 2) << '\n'; // 0
    // cout << my_round(-0.123, 2) << '\n'; // -0.1
    // cout << my_round(-0.567, 2) << '\n'; // -0.6
    // cout << my_round(-3.456, 2) << '\n'; // -3.5

    // cout << "===========" << '\n';

    // cout << my_round(1.2345, 3) << '\n'; // 1.23
    // cout << my_round(1.456, 3) << '\n'; // 1.46
    // cout << my_round(5.789, 3) << '\n'; // 5.79
    // cout << my_round(-0.002, 3) << '\n'; // 0
    // cout << my_round(-0.123, 3) << '\n'; // -0.12
    // cout << my_round(-0.567, 3) << '\n'; // -0.57
    // cout << my_round(-3.456, 3) << '\n'; // -3.46
    
    double f = 3.141592;
//           12345

    streamsize ss = cout.precision();
    cout << f << '\n'; // 3.14159
    cout << setprecision(5) << f << '\n'; // output : 3.1416
    cout << fixed << setprecision(3) << f << '\n'; // output : 3.142

    // reset fixed
    // cout << defaultfloat << setprecision(ss);
    cout << defaultfloat << setprecision(ss);
    cout << f << '\n'; // 3.14159



    // cout << numeric_limits<double>::max() << '\n';
    // cout << numeric_limits<long long>::max() << '\n';

    // for(int i=0; i<53; i++)
    //     cout << '1';
    
}