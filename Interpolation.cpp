#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "fstream"
#include "ctime"
//------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------
const double pi=3.14159265;
//------------------------------------------------------------------------------------------------
void input(double*,double*,int*);
void input_y(double*,double*,double*,double,double,int);
double a_0(double*,int);
double a_m(double*,int);
double a_k(double*,int,int);
double b_k(double*,int,int);
void T_m(double*,double*,double*,double*,double*,double,double,int);
void stream_output(double*,double*,double*,double*,int);
//------------------------------------------------------------------------------------------------
void main()
{
	srand(time(0));
	int m,N;
	double *y,*x,*T,*t,*t_int,a,b;
	input(&a,&b,&m);
	N=2*m;
	t_int=new double[60];
	T=new double[60];
	t=new double[N];
	y=new double[N];
	x=new double[60];
	input_y(t_int,y,t,a,b,N);
	T_m(t_int,T,x,t,y,a,b,m);
	stream_output(t_int,T,t,y,2*m);
	cout<<"Done!"<<endl;
}

void input(double *a,double *b,int *m)
{
	ifstream f("Experimental_data.txt");
	f>>*a;
	f>>*b;
	f>>*m;
	f.close();
}

void input_y(double *t_int,double *y,double *t,double a,double b,int N)
{
	double dt=(b-a)/N,x=a,dintx;
	for(int i=1;i<=N;i++)
	{
		t[i]=x;
		y[i]=rand()%10;
		x+=dt;
	}
	dintx=(b-a)/60,x=a;
	for(int i=1;i<=60;i++)
	{	
		t_int[i]=x;
		x+=dintx;
	}
}

void stream_output(double *t_int,double *T,double *t,double *y, int N)
{
	ofstream f;
	f.open("Interpolation.txt");
	for(int i=1;i<=N;i++)
	{
		f<<t[i];
		f<<' ';
	}
	for(int i=1;i<=N;i++)
	{
		f<<y[i];
		f<<' ';
	}
	for(int i=1;i<=60;i++)
	{
		f<<t_int[i];
		f<<' ';
	}
	for(int i=1;i<=60;i++)
	{
		f<<T[i];
		f<<' ';
	}
	f.close();
}

double a_0(double *y,int N)
{
	double a0=0;
	for(int i=1;i<=N;i++)
		a0+=y[i];
	a0*=2;
	a0/=N;
	return a0;
}

double a_m(double *y,int N)
{
	double am=0;
	for(int i=1;i<=N;i++)
		am+=(pow(-1,i-1)*y[i]);
	am*=2;
	am/=N;
	return am;
}

double a_k(double *y,int k,int N)
{
	double ak=0;
	for(int i=1;i<=N;i++)
		ak+=(cos(2*pi*k*(i-1)/N)*y[i]);
	ak*=2;
	ak/=N;
	return ak;
}

double b_k(double *y,int k,int N)
{
	double bk=0;
	for(int i=1;i<=N;i++)
		bk+=(sin(2*pi*k*(i-1)/N)*y[i]);
	bk*=2;
	bk/=N;
	return bk;
}

void T_m(double *t_int,double *T,double *x,double *t,double *y,double a,double b,int m)
{
	int N=2*m;
	double s;
	x=new double[60];
	for(int i=1;i<=60;i++)
		x[i]=2*pi*(t_int[i]-a)/(b-a);
	for(int i=1;i<=60;i++)
	{
	s=0;
	for(int k=1;k<=m-1;k++)
		s+=(a_k(y,k,N)*cos(k*x[i])+b_k(y,k,N)*sin(k*x[i]));
	T[i]=a_0(y,N)/2+s+a_m(y,N)*cos(m*x[i])/2;
	}
}