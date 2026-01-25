#include<iostream>

struct Point 
{
	int x;
	int y;
};

const size_t ELEMENTS = 5;

long findSeq(const char* arr, char S);
long myMax(long a, long b);
bool findWord(const char* const* grid, size_t M, size_t N, const char* word);
size_t myStrlen(const char* str);
int containsAt(const char* str, char c, bool* visited);
int* findSets(const int* arr, size_t N, size_t& size);
int myPow(int num, int pow);

int main()
{
	/*char str[1024];
	std::cin.getline(str, 1024);

	char c;
	std::cin >> c;

	std::cout << findSeq(str, c) << std::endl;*/

	/*size_t m, n;

	std::cin >> m >> n;

	char** grid = new char*[m];

	for (size_t i = 0; i < m; i++)
	{
		grid[i] = new char[n];
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> grid[i][j];
		}
	}

	char word[1024];
	std::cin >> word;

	std::cout << std::boolalpha << findWord(grid, m, n, word) << std::endl;

	for (size_t i = 0; i < m; i++)
	{
		delete[] grid[i];
		grid[i] = nullptr;
	}

	delete[] grid;
	grid = nullptr;*/

	int arr[] = { 1, 2, 3, 4 };
	size_t size = 0;

	int* res = findSets(arr, sizeof(arr) / sizeof(int), size);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << res[i] << " ";
	}

	delete[] res;

	return 0;
}

long findSeq(const char* arr, char S)
{
	if (!arr)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	long max = 0;

	int currLen = 0;

	while (*arr)
	{
		if (*arr != S)
		{
			max = myMax(max, currLen);
			currLen = 0;
		}

		if (*arr == S)
		{
			currLen++;
		}

		arr++;
	}

	if (currLen != 0)
	{
		max = myMax(max, currLen);
	}

	return max;
}

long myMax(long a, long b)
{
	return a > b ? a : b;
}

bool findWord(const char* const* grid, size_t M, size_t N, const char* word)
{
	if (!grid || !word)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return false;
	}

	size_t wordLen = myStrlen(word);

	bool* visited = new bool[wordLen](false);

	struct Point directions[ELEMENTS] = {{0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	for (size_t i = 0; i < M; i++)
	{
		if (!grid[i])
		{
			std::cout << "Null pointer exception!" << std::endl;
			return false;
		}

		for (size_t j = 0; j < N; j++)
		{
			for (size_t k = 0; k < ELEMENTS; k++)
			{

				int dirY = i + directions[k].y;
				int dirX = j + directions[k].x;

				if (dirY < 0 || dirX < 0
					|| dirY > M - 1 || dirX > N - 1)
				{
					continue;
				}

				int index = containsAt(word, grid[dirY][dirX], visited);

				if (index != -1)
				{
					visited[index] = true;
				}
			}

			bool visitedAll = true;

			for (size_t i = 0; i < wordLen; i++)
			{
				if (!visited[i])
				{
					visitedAll = false;
				}
				visited[i] = false;
			}

			if (visitedAll)
			{
				return true;
			}
		}
	}

	delete[] visited;

	return false;
}

size_t myStrlen(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return 0;
	}

	size_t length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return length;
}

int containsAt(const char* str, char c, bool* visited)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	for (size_t i = 0; str[i]; i++)
	{
		if (c == str[i] && !visited[i]) {
			return i;
		}
	}

	return -1;
}

int* findSets(const int* arr, size_t N, size_t& size)
{
	int subsetCount = myPow(2, N);

	int subsetArrSize = N * (subsetCount / 2) + subsetCount;

	size = subsetArrSize;

	int* subsets = new int[subsetArrSize];

	int* beginning = subsets;

	uint32_t combination = 1;

	for (size_t i = 0; i < subsetCount; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			uint32_t mask = (1 << j);

			if (combination & mask)
			{
				*subsets = arr[j];
				subsets++;
			}
		}

		*subsets = 0;
		subsets++;

		combination ^= (1 << (subsetCount - i) % N);
	}

	return beginning;
}

int myPow(int num, int pow)
{
	int res = 1;

	for (size_t i = 0; i < pow; i++)
	{
		res *= num;
	}

	return res;
}
