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
			
			cout<<"类型:";
			if(type == infantry){
				cout<<"步兵     ";
			} 
			if(type == engineer){
				cout<<"工程     ";
			}
			if(type == guard){
				cout<<"哨兵     ";
			}
			if(type == hero){
				cout<<"英雄     ";
			}
			
			cout<<"队伍:";
			if(team == red){
				cout<<"红方     ";
			}else{
				cout<<"蓝方     ";
			}
			
			cout<<"编号:"<<setw(3)<<num<<"     "; 
			
			cout<<"血量:"<<setw(3)<<health<<"     ";
			if(health>0){
				cout<<"状态:存活     "; 
			}else{
				cout<<"状态:死亡     ";
			}
			
			cout<<"剩余热量:";
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
			//加入容器 
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
			//遍历容器操作 
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
			//遍历容器操作
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
			//遍历容器操作 
			cout<<endl<<"开始输出"<<endl; 
			for(vector<Robot>::iterator r_t = rvec.begin(); r_t != rvec.end(); r_t ++){
				r_t->show();
			}
			cout<<"结束输出"<<endl<<endl; 
		}
		if(cmd[0]=='C'){
			return 0;
		}
	}
}

