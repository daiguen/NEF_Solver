#include "NEF_Domain.h"
#include "NEF_Component.h"


void NEF_Domain::init(void) {
	_rpm = 0.;
	_num_cyl = 0;
	_bore = 0.;
	_stroke = 0.;
	_con_rod_len = 0.;
	_e_type = 0;

	_p_mass = 0.;
	_pp_mass = 0.;
	_con_rod_se_mass = 0.;
	_con_rod_be_mass = 0.;
	_con_rod_se_inertia = 0.;
	_con_rod_be_inertia = 0.;
	_con_rod_cm_len = 0.;
	_crank_pin_mass = 0.;
}

void NEF_Domain::set_con_rod_cm_length(void) {
	double ma, mb;
	ma = get_con_rod_big_end_mass();
	mb = get_con_rod_small_end_mass();
	
	if (ma == 0) {
		_con_rod_cm_len = 0.;
	}
	else {
		double l = get_con_rod_length();
		_con_rod_cm_len = l - l / ((mb / ma) + 1);
	}

}

void NEF_Domain::calculate(void) {
	vector<NEF_Cylinder*>& cyl_vec = get_cylinder();
	vector<NEF_Cylinder*>::iterator cyl_it;

	for (cyl_it = cyl_vec.begin(); cyl_it != cyl_vec.end(); cyl_it++) {
		(*cyl_it)->calculate();
	}


}