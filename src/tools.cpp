#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */
  size_t estimations_length = estimations.size();
  size_t ground_truth_length = ground_truth.size();
  assert(estimations_length == ground_truth_length);
  assert(estimations_length != 0);

  VectorXd temp = VectorXd(4); 
  VectorXd RMSE = VectorXd(4); 
  RMSE.fill(0.0);
  for (size_t i = 0; i < estimations_length; i++) {
	temp = estimations[i] - ground_truth[i];
	temp = temp.array()*temp.array();
	RMSE += temp;
  }
  RMSE = RMSE / estimations_length;
  RMSE = RMSE.cwiseSqrt();
  
  return RMSE;
}
