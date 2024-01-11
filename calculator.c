#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool runtime=true;

// Kører de forskellige funktioner
void run_calculator(double akkumulator){
    char operator;
    double operand;

    while(runtime==true) {
        scan_data(&operator, &operand);

        if(check_valid_input_operator(operator)==true&&
           check_valid_input_operand(operand)==true )
        {
            do_next_op(operator,operand,&akkumulator);
        }

        if(runtime==true) {
            printf("Your result is: %lf\n", akkumulator);
        }

    }
}

// Laver alle beregningerne
void do_next_op(char operator, double operand, double* akkumulator) {
    if(operator=='+')
    {
        *akkumulator+=operand;
    }

    else if(operator=='-')
    {
        *akkumulator-=operand;
    }

    else if(operator=='*')
    {
        *akkumulator*=operand;
    }

    else if(operator=='/' && (operand!=0))
    {

        *akkumulator/=operand;
    }

    else if(operator=='^')
    {
        *akkumulator=pow(*akkumulator,operand);
    }

    else if(operator=='#' && (*akkumulator>=0))
    {
        *akkumulator=sqrt(*akkumulator);
    }

    else if(operator=='%')
    {
        *akkumulator*=(-1);
    }

    else if(operator=='!')
    {
       *akkumulator=(1/ *akkumulator);
    }

    else if(operator=='q'){
        printf("Your final result is: %lf\n",*akkumulator);
        runtime=false;
    }
}

// Tager bruger input
void scan_data(char* operator, double* operand){

        printf("Input operator\n>");
        scanf(" %c", operator);

        if(check_binary(*operator)==true)
        {
            printf(" Input operand\n>");
            scanf(" %lf", operand);
        }
}

// Tjekker om operatoren er valid
bool check_valid_input_operator(char valid_operator){
    return (valid_operator == '+'||
        valid_operator == '-'||
        valid_operator == '*'||
        valid_operator == '/'||
        valid_operator == '^'||
        valid_operator == '#'||
        valid_operator == '%'||
        valid_operator == 'q'||
        valid_operator == '!');

}



// Funktion til at tjekke om brugerens operand input er gyldigt. Funktionen er sand hvis input er gyldigt
bool check_valid_input_operand(double valid_operand)
{
    return !isnan(valid_operand) && isfinite(valid_operand);
}


// Funktion til at tjekke om brugerens input er en binær operator
bool check_binary(char check_operator){
    return( check_operator == '+' ||
        check_operator == '-' ||
        check_operator == '*' ||
        check_operator == '/' ||
        check_operator == '^');
}