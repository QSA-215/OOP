#include "stringStack.h"

CStringStack::CStringStack()
{
	m_stack = nullptr;
	m_size = 0;
};

CStringStack::CStringStack(const CStringStack& otherStack)
{
	if (otherStack.m_stack == nullptr)
	{
		m_stack = nullptr;
		m_size = 0;
		return;
	}
	Node* newStack = new Node({ otherStack.m_stack->str, otherStack.m_stack->next });
	Node* position = newStack->next;
	Node* data = otherStack.m_stack->next;
	while (data != nullptr)
	{
		position = new Node(*data);
		position = position->next;
		data = data->next;
	}
	m_stack = newStack;
	m_size = otherStack.m_size;
};

CStringStack::CStringStack(CStringStack&& otherStack) noexcept
{
	m_stack = otherStack.m_stack;
	m_size = otherStack.m_size;
	otherStack.m_size = 0;
};

CStringStack::~CStringStack()
{
	while (m_stack != nullptr)
	{
		m_stack->str = "";
		m_stack = m_stack->next;
	}
};

void CStringStack::push(const std::string& str)
{
	Node* newObject = new Node({ str, m_stack });
	m_stack = newObject;
	m_size++;
};

void CStringStack::pop()
{
	if (m_size == 0)
		throw std::out_of_range("There are no elements in stack");
	
	m_stack->str = "";
	m_stack = m_stack->next;
	m_size--;
};

std::string CStringStack::getTop()
{
	if (m_size == 0)
		throw std::out_of_range("There are no elements in stack");

	return m_stack->str;
};

CStringStack& CStringStack::operator=(const CStringStack& otherStack)
{
	if (std::addressof(otherStack) != this)
	{
		CStringStack tmpCopy(otherStack);
		std::swap(m_stack, tmpCopy.m_stack);
		std::swap(m_size, tmpCopy.m_size);
	}
	return *this;
};

CStringStack& CStringStack::operator=(CStringStack&& otherStack) noexcept
{
	if (std::addressof(otherStack) != this)
	{
		CStringStack tmpCopy(otherStack);
		std::swap(m_stack, tmpCopy.m_stack);
		std::swap(m_size, tmpCopy.m_size);
		otherStack.m_stack = nullptr;
		otherStack.m_size = 0;
	}
	return *this;
};