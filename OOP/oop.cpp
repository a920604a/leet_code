#include <iostream>
using namespace std;
class AbstractChart
{
    // 抽象類
public:
    //抽象類，子類實現
    virtual void display() = 0;
};

class ChartDisplay
{
    // 接口類、客戶端
private:
    AbstractChart *chart;

public:
    void setChart(AbstractChart *chart) // 避免 object slice
    {
        this->chart = chart;
    }

    virtual void display()
    {
        this->chart->display();
    }
};
class PieChart : public AbstractChart
{
public:
    void display()
    {
        cout << "display PieChart" << endl;
    }
};
class BarChart : public AbstractChart
{
public:
    void display()
    {
        cout << "display BarChart" << endl;
    }
};

class A
{
private:
    string name;

    void setName(string x)
    {
        this->name = x;
        cout << "setName" << endl;
    }

protected:
    int pro;
    void setPro(int x)
    {
        this->pro = x;
        cout << "setPro" << endl;
    }

public:
    int pub;
    void setPub(int x)
    {
        this->pub = x;
        cout << "setPub" << endl;
    }
};
class B : protected A
{
private:
    void sing(){
        this->setPub(5);
        cout<<this->pub<<endl;
        this->setPro(50);
        cout<<this->pro<<endl;
    }
protected:
    void play(){
        this->setPub(5);
        cout<<this->pub<<endl;
        this->setPro(50);
        cout<<this->pro<<endl;
    }
public:
    void display()
    {
        this->play();
    //     // this->setName('yuan');
    //     // cout << this->name << endl;
    //     this->setPub(5);
    //     cout << this->pub << endl;
    //     this->setPro(50);
    //     cout << this->pro << endl;
    }
};
int main()
{
    B b = B();
    b.display();
    // b.setPub(5);
    // cout<<b.pub<<endl;
    // b.setPro(50);
    // cout<<b.pro<<endl;

    return 0;
}