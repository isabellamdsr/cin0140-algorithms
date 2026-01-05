#include <iostream>
using namespace std;

struct Node {
    int key;
    int val;
    Node* esq;
    Node* dir;
    int height;

    Node(int k, int v) {
        key = k;
        val = v;
        esq = dir = nullptr;
        height = 0;
    }
};

int height(Node* n) {
    return n == nullptr ? -1 : n->height;
}

int getBalance(Node* n) {
    if (n == nullptr) return 0;
    return height(n->esq) - height(n->dir);
}

Node* rightRotate(Node* y) {
    Node* x = y->esq;
    Node* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->height = 1 + max(height(y->esq), height(y->dir));
    x->height = 1 + max(height(x->esq), height(x->dir));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->dir;
    Node* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->height = 1 + max(height(x->esq), height(x->dir));
    y->height = 1 + max(height(y->esq), height(y->dir));

    return y;
}

// ===== Inserção AVL =====
Node* insertHelp(Node* rt, int k, int value) {
    if (rt == nullptr)
        return new Node(k, value);

    if (k < rt->key)
        rt->esq = insertHelp(rt->esq, k, value);
    else if (k >= rt->key)
        rt->dir = insertHelp(rt->dir, k, value);

    rt->height = 1 + max(height(rt->esq), height(rt->dir));

    int balance = getBalance(rt);

    // Caso Esquerda-Esquerda
    if (balance > 1 && k < rt->esq->key)
        return rightRotate(rt);

    // Caso Direita-Direita
    if (balance < -1 && k > rt->dir->key)
        return leftRotate(rt);

    // Caso Esquerda-Direita
    if (balance > 1 && k > rt->esq->key) {
        rt->esq = leftRotate(rt->esq);
        return rightRotate(rt);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && k < rt->dir->key) {
        rt->dir = rightRotate(rt->dir);
        return leftRotate(rt);
    }

    return rt;
}

int findHelp(Node* root, int k) {
    if (root == nullptr) return -1;

    if (k < root->key)
        return findHelp(root->esq, k);
    else if (k > root->key)
        return findHelp(root->dir, k);
    else
        return root->val;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->esq);
        cout << root->key << " ";
        inorder(root->dir);
    }
}

struct AVL {
    Node* root;
    int node_count;

    AVL() {
        root = nullptr;
        node_count = 0;
    }

    void insert(int k, int v) {
        root = insertHelp(root, k, v);
        node_count++;
    }

    int find(int k) {
        return findHelp(root, k);
    }

    void print() {
        inorder(root);
        cout << endl;
    }
};