//
// Created by hardieck on 9/27/19.
//

#ifndef ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H
#define ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H

#include "debug.h"
#include "base_obj.h"
#include "calc_base.h"
#include "permutator.h"

#include <vector>
#include <set>

class selective_add : public config_reset_base
{
public:

    selective_add();
    std::set<int>* compute();
    void init();
    calc_base* calc = nullptr;

    void reset_config(); // reset the current config counters to the initial values specified by min-shift max-shift and possible operations.
    bool next_config(config_helper_obj& conv_helper); // go to the next configuration. (return false if it was the last configuration. true otherwise)
    std::set<int> get_operation_set(); // read out set from coresponding permutaotr and interprate it
    int get_shift(unsigned int input_no); // read out set from coresponding permutaotr and interprate it

    void set_mode_list();
    std::vector<sel_add_type> sel_add_search_space;
    unsigned int from_sp_use;
    void clear_calc_data();
    void init_permutators();

protected:
    Permutator perm_shift;
    Permutator perm_operation;

};

std::set<int>* gen_shift(std::set<int>* input_set, int shift);


#endif //ADDNET_PERMUTATOR_V2_SELECTIVE_ADD_H


