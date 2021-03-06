#ifndef SNIP_WRITER_HPP
#define SNIP_WRITER_HPP

#include <map>
#include <string>

class snip_writer {
public:
	snip_writer(std::string fp);
	void write_snips(const std::map<std::string,std::map<std::string,int> >  &snip_db);

private:
	std::string _fp;
};


#endif // SNIP_WRITER_HPP
