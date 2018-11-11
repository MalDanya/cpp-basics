#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const int kMaxIters = 1000;
	const double kEps = 1e-15;
	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		cout << string(74, '-') << endl;
		cout << "|         x         ";
		cout << "|  cos(x)   (mine)  ";
		cout << "|  cos(x)  (cmath)  ";
		cout << "| iterations |\n";
		cout << string(74, '-') << endl;

		cout << fixed;
		cout.precision(6);

		double f, iter;
		while ((xk - xn) > kEps)
		{
			int n = 1;
			iter = f = 1;
			while (abs(iter) > eps) {
				iter = pow((-1), n)*pow(xn, n * 2) / tgamma(n * 2);
				f += iter;
				n++;
				if (n > kMaxIters) break;
			}
			cout << "|" << setw(13) << xn << setw(7) << "|" << setw(14);
			if (n <= kMaxIters)
				cout << f << setw(6) << "|";
			else
				cout << " limit is exceeded |";
			cout << setw(14) << cos(xn) << setw(6) << "|";
			cout << setw(7) << n << setw(7) << "|\n";
			xn += dx;
		}
		cout << string(74, '-');
	}

	return 0;
}