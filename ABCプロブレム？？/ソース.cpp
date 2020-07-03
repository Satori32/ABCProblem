#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

//typedef std::vector<std::uintmax_t> DType;
//https://ja.wikipedia.org/wiki/ABC%E4%BA%88%E6%83%B3

template<class UInt>
std::vector<UInt> PrimeFacterlizer(UInt N) {

	std::vector<UInt> R;
	for (UInt i = 2; i <= N; i++) {
		if (N % i == 0) {
			R.push_back(i);
			N /= i;
			i--;
		}
	}

	return R;
}

template<class UInt>
UInt Radical(UInt N) {
	auto R = PrimeFacterlizer(N);

	std::sort(R.begin(), R.end());

	R.erase(std::unique(R.begin(), R.end()), R.end());

	UInt V = 1;
	for (auto& o : R) {
		V *= o;
	}
	
	return N;

}

bool CrashABCProblem(double Epsilon) {//not debug complete

	for (std::uintmax_t C = 1; C <= std::numeric_limits<std::uintmax_t>::max(); C++) {
		for (std::uintmax_t B = 1; B < C / 2; B++) {
			std::uintmax_t A = C - B;
			if (std::gcd(A, B) != 1) { continue; }
			if (std::gcd(A, C) != 1) { continue; }
			if (std::gcd(B, C) != 1) { continue; }
			auto R = Radical(A * B * C);
			double X = std::pow(R, 1 + Epsilon);
			if (X < C) {
				std::cout << "A:" << A << ",B:" << B << ",C:" << C << ",Rad:" << R << std::endl;
			}
		}
	}
	return true;
}
template<class Float,class UInt>
bool ABCCheck(const UInt A, UInt B, Float Ep) {//not debug complete.
	UInt C = A + B;

	if (std::gcd(A, B) != 1) { return false; }
	if (std::gcd(A, C) != 1) { return false; }
	if (std::gcd(B, C) != 1) { return false; }
	UInt N = A * B * C;
	auto R = Radical(N);
	Float X = std::pow(R, 1 + Ep);//i cant solve. need custamizetion point.

	return C>X;
}
template<class Float,class UInt>
Float Quality(const UInt& A, const UInt& B) {//need custmizetion point. and not debug complete.
	UInt C = A + B;
	return std::log(C) / std::log(Radical(A* B* C));
}
int main() {

	std::uintmax_t N = 2 * 3 * 4 * 4 * 2 * 5 * 7;
	auto R = PrimeFacterlizer(N);
	auto V = Radical(N);

	bool A = ABCCheck<double>(1, 1, -2);
	std::cout << A << std::endl;
	A = ABCCheck<double>(1, 1, 1);
	std::cout << A << std::endl;
	A = ABCCheck<double>(1, 1, 0);
	std::cout << A << std::endl;
	A = ABCCheck<double>(2, 2, 0);
	std::cout << A << std::endl;

	int C = 0;
	for (std::uintmax_t i = 0; i < 100; i++) {
		if (Quality<double>(i, 100 - i) > 1.0) {
			C++;
		}
	}
	std::cout << C << std::endl;
	return 0;
}
/** /
int main() {
	std::uintmax_t N = 2 * 2 * 3 * 3 * 5 * 7;
	auto R = PrimeFacterlizer(N);

	for (auto& o : R) {
		std::cout << o << ',';
	}
	std::cout << std::endl;

	std::cout<<Radical(N) << std::endl;

	CrashABCProblem(0);
	return 0;
}
/**/