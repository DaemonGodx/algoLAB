//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)
//Experiment-6 Task-2- fractional knapsack implementation 


#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // sort in decreasing order of value/weight ratio
}

double fractionalKnapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), cmp);

    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            finalValue += items[i].value;
        } else {
            finalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);

    cout << "Enter values and weights:\n";
    for (int i = 0; i < n; i++) cin >> items[i].value >> items[i].weight;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << fixed << setprecision(2);
    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items, n) << endl;
    return 0;
}