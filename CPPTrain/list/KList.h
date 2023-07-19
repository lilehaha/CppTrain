#pragma once
#include <iostream>

template<typename T>
struct ListNode {
    T value;
    ListNode<T>* next = nullptr;
    ListNode<T>* pre = nullptr;

    friend std::ostream& operator<<(std::ostream& cout, const ListNode<T>& obj) {
        cout << obj.value;
        return cout;
    }
};

template<typename T>
class KList
{
public:
    KList()
    {
        m_head = new ListNode<T>();
        m_tail = new ListNode<T>();
        m_head->next = m_tail;
        m_tail->pre = m_head;
    }
    ~KList()
    {
        popAll();
        delete m_head;
        m_head = nullptr;
        delete m_tail;
        m_tail = nullptr;
    }
    void printlist()
    {
        std::cout << "KList: " << std::endl;
        ListNode<T>* cur = m_head->next;
        while (cur != m_tail) {
            std::cout << cur->value << " -> ";
            cur = cur->next;
        }
    }

    ListNode<T>* push(T value)
    {
        ListNode<T>* _node = new ListNode<T>();
        _node->value = value;
        _node->pre = m_tail->pre;
        _node->next = m_tail;
        m_tail->pre->next = _node;
        m_tail->pre = _node;
        return _node;
    }

    ListNode<T>* insert(ListNode<T>* node, T value) {
        ListNode<T>* new_node = new ListNode<T>();
        new_node->value = value;
        new_node->pre = node;
        new_node->next = node->next;
        node->next->pre = new_node;
        node->next = new_node;
        return new_node;
    }
    ListNode<T>* find(T value) {
        ListNode<T>* cur = m_head->next;
        while (cur != m_tail) {
            if (cur->value == value) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }
    void remove(ListNode<T>* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
        node = nullptr;
    }
    void popAll() {
        ListNode<T>* cur = m_head->next;
        while (cur != m_tail) {
            ListNode<T>* tmp = cur;
            cur = cur->next;
            remove(tmp);
        }
    }
private:
    ListNode<T>* m_head = nullptr;
    ListNode<T>* m_tail = nullptr;
};

