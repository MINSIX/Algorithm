#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool isEnd;
    unordered_map<char, Trie*> children;

    Trie() {
        isEnd = false;
    }

    bool insert(const string& word) {
        Trie* current = this;
        for (char ch : word) {
            if (current->isEnd) return false;  
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new Trie();
            }
            current = current->children[ch];
        }
        if (!current->children.empty()) return false;
        current->isEnd = true;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<string> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        Trie* root = new Trie();
        bool isValid = true;

        for (int i = 0; i < N; i++) {
            if (!root->insert(arr[i])) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
