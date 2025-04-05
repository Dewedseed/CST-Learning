#include <iostream>
#include <vector>
using namespace std;

class Widget
{
public:
    void Move(int x, int y) {x_ += x; y_ += y;}
    virtual void Draw() {cout << "Widge Draw " << x_ << ":" << y_ << endl;}
    int x() {return x_;}
    int y() {return y_;}

private:
    int x_{0};
    int y_{0};
};

class Rect:public Widget
{
public:
    void Draw() override {cout << "Rect Draw " << x() << ":" << y() << endl;}
};

class Circle:public Widget
{
public:
    void Draw() override {cout << "Circle Draw " << x() << ":" << y() << endl;}
};

class Scene
{
public:
    ~Scene(){
        Close();
    }

    void Close(){
        for (auto w : wids_)
            delete w;
        wids_.clear();
    }

    void Add(Widget* w) {
        wids_.push_back(w);
    }

private:
    vector<Widget*> wids_;
};

static void DrawWidget(Widget* w) {
    w->Draw();
}

static void DrawWidget(Widget& w) {
    w.Draw();
}

int main()
{
    Rect re;
    re.Move(100, 100);
    re.Draw();

    Circle cr;
    cr.Move(100, 100);
    cr.Draw();

    Widget w;
    w.Move(100, 100);
    w.Draw();

    DrawWidget(re);
    DrawWidget(&cr);

    Scene sec;
    sec.Add(new Widget());
    sec.Add(new Circle());
    sec.Add(new Rect());
}
