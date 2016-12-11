#ifndef BST_H
#define BST_H

class BST {
    // public methods
public:
    BST();
    BST(int value);
    BST(const BST& other);
    ~BST();
    BST& operator=(const BST& other);
    int successor(int value);
    int predecessor(int value);
    void insert(int value);
    void remove(int value);
    int min();
    int max();
    void display();
    bool valid();

    // private fields
private:
    int value;
    int count;
    BST* left;
    BST* right;

    // private methods
private:
    void copy_helper(BST* current, const BST& other);
    void insert_helper(BST* root, int value);
    BST* remove_helper(BST* root, int value);
    int min_helper(BST* root);
    int max_helper(BST* root);
    void display_helper(BST* root);
    bool valid_helper(BST* root);
    BST* findsuccessorbelow(BST* root);
};
#endif
