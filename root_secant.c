#include <stdio.h>
#include <math.h>
#define EPS 10e-6

int iter=0;

double f(double x){
	return (x*x*x)+4*(x*x)-10;
}

int secant(double a,double b){
	iter++;
	double c=(a*f(b)-b*f(a))/(f(b)-f(a));
	printf("%3d %lf %lf %lf %lf %lf %lf\n",iter,a,b,c,f(a),f(b),f(c));
	if(fabs(f(c))<EPS) {
		printf("---------------------------------------------------------\n");
		printf("\n The root is %16.9lf\n",c);
		return 0;
	}
	else{
	//a=b;
	//b=c;
	secant(b,c);
	}
}
void main(){
	double a,b;
	
	printf("Enter two points: ");
	scanf("%lf %lf",&a,&b);
	printf("---------------------------------------------------------\n");
	printf("Iter    x0       x1       x2       f(a)     f(b)      f(c)  \n");
	printf("---------------------------------------------------------\n");
	secant(a,b);
}
