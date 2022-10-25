#include<iostream>

using namespace std;

int main(){
    int nums;
    cin >> nums;

    int n[100000], h[100000];
    bool up = true, down = true, reverse = false, first = true;
    int last;
    for(int i = 0; i < nums; i++){
        cin >> n[i];
        for (int j = 0; j < n[i]; j++){
            cin >> h[j];
            if (j == 0)
                last = h[j];
            if (j == 1)
                if (last > h[j] && first)
                    up = true;
            if (last > h[j] && down){
                last = h[j];
            }
        }
    }

    return 0;
}
