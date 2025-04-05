#include "string_vector.h"

#include <memory>
#include <string>
using namespace std;

StringVector::StringVector (int size) {
    capacity_ = size;
    strs_ = make_unique<string[]>(size);
}

void StringVector::ExpansionVector() {
    capacity_ *= 2;
    auto tmp_ = make_unique<string[]>(capacity_);
    for (int i = 0; i < size_; ++i) {
        tmp_[i] = move(strs_[i]);
    }
    strs_.reset(nullptr);
    strs_ = move(tmp_);
    tmp_.reset(nullptr);
}

void StringVector::Push(const string& s) {
    if (size_ == capacity_) {
        ExpansionVector();
    }
    strs_[size_] = s;
    ++size_;
}

void StringVector::Push(string && s) {
    if (size_ == capacity_) {
        ExpansionVector();
    }
    strs_[size_] = s;
    ++size_;
    s = "";
}

const string& StringVector::operator[](int index) {
    return strs_[index];
}

int StringVector::Size() {
    return size_;
}

int StringVector::Capacity() {
    return capacity_;
}
