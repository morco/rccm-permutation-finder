//
// Created by hardieck on 9/27/19.
//

#include "../inc/rccm.h"
#include "../inc/calc_rccm_C1.h"

rccm::rccm()
{

}

bool rccm::set_config(std::string input_config)
{
	// read a string with configuration specifications and generate the subconfigurations out of it
	// to configure the selective adder in terms of possible operation sets and the current used one.
	return false;
}

bool rccm::next_config(config_level)
{

    return 1; // there are still configs with this config level
    return 0; // no config left. this was the last one
}
std::set<int>* rccm::compute()
{
    
    this->clear_calc_data();
    from_sp_use=0; // TODO: Fix!!! THis has to be the current type from the permutation list.
    switch(rccm_search_space[from_sp_use])
    {
        case typ_C1: calc = new calc_rccm_C1; break;
        case typ_C2: ERROR("Type B is not supported yet", "rccm::compute()") break;
        case typ_C3: ERROR("Type C is not supported yet", "rccm::compute()") break;
        case typ_C4: ERROR("Type D is not supported yet", "rccm::compute()") break;
        default: ERROR("Invalid Type","rccm::compute()");
    }

    return calc->compute(this);
}

bool rccm::parse_config_string(string) {
    return false;
}


selective_add* rccm::get_sel_add(unsigned int no)
{
    return &(sel_add[no]);
}

void rccm::clear_calc_data()
{
    if (this->calc != nullptr)
    {
        delete calc;
    }
}
