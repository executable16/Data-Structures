// Prefix Function Z algorithm
vector<int> prefix(string s)
{
    vector<int> pi(s.size());
    int n = s.size();
    pi[0]=0;
    for(int i=1;i<n;i++)
    {
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}
