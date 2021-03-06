
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
#define SIZE 26
using namespace std;

// to map each character its huffman value
map<char, string> codes;

// to store the frequency of character of the input data
map<char, int> freq;

// A Huffman tree node
struct MinHeapNode
{
	char data;			 // One of the input characters
	int freq;			 // Frequency of the character
	MinHeapNode *left, *right; // Left and right child

	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// utility function for the priority queue
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

// utility function to print characters along with
// there huffman value
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// function to build the Huffman tree and store it
// in minHeap
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

// utility function to store map each character with its
// frequency in input string
void calcFreq(string str, int n)
{
	for (int i=0; i<str.size(); i++)
		freq[str[i]]++;


}



void printCharWithFreq(string str)
{
    // size of the string 'str'
    int n = str.size();

    // 'freq[]' implemented as hash table
    int freq[SIZE];

    // initialize all elements of freq[] to 0
    memset(freq, 0, sizeof(freq));

    // accumulate frequency of each character in 'str'
    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    // traverse 'str' from left to right
    cout<<"\nCharacters with their frequencies:\n";
    for (int i = 0; i < n; i++) {

        // if frequency of character str[i] is not
        // equal to 0
        if (freq[str[i] - 'a'] != 0) {

            // print the character along with its
            // frequency
            cout << str[i] <<" : "<< freq[str[i] - 'a'] << "\n";

            // update frequency of str[i] to 0 so
            // that the same character is not printed
            // again
            freq[str[i] - 'a'] = 0;
        }
    }
}


// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string decode_file(struct MinHeapNode* root, string s)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == '0')
		curr = curr->left;
		else
		curr = curr->right;

		// reached leaf node
		if (curr->left==NULL and curr->right==NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	// cout<<ans<<endl;
	return ans+'\0';
}

// Driver program to test above functions
int main()
{
	string str, first, last;
	cout<<"*** Huffman Coding ***";
	cout<<"\nEnter your string:\n";
	cin>>first;
	cin>>last;
    str = first + " " + last;
	string encodedString, decodedString;
	calcFreq(str, str.length());
	HuffmanCodes(str.length());


	printCharWithFreq(str);


	cout << "Character With there Code:\n";
	for (auto v=codes.begin(); v!=codes.end(); v++)
		cout << v->first <<' ' << v->second << endl;

	for (auto i: str)
		encodedString+= codes[i];
	cout<<"*** Encoded Huffman Code for the given data ***\n";
	cout << "\nEncoded Huffman data:\n" << encodedString << endl;

	decodedString = decode_file(minHeap.top(), encodedString);
	cout<<"*** Decoded Huffman Code for the given data ***\n";
	cout << "\nDecoded Huffman Data:\n" << decodedString << endl;
	return 0;
}
