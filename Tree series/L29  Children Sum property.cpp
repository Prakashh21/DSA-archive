class Solution {

void changeTree(TreeNode* root){
	if(root == NULL){
		return;
	}

// check if parent ka dono children ka sum parent >=(bada hai ya nahi)
// agar bada hai toh parent ko dono children ka sum ka value de do
// agar bada nahi hai toh dono children ko parent ka value de do
// dfs call lagao takki pura tree me ye kaam ho jaaye	

	int child = 0;
	if(root -> left){
		child += root -> left -> val;
	}

	if(root -> right){
		child += root -> right -> val;
	}

	if(root -> val <= child){
		root -> val = child;
	}else{
		if(root -> left ) root -> left -> val = root -> val;
		else if(root -> right) root -> right -> val = root -> val;
	}

	changeTree(root -> left);
	changeTree(root -> right);

	// backtrack karte waqt sum variable me dono children ka value
	// add karo , aur agar leaf node nahi hai toh, node ka value
	// ko sum ke equal kar do.

	int sum =0;
	if(root -> left) sum += root -> left -> val;
	if(root -> right) sum += root -> right -> val;
	if(root -> left || root -> right) root -> val = sum;



}


}