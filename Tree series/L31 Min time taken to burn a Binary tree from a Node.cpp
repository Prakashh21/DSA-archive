// ** this question is similar to the previous question print all nodes at distance K.

S-1 -- mark the parent pointers using a map and level order traversal.
S-2 -- start dfs traversal from the target node. burn left , right and up(parent) from the target node and increase the time by one (+ 1) in every iteration of burning, and keep incrementing a burn count , also mark that node as visited in a visited hash. when the q becomes empty the value of the burn count will be our answer.


class Solution{
	
	TreeNode* dfstoParentNodes(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_map, int start){
				queue<TreeNode*> q;
				q.push(root);
				TreeNode* res;
				
				while(!q.empty()){
					
					TreeNode* node = q.front();
					if(node -> val == start){
							res = node;
					}

					q.pop();

					if(node -> left){
					parent_map[node -> left] = node;
					q.push(node -> left);
					}

					else if(node -> right){
					parent_map[node -> right] = node;
					q.push(node -> right);

								}
						}
							 return res;	
				}
	
		

		int TimetoBurnBinaryTree(TreeNode* root , int start){

			unordered_map<TreeNode* , TreeNode*> mpp;
			TreeNode* target = dfstoParentNodes(root, mpp, start);
			
			return minTimetoBurn(mpp, target, 0);



		}


		int minTimetoBurn(unordered_map<TreeNode* , TreeNode*> &parent_map , TreeNode* target, int &mini){
				queue<TreeNode*> q;
				unordered_map<TreeNode* , bool> visited;

				q.push(target);
				visited[target] = true;


				while(!q.empty()){

				int size = q.size();
				int flag = 0;

				for(int i = 0; i < size ; i++ ){

							TreeNode* node = q.front();
							q.pop();

							if(node -> left && !visited[node -> left]){
							flag =1;
							q.push(node -> left);
							visited[node -> left] = true
							}

							if(node -> right && !visited[node -> right]){
							flag =1;
							q.push(node -> right);
							visited[node -> right] = true;
							}

							if(parent_map[node] && !visited[parent_map[node]]){
							flag = 1;
							q.push(parent_map[node]);
							visited[parent_map[node]] = true;
							}

						}
				if(flag) mini++; 

				// agar flag ek baar bhi agar 1 hogaya matlab ek node toh atleast burn hua hi // hai in that case humlog mini ko increment kar denge..
				// jab teeno traversal me leaf node pe hoga tab 3 me se koi bhi condition  
				// execute nahi ho paayega in that case flag zero hi rahega aur , mini 
				// increment nahi hoga, loop baar baar chalega and queue empty ho jaayega
				// and mini ka jo final value rahega wahi humlog ka answer hoga and humlog 
				// mini ko return kar denge.
				} 
		
					mini;
		}


};