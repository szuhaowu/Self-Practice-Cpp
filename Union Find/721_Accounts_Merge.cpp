//Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//
//Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
//After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
//
//Example 1:
//Input: 
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
//Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//Explanation: 
//The first and third John's are the same person as they have the common email "johnsmith@mail.com".
//The second John and Mary are different people as none of their email addresses are used by other accounts.
//We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
//['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//Note:
//
//The length of accounts will be in the range [1, 1000].
//The length of accounts[i] will be in the range [1, 10].
//The length of accounts[i][j] will be in the range [1, 30].


//Union find
//將name跟email連到同一個root, 再從root裡找出每個人的email
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        vector<int> root(n, 0);
        unordered_map<string, int> mail_root;
        for (int i = 0; i < n; i++) {
            root[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mail_root.count(accounts[i][j])) {
                    int root1 = findroot(root, i);
                    int root2 = findroot(root, mail_root[accounts[i][j]]);
                    root[root1] = root2;
                }
                else mail_root[accounts[i][j]] = i;
            }
        }
        unordered_map<int, vector<string>> res_map;
        for (auto it : mail_root) {
            int ind = findroot(root, it.second);
            res_map[ind].push_back(it.first);
        }
        for (auto it : res_map) {
            vector<string> v = it.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), accounts[it.first][0]);
            res.push_back(v);
        }
        return res;
    }

private:
    int findroot(vector<int>& root, int i) {
        return root[i] == i ? i : findroot(root, root[i]);
    }
};




//BFS
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string,vector<int>> map;
        vector<int> visited(accounts.size(),0);
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                map[accounts[i][j]].push_back(i);
            }
        }
        for(int i=0; i<accounts.size(); i++){
            if(visited[i]!=0) continue;
            queue<int> q{{i}};
            set<string> s;
            while(!q.empty()){
                int t = q.front(); q.pop();
                vector<string> mails(accounts[t].begin()+1, accounts[t].end());
                for(auto mail:mails){
                    s.insert(mail);
                    for(auto user:map[mail]){
                        if(visited[user]!=0) continue;
                        q.push(user);
                        visited[user] = 1;
                    }
                }
            }
            vector<string> out(s.begin(),s.end());
            out.insert(out.begin(),accounts[i][0]);
            res.push_back(out);
        }
        return res;
    }
};
