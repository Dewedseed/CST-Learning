#include <memory>
#include <string>

class StringVector
{
public:
    StringVector(int size = 10);
    ~StringVector(){}

    void Push(const std::string& s);
    void Push(std::string&& s);

    const std::string& operator[](int index);

    int Size();
    int Capacity();

private:
    std::unique_ptr<std::string[]> strs_;

    int size_{ 0 };
    int capacity_{ 100 };

    void ExpansionVector();
};
