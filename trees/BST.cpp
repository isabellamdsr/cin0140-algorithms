#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int key;
    int val;
    BSTNode* esq;
    BSTNode* dir;

    BSTNode(int k, int value) {
        key = k;
        val = value;
        esq = nullptr;
        dir = nullptr;
    }
};

struct BST {
    BSTNode* root;
    int node_count;

    BST() {
        root = nullptr;
        node_count = 0;
    }
};


BSTNode* insertHelp(BSTNode* root, int k, int value) {
    if (root == nullptr) return new BSTNode(k, value);

    if (root->key > k)
        root->esq = insertHelp(root->esq, k, value);
    else
        root->dir = insertHelp(root->dir, k, value);

    return root;
}

int findHelp(BSTNode* root, int k) {
    if (root == nullptr) return -1; 

    if (root->key > k)
        return findHelp(root->esq, k);
    else if (root->key == k)
        return root->val;
    else
        return findHelp(root->dir, k);
}

BSTNode* getMin(BSTNode* root) {
    if (root->esq == nullptr) return root;
    return getMin(root->esq);
}

BSTNode* deleteMin(BSTNode* root) {
    if (root->esq == nullptr) return root->dir;
    root->esq = deleteMin(root->esq);
    return root;
}

BSTNode* removeHelp(BSTNode* root, int k) {
    if (root == nullptr) return nullptr;

    if (root->key > k) {
        root->esq = removeHelp(root->esq, k);
    } else if (root->key < k) {
        root->dir = removeHelp(root->dir, k);
    } else {
        // nó encontrado
        if (root->esq == nullptr) return root->dir;
        else if (root->dir == nullptr) return root->esq;
        else {
            // dois filhos
            BSTNode* temp = getMin(root->dir);
            root->key = temp->key;
            root->val = temp->val;
            root->dir = deleteMin(root->dir);
        }
    }
    return root;
}

void insert(BST &bst, int k, int value) {
    bst.root = insertHelp(bst.root, k, value);
    bst.node_count++;
}

int find(BST &bst, int k) {
    return findHelp(bst.root, k);
}

int removeNode(BST &bst, int k) {
    int val = find(bst, k);
    if (val != -1) {
        bst.root = removeHelp(bst.root, k);
        bst.node_count--;
    }
    return val;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST bst;
}
