#include <cstddef>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// UDF string
class String {
    public:
        String(const char* str = "") {
            cout << "Create String" << endl;
            size_ = strlen(str);
            if (size_ == 0) return;
            str_ = new char[size_ + 1];
            memcpy(str_, str, size_ + 1);
        }

        String (const String& s) {
            cout << "Copy String" << endl;
            size_ = s.size_;
            str_ = new char[size_ + 1];
            memcpy(str_, s.str_, size_);
        }

        String (String&& s) {
            cout << "Move String" << endl;
            str_  = s.str_;
            size_ = s.size_;

            s.str_  = nullptr;
            s.size_ = 0;
        }

        ~String() {
            cout << "Drop String:" << size_ << endl;
            size_ = 0;
            delete str_; str_ = nullptr;
        }

        const char* c_str() {
            if (!str_) return "";
            return str_;
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
        TestString(str1);

        String str2("Test UDF String str2");
        TestString(str2);

        String str3(move(str2));
        TestString(str2);
        TestString(str3);
    }
