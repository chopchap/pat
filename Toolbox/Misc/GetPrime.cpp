/**
 * To select primes
 */
#include <cstdio>
#include <cmath>

const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};

// Eratosthenes sieve: T = O(nloglogn)
void EratosthenesSieve()
{
	for (int i = 2; i < maxn; i++)
		if (p[i] == false) {
			prime[num++] = i;
			for (int j = i+i; j < maxn; j += i)
				p[j] = true;
		}
}

// Euler sieve method: T = O(n)
bool vis[maxn] = {0};
void EulerSieve()
{
	for (int i = 2; i < maxn; i++) {
		if (!vis[i])
			prime[num++] = i;
		for (int j = 0; j < num && i*prime[j] < maxn; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int) sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
		if (n % i == 0) return false;
	return true;
}

// T = O(n * sqrt(n)), works fine if maxn < 10^5
void Naive_Find_Prime()
{
	for (int i = 1; i < maxn; i++)
		if (isPrime(i)) {
			prime[num++] = i;
			p[i] = true;
		}
}

int main()
{
	EratosthenesSieve();

	for (int i = 0; i < num; i++)
		printf("%d ", prime[i]);

	return 0;
}

