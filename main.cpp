#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

// Hash Libraries //
#include "src/sha1.h"
using namespace std;

bool verbose;

void sha1_crack(string hash, string file);


int main(int argc, char* argv[]) {
	if(argc < 4) {
		cout << " Usage : ./program [hash_type] [hash_value] [dict_file] [-v]"
	} else if(argc == 4 || argc == 5) {
		string type = argv[1];
		string hash = argv[2];
		string dict = argv[3];
		std::ifstream file(dict);
		if(file.is_open()) {
			if (argc == 5) {
				verbose = true;
			} else {
				verbose = false;
			}
			cout << "Uses Crypt++ library for C++" << endl;
			cout << "Dictionary: " << dict << endl;

			if(type == "SHA1" || type == "sha1"){
				cout << "Hashing algorithm: SHA1" << endl;
                                cout << "Cracking..." << endl << endl;
				sha1_crack(hash, dict);

		} else {
			cout << endl << "File could not be found." << endl;
		}
	} else {
			;
	}
}
}
// CRACKING //

void sha1_crack(string hash, string filename) {
        int tries = 0;
        std::ifstream file(filename);
        string pass;
        while(file >> pass) {
                tries++;
                string hash_sum = sha1(pass);
                if (hash_sum == hash) {
                        cout << "[" << tries << "] - PASSWORD FOUND - " << pass << endl;
                        exit(0);
                } else {
			if (verbose == true) {
				cout << "[" << tries << "] - FAILED ATTEMPT - " << pass << endl;
			}
                }
        }
}
