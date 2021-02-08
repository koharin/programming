#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector<int> count(26, 0);
    int c=0;
    for(auto i: a) ++count[i-'a'];
    for(auto i: b) --count[i-'a'];
    for(auto i: count) c += abs(i);
    return c;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
