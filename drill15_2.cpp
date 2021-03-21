#include "std_lib_facilities.h"

struct Person 
{
Person(string first_name, string last_name, int age)
	{
		if (age < 0 || age > 150)
			error("Invalid age");
		else 
			m_age = age;

		string n = first_name + last_name;
		for (char c : n) 
		{
			switch(c) 
			{
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!': 
                error("Invalid character");
                break;
            default:
                break;
        	}
		}
		
		m_first_name = first_name;
		m_last_name = last_name;
	}
	int age() const {
        return m_age;
    }

    string first_name() const {
        return m_first_name;
    }

    string second_name() const {
        return m_last_name;
    }

    string name() const {
        return m_first_name + " " + m_last_name;
    }

private:
	string m_first_name;
	string m_last_name;
	int m_age;
};

ostream& operator<<(ostream& o, const Person& p) 
{
    o << p.name() << " " << p.age() << '\n';
    return o;
}

istream& operator>>(istream& i, Person& p) 
{
    string tmp_first_name, tmp_last_name;
    int tmp_age;

    i >> tmp_first_name >> tmp_last_name >> tmp_age;
    p = Person{tmp_first_name, tmp_last_name, tmp_age};

    return i;
}


int main()										//????
{
	Person buffer{"", "", 0};

    vector<Person> person_vec;

    while (cin >> buffer) {
        person_vec.push_back(buffer);
    }

    for (auto i : person_vec)
        cerr << i;

}