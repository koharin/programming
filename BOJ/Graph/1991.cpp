#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    char left;
    char right;
    //Node(string val1) : data(val1), left(nullptr), right(nullptr) {}
};

vector<Node> tree(26);

void Preorder(char current){
    if(current=='.') return;
    
    cout << current;
    Preorder(tree[current-'A'].left);
    Preorder(tree[current-'A'].right);
}
void Inorder(char current){
    if(current=='.') return;
    
    Inorder(tree[current-'A'].left);
    cout << current;
    Inorder(tree[current-'A'].right);
}
void Postorder(char current){
    if(current=='.') return;
    
    Postorder(tree[current-'A'].left);
    Postorder(tree[current-'A'].right);
    cout << current;
}

int main(){
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        char root, left, right;
        cin >> root >> left >> right;

        tree[root-'A'].left = left;
        tree[root-'A'].right = right;
    }
    
    Preorder('A');
    cout << endl;
    Inorder('A');
    cout << endl;
    Postorder('A');
    cout << endl;
    
    return 0;
}