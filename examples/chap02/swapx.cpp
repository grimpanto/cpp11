#include <iostream>

using namespace std;

class String {
  private:
    string s_;
    
  public:
    String(string s) : s_(s) {
        cout << "String(\"" + s + "\")" << endl;
    }
    
    String(String& rhs) {
        s_ = rhs.s_;
        cout << "String(" + s_ + "&)" << endl;
    }

    String(String&& rhs) {
        s_ = rhs.s_;
        cout << "String(" + s_ + "&&)" << endl;
    }
    
    String& operator=(const String& rhs) {
        s_ = rhs.s_;
        cout << "operator=(" + rhs.s_ + "&)" << endl;
    }
    
    String& operator=(const String&& rhs) {
        s_ = rhs.s_;
        cout << "operator=(" + rhs.s_ + "&&)" << endl;
    }
};

void swap(String&& a, String&& b) {
    String tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main() {
    String s1{"a"};
    String s2{"b"};

    swap(s1, s2);

    string s{};
    s = to_string(12);
    cout << s << endl;

    int i = stoi(s + "i");
    cout << i + 1 << endl;
}
