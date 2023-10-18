#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int MAX_N = 50;
const int MAX_F = 50;

int C[MAX_F][MAX_N][MAX_N];
int diff[MAX_F][MAX_F];
int dp[MAX_N][MAX_F];

int main()
{
    int F, L, T, N, M;
    cin >> F >> L >> T >> N >> M;

    for (int i = 1; i <= F; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> C[i][j][k];
            }
        }
    }

    for (int i = 1; i <= F; i++)
    {
        for (int j = 1; j <= F; j++)
        {
            int cnt = 0;
            for (int x = 0; x < N; x++)
            {
                for (int y = 0; y < M; y++)
                {
                    if (C[i][x][y] != C[j][x][y])
                    {
                        cnt++;
                    }
                }
            }
            diff[i][j] = cnt * cnt;
        }
    }

    for (int i = 1; i <= L; i++)
    {
        int last;
        cin >> last;
        last--;

        for (int j = 1; j <= F; j++)
        {
            dp[i][j] = INF;
            for (int k = 1; k <= F; k++)
            {
                if (k != last)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + diff[k][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int j = 1; j <= F; j++)
    {
        ans = min(ans, dp[L][j]);
    }

    cout << ans << endl;
    return 0;
}
