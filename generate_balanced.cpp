#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <map>
using namespace std;
int main()
{
    for (int it = 0; it < 10000; it++) {
        
        vector<char> vals = {'1','1','1','1','1','1','1','1','1','1','1','1',
        '1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1'
        ,'1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0'
        ,'0','0','0','0','0'};
        
        random_shuffle(vals.begin(),vals.end());
        
        string str = "";
        for (int i = 0; i < 52; i++) {
            str += vals[i];
        }
        
        bool fin = false;
        int len = 52;
        int frame; frame = 5;
        int lim; lim = 2;
        
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
                fin = true;
                break;
            }
        }
        
        if(!fin) {
            cout << str << "\n";
        }
    }
    return 0;
}


