#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    cout << "What is your sequence length?" << "\n";
    int len; cin >> len;
    cout << "\n";
    cout << "How long is each substring?" << "\n";
    int frame; cin >> frame;
    cout << "\n";
    cout << "How often can each substring occur at most?" << "\n";
    int lim; cin >> lim;
    cout << "\n";
    cout << "Enter your sequence (without spaces or commas):" << "\n";
    string str; cin >> str; 
    
    vector<int> sequence;
    for (int i = 0; i < str.length(); i++) {
        sequence.push_back(str[i]-'0');
    }

    map<string,int> done;
    for(int i = 0; i < sequence.size(); i++) {
        string temp = "";
        for (int j = i; j < i+frame; j++) {
            temp += sequence[j%sequence.size()];
        }
        done[temp]++;
        
        if(done[temp] > lim) {
            cout << "\n";
            cout << "Not a balanced cyclic de Bruijn sequence with parameters " <<  sequence.size() << " " << 5 << " " << 2 << " (start index " << i+1 << " gives too many occurrences)" << "\n";
            return 0;
        }
    }
    
    cout << "\n";
    cout << "Valid balanced cyclic de Bruijn sequence with parameters  " <<  sequence.size() << " " << 5 << " " << 2 << "\n";
    return 0;
}

