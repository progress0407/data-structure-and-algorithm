#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

struct Person {
    string name;
    int score;

    Person(const string& name, int score) : name(name), score(score) {}
};

struct CompareScore {
    bool operator()(Person const& p1, Person const& p2)
    {
        // return "true" if "p1" has lower score than "p2"
        return p1.score < p2.score;
    }
};

int main() {
    // Create a priority queue with CompareScore comparator
    priority_queue<Person, vector<Person>, CompareScore> pq;

    pq.push(Person("Tom", 3));
    pq.push(Person("Jerry", 5));
    pq.push(Person("Spike", 1));
    pq.push(Person("Butch", 4));

    while(!pq.empty()) { 
        cout << pq.top().name << " " << pq.top().score << '\n'; 
        pq.pop(); 
    }

    return 0;
}
