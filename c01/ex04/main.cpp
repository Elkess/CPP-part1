#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileReplacer {
public:
	FileReplacer(const std::string &fn, const std::string &from, const std::string &to)
		: filename(fn), s1(from), s2(to), outname(fn + ".replace") {}
	bool valid() const { return !s1.empty(); }
	bool process() {
		std::ifstream in(filename.c_str());
		if (!in)
			return false;
		std::ostringstream buf;
		buf << in.rdbuf();
		content = buf.str();
		in.close();
		std::ofstream out(outname.c_str());
		if (!out)
			return false;
		std::string::size_type pos = 0;
		std::string::size_type found;
		while ((found = content.find(s1, pos)) != std::string::npos) {
			out << content.substr(pos, found - pos) << s2;
			pos = found + s1.length();
		}
		out << content.substr(pos);
		out.close();
		return true;
	}
private:
	std::string filename;
	std::string s1;
	std::string s2;
	std::string outname;
	std::string content;
};

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage: ./replace_file filename s1 s2" << std::endl;
		return 1;
	}
	FileReplacer r(av[1], av[2], av[3]);
	if (!r.valid()) {
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}
	if (!r.process()) {
		std::cerr << "Error: processing failed (file open/write)" << std::endl;
		return 1;
	}
	return 0;
}
