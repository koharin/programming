#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	unsigned long K, P, N;

	scanf("%u %u %u", &K, &P, &N);

	for(unsigned int i=0; i<N; i++){
		K *= P;
		K %= 1000000007;
	}

	printf("%lu", K);
	return 0;
}
