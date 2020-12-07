//
// Created by hardieck on 9/27/19.
//

#ifndef ADDNET_PERMUTATOR_V2_CONFIG_RCCM_H
#define ADDNET_PERMUTATOR_V2_CONFIG_RCCM_H

#define VERBOSE(x):

#include "debug.h"
#include "config_selective_add.h"
#include <vector>
#include "permutator.h"
#include <string>

class config_rccm
{
public:
	config_rccm();

	std::string get_config();
	std::string get_config_for_implementation();
	bool set_config(std::string input_config);

	std::vector<config_selective_add> conf_list;
	std::vector<int> add_sell_type_alternatives; // don't know how this will be work when finishes...
	bool next_config();

private:
	std::vector<int> config;

};


#endif //ADDNET_PERMUTATOR_V2_CONFIG_RCCM_H
