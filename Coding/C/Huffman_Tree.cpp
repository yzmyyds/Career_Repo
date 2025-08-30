#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Huffman_Node {
    public:
    char c;
    int freq;
    Huffman_Node* left, *right;
    Huffman_Node(char character, int frequency){
        c=character;
        freq=frequency;
        left=nullptr;
        right=nullptr;
    }
}; 
vector<Huffman_Node*>sort_vec(vector<Huffman_Node*> vec){
    for (int i=0; i<vec.size()-1;i++){
        for (int j=0; j<vec.size()-i-1;j++){
            if (vec[j]->freq>vec[j+1]->freq){
                swap(vec[j],vec[j+1]);
            }
        }
    }
    return vec;
}
// void print_tree(Huffman_Node* root){
//     if (root==nullptr) return;
//     cout<<root->c<<" "<<root->freq<<endl;
//     print_tree(root->left);
//     print_tree(root->right);
// }

void print_tree(Huffman_Node* root, int depth = 0) {
    if (root == nullptr) return;

    // 打印缩进（根据深度）
    for (int i = 0; i < depth; i++) {
        cout << "   ";
    }

    if (root->c == '\0') {
        cout << "* (" << root->freq << ")" << endl;  // 内部节点
    } else {
        cout << root->c << " (" << root->freq << ")" << endl; // 叶子节点
    }

    // 递归打印子树
    print_tree(root->left, depth + 1);
    print_tree(root->right, depth + 1);
}

int main() {
    cout<<"Enter a string"<<endl;
    string s;
    int n;
    getline(cin,s);
    n=s.length();
    unordered_map<char,int> freq_map;
    vector<Huffman_Node*> huff_vec;
    for (char c: s){
        freq_map[c]++;
    }
    for (auto p: freq_map) {
        cout<<p.first<<" "<<p.second<<endl;
        Huffman_Node* node=new Huffman_Node(p.first,p.second);
        huff_vec.push_back(node);
    }
    huff_vec=sort_vec(huff_vec);
    // print sorted vector
    cout<<"Sorted vector:"<<endl;
    for (Huffman_Node* node: huff_vec){
        cout<<node->c<<" "<<node->freq<<endl;
    }
    while (huff_vec.size()>1){
        int root_freq=huff_vec[0]->freq+huff_vec[1]->freq;
        Huffman_Node* root=new Huffman_Node('\0',root_freq);
        root->left=huff_vec[0];
        root->right=huff_vec[1];
        huff_vec.erase(huff_vec.begin());
        huff_vec.erase(huff_vec.begin());
        huff_vec.push_back(root);
        huff_vec=sort_vec(huff_vec);
    }
    print_tree(huff_vec[0]);
    return 0;
}