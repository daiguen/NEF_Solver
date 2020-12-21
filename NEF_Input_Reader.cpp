#include "NEF_Input_Reader.h"
#include "NEF_Utils.h"
#include "NEF_Domain.h"
#include "NEF_Component.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void NEF_Input_Reader::read(NEF_Domain& dom) {
	ifstream ReadFile;
	ReadFile.open(get_input_file());

	if (ReadFile.is_open()) {
		string str, key;
		vector<string> str_vec;

		while (!ReadFile.eof()) {
			str = "";
			getline(ReadFile, str);
			str_vec = NEF_Utils::parsing_string(str, "\t");
			if (str_vec.empty()) continue;
			key = str_vec[0];

			if (key == "DOMAIN") {
				dom.set_rpm(stod(str_vec[1]));
				dom.set_num_cylinder(stoi(str_vec[2]));
				dom.set_bore(stod(str_vec[3]));
				dom.set_stroke(stod(str_vec[4]));
				dom.set_con_rod_length(stod(str_vec[5]));
				dom.set_engine_type(stoi(str_vec[6]));
				dom.set_piston_mass(stod(str_vec[7]));
				dom.set_piston_pin_mass(stod(str_vec[8]));
				dom.set_con_rod_small_end_mass(stod(str_vec[9]));
				dom.set_con_rod_big_end_mass(stod(str_vec[10]));
				dom.set_con_rod_small_end_inerita(stod(str_vec[11]));
				dom.set_con_rod_big_end_inerita(stod(str_vec[12]));
				dom.set_crank_pin_mass(stod(str_vec[13]));
				dom.set_con_rod_cm_length();
			}
			else if (key == "CYLINDER") {
				vector<NEF_Cylinder*>& cyl_vec = dom.get_cylinder();
				NEF_Cylinder* cyl = new NEF_Cylinder;
				cyl->set_id(stoi(str_vec[1]));
				cyl->set_bank_angle(stod(str_vec[2]));
				cyl->set_xposition(stod(str_vec[3]));
				cyl->set_fire_angle(stod(str_vec[4]));
				cyl->set_main_bearing_id(stoi(str_vec[5]), stoi(str_vec[6]));
				cyl->set_web_id(stoi(str_vec[7]), stoi(str_vec[8]));
				cyl_vec.push_back(cyl);
			}
			else if (key == "MB") {
				vector<NEF_MB*>& mb_vec = dom.get_main_bearing();
				NEF_MB* mb = new NEF_MB;
				mb->set_id(stoi(str_vec[1]));
				mb->set_xposition(stod(str_vec[2]));
				mb_vec.push_back(mb);
			}
			else if (key == "CW") {
				vector<NEF_CW*>& cw_vec = dom.get_counter_weight();
				NEF_CW* cw = new NEF_CW;
				cw->set_id(stoi(str_vec[1]));
				cw->set_angle(stod(str_vec[2]));
				cw->set_xposition(stod(str_vec[3]));
				cw->set_radius(stod(str_vec[4]));
				cw->set_mass(stod(str_vec[5]));
				cw_vec.push_back(cw);
			}
			else if (key == "WEB") {
				vector<NEF_Web*>& web_vec = dom.get_web();
				NEF_Web* web = new NEF_Web;
				web->set_id(stoi(str_vec[1]));
				web->set_counter_weight_id(stoi(str_vec[2]));
				web->set_angle(stod(str_vec[3]));
				web->set_xposition(stod(str_vec[4]));
				web->set_radius(stod(str_vec[5]));
				web->set_mass(stod(str_vec[6]));
				web_vec.push_back(web);
			}
			else {

			}
		}
		ReadFile.close();
	}
		
}