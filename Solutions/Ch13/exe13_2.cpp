#include <iostream>
#include <cstring>
using namespace std;

// base class
class Cd
{
private:
    char * performer;
    char * label;
    int selections;
    double playtime;
public:
    Cd(const char * s1,const char * s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd() {delete [] performer; delete [] label;};
    virtual void Report() const;
    Cd & operator=(const Cd &d);
};

class Classic: public Cd
{
private:
    char * work;
public:
    Classic(const char* w, const char * s1, const char * s2, int n, double x);
    Classic(const Classic & c);
    Classic();
    virtual void Report() const;
    Classic & operator=(const Classic &c);
    ~Classic();
};

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performer = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performer, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd()
{
    performer = new char[1];
    label = new char[1];
    performer[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}
Cd::Cd(const Cd & d)
{
    performer = new char[strlen(d.performer) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performer, d.performer);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    cout << "=== CD REPORT =====\n";
    cout << "performers " << performer << '\n';
    cout << "label " << label << '\n';
    cout << "selections " << selections << '\n';
    cout << "playtime " << playtime << '\n';
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
    {
        return *this;
    }

    delete [] performer;
    delete [] label;
    performer = new char[strlen(d.performer) + 1];
    label = new char[strlen(d.label) + 1];

    strcpy(performer, d.performer);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Classic::~Classic()
{
    delete [] work;
}

Classic::Classic()
    :Cd()
{
    work = new char[1];
    work[0] = '\0';
}

Classic::Classic(const char* w, const char * s1, const char * s2, int n, double x)
    : Cd(s1, s2, n, x)
{
    work = new char[strlen(w) + 1];
    strcpy(work, w);
}

Classic::Classic(const Classic & c)
    : Cd(c)
{
    work = new char[strlen(c.work) + 1];
    strcpy(work, c.work);
}

void Classic::Report() const
{
    cout << "=== CLASSIC REPORT ===\n";
    Cd::Report();
    cout << "work " << work << '\n';
}

Classic & Classic::operator=(const Classic & d)
{
    if (this == &d)
    {
        return *this;
    }
    Cd::operator=(d);

    delete [] work;
    work = new char[strlen(d.work) + 1];
    strcpy(work, d.work);
    return *this;
}

void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
    "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    // use Cd method
    c2.Report();
    // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";

    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}