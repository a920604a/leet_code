

bool isValid(char * s){
    char * stack = malloc(sizeof(char)*strlen(s));
    int n = strlen(s);
    int idx = 0;
    for(int i=0 ; i<n ;++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[idx++] = s[i];
        }
        else{
            if(idx ==0) return false;
            else if( stack[idx-1] == '(' && s[i] == ')') idx--;
            else if( stack[idx-1] == '[' && s[i] == ']') idx--;
            else if( stack[idx-1] == '{' && s[i] == '}') idx--;
            else return false;
        }
    }
    free(stack);
    return idx==0;
}