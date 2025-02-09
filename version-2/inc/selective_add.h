//
// Created by hardieck on 9/27/19.
//

#ifndef ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H
#define ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H

#include "debug.h"
#include "base_obj.h"
#include "calc_base.h"
#include "permutator.h"
#include "search_space_plan.h"

#include <vector>
#include <set>

class selective_add : public config_reset_base
{
public:
    selective_add();
    ~selective_add();
    std::set<int>* compute();
    void init(shared_ptr<search_space_plan> _ssp = nullptr, int _sel_add_pos=-1,rccm_type _current_rccm_type=rccm_type_NAN);
    calc_base* calc = nullptr;


    std::string get_config();// return only the part for one Selective add with shifts in HM1 standart
    bool set_config(std::string new_config);// use only the part for one Selective add with shifts in HM1 standart

    void reset_config(); // reset the current config counters to the initial values specified by min-shift max-shift and possible operations.
    bool next_config(config_helper_obj& conv_helper); // go to the next configuration. (return false if it was the last configuration. true otherwise)

    spec_sel_add get_spec();
    std::set<int> get_operation_set(); // read out set from coresponding permutaotr and interprate it
    int get_shift(unsigned int input_no); // read out set from coresponding permutator and interprate it
    const sspk get_current_key() const; // returns a key of the current possition in search space

    void set_mode_list();
    std::vector<sel_add_type> sel_add_search_space;
    unsigned int from_sp_use;
    void delete_calc();// clear all intermediate calculation data
    void init_permutators(); // initializes both permutators depending on current selective adder type ad resets them

//protected:
    Permutator perm_shift;
    Permutator perm_operation;

    rccm_type current_rccm_type;
    int sel_add_pos; // position of selective add in rccm;
    shared_ptr<search_space_plan> ssp;
};

std::set<int>* gen_shift(std::set<int>* input_set, int shift);


#endif //ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H


