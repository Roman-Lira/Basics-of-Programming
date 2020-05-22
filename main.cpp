#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "algorithm"
#include <iterator>

using namespace std;

struct Human {
    string surname, name;
    int year{};
    bool sex{};

    Human() = default;

    const string &getSurname() const {
        return surname;
    }

    const string &getName() const {
        return name;
    }

    int getYear() const {
        return year;
    }

    bool isSex() const {
        return sex;
    }

    bool operator<(const Human &rhs) const {
        if (surname < rhs.surname)
            return true;
        if (rhs.surname < surname)
            return false;
        if (name < rhs.name)
            return true;
        if (rhs.name < name)
            return false;
        if (year < rhs.year)
            return true;
        if (rhs.year < year)
            return false;
        return sex < rhs.sex;
    }

    bool operator>(const Human &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Human &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Human &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const Human &human) {
        os << "surname: " << human.surname << " name: " << human.name << " year: " << human.year << " sex: "
           << human.sex;
        return os;
    }

    friend istream &operator>>(istream &is, Human &human) {
        is >> human.surname >> human.name >> human.year >> human.sex;
        return is;
    }
};

int main(){
    ifstream in("people.txt");
    ifstream in1("human.txt");
    ofstream out("out.txt");
    vector<Human> people;
    vector<Human> human;
    copy(istream_iterator<Human>(in), istream_iterator<Human>(), back_inserter(people));
    copy(istream_iterator<Human>(in1), istream_iterator<Human>(), back_inserter(human));
    sort(people.begin(),people.end());
    out << "Sort by surname:" << endl;
    for(auto&i:people){
        out << i << endl;
    }
    out << "------------------------------------------\n";
    stable_sort(human.begin(), human.end(), [](const Human& a, const Human& b){
        return a.getYear() < b.getYear();
    });
    for(auto&i:human){
        out << i << endl;
    }


}