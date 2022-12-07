#include <iostream>
#include "My_List.h"
#include <Windows.h>

void initGroup(size_t sizeGroup, int* group)
{
	for (size_t i = 0; i < sizeGroup; ++i)
		group[i] = i + 2;
}

template <typename T>
void initList(LIST<T>& list)
{
	for (int i = 0; i < 6; ++i)
		list.add_to_tail((i+1)*100+(i*10+i%2) + i);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LIST<int> list;
	std::ifstream file("test.txt");
	list.create_by_queue(file);

	std::cout << "\n_____________________________________\n";
	std::cout << "\n    LIST: " << list;
	std::cout << "_____________________________________\n";
	
	if (list.find_elem(13) > -1)
		std::cout << "\n    FIND_ELEM(13): " << list.find_elem(13);
	else
		std::cout << "\n    FIND_ELEM(13): " << "Элемент не найден";

	std::cout << "\n    LIST[3...7]:   ";
	list.print(3, 7);
	
	if (list[7])
		std::cout << "    LIST[7]->INFO: " << list[7]->info;
	else
		std::cout << "    LIST[7]->INFO: " << "Элемент не найден";

	LIST<int> list_2;
	initList(list_2);
	std::cout << "\n\n";
	
	std::cout << "\n______________________________________\n";
	std::cout << "\n    GROUP: " << list_2;
	std::cout << "______________________________________\n";

	//Добавление группы в начало списка
	list.add_group_to_head(list_2);
	std::cout << "\n    ADD_GROUP_TO_HEAD:            " << list;

	//Удаление группы
	list.del_group(list_2);
	std::cout << "    DEL_GROUP:                    " << list;

	//Добавление группы в конец списка
	list.add_group_to_tail(list_2);
	std::cout << "\n    ADD_GROUP_TO_TAIL:            " << list;

	//Удаление группы
	list.del_group(list_2);
	std::cout << "    DEL_GROUP:                    " << list;

	/*LIST<int> list_4;
	list_4.add_to_tail(40);
	list_4.add_to_tail(50);
	list_4.add_to_tail(60);
	list_4.add_to_tail(70);*/

	//Добавление группы после элемента
	list.add_group_after(list_2, 3);
	std::cout << "\n    ADD_GROUP_AFTER([3]):         " << list;

	//Удаление группы
	list.del_group(list_2);
	std::cout << "    DEL_GROUP:                    " << list;

	//Добавление группы перед элементом
	list.add_group_before(list_2, 1);
	std::cout << "\n    ADD_GROUP_BEFORE([1]):        " << list;
	
	//Удаление группы
	list.del_group(list_2);
	std::cout << "    DEL_GROUP:                    " << list;

	//Замена первого элемента на 2022
	list.change_by_pointer(0, 2022);
	std::cout << "\n    CHANGE_BY_POINTER([0], 2022): " << list;
	

	LIST<double> list_3;
	std::ifstream file_2("test_2.txt");
	list_3.create_by_queue(file_2);

	std::cout << "\n\n___________________________\n";
	std::cout << "\n    LIST 2: " << list_3;
	std::cout << "___________________________\n";
	return 0;
}