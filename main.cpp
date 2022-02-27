#include <iostream>
using namespace std;
#include <vector>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

vector<double> collatzConjecture(int number) {
    vector<double> results = {};
    while(number != 1) {
        if(number % 2 == 0) {
            number /= 2;
        } else {
            number = (number * 3) + 1;
        }
    // cout << number << "\n";
    results.insert(results.end(), number);
    }

    return results;
}

int main() {
    int max = 0;
    int currentIteration = 1;
    cout << "Max number" << endl;
    cin >> max;
    cout << "Generating!" << endl;

    while(currentIteration < max) {
        vector<double> x = {};
        vector<double> y = collatzConjecture(currentIteration);

        int temp = 0;
        for(auto i: y) {
            x.insert(x.end(), temp);
            temp++;
        }

        plt::plot(x, y, {{"color", "purple"}, {"marker", "."}});
        plt::xlabel("Iteration");
        plt::ylabel("Returned Number");
        plt::title("Collatz Conjecture " + to_string(currentIteration));
        plt::save("./figs/fig" + to_string(currentIteration) + ".png");
        plt::close();

        currentIteration++;
    }

    return 0;
}