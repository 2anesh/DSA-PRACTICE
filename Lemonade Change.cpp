class Solution {

  public:

    bool lemonadeChange(int N, vector<int> &bills) {

        

        vector<int>temp(3,0);

        

        for(int i = 0; i < N; i++){

            if(bills[i] == 5){

                temp[0]++;

            }

            else if(bills[i] == 10){

                if(temp[0] == 0)return false;

                temp[0]--;

                temp[1]++;

            }

            else{

                if((temp[1] == 0 && (temp[0] == 0 || temp[0] < 3)) || (temp[0] == 0))return false;

                else if(temp[1] == 0 && temp[0] >= 3){

                    temp[0] -= 3;

                }

                else if(temp[1] != 0 && temp[0] != 0){

                    temp[1]--;

                    temp[0]--;

                }

                temp[2]++;

            }

        }

        return true;

    }

};
