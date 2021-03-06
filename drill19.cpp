#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

template <typename T>
struct S {
    S(T val_) : val(val_) {}

    T&       get();
    const T& get() const;

    S& operator=(const T&);

private:
    T val;
};

template <typename T>
T& S<T>::get() {
    return val;
}

template <typename T>
const T& S<T>::get() const {
    return val;
}

template <typename T>
S<T>& S<T>::operator=(const T& rhs) {
    val = rhs;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> vec) {

    o << "{ ";
    for (auto i : vec)
        o << i << ", ";
    o << '}';

    return o;
}

template <typename T>
std::istream& operator>>(std::istream& i, std::vector<T>& vec) {
    char buf;
    i >> buf;

    if (buf != '{') {
        i.unget();
        return i;
    }

    for (T val; i >> val;) {
        vec.push_back(val);

        i.get(buf);
        if (buf != ',')
            break;
    }

    return i;
}

template <typename T>
void read_val(T& v) {
    std::cin >> v;
}

int main() 
{
    int tmp_i;
    read_val(tmp_i);
    S<int> s_int{tmp_i};

    char tmp_c;
    read_val(tmp_c);
    S<char> s_char{tmp_c};

    double tmp_d;
    read_val(tmp_d);
    S<double> s_double{tmp_d};

    std::string tmp_s;
    read_val(tmp_s);
    S<std::string> s_string{tmp_s};

    std::vector<int> tmp_v;
    read_val(tmp_v);
    S<std::vector<int>> s_vector{tmp_v};

    std::cerr << s_int.get() << '\n';
    std::cerr << s_char.get() << '\n';
    std::cerr << s_double.get() << '\n';
    std::cerr << s_string.get() << '\n';
    std::cerr << s_vector.get() << '\n';
}