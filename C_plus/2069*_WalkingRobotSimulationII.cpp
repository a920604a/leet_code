class Robot
{
private:
    int width, height, dir;
    vector<string> dirs = {"East", "North", "West", "South"};
    vector<int> cur;
    vector<vector<int> > acts = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    Robot(int width, int height)
    {
        this->width = width;
        this->height = height;
        dir = 0;
        cur = vector<int>(2, 0);
    }
    void move()
    {
        int x = cur[0] + acts[dir % 4][0];
        int y = cur[1] + acts[dir % 4][1];
        while (x < 0 || x > width - 1 || y < 0 || y > height - 1)
        {
            dir++;
            x = cur[0] + acts[dir % 4][0];
            y = cur[1] + acts[dir % 4][1];
        }
        cur[0] = x;
        cur[1] = y;
    }
    void step(int num)
    {
        for (int i = 0; i < num; ++i)
            move();
    }

    vector<int> getPos()
    {
        return cur;
    }

    string getDir()
    {
        return dirs[dir % 4];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */