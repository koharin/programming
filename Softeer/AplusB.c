#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	unsigned int T;
	scanf("%d", &T);

	for(int i=0; i<T; i++){
		unsigned int a,b;
		scanf("%d %d", &a, &b);

		printf("Case #%d: %d\n", i+1, a+b);
	}
	return 0;
}
