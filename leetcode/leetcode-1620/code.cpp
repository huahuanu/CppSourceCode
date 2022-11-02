class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        if (towers.size() == 1){
            if (towers[0][2] == 0)
                return {0, 0};
            else{
                return {towers[0][0], towers[0][1]};
            }
        }

        else{
            int min_x = towers[0][0], min_y = towers[0][1], max_x = towers[0][0], max_y = towers[0][1];
            for (int i = 1; i < towers.size(); i++){
                if (min_x > towers[i][0])
                    min_x = towers[i][0];
                if (min_y > towers[i][1])
                    min_y = towers[i][1];
                if (max_x < towers[i][0])
                    max_x = towers[i][0];
                if (max_y < towers[i][1])
                    max_y = towers[i][1];
            }

            int index_x = towers[0][0], index_y = towers[0][1];
            int max = 0;
            int signal;
            double distance;
            min_x = min_x - radius < 0? 0: min_x - radius;
            max_x += radius;
            min_y = min_y - radius < 0? 0: min_y - radius;
            max_y += radius;
            for (int i = min_x - radius; i< max_x; i++){
                for (int j = min_y; j < max_y; j++){
                    signal = 0;
                    for (int k = 0; k < towers.size(); k++){
                        distance = sqrt(pow(i - towers[k][0], 2) + pow(j - towers[k][1], 2));
                        if (distance <= radius)
                            signal +=  int(double(towers[k][2]) / (1 + distance));
                    }
                    if (signal > max) {
                        max = signal;
                        index_x = i;
                        index_y = j;
                    }

                }
            }
            return {index_x, index_y};
        }
    }
};
