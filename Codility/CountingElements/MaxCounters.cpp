// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n^2) time and O(n) space => run time
    int n = A.size();
    vector<int> vec(N, 0);
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == N + 1)
        {
            // max counter
            for (int &v : vec)
                v = mx;
        }
        else
        {
            // increase 1
            vec[A[i] - 1]++;

            mx = max(mx, vec[A[i] - 1]);
        }
    }
    return vec;
}



// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(n) space
    int n = A.size();
    vector<int> vec(N,0);
    int mx = 0, lastMax = 0;
    for(int i=0;i<n;++i){
        if(A[i]<N+1){   
            int j  = A[i]-1;
            if(vec[j] < lastMax) vec[j] = lastMax;
            vec[j]++;

            if(mx < vec[j]) mx = vec[j];
        }
        else{
            lastMax = mx;
        }
    }
    
    for(int &v:vec){
        if(v< lastMax) v = lastMax;
    }
    return vec;
}
