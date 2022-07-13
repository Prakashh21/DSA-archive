class Solution{
 

/*

  S-1 -- mark the parent pointers , using a hashmap and level order traversal.
  S-2 -- create a visited hash and a count variable which would signify the distance from the  target node , start at the target node and start doing dfs traversal , in left , right , and  top (parent) directions , mark the node as visited in the visited hash as you visit them ,  for each iteration , increase the count after every iteration , break the loop when  alue of count == k , the remaining nodes inside the queue when the loop breaks would be all the nodes at k distance from the target node. , pop those nodes and add them to a vector and return it.

*/	
	void markParents(TreeNode* root , unordered_map<TreeNode*, TreeNode*> &parent_track , TreeNode* target){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
	TreeNode* node = q.front();
	q.pop();
			if(node -> left){
			parent_track[node->left] = node;
			q.push(node->left);
			}

			if(node -> right){
			parent_track[node->right] = node;
			q.push(node->right);
			}	

	}

	}


public:	
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
	unordered_map<TreeNode* , TreeNode*> parent_track;
	markParents(root, parent_track, target);
	

  unordered_map<TreeNode*,bool> visited;
	queue<TreeNode*> q;
	q.push(target);
	visited[target] = true;
	int count = 0;

	while(!q.empty()){
	int size = q.size();
	
	if(count++ == k) break;
	for(int i = 0 ; i < size ; i++){
	TreeNode* current = q.front() ;
	q.pop();

	if(current -> left && !visited[current -> left]){
			q.push(current -> left);
			visited[current -> left] = true;
		} 

	if(current -> right && !visited[current -> right]){
			q.push(current -> right);
			visited[current -> right] = true;
		} 	
	
	if(parent_track[current] && !visited[parent_track[current]]){
		q.push(parent_track[current]);
		visited[parent_track[current]] = true;
		}
			}

				}

	vector<int> ans;
	while(!q.empty()){
	TreeNode* node = q.front();
	q.pop();
	ans.push_back(node->val);
	}
		return ans;
	}



};