#include <stdio.h>
#include <math.h>
#define EPS 10e-6

int iter=0;

double f(double x){
	return (x*x*x)+4*(x*x)-10;
}

int false_pos(double a,double b){
	iter++;
	double c=(a*f(b)-b*f(a))/(f(b)-f(a));
	printf("%d %lf %lf %lf %lf %lf %lf\n",iter,a,b,c,f(a),f(b),f(c));
	if(fabs(f(c))<EPS) {
		printf("---------------------------------------------------------\n");
		printf("\n The root is %lf\n",c);
		return 0;
	}
	else {
		if(f(a)*f(c)<0) false_pos(a,c);
		else false_pos(c,b);
	}
}
void main(){
	double a,b;
	
	printf("Enter two points: ");
	scanf("%lf %lf",&a,&b);
	printf("---------------------------------------------------------\n");
	printf("I     a        b        c       f(a)     f(b)      f(c)  \n");
	printf("---------------------------------------------------------\n");
	false_pos(a,b);
}
