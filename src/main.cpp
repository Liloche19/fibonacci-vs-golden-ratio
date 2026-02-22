#include <iomanip>
#include <ios>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

int main(int argc, char** argv) {
    if (argc != 2)
        return 1;

    unsigned long nb = std::atoll(argv[1]);

    if (nb < 2) {
        std::cerr << "Error: Number must be greater than or equal to 2." << std::endl;
        return 1;
    }

    double goldenRatio = (1 + std::sqrt(5)) / 2;
    std::vector<unsigned long> fibonacci = std::vector<unsigned long>(nb + 1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    std::cout << "Computing Fibonacci numbers up to " << nb << "..." << std::endl;
    for (unsigned long i = 2; i <= nb; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    std::cout << "Fibonacci " << nb << ": " << fibonacci[nb] << std::endl;
    std::cout << "Computed golden ratio: " << std::setprecision(10) << fibonacci[nb] / static_cast<double>(fibonacci[nb - 1]) << " | Difference: " << std::fixed << std::setprecision(10) << (std::fabs(static_cast<double>(fibonacci[nb]) / fibonacci[nb - 1] - goldenRatio)) * 100.0 << "%" << std::endl;
    return 0;
}
