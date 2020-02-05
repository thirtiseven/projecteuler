#include <iostream>

using ll = unsigned long long;

ll gcd(ll x,ll y) {
	if (x<0) x=-x;
	if (y<0) y=-y;
	while (true) {
		if (x==0) return (y);
		if (y==0) return (x);
		if (x>y) x%=y; else y%=x;
	}
}
struct Rational {
	ll p,q;
	Rational() {
		p=0;q=1;
	}
	Rational(ll p) {
		this->p=p;
		this->q=1;
	}
	Rational(ll p,ll q) {
		if (q<0) {
			p=-p;q=-q;
		}
		this->p=p;
		this->q=q;
	}
	Rational operator + (const Rational &x) const {
		return (Rational(p*x.q+q*x.p,q*x.q));
	}
	Rational operator - (const Rational &x) const {
		return (Rational(p*x.q-q*x.p,q*x.q));
	}
	Rational operator * (const Rational &x) const {
		return (Rational(p*x.p,q*x.q));
	}
	Rational operator / (const Rational &x) const {
		return (*this*x.inverse());
	}
	Rational inverse(void) const {
		return (Rational(q,p));
	}
	int compare(const Rational &x) const {
		ll A=p*x.q;
		ll B=q*x.p;
		return ((A>B)-(A<B));
	}
	#define DEF_OPER(x) bool operator x (const Rational &a) const { \
		return (compare(a) x 0); \
	}
	DEF_OPER(<) DEF_OPER(>) DEF_OPER(<=) DEF_OPER(>=) DEF_OPER(==) DEF_OPER(!=)
	#undef DEF_OPER
};
std::ostream& operator << (std::ostream &os,const Rational &x) {
	ll t=gcd(x.p,x.q);
	return (os<<x.p/t<<"/"<<x.q/t);
}

ll x[123];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll cnt = 1;
	for (int i = 1; i < 102; i++) {
		if (i%3==2) {
			x[i] = 2ll*cnt;
			cnt++;
		} else {
			x[i] = 1LL;
		}
	}
	int upper = 50;
	Rational ans = Rational(1ll, x[upper]);
	for (int i = upper-1; i >= 1; i--) {
		ans = Rational(1ll) / (Rational(x[i]) + ans);
	}
	ans = ans + Rational(2ll);
	std::cout << ans;
}