#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;


struct TodoItem {
	string title;       
	int priority = 0;      
	string description; 
	string data;   
};


struct TodoList
{
	TodoItem items[MAX_ITEMS]; 
	int size = 0;              

	
	void addItem(string title, string description, string datetime, int priority) {
		if (size < MAX_ITEMS) { 
			items[size++] = { title, priority, description, datetime };
		}
	}
	void removeItem(string title) {
		int index = -1;
		for (int i = 0; i < size; ++i) { 
			if (items[i].title == title) { 
				index = i;
				break; 
			}
		}
		if (index != -1) { 
			for (int i = index; i < size - 1; ++i) {
				items[i] = items[i + 1];
			}
			size--; 
		}
	}


	void editItem(string title, int priority, string description, string datetime) {
		for (int i = 0; i < size; ++i) { 
			if (items[i].title == title) { 
				
				items[i].priority = priority;
				items[i].description = description;
				items[i].data = datetime;
				break; 
			}
		}
	}

	
	void displayItems() {
		for (int i = 0; i < size; ++i) {
			TodoItem item = items[i]; 
			
			cout << "Title: " << item.title << ", Priority: " << item.priority << ", Description: " << item.description << ", Datetime: " << item.data << endl;
		}
	}

	
	void searchByTitleFromConsole() {
		string searchTerm;
		cout << "Введите название для поиска: ";
		getline(cin, searchTerm); 
		bool found = false;
		for (int i = 0; i < size; ++i) { 
			if (items[i].title == searchTerm) { 
				found = true;
				
				cout << "Title: " << items[i].title << ", Priority: " << items[i].priority << ", Description: " << items[i].description << ", Datetime: " << items[i].data << endl;
			}
		}
		if (!found) { //
			cout << "Ничего не найдено" << endl; 
		}
	}


	
	void searchByPriority(int priority) {
		bool found = false;
		for (int i = 0; i < size; ++i) { 
			if (items[i].priority == priority) { 
				found = true;
			
				cout << "Title: " << items[i].title << ", Priority: " << items[i].priority << ", Description: " << items[i].description << ", Datetime: " << items[i].data << endl;
			}
		}
		if (!found) { 
			cout << "Ничего не найдено с приоритетом " << priority << endl; 
		}
	}


	void searchByDescription(string description) {
		
		bool found = false;
		for (int i = 0; i < size; ++i) { 
			if (items[i].description == description) { 
				found = true;
				
				cout << "Title: " << items[i].title << ", Priority: " << items[i].priority << ", Description: " << items[i].description << ", Datetime: " << items[i].data << endl;
			}
		}
		if (!found) { 
			cout << "Ничего не найдено с описанием \"" << description << "\"" << endl; 
		}
	}

	
	void searchByDateTime(string datetime) {
		bool found = false;
		for (int i = 0; i < size; ++i) { 
			if (items[i].data == datetime) { 
				found = true;
		
				cout << "Title: " << items[i].title << ", Priority: " << items[i].priority << ", Description: " << items[i].description << ", Datetime: " << items[i].data << endl;
			}
		}
		if (!found) {
			cout << "Ничего не найдено с датой и временем исполнения \"" << datetime << "\"" << endl; 
		}
	}



	void displayItemsForDay(string date) {
	
	}

	void displayItemsForWeek(string start_date, string end_date) {
		
	}

	void displayItemsForMonth(string month) {
	
	}

	void addItemsFromconsole() {
		int index = 0;
		string title;
		int priority;
		string description;
		string datetime;
		cout << "название " << endl;
		getline(cin, title);
		cout << "описание" << endl;
		getline(cin, description);
		cout << "время" << endl;
		getline(cin, datetime);
		cout << "приоритет" << endl;
		cin >> priority;
		if (size < MAX_ITEMS) { 
			items[size++] = { title, priority, description, datetime }; }

		addItem(title, description, datetime, priority);
		index++;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	TodoList todoList;
	
	todoList.addItem("shop", "buy milk and tea", "13.02.2024 10:00", 1);
	todoList.addItem("school", "wright an essay", "15.02.2024 15:00", 2);
	
	//todoList.addItemsFromconsole();

	//todoList.searchByTitleFromConsole();
	//todoList.removeItem("school");

	//todoList.searchByPriority(1);
	//todoList.displayItems();

	//todoList.searchByDescription("buy milk and tea");

	//todoList.searchByDateTime("13.02.2024 10:00");


	//-----------------------------------------------------------------------------------------------------------------------------------------------------------
	//todoList.displayItemsForDay("15");
	//todoList.displayItemsForMonth("2");
	//todoList.displayItemsForWeek("2", "7");


	int choice;

	do {
		cout << "Меню:" << endl;
		cout << "1. Добавить задачу" << endl;
		cout << "2. Удалить задачу" << endl;
		cout << "3. Редактировать задачу" << endl;
		cout << "4. Отобразить список задач" << endl;
		cout << "5. Поиск по названию" << endl;
		cout << "6. Поиск по приоритету" << endl;
		cout << "7. Поиск по описание" << endl;
		cout << "0. Выйти из программы" << endl;
		cout << "Выберите действие: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			//todoList.addItemsFromconsole();
				string title, description, datetime;
				int priority;
				
				cout << "Введите название задачи: " << endl;
				getline(cin, title);
				cout << "Введите описание задачи: ";
				getline(cin, description);
				cout << "Введите дату и время задачи: ";
				getline(cin, datetime);
				cout << "Введите приоритет задачи: ";
				cin >> priority;
				
				
				todoList.addItem(title,  description, datetime, priority);
			break;
		}
	
		case 2: {
			string title;

			cout << "Введите название задачи для удаления: ";
			cin >> title;
			todoList.removeItem(title);
			break;
		}
		case 3: {
			string title, description, datetime;
			int priority;
			cout << "Введите название задачи для редактирования: ";
			cin >> title;                                                                   
			cout << "Введите новое описание задачи: ";
			cin >> description;
			cout << "Введите новую дату и время задачи: ";
			cin >> datetime;
			cout << "Введите новый приоритет задачи: ";
			cin >> priority;
			todoList.editItem(title, priority, description, datetime);
			break;
		}

		
		case 4:
			todoList.displayItems();
			break;
		case 5:
			todoList.searchByTitleFromConsole();
			break;
		case 6:
			int priority;
			cin >> priority;
			todoList.searchByPriority(priority);
			break;
		case 7:{
			string description;
			getline(cin, description);
			todoList.searchByDescription(description);
			break; }
		case 0:
			cout << "Выход из программы." << endl;
			break;
		default:
			cout << "Неверный выбор. Попробуйте снова." << endl;
		}
	} while (choice != 0);
	return 0;
}
