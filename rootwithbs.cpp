#include <iostream>
using namespace std;

double squareRoot(int x) {
    if (x == 0 || x == 1) // Base case for 0 and 1
        return x;

    double low = 0, high = x;
    double epsilon = 0.000001; // Precision

    while (high - low > epsilon) {
        double mid = low + (high - low) / 2;
        double square = mid * mid;

        if (square == x)
            return mid;
        else if (square < x)
            low = mid;
        else
            high = mid;
    }

    // If no exact square root is found, return the floor value of high
    return high;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Square root of negative numbers is undefined." << endl;
    } else {
        double result = squareRoot(num);
        cout << "Square root of " << num << " is approximately " << result << endl;
    }

    return 0;
}
