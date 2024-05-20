# Описание задачи

Реализуйте бинарный поиск на массиве чисел, отсортированном в неубывающем порядке. Запрещается использование готовых функций бинарного поиска из стандартных библиотек.

## Формат входных данных

1. В первой строке записано целое число n — количество чисел в массиве (0 ≤ n ≤ 300000).
2. Во второй строке через пробел записаны n чисел массива. Все числа целые и принадлежат промежутку от -2³¹ до 2³¹ - 1 включительно. Числа в массиве упорядочены по неубыванию.
3. В третьей строке записано целое число k — количество запросов (0 ≤ k ≤ 300000).
4. В четвертой строке через пробел записаны k целых чисел-запросов из промежутка от -2³¹ до 2³¹ - 1 включительно.

## Формат выходных данных

Для каждого числа-запроса x в отдельной строке выведите через пробел числа b, l и r, где:
- b равно 1, если x присутствует в массиве, или 0 в противном случае;
- l — индекс первого элемента, большего либо равного x;
- r — индекс первого элемента, большего x.

Элементы массива нумеруются индексами от 0 до n-1. Если подходящих элементов в массиве нет, договоримся, что возвращаемый индекс будет равен n.