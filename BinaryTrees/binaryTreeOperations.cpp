#include<iostream>
#include<vector>


using namespace std;


struct node {
	
	int key_value;
	node *left;
	node *right;
};

class btree {
	
	public:
		btree();
		~btree();
		
		void insert(int key);
		node *search(int key);
		void destroy_tree();
		node *getRoot();
	private:
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		void destroy_tree(node *leaf);
		
		
		node *root;
		
		
};

btree::btree(){
	root = NULL;
}

btree::~btree(){
		destroy_tree();
}

node *btree::getRoot(){
		return root;
}

void btree::insert(int key){
	
	if(root != NULL)
		insert(key,root);
	else {
		root = new node();
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::insert(int key,node *leaf){

		if(leaf->key_value > key){
			if(leaf->left != NULL)
				insert(key,leaf->left);
			else {
				leaf->left = new node();
				leaf->left->key_value = key;
				leaf->left->left = NULL;
				leaf->left->left = NULL;
			}
		} else {
			if(leaf->right != NULL)
				insert(key,leaf->right);
			else {
				leaf->right = new node();
				leaf->right->key_value = key;
				leaf->right->left = NULL;
				leaf->right->right = NULL;
			}
			
		}
}

void btree::destroy_tree(){
	
	if(root!=NULL)
		destroy_tree(root);
	cout<<"b-tree destroyed"<<endl;
}

node *btree::search(int key){
	if(root!=NULL)
		return search(key,root);
	return NULL;
}

node *btree::search(int key, node *leaf){
	if(leaf!=NULL){
		if(leaf->key_value == key)
			return leaf;
		else if(leaf->key_value > key)
			return search(key,leaf->left);
		else 
			return search(key,leaf->right);
	}
	
	return NULL;
}

void btree::destroy_tree(node *leaf){
	if(leaf!=NULL){
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete(leaf);
	}
}

void inOrder(node *leaf){
	if(leaf!=NULL){
		inOrder(leaf->left);
		cout<<leaf->key_value<<" ";
		inOrder(leaf->right);
	}
}


// function to get height of tree
int getHeight(node *leaf){

		if(leaf!=NULL)
			return max(getHeight(leaf->left),getHeight(leaf->right))+1;
		else
			return 0;
}

// function to test the any given tree is balanced or not;
bool isBalanced(node *root){
	if(root == NULL)
		return true;
	if(abs(getHeight(root->left)-getHeight(root->right))>1){
		cout<<"unbalanced at: "<<root->key_value<<endl;
		return false;
	}
		
	
	if(!isBalanced(root->left) || !isBalanced(root->right)){
		//cout<<"unbalanced at: "<<root->key_value<<endl;
		return false;
	}
	
	return true;
}

// efficient implementation to check tree is balanced or not
// time O(N) and space O(H) where N is no.of nodes and H is height of the tree.
// returns -1 if tree is not balanced or returns height of the tree
int isBalanced_efficient(node *root){
	if(root==NULL)
		return 0;
	int leftH,rightH;
	leftH = isBalanced_efficient(root->left);
	rightH = isBalanced_efficient(root->right);
	if(leftH == -1 || rightH == -1)
		return -1;
	else if(abs(leftH-rightH) > 1)
		return -1;
	else 
		return max(leftH,rightH)+1;
		

}

void construct(btree *tree,vector<int> &a,int start,int end){
		
		if(start > end)
			return;

		int mid = (start+end)/2;
		tree->insert(a[mid]);
		construct(tree,a,start,mid-1);
		construct(tree,a,mid+1,end);
}

int main(){
	
		btree *tree = new btree();
		int key;
		
		/*tree->insert(4);
		tree->insert(2);
		tree->insert(1);
		tree->insert(3);
		tree->insert(6);
		tree->insert(5);
		tree->insert(7);*/
		
		/*tree->insert(10);
		tree->insert(5);
		tree->insert(15);
		tree->insert(4);
		tree->insert(9);
		tree->insert(13);
		tree->insert(17);
		tree->insert(3);
		tree->insert(11);
		tree->insert(14);
		tree->insert(19);
		tree->insert(2);
		tree->insert(12);
		//tree->insert(1);*/
		
		vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);
		a.push_back(9);
		a.push_back(10);
		a.push_back(11);
		a.push_back(12);
		a.push_back(13);
		a.push_back(14);
		a.push_back(15);
		a.push_back(16);
		
		construct(tree,a,0,15);
		
		
		inOrder(tree->getRoot());
		cout<<endl;
		cout<<"Enter key value:";
		cin>>key;
		
		node *searchedNode = tree->search(key);
		
		if(searchedNode != NULL){
			
				cout<<"searched value:"<<searchedNode->key_value<<endl;
				if(searchedNode->left != NULL)
					cout<<"its left value: "<< searchedNode->left->key_value<<endl;
				if(searchedNode->right != NULL)
					cout<<"its right value: "<< searchedNode->right->key_value<<endl;
		} else {
		
				cout<<"given key does not exists"<<endl;
		}
		
		
		cout<<"is tree balanced: "<<isBalanced_efficient(tree->getRoot())<<endl;
		
		tree->destroy_tree();

		return 0;
}
