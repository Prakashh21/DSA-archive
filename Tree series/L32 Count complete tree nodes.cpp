class Solution {

/*  

This is O(log^2(N)) solution , is solution me poora tree traverse nahi karna padega 
jaise hi koi full subtree milega uska no. of nodes formulae ke help se nikal lenge
and return kar denge .. formulae for no. of nodes in a full tree = 2^height of the tree - 1;

*/    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = leftH(root);
        int rh = rightH(root);
        
        if(lh == rh){       // if lh == rh this means the subtree is a full tree
        return (1<<rh) -1;     //  then total nodes = 2^height - 1
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    int leftH(TreeNode* root){
        int ht = 0;
        while(root){
            ht++;         
            root = root -> left;   
           
        }
    
        return ht;
    }
    
    
    
    int rightH(TreeNode* root){
        int ht = 0;
        while(root){
            ht++;
            root = root -> right;
        }
        return ht;
    }
};
 


