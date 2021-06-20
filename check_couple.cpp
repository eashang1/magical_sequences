#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    cout << "Enter first sequence:" << "\n";
    string str1; cin >> str1;
    cout << "\n";
    cout << "Enter second sequence:" << "\n";
    string str2; cin >> str2;
    
    vector<int> seq1, seq2;
    for (int i = 0; i < len; i++) {
        seq1.push_back(str1[i]-'0');
    }
    for (int i = 0; i < len; i++) {
        seq2.push_back(str2[i]-'0');
    }

    bool done = false;
    for (int i = 0; i < str1.length(); i++) {
        set<int> majority, minority;
        for (int j = 0; j < frame; j++) {
            if(seq1[(i+j)%len] == 0) {
                majority.insert(j);
            }
            else {
                minority.insert(j);
            }
        }
        
        if(minority.size() > majority.size()) {
            swap(minority,majority);
        }
        
        map<string,int> check;
        for (int j = 0; j < len; j++) {
            set<int> temp1, temp2;
            for (int k = 0; k < frame; k++) {
                if(seq1[(j+k)%len] == 0) {
                    temp1.insert(k);
                }
                else {
                    temp2.insert(k);
                }
            }
            
            if(temp2.size() > temp1.size()) {
                swap(temp1,temp2);
            }
            
            if(majority == temp1) {
                string add = "";
                for (int loc : majority) {
                    add += ('0'+seq2[(j+loc)%len]);
                }
                
                check[add]++;
                if(check[add] > 1){done = true;}
                
                string add_neg = "";
                for (int k = 0; k < add.length(); k++) {
                    if(add[k] == '1') {
                        add_neg += '0';
                    }
                    else {
                        add_neg += '1';
                    }
                }
                
                check[add_neg]++;
                if(check[add_neg] > 1){done = true;}
            }
        }
        
        if(done) {
            break;
        }
    }
    
    cout << "\n";
    if(done) {
        cout << "Not a valid de Bruijn couple" << "\n";
    }
    else {
        cout << "Valid de Bruijn couple" << "\n";
    }
    
    return 0;
}


