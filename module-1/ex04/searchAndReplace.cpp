#include <string>
#include <iostream>
#include <fstream>

/* Get the end index to skip to the end part that doesn't have 'search': we move the base until we can't find search and we store the endIndex */

std::string getBegBase(const std::string& base, const std::string& search)
{
	std::string begBase;
	begBase = base.substr(0, base.find(search));
	return begBase;
}

/* Pos is `base.find(search)` , len is `search.length()` (how many characters we put out) */
std::string my_replace(const std::string& base, size_t pos, size_t len, const std::string& replace)
{
	// part 1 + replace + part 2
	std::string replaced;
	std::string begBase = base.substr(0, pos);
	std::string endBase = base.substr(pos + len);
	replaced.append(begBase).append(replace).append(endBase);

	return replaced;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error argc != 4\n";
		return 0;
	}
	if (!argv[1] || !argv[2] || !argv[3])
	{
		std::cout << "Error argv\n";
		return 0;
	}

	std::string filename = std::string(argv[1]);
	std::string search = std::string(argv[2]);
	std::string replace = std::string(argv[3]);

	if (filename.empty())
		return (std::cout << "No filename provided\n", 0);
	if (search.empty())
		return (std::cout << "No search string provided\n", 0);

	std::ifstream infile(filename);
	if (!infile.is_open())
		return (std::cout << "Error. Can't open file.\n", 0);
	std::string base;
	std::ofstream outfile(filename + ".replace");

	while (std::getline(infile, base))
	{
		int offset = 0;
		while (base.find(search, offset) != std::string::npos)
		{
			size_t pos = base.find(search, offset);
			base = my_replace(base, base.find(search, offset), search.length(), replace);
			offset = pos + replace.length();
		}
		outfile << base; 
		if (!infile.eof())
			outfile << std::endl;
	}
	return 0;
}
