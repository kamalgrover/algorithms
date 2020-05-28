#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int weight = 0 ;
	bool isEndOf = false;
	Node* child[26];
};
void insert(struct Node** root , string& s)
{
	if ((*root) == NULL)
	{
		(*root) = new Node;
	}
	Node* temp = (*root);
	for (int i = 0 ; i < s.length() ; i++)
	{
		int pos = s[i] - 'a';
		if(!temp->child[pos])
		{
			temp->child[pos] = new Node;
		}
		temp = temp->child[pos];
		temp->weight++;
	}
	temp->isEndOf = true;
}

struct Node* search(struct Node** root , string& s)
{
	struct Node* prefix = NULL;
	struct Node* temp = *root;

	for (int i=0; i<s.length();i++)
	{
		int pos = s[i] - 'a'; 
		if(!temp->child[pos]) 
			return NULL;
		prefix = temp;
		temp = temp->child[pos];
	}
	if(temp->isEndOf)
	{
		return temp;
	} 
		
	return NULL;
}
int countStringsWithPrefix(struct Node** root, string& prefix)
{
	struct Node* temp = *root;

	for (int i=0; i<prefix.length();i++)
	{
		int pos = prefix[i] - 'a'; 
		
		if(!temp->child[pos]) 
			return 0;
		
		temp = temp->child[pos];
			
	}

	return temp->weight;
}

int main ()
{
	int N;
	string s;
	cout << "Enter Number ";
	cin >> N;
	struct Node* root = new Node;
	for (int i=0 ; i<N ; i++)
	{	
		cin >> s;
		insert(&root, s);
	} 
	cout << "Enter Number ";
	cin>>N;
	for (int i=0 ;i<N ; i++)
	{
		cin >> s;
		struct Node* result = search(&root, s);
		if(result)
		{

			cout << "1" << endl;
		}
		else cout << "0" << endl;
		cout << "No of strings with prefix "<< countStringsWithPrefix(&root, s)<<endl;
	}

	return 0;
}