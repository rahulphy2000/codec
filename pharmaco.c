#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define N 2   // number of ODEs
#define h 0.01 // step size

double f(double t, double y[N], int i) 
{
	
	float K = 0.0409;
    float K12 = 0.0376;
    float K21 = 0.0190;
    float K12e = 0.0648;
    float sigma = 0.71;
    float ohm = 12.6;
    //C=y[0],H=y[1],tau=t
    // Define the ODEs here
    double dydt;
    switch(i) {
        case 0:
            dydt = -K*y[0]+3*y[1]*y[1]*((sigma-y[0])/(ohm+1-(y[1]*y[1]*y[1])))*(1-y[0]) ;
            break;
        case 1:
            dydt = -(1-y[0]);
            break;
    }
    return dydt;
}

int main() {
    double t = 0.0;
    double y[N] = {0.0, 1.0}; // initial values
    double k1[N], k2[N], k3[N], k4[N];
    int i;

    
    printf("%f\t %f\t %f\n", t, y[0], y[1]);

    // Runge-Kutta method
    while (t <= 50.0) 
	{
        for (i = 0; i < N; i++) 
		{
            k1[i] = h * f(t, y, i);
            k2[i] = h * f(t + h/2, y, i) + k1[i]/2;
            k3[i] = h * f(t + h/2, y, i) + k2[i]/2;
            k4[i] = h * f(t + h, y, i) + k3[i];
            y[i] += (k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6;
        }
        t += h;
        printf("%f\t %e\t %e\t %e\n", t, y[0], y[1]);
    }

    return 0;
}
