#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct tree {
    tree(int num) {
        info = num;
        left = nullptr;
        right = nullptr;
        h = 1;
    }
    int info;
    tree* left = nullptr;
    tree* right = nullptr;
    int h;
};
tree* intree(tree* tr, int& number) {
    if (tr == nullptr) {
        return new tree(number);
    }
    if (tr->info > number) {
        tr->left = intree(tr->left, number);
    }
    if (tr->info < number) {
        tr->right = intree(tr->right, number);
    }
    if (tr->left != nullptr && tr->right != nullptr) {
        tr->h = max(max(1, tr->right->h), max(tr->left->h, 1)) + 1;
        return tr;
    }
    if (tr->left == nullptr && tr->right != nullptr) {
        tr->h = tr->right->h + 1;
    }
    if (tr->left != nullptr && tr->right == nullptr) {
        tr->h = tr->left->h + 1;
    }
    return tr;
}
void preordered(tree* tr) {
    if (tr == nullptr) {
        return;
    }
    std::cout << tr->info << "\n";
    preordered(tr->left);
    preordered(tr->right);
}
tree* minValueNode(tree* node) {
    tree* current = node;

    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}
tree* removeNode(tree* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->info) {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->info) {
        root->right = removeNode(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            tree* temp = root->right;
            return temp;
        }
        else if (root->right == nullptr) {
            tree* temp = root->left;
            return temp;
        }


        tree* temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = removeNode(root->right, temp->info);
    }
    return root;
}

void search(tree* root, int level, int& need, std::vector<int>& vec) {
    if (root == nullptr) {
        return;
    }
    if (level == need) {
        if (root->left != nullptr && root->right != nullptr && root->left->h == root->right->h) {
            vec.push_back(root->info);
        }
        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(root->info);
        }
    }
    search(root->left, level + 1, need, vec);
    search(root->right, level + 1, need, vec);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int del;
    int number;
    tree* root = nullptr;
    while (std::cin >> number) {
        root = intree(root, number);
    }
    if (root == nullptr) {
        return 0;
    }
    int level = root->h / 2 + 1;
    std::vector<int> vec;
    search(root, 1, level, vec);
    if (vec.size() % 2 == 0) {
        preordered(root);
        return 0;
    }
    std::sort(vec.begin(), vec.end());
    int res = vec[(int)(vec.size() + 1) / 2 - 1];
    root = removeNode(root, res);
    preordered(root);
    return 0;
}