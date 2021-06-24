class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        // option 1 reversed traversal
        // int n=arr.size(), _max = -1;
        // int tmp = arr[n-1];
        // arr[n-1] = _max;
        // for(int i=n-2;i>-1;--i){
        //     _max = max(tmp, _max);
        //     tmp = arr[i];
        //     arr[i] = _max;
        // }
        // return arr;

        // option 2 STL stack
        stack<int> sta1, sta2;
        sta1.push(arr[0]);
        for (int i = 1; i < arr.size(); ++i)
        {
            // cout<<arr[i]<<" "<<sta1.top()<<endl;
            while (!sta1.empty() && arr[i] > sta1.top())
            {
                sta1.pop();
            }
            sta1.push(arr[i]);
        }
        sta2.push(-1);
        while (!sta1.empty())
        {
            sta2.push(sta1.top());
            sta1.pop();
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i] << " " << sta2.top() << endl;
            if (!sta2.empty() && arr[i] >= sta2.top())
            {
                sta2.pop();
            }
            arr[i] = sta2.top();
            // sta.pop();
        }
        return arr;
    }
};