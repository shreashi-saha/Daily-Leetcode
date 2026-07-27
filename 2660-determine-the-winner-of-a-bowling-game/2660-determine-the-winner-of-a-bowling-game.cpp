class Solution {
public:
    int score(vector<int>& rolls)
    {
        int total = 0;
        for(int i=0;i<rolls.size();i++)
        {
            if((i>=1 && rolls[i-1]==10) || (i>=2 && rolls[i-2]==10))
            {
                total += 2*rolls[i];
            }
            else
            {
                total+=rolls[i];
            }
        }
        return total;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = score(player1);
        int s2 = score(player2);

        if(s1>s2) return 1;
        if(s2>s1) return 2;
        return 0;
    }
};