#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    long long k;

    cin >> n >> m >> k;

    vector<int> arr(n);
    vector<bool> eaten(n, false);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long c = 0;

    for (int i = 0; i < n; i++) {

        if (i >= m) {
            if (eaten[i - m]) {
                c -= arr[i - m];
            }
        }

        if (c + arr[i] <= k) {
            cout << "Yes" << endl;
            c += arr[i];
            eaten[i] = true;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
