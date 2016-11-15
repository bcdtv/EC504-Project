#include <iostream>

using namespace std ;


struct BstNode
{
	int data ;
	BstNode* left ;
	BstNode* right ;

};



BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;	
	newNode->left= NULL ;
    newNode->right= NULL ;
    return newNode ;

}


BstNode* Insert(BstNode* root , int data)
{
	if(root==NULL){
		root = GetNewNode(data);
	}                                                      
		else if (data <= root->data){
			root->left = Insert(root-> left, data);
		}
		else {
			root->right = Insert(root->right , data);
		}
	
   return root ;
	}




int main()
{

BstNode* root ;
root = NULL ;

root = Insert(root , 10);
root = Insert(root , 20);
root = Insert(root, 5000);
root = Insert(root, 6000);
//rootPtr = NULL ;


}