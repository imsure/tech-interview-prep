#include "../common.hpp"

class Solution {
public:
  int calPoints(vector<string>& ops) {
    int sum = 0, cur_score;
    int last_valid1 = -30001, last_valid2 = -30001, last_valid3 = -30001;

    for (int i = 0; i < ops.size(); ++i) {
      if (isdigit(ops[i][0]) || ops[i][0] == '-') {
        cur_score = stoi(ops[i]);
        sum += cur_score;
        last_valid3 = last_valid2;
        last_valid2 = last_valid1;
        last_valid1 = cur_score;
      } else if (ops[i][0] == '+') {
        cur_score = last_valid1 + last_valid2;
        sum += cur_score;
        last_valid3 = last_valid2;
        last_valid2 = last_valid1;
        last_valid1 = cur_score;
      } else if (ops[i][0] == 'D') {
        cur_score = last_valid1 * 2;
        sum += cur_score;
        last_valid3 = last_valid2;
        last_valid2 = last_valid1;
        last_valid1 = cur_score;
      } else if (ops[i][0] == 'C') {
        sum -= last_valid1;
        last_valid1 = last_valid2;
        last_valid2 = last_valid3;
        last_valid3 = -30001;
      }
      //cout << "cur sum: " << sum << endl;
    }

    return sum;
  }
};

int main()
{
  //vector<string> ops1 {"5","2","C","D","+"};
  //vector<string> ops2 {"5","-2","4","C","D","9","+","+"};
  vector<string> ops3 {"15483","-20523","C","C","9061","26083","+","C","4702","+","D","10260","-525","C","+","15023","-20005","-1647","C","-12853","20706","D","-21983","24892","10570","D","1215","D","D","+","3854","20505","C","D","-18850","-2170","27914","-26175","+","3188","+","+","21804","D","+","-847","D","26184","14945","C","D","+","+","13795","+","1839","15755","2627","-2090","C","C","29743","24319","D","-22624","20374","+","D","2631","+","7296","-5109","9454","-10466","D","C","+","17555","+","12144","D","16710","27969","22863","D","8521","+","D","C","-25486","-1137","9782","25633","-12031","-11248","+","C","-13559","D","D"};
  vector<string> ops4 {"15483","-20523","C","C","9061","26083","+","C","4702","+","D","10260","-525","C","+","15023","-20005","-1647","C","-12853","20706","D","-21983","24892","10570","D","1215","D","D","+","3854","20505","C","D","-18850","-2170","27914","-26175","+","3188","+","+","21804","D","+","-847","D","26184","14945","C","D","+","+","13795","+","1839","15755","2627","-2090","C","C","29743","24319","D","-22624","20374","+","D","2631","+","7296","-5109","9454","-10466","D","C","+","17555","+","12144","D","16710","27969","22863","D","8521","+","D","C","-25486","-1137","9782","25633","-12031","-11248","+","C","-13559","D","D"};
  Solution sol;
  //cout << sol.calPoints(ops1) << endl;
  //cout << sol.calPoints(ops2) << endl;
  cout << sol.calPoints(ops3) << endl;
  cout << sol.calPoints(ops4) << endl;
}
