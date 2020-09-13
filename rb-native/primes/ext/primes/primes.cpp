#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void get_primes7(int n, std::vector<int> &res) {
	if (n < 2) return;
	if (n == 2) {
		res.push_back(2);
		return;
	}
	std::vector<int> s;
	s.reserve(n / 2);
	for (int i = 3; i < n + 1; i += 2) {
		s.push_back(i);
	}
	int mroot = sqrt(n);
	int half = static_cast<int>(s.size());
	int i = 0;
	int m = 3;
	while (m <= mroot) {
		if (s[i]) {
			int j = static_cast<int>((m*m - 3) * 0.5);
			s[j] = 0;
			while (j < half) {
				s[j] = 0;
				j += m;
			}
		}
		i = i + 1;
		m = 2*i + 3;
	}
	res.reserve(n / log(n));
	res.push_back(2);

	std::vector<int>::iterator pend = std::remove(s.begin(), s.end(), 0);
	res.insert(res.begin() + 1, s.begin(), pend);
}

extern "C" int get_primes(int);

int get_primes(int n)
{
    std::vector<int> res;
    get_primes7(n, res);
    return res.size();
}
