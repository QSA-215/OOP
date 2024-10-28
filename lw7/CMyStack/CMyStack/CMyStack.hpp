#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
	T str;
    Node<T>* next;
};

template <typename T>
class CMyStack
{
public:
    CMyStack();
    CMyStack(const CMyStack& otherStack);
    CMyStack(CMyStack&& otherStack) noexcept;
    ~CMyStack();
	//переименовать
    void push(const T& str);
    void pop();
    T getTop();
	bool isEmpty() const;
	void Clear();

    CMyStack& operator=(const CMyStack& otherStack);
    CMyStack& operator=(CMyStack&& otherStack) noexcept;
private:
    Node<T>* m_stack;
    size_t m_size;
};

template <typename T>
CMyStack<T>::CMyStack()
{
	m_stack = nullptr;
	m_size = 0;
};

template <typename T>
CMyStack<T>::CMyStack(const CMyStack& otherStack)
{
	if (otherStack.m_stack == nullptr)
	{
		m_stack = nullptr;
		m_size = 0;
		return;
	}
	Node<T>* newStack = new Node<T>({ otherStack.m_stack->str, otherStack.m_stack->next });
	Node<T>* position = newStack->next;
	Node<T>* data = otherStack.m_stack->next;
	while (data != nullptr)
	{
		position = new Node<T>(*data);
		position = position->next;
		data = data->next;
	}
	m_stack = newStack;
	m_size = otherStack.m_size;
};

template <typename T>
CMyStack<T>::CMyStack(CMyStack&& otherStack) noexcept
{
	m_stack = otherStack.m_stack;
	m_size = otherStack.m_size;
	otherStack.m_stack = nullptr;
	otherStack.m_size = 0;
};

template <typename T>
CMyStack<T>::~CMyStack()
{
	Clear();
};

template <typename T>
void CMyStack<T>::push(const T& str)
{
	Node<T>* newObject = new Node<T>({ str, m_stack });
	m_stack = newObject;
	m_size++;
};

template <typename T>
void CMyStack<T>::pop()
{
	if (m_size == 0)
		throw std::out_of_range("There are no elements in stack");

	Node<T>* tempPtr;
	tempPtr = m_stack->next;
	delete m_stack;
	m_stack = tempPtr;
	m_size--;
};

template <typename T>
T CMyStack<T>::getTop()
{
	if (m_size == 0)
		throw std::out_of_range("There are no elements in stack");

	return m_stack->str;
};

template <typename T>
bool CMyStack<T>::isEmpty() const
{
	return m_size == 0;
};

template <typename T>
void CMyStack<T>::Clear()
{
	Node<T>* tempPtr;
	while (m_stack != nullptr)
	{
		tempPtr = m_stack->next;
		delete m_stack;
		m_stack = tempPtr;
	}
	m_size = 0;
};

template <typename T>
CMyStack<T>& CMyStack<T>::operator=(const CMyStack& otherStack)
{
	if (std::addressof(otherStack) != this)
	{
		CMyStack tmpCopy(otherStack);
		std::swap(m_stack, tmpCopy.m_stack);
		std::swap(m_size, tmpCopy.m_size);
	}
	return *this;
};

template <typename T>
CMyStack<T>& CMyStack<T>::operator=(CMyStack&& otherStack) noexcept
{
	if (std::addressof(otherStack) != this)
	{
		CMyStack tmpCopy(otherStack);
		std::swap(m_stack, tmpCopy.m_stack);
		std::swap(m_size, tmpCopy.m_size);
		otherStack.m_stack = nullptr;
		otherStack.m_size = 0;
	}
	return *this;
};