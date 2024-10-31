//
//  main.cpp
//  tree_node_left_right
//
//  Created by Dmytra on 31.10.2024.
//  Copyright © 2024 Dmytra. All rights reserved.
//
// https://www.youtube.com/watch?v=TzrpCF5NliU


#include <iostream>

struct Node {
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
    Node()
        : value(0) {}
    
    explicit Node(int vat)
        : value(vat) {}
};

Node* findNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->value) {
        return findNode(root->left, value);
    } else if (value > root->value) {
        return findNode(root->right, value);
    }
    return root;
}

int getCountList(Node* root) {
if (root == nullptr) {
    return 0;
}
    
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return getCountList(root->left) + getCountList(root->right);
}

int getValuetList(Node* root) {
if (root == nullptr) {
    return 0;
}
    
    if (root->left == nullptr && root->right == nullptr) {
        return root->value;
    }
    return getValuetList(root->left) + getValuetList(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "\n ====== code 19:00 found www.youtube.com/watch?v=TzrpCF5NliU \n";
 
    Node root(10), left(5), right(15);
    root.left = &left;
    root.right = &right;
    Node *result = findNode(&root, 5);
    if (result != nullptr) {
        std::cout << "Is found";
}
 
    std::cout << "\n =====  code 31:00 found www.youtube.com/watch?v=TzrpCF5NliU \n";
    
    std::cout << getCountList(&root) << "\n";
    
    std::cout << "\n =====  code 40:00 found www.youtube.com/watch?v=TzrpCF5NliU \n";
    
    std::cout << getValuetList(&root) << "\n";
    
    return 0;
}
