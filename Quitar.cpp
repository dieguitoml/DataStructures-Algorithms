#include <cassert>
#include <iostream>
#include <queue>

void how_many(std::queue<int> &q, int salta) {
    int aux1;
    int aux2;
    while (!q.empty()) {
        aux2 = q.front();
        for (int i = 0; i < salta; i++) {
            aux1 = q.front();
            q.pop();
            q.push(aux1);
        }
        q.pop();
    }
    std::cout << aux2 << '\n';
}

bool resuelveCaso() {
    int N, salta;
    std::cin >> N >> salta;
    if (N == 0 && salta == 0)return false;
    std::queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }
    how_many(q,salta);
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}