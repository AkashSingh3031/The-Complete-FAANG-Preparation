/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode* node,graphNode* root,vector<graphNode*> &visited){
    for(auto n:node->neighbours){
        if(visited[n->data]==NULL){
            graphNode* newNode=new graphNode(n->data);
            visited[n->data]=newNode;
            (root->neighbours).push_back(newNode);
            dfs(n,newNode,visited);
        }
        else (root->neighbours).push_back(visited[n->data]);
    }
}

graphNode *cloneGraph(graphNode *node)
{
    if(!node)return node;
    vector<graphNode*> visited(100005,NULL);
    graphNode* root=new graphNode(node->data);
    visited[node->data]=root;
    dfs(node,root,visited);
    return root;
}