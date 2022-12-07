#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define newDBG_NEW


template <typename T>
struct NODE
{
	T info;
	NODE* next;
	NODE(T info, NODE* ptr = nullptr) :info(info), next(ptr) {}
	~NODE()
	{
		next = nullptr;
	}
};

template <typename T>
class LIST
{
using ptrNODE = NODE<T>*;
private:
	ptrNODE head;
	size_t size = 0;
	void adding_by_pointer(ptrNODE& ptr, T elem)
	{
		ptrNODE p = new NODE<T>(elem, ptr);
		ptr = p;
	}
	void deleting_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		--size;
		delete p;
	}
public:
	LIST()
	{
		head = new NODE<T>(0);
	}

	~LIST()
	{
		while (!empty())
			del_from_head();
		size = 0;
		delete head;
		_CrtDumpMemoryLeaks();
	}

	ptrNODE get_head()
	{
		return head;
	}

	T get_first()
	{
		return head->next->info;
	}

	size_t get_size()
	{
		return size;
	}

	bool empty()
	{
		return !head->next;
	}

	void add_to_head(T elem)
	{
		adding_by_pointer(head->next, elem);
	}

	void add_after(ptrNODE ptr, T elem)
	{
		if (ptr)
		{
			adding_by_pointer(ptr->next, elem);
			++size;
		}
	}

	void del_from_head()
	{
		if (head->next)
			deleting_by_pointer(head->next);
	}

	void del_after(ptrNODE ptr)
	{
		if (ptr && ptr->next)
			deleting_by_pointer(ptr->next);
	}

	void add_to_tail(T elem)
	{
		ptrNODE p = head;
		while (p->next)
			p = p->next;
		add_after(p, elem);
	}

	void create_by_queue(std::ifstream& file)
	{
		T elem;
		while (file >> elem)
			add_to_tail(elem);
	}

	void change_by_pointer(int index, T elem)
	{
		if ((*this)[index])
			(*this)[index]->info = elem;
	}

	void print(int left, int right)
	{
		if (empty())
			std::cout << "Список пуст!";
		else
			if (right < size)
				while (left != right+1)
					std::cout << (*this)[left++]->info << ' ';
		std::cout << '\n';
	}

	///Как лучше?
	ptrNODE operator[](int index)
	{
		ptrNODE p = nullptr;
		if (index > -1 && index < size)
		{
			int i = -1;
			p = head;
			while (p->next && i++ != index)
				p = p->next;
		}
		else
			if (index == -1)
				p = head;
		return p;
	}

	void add_group_to_head(LIST<T>& group)
	{
		ptrNODE p = group[0];
		ptrNODE h = head;
		while (p)
		{
			adding_by_pointer(h->next, p->info);
			h = h->next;
			p = p->next;
			++size;
		}
	}

	void add_group_to_tail(LIST<T>& group)
	{
		ptrNODE p = group[0];
		while (p)
		{
			add_to_tail(p->info);
			p = p->next;
		}
	}

	void add_group_after(LIST<T>& group, int index)
	{
		if ((*this)[index])
		{
			ptrNODE p = group[0];
			while (p)
			{
				add_after((*this)[index++], p->info);
				p = p->next;
			}
		}
	}

	void add_group_before(LIST<T>& group, int index)
	{
		if ((*this)[index])
		{
			index--;
			ptrNODE p = group[0];

			while (p)
			{
				add_after((*this)[index++], p->info);
				p = p->next;
			}
		}
	}

	void del_group(LIST<T>& group)
	{
		if (!empty() && !group.empty() && size >= group.size)
		{
			auto isStartGroup = [this](int i, LIST<T>& group)
			{
				int j = 1;
				if ((*this)[i++]->info == group[0]->info)
					while (group[j] && (*this)[i++]->info == group[j++]->info) {}

				return !group[j];
			};

			int check = 1;
			int i = find_elem(group[0]->info, check);
			while (!isStartGroup(i, group) && i > -1)
				i = find_elem(group[0]->info, ++check);
			
			int count = 0;
			while (count++ < group.size)
				del_after((*this)[i-1]);

			
			/*auto isStartGroup = [this](ptrNODE p, LIST<T>& group)
			{
				if (p->info == group[0]->info)
				{
					ptrNODE tmp = p->next;
					ptrNODE ptr = group[1];

					while (ptr && tmp->info == ptr->info)
					{
						ptr = ptr->next;
						tmp = tmp->next;
					}

					if (!ptr)
						return true;
				}
				return false;
			};

			bool isFind = false;
			ptrNODE ptr = head;
			while (ptr && !isFind)
			{
				if (ptr->next)
					if (ptr->next && isStartGroup(ptr->next, group))
						isFind = true;

				if (!isFind)
					ptr = ptr->next;
			}

			int count = 0;
			while (count < group.size)
			{
				del_after(ptr);
				++count;
			}*/
		}
	}

	int find_elem(T elem, size_t count = 1)
	{
		int i = 0;
		bool isFind = false;
		if (!empty())
			if (count < size)
				while (i < size && !isFind)
				{
					if ((*this)[i]->info == elem)
							count--;
					
					if (count < 1)
						isFind = true;

					if (!isFind)
						++i;
				}

		///Как лучше?
		return ((*this)[i] && i != -1 ? i : -2);
	}

	friend std::ostream& operator << (std::ostream& out, LIST<T>& list)
	{
		if (list.empty())
			out << "Список пуст!\n";
		else
		{
			ptrNODE p = list[0];
			while (p)
			{
				out << p->info << ' ';
				p = p->next;
			}
			out << '\n';
		}
		return out;
	}
};