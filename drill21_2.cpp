#include "std_lib_facilities.h"

// 5. Read in pairs from std::cin and place them in map
void f(map<string, int>& m)
{
    string s;
    int i = 0;

    while (m.size() < 10) {
        cin >> s >> i;
        m.insert(make_pair(s, i));
    }
}

int main()
try
{
	// 1. Define a map
    map<string, int> msi;

    // 2. Insert 10 pairs into map
    msi["Peter"] = 45;
    msi["Lois"] = 43;
    msi["Meg"] = 17;
    msi["Stewie"] = 2;
    msi["Chris"] = 14;
    msi["Brian"] = 7;
    msi["Cleveland"] = 41;
    msi["Quagmire"] = 24;
    msi["Joe"] = 38;
    msi["Consuela"] = 55;

    // 3. Output them
    cout << "Original map:\n";
    for (const auto i : msi)
        cout << i.first << '\t' << '\t' << i.second << '\n';
    cout << endl;

    // 4. Erase
    msi.erase(msi.begin(), msi.end());
    cout << "Items erased:\n";
    for (const auto i : msi)
        cout << i.first << '\t' << '\t' << i.second << '\n';
    cout << endl;

    // 6. Read 10 pairs from std::cin and place them in msi
    f(msi);

    // 7. Write the elements from msi to cout
    cout << "Items read from input:\n";
    for (const auto i : msi)
        cout << i.first << '\t' << '\t' << i.second << '\n';
    cout << endl;

    // 8. Output the sum of the integer values in msi
    int total = accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const pair<std::string,int>& p)
            { return sum += p.second; });

    cout << "Total of integers: " << total << '\n';

    // 9. Define a map<int,string>
    map<int, std::string> mis;

    // 10. Enter values from msi into mis
    for (const auto& a : msi)
        mis[a.second] = a.first;

    // 11. Output the elements of mis
    cout << "mis:\n";
    for (const auto i : mis)
        cout << i.first << '\t' << '\t' << i.second << '\n';
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