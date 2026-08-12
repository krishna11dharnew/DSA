class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        // STATE:
        // dp[i][j] = first i coins se amount j banane ke liye
        // minimum number of coins
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));

        // BASE CASE:
        // Amount 0 banane ke liye 0 coins chahiye
        for(int i=0;i<=n;i++)
            dp[i][0]=0;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {

                // Current coin use kar sakte hain
                if(coins[i-1]<=j) {

                    // NOT TAKE:
                    // Current coin nahi liya
                    // dp[i-1][j]
                    //
                    // TAKE:
                    // Current coin liya -> +1 coin
                    // Remaining amount = j-coins[i-1]
                    //
                    // Unbounded:
                    // Same coin dobara use kar sakte hain,
                    // isliye dp[i][...] use kiya
                    dp[i][j]=min(
                        dp[i-1][j],
                        1+dp[i][j-coins[i-1]]
                    );
                }
                else {

                    // Coin ka value j se bada hai,
                    // isliye current coin nahi le sakte
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        // Agar amount banana possible nahi hai
        if(dp[n][amount]>=1e9)
            return -1;

        return dp[n][amount];
    }
};