#ifndef __NEF_DOMAIN_H__
#define __NEF_DOMAIN_H__

#include <vector>

using namespace std;

class NEF_Cylinder;
class NEF_MB;
class NEF_CW;
class NEF_Web;

class NEF_Domain {
private:
	double _rpm;
	int _num_cyl;
	double _bore;
	double _stroke;
	double _con_rod_len;
	int _e_type;

	double _p_mass;
	double _pp_mass;
	double _con_rod_se_mass;
	double _con_rod_be_mass;
	double _con_rod_se_inertia;
	double _con_rod_be_inertia;
	double _con_rod_cm_len;
	double _crank_pin_mass;

	vector<NEF_Cylinder*> _cyl_vec;
	vector<NEF_MB*> _mb_vec;
	vector<NEF_CW*> _cw_vec;
	vector<NEF_Web*> _web_vec;

public:
	NEF_Domain() {
		init();
	}
	~NEF_Domain() {

	}

	void init(void);

	void set(void);
	void set_rpm(double rpm) { _rpm = rpm; }
	void set_num_cylinder(int num_cyl) { _num_cyl = num_cyl; }
	void set_bore(double bore) { _bore = bore; }
	void set_stroke(double stroke) { _stroke = stroke; }
	void set_con_rod_length(double length) { _con_rod_len = length; }
	void set_engine_type(int type) { _e_type = type; }
	void set_piston_mass(double mass) { _p_mass = mass; }
	void set_piston_pin_mass(double mass) { _pp_mass = mass; }
	void set_con_rod_small_end_mass(double mass) { _con_rod_se_mass = mass; }
	void set_con_rod_big_end_mass(double mass) { _con_rod_be_mass = mass; }
	void set_con_rod_small_end_inerita(double inerita) { _con_rod_se_inertia = inerita; }
	void set_con_rod_big_end_inerita(double inerita) { _con_rod_be_inertia = inerita; }
	void set_con_rod_cm_length(void);
	void set_crank_pin_mass(double mass) { _crank_pin_mass = mass; }

	double get_rpm(void) { return _rpm; }
	int get_num_cylinder(void) { return _num_cyl; }
	double get_bore(void) { return _bore; }
	double get_stroke(void) { return _stroke; }
	double get_con_rod_length(void) { return _con_rod_len; }
	int get_engine_type(void) { return _e_type; }
	double get_piston_mass(void) { return _p_mass; }
	double get_piston_pin_mass(void) { return _pp_mass; }
	double get_con_rod_small_end_mass(void) { return _con_rod_se_mass; }
	double get_con_rod_big_end_mass(void) { return _con_rod_be_mass; }
	double get_con_rod_small_end_inerita(void) { return _con_rod_se_inertia; }
	double get_con_rod_big_end_inerita(void) { return _con_rod_be_inertia; }
	double get_con_rod_cm_length(void) { return _con_rod_cm_len; }
	double get_crank_pin_mass(void) { return _crank_pin_mass; }
	vector<NEF_Cylinder*>& get_cylinder(void) { return _cyl_vec; }
	vector<NEF_MB*>& get_main_bearing(void) { return _mb_vec; }
	vector<NEF_CW*>& get_counter_weight(void) { return _cw_vec; }
	vector<NEF_Web*>& get_web(void) { return _web_vec; }

	void calculate(void);



};



#endif