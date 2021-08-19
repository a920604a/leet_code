// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int height(tree *root)
{
    if (!root)
        return 0;
    if (!root->l && !root->r)
        return 0;
    return 1 + max(height(root->l), height(root->r));
}
int solution(tree *T)
{
    // write your code in C++14 (g++ 6.2.0)
    if (!T)
        return 0;
    return height(T);
}
