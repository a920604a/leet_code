#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)

int CostHour(int *piles, int pilesSize, int sp){
    int hours = 0;
    for(int i=0;i<pilesSize;++i){
        if(piles[i] < sp) hours++;
        // hours += piles[i]/sp;
        else{
            hours+= piles[i]/sp;
            if(piles[i]%sp!=0) hours++;
        }
        
    }
    return hours;
}
int minEatingSpeed(int* piles, int pilesSize, int h){
    
    int l = 1, r = 0;
    for(int i=0;i<pilesSize;++i){
        r = max(r, piles[i]);
    }
    
    while(l<r){
        int mid = l + (r-l)/2;
        int hours = CostHour(piles, pilesSize, mid);
        if( hours == h ) r  = mid;
        else if(hours < h) r= mid;
        else l = mid+1;
    }
    return l;
}