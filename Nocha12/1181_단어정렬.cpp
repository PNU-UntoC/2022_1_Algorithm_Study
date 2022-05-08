#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<string> words;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string temp;
        
        cin >> temp;
        
        words.push_back(temp);
    }
    
    sort(words.begin(), words.end(),
         [](string a, string b) {
            if(a.length() == b.length())
                return a < b;
            
        return a.length() < b.length();
        });
    
    cout << words[0] << endl;
    
    for(int i = 1; i < N; i++) {
        if(words[i - 1] != words[i]) {
            cout << words[i] << endl;
        }
    }
}
