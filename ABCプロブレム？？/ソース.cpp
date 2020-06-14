#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

typedef std::vector<std::uintmax_t> DType;

DType PrimeFacterlizer(std::uintmax_t N) {

	DType R;
	for (std::uintmax_t i = 2; i <= N; i++) {
		if (N % i == 0) {
			R.push_back(i);
			N /= i;
			i--;
		}
	}

	return R;
}

std::uintmax_t Radical(std::uintmax_t N) {
	auto R = PrimeFacterlizer(N);

	std::sort(R.begin(), R.end());

	R.erase(std::unique(R.begin(), R.end()), R.end());

	std::uintmax_t V = 1;
	for (auto& o : R) {
		V *= o;
	}
	
	return N;

}

bool CrashABCProblem(double Epsilon) {//not debug complete

	for (std::uintmax_t A = 1; A <= std::numeric_limits<std::uintmax_t>::max(); A++) {
		for (std::uintmax_t B = 1; B < A/2; B++) {
			std::uintmax_t AD = A - B;
			if (std::gcd(AD, B) != 1) { continue; }
			std::uintmax_t C = AD + B;
			auto R = Radical(AD * B * C);
			double X = std::pow(R, 1 + Epsilon);
			if (X < C) {
				std::cout << "A:" << AD << ",B:" << B << ",C:" << C << ",Rad:" << R << std::endl;
			}
		}
	}
	return true;
}

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