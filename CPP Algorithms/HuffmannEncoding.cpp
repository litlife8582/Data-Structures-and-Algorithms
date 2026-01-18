#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
    int time;

    Node(char d, int f, int t) : data(d), freq(f), left(NULL), right(NULL), time(t) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        if (l->freq != r->freq)
            return l->freq > r->freq;
        return l->time > r->time;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->data << " " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    string S;
    cin >> S;

    int n = S.length();
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(S[i], f[i], i));
    }

    int timer = n;

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* top = new Node('$', left->freq + right->freq, timer++);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");

    return 0;
}