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
int main() {
    cout<<"Enter a string"<<endl;
    string s;
    int n;
    getline(cin,s);
    n=s.length();
    unordered_map<char,int> freq_map;
    for (char c: s){
        freq_map[c]++;
    }
    for (auto p: freq_map) {
        cout << p.first << ": " << p.second << endl;
    }
}