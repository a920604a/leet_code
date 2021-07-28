class FreqStack
{
private:
    int maxFreq;
    unordered_map<int, int> valToFreq;
    unordered_map<int, stack<int> > freqToVals;

public:
    FreqStack()
    {
        maxFreq = 0;
    }

    void push(int val)
    {
        int freq = valToFreq[val]++;
        maxFreq = max(maxFreq, freq);

        freqToVals[freq].push(val);
    }

    int pop()
    {
        stack<int> &vals = freqToVals[maxFreq];
        int v = vals.top();
        vals.pop();
        valToFreq[v]--;
        if (vals.empty())
        {
            maxFreq--;
        }
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */