#include<iostream>
using namespace std;

// A^B % C
long long power(long long A, long long B, long long C) {
    if (B == 0) return 1;
    long long half = power(A, B / 2, C);
    long long result = (half * half) % C;
    if (B % 2 == 1) {
        result = (result * A) % C;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C) << '\n';

    return 0;
}
