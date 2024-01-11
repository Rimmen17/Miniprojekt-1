#include <stdbool.h>

void do_next_op(char operator, double operand, double* akkumulator);
void scan_data(char* operator, double* operand);
void run_calculator(double akkumulator);
bool check_binary(char check_operator);
bool check_valid_input_operand(double valid_operand);
bool check_valid_input_operator(char valid_operator);