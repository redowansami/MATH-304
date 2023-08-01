#include <stdio.h>
#include <math.h>
#define EPS 10e-6

int iter=0;

double f(double x){
	return (x*x*x)+4*(x*x)-10;
}
double fp(double x){
	return 3*(x*x)+8*x;
}

int secant(double a){
	iter++;
	double c=a-(f(a)/fp(a));
	printf("%3d %lf %lf %lf %lf %lf\n",iter,a,c,f(a),fp(a),f(c));
	if(fabs(f(c))<EPS) {
		printf("---------------------------------------------------------\n");
		printf("\n The root is %16.9lf\n",c);
		return 0;
	}
	else{
	//a=b;
	//b=c;
	secant(c);
	}
}
void main(){
	double a;
	
	printf("Enter two points: ");
	scanf("%lf",&a);
	printf("---------------------------------------------------------\n");
	printf("Iter    x0       x1       f(a)     f(b)      f(c)  \n");
	printf("---------------------------------------------------------\n");
	secant(a);
}
