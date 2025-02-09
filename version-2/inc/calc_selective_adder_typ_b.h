//
// Created by hardieck on 10/8/19.
//

#ifndef ADDNET_PERMUTATOR_V2_CALC_SELECTIVE_ADDER_TYP_B_H
#define ADDNET_PERMUTATOR_V2_CALC_SELECTIVE_ADDER_TYP_B_H
#include "calc_selective_adder_base.h"

class calc_selective_adder_typ_b : public calc_selective_adder_base
{
    public:
    calc_selective_adder_typ_b()
    {
        IF_VERBOSE(6) ENTER_FUNCTION("calc_selective_adder_typ_b::calc_selective_adder_typ_b()")
        init();
    };
    virtual sel_add_type type() const {return typ_B;}
    std::set<int>* compute(base_obj *parent_);
    virtual const spec_sel_add get_spec();
private:
    const spec_sel_add spec = spec_sel_add(2,1,13,4,{{1,3,6,8}});
    //DO NOT USE local spec value!!! use get_spec()! cause derived classes overload get_spec() but don't overload spec...
};

#endif //ADDNET_PERMUTATOR_V2_SELECTIVE_ADDER_TYPE_B_H
