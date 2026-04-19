/*
Problem: P1087 FBI Tree
Source: https://www.luogu.com.cn/problem/P1087
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: binary-tree
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	char c;
	TreeNode(char c):c(c),left(nullptr),right(nullptr){}
};

void postorder(TreeNode* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->c;
}

int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	vector<vector<TreeNode*>>layer(n + 1);
	for (int i = 0; i < s.size(); i++) {
		char c = (s[i] == '1' ? 'I' : 'B');
		TreeNode* temp = new TreeNode(c);
		layer[0].push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < layer[i - 1].size()- 1; j += 2) {
			char c1 = layer[i - 1][j]->c;
			char c2 = layer[i - 1][j + 1]->c;
			char c;
			if (c1 == c2) c = c1;
			else c = 'F';
			TreeNode* temp = new TreeNode(c);
			temp->left = layer[i - 1][j];
			temp->right = layer[i - 1][j + 1];
			layer[i].push_back(temp);
		}
	}
	postorder(layer[n][0]);
	return 0;
}

