#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> cost(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cost[i];
    }

    int Q;
    cin >> Q;

    vector<int> dissatisfaction(N * N, 0);
    vector<int> max_costs(N, 0);
    vector<int> cost_diff_count(N, 1);

    long long total_cost = 0;

    for (int i = 0; i < Q; ++i)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int total_dissatisfaction = 0;
            int prev_group = 0;
            int group;

            for (int j = 0; j < 2 * N; ++j)
            {
                cin >> group;

                if (j > 0)
                {
                    if (group != prev_group)
                    {
                        if (dissatisfaction[prev_group * N + group] >= K)
                        {
                            total_cost = -1;
                            break; // 불만도가 K 이상이면 더 이상 진행하지 않음
                        }
                        dissatisfaction[prev_group * N + group]++;
                        dissatisfaction[group * N + prev_group]++;
                    }
                }

                total_dissatisfaction += dissatisfaction[group * N + group];
                prev_group = group;
            }

            if (total_cost != -1)
            {
                total_cost += total_dissatisfaction;
            }
        }
        else if (query_type == 2)
        {
            int max_possible_cost = 0;
            vector<int> group_counts(N, 0);

            for (int j = 0; j < 2 * N; ++j)
            {
                int group;
                cin >> group;
                max_possible_cost += max_costs[group - 1];
                group_counts[group - 1]++;
            }

            for (int j = 0; j < N; ++j)
            {
                if (group_counts[j] > cost_diff_count[j])
                {
                    max_possible_cost -= (group_counts[j] - cost_diff_count[j]) * cost[j];
                }
            }

            cout << max_possible_cost << endl;
        }
        else if (query_type == 3)
        {
            int group, cost_increase;
            cin >> group >> cost_increase;
            group--;

            int prev_max_cost = max_costs[group];

            max_costs[group] += cost_increase;
            cost_diff_count[group]++;

            if (max_costs[group] > prev_max_cost)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (cost[j] > cost[group] && max_costs[j] >= max_costs[group])
                    {
                        max_costs[j] = max_costs[group];
                        cost_diff_count[j]++;
                    }
                }
            }
        }
    }

    cout << total_cost << endl;

    return 0;
}
