#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "args.hpp"
#include "snip_parser.hpp"
#include "fasta_reader.hpp"
#include "sam_reader.hpp"

using namespace std;

void print_reads(const std::unordered_map<std::string,std::vector<std::string> > reads) {
	for(auto key = reads.begin(); key != reads.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			cout << *val << endl;
		}
	}
}

void print_records(map<string,string> &r) {
	for(auto it = r.begin(); it != r.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

int main(int argc, const char *argv[]) {
	fasta_reader fr(argv[1]);
	map<string,string> records = fr.read();

	sam_reader sr(argv[2], 0);
	std::unordered_map<std::string,std::vector<std::string> > alignments = sr.read();

	for(auto key = alignments.begin(); key != alignments.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			find_snips(records, *val);
		}
	}	
	

	return 0;
}
