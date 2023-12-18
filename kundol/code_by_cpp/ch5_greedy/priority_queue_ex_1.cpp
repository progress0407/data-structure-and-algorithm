#include <iostream>
#include <queue> // 우선순위 큐를 사용하기 위한 헤더 파일

using namespace std;

int main() {
    priority_queue<int> pq; // 정수형 우선순위 큐 선언

    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(4); // 각 요소를 큐에 삽입

    while(!pq.empty()) { // 큐가 비어있지 않는 동안
        cout << pq.top() << ' '; // 큐의 가장 높은 요소를 출력
        pq.pop(); // 가장 높은 요소를 제거
    }

    return 0;
}
