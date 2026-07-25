// Write your code here
#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
 
    int N, L, R;
    cin >> N >> L >> R;
 
    vector<long long> arr(N + 1);
    vector<long long> prefix(N + 1, 0);
 
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
 
    vector<long long> dp(N + 1, 0);
 
    dp[0] = 1;
 
    for (int i = 1; i <= N; i++) {
 
        for (int j = i; j >= 1; j--) {
 
            long long sum = prefix[i] - prefix[j - 1];
 
            if (sum >= L && sum <= R) {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
            }
        }
    }
 
    cout << dp[N] << endl;
 
    return 0;
}
