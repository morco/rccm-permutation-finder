//
// Created by hardieck on 9/27/19.
//

#ifndef ADDNET_PERMUTATOR_V2_CALC_SELECTIVE_ADDER_TYP_A_H
#define ADDNET_PERMUTATOR_V2_CALC_SELECTIVE_ADDER_TYP_A_H
#include "calc_selective_adder_base.h"

class calc_selective_adder_typ_a : public calc_selective_adder_base
{
    public:
    calc_selective_adder_typ_a();
	std::set<int> compute();
};


#endif //ADDNET_PERMUTATOR_V2_CALC_SELECTIVE_ADDER_TYP_A_H
