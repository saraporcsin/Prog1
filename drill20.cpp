#include "std_lib_facilities.h"

//Print
template<typename C>
void print_contents(const C& c, const std::string& s = "")
{
    std::cout << s << '\t';
    for (auto& a : c)
        std::cout << a << ' ';
    std::cout << '\n';
}

//Write copy operation
template<typename Iter1, typename Iter2>
    // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
{
	//Define an array, a vector and a list of ints
	array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_contents(arr, "Array: ");
	print_contents(vec, "Vector:");
	print_contents(lst, "List: ");
	
	cout << endl;

	//Define copies
	array<int, 10> arr2 = arr;
	vector<int> vec2 = vec;
	list<int> lst2 = lst;
	print_contents(arr2, "Copied array: ");
	print_contents(vec2, "Copied vector:");
	print_contents(lst2, "Copied list: ");

	cout << endl;

	//Increase values
	for (auto& i : arr2)
        i += 2;

    for (auto& i : vec2)
        i += 3;

    for (auto& i : lst2)
        i += 5;
    print_contents(arr2, "Copied array: ");
	print_contents(vec2, "Copied vector:");
	print_contents(lst2, "Copied list: ");

	cout << endl;

	//Use my_copy() to copy array into vector and list into array
    my_copy(arr2.begin(), arr2.end(), vec2.begin());
    my_copy(lst2.begin(), lst2.end(), arr2.begin());
    print_contents(arr2, "Array copied: ");
    print_contents(vec2, "Vector copied: ");
    print_contents(lst2, "List copied: ");

    cout << endl;

    //Use find() to locate values
    vector<int>::iterator vit;
    vit = find(vec2.begin(), vec2.end(), 3);
    if (vit != vec2.end())
        cout << "Found at: " << distance(vec2.begin(), vit) << endl;
    else
        cout << "Not found\n";

    cout << endl;

    list<int>::iterator lit;
    lit = find(lst2.begin(), lst2.end(), 27);
    if (lit != lst2.end())
        cout << "Found at: " << distance(lst2.begin(), lit) << endl;
    else
        cout << "Not found\n";
}