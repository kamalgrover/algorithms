//Height of a binary Tree
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data = 0 ;
	struct Node* left = NULL;
	struct Node* right = NULL;
};

Node* createBinaryTree(std::vector<int>& input)
{
	int i = 0;
	int size = input.size();
	
	// cout << size << endl;

	Node* root = new Node;
	root->data = input[i++];
	
	std::queue<Node*> q;
	q.push(root);

	while( i < size)
	{
		Node* node = q.front(); q.pop();

		Node *temp = new Node ;
		temp->data = input[i++];
		node->left = temp;
		
		q.push(temp);
		
		if ( i == size )
		{
			 break;
		}
		else
		{
			temp = new Node;
			temp->data = input[i++];
			node->right = temp;
			q.push(temp);	
		}
	}
	//cout << "q.size() " << q.size() << endl;
	return root;
}

void printInorder(Node* root)
{

	if(root)
	{
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);

	}
}

int height(Node* root)
{
	if(root)
	{
		return std::max(height(root->left),height(root->right)) + 1;
	}
	return 0;
}

void printPreorder(Node* root)
{
	if(root)
	{
		cout << root->data << " ";
		printPreorder(root->left);
		printPreorder(root->right);

	}
}

void printLevelorder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* node = q.front();

		cout << node->data<< " "; 
		
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);

		q.pop();
	}
}

int main()
{
	std::vector<int> v;
	int N ;
	int number ;
	cout << "Enter Number of Elements"<< endl;
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		cin >> number;
		v.push_back(number);
	}
	
	// for (int i = 0 ; i < v.size() ; i++)
	// {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;
	if (v.size())
	{
		Node* root = createBinaryTree(v);

		cout << "Inorder " ; printInorder(root) ; cout << endl;
		cout << "Preorder " ; printPreorder(root); cout << endl;
		cout << "Levelorder " ; printLevelorder(root); cout << endl;
		
		cout << "Height " <<  height(root) - 1 <<  endl;
	}
	
}