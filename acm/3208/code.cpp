#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int nums;
    cin >> nums;
    //nums = 3;
    int min[nums], max[nums];
    //int min[3] = {8, 219, 210}, max[3] = {14, 111, 35};
    for (int i = 0; i < nums; i++)
        cin >> min[i] >> max[i];
    bool reverse = false;
    for (int j = 0; j < nums; j++){
        if (max[j] < min[j]){
            swap(max[j], min[j]);
            reverse = true;
        }
        /*int edge = min[j];
        if (sqrt(max[j]) > edge)
            edge = int(sqrt(max[j]));*/
        for (int i = 2; i <= min[j] && i <= max[j];){
            if (max[j] % i == 0 && min[j] % i == 0){
                max[j] /= i;
                min[j] /= i;
                i = 2;
            }
            else
                i++;
        }
        if (max[j] == 2 && min[j] == 2){
            max[j] = 1;
            min[j] = 1;
        }
        if(reverse)
            swap(min[j], max[j]);
        //int res1 = min[j], res2 = max[j];
        cout << min[j] << "/" << max[j] << endl;
        //cout << "\n";
        reverse = false;
    }
    return 0;
    //res = [4/7, 73/37, 6/1]
}
