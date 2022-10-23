#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair <double, double> delta[1010];
int main(){
    bool flag = true;// flag=false dff in island and mainland is 2 further.
    int nums = 0;//numbers of radar.
    int islands, radars;
    cin>>islands>>radars;//get n and d;

    double dff;
    for(int i = 0; i < islands && flag; i++){
        int x_pos, y_pos;
        cin>>x_pos>>y_pos;//get position
        if(y_pos > radars)
            flag = false;//distance out of the radar.
        dff = sqrt(radars * radars - y_pos * y_pos);
        delta[i] = {x_pos - dff, x_pos + dff};//delta position
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    sort(delta, delta + islands);
    double max = 1e8;
    for(int i = islands - 1; i >= 0; i--){
        if(max > delta[i].second){
            nums++;
            max = delta[i].first;
        }
    }
    cout << nums << endl;
    return 0;
}
