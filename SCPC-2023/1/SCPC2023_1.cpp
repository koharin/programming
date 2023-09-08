/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{

        Answer = 0;
		
		/////////////////////////////////////////////////////////////////////////////////////////////
        int N, A, B, index1=0, index2=0, lim=0;

        scanf("%d %d %d", &N, &A, &B);

        index1 = A < B ? A : B;
        index2 = A < B ? B : A;
        lim = N/index1+1;
        vector<int> DP(lim);
        DP[0] = 0;

        for(int i=1; i<lim; i++){
            if(i + (N - index1*i)/index2 != 0) DP[i] = DP[i-1];
            else DP[i] = max(DP[i-1], i + (N - index1*i)/index2);
        }

        Answer = DP.back();
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}