#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Student
{
    string name;
    string surname;
    int age;
};

Student* students = nullptr;
int studentCount = 0;

void showMenu()
{
    cout << "\n       === Меню ===\n";
    cout << "1. Показать всех студентов\n";
    cout << "2. Добавить студента\n";
    cout << "3. Изменить студента\n";
    cout << "4. Удалить студента\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт: ";
}

void showStudents()
{
	if (studentCount == 0)
	{
		cout << "Student list empty." << endl;
		return;
	}
	for (int i = 0; i < studentCount; i++)
	{
		cout << i + 1 << ". " << students[i].name << " " << students[i].surname << ", age: " << students[i].age << endl;
	}
}

void addStudent()
{
    Student s;
    cout << "Введите имя: ";
    cin >> s.name;
    cout << "Введите фамилию: ";
    cin >> s.surname;
    cout << "Введите возраст: ";
    cin >> s.age;

    // Создаем новый массив с размером на 1 больше
    Student* temp = new Student[studentCount + 1];
    // Копируем старые данные
    for (int i = 0; i < studentCount; i++)
        temp[i] = students[i];
    temp[studentCount] = s;
    delete[] students;
    students = temp;
    studentCount++;

    cout << "Студент добавлен.\n";
}

void changeStudent()
{
    if (studentCount == 0)
    {
        cout << "Нет студентов для изменения.\n";
        return;
    }
    showStudents();
    cout << "Введите номер студента для изменения: ";
    int index;
    cin >> index;
    if (index <= 0 || index > studentCount)
    {
        cout << "Неправильный номер.\n";
        return;
    }
    index--;
    cout << "Введите новое имя: ";
    cin >> students[index].name;
    cout << "Введите новую фамилию: ";
    cin >> students[index].surname;
    cout << "Введите новый возраст: ";
    cin >> students[index].age;

    cout << "Данные студента обновлены.\n";
}

void deleteStudent()
{
    if (studentCount == 0)
    {
        cout << "Нет студентов для удаления.\n";
        return;
    }
    showStudents();
    cout << "Введите номер студента для удаления: ";
    int index;
    cin >> index;
    if (index <= 0 || index > studentCount)
    {
        cout << "Неправильный номер.\n";
        return;
    }
    index--;

    Student* temp = new Student[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; i++)
    {
        if (i == index) continue; // пропускаем удаляемый элемент
        temp[j++] = students[i];
    }
    delete[] students;
    students = temp;
    studentCount--;

    cout << "Студент удалён.\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	while (true)
	{
		showMenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			showStudents();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			changeStudent();
			break;
		case 4:
			deleteStudent();
			break;
		case 0:
			delete[] students; // Очистка памяти перед выходом
			cout << "Выход.\n";
			return 0;
		default:
			cout << "Неверный выбор, попробуйте ещё раз.\n";
		}
	}
}
