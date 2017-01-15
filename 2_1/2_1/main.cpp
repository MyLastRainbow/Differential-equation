#include <iostream>
#include <math.h>

using namespace std;

void memory_assign(double *&t, int n)
{
	t = (double*)malloc(sizeof(double)*(n + 1));
	return;
}

void memory_free(double *&t)
{
	free(t);
	t = nullptr;
	return;
}



double f(double x, double y)
{
	double t = y - (2 * x) / y;
	return t;

}

double yexact(double x)
{
	return sqrt(1 + 2 * x);
}


int main(int num, char **ptr)
{
	int i; // variable for iteration

	int n; // the segment number
	double a, b; //the bound
	double h; // strp size
	
	double err = 0; // local error
	double maxerr = 0; // max local error

	double *x = nullptr; // discrete the independent variables
	double *yi = nullptr; // Numerical solution

	a = 0.0;
	b = 1.0;
	n = 10;
	h = (b - a) / n;

	memory_assign(x, n); // Allocate memory for the independent
	memory_assign(yi, n); // Allocate memory for the numerical solution


	for (i = 0; i <= n; i++)
	{
		x[i] = a + i * h; // initialize the the independent
	}

	yi[0] = 1.0;

	for (i = 0; i < n; i++) // Attention the logic symbol
	{
		yi[i + 1] = yi[i] + h * f(x[i],yi[i]);
		err = fabs(yi[i + 1] - yexact(x[i + 1]));    //计算节点处的误差
		printf("x[%d]=%.4f, y[%d]=%f, exact=%f,  err=%f\n", i + 1, x[i + 1], i + 1, yi[i
			+ 1], yexact(x[i + 1]), err);  //打印节点及在这个节点上的数值解、精确解和误差
		if (err>maxerr)
			maxerr = err;

	}

	printf("The max error is %f\n", maxerr);  //打印最大误差
	
	memory_free(x);
	memory_free(yi);

	system("pause");

	return 0;


}