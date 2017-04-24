#include<iostream>
#include<cstdio>
class BinaryTree
{
	public:
		BinaryTree():num(0),left( NULL ), right( NULL ){};
		~BinaryTree(){ 
			if( left != NULL )
				delete[] left;
			if( right != NULL )
				delete[] right;
		};
		BinaryTree* Creat_binarytree(  );
        void Display_binarytree(  );
//		friend ostream&  operator <<( ostream &os, const BinaryTree &a );
	private:
		int   num;
		BinaryTree *left;
		BinaryTree *right;
};
BinaryTree *  BinaryTree::Creat_binarytree(  );
{
	int   temp ;
	cin>>temp;

	if( -1 == temp )
		this = NULL;
	else
	{
		ptr->num = temp ;
		ptr->left = Creat_binarytree( ptr->left );
		ptr->right =  Creat_binarytree( ptr->right );
	}

	return ptr;


};
void BinaryTree::Display_binarytree(  );
{
	while( ptr!= NULL )
	{
		cout<<ptr->num<<"  ";
		Display_binarytree( ptr->left );
		Display_binarytree( ptr->right );

	}

}

int main( int argc, char ** argv )
{
	BinaryTree  *temp = NULL ;
	temp = temp->Creat_binarytree(  );
	temp->Display_binarytree( );





	return 0;
}


