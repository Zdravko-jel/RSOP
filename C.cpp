#include <iostream>
#include <vector>

using namespace std;

// Floyed Warshall method

vector<int> maxPathBetweenColors(int n, int numColors, vector<vector<int>>& adj, vector<int>& colors) {
	vector<int> ans;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, -1));
	for (int i = 0; i < adj.size(); i++)
	{
		matrix[i][i] = 0;

		for (auto it: adj[i]) {
			matrix[i][it] = 1;
			matrix[it][i] = 1;
		}
	}

	int n = matrix.size();

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = (matrix[i][j] > matrix[i][k] + matrix[k][j]) ? matrix[i][j] : matrix[i][k] + matrix[k][j];
			}
		}
	}

	for (int i = 1; i < numColors + 1; i++)
	{
		int curr_sum = -1;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (matrix[j][k] > curr_sum && j != k && colors[j] == colors[k])
				{
					curr_sum = matrix[j][k];
				}
			}
		}

		ans.push_back(curr_sum);
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

		vector<vector<int>> adj(n+1);
		vector<int> colors(n+1);

		int a, b;
		cin >> a >> b;

		colors[1] = b;

		for (int i = 1; i < n; i++) {
			int parent, color;
			cin >> parent >> color;

			colors[i + 1] = color;
			adj[parent].push_back(i + 1);
			adj[i + 1].push_back(parent);
		}

		vector<int> res = maxPathBetweenColors(n, k, adj, colors);

		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << endl;
		}
	}

	return 0;
}