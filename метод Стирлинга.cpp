
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
const int n = 10;
double x[n + 1] = { 0.324, 0.519, 0.714, 0.909, 1.104, 1.299, 1.494, 1.689, 1.884, 2.079, 2.274 };
double y[n + 1] = { -0.345, -0.085, 0.02, 0.017, -0.049, -0.136, -0.199, -0.193, -0.074, 0.203, 0.683 };
double z[3] = { 1.696, 1.886, 1.34 };

double Stir(int d, double q);
double delta(int r, int k);
int main()
{

	setlocale(0, "rus");
	double min, b, q, rez;
	int d;
	for (int j = 0; j<3; j++)
	{
		min = 1000;
		b = z[j];
		cout << "x = " << b << endl;
		for (int i = 0; i <= n; i++)
			if (fabs(x[i] - b)<min)
			{
				d = i;
				min = fabs(x[i] - b);
			}
		q = fabs(b - x[d]) / (x[2] - x[1]);
		cout << "Вычисление методом Стирлинга" << endl;
		cout << "q = " << q << endl;
		rez = Stir(d, q);
		cout << "Результат вычислений: " << rez << endl << endl;
	}
	system("pause");
}

int fact(int i)
{
	if (i <= 1) return 1;
	else return (i*fact(i - 1));
}

int C(int j, int r)
{
	return (fact(j) / fact(r) / fact(r - j));
}

double delta(int r, int k)
{
	double sum = 0;
	for (int j = 0; j <= k; j++)
		if (j % 2 == 0) sum += C(j, k)*y[k - j];
		else sum -= C(j, k)*y[k - j];
		return (sum);
}
double Stir(int d, double q)
{
	double sum, a;
	sum = y[d];
	a = 1;
	for (int i = 1; i <= n; i++, a *= (q*q - (i - 1)*(i - 1)))
		sum += q*a*(delta(2 * i - 1, i) + delta(2 * i, i - 1)) / (fact(2 * i - 1) * 2) + q*q*a*delta(2 * i, i) / fact(2 * i);
	return (sum);
}
