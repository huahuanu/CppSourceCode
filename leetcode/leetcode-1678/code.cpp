class Solution {
public:
    string interpret(string command) {
        int len = command.size();
        string y = "";
        for (int i = 0; i < len; i++){
            if (command[i] == 'G')
                y.append("G");
            if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    i += 1;
                    y.append("o");
                }
                else {
                    i += 3;
                    y.append("al");
                }
            }
        }
        return y;
    }
};
