#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int del;
    cin >> del;
    int number;
    tree* root = nullptr;
    while (std::cin >> number) {
        if (number == 0) {
            break;
        }
        root = intree(root, number);
    }
    root = removeNode(root, del);

    preordered(root);

    return 0;
}