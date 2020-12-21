#ifndef __NEF_COMPONENT_H__
#define __NEF_COMPONENT_H__

#include <vector>

using namespace std;

typedef vector<double> RealVector;

class NEF_Domain;

class NEF_Cylinder {
private:
	int _id;
	double _bank_ang;
	double _xpos;
	double _fire_ang;
	int _mb_id[2];
	int _web_id[2];

	vector<RealVector> _u, _du, _ddu;
	vector<RealVector> _f;

public:
	NEF_Cylinder() {
		_id = 0;
		_bank_ang = 0.;
		_xpos = 0.;
		_fire_ang = 0.;
		_mb_id[0] = 0; _mb_id[1] = 0;
		_web_id[0] = 0; _web_id[1] = 0;
	}
	~NEF_Cylinder() {

	}

	void set_id(int id) { _id = id; }
	void set_bank_angle(double ang) { _bank_ang = ang; }
	void set_xposition(double xpos) { _xpos = xpos; }
	void set_fire_angle(double ang) { _fire_ang = ang; }
	void set_main_bearing_id(int id1, int id2) { _mb_id[0] = id1; _mb_id[1] = id2; }
	void set_web_id(int id1, int id2) { _web_id[0] = id1; _web_id[1] = id2; }	

	int get_id(void) { return _id; }
	double get_bank_angle(void) { return _bank_ang; }
	double get_xposition(void) { return _xpos; }
	double get_fire_angle(void) { return _fire_ang; }
	int* get_main_bearing_id(void) { return _mb_id; }
	int* get_web_id(void) { return  _web_id; }

	vector<RealVector>& get_u(void) { return _u; }
	vector<RealVector>& get_du(void) { return _du; }
	vector<RealVector>& get_ddu(void) { return _ddu; }
	vector<RealVector>& get_f(void) { return _f; }

	void calculate(void);

};

class NEF_MB {
private:
	int _id;
	double _xpos;

public:
	NEF_MB() {
		_id = 0;
		_xpos = 0.;
	}
	~NEF_MB() {

	}

	void set_id(int id) { _id = id; }
	void set_xposition(double xpos) { _xpos = xpos; }

	int get_id(void) { return _id; }
	double get_xposition(void) { return _xpos; }
};

class NEF_CW {
private:
	int _id;
	double _ang;
	double _xpos;
	double _r;
	double _mass;

public:
	NEF_CW() {
		_id = 0;
		_ang = 0.;
		_xpos = 0.;
		_r = 0.;
		_mass = 0.;
	}
	~NEF_CW() {

	}

	void set_id(int id) { _id = id; }
	void set_angle(double ang) { _ang = ang; }
	void set_xposition(double xpos) { _xpos = xpos; }
	void set_radius(double r) { _r = r; }
	void set_mass(double mass) { _mass = mass; }

	int get_id(void) { return _id; }
	double get_angle(void) { return _ang; }
	double get_xposition(void) { return _xpos; }
	double get_radius(void) { return _r; }	
	double get_mass(void) { return _mass; }

};

class NEF_Web {
private:
	int _id;
	int _cw_id;
	double _ang;
	double _xpos;
	double _r;
	double _mass;

public:
	NEF_Web() {
		_id = 0;
		_cw_id = 0;
		_ang = 0.;
		_xpos = 0.;
		_r = 0.;
		_mass = 0.;
	}
	~NEF_Web() {

	}

	void set_id(int id) { _id = id; }
	void set_counter_weight_id(int id) { _cw_id = id; }
	void set_angle(double ang) { _ang = ang; }
	void set_xposition(double xpos) { _xpos = xpos; }
	void set_radius(double r) { _r = r; }
	void set_mass(double mass) { _mass = mass; }

	int get_id(void) { return _id; }
	int get_counter_weight_id(void) { return _cw_id; }
	double get_angle(void) { return _ang; }
	double get_xposition(void) { return _xpos; }
	double get_radius(void) { return _r; }
	double get_mass(void) { return _mass; }

};

#endif