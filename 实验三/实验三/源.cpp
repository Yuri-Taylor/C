#include <iostream>
using namespace std;

void myInvMod(long *k3, const long k2, const long x)
{
	long u, v, t, t1, t2, q, r;

	u = k2; v = x;
	if (u < 0)
	{
		cout << "#######################This is break by inversion of a negative number.\n";
	}

	t1 = 1; t2 = 0;

	while (u != 1)
	{
		if (u == 0)cout << "u is equal to 0;" << endl;
		q = (v - v % u) / u; r = v - q * u; t = t2 - q * t1;
		v = u; u = r; t2 = t1; t1 = t;
	}

	if (t1 < 0)
		*k3 = x - (-t1) % x;
	else
		*k3 = t1 % x;
}


void tuoadd(const long x1, const long y1, long *x2, long *y2, const long x, const long a, long n)
{
	//(X1,Y1)N次数乘,结果为(*X2,*Y2)
	int i;
	long k, k1, k2, k3, x3, y3;
	*x2 = x1; *y2 = y1;

	for (i = 2; i <= n; i++)                                           //x1=3;y1=10;x2=9;y2=7;x=23;a=1;//
	{
		if ((*x2 == x1) && (*y2 == y1))
		{
			k1 = 3 * x1*x1 + a;
			k2 = 2 * y1;
		}
		else
		{
			k1 = *y2 - y1;
			k2 = *x2 - x1;
		}

		if (k2 < 0)
			k2 = x - (-k2) % x;
		else
			k2 = k2 % x;

		if (k2 == 0)
		{
			//k2=23;
			cout << "i=" << i << endl;
			cout << "k2 is equal to zero here!" << endl;
			cout << "x1=" << x1 << "y1=" << y1 << endl;
			cout << "x2=" << *x2 << "y2=" << *y2 << endl;
		}

		myInvMod(&k3, k2, x);

		if ((k1*k3) < 0)
			k = x - (-(k1*k3)) % x;
		else
			k = (k1*k3) % x;

		x3 = k * k - x1 - (*x2);

		if (x3 < 0)
			*x2 = x - (-x3) % x;
		else
			*x2 = x3 % x;

		y3 = k * (x1 - x3) - y1;

		if (y3 < 0)
			*y2 = x - (-y3) % x;
		else
			*y2 = y3 % x;

		cout << "i=" << i << "   (" << *x2 << "," << *y2 << ")" << endl;
	}
}

void tuoadd2(const long x1, const long y1, long *x2, long *y2, const long x, const long a)
{
	//(x1,y1)+(*x2,*y2)=(*x2,*y2)
	long k, k1, k2, k3, x3, y3;

	if (((*x2) == (x1)) && ((*y2) == (y1)))
	{
		k1 = 3 * (x1)*(x1)+a;
		k2 = 2 * (y1);
	}
	else
	{
		k1 = (*y2) - (y1);
		k2 = (*x2) - (x1);
	}

	if (k2 < 0)
		k2 = x - (-k2) % x;
	else
		k2 = k2 % x;

	if (k2 == 0)
	{
		cout << "k2 is equal to zero here!" << endl;
		cout << "x1=" << x1 << "y1=" << y1 << endl;
		cout << "x2=" << *x2 << "y2=" << *y2 << endl;
	}

	myInvMod(&k3, k2, x);

	if ((k1*k3) < 0)
		k = x - (-(k1*k3)) % x;
	else
		k = (k1*k3) % x;

	x3 = k * k - (x1)-(*x2);

	if (x3 < 0)
		(*x2) = x - (-x3) % x;
	else
		(*x2) = x3 % x;

	y3 = k * ((x1)-x3) - (y1);

	if (y3 < 0)
		*y2 = x - (-y3) % x;
	else
		*y2 = y3 % x;
}

void Signature(long xb, long yb, long Hm, long n, long a, long q, long d, long *r, long *s)
{
	long k, Inv_k, x2, y2, t;
	k = 3;
	tuoadd(xb, yb, &x2, &y2, q, a, k);
	cout << "This is in Signature!" << endl;
	cout << "x2=" << x2 << "  y2=" << y2 << endl;

	if (x2 < 0)
		*r = n - (-x2) % n;
	else
		*r = x2 % n;

	myInvMod(&Inv_k, k, n);

	t = (Inv_k*(Hm + d * (*r)));
	if (t < 0)
		*s = n - (-t) % n;
	else
		*s = t % n;

	cout << "*r=" << *r << "  *s=" << *s << endl;

}

void Verification(long xb, long yb, long xu, long yu, long Hm, long r, long q, long a, long s, long n)
{
	long Inv_s, x1, y1, x2, y2, w, u1, u2;

	cout << "This is in Verification!" << endl;
	cout << "r=" << r << endl;
	myInvMod(&Inv_s, s, n);

	if (Inv_s < 0)
		w = n - (-Inv_s) % n;
	else
		w = Inv_s % n;

	if ((Hm*w) < 0)
		u1 = n - (-(Hm*w)) % n;
	else
		u1 = (Hm*w) % n;

	if ((r*w) < 0)
		u2 = n - (-(r*w)) % n;
	else
		u2 = (r*w) % n;


	cout << "w=" << w << "  u1=" << u1 << "  u2=" << u2 << endl;
	tuoadd(xb, yb, &x1, &y1, q, a, u1);
	tuoadd(xu, yu, &x2, &y2, q, a, u2);
	tuoadd2(x1, y1, &x2, &y2, q, a);
	cout << "x2=" << x2 << " y2=" << y2 << endl;

	if (x2 == r)
		cout << "Accept the signature!" << endl;
	else
		cout << "Reject the signature!" << endl;

}



void main()
{

	cout << "====================================================" << endl;
	cout << "             椭圆曲线数字签名验证函数               " << endl;
	cout << "====================================================" << endl;
	cout << "this is in main program." << endl;
	/*
	 Domain parameters for an elliptic curve scheme describes an elliptic curve E defined over a finite field
	 Fq, a base point P belongs to E(Fq), and its order n. The parameters should be chosen so that the ECDLP
	 is resistant to all known attacks. The parameters (q,FR,S,a,b,P,n,h) has the following form:

	 q=23; a=1; b=1; P=(x1,y1); n=28; h=1;

	 where n is the order of the base point P; h is the cofactor #E(Fq)/n
		a and b are coefficients of equation of the elliptic curve E over Fq.
		the representation of the elliptic curve is :y2=x3+ax+b

	 */

	long q, a, b, xb, yb, n, h, d, r, s, xu, yu, Hm;

	q = 11;   // the modulus of the finite field;
	a = 1; b = 6; // y2=x3+ax+b;
	xb = 2; yb = 7; // P=(2,7) base point of elliptic curve;
	n = 13; h = 1;
	d = 7;  // d is private key;
	Hm = 4; // Hm is hash funcation of message;
	tuoadd(xb, yb, &xu, &yu, q, a, d); // Q=(xu,yu) is the public key;

	cout << "xu=" << xu << "yu=" << yu << endl;

	Signature(xb, yb, Hm, n, a, q, d, &r, &s);
	Verification(xb, yb, xu, yu, Hm, r, q, a, s, n);

	/*
	x1=2;y1=7; // P=(2,7);
   tuoadd(x1,y1,&x2,&y2,q,a,n);
   tuoadd2(x1,y1,&x2,&y2,x,a);
   cout<<"  ("<<x2<<","<<y2<<")"<<endl;
   */

}


