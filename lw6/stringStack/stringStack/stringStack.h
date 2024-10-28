#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

struct Node
{
    std::string str;
    Node* next;
};

class CStringStack
{
public:
    CStringStack();
    CStringStack(const CStringStack& otherStack);
    CStringStack(CStringStack&& otherStack) noexcept;
    ~CStringStack();

    void push(const std::string& str);
    void pop();
    std::string getTop();

    CStringStack& operator=(const CStringStack& otherStack);
    CStringStack& operator=(CStringStack&& otherStack) noexcept;
private:
    Node* m_stack;
    size_t m_size;
};