#ifndef BST_H
#define BST_H

class BST{
  // public methods
  public:
    BST();
    BST(int value);
    int successor(int value);
    int predecessor(int value);
    void insert(int value); 
    void remove(int value);
    int min();

  // private fields
  private:
    int value;
    BST* left;
    BST* right;

  // private methods
  private:
    int successor_helper(BST* root, int value);
    int predecessor_helper(BST* root, int value);
    void insert_helper(BST* root, int value);
    void remove_helper(BST* root, int value);
    int min_helper(BST* root);
};






#endif
