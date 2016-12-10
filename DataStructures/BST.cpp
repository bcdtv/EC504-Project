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


int FindMin (BstNode* root)
{
	if (root == NULL)
	{
		cout << "Tree is empty"<<endl ;
		return -1 ;
	}
    else 
    	if (root->left == NULL )
    	{
    		return root->data;
    	}

    return FindMin(root->left);

}



int main()
{

BstNode* root ;
root = NULL ;




}
