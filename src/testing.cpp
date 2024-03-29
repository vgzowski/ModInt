#include <vector>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <optional>
#include <cassert>
#include "Modular.h"

using namespace std;

int main() {
	ModInteger<998244353> H(1);
	auto S = sqrt(H);
	if (S.has_value()) {
		cout << "! " << S.value() << endl;
	}
	else {
		cout << "! No value" << endl;
	}

	ModInteger<11> a(3);
	initialiseInverse<11>(10);
	for (int i = 1; i <= 10; ++i) {
		cout << (ModInteger<11>(i)).inverse() * i << " ";
	}
	cout << endl;

	cout << sqrt(a).value() << endl;

	cout << a * a.inverse() << endl;
	cout << -a << endl;

	int C = static_cast<int>(a);
	cout << "! " << C << endl;

	vector < ModInteger <13> > vec{1, 2, 17};
	auto vec1 = vector <int> (begin(vec), end(vec));

	for (auto &x : vec) cout << x << " ";
	cout << endl;
	for (auto &x : vec1) cout << x << " ";
	cout << endl;

	cout << abs(a) << endl;

	cout << pow(a, 4) << endl;
	cout << a * 128 << endl;

	ModInteger<10> b(3);
	cout << b * b.inverse() << endl;


	static_assert( IsModular<ModInteger<-5>>::value );
	static_assert( IsModular<ModInteger<123>>::value );
	static_assert( IsModular<ModInteger<11>>::value );
	static_assert( IsModular<ModInteger<0>>::value );
	static_assert( !IsModular<int>::value );

	const int md = 191;
	typedef ModInteger<md> mint;

	for (int i = 1; i < md; ++i) {
		mint x(i);
		auto sq = sqrt(x);

		optional<int> found;
		for (int j = 1; j < md; ++j) {
			if (((j * j) % md) == i) {
				found = j;
				break;
			}
		}
		assert((found == nullopt) == (sq == nullopt));
		if (sq.has_value()) {
			auto z = sq.value();
			assert(z * z == x);
		}
	}
	for (int i = 1; i < md; ++i) {
		for (int j = 1; j < md; ++j) {
			mint a(i), b(j);
			optional<int> found;
			auto _lg = log(a, b);
			for (int x = 0; x < md; ++x) {
				if (pow(a, x) == b) {
					found = x;
					break;
				}
			}
			assert((found == nullopt) == (_lg == nullopt));
			if (_lg.has_value()) {
				auto z = _lg.value();
				assert(pow(a, z) == b);
			}
		}
	}
}
