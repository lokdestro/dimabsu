#include <iostream>
#include <vector>
#include <algorithm>

struct tree {
    tree(int num) {
        info = num;
        left = nullptr;
        right = nullptr;
    }
    int info;
    tree* left = nullptr;
    tree* right = nullptr;
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int number;
    tree* root = nullptr;
    while (std::cin >> number) {
        root = intree(root, number);
    }
    preordered(root);
    return 0;
}