#include <cstddef>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// UDF string
class String {
    public:
        // initial
        String(const char* str = "") {
            cout << "Create String" << endl;
            if (str == nullptr) return;
            size_ = strlen(str);
            if (size_ == 0) return;
            str_ = new char[size_ + 1];
            memcpy(str_, str, size_ + 1);
        }
        // copy
        String (const String& s) {
            cout << "Copy String" << endl;
            size_ = s.size_;
            str_ = new char[size_ + 1];
            memcpy(str_, s.str_, size_);
        }
        // move
        String (String&& s) {
            cout << "Move String" << endl;
            str_  = s.str_;
            size_ = s.size_;

            s.str_  = nullptr;
            s.size_ = 0;
        }
        // destructor
        ~String() {
            cout << "Drop String:" << size_ << endl;
            Clear();
        }
        // assign
        String &operator = (const char* str) {
            cout << "Operator = char* " << endl;
            if (str == nullptr) return *this;
            if (str == str_) return *this;
            size_ = strlen(str);
            if (size_ == 0) return *this;
            str_ = new char[size_ + 1];
            memcpy(str_, str, size_ + 1);
            return *this;
        }
        // copy assign
        String &operator = (const String& s) {
            cout << "Operator = copy " << s.str_ << endl;
            if (this == &s) return *this;
            Clear();
            // copy
            size_ = s.size_;
            str_ = new char[size_ + 1];
            memcpy(str_, s.str_, size_ + 1);
            return *this;
        }
        // move assign
        String &operator = (String && s) {
            cout << "Operator = move " << s.str_ << endl;
            if (this == &s) return *this;
            str_  = s.str_;
            size_ = s.size_;

            s.str_  = nullptr;
            s.size_ = 0;
            return *this;
        }

        const char* c_str() {
            if (!str_) return "";
            return str_;
        }

        void Clear() {
            size_ = 0;
            delete str_; str_ = nullptr;
        }

    private:
        char* str_{nullptr};
        int size_{ 0 };
    };

    void TestString(String& s) {
        cout << "TestString: " << s.c_str() << endl;
    }

    int main()
    {
        String str1("Test UDF String str1");
        String str2("Test UDF String str2");

        TestString(str1);
        TestString(str2);

        str2 = str1;

        TestString(str1);
        TestString(str2);

        str2 = str2;

        str1 = "Operator = ";
        str2 = move(str1);
    }
