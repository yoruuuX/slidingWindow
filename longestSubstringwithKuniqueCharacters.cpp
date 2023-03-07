  int longestKSubstr(string s, int k) {
    // your code here
    int i=0,j=0;
    int ans=-1;
    unordered_map<int, int>mp;
    while(j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()==k)
        {
            ans=max(ans,j-i+1);
        }
        if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
return(ans);
