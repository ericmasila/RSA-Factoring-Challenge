#ifndef __HEADER_H_FILE__
#define __HEADER_H_FILE__

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#define LEN 18

using namespace std;
typedef long long int llint;

/**
 * @brief RsaRef Object
 *
 */
class RSARef
{
public:
	/**
	 * @brief Construct a new Rsa Ref object
	 *
	 * @param line string numbers
	 */
	RSARef(char *fileName)
	{
		file = fileName;
	}

	void run(void)
	{
		handler(file);
	}

private:
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
				if (k.empty())
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

protected:
	char *file;

};

class RSAPrime
{
public:
	/**
	 * @brief Construct a new Rsa Prime object
	 *
	 * @param line string numbers
	 */
	RSAPrime(char *fileName)
	{
		file = fileName;
	}

	void run(void)
	{
		handler(file);
	}

private:
	/**
	 * @brief Handle large numbers
	 *
	 * @param line string numbers
	 */
	void big_nums(string line)
	{
		cout << line << endl;
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

		for (; x < num; x++)
		{
			if (num % x == 0)
			{
				if (!isprime(x))
					continue;
					
				if (isprime(num / x))
					break;
			}
		}

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

	bool isprime(llint num)
	{
		if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 )
			return true;

		for (int i = 2 ; i < num; i++)
		{
			if (num % i == 0)
				return false;
		}

		return true;
	}

protected:
	char *file;

};

#endif
