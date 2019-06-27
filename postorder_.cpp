void postorder_(node* root)
{
	stack<node* > s;
	s.push(root);
	vector<int> v;
	
	while(!s.empty())
	{
		auto x = s.top();
		v.push_back(x->val);
		s.pop();
		if(x->left)
		{
			s.push(x->left);
		}
    if(x->right)
		{
			s.push(x->right);
		}
	}
  reverse(v.begin(),v.end());
	for(auto x : v)
		cout<<x<<" ";
		
}
