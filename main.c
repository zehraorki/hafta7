#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

void search_treasure(struct Node* root, int target, int step) {
    if (root == NULL) {
        printf("Bosuna kazdin!\n");
        return;
    }
    printf("Adim %d: Ziyaret edilen dugum -> %d\n", step, root->val);

    if (root->val == target) {
        printf("Hazine bulundu!\n");
        return;
    }

    if (target < root->val) {
        search_treasure(root->left, target, step + 1);
    }
    else {
        search_treasure(root->right, target, step + 1);
    }
}

int tree_height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

int main() {
    struct Node* root = NULL;

    int hazineler[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(hazineler) / sizeof(hazineler[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, hazineler[i]);
    }
    
    int hedef;
    printf("Aramak istediginiz hazine degerini girin: ");
    scanf("%d", &hedef);

    printf("\nArama Basliyor...\n");
    search_treasure(root, hedef, 1);

    int max_adim = tree_height(root);
    printf("\nBilgi: Hazineyi bulmak icin en kotu durumda (agac yuksekligi) %d adim gerekir.\n", max_adim);

    return 0;
}
