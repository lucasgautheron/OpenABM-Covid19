/*
 * individual.h
 *
 *  Created on: 5 Mar 2020
 *      Author: hinchr
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

/************************************************************************/
/******************************* Includes *******************************/
/************************************************************************/

#include <gsl/gsl_rng.h>
#include "params.h"
#include "constant.h"

/************************************************************************/
/****************************** Structures  *****************************/
/************************************************************************/

typedef struct interaction interaction;

typedef struct{
	long idx;
	int status;
	int n_mean_interactions;
	int n_interactions[MAX_DAILY_INTERACTIONS];
	interaction *interactions[MAX_DAILY_INTERACTIONS];
} individual;

struct interaction{
	individual *individual;
	interaction *next;
};


/************************************************************************/
/******************************  Functions  *****************************/
/************************************************************************/

void initialize_individual( individual*, parameters*, long );
void destroy_individual( individual* );


#endif /* INDIVIDUAL_H_ */
