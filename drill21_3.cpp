#include "std_lib_facilities.h"

void print(vector<double> vec) {
    for (auto i : vec)
        cout << i << '\n';
}

class Less_than {
    double v;
public:
    Less_than(double vv) : v(vv) { }

    bool operator()(double val) const { return val < v; }
};

int main()
try 
{
    // 1. Make a vector<Item> and fill it with ten Items from a file

    const string iname {"inputfloat.txt"};

    ifstream ifs {iname};
    if (!ifs) throw runtime_error("Could not read from file: " + iname);

    // 2. Output to cout

    vector<double> vd;
    for (double d; ifs >> d; )
        vd.push_back(d);
    cout << "Vector:\n";
    print(vd);
    cout << endl;

    // 3. Make a vector of ints and copy the elements from vd to vi

    vector<int> vi (vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

     // 4. Output the pairs of vd[i], vi[i] to cout, one pair per line

    for (int i = 0; i < vd.size(); ++i)
        cout << vd[i] << '\t' << vi[i] << '\n';
    cout << endl;

    // 5. Output the sum of the elements of vd

    double double_sum = accumulate(vd.begin(), vd.end(), 0.0);
    cout << "Sum of vector<double>: " << double_sum << '\n';
    cout << endl;

    // 6. Output the difference between the sum of the elements of vd and vi

    double double_sum2 = accumulate(vi.begin(), vi.end(), 0.0);
    double difference = double_sum - double_sum2;
    cout << "The difference is: " << difference << endl;
    cout << endl;

    // 7. Reverse vd and output vd to std::cout

    reverse(vd.begin(), vd.end());
    cout << "Reversed:\n";
    print(vd);
    cout << endl;

    // 8. Compute the mean value of vd and output it

    double vd_mean = double_sum / vd.size();
    cout << "The mean value of vd is: " << vd_mean << '\n';
    cout << endl;

    // 9. ake a new vector<double> and copy all elements from vd that are less than vd's mean

    vector<double> vd2 (vd.size());
    auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
    vd2.resize(distance(vd2.begin(), it));
    cout << "Vector vd2:\n";
    print(vd2);
    cout << endl;

    // 10. Sort vd, output it again

    sort(vd.begin(), vd.end());
    cout << "Vector vd sorted:\n";
    print(vd);

}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}