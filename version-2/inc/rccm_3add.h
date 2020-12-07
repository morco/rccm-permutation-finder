//
// Created by hardieck on 9/27/19.
//

#ifndef ADDNET_PERMUTATOR_V2_RCCM_3ADD_H
#define ADDNET_PERMUTATOR_V2_RCCM_3ADD_H

#include "rccm_base.h"
#include "selective_adder_typ_a.h"
#include "selective_adder_typ_b.h"

class rccm_3add : public rccm_base
{
public:
	rccm_3add()
	{
        IF_VERBOSE(9) std::cout << "Enter Funktion: rccm_3add/construktor:" << std::endl;

		this->config = new config_rccm();
		this->results.push_back(new evaluate_result());
		this->s_add.push_back(new selective_adder_typ_a());
		this->s_add.push_back(new selective_adder_typ_b());

	}
	std::set<int>compute()
	{
	    IF_VERBOSE(5) std::cout << "Enter funktion: rccm_3add/compute" << std::endl;
		//example computation...:
		std::set<int> input;
		input.insert(1);

        IF_VERBOSE(1) std::cout << "specify connection of first container (selective_adder_typ_a)" << std::endl;
		//specify connection of first container (selective_adder_typ_a)
        IF_VERBOSE(1) std::cout << "get_no_of_inputs()=" << s_add[0]->get_no_of_inputs() << std::endl;
		s_add[0]->set_inputs(0,input);
		s_add[0]->set_inputs(1,input);
		s_add[0]->set_inputs(2,input);
        s_add[0]->set_inputs(3,input);
        IF_VERBOSE(1) std::cout << "first container inputs done" << std::endl;
        IF_VERBOSE(1) std::cout << "first container get_operation_set()" << s_add[0]->convfg->get_operation_set()  << std::endl;
		s_add[0]->compute();
        IF_VERBOSE(1) std::cout << "first container compute done" << std::endl;

        IF_VERBOSE(1) std::cout << "specify connection of second container (selective_adder_typ_b)" << std::endl;
        //specify connection of second container (selective_adder_typ_b)
		s_add[1]->set_inputs(0,s_add[0]->get_output());
		s_add[1]->set_inputs(1,s_add[0]->get_output());
        s_add[1]->set_inputs(2,s_add[0]->get_output());
        s_add[1]->set_inputs(3,s_add[0]->get_output());
		s_add[1]->compute();

		return s_add[1]->get_output();;
	};
};


#endif //ADDNET_PERMUTATOR_V2_RCCM_3ADD_H
