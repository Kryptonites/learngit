#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;
 
std::vector<int> num;
std::vector<int> val;
int n;
int nxt[1005];
int dfs(int i, int s, int p){
    if(i >= n) 
	{
		return s > p;
	}
	if(val[i] > 1 && s < p) 
	{
		return 0;
	}
    return dfs(i + 1, s + val[i], p * val[i]) + dfs(nxt[i], s, p);
}
int solve(){
    val = num;
    int p = n;
    for(int i = n - 1; i >= 0; i--){
        if(i < n - 1 && val[i + 1] > val[i]) p = i + 1;
        nxt[i] = p;
    }
    return dfs(0, 0, 1);
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int x; 
		scanf("%d",&x);
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    cout << solve() << endl;
}
