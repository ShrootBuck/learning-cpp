#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <numeric>

// Function to calculate the Monte Carlo price of a European call option
double monteCarloCallPrice(double S0, double K, double T, double r, double sigma,
                           int numSimulations) {
    // Random number generator for standard normal distribution
    std::mt19937_64                  rng(std::random_device{}());
    std::normal_distribution<double> normDist(0.0, 1.0);

    std::vector<double> payoffs;
    payoffs.reserve(numSimulations);

    for (int i = 0; i < numSimulations; ++i) {
        double Z      = normDist(rng);
        double ST     = S0 * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * Z);
        double payoff = std::max(ST - K, 0.0);
        payoffs.push_back(payoff);
    }

    // Calculate average payoff
    double sumPayoffs = std::accumulate(payoffs.begin(), payoffs.end(), 0.0);
    double meanPayoff = sumPayoffs / numSimulations;

    // Discount back to present value
    return std::exp(-r * T) * meanPayoff;
}

int main() {
    double S0             = 100.0; // Initial stock price
    double K              = 105.0; // Strike price
    double T              = 1.0;   // Time to maturity in years
    double r              = 0.05;  // Risk-free interest rate
    double sigma          = 0.2;   // Volatility
    int    numSimulations = 100000;

    double price = monteCarloCallPrice(S0, K, T, r, sigma, numSimulations);
    std::cout << "Estimated Call Option Price: " << price << std::endl;

    return 0;
}
