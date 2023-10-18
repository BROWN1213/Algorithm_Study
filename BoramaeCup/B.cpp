#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, A, B, M;
    cin >> N >> A >> B >> M;

    vector<pair<int, int>> tasks(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // dp[i][j][k]: i번째 작업까지 고려하고, j번 평일 작업을 하고, k번 주말 작업을 할 때 얻을 수 있는 최대 가점
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(A + 1, vector<int>(B + 1, -1)));

    dp[0][0][0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= A; ++j)
        {
            for (int k = 0; k <= B; ++k)
            {
                if (dp[i][j][k] != -1)
                {
                    int newScore = dp[i][j][k];
                    if (tasks[i].first * (i % 7 < 5 ? A : B) <= tasks[i].second)
                    {
                        newScore++;
                    }

                    // 현재 작업을 평일에 할 때
                    if (j < A && i % 7 < 5)
                    {
                        dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], newScore);
                    }

                    // 현재 작업을 주말에 할 때
                    if (k < B && i % 7 >= 5)
                    {
                        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], newScore);
                    }

                    // 현재 작업을 안 할 때
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
        }
    }

    // 결과 계산
    int result = -1;
    for (int j = 0; j <= A; ++j)
    {
        for (int k = 0; k <= B; ++k)
        {
            if (dp[N][j][k] == M)
            {
                result = max(result, j + k);
            }
        }
    }

    if (result >= 0)
    {
        cout << result << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
