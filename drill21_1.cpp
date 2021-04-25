#include "std_lib_facilities.h"

// 1. Define a struct Item

struct Item {
    string name;
    int iid;
    double value;
};

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t'
              << it.iid << '\t'
              << it.value;
}

istream& operator>>(istream& is, Item& it)
{
    string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item itt {ss, ii, dd};
    it = itt;
    return is;
}

void print(vector<Item> vec) {
    for (auto i : vec)
        cout << i << '\n';
}

class erase_by_name 
{
    string name;
	public:
    erase_by_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};
 
class erase_by_iid 
{
    int iid;
	public:
    erase_by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};


int main()
try 
{
    // 1. Make a vector<Item> and fill it with ten Items from a file

    const string iname {"input.txt"};

    ifstream ifs {iname};
    if (!ifs) throw runtime_error("Could not read from file: " + iname);

    vector<Item> vi;
    for (Item ii; ifs >> ii; )
        vi.push_back(ii);

    // 8. Repeat exercise with a list<Item>
    list<Item> lst (vi.size());
    copy(vi.begin(), vi.end(), lst.begin());

    cout << "Vector:\n";
    print(vi);
    cout << endl;

    // 2. Sort vi by name

    sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.name < b.name; });
    cout << "Sorted by name:\n";
    print(vi);
    cout << endl;

    // 3. Sort vi by iid

    sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.iid < b.iid; });
    cout << "Sorted by iid:\n";
    print(vi);
    cout << endl;

    // 4. Sort vi by value, print in decreasing order

    sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.value < b.value; });
    cout << "Sorted by decreasing value:\n";
    for (auto it = vi.rbegin(); it != vi.rend(); ++it)
        cout << *it << '\n';
    cout << endl;

    // 5. Insert values

    vi.push_back(Item{"Canon S400", 9988, 499.95});
    vi.push_back(Item{"horse shoe", 99, 12.34});
    cout << "2 values inserted:\n";
    print(vi);
    cout << endl;

    // 6. Remove two items identified by name

    vi.erase(find_if(vi.begin(), vi.end(), erase_by_name("Anja")));
    vi.erase(find_if(vi.begin(), vi.end(), erase_by_name("Klaus")));
    cout << "2 items removed by name:\n";
    print(vi);
    cout << endl;

    // 7. Remove two items identified by iid

    vi.erase(find_if(vi.begin(), vi.end(), erase_by_iid(0)));
    vi.erase(find_if(vi.begin(), vi.end(), erase_by_iid(9)));
    cout << "2 items removed by iid:\n";
    print(vi);
    cout << endl;

    //8. Repeat the exercise with a list<Item>
    
    cout << "List:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    cout << "List sorted by name:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    cout << "List sorted by iid:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.sort([](const Item& a, const Item& b) { return a.value > b.value; });
    cout << "List sorted by decreasing value:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.push_back(Item{"Canon S400", 9988, 499.95});
    lst.push_back(Item{"horse shoe", 99, 12.34});
    cout << "2 items added:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.erase(find_if(lst.begin(), lst.end(), erase_by_name("Anja")));
    lst.erase(find_if(lst.begin(), lst.end(), erase_by_name("Klaus")));
    cout << "2 values erased by name:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

    lst.erase(find_if(lst.begin(), lst.end(), erase_by_iid(0)));
    lst.erase(find_if(lst.begin(), lst.end(), erase_by_iid(9)));
    cout << "2 values erased by iid:\n";
    for (auto i : lst)
        cout << i << '\n';
    cout << endl;

}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}