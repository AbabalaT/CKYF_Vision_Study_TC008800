#include<iostream>
#include<iomanip> 
#include <vector>

using namespace std;

enum Types{
	engineer=0, infantry=1, guard=2, hero=3
};

enum Teams{
	red=1,blue=2
};

class Robot{
	private:
        int health;
        int heat;
        
	public:
		Types type;
		Teams team;
		int num;
		
        Robot(int num_in, Teams team_in, Types type_in){
        	
        	type = type_in;
        	team = team_in;
            num= num_in;
            
            if(type == engineer){
            	heat = 0;
            	health = 200;
            	return;
			}
			if(type == infantry){
            	heat = 200;
            	health = 100;
            	return;
			}
			if(type == guard){
            	heat = 300;
            	health = 200;
            	return;
			}
			if(type == hero){
            	heat = 300;
            	health = 200;
            	return;
			}
        }
        
        void hit(int amount){
        	if(type == engineer){
        		return;
			}
        	if(type == hero){
        		heat = heat - 30 * amount;
			}else{
				heat = heat - 15 * amount;
			}
			if(heat <= 0){
				health = 0;
				heat = 0;
			}
		}
		
		void hurt(int injury){
			health = health - injury;
			if(health <= 0){
				health =0;
			}
		}
		
		void show(){
			
			cout<<"����:";
			if(type == infantry){
				cout<<"����     ";
			} 
			if(type == engineer){
				cout<<"����     ";
			}
			if(type == guard){
				cout<<"�ڱ�     ";
			}
			if(type == hero){
				cout<<"Ӣ��     ";
			}
			
			cout<<"����:";
			if(team == red){
				cout<<"�췽     ";
			}else{
				cout<<"����     ";
			}
			
			cout<<"���:"<<setw(3)<<num<<"     "; 
			
			cout<<"Ѫ��:"<<setw(3)<<health<<"     ";
			if(health>0){
				cout<<"״̬:���     "; 
			}else{
				cout<<"״̬:����     ";
			}
			
			cout<<"ʣ������:";
			if(type == engineer){
				cout<<"N/A"<<endl;
			}else{
				cout<<heat<<endl;
			}
		}
};

int main(){
	int n_num;
	int n_amount;
	int n_injury;
	
	Teams n_team;
	Types n_type;
	
	char c_team;
	char c_type;
	
	char cmd[4] = "000";
	
	vector<Robot> rvec;
	
	while(1){
		cin>>cmd;
		
		if(cmd[0]=='A'){
			cin>>c_team;
			cin>>c_type;
			cin>>n_num;
			
			if(c_team == 'R'){
				n_team = red;
			}else{
				n_team = blue;
			}
			
			if(c_type == 'B'){
				n_type = infantry;
			}
			if(c_type == 'S'){
				n_type = guard;
			}
			if(c_type == 'Y'){
				n_type = hero;
			}
			if(c_type == 'G'){
				n_type = engineer;
			}
			//�������� 
			rvec.push_back(Robot(n_num, n_team, n_type));
		}
		
		if(cmd[0]=='F'){
			cin>>c_team;
			cin>>n_num;
			cin>>n_injury;
			
			if(c_team == 'R'){
				n_team = red;
			}else{
				n_team = blue;
			}
			//������������ 
			for(vector<Robot>::iterator r_t = rvec.begin(); r_t != rvec.end(); r_t ++){
				if(r_t->num == n_num){
					if(r_t->team == n_team){
						(*r_t).hurt(n_injury);
						break;
					}
				}
			}
		}
		
		if(cmd[0]=='H'){
			cin>>c_team;
			cin>>n_num;
			cin>>n_amount;
			
			if(c_team == 'R'){
				n_team = red;
			}else{
				n_team = blue;
			}
			//������������
			for(vector<Robot>::iterator r_t = rvec.begin(); r_t != rvec.end(); r_t ++){
				if(r_t->num == n_num){
					if(r_t->team == n_team){
						(*r_t).hit(n_amount);
						break;
					}
				}
			}
		}
		
		if(cmd[0]=='E'){
			//������������ 
			cout<<endl<<"��ʼ���"<<endl; 
			for(vector<Robot>::iterator r_t = rvec.begin(); r_t != rvec.end(); r_t ++){
				r_t->show();
			}
			cout<<"�������"<<endl<<endl; 
		}
		if(cmd[0]=='C'){
			return 0;
		}
	}
}

