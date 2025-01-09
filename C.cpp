#include <iostream>
#include <vector>
#include <queue>

using namespace std;



// Floyed Warshall method

vector<int> maxPathBetweenColors(int n, vector<vector<int>>& adj, vector<int>& colors, vector<int>& sources) {
	vector<int> ans;

	for (auto it : sources) {
		vector<int> vis1(n + 1);
		queue<pair<int, int>> qu;
		int max_dist = 0;
		qu.push({ it, 0 });

		while (!qu.empty()) {
			int node = qu.front().first;
			int path = qu.front().second;
			qu.pop();

			vis1[node] = 1;

			if (colors[node] == colors[it]) {
				max_dist = max(max_dist, path);
			}

			for (auto at : adj[node]) {
				if (!vis1[at])
				{
					qu.push({ at, path + 1 });
				}
			}
		}

		ans.push_back(max_dist);
	}

	return ans;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<vector<int>> adj(n + 1);
		vector<int> sources(k);
		vector<int> colors(n + 1);

		int a , b;
		cin >> a >> b;

		sources[b - 1] = a + 1;
		colors[a + 1] = b;

		for (int i = 1; i < n; i++) {
			int parent, color;
			cin >> parent >> color;

			if (sources[color - 1] < i + 1)
			{
				sources[color - 1] = i + 1;
			}

			colors[i + 1] = color;

			adj[parent].push_back(i + 1);
			adj[i + 1].push_back(parent);
		}

		vector<int> res = maxPathBetweenColors(n, adj, colors, sources);

		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << endl;
		}
	}

	return 0;
}