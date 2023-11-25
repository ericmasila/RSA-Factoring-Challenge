#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#define LEN 19

using namespace std;
typedef long long int llint;

/**
 * @brief RsaRef Object
 *
 */
class RsaRef
{
public:
	/**
	 * @brief Construct a new Rsa Ref object
	 *
	 * @param line string numbers
	 */
	RsaRef(char *fileName)
	{
		file = fileName;
	}

	void run(void)
	{
		handler(file);
	}

private:
	char *file;
	/**
	 * @brief Handle large numbers
	 *
	 * @param line string numbers
	 */
	void big_nums(string line)
	{
		string num[1024];
		string res = "";
		int i, j;

		j = line.length() / LEN;
		j += line.length() % LEN ? 1 : 0;

		for (i = 0; i < j; i++)
			num[i] = line.substr(i * LEN, LEN);

		llint val, rem, x;
		string s_val, ne_val;
		for (x = 2; 1; x++)
		{
			res = "";
			ne_val = "";
			for (auto k : num)
			{
				if (!atoll(k.c_str()))
					break;
				s_val = ne_val + k;
				val = atoll(s_val.c_str()) / x;
				rem = atoll(s_val.c_str()) % x;
				ne_val = rem ? to_string(rem) : "";
				res += to_string(val);
			}
			if (!rem)
				break;
		}

		cout << line << "=" << res << "*" << x << endl;
	}

	/**
	 * @brief Handle small numbers
	 *
	 * @param line string numbers
	 */
	void small_nums(string line)
	{
		llint num = atoll(line.c_str());
		llint x = 2;

		for (; 1; x++)
			if (num % x == 0)
				break;

		cout << line << "=" << num / x << "*" << x << endl;
	}

	void handler(char *fileName)
	{
		ifstream file(fileName);
		string line;

		for (; getline(file, line);)
		{
			if (line.length() <= 19)
				small_nums(line);
			else
				big_nums(line);
		}
		file.close();
	}
};

/**
 * @brief Entry point
 *
 * @param av char array
 * @return int Always 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	RsaRef fact(av[1]);

	fact.run();

	return (0);
}
