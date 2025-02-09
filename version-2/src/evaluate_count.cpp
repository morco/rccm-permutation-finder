//
// Created by hardieck on 12/5/21.
//

#include "../inc/evaluate_count.h"

evaluate_count::evaluate_count()
{
    count_size = false;
    count_sets = false;
    use_metric = false;
    metric = nullptr;
    v_config.clear();
    v_coeff_sets.clear();
    v_count.clear();
    v_score.clear();
    counted_cases =0;
}
evaluate_count::~evaluate_count()
{
}

double evaluate_count::evaluate(const string &config,const std::set<int> &inputs)
{
    IF_VERBOSE(5) ENTER_FUNCTION("evaluate_count::evaluate(const string &config,const std::set<int> &inputs)")
    ++counted_cases;
    if (count_size){return evaluate_count_size(config,inputs);}
    if (count_sets){return evaluate_count_sets(config,inputs);}
    ERROR("No evaluation option is specified! Configure First!","evaluate_count::evaluate(string config,std::set<int> inputs)")
}
int evaluate_count::configure(string parameter)
{
    //TODO implement configer function for evaluate_count
    return 0;
}
void evaluate_count::print_configure_help()
{
    //TODO implement print_configure_help function for evaluate_count
}
void evaluate_count::print_result()
{
    IF_VERBOSE(5) ENTER_FUNCTION("void evaluate_count::print_result()")

    std::cout << "Tested Cases: " << counted_cases;
    if(this->count_sets) // outpout only makes sense for count sets
        {std::cout << " Found: " << v_config.size()-1 << " different sets" <<  std::endl;}// -1 cause zero is excluded
    else
        {std::cout << std::endl;} // just finish line
    std::cout << "Size\tcount\tScore\tConfig\tCoefficient Set" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    for(int i = 1; i < v_config.size(); ++i) // there are no sets with size 0...
    {
        std::cout << i <<"\t" << v_count[i]<<"\t" << v_score[i] << "\t" << v_config[i] << "\t" << v_coeff_sets[i] << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    IF_VERBOSE(5) LEAVE_FUNCTION("void evaluate_count::print_result()")
}

double evaluate_count::evaluate_count_size(const string &config,const std::set<int> &inputs)
{
    IF_VERBOSE(6) ENTER_FUNCTION("evaluate_count::evaluate_count_size(const string &config,const std::set<int> &inputs)")
    if(use_metric)
    {// use a metric to find best fitting case for the size
        int size = inputs.size();
        if (v_config.size() < size+1) // a bigger result was found and all vectors must be extended
        {
            v_config.resize(size+1);
            v_coeff_sets.resize(size+1);
            v_count.resize(size+1);
            v_score.resize(size+1);
        }
        if(v_count[size] == 0)// there was no result with this size before
        {
            v_config[size] = config; // save config for this result
            v_coeff_sets[size] = inputs; // save coeffs for this result
            ++v_count[size]; // increase counter for results with this size
            v_score[size] = this->metric->evaluate(config,inputs);
        }
        else// there was a result with this size before
        {
            ++v_count[size]; // increase counter for results with this size
            double new_score = this->metric->evaluate(config,inputs);
            if(v_score[size] < new_score)
            {
                v_config[size] = config;
                v_coeff_sets[size] = inputs;
                v_score[size] = new_score;
            }
        }
    }
    else
    {// just Count corresponding size's and keep one example
        int size = inputs.size();
        if (v_config.size() < size+1) // a bigger result was found and all vectors must be extended
        {
            v_config.resize(size+1);
            v_coeff_sets.resize(size+1);
            v_count.resize(size+1);
            v_score.resize(size+1);
        }
        if(v_count[size] == 0)// there was no result with this size before
        {
            v_config[size] = config; // save config for this result
            v_coeff_sets[size] = inputs; // save coeffs for this result
            ++v_count[size]; // increase counter for results with this size
            //v_score[size]; // unused in this case
        }
        else// there was a result with this size before
        {
            ++v_count[size]; // increase counter for results with this size
        }


    }
    return 0;
}

double evaluate_count::evaluate_count_sets(const string &config,const std::set<int> &inputs)
{
    for(int i =0; i< v_coeff_sets.size();++i)
    {
        if(v_coeff_sets[i] == inputs) // if true there is a match with a previus found set!
        {
            ++(v_count[i]);
            return 0;
        }
    }// it ends without a match a new set was found
    v_config.push_back(config);
    v_coeff_sets.push_back(inputs);
    v_count.push_back(1);
    if(use_metric)
    {
        v_score.push_back(this->metric->evaluate(config,inputs));
    }
    else
    {
        v_score.push_back(0);
    }
    return 0;
}
