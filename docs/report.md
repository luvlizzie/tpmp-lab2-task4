# Отчет по заданию 4
## Студент: Кудинова Елизавета, группа 12
## Вариант 11

### Описание структуры Student
Структура содержит поля:
- Фамилия, имя, отчество
- Пол, национальность
- Рост (см), вес (кг)
- Дата рождения (год, месяц, день)
- Номер телефона
- Домашний адрес (почтовый индекс, страна, область, район, город, улица, дом, квартира)
- ВУЗ, курс, группа
- Средний балл
- Специальность

### Реализованные функции
1. `create_initial_file` - создание файла с тестовыми данными
2. `load_from_file` - загрузка данных из файла
3. `save_to_file` - сохранение всех данных в файл
4. `add_student` - интерактивное добавление студента
5. `print_all_students` - вывод всех студентов
6. `find_low_performers` - поиск студентов со средним баллом < 7.0
7. `print_low_performers_to_file` - сохранение результатов в отдельный файл

### Тестирование программы

#### Тест 1: Создание исходного файла
| Действие | Результат |
|----------|-----------|
| Выбор пункта меню 1 | Файл data/students.txt создан с 5 тестовыми студентами |

#### Тест 2: Загрузка данных из файла
| Действие | Результат |
|----------|-----------|
| Выбор пункта меню 2 | Загружено 5 студентов, сообщение "Successfully loaded 5 students" |

#### Тест 3: Просмотр всех студентов
| Действие | Результат |
|----------|-----------|
| Выбор пункта меню 4 | Все 5 студентов отображены корректно с полной информацией |

#### Тест 4: Поиск студентов со средним баллом ниже 7.0

**Ожидаемый результат:** Должны найтись студенты с баллами 6.2, 6.8, 5.9 (3 человека)

**Фактический результат:**
=== Students with average grade below 7.0 ===

Ivanov Ivan Ivanovich (grade: 6.20)
Sidorova Anna Sergeevna (grade: 6.80)
Novikov Alexey Sergeevich (grade: 5.90)
Total: 3 students

**Тест пройден:** Да

#### Тест 5: Сохранение результатов в файл
| Действие | Результат |
|----------|-----------|
| Выбор пункта меню 6 | Файл data/low_performers.txt создан |

Содержимое файла `data/low_performers.txt`:
Students with average grade below 7.0:

1. Ivanov Ivan Ivanovich
Sex: M
Nationality: Russian
Birth date: 2000-05-15
University: BSU, Course: 3, Group: 11
Average grade: 6.20
Speciality: Computer Science
1. Sidorova Anna Sergeevna
Sex: F
Nationality: Russian
Birth date: 2000-11-03
University: BSU, Course: 3, Group: 11
Average grade: 6.80
Speciality: Computer Science
1. Novikov Alexey Sergeevich
Sex: M
Nationality: Russian
Birth date: 2001-12-01
University: BSU, Course: 2, Group: 12
Average grade: 5.90
Speciality: Mathematics
Total: 3 students

#### Тест 6: Проверка граничных случаев
| Ситуация | Ожидание | Реальность |
|----------|----------|------------|
| Пункт 4 без загруженных данных | Сообщение "No students loaded" | "No students loaded. Please load from file or add new students." |
| Пункт 5 без загруженных данных | Сообщение "No students loaded" | "No students loaded. Please load from file first." |
| Пункт 6 без загруженных данных | Сообщение "No students loaded" | "No students loaded. Please load from file first." |

### Проверка GitHub Actions
GitHub Actions успешно выполняет сборку проекта:
- Создаются директории obj, bin, data
- Компиляция проходит без ошибок
- Тестовый запуск выполняется корректно

### Вывод
Все функции работают корректно, требования задания выполнены:
- Структура Student реализована со всеми полями
- Программа работает с текстовыми файлами (чтение/запись)
- Реализован поиск студентов со средним баллом ниже 7.0
- Результаты сохраняются в отдельный файл
- Модель КИС соблюдена (отдельные файлы .h и .c)
- Нет глобальных переменных
- Makefile работает
- GitHub Actions настроен
