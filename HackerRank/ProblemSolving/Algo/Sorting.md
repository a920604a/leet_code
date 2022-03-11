## Lily's Homework

```c++
int lilysHomework(vector<int> arr) {
    int n = arr.size();
    vector<bool> vis(n, false);
    vector<vector<int>> p;
    for(int i=0;i<n;++i) p.push_back({arr[i], i});
    int count = 0;
    sort(p.begin(), p.end());
    for(int i=0;i<n;++i){
        int j = i;
        int cycle_size = 0;
        while(vis[j] == false){
            vis[j] = true;
            j = p[j][1];
            cycle_size++;
        }
        if(cycle_size>1) count+=cycle_size-1;
    }
    int ret = count;
    count = 0;
    sort(p.rbegin(), p.rend());
    
    vis = vector<bool>(n , false);
    for(int i=0;i<n;++i){
        int j = i;
        int cycle_size = 0;
        while(vis[j] == false){
            vis[j] = true;
            j = p[j][1];
            cycle_size++;
        }
        if(cycle_size>1) count+=cycle_size-1;
    }
    
    return min(ret, count) ;

}
```
## Fraudulent Activity Notifications


## The Full Counting Sort

