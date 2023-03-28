#include<iostream>
#include <random>

double func(double x, double y) {
	return -(x * x + y * y)+2;
}

double integrateMonteCarlo(double a, double b, int N) {
	srand(unsigned(time(0)));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(a, b);
	
	double p = 1 / ((b - a) * (b - a));
	double res=0;
	for (int i = 0; i < N; i++) {
		double x = dist(gen);
		double y = dist(gen);
		res += func(x, y) /p;
	}
	return res/N;
}

int main() {
	int n=100;
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		double val = integrateMonteCarlo(-2, 2, 10000);
		res += val / n;
		//std::cout << val << std::endl;
	}

	std::cout << "RESULT: " << res;

	system("pause");
}