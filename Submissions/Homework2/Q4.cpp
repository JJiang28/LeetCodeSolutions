#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string parameters = " ";
    string initial = " ";
    string operations = " ";
    string queries = " ";

    getline(cin, parameters);
    istringstream s(parameters);
    int n, m, k;
    s >> n >> m >> k;
    
    getline(cin, initial);
    istringstream p(initial);
    vector<long long> initialArr; 
    long long num = 0;

    vector<long long> l(m);
    vector<long long> r(m);
    vector<long long> d(m);

    vector<long long> x(k);
    vector<long long> y(k);

    vector<long long> queryFreq(m + 1, 0);
    vector<long long> meow(n + 1, 0); //meow

    while(p >> num) {
        initialArr.push_back(num);
    }
    for(int i = 0; i < m; i++) {
        getline(cin, operations);
        istringstream k(operations);
        k >> num;
        l[i] = num - 1;
        k >> num;
        r[i] = num - 1;
        k >> num;
        d[i] = num;
    }
    for(int i = 0; i < k; i++) {
        getline(cin, queries);
        istringstream l(queries);
        l >> num;
        x[i] = num - 1; 
        l >> num;
        y[i] = num - 1;
    }
    for(int i = 0; i < k; i++) {
        queryFreq[x[i]] += 1;
        if (y[i] + 1 < m) {
            queryFreq[y[i] + 1] -= 1;
        }
    }
    for(int i = 1; i < m; i++) {
        queryFreq[i] += queryFreq[i - 1];
    }
    for(int i = 0; i < m; i++) {
        long long times = queryFreq[i];
        if (times > 0) {
            meow[l[i]] += d[i] * times;
            if (r[i] + 1 < n) {
                meow[r[i] + 1] -= d[i] * times;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        meow[i] += meow[i - 1];
    }
    for(int i = 0; i < n; i++) {
        initialArr[i] += meow[i];
    }
    for(int i = 0; i < n; i++) {
        cout << initialArr[i] << " ";
    }
    return 0;
}
