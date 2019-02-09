#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
void show(ll a, ll b) {
	if(b < 0) {
		a = -a;
		b = -b;
	}
	if(a < 0 || b < 0) printf("(");
	if(a % b == 0) printf("%lld", a / b);
	else if(a / b && a % b) printf("%lld %lld/%lld", a / b, a > 0 ? a % b : - a % b, b);
	else if(a % b) printf("%lld/%lld", a, b);
	if(a < 0 || b < 0) printf(")");
}
void add(ll a, ll b, ll c, ll d) {
	show(a, b); printf(" + ");
	show(c, d); printf(" = ");
	a = a * d + c * b;
	b *= d;
	ll g = gcd(a, b);
	show(a / g, b / g);
	printf("\n");
}
void sub(ll a, ll b, ll c, ll d) {
	show(a, b); printf(" - ");
	show(c, d); printf(" = ");
	a = a * d - c * b;
	b *= d;
	ll g = gcd(a, b);
	show(a / g, b / g);
	printf("\n");
}
void div(ll a, ll b, ll c, ll d) {
	show(a, b); printf(" / ");
	show(c, d); printf(" = ");
	if(c == 0) printf("Inf");
	else {
		a *= d; b *= c;
		ll g = gcd(a, b);
		show(a / g, b / g);
	}
	printf("\n");
}
void mul(ll a, ll b, ll c, ll d) {
	show(a, b); printf(" * ");
	show(c, d); printf(" = ");
	a *= c; b *= d;
	ll g = gcd(a, b);
	show(a / g, b / g);
	printf("\n");
}
int main() {
	ll a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	if(b == 0 || d == 0) printf("Inf"); // 注意分母为0的情况。。。 
	else {
		ll g = gcd(a, b); a /= g; b /= g;
		g = gcd(c, d); c /= g; d /= g;
		add(a, b, c, d);
		sub(a, b, c, d);
		mul(a, b, c, d);
		div(a, b, c, d);
	}
	return 0;
}
