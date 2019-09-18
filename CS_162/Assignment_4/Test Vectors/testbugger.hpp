
class Bug{
	private:
		int health;
		int location;
		bool can_move;
		bool attack;
		int attack_range;
		bool attack_all;
		bool visible;

	public:
		Bug(){
			health = 0;
			location = -1;
			attack = 0;
			attack_all = 0;
			attack_range = -1;
			can_move = 0;
			visible = 0;
		}
		int gethealth(){return health;}
		int getlocation(){return location;}
		int getAtackRange(){return attack_range;}

		void Attacked(){health--;}
		virtual char returnType(){return 'B';}


};
