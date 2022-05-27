
#include <memory>
#include <unordered_map>
#include <map>
#include <queue>
#include <cassert>

struct Node;
using SharedNode=std::shared_ptr<Node>;

struct Node{
    char value;        // symbol to be encoded
    int frequency;     // total count of `value` in the text
    SharedNode left;   // assume that going left refers to 0 in the Huffman code
    SharedNode right;  // right refers to 1

    // constructor for leafs
    Node(char v, int f): value{v}, frequency{f}, left{nullptr}, right{nullptr} {}
    // constructor for inner nodes
    Node(SharedNode l, SharedNode r)
      : value{0}, frequency{l->frequency + r->frequency}, left{l}, right{r} {};
};

// required for heap
struct comparator {
 bool operator()(const SharedNode a, const SharedNode b) const {return a->frequency > b->frequency;}
};



int length(SharedNode node, int depth = 0){
    if (node != nullptr){
        if (node->value != 0){
            return depth * node->frequency;
        }
        return length(node->left, depth+1) + length(node->right, depth+1);
    }
    return 0;
}

// Returns the root of the constructed Huffman Tree
SharedNode buildHuffmanTree(std::istream& in){
    // read in characters and get frequencies
    std::map<char, int> m;
    char x;
    int n = 0;
    while (in.get(x)){
        ++m[x];
        ++n;
    }
    std::cout << "n = " << n << " characters" << std::endl; 
    
    // build head
    std::priority_queue<SharedNode, std::vector<SharedNode>, comparator> q;
    for (auto y: m){
        q.push(std::make_shared<Node>(y.first, y.second));
    }

    // build code tree
    SharedNode left;
    while (!q.empty()){
        left = q.top();q.pop(); 
        if (!q.empty()){
            auto right = q.top();q.pop();   
            q.push(std::make_shared<Node>(left, right));
        }
    }

    return left;
}

// debugging / output
// optional
void output_code(SharedNode node, std::string prefix = ""){
    if (node != nullptr){
        if (node->value != 0){
            std::cout << node->value << "(" << node->frequency << ") :" << prefix << std::endl;
        }
        output_code(node->left, prefix + "0");
        output_code(node->right, prefix + "1");
    }
}

// optional
void storetree(SharedNode node, std::ostream& out){
    if (node->left){
        out << "0";
        storetree(node->left,out);
        storetree(node->right,out);
    }
    if (node->value){
        out << "1";
        out << node->value;
    }
}

// optional
SharedNode readtree(std::istream& is){
    std::unique_ptr<Node> result = std::make_unique<Node>(Node(0,0));
    char c;
    is >> c;
    if (c == '0'){
        result->left = std::move(readtree(is));
        result->right= std::move(readtree(is));
    }
    if (c == '1'){
        is >> result->value;
    }
    return result;
}

// Iterates the Huffman Tree to a table char->boolean sequence
// for encoding, optional
void ht2table(SharedNode ht, std::unordered_map<char, std::string> &char2code, std::string prefix="") {
  if (ht == nullptr)
    return;
  
  if (ht->value)  // if leaf
    char2code[ht->value] = prefix;
  else {
    ht2table(ht->left, char2code, prefix+'0');
    ht2table(ht->right, char2code, prefix+'1');
  }
}

// Returns a string consisting of characters '0' and '1'
// after encoding `text` using `ht`
// optional
std::string encode(std::string &text, SharedNode ht) {
  std::unordered_map<char, std::string> char2code;
  ht2table(ht, char2code);
  
  std::string res;
  for (char c: text)
    res += char2code[c];
    
  return res;
}

// Decodes `code` using `ht`
// optional
std::string decode(std::string code, SharedNode ht) {
  std::string res;
  
  SharedNode curr = ht;
  for (char c: code) {
    assert(c == '0' || c == '1');
    curr = (c == '0') ? curr->left : curr->right; 
    if (curr->value) {
      res += curr->value;
      curr = ht;
    }
  }
  assert(curr == ht);
  
  return res;
}

int code_length(std::istream& input){
    SharedNode n = buildHuffmanTree(input);

    /* debugging and tree storage experiments
    std::cout << "outcode" << std::endl;
    output_code(n,"");
    std::stringstream s;
    storetree(n,s);
    n = readtree(s);
    std::cout << "outcode" << std::endl;
    output_code(n,"");
    */
    
    return length(n);
}
