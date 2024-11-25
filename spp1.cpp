#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;


int main() {
    
    vector<int> weight = {2,1,3,2,1};
    vector<int> value = {12,10,20,15,20};

    int w = 5 + 1;
    int k = weight.size() + 1;

    int dp[k][w];   //k: 为件数，w: 为背包的容量
    for (int i = 0; i < w; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j < w; j++)
        {
            dp[i][j] = dp[i - 1][j]; 
            //捡 or 不捡 
            if (j >= weight[i])
            {
                dp[i][j] = max(dp[i][j],value[i] + dp[i - 1][j - weight[i]]);
            }
            
        }
        
    }
    
    cout<<"背包的最大价值为：" <<dp[k - 1][w - 1]<<endl;
    
    return 0;
}